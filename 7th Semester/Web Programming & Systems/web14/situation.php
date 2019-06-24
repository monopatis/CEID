<?php echo $_GET["id"];
	$id = $_GET["id"];
	 ?><br>
<?php
	session_start();
	$hostname="localhost"; //local server name default localhost
	$username="web";  //mysql username default is root.
	$password="web2014";       //blank if no password is set for mysql.
	$database="web14";  //database name which you created
	$con=mysqli_connect($hostname,$username,$password,$database);
	$sql="SET NAMES utf8";
	$query = mysqli_query($con,$sql);
	$sql="UPDATE `reports` SET `situation` = '0',`timefix` = now() , `sit_username`='".$_SESSION['username']."' WHERE `report_id` =$id";
	echo $sql;
	$query = mysqli_query($con,$sql);
	header('Location: ./report/?id='.$id);

?>