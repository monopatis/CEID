<?php     //start php tag
session_start(); 
if ($_SESSION['is_admin']==1){
$hostname="localhost"; //local server name default localhost
$username="web";  //mysql username default is root.
$password="web2014";       //blank if no password is set for mysql.
$database="web14";  //database name which you created
//if submit is not blanked i.e. it is clicked.
?>
<!DOCTYPE html>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=0.8, maximum-scale=1.0, user-scalable=no" />
  <title>Open Reports</title>
  <link rel="shortcut icon" href="favicon.png" />
  <link href="rss.php" rel="alternate" type="application/rss+xml" title="RSS 2.0" />
	<link rel="stylesheet" type="text/css" href="styles.css">
</head>
<body>
	<?php include 'navigation.php';?>
<?php
$con = mysqli_connect('localhost','web','web2014','web14');
$sql="SET NAMES utf8";
$query = mysqli_query($con,$sql);
$rec_limit = 20;

/* Get total number of records */
$sql = "SELECT count(report_id) FROM `reports` WHERE `situation`=1";
$retval = mysqli_query( $con, $sql );
if(! $retval )
{
  die('Could not get data: ' . mysql_error());
}
$row = mysqli_fetch_array($retval);
$rec_count = $row[0];

if( isset($_GET{'page'} ) )
{
   $page = $_GET{'page'} + 1;
   $offset = $rec_limit * $page ;
}
else
{
   $page = 0;
   $offset = 0;
}
?>
    <div id="reports" > 
    <b>Όλες οι ανοιχτές αναφορές</b><br/>
<?php
$left_rec = $rec_count - ($page * $rec_limit);

$sql = "SELECT * FROM `reports` WHERE `situation`=1 ORDER BY `report_id` ".
       "LIMIT $offset, $rec_limit";

$retval = mysqli_query($con,$sql);
if(! $retval )
{
  die('Could not get data: ' . mysql_error());
}
while($row = mysqli_fetch_array($retval))
{
	echo '<a href="./report/?id=';
    echo $row['report_id'];
    echo '">';
    echo date("d/m/Y", strtotime($row['time'])).' '.$row['category'];
    echo '</a> ';

    echo "<br/>";
} 
if( $page!=0)
{
   $last = $page - 2;
   echo "<a href=\"$_PHP_SELF?page=$last\">Last 20 Records</a> ";
}
if( $left_rec > $rec_limit )
{
   echo "<a href=\"$_PHP_SELF?page=$page\">Next 20 Records</a>";
}
mysql_close($con);
}
?>