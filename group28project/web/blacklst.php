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

<?php if(isset($_SESSION['nme'])){ ?>
   	

<div class="page-container">	
   <div class="left-content">
	   <div class="mother-grid-inner">
            <!--header start here-->
				<div  class="header-main">
					<div class="header">
							<div class="logo-name">
									 <a href="index.php"> <h1>Ready Jobs</h1> 
									<!--<img id="logo" src="" alt="Logo"/>--> 
								  </a> 								
							</div>
							
						<!--	<div class="clearfix"> </div> -->
						 </div>
						 
						 
						 <div class="header-right">
							
							
							
							
							<div class="profile_details">		
								<ul>
									<li class="dropdown profile_details_drop">
										<a href="#" class="dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
											<div class="profile_img">	
												<span class="prfil-img"><img src="images/p1.jpeg" alt="" height="50px" widith="10px"> </span> 
												<div class="user-name">
													<p><?php 
													
													echo @$_SESSION["nme"];
													
													?> </p>
													<span>Administrator</span>
												</div>
												<i class="fa fa-angle-down lnr"></i>
												<i class="fa fa-angle-up lnr"></i>
												<div class="clearfix"></div>	
											</div>	
										</a>
										<ul class="dropdown-menu drp-mnu">
											<li> <a href="#"><i class="fa fa-cog"></i> Settings</a> </li> 
											<li> <a href="#"><i class="fa fa-user"></i> Profile</a> </li> 
											<li> <a href="logout.php"><i class="fa fa-sign-out"></i> 
											
											
											Logout</a> </li>
										</ul>
									</li>
								</ul>
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
<!--market updates updates-->
	 <div class="market-updates">
			
			
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


$from= "select * from rejected where length != '';";
$result = mysqli_query($con,$from);
if (!$result) {
    printf("Error: %s\n", mysqli_error($con));
    exit();
}

//Std_ID VARCHAR(35), JOB_ID VARCHAR(30), Error  TEXT,orgtimestamp int(11),length int(11),string TEXT,curtimestamp TIMESTAMP
        
                                echo"<table class='table table-hover'->";
                                  echo"<thead>
                                    <tr>
                                      <th>Std_ID</th>
                                      <th>JOB_ID</th>
                                      <th>length</th>                                   
                                                                        
                                      <th>Error</th>
                                      <th>string</th>
                                      
                                  </tr>
                              </thead>";
                              
while($value=mysqli_fetch_array($result)){                              
                            
                                echo'<tr>
                                  <td>'; echo $value['Std_ID'];
                                  echo'</td>';
                                   
                                  echo'<td>';
                                  echo $value['JOB_ID'];
                                  echo'</td>';
                                   
                                                        
 
                                                       
                                  echo'<td><span class="label label-danger">';
                                   echo $value['length'];
                                  echo'</span></td>';  
                                  
                                  echo'<td><span class="badge badge-info">'; echo $value['Error'];
                                  echo'</span></td>'; 
                                  echo'<td style="color:red;">';
                                  echo $value['string']; 
                                    echo'</td></tr>'; 
                        //break;
                    }
                    
  //echo 'tbody';
  echo '</table>';  
                 // </div>
             //</div>
      //</div>
     // </div>
      
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
<div class="copyrights">
	 <p>© Task Scheduling <a href="">MUK</a> </p>
</div>	
<!--COPY rights end here-->
</div>
</div>
<!--slider menu-->
    <div class="sidebar-menu">
		  	<div class="logo"> <a href="#" class="sidebar-icon"> <span class="fa fa-bars"></span> </a> <a href="#"> <span id="logo" ></span> 
			      <!--<img id="logo" src="" alt="Logo"/>--> 
			  </a> </div>		  
		    <div class="menu">
		      <ul id="menu" >
		        <li id="menu-home" ><a href="index.php"><i class="fa fa-tachometer"></i><span>Dashboard</span></a></li>
		        <li><a href="#"><i class="fa fa-cogs"></i><span>JOBs</span><span class="fa fa-angle-right" style="float: right"></span></a>
		          <ul>
		            <li><a href="grids.php">Aready</a></li>
		            <li><a href="portlet.php">Waiting</a></li>		            
		          </ul>
		        </li>
		        <li id="menu-comunicacao" ><a href="#"><i class="fa fa-book nav_icon"></i><span>Rates</span><span class="fa fa-angle-right" style="float: right"></span></a>
		          <ul id="menu-comunicacao-sub" >
		            <li id="menu-mensagens" style="width: 120px" ><a href="sucess.php">Success rate</a>		              
		            </li>
		            <li id="menu-arquivos" ><a href="typography.php">Failure rates</a></li>
		  <!--          <li id="menu-arquivos" ><a href="icons.html">Icons</a></li>-->
		          </ul>
		        </li>
		          <!--<li><a href="maps.html"><i class="fa fa-map-marker"></i><span>Maps</span></a></li>-->
		        
	
	
	
	
	
	
    <?php ?>
    <li id="menu-academico" ><a href="logout.php"><i class="fa fa-file-text"></i><span>Logout</span><span class="fa fa-angle-right" style="float: right"></span></a>
		          <ul id="menu-academico-sub" >
	 
	</ul>
		        </li>
	 	        
		        <li><a href="chart.php"><i class="fa fa-bar-chart"></i><span>Average Rate</span></a></li>
		        		         <li><a href="#"><i class="fa fa-cog"></i><span>System</span><span class="fa fa-angle-right" style="float: right"></span></a>
		         	  
		         </li>
		       <!--  <li><a href="#"><i class="fa fa-shopping-cart"></i><span>E-Commerce</span><span class="fa fa-angle-right" style="float: right"></span></a>
		         	<ul id="menu-academico-sub" >
			            <li id="menu-academico-avaliacoes" ><a href="product.html">Product</a></li>
			            <li id="menu-academico-boletim" ><a href="price.html">Price</a></li>
		             </ul>
		         </li>-->
		      </ul>
		    </div>
	 </div>
	<div class="clearfix"> </div>
</div>
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

     <?php  ?> 
    
    <?php  ?>
    <script>
         
    </script>
    

</body>
</html>                     
