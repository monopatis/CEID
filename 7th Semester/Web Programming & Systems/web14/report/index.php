<!DOCTYPE HTML>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=0.8, maximum-scale=1.0, user-scalable=no" />
	<link rel="shortcut icon" href="../favicon.png" />
	<link href="../rss.php" rel="alternate" type="application/rss+xml" title="RSS 2.0" />
	<link rel="stylesheet" type="text/css" href="../styles.css">
	<link rel="stylesheet" href="http://cdn.leafletjs.com/leaflet-0.7.2/leaflet.css" />
	<script src="http://cdn.leafletjs.com/leaflet-0.7.2/leaflet.js"></script>
	<script src="../script/jquery-1.9.1.js"></script>
	<script src="../script/jquery-ui-1.10.3.js"></script>
</head>
<body>
ID <?php echo $_GET["id"];
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
	$sql="SELECT * FROM `reports` WHERE `report_id`=$id";
	$query = mysqli_query($con,$sql);
	$row = mysqli_fetch_array($query);
	echo $row['geolocation'];
	echo '<br>';?>
    <?php
	echo $row['situation'];
	echo ' by ';
	echo $row['sit_username'];
	echo '<a href="../situation.php?id=';
    echo $id;
    echo '"> Change</a>';
	echo '<br>';
	echo $row['username'];
	echo '<br>';
	echo  $row['category'];
	echo '<br>';
	echo  $row['description'];
	echo '<br>';
	echo  date("D, d M Y H:i:s O", strtotime($row['time']));
	echo '<br><div style="width: 100%">';
	echo  '<img src="../images/'.$row['foto_1'].'" alt="'.$row['foto_1'].'" style="max-width: 100%;max-height: 100%">';
	echo  '<img src="../images/'.$row['foto_2'].'" alt="'.$row['foto_2'].'" style="max-width: 100%;max-height: 100%">';
	echo  '<img src="../images/'.$row['foto_3'].'" alt="'.$row['foto_3'].'" style="max-width: 100%;max-height: 100%">';
	echo  '<img src="../images/'.$row['foto_4'].'" alt="'.$row['foto_4'].'" style="max-width: 100%;max-height: 100%">';
	echo '</div>';
    $sql="SELECT * FROM `comments` WHERE `report_id`=$id ORDER BY `comment_id`";
    $info = mysqli_query($con,$sql);
    $info_rows = mysqli_num_rows($info);
	if($info_rows > 0) {
		echo '<h5>Σχόλια:</h5>';
		echo '<table width="95%">';
		while($info2 = mysqli_fetch_object($info)) {	
			echo '<tr>';   
			echo '<td>"'.htmlspecialchars(stripslashes($info2->comment_id)).'" by: '.htmlspecialchars(stripslashes($info2->user_email)).'</td> <td><div align="right"> @ '.date("D, d M Y H:i:s O", strtotime($info2->timestamp)).'</div></td>';
			echo '</tr><tr>';
			echo '<td colspan="2"> '.htmlspecialchars(stripslashes(nl2br($info2->comment))).' </td>';
			echo '</tr>';
		}//end while
		echo '</table>';
		echo '<hr width="95%" noshade>';
	} else echo 'Κάντε το πρώτο σχόλιο <br>';
	
if(isset($_POST['submit'])) {
  if(!addslashes($_POST['comment']))  die('<u>ERROR:</u> cannot add comment if you do not enter one!?');
//add comment
$q ="INSERT INTO `comments` (report_id, user_email, user_id, comment) 
VALUES ('".$id."', '".$_SESSION['email']."', '".$_SESSION['user_id']."', '".addslashes(htmlspecialchars(nl2br($_POST['comment'])))."')";

$q2 = mysqli_query($con,$q);
  if(!$q2) die(mysql_error());

//refresh page so they can see new comment
header('Location: http://' . $_SERVER['HTTP_HOST'] . $_POST['page'] .'/web/report/?id='.$id. "#comments");

} else {  //display form
?>
<form name="comments" action="<? $_SERVER['PHP_SELF']; ?>" method="post">

<table width="90%" border="0" cellspacing="0" cellpadding="0">
   <tr> 
      <td><div align="right">User email:   </div></td> 
       <td><? echo($_SESSION['email']); ?></td>
   </tr>
    <tr>
      <td><div align="right">Σχόλιο:   </div></td>
      <td><textarea name="comment" cols="45" rows="5" wrap="VIRTUAL"></textarea></td>
    </tr>
    <tr> 
      <td></td>
      <td colspan="2"><input type="reset" value="Reset Fields">     
        <input type="submit" name="submit" value="Προσθήκη Σχολίου"></td>
    </tr>
  </table>
</form>
<?
} // end else
?>

</body>
</html> 