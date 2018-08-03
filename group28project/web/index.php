
<?php
$a = @$_REQUEST['action']; 
if(empty($a)) $a= "index";
?>
 
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

            var chart3 = $('#geoChart').chartinator({
                tableSel: '.geoChart',

                columns: [{role: 'tooltip', type: 'string'}],
         
                colIndexes: [2],
             
                rows: [
                    ['China - 2015'],
                    ['Colombia - 2015'],
                    ['France - 2015'],
                    ['Italy - 2015'],
                    ['Japan - 2015'],
                    ['Kazakhstan - 2015'],
                    ['Mexico - 2015'],
                    ['Poland - 2015'],
                    ['Russia - 2015'],
                    ['Spain - 2015'],
                    ['Tanzania - 2015'],
                    ['Turkey - 2015']],
              
                ignoreCol: [2],
              
                chartType: 'GeoChart',
              
                chartAspectRatio: 1.5,
             
                chartZoom: 1.75,
             
                chartOffset: [-12,0],
             
                chartOptions: {
                  
                    width: null,
                 
                    backgroundColor: '#fff',
                 
                    datalessRegionColor: '#F5F5F5',
               
                    region: 'world',
                  
                    resolution: 'countries',
                 
                    legend: 'none',

                    colorAxis: {
                       
                        colors: ['#679CCA', '#337AB7']
                    },
                    tooltip: {
                     
                        trigger: 'focus',

                        isHtml: true
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

<?php  ?>
   	

<div class="page-container">	
   <div class="left-content">
	   <div class="mother-grid-inner">
            <!--header start here-->
				<div  class="header-main">
					<div class="header">
							<div class="logo-name">
									 <a href="index.php"> <h1>Server Processing</h1> 
									<!--<img id="logo" src="" alt="Logo"/>--> 
								  </a> 								
							</div>
							
						<!--	<div class="clearfix"> </div> -->
						 </div>
						 
						 
						 <div class="header-right">
							
							
							
							
							<div class="profile_details">		
								<div class="row">
								 <a href="portlet.php"><div class="col-md-2" style="border:2px solid blue; border-radius:4px; padding:2px; margin:2px;">waiting jobs</div></a>
								 <a href="grids.php"><div class="col-md-2" style="border:2px solid blue; border-radius:4px; padding:2px; margin:2px;">ready jobs</div></a>
								 <a href="sucess.php"><div class="col-md-2" style="border:2px solid blue; border-radius:4px; padding:2px; margin:2px;">sucees rate</div></a>
								 <a href="typography.php"><div class="col-md-2" style="border:2px solid blue; border-radius:4px; padding:2px; margin:2px;">failure rate</div></a>
								 <a href="index.php"><div class="col-md-2" style="border:2px solid blue; border-radius:4px; padding:2px; margin:2px;">average prate</div></a>
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
			 Refreshpage(5000);
			 function Refreshpage($seconds){
			  setInterval("ref()",$seconds);
			 }
			 function ref(){
			   location.reload();
			 }
		});
		</script>
		
		
		<!-- /script-for sticky-nav -->
<!--inner block start here-->
<div class="inner-block">
<!--market updates updates-->
	 <div class="market-updates">
			<div class="col-md-4 market-update-gd">
				<div class="market-update-block clr-block-1">
					<div class="col-md-8 ">
						<h3>
						<?php  include 'connectdb.php';
						
						mysqli_select_db($con,"recessdb") or die("couldn't find db");

						$sq ="SELECT count(DISTINCT Job_ID) AS sucess FROM readyjobs ";
						$result=mysqli_query($con,$sq);
						$values = @mysqli_fetch_assoc($result);
						 $num=$values['sucess'];
						 //echo $values;
						 echo @$num; 
						 ?> 
						</h3>
						<h4>Sucessful job</h4> 
					</div>
					
					 
				  <div class="clearfix"> </div>
				</div>
			</div>
			<div class="col-md-4 market-update-gd">
				<div class="market-update-block clr-block-2">
				 <div class="col-md-8  ">
					<h3><?php  include 'connectdb.php';
						
						mysqli_select_db($con,"recessdb") or die("couldn't find db");

						$sq ="SELECT count(DISTINCT JOB_ID) AS Failed FROM busylist ";
						$result=mysqli_query($con,$sq);
						$values=@mysqli_fetch_assoc($result);
						 $num=$values['Failed'];
						 //echo $values;
						 echo @$num; 
						 ?>
						 
					</h3>
					<h4>Busy Jobs</h4>
					
				  </div>
					 
				  <div class="clearfix"> </div>
				</div>
			</div>
			<div class="col-md-4 market-update-gd">
				<div class="market-update-block clr-block-3">
					<a href="blacklst.php"><div class="col-md-8  ">
						<h3>
						
						<?php  include 'connectdb.php';
						
						mysqli_select_db($con,"recessdb") or die("couldn't find db");

						$sq ="SELECT count(DISTINCT *) AS Failed FROM blacklisted ;";
						$result=mysqli_query($con,$sq);
						$values=@mysqli_fetch_assoc($result);
						 $num=$values['Failed'];
						 //echo $values;
						 echo @$num;
						 
						 ?>
						 </h3>
						<h4>Blacklisted jobs</h4>
						
					</div></a>
					 
				  <div class="clearfix"> </div>
				</div>
			</div>
		   <div class="clearfix"> </div>
		</div>
<!--market updates end here-->
<!--mainpage chit-chating-->

<table border="" width="900px" border="0" cellspacing="0" cellpadding="0" >
<tr width="20">
<div class="chit-chat-layer1">
	<div class="col-md-6 chit-chat-layer1-left">
              <!-- <div class="work-progres">-->
                           <!-- <div class="table-responsive"> -->
                           
                           
                           
                           <?php include 'connectdb.php'; 
                           
                         mysqli_select_db($con,"recessdb") or die("couldn't find db");


$from= "select * from readyjobs";
$result = mysqli_query($con,$from);
if (!$result) {
    printf("Error: %s\n", mysqli_error($con));
    exit();
}


$from1 = "select DISTINCT * from status WHERE status='IN-PROGRESS'";
$result1 = mysqli_query($con,$from1);
if (!$result1) {
    printf("Error: %s\n", mysqli_error($con));
    exit();
}

        
                                echo"<table class='table table-hover'->";
                                  echo"<thead>
                                    <tr>
                                      <th>Priority</th>
                                      <th>Std_ID</th>
                                      <th>Job_ID</th>                                   
                                                                        
                                      <th>Status</th>
                                      <th>Time_recd</th>
                                      <th>Task_type</th>
                                      <th>Task_String</th>
                                  </tr>
                              </thead>";
                              
while($value=mysqli_fetch_array($result)){                              
                            //  echo'<tbody>';
   
       while($value1 = mysqli_fetch_array($result1)){                             
                                
   if($value['Job_ID']== $value1['JOB_ID']){ 
                                
                                echo'<tr>
                                  <td>'; echo $value['Priority'];
                                  echo'</td>';
                                   
                                  echo'<td>';
                                  echo $value['Std_ID'];
                                  echo'</td>';
                                   
                                  echo'<td>';
                                  echo $value['Job_ID'];
                                  echo'</td>';                                 
 
                        //    if($value1['JOB_ID']== $value['Job_ID']){                                
                                  echo'<td><span class=">';
                                   echo $value1['status'];
                                   
                                  echo'</span></td>'; //} 
                                  echo'<td><span class="badge ">'; echo $value['curtimestamp'];
                                  echo'</span></td>'; 
                                  echo'<td style="color:black;">';
                                  echo $value['Task_type']; 
                                  echo'</td>';
                                   echo'<td style="color:black;">'; echo $value['Task_String'];
                                    echo'</td></tr>'; 
                        break;
                           
                           } 
                        } 
                    }
                    
  //echo 'tbody';
  echo '</table>';  
                 
      ?>
      <!-- .wrapper-flex -->
				</section>				
			</div>
      </div>
     <div class="clearfix"> </div>
</div>
<!--main page chit chating end here-->
  </div>
 </div>
<!--different-->
<div class="chart-layer-2">
	<!--
	
	      //Progress bars-->
	      </div>
	</div>
	
	
<!-- table data-->	

		
<!--climate end here-->
</div>
<!--inner block end here-->
<!--copy rights start here-->
 	
<!--COPY rights end here-->
</div>
</div>
<!--slider menu--> 
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

     <?php ?> 
    
    <?php  ?>
    <!----------------------------------------------->
    <script>
         
    </script>
    <!----------------------------------------------->
</body>
</html>                     
