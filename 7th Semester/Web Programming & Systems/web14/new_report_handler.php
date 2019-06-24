<?php     //start php tag
session_start(); 
ini_set("display_errors", 1);
ini_set("track_errors", 1);
ini_set("html_errors", 1);
error_reporting(E_ALL);
$hostname="localhost"; //local server name default localhost
$username="web";  //mysql username default is root.
$password="web2014";       //blank if no password is set for mysql.
$database="web14";  //database name which you created
$con=mysqli_connect($hostname,$username,$password,$database);
if(! $con)
{
die('Connection Failed'.mysql_error());
}
$sql="SET NAMES utf8";
$query = mysqli_query($con,$sql);

//if submit is not blanked i.e. it is clicked.
If(isset($_REQUEST['submit'])!='')
{
If($_REQUEST['location']=='')
{
Echo "please fill the empty field.";
}
Else
{
    move_uploaded_file($_FILES["image"]["tmp_name"][0],"images/".$_FILES["image"]["name"][0]);
    move_uploaded_file($_FILES["image"]["tmp_name"][1],"images/".$_FILES["image"]["name"][1]);
    move_uploaded_file($_FILES["image"]["tmp_name"][2],"images/".$_FILES["image"]["name"][2]);
    move_uploaded_file($_FILES["image"]["tmp_name"][3],"images/".$_FILES["image"]["name"][3]);
    $foto1 =$_FILES['image']['name'][0];
    $foto2 =$_FILES['image']['name'][1];
    $foto3 =$_FILES['image']['name'][2];
    $foto4 =$_FILES['image']['name'][3];
    echo "Stored in: " . "./images/". $_FILES['image']['name'][1];
    $sql="insert into reports(category,geolocation,description,foto_1,foto_2,foto_3,foto_4,situation,username) values('".$_REQUEST['category']."', '".$_REQUEST['location']."', '".$_REQUEST['description']."', '".$foto1."', '".$foto2."', '".$foto3."', '".$foto4."', '1','".$_SESSION['email']."')";
    If(mysqli_query($con,$sql))
    {
        Echo "Record successfully inserted";
        header( "Location: index.php" );
    }
    Else
    {
        Echo "There is some problem in inserting record. ". mysqli_error($con);
    }
}
}
?>
