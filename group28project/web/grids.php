 <?php
$a = @$_REQUEST['action']; 
if(empty($a)) $a= "index";
?>
<?php  include 'connectdb.php'; ?>
 
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
<!--static chart-->
<script src="js/Chart.min.js"></script>
<!--//charts-->
<!-- geo chart -->
    <script src="//cdn.jsdelivr.net/modernizr/2.8.3/modernizr.min.js" type="text/javascript"></script>
    <script>window.modernizr || document.write('<script src="lib/modernizr/modernizr-custom.js"><\/script>')</script>
    <!--<script src="lib/html5shiv/html5shiv.js"></script>-->
     <!-- Chartinator  -->
    <script src="js/chartinator.js" ></script>
    <script type="text/javascript">
        jQuery(function ($) { 
            var chart3 = $('#geoChart').chartinator({ tableSel: '.geoChart', columns: [{role: 'tooltip', type: 'string'}],
          colIndexes: [2], rows: [
                    ['China - 2015'], ['Colombia - 2015'], ['France - 2015'], ['Italy - 2015'], ['Japan - 2015'],
                    ['Kazakhstan - 2015'], ['Mexico - 2015'], ['Poland - 2015'], ['Russia - 2015'], ['Spain - 2015'],
                    ['Tanzania - 2015'], ['Turkey - 2015']], 
                ignoreCol: [2], chartType: 'GeoChart', chartAspectRatio: 1.5, chartZoom: 1.75,  
                chartOffset: [-12,0], chartOptions: {  width: null,     backgroundColor: '#fff', 
                    datalessRegionColor: '#F5F5F5',  region: 'world',  resolution: 'countries', legend: 'none', colorAxis: {
                        colors: ['#679CCA', '#337AB7']
                    }, tooltip: {  trigger: 'focus',isHtml: true
                    }
                } 
            });                       
        });
    </script>
<!--geo chart--> 
<!--skycons-icons-->
<script src="js/skycons.js"></script>
<!--//skycons-icons-->
</head>

<body>	 
<?php ?> 
<div class="page-container">	
   <div class="left-content">
	   <div class="mother-grid-inner">
            <!--header start here-->
				<div class="header-main" style="background-color:lightgreen; border: 1px solid red;">
					<div class="header" >
							<div class="logo-name">
									 <a > <h1 style="text-shadow:4px -4px black;">READY JOBS</h1> 
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
				}else{ $(".header-main").removeClass("fixed"); }
			 }); 
		});
		 
		</script> 
		<!-- /script-for sticky-nav --> 
		</div> 
		
<!--mainpage chit-chating--> 
<table border="1" width="900px" cellspacing="0" cellpadding="0" >
<tr width="20">
<div class="chit-chat-layer1">
    <div id="clearfix"></div>
	      <div class="col-md-6 chit-chat-layer1-left" > </div> 
	      
		  <div id="newrows" style="margin-top:200px; background-color:NavajoWhite"></div>
		    
     <div class="clearfix"> </div>
</div>
<tr>
</table>
<!--main page chit chating end here-->
 
<!--different-->
<div class="chart-layer-2">  </div>
 
<!--inner block end here-->
 

<!--copy rights start here-->
 
<!--COPY rights end here--> 
</div>



 	<div class="clearfix"> </div>
</div>



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
            
            $.post('tmpwrite.php',{flag:1}, function(dbdata){
					$("#newrows").html(dbdata); 
				   });
</script>
<!--scrolling js-->
		<script src="js/jquery.nicescroll.js"></script>
		<script src="js/scripts.js"></script>
		<!--//scrolling js-->
<script src="js/bootstrap.js"> </script>
<!-- mother grid end here-->

     <?php ?>   
    
    <?php  ?>
    
   <!----------------------------------------------->
     
    <!-----------------------------------------------> 

</body>
</html>                     
