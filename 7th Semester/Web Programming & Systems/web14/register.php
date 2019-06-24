<!DOCTYPE HTML>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=0.8, maximum-scale=1.0, user-scalable=no" />
<title>REGISTRATION FORM</title>
<link rel="shortcut icon" href="favicon.png" />
<link rel="stylesheet" type="text/css" href="styles.css">
</head>
<body>
<?php include 'navigation.php';?>
<form id="reg" name="registration" method="post" action="registration.php">
<table>
<tr>
  <td>Όνομα:</td>
  <td><input type="text" name="name" value=""></td>		
  </tr>
<tr>
  <td>Email:</td>
  <td><input type="text" name="email" value=""></td>		
  </tr>
<tr>
  <td>Password:</td>
  <td><input type="password" name="password" value=""></td>
  </tr>
<tr>
  <td>Τηλέφωνο:</td>
  <td><input type="text" name="telephone" value=""></td>
  </tr>
</table>
<input type="submit" name="submit" value="submit">
</form>

</body>
</html>