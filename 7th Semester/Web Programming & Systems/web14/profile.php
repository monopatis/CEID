
<!DOCTYPE HTML>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=0.8, maximum-scale=1.0, user-scalable=no" />
<title>PROFILE</title>
  <link rel="shortcut icon" href="favicon.png" />
<link rel="stylesheet" type="text/css" href="styles.css">
</head>
<body>
    <?php include 'navigation.php';?>
    <?php
    session_start();
    $id=$_SESSION['user_id'];
    $username=$_SESSION['username'];
    $name=$_SESSION['name'];
    $email=$_SESSION['email'];
    $telephone=$_SESSION['telephone'];
    $is_admin=$_SESSION['is_admin'];
    ?>
<div id="reg">
<form action="./change_profile.php" method="post"> 
<table>
<tr>
  <td>Όνομα:</td>
  <td><input type="text" name="name" value="<?php echo $name ?>"></td>     
  </tr>
<tr>
  <td>Username:</td>
  <td><input type="text" name="username" value="<?php echo $username ?>"></td>     
  </tr>
<tr>
  <td>Email:</td>
  <td><input type="text" name="email" value="<?php echo $email ?>"></td>        
  </tr>
<tr>
  <td>Password:</td>
  <td><input type="password" name="password" value="<?php echo $password ?>"></td>
  </tr>
<tr>
  <td>Τηλέφωνο:</td>
  <td><input type="text" name="telephone" value="<?php echo $telephone ?>"></td>
  </tr>
<tr>
  <td>Is admin:</td>
  <td><input type="text" name="is_admin" value="<?php echo $is_admin ?>"></td>     
  </tr>
</table>
<input type="submit" name="submit" value="submit">
</form>
<?php
    $hostname="localhost"; //local server name default localhost
    $username="web";  //mysql username default is root.
    $password="web2014";       //blank if no password is set for mysql.
    $database="web14";  //database name which you created
    $con=mysqli_connect($hostname,$username,$password,$database);
    $sql="SET NAMES utf8";
    $query = mysqli_query($con,$sql);
    $sql="SELECT * FROM `reports` WHERE `username`='$email'";
    $query = mysqli_query($con,$sql);
    while ($row = mysqli_fetch_array($query)) {
         echo '<a href="./report/?id=';
        echo $row['report_id'];
        echo '">';
        echo $row['category']." ".$row['description'];
        echo '</a> ';
        if ($row['situation']==0){
          echo "&#10004;";
        }
        echo "</br>";
    }
    if ($is_admin==1){
      echo '<form action="./admin.php">';
      echo '<input type="submit" value="Επεξεργασία χρηστών/κατηγοριών">';
      echo '</form>';
      echo '<form action="./reports_open.php">';
      echo '<input type="submit" value="Όλες οι ανοιχτές αναφορές">';
      echo '</form>';
      echo '<form action="./reports_close.php">';
      echo '<input type="submit" value="Όλες οι κλειστές αναφορές">';
      echo '</form>';
    }
?>
</div>
</body>
</html>