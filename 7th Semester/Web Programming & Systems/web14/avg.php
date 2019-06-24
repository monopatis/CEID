<?php
	$hostname="localhost"; //local server name default localhost
    $username="web";  //mysql username default is root.
    $password="web2014";       //blank if no password is set for mysql.
    $database="web14";  //database name which you created
    $con=mysqli_connect($hostname,$username,$password,$database);
    $sql="SELECT * FROM `reports` WHERE `situation` = '0' ORDER BY `report_id` DESC";
    $query = mysqli_query($con,$sql);
    $i=0;
    $sumfix=0;
    while ($row = mysqli_fetch_array($query)) {
        $i++;
        $fix = strtotime($row['timefix']) - strtotime($row['time']);
        $sumfix = $sumfix + $fix;
    }
    $avg = $sumfix/$i;
    echo gmdate("d H:i:s", $avg);
?>