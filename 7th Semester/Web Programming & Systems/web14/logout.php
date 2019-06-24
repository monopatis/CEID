<?php
session_start(); 
//session variables initialization
$_SESSION['myemail'] = "";
$_SESSION['mypassword'] = "";
$_SESSION['user_id'] = "";
$_SESSION['username'] = "";
$_SESSION['name'] = "";
$_SESSION['email'] = "";
$_SESSION['telephone'] = "";
$_SESSION['is_admin'] = "";
header( "Location: index.php" );
?>