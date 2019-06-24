<?php
session_start(); 
?>
<div id="bar">
<ul>
<li><a id="nav" href="index.php">Home</a></li>
<li><a id="nav" href="new_report.php">New Report</a></li>
<li><a id="nav" href="rss.php">RSS</a></li>
	<?php 
	if ($_SESSION['user_id']==""){
		echo '<li><a id="nav" href="register.php">Register</a></li>';
		echo '<li><a id="nav" href="login.php"> Log in</a></li>';
	}
	else {
		echo '<li><a id="nav" href="profile.php">'.$_SESSION['name'].'</a></li>';
		echo '<li><a id="nav" href="logout.php">Log out</a></li>';
	}
?>
</ul>
</div>