(defvar *state*)

(defvar *game-file-out* "/home/mitsos/lisp/gameout.txt")
(defvar *game-file-in* "/home/mitsos/lisp/gamein.txt")

(defun start ()
  (display-message-0)
  (if (= *state* 1)
    (take-data-1)
    (if (= *state* 2)
      (take-data-2)
    )
  )
  (data-check)
  (format t "~%~%Η μετακίνηση μίας ψηφίδας γίνεται με το (move <position>): πχ (move 5)")
)

(defun display-message-0 ()
  (with-open-file (game-stream-out  *game-file-out* :direction :output :if-does-not-exist :create :if-exists :append)
    (multiple-value-bind
      (second minute hour date month year day-of-week dst-p tz)
      (get-decoded-time)
      (format game-stream-out "~%~d/~2,'0d/~d ~2,'0d:~2,'0d:~2,'0d"
       date
       month
       year
       hour
       minute
       second
      ))
    (format game-stream-out " Kalosirthate sto pazzle 6 psifion !")
    (format t "~%Καλωσήλθατε στο παζλ 6 ψηφίδων !~%Η ώρα είναι: ")
    (multiple-value-bind
      (second minute hour date month year day-of-week dst-p tz)
      (get-decoded-time)
      (format t "~2,'0d:~2,'0d:~2,'0d , ~d/~2,'0d/~d"
	      hour
	      minute
	      second
	      date
	      month
	      year))
    (format t "~%Γράψτε 1 για αρχικοποίηση από πληκτρολόγιο και 2 από αρχείο:~%")
    (setf *state* (read))
  )
)

(defun take-data-1 ()
  (format t "~%Δώστε την αρχική κατάσταση του προβλήματος με την μορφή~%")
  (format t "~%(<1η θέση> <2η> <3η> <4η> <5η> <6η> <7η>):(B B W _ B W W)")
  (format t "~%όπου B:Black(Μαύρο), W:White(Λευκό), _:Gap(Κενό)")
  (format t "~%αυστηρά 3xB, 3xW και ένα _~%")
  (format t "~%Αρχική κατάσταση: ")
  (setf *state* (read))
  (with-open-file (game-stream-out  *game-file-out* :direction :output :if-does-not-exist :create :if-exists :append)
      (format game-stream-out "~%Arxikh katastash: ~a" *state*)
  )
)

(defun take-data-2 ()
  (with-open-file (game-stream-out  *game-file-out* :direction :output :if-does-not-exist :create :if-exists :append)
    (format game-stream-out "~%Read from file: ~a~%" *game-file-in*)
    (format t "~%Πρέπει να έχετε καταχωρήσει την αρχική κατάσταση του προβλήματος με την μορφή")
    (format t "~%(<1η θέση> <2η> <3η> <4η> <5η> <6η> <7η>) πχ: (B B W _ B W W)")
    (format t "~%όπου B:Black(Μαύρο), W:White(Λευκό), _:Gap(Κενό)")
    (format t "~%αυστηρά 3xB, 3xW και ένα _~%")
    (format t "~%Στο αρχείο: ~a" *game-file-in*)
  )
  (with-open-file (game-stream-in  *game-file-in* :direction :input)
     (setf *state* (read game-stream-in))
  )
  (with-open-file (game-stream-out  *game-file-out* :direction :output :if-does-not-exist :create :if-exists :append)
      (format game-stream-out "Arxikh katastash: ~a" *state*)
  )
  (format t "~%Αρχική κατάσταση: ~a~%" *state*)
)

(defun data-check ()
  (let ((var_b 0)(var_w 0)(var_g 0))
    (dolist (n *state*)
      (case n
        (B (incf var_b 1))
        (W (incf var_w 1))
        (_ (incf var_g 1))
      )
    )
    (if (or (/= var_b 3) (/= var_w 3) (/= var_g 1) )
      (error-1)
    )
  )
)

(defun error-1 ()
  (with-open-file (game-stream-out  *game-file-out* :direction :output :if-does-not-exist :create :if-exists :append)
    (format game-stream-out "~%Error! H arxikh katastash den einai sosti! Anagnosi apo to pliktrologio.")
  )
  (format t "~%ΣΦΑΛΜΑ! Η αρχική κατάσταση δεν είναι σωστή!~%")
  (take-data-1)
  (data-check)
)

(defun make-move (pos)
  (format t "~%Μετακίνηση από την θέση ~a, νέα κατάσταση:~%" pos)
  (with-open-file (game-stream-out  *game-file-out* :direction :output :if-does-not-exist :create :if-exists :append)
      (format game-stream-out "~%Metakinhsh apo thn thesh: ~a" pos)
  )
  (setq psifida (nth (- pos 1) *state*))
  (setq gap (position '_ *state*))
  (if (< (- pos 1) gap)
    (setf *state* (move-from-left pos psifida gap))
    (setf *state* (move-from-right pos psifida gap))
  )
  (format t "~a" *state*)
  (with-open-file (game-stream-out  *game-file-out* :direction :output :if-does-not-exist :create :if-exists :append)
      (format game-stream-out ", nea katastash: ~a" *state*)
  )
)

(defun move-from-left (pos psifida gap)
  (append
    (subseq *state* 0 (- pos 1))
    (subseq *state* pos gap)
    '(_)
    (list psifida)
    (subseq *state* (+ 1 gap))
  )
)

(defun move-from-right (pos psifida gap)
  (append
    (subseq *state* 0 gap)
    (list psifida)
    (subseq *state* gap (- pos 1))
    (subseq *state* pos)
  )
)

(defun move (pos)
  (let ((movement (checkpos pos)))
    (if movement
        (make-move pos)
        (display-message-1 pos)
    )
  )
)

(defun checkpos (pos)
  (and (numberp pos) (> pos 0) (< pos 8) (typep pos 'integer) )
)

(defun display-message-1 (pos)
  (format t "~%Δεν υπάρχει τέτοια θέση: ~a~%" pos)
  (with-open-file (game-stream-out  *game-file-out* :direction :output :if-does-not-exist :create :if-exists :append)
      (format game-stream-out "~%Den uparxei tetoia thesi: ~a" pos)
  )
)
