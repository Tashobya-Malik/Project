
<?php session_start(); ?>
 
<!DOCTYPE HTML>
<html>
<head>
<title>Server Task Scheduling</title>
<!---------------------------->
<script type="text/javascript" src="jqr/jq_file.js"></script>
<script type="text/javascript" src="jqr/jq-ui.js"></script>
<!----------------------------->
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="keywords" content="Shoppy Responsive web template, Bootstrap Web Templates, Flat Web Templates, Android Compatible web template, 
Smartphone Compatible web template, free webdesigns for Nokia, Samsung, LG, SonyEricsson, Motorola web design" />
<script type="application/x-javascript"> addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false); function hideURLbar(){ window.scrollTo(0,1); } </script>
<!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
<link href="css/bootstrap.css" rel="stylesheet" type="text/css" media="all">
<!-- Custom Theme files -->
<link href="css/style.css" rel="stylesheet" type="text/css" media="all"/>
<!--js-->
<script src="js/jquery-2.1.1.min.js"></script> 
<!--icons-css-->
<link href="css/font-awesome.css" rel="stylesheet"> 
<!--Google Fonts-->
<link href='//fonts.googleapis.com/css?family=Carrois+Gothic' rel='stylesheet' type='text/css'>
<link href='//fonts.googleapis.com/css?family=Work+Sans:400,500,600' rel='stylesheet' type='text/css'>
<!--//skycons-icons-->
</head>
<body>	
<div class="page-container">	
   <div class="left-content">
	   <div class="mother-grid-inner">
            <!--header start here-->
				<div class="header-main" style="background-color:lightgreen; border: 1px solid red;">
					<div class="header" >
							<div class="logo-name">
									 <a > <h1 style="text-shadow:4px -4px black;">SUCCESS RATES</h1> 
									<!--<img id="logo" src="" alt="Logo"/>--> 
								  </a> 								
							</div>
				
				
							<div class="clearfix"> </div>
						 </div>
				
				
				
						 <div class="header-right" style=" text-align:center; font-weight:800;  border-radius:4px; padding-bottom:10px;">
							<div class="profile_details_left"><!--notifications of menu start -->
								
								
								<ul class="nofitications-dropdown">
									<li class="dropdown head-dpdn">

									<li class="dropdown head-dpdn">
									
										<ul class="dropdown-menu">
											<li>
												
												
										<!--		<div class="notification_header"> -->
									</li>	
								</ul>
								<div class="clearfix"> </div>
							</div>
							<!--notification menu end -->
							<div class="profile_details" style="">		
								<div class="row">
								 <a href="portlet.php"><div class="col-md-2" style="border:2px solid blue; border-radius:8px; padding:2px; margin:3px; background-color:skyblue; color:white">waiting jobs</div></a>
								 <a href="grids.php"><div class="col-md-2" style="border:2px solid blue; border-radius:8px; padding:2px; margin:3px; background-color:skyblue; color:white">ready jobs</div></a>
								 <a href="sucess.php"><div class="col-md-2" style="border:2px solid blue; border-radius:8px; padding:2px; margin:3px; background-color:skyblue; color:white">sucees rate</div></a>
								 <a href="typography.php"><div class="col-md-2" style="border:2px solid blue; border-radius:8px; padding:2px; margin:3px; background-color:skyblue; color:white">failure rate</div></a>
								 <a href="chart.php"><div class="col-md-2" style="border:2px solid blue; border-radius:8px; padding:2px; margin:3px; background-color:skyblue; color:white">average prate</div></a>
								 </div>
							</div>
							<div class="clearfix"> </div>				
						</div>
				     <div class="clearfix"> </div>	
				</div>
<!--heder end here-->
<!-- script-for sticky-nav -->
		<script>
		$(document).ready(function() {
			 var navoffeset=$(".header-main").offset().top;
			 $(window).scroll(function(){
				var scrollpos=$(window).scrollTop(); 
				if(scrollpos >=navoffeset){
					$(".header-main").addClass("fixed");
				}else{
					$(".header-main").removeClass("fixed");
				}
			 });
			 
		});
		</script>
		<!-- /script-for sticky-nav -->
<!--inner block start here-->
<div class="inner-block">
     <div class="typography">
     	
     	
      <div class="typo-progresses">
        <div class="page-header">
        <h3>Progress bars</h3>
      </div>
      
      <?php  include 'connectdb.php';
						
						mysqli_select_db($con,"recessdb") or die("couldn't find db");
						
						
	  //======================================
       $tm = time();
       $readbusyReady = "SELECT b.Std_ID,COUNT(b.JOB_ID) as jobsent,COUNT(t.Job_ID) AS jobsprocessed, (COUNT(t.JOB_ID)/COUNT(b.Job_ID))*100 as success, 100-((COUNT(t.JOB_ID)/COUNT(b.Job_ID))*100) as failure FROM busylist b JOIN readyjobs t ON t.Std_ID = b.Std_ID GROUP BY b.Std_ID;";
      $table2data = mysqli_query($con,$readbusyReady); 
               echo "<table>"; 
	   while($valu=@mysqli_fetch_array($table2data)){
	    $stid = $valu['Std_ID']; $suces = (int)$valu['success']; $failr = (int)$valu['failure'];  
	    echo "<p>"; echo '<div style="font-size:24px; font-weight:800; ">'.$stid;  echo "  >>>>>  ".$failr."%"." </div>"; 
	    echo "<hr/>";
		echo "</p>"; echo'  <div class="col-md-2" >  <div class="col-md-11" style="width:'.'"> <span class="sr-only"> </span></div></div>';  echo"</p>"; 
		}  echo"</table>";
	  //======================================		
 
    ?>  
    
         </div>
     </div>
</div>
<!--inner block end here-->
<!--copy rights start here-->
 
<!--COPY rights end here-->
</div>
</div>
<!--slider menu-->
     
<!--slide bar menu end here-->
<script>
var toggle = true;
            
$(".sidebar-icon").click(function() {                
  if (toggle)
  {
    $(".page-container").addClass("sidebar-collapsed").removeClass("sidebar-collapsed-back");
    $("#menu span").css({"position":"absolute"});
  }
  else
  {
    $(".page-container").removeClass("sidebar-collapsed").addClass("sidebar-collapsed-back");
    setTimeout(function() {
      $("#menu span").css({"position":"relative"});
    }, 400);
  }               
                toggle = !toggle;
            });
</script>
<!--scrolling js-->
		<script src="js/jquery.nicescroll.js"></script>
		<script src="js/scripts.js"></script>
		<!--//scrolling js-->
<script src="js/bootstrap.js"> </script>
  
<!-- mother grid end here-->
</body>
</html>                			
