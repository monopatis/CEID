<!DOCTYPE HTML>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=0.8, maximum-scale=1.0, user-scalable=no" />
<title>HOME</title>
<link rel="shortcut icon" href="favicon.png" />
<link href="rss.php" rel="alternate" type="application/rss+xml" title="RSS 2.0" />
<link rel="stylesheet" type="text/css" href="styles.css">
<link rel="stylesheet" href="http://cdn.leafletjs.com/leaflet-0.7.2/leaflet.css" />
<script src="http://cdn.leafletjs.com/leaflet-0.7.2/leaflet.js"></script>
<script src="script/jquery-1.9.1.js"></script>
<script src="script/jquery-ui-1.10.3.js"></script>
<script type="text/javascript">
var open_sum, open_old;
open_old="0";
function post_open()
{
    $.post( "open_sum.php", function(data) {
        open_sum = data;
        if (open_sum!=open_old){
            open_old=open_sum;
            $('#open').html(open_sum);
        }
        }
    );

}
var close_sum, close_old;
close_old="0";
function post_close()
{
    $.post( "close_sum.php", function(data) {
        close_sum = data;
        if (close_sum!=close_old){
            close_old=close_sum;
            $('#close').html(close_sum);
        }
        }
    );

}
var sum, old;
old="0";
function post_sum()
{
    $.post( "sum.php", function(data) {
        sum = data;
        if (sum!=old){
            old=sum;
            $('#sum').html(sum);
        }
        }
    );

}
var avg, avg_old;
avg_old="0";
function post_avg()
{
    $.post( "avg.php", function(data) {
        avg = data;
        if (avg!=avg_old){
            avg_old=avg;
            $('#avg').html(avg);
        }
        }
    );

}

</script>
<script type="text/javascript">
$(document).ready(function(){   
    setInterval ("post_sum()", 3000);
    setInterval ("post_open()", 3000);
    setInterval ("post_close()", 3000);
    setInterval ("post_avg()", 3000);
});

</script>
</head>
<body>
    <?php include 'navigation.php';?>
<div id="reg">
<table>
    <tr>
        <td>Σύνολο αναφορών:</td>
        <td><div id="sum">loading...</div></td>
    </tr>
    <tr>
        <td>Ανοιχτές:</td>
        <td><div id="open"></div></td>
    </tr>
    <tr>
        <td>Κλειστές:</td>
        <td><div id="close"></div></td>
    </tr> 
    <tr>
        <td>Μέσος χρόνος επίλυσης:</td>
        <td><div id="avg"></div></td>
    </tr>
</table>
</div>
<div id="map"></div>
<script type="text/javascript">
    var map = L.map('map').setView([38.35889, 24.27979], 6);
    CM_ATTR = '';
    CM_URL = 'http://{s}.tile.osm.org/{z}/{x}/{y}.png';
    L.tileLayer(CM_URL, {attribution: CM_ATTR, styleId: 997}).addTo(map);
    var marker = new Array();
    </script>
         <?php
    $hostname="localhost"; //local server name default localhost
    $username="web";  //mysql username default is root.
    $password="web2014";       //blank if no password is set for mysql.
    $database="web14";  //database name which you created
    $con=mysqli_connect($hostname,$username,$password,$database);
    $sql="SET NAMES utf8";
    $query = mysqli_query($con,$sql);
    $sql="SELECT * FROM `reports` WHERE 1 ORDER BY `report_id` DESC LIMIT 20";
    $query = mysqli_query($con,$sql);
    echo '<script type="text/javascript">';
    $i=0;
    while ($row = mysqli_fetch_array($query)) {
       // echo 'marker['.$i++.'] = L.marker(['.$row['geolocation'].']).addTo(map);';
        echo 'marker['.$i++.'] = L.marker(['.$row['geolocation'].']).addTo(map) .bindPopup("<b>'.$row['category'].'</b><br />';
        echo '<a href=./report/?id=';
        echo $row['report_id'];
        echo '>';
        echo  date("d M Y", strtotime($row['time']));
        echo '</a> ';
        echo $row['description'].'");';
        //echo "<br/>";
	}
    echo '</script>';
    ?>
    <div id="reports" > 
    <h3>Τελευταίες 20 αναφορές</h3>
    <?php
    $query = mysqli_query($con,$sql);
    while ($row = mysqli_fetch_array($query)) {
        echo '<a href="./report/?id=';
        echo $row['report_id'];
        echo '">';
        echo date("d/m/Y", strtotime($row['time'])).' '.$row['category'];
        echo '</a> ';
        if ($row['situation']==0){
          echo "&#10004;";
        }
        echo "<br/>";
	}
	?>
    </div>
</body>
</html>
