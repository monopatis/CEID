<?php     //start php tag
session_start(); 
$hostname="localhost"; //local server name default localhost
$username="web";  //mysql username default is root.
$password="web2014";       //blank if no password is set for mysql.
$database="web14";  //database name which you created
//if submit is not blanked i.e. it is clicked.
If ($_SESSION['is_admin'] == "1")
{
If(isset($_REQUEST['submit'])!='')
{
If($_REQUEST['category']=='')
{
Echo "please fill the empty field.";
}
Else
{
    $con=mysqli_connect($hostname,$username,$password,$database);
    if(! $con)
    {
    die('Connection Failed'.mysql_error());
    }
    $sql="SET NAMES utf8";
    $query = mysqli_query($con,$sql);
    $sql="insert into categories(name) values('".$_REQUEST['category']."')";
    If(mysqli_query($con,$sql))
    {
        Echo "Record successfully inserted";
        header( "Location: admin.php" );
    }
    Else
    {
        Echo "There is some problem in inserting record. ". mysqli_error($con);
    }
}
}
}
?>
