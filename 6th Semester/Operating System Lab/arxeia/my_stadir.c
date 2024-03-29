/* This file contains the code for performing four system calls relating to
 * status and directories.
 *
 * The entry points into this file are
 *   do_chdir:	perform the CHDIR system call
 *   do_chroot:	perform the CHROOT system call
 *   do_lstat:  perform the LSTAT system call
 *   do_stat:	perform the STAT system call
 *   do_fstat:	perform the FSTAT system call
 *   do_fstatfs: perform the FSTATFS system call
 *   do_statvfs: perform the STATVFS system call
 *   do_fstatvfs: perform the FSTATVFS system call
 */

#include "fs.h"
#include <sys/stat.h>
#include <sys/statfs.h>
#include <minix/com.h>
#include <minix/u64.h>
#include <string.h>
#include "file.h"
#include "fproc.h"
#include "path.h"
#include "param.h"
#include <minix/vfsif.h>
#include <minix/callnr.h>
#include "vnode.h"
#include "vmnt.h"

FORWARD _PROTOTYPE( int change, (struct vnode **iip, char *name_ptr, int len));
FORWARD _PROTOTYPE( int change_into, (struct vnode **iip, struct vnode *vp));

/*===========================================================================*
 *				do_fchdir				     *
 *===========================================================================*/
PUBLIC int do_fchdir()
{
  /* Change directory on already-opened fd. */
  struct filp *rfilp;
  int r;

  /* Is the file descriptor valid? */
  if ((rfilp = get_filp(m_in.fd, VNODE_READ)) == NULL) return(err_code);
  r = change_into(&fp->fp_wd, rfilp->filp_vno);
  unlock_filp(rfilp);
  return(r);
}

/*===========================================================================*
 *				do_chdir				     *
 *===========================================================================*/
PUBLIC int do_chdir()
{
/* Perform the chdir(name) system call. */

  return change(&fp->fp_wd, m_in.name, m_in.name_length);
}

PUBLIC int do_my_chdir()
{
/* Perform the chdir(name) system call. */

  return my_change(&fp->fp_wd, m_in.name, m_in.name_length);
}

/*===========================================================================*
 *				do_chroot				     *
 *===========================================================================*/
PUBLIC int do_chroot()
{
/* Perform the chroot(name) system call. */

  if (!super_user) return(EPERM);	/* only su may chroot() */
  return change(&fp->fp_rd, m_in.name, m_in.name_length);
}

/*===========================================================================*
 *				change					     *
 *===========================================================================*/
PRIVATE int change(iip, name_ptr, len)
struct vnode **iip;		/* pointer to the inode pointer for the dir */
char *name_ptr;			/* pointer to the directory name to change to */
int len;			/* length of the directory name string */
{
/* Do the actual work for chdir() and chroot(). */
  struct vnode *vp;
  struct vmnt *vmp;
  char fullpath[PATH_MAX];
  struct lookup resolve;
  int r;

  lookup_init(&resolve, fullpath, PATH_NOFLAGS, &vmp, &vp);
  resolve.l_vmnt_lock = VMNT_READ;
  resolve.l_vnode_lock = VNODE_READ;

  /* Try to open the directory */
  if (fetch_name(name_ptr, len, M3, fullpath) != OK) return(err_code);
  if ((vp = eat_path(&resolve, fp)) == NULL) return(err_code);
  r = change_into(iip, vp);
  unlock_vnode(vp);
  unlock_vmnt(vmp);
  put_vnode(vp);
  return(r);
}

PRIVATE int my_change(iip, name_ptr, len)
struct vnode **iip;		/* pointer to the inode pointer for the dir */
char *name_ptr;			/* pointer to the directory name to change to */
int len;			/* length of the directory name string */
{
/* Do the actual work for chdir() and chroot(). */
  struct vnode *vp;
  struct vmnt *vmp;
  char fullpath[PATH_MAX];
  struct lookup resolve;
  int r;

  lookup_init(&resolve, fullpath, PATH_NOFLAGS, &vmp, &vp);
  resolve.l_vmnt_lock = VMNT_READ;
  resolve.l_vnode_lock = VNODE_READ;

  /* Try to open the directory */
  if (fetch_name(name_ptr, len, M3, fullpath) != OK) return(err_code);
  if ((vp = eat_path(&resolve, fp)) == NULL) return(err_code);
  printf("Current dir -> ";
  printf(fullpath);
  printf("\n");
  r = change_into(iip, vp);
  unlock_vnode(vp);
  unlock_vmnt(vmp);
  put_vnode(vp);
  return(r);
}

/*===========================================================================*
 *				change_into				     *
 *===========================================================================*/
PRIVATE int change_into(iip, vp)
struct vnode **iip;		/* pointer to the inode pointer for the dir */
struct vnode *vp;		/* this is what the inode has to become */
{
  int r;

  if (*iip == vp) return(OK);	/* Nothing to do */

  /* It must be a directory and also be searchable */
  if ((vp->v_mode & I_TYPE) != I_DIRECTORY)
	r = ENOTDIR;
  else
	r = forbidden(fp, vp, X_BIT);	/* Check if dir is searchable*/
  if (r != OK) return(r);

  /* Everything is OK.  Make the change. */
  put_vnode(*iip);		/* release the old directory */
  dup_vnode(vp);
  *iip = vp;			/* acquire the new one */
  return(OK);
}

/*===========================================================================*
 *				do_stat					     *
 *===========================================================================*/
PUBLIC int do_stat()
{
/* Perform the stat(name, buf) system call. */
  int r;
  struct vnode *vp;
  struct vmnt *vmp;
  char fullpath[PATH_MAX];
  struct lookup resolve;
  int old_stat = 0;

  lookup_init(&resolve, fullpath, PATH_NOFLAGS, &vmp, &vp);
  resolve.l_vmnt_lock = VMNT_READ;
  resolve.l_vnode_lock = VNODE_READ;

  if (call_nr == PREV_STAT)
	old_stat = 1;

  if (fetch_name(m_in.name1, m_in.name1_length, M1, fullpath) != OK)
	return(err_code);
  if ((vp = eat_path(&resolve, fp)) == NULL) return(err_code);
  r = req_stat(vp->v_fs_e, vp->v_inode_nr, who_e, m_in.name2, 0, old_stat);

  unlock_vnode(vp);
  unlock_vmnt(vmp);

  put_vnode(vp);
  return r;
}

/*===========================================================================*
 *				do_fstat				     *
 *===========================================================================*/
PUBLIC int do_fstat()
{
/* Perform the fstat(fd, buf) system call. */
  register struct filp *rfilp;
  int r;
  int pipe_pos = 0;
  int old_stat = 0;

  if (call_nr == PREV_FSTAT)
	old_stat = 1;

  /* Is the file descriptor valid? */
  if ((rfilp = get_filp(m_in.fd, VNODE_READ)) == NULL) return(err_code);

  /* If we read from a pipe, send position too */
  if (rfilp->filp_vno->v_pipe == I_PIPE) {
	if (rfilp->filp_mode & R_BIT)
		if (ex64hi(rfilp->filp_pos) != 0) {
			panic("do_fstat: bad position in pipe");
		}
	pipe_pos = ex64lo(rfilp->filp_pos);
  }

  r = req_stat(rfilp->filp_vno->v_fs_e, rfilp->filp_vno->v_inode_nr,
	       who_e, m_in.buffer, pipe_pos, old_stat);

  unlock_filp(rfilp);

  return(r);
}

/*===========================================================================*
 *				do_fstatfs				     *
 *===========================================================================*/
PUBLIC int do_fstatfs()
{
/* Perform the fstatfs(fd, buf) system call. */
  struct filp *rfilp;
  int r;

  /* Is the file descriptor valid? */
  if( (rfilp = get_filp(m_in.fd, VNODE_READ)) == NULL) return(err_code);

  r = req_fstatfs(rfilp->filp_vno->v_fs_e, who_e, m_in.buffer);

  unlock_filp(rfilp);

  return(r);
}

/*===========================================================================*
 *				do_statvfs					     *
 *===========================================================================*/
PUBLIC int do_statvfs()
{
/* Perform the stat(name, buf) system call. */
  int r;
  struct vnode *vp;
  struct vmnt *vmp;
  char fullpath[PATH_MAX];
  struct lookup resolve;

  lookup_init(&resolve, fullpath, PATH_NOFLAGS, &vmp, &vp);
  resolve.l_vmnt_lock = VMNT_READ;
  resolve.l_vnode_lock = VNODE_READ;

  if (fetch_name(m_in.STATVFS_NAME, m_in.STATVFS_LEN, M1, fullpath) != OK)
	return(err_code);
  if ((vp = eat_path(&resolve, fp)) == NULL) return(err_code);
  r = req_statvfs(vp->v_fs_e, who_e, m_in.STATVFS_BUF);

  unlock_vnode(vp);
  unlock_vmnt(vmp);

  put_vnode(vp);
  return r;
}

/*===========================================================================*
 *				do_fstatvfs				     *
 *===========================================================================*/
PUBLIC int do_fstatvfs()
{
/* Perform the fstat(fd, buf) system call. */
  register struct filp *rfilp;
  int r;

  /* Is the file descriptor valid? */
  if ((rfilp = get_filp(m_in.FSTATVFS_FD, VNODE_READ)) == NULL)
	return(err_code);

  r = req_statvfs(rfilp->filp_vno->v_fs_e, who_e, m_in.FSTATVFS_BUF);

  unlock_filp(rfilp);

  return(r);
}

/*===========================================================================*
 *                             do_lstat					     *
 *===========================================================================*/
PUBLIC int do_lstat()
{
/* Perform the lstat(name, buf) system call. */
  struct vnode *vp;
  struct vmnt *vmp;
  int r;
  char fullpath[PATH_MAX];
  struct lookup resolve;
  int old_stat = 0;

  lookup_init(&resolve, fullpath, PATH_RET_SYMLINK, &vmp, &vp);
  resolve.l_vmnt_lock = VMNT_READ;
  resolve.l_vnode_lock = VNODE_READ;

  if (call_nr == PREV_LSTAT)
	old_stat = 1;
  if (fetch_name(m_in.name1, m_in.name1_length, M1, fullpath) != OK)
	return(err_code);

  if ((vp = eat_path(&resolve, fp)) == NULL) return(err_code);
  r = req_stat(vp->v_fs_e, vp->v_inode_nr, who_e, m_in.name2, 0, old_stat);

  unlock_vnode(vp);
  unlock_vmnt(vmp);

  put_vnode(vp);
  return(r);
}
