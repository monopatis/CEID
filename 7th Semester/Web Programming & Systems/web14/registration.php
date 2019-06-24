<?php     //start php tag
ini_set("display_errors", 1);
ini_set("track_errors", 1);
ini_set("html_errors", 1);
error_reporting(E_ALL);
$hostname="localhost"; //local server name default localhost
$username="web";  //mysql username default is root.
$password="web2014";       //blank if no password is set for mysql.
$database="web14";  //database name which you created
$con=mysqli_connect($hostname,$username,$password,$database);

if(! $con)
{
die('Connection Failed'.mysql_error());
}
$sql="SET NAMES utf8";
$query = mysqli_query($con,$sql);

//if submit is not blanked i.e. it is clicked.
If(isset($_REQUEST['submit'])!='')
{
If( $_REQUEST['email']=='' || $_REQUEST['password']=='')
{
Echo "please fill the empty field.";
}
Else
{
	$sql="insert into users(name,email,password,telephone) values('".$_REQUEST['name']."', '".$_REQUEST['email']."', '".$_REQUEST['password']."', '".$_REQUEST['telephone']."')";
	If(mysqli_query($con,$sql))
	{
		Echo "Record successfully inserted";
		header( "Location: login.php" );

	}
	Else
	{
		Echo "There is some problem in inserting record. ". mysqli_error($con);
	}
}
}
?>
