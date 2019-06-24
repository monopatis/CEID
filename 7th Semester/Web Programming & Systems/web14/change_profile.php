<?php     //start php tag
$hostname="localhost"; //local server name default localhost
$username="web";  //mysql username default is root.
$password="web2014";       //blank if no password is set for mysql.
$database="web14";  //database name which you created
$con=mysqli_connect($hostname,$username,$password,$database);
$sql="SET NAMES utf8";
$query = mysqli_query($con,$sql);
session_start();
$id=$_SESSION['user_id'];

if(! $con)
{
die('Connection Failed'.mysql_error());
}

//if submit is not blanked i.e. it is clicked.
If(isset($_REQUEST['submit'])!='')
{
If( $_REQUEST['email']=='' || $_REQUEST['password']=='')
{
Echo "please fill the empty field.";
}
Else
{
	$sql="update users set name='".$_REQUEST['name']."', email='".$_REQUEST['email']."', password='".$_REQUEST['password']."', telephone='".$_REQUEST['telephone']."' WHERE user_id=$id ";
	If(mysqli_query($con,$sql))
	{
		Echo "Record successfully updated";
		$_SESSION['name'] = $_REQUEST['name'];
		$_SESSION['email'] = $_REQUEST['email'];
		$_SESSION['telephone'] = $_REQUEST['telephone'];
		header( "Location: profile.php" );
	}
	Else
	{
		Echo "There is some problem in inserting record. ". mysqli_error($con);
	}
}
}
?>
