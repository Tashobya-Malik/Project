	<!--============================================-->
    <?php
    if(isset($_POST['flag'])){
  
     include 'connectdb.php';  
     mysqli_select_db($con,"recessdb") or die("couldn't find db"); 
     $from= "select DISTINCT * from readyjobs";
     $result = mysqli_query($con,$from);
     if (!$result) { printf("Error: %s\n", mysqli_error($con));  exit(); }  
                        
                        echo "<table class='table table-hover'>";
                             echo "<thead>
                                          <tr><th>Priority</th> <th>Std_ID</th> <th>Job_ID</th> <th>Status</th>
                                             <th>Duration</th> <th>Task_type</th> <th>Task_String</th> <th>Result_strg</th>
                                          </tr>
                             </thead>";
                                                   
                              while($value=mysqli_fetch_array($result)){
                                $prio = $value['Priority'];  $studi = $value['Std_ID'];  $jobi=$value['Job_ID']; 
                                $statu=$value['Status']; $dura=$value['Duration'];  $tas_typ=$value['Task_type']; 
                                $tstr =$value['Task_String']; $resl =$value['Result'];
                                echo "<tr> <td>".$prio."</td><td>".$studi."</td><td>".$jobi.
                                "</td><td><span class=\"\">".$statu.
                                "</span></td><td><span class=\"\">".$dura.
                                "</span></td><td style=\"color:black;\">". $tas_typ.
                                "</td><td style=\"color:black;\">".$tstr."<td><td style=\"color:black;\">".$resl.
                                "</td></tr>"; 
                               }
                       
                       
                       echo '</table>'; 
                       
                    }
             ?>
     
      <!--==========================================--> 
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      	
				
