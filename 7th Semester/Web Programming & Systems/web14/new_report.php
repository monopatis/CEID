<?php 
session_start(); 

?>
<!DOCTYPE HTML>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=0.8, maximum-scale=1.0, user-scalable=no" />

<title>New report form</title>
<link rel="shortcut icon" href="favicon.png" />
<link rel="stylesheet" href="http://cdn.leafletjs.com/leaflet-0.7.2/leaflet.css" />
<script src="http://cdn.leafletjs.com/leaflet-0.7.2/leaflet.js"></script>
<script>
    var location;
</script>

<link rel="stylesheet" type="text/css" href="styles.css">
</head>
<body>
    <?php include 'navigation.php';?>
    <?php 
        if ($_SESSION['user_id']==""){
            echo "Για νέο report κάντε login ή register";
        }
        else {
    ?>
<form id="cat" name="new_report_handler" method="post" action="new_report_handler.php" enctype="multipart/form-data">
Κατηγορία:&nbsp;
<select name="category">
<?php
    $hostname="localhost"; //local server name default localhost
    $username="web";  //mysql username default is root.
    $password="web2014";       //blank if no password is set for mysql.
    $database="web14";  //database name which you created
    $con=mysqli_connect($hostname,$username,$password,$database);
    $sql="SET NAMES utf8";
    $query = mysqli_query($con,$sql);
    $sql="SELECT * FROM categories";
    $query = mysqli_query($con,$sql);
    while ($row = mysqli_fetch_array($query)) {
        echo '<option value="'.$row['name'].'">'.$row['name'].'</option>';
    }
?>
</select><br>
Location:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input id="location" size="15" type="text" name="location" value=""><br>
Σύντομη περιγραφή:<br><textarea rows="3" cols="30" name="description" ></textarea><br>
<li>Φωτογραφία 1:<input type="file" name="image[0]" accept="image/*"></li>
<li>Φωτογραφία 2:<input type="file" name="image[1]" accept="image/*"></li>
<li>Φωτογραφία 3:<input type="file" name="image[2]" accept="image/*"></li>
<li>Φωτογραφία 4:<input type="file" name="image[3]" accept="image/*"></li>

<input type="submit" name="submit" value="submit">
<div id="map"></div>
</form>
 
<script type="text/javascript">
    var map = L.map('map').setView([38.385, 24.236], 6);
    CM_ATTR = '';
    CM_URL = 'http://{s}.tile.osm.org/{z}/{x}/{y}.png';
    L.tileLayer(CM_URL, {attribution: CM_ATTR, styleId: 997}).addTo(map);
    
var popup = L.popup();
function onMapClick(e) {
    var geolocation = e.latlng.toString();
    geolocation = geolocation.replace('LatLng(','');
    geolocation = geolocation.replace(')','');
    document.getElementById('location').value = geolocation;
     
    popup
        .setLatLng(e.latlng)
        .setContent(e.latlng.toString().replace('LatLng(','').replace(')',''))
        .openOn(map);
}
function onLocationFound(e) {
    var radius = e.accuracy / 2;
    var geolocation = e.latlng.toString();
    geolocation = geolocation.replace('LatLng(','');
    geolocation = geolocation.replace(')','');
    document.getElementById('location').value = geolocation;
    L.marker(e.latlng).addTo(map)
    .bindPopup("You are within " + radius + " meters from this point").openPopup();
    L.circle(e.latlng, radius).addTo(map);                }             
    function onLocationError(e) { 
        alert(e.message);}
    map.on('locationfound', onLocationFound);
    map.on('locationerror', onLocationError);
    map.locate({setView: true, maxZoom: 16});
    map.on('click', onMapClick);
</script>
<?php
    }
?>
</body>
</html>
