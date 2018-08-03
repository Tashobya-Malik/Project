<?php

$servername = "localhost";
$accountnm  = "root";
$password   = "";
$database   = "recessdb";

$con = mysqli_connect ($servername,$accountnm,$password);  
if($con==false){
	die("ERROR:Could not connect. " . mysqli_connect_error());
}

//=======================CREATING THE highschooldb DATABASE========================================================
$dbcreate = "CREATE DATABASE recessdb";
if(mysqli_query($con, $dbcreate)){ echo "recess Database created successfully <br /><br /><br />"; }

mysqli_select_db($con,"recessdb");
 
//readyjobs
$appnbanktable = "CREATE TABLE readyjobs(Std_ID VARCHAR(35), Job_ID VARCHAR(30),Status  TEXT , Duration varchar(11), Task_type TEXT, Task_String TEXT,Priority varchar(50),Result varchar(200) )";
     if(mysqli_query($con, $appnbanktable)){ echo "readyjobs table created successfully.<br />"; }
  
  //busylist
  $stdbanktable = "CREATE TABLE busylist(JOB_ID VARCHAR(12), Std_ID VARCHAR(12), Task_Type VARCHAR(12), Task_String VARCHAR(60),
		       Daterecv VARCHAR(12),Timerecv VARCHAR(12) )";
	  if(mysqli_query($con, $stdbanktable)){ echo "Busylist Table created successfully.<br />"; }
	  //status
	  $status = "CREATE TABLE status(JOB_ID VARCHAR(12), Task_Type VARCHAR(12), Task_String VARCHAR(60),status varchar(20))";
	  if(mysqli_query($con, $status)){ echo "status Table created successfully.<br />"; }

			  
	//rejected
$tbrejected = "CREATE TABLE blacklisted (Std_ID VARCHAR(35), JOB_ID VARCHAR(30), Error  TEXT, length int(11),string TEXT)";
    if(mysqli_query($con, $tbrejected)){ echo " Blacklisted created successfully.<br />"; }

//average rate
$avrate = "CREATE TABLE av_rate (Average_rate int(11))";
    if(mysqli_query($con, $avrate)){ echo " average rate table created successfully.<br />"; }



?>


