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
  <title>ADMIN</title>
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
   //*** Update Condition ***//
if($_POST["hdnCmd"] == "Update")
{
$strSQL = "UPDATE users SET ";
$strSQL .="user_id = '".$_POST["txtEdituser_id"]."' ";
$strSQL .=",username = '".$_POST["txtEdituser_username"]."' ";
$strSQL .=",password = '".$_POST["txtEdituser_password"]."' ";
$strSQL .=",name = '".$_POST["txtEdituser_name"]."' ";
$strSQL .=",email = '".$_POST["txtEdituser_email"]."' ";
$strSQL .=",telephone = '".$_POST["txtEdituser_telephone"]."' ";
$strSQL .=",is_admin = '".$_POST["txtEdituser_is_admin"]."' ";
$strSQL .="WHERE user_id = '".$_POST["hdnEdituser_id"]."' ";
$objQuery = mysqli_query($con, $strSQL);
if(!$objQuery)
{
	echo "Error Update [".mysqli_error()."]";
}
}
//*** Delete Condition ***//
if($_GET["Action"] == "Del")
{
$strSQL = "DELETE FROM users ";
$strSQL .="WHERE user_id = '".$_GET["UserID"]."' ";
$objQuery = mysqli_query($con, $strSQL);
if(!$objQuery)
{
	echo "Error Delete [".mysqli_error()."]";
}
}
if ($_SESSION['is_admin'] == "1")
{
    $sql="SELECT * FROM users ORDER BY user_id ASC";
    $query = mysqli_query($con,$sql);
    ?>
<form id="admin" name="frmMain" method="post" action="<?=$_SERVER["PHP_SELF"];?>">
<input type="hidden" name="hdnCmd" value="">
<table width="600" border="1">
  <tr>
    <th > <div>ID </div></th>
    <th > <div>Username </div></th>
    <th > <div>Password </div></th>
    <th > <div>Name </div></th>
    <th > <div>Email </div></th>
    <th > <div>Telephone </div></th>
    <th > <div>isAdmin </div></th>
    <th > <div>Edit </div></th>
    <th > <div>Delete </div></th>
  </tr>
<?php
    while($objResult = mysqli_fetch_array($query))
	{
	?>
	<?php
	if($objResult["user_id"] == $_GET["UserID"] and $_GET["Action"] == "Edit")
	{
		?>
		<tr>
    <td><div>
		<input type="text" name="txtEdituser_id" size="5" value="<?php echo $objResult["user_id"];?>">
		<input type="hidden" name="hdnEdituser_id" size="5" value="<?php echo $objResult["user_id"];?>">
	</div></td>
    <td><input type="text" name="txtEdituser_username" size="5" value="<?php echo $objResult["username"];?>"></td>
    <td><input type="text" name="txtEdituser_password" size="5" value="<?php echo $objResult["password"];?>"></td>
    <td><div align="center"><input type="text" name="txtEdituser_name" size="5" value="<?php echo $objResult["name"];?>"></div></td>
    <td ><input type="text" name="txtEdituser_email" size="5" value="<?php echo $objResult["email"];?>"></td>
    <td ><input type="text" name="txtEdituser_telephone" size="5" value="<?php echo $objResult["telephone"];?>"></td>
    <td ><input type="text" name="txtEdituser_is_admin" size="5" value="<?php echo $objResult["is_admin"];?>"></td>
    <td colspan="2" align="right"><div align="center">
      <input name="btnAdd" type="button" id="btnUpdate" size="5" value="Update" OnClick="frmMain.hdnCmd.value='Update';frmMain.submit();">
	  <input name="btnAdd" type="button" id="btnCancel" size="5" value="Cancel" OnClick="window.location='<?php echo $_SERVER["PHP_SELF"];?>';">
    </div></td>
  </tr>
  <?php
	}
  else
	{
  ?>
  <tr>
    <td><div align="center"><?php echo $objResult["user_id"];?></div></td>
    <td><?php echo $objResult["username"];?></td>
    <td><?php echo $objResult["password"];?></td>
    <td><div align="center"><?php echo $objResult["name"];?></div></td>
    <td align="right"><?php echo $objResult["email"];?></td>
    <td align="right"><?php echo $objResult["telephone"];?></td>
    <td align="right"><?php echo $objResult["is_admin"];?></td>
    <td align="center"><a href="<?php echo $_SERVER["PHP_SELF"];?>?Action=Edit&UserID=<?php echo $objResult["user_id"];?>">Edit</a></td>
	<td align="center"><a href="JavaScript:if(confirm('Confirm Delete?')==true){window.location='<?php echo $_SERVER["PHP_SELF"];?>?Action=Del&UserID=<?php echo $objResult["user_id"];?>';}">Delete</a></td>
  </tr>
  <?php
	}
  ?>
  <?php
	}
}
?>
</table>
</form>
<?php
if($_POST["hdnCmd"] == "Update_c")
{
$strSQL = "UPDATE categories SET ";
$strSQL .="name = '".$_POST["txtEditcat_name"]."' ";
$strSQL .="WHERE name = '".$_POST["hdnEditcat_name"]."' ";
$objQuery = mysqli_query($con, $strSQL);
if(!$objQuery)
{
  echo "Error Update [".mysqli_error()."]";
}
}
//*** Delete Condition ***//
if($_GET["Action"] == "Delcat")
{
$strSQL = "DELETE FROM categories ";
$strSQL .="WHERE name = '".$_GET["CatNAME"]."' ";
$objQuery = mysqli_query($con, $strSQL);
if(!$objQuery)
{
  echo "Error Delete [".mysqli_error()."]";
}
}
if ($_SESSION['is_admin'] == "1")
{
    $sql="SELECT * FROM categories";
    $query = mysqli_query($con,$sql);
    ?>
<form id="admin" name="frmCat" method="post" action="<?=$_SERVER["PHP_SELF"];?>">
<input type="hidden" name="hdnCmd" value="">
<table width="600" border="1">
  <tr>
    <th > <div>Name</div></th>
  </tr>
<?php
    while($objResult = mysqli_fetch_array($query))
  {
  ?>
  <?php
  if($objResult["name"] == $_GET["CatNAME"] and $_GET["Action"] == "Edit")
  {
    ?>
    <tr>
    <td><div>
    <input type="text" name="txtEditcat_name" size="20" value="<?php echo $objResult["name"];?>">
    <input type="hidden" name="hdnEditcat_name" size="20" value="<?php echo $objResult["name"];?>">
  </div></td>
      <td colspan="2" align="right"><div align="center">
      <input name="btnAdd" type="button" id="btnUpdate" size="5" value="Update" OnClick="frmCat.hdnCmd.value='Update_c';frmCat.submit();">
    <input name="btnAdd" type="button" id="btnCancel" size="5" value="Cancel" OnClick="window.location='<?php echo $_SERVER["PHP_SELF"];?>';">
    </div></td>
  </tr>
  <?php
  }
  else
  {
  ?>
  <tr>
    <td><div align="center"><?php echo $objResult["name"];?></div></td>
    <td align="center"><a href="<?php echo $_SERVER["PHP_SELF"];?>?Action=Edit&CatNAME=<?php echo $objResult["name"];?>">Edit</a></td>
  <td align="center"><a href="JavaScript:if(confirm('Confirm Delete?')==true){window.location='<?php echo $_SERVER["PHP_SELF"];?>?Action=Delcat&CatNAME=<?php echo $objResult["name"];?>';}">Delete</a></td>
  </tr>
  <?php
  }
  }
}
?>
</table>
</form>
<form id="admin" name="new_category" method="post" action="new_category.php" accept-charset="utf-8">
Νέα κατηγορία: <input type="text" size="20" name="category" value="">
<input type="submit" name="submit" value="submit">
</form>
</body>
</html>
<?php
}
?>