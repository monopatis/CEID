<?php 
session_start(); 
?>

<!DOCTYPE html>
<html>
<head> 
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=0.8, maximum-scale=1.0, user-scalable=no" />
<link rel="stylesheet" type="text/css" href="styles.css">
<title>LOGIN</title>
  <link rel="shortcut icon" href="favicon.png" />
</head>
<body>
    <?php include 'navigation.php';?>
<div id="login">
<fieldset>
<h2>Είσοδος στο Σύστημα:</h2>
<form name='login_form' method='post' action=''>  
<label><b>Email :<br></label> <input type='text' name='email'></b><br><br>
<label><b>Password :<br></label> <input type='password' name='password'></b><br><br>
<input class='button' type='submit' value='Σύνδεση'>
</fieldset>
</form> 
</div>
<?php
 //if login fails redirect on the same file

//---------------- processing username & password ----------------

//session variables initialization
$_SESSION['myemail'] = "";
$_SESSION['mypassword'] = "";


if (isset($_POST['email'])){  //if the user pressed the submit button
// check the POST variable username is sane, and is not empty
    if(empty($_POST['email'])==FALSE ){
        $_SESSION['myemail'] = $_POST['email'];		
		echo "Email: ". $_SESSION['myemail'];
        }
    else{
        echo "Username is not set!";
        exit();
        }
}	

if (isset($_POST['password'])){ //if the user pressed the submit button
// check the POST variable userName is sane, and is not empty
    if(empty($_POST['password'])==FALSE){
        $_SESSION['mypassword'] = $_POST['password'];
		echo "Password: ". $_SESSION['mypassword'];
        }
    else{
        echo 'Password is not set!';
		exit();
        }
}

if (($_SESSION['myemail'] != "") && ($_SESSION['mypassword'] != "")){
	
	/* ------------------- Connection to database ------------------- */
	$con = mysqli_connect('localhost','web','web2014','web14');
	$sql="SET NAMES utf8";
    $query = mysqli_query($con,$sql);

	// Check connection
	if (mysqli_connect_errno()){
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
		exit();
	}
	$sql = "SELECT * FROM `users` WHERE email = '$_SESSION[myemail]' AND password = '$_SESSION[mypassword]'"; 
	$result = mysqli_query($con,$sql); //insert to $result the query from base
	$row = mysqli_fetch_array($result);
	if ($row['user_id']==''){
		echo "Failed to find user ";
		exit();
	}
	$_SESSION['user_id'] = $row['user_id'];
	$_SESSION['username'] = $row['username'];
	$_SESSION['name'] = $row['name'];
	$_SESSION['email'] = $row['email'];
	$_SESSION['telephone'] = $row['telephone'];
	$_SESSION['is_admin'] = $row['is_admin'];
	mysqli_close($con);
	header( "Location: profile.php" );
}

?>

</body>	
</html>