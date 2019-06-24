<?php
 header("Content-Type: application/rss+xml; charset=UTF-8");
 $rssfeed = '<?xml version="1.0" encoding="UTF-8" ?>';
 $rssfeed .= '<rss version="2.0">';
 $rssfeed .= '<channel>';
 $rssfeed .= '<title>Kαταστροφές</title>';
 $rssfeed .= '<link>http://web.monopatis.com/web/</link>';
  $rssfeed .= '<description>Καταγραφή καταστροφών</description>';
   $hostname="localhost"; //local server name default localhost
   $username="web";  //mysql username default is root.
   $password="web2014";       //blank if no password is set for mysql.
   $database="web14";  //database name which you created
   $con=mysqli_connect($hostname,$username,$password,$database);
   $sql="SET NAMES utf8";
   $query = mysqli_query($con,$sql);
   $sql="SELECT * FROM `reports` WHERE 1 ORDER BY `report_id` DESC LIMIT 20";
   $query = mysqli_query($con,$sql);
   while ($row = mysqli_fetch_array($query)) {
      $rssfeed .= '<item>';
      $rssfeed .= '<title>' . $row['geolocation'] . '</title>';
      $rssfeed .= '<link>' . 'http://web.monopatis.com/web/report/?id=' . $row['report_id'] . '</link>';
      $rssfeed .= '<description>' .'Κατηγορία: '. $row['category'].' Περιγραφή: ' . $row['description'] . '</description>';
      $rssfeed .= '<pubDate>' . date("D, d M Y H:i:s O", strtotime($row['time'])) . '</pubDate>';
      $rssfeed .= '</item>';
   }
  $rssfeed .= '</channel>';
 $rssfeed .= '</rss>';
 echo $rssfeed;

  ?>
    