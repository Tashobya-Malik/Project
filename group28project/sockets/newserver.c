#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>
#include <netdb.h>
#define PORT 6900
#define BUFSIZE 1024
//==================structures============
struct myjobs encrproc(struct myjobs encrtask);
struct myjobs encrproc2(struct myjobs encrtask);
struct myjobs mainproc(struct myjobs mainjob);
struct myjobs decrproc(struct myjobs decrtask);
struct myjobs replproc(struct myjobs repltask);
struct myjobs delproc(struct myjobs var);
struct myjobs dblproc(struct myjobs jobject);
struct myjobs revproc(struct myjobs job);
struct myjobs decrproc2(struct myjobs decrtask);
void bbzero(char * strg);
int strchNo(char arr[]); 
int strbg(char strn[]); 
//=======task structure==============

struct myjobs {
            char commandd[12];
            char processedstring[80];
            char stringoptions[30];
	        char sender_id[12];
            char jobId[12];
	        char sourceIP[30];
	        int portNo;
	        char daterecv[15];
	        char timerecv[15]; 
            char processingDuration[12];
            char process_status[20];
            char priorityNo[12];
            int  charlength; 
            char resultStr[1200];  
         };

//structure instances 
struct myjobs job;
struct myjobs jobret;
struct myjobs jobrets;
struct myjobs ret_structr;
struct myjobs param_structr;
struct myjobs tempstruct;
struct myjobs structosend;
struct myjobs rtrn;
struct myjobs cpystruct;

//structure arrays
struct myjobs busylist[700];
struct myjobs shortask[50];// 1st priority
struct myjobs mostcommon[50];//2nd priority
struct myjobs replacetask[10];
struct myjobs otherpri[50];
struct myjobs readylist[200];
struct myjobs rejectedTask[40];
struct myjobs workingArr[10];//working array
struct myjobs workingArr2[10];
struct myjobs workingArr3[10];
struct myjobs workingArr4[10];
char commonID[10];
char sender_idcopy[10];
char sender_ids[10][10];
char tempstrg[80]; 
FILE *fileptrbusy;
FILE *fileptrrejected;
FILE *fileptrready;
FILE *fileptrstatus;

 time_t t; struct tm tmm;

int ras=0,bbg=0,bgg=0,ddx,end=9,ix=0,min,newMin,prior1pos,ax,sh=0,vvx, iix, occ, xi, maxoc, newMax,c,hh,cm, occurr[10], port; 
int ixx,cxx,x,zx,maxpos,cmpp,i1,i2,i3,i4,bxxx,rp,op=0,nextready=0,secs,starttime,curtime,bggr=0,endr=9,headerprinted=0;
int wa,wa2,wa3,wa4,startprocessing=0;
//========================================

void send_to_all(int j, int sockfd,  struct myjobs structosend, fd_set *master) {//sending to all
	if (FD_ISSET(j, master)){
		if (j != sockfd) {
			if (send(j, &structosend, sizeof(structosend), 0) == -1) {
				perror("send");
		} } } } //...................................
		
void new_recv(int i, fd_set *master, int sockfd, int fdmax,struct sockaddr_in my_addr,struct sockaddr_in client_addr)//sending and receiving fuction
{ 
fileptrrejected=fopen("rejectedd.txt","a");

    
    t = time(NULL); tmm =  *localtime(&t);
	int nbytes_recvd, j;
	char msgvar[1200], recv_buf[BUFSIZE], buf[BUFSIZE]; 
	if ((nbytes_recvd = read(i, &job, sizeof(job))) <= 0) {
		if (nbytes_recvd == 0) { printf("socket %d hung up\n", i);
		}else { perror("recv"); }
		close(i);
		FD_CLR(i, master);
	}else {
	
	if(!strcmp(job.commandd,"pp")){ 
	    startprocessing=1; 
	   }else{
	                                                         if(headerprinted==0){
	printf("\nJOBS RECIEVED :  ");
	printf("\n================="); headerprinted=1;
	                                                            }
	     //determine the length of the string and store it in a variable 
	    if(strlen(job.processedstring)>50){
	    //display the rejection info
	    printf("\n!!!  job %d rejected because string is of length %d greater than __50 characters",ras+1,strlen(job.processedstring)); 
	    //send a reply to the sender immediately, and write the attribues of the myjobs to a 
	    sprintf(msgvar,"%s '%s %s %s' %s","!!! your job",job.commandd,job.processedstring,job.stringoptions,"has been rejected because the string is too long, >50 characters");
	    //printf("\n%s",msgvar);
	    printf("\n   %d.",ras+1);
	     printf("        %s %s %s  ",job.commandd,job.processedstring,job.stringoptions); 
	    
	    //send(sockfd,msgvar, strlen(msgvar),0); 
	    ras=ras+1; 
	       //write attributes to the rejected list file 
	        strcpy(job.resultStr," !! Rejected because the string is too long ( > 50 characters)");
          fileptrrejected=fopen("rejectedd.txt","a");
         fprintf(fileptrrejected,"\n %d|%s", job.charlength,job.processedstring);
         fprintf(fileptrrejected,"|%s|%s",job.jobId,job.sender_id);  
          fprintf(fileptrrejected,"|%s;",job.resultStr);
            fclose(fileptrrejected);
	    }else{ 
	                //if(ras==0){starttime = time(NULL);}
	                
	     job.charlength = strlen(job.processedstring);
	      
          if(job.charlength > 0){
	     strcpy(job.process_status,"Waiting");
	     strcpy(job.sourceIP,inet_ntoa(client_addr.sin_addr));
	     port= ntohs(client_addr.sin_port);
	     job.portNo = port;
         sprintf(job.daterecv,"%d-%d-%d",tmm.tm_year + 1900, tmm.tm_mon + 1, tmm.tm_mday );
         sprintf(job.timerecv,"%d:%d:%d" ,tmm.tm_hour, tmm.tm_min, tmm.tm_sec); 
         if(strcmp(job.commandd,"delete") && strcmp(job.commandd,"replace")){strcpy(job.stringoptions,"   "); }
          //write attributes to the file 
          fileptrbusy=fopen("busylistt.txt","a");
         fprintf(fileptrbusy,"\n %s|%s", job.commandd,  job.processedstring);
         fprintf(fileptrbusy,"|%s|%s",job.stringoptions,job.sender_id);
         fprintf(fileptrbusy,"|%s|%s|%d",job.jobId,job.sourceIP,job.portNo);
         fprintf(fileptrbusy,"|%s|%s|%d;",job.daterecv,job.timerecv,job.charlength);
          fclose(fileptrbusy);
          // status file handler
          fileptrstatus=fopen("statuss.txt","a");
         fprintf(fileptrstatus,"\n %s|%s", job.commandd,  job.processedstring);
         fprintf(fileptrstatus,"|%s|%s|%s", job.stringoptions, job.sender_id, job.jobId);
         fprintf(fileptrstatus,"|%s|%d|%s",job.sourceIP, job.portNo,job.daterecv);
         fprintf(fileptrstatus,"|%s|%d|%s;",job.timerecv, job.charlength,job.process_status);
          fclose(fileptrstatus);
          
 	     busylist[ras] = job; //added to busy list.
 	     
	     rtrn = busylist[ras];
	     printf("\n   %d.",ras+1);
	     printf("        %s %s %s  ",job.commandd,job.processedstring,job.stringoptions); 
	          
	        ras = ras+1; 
	        }
	       }
	       }
	      }  }//...................................
		
void connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr)
{
	socklen_t addrlen;
	int newsockfd; 	
	addrlen = sizeof(struct sockaddr_in);
	if((newsockfd = accept(sockfd, (struct sockaddr *)client_addr, &addrlen)) == -1) {
		perror("accept"); exit(1);
	}else {
		FD_SET(newsockfd, master);
		if(newsockfd > *fdmax){  *fdmax = newsockfd;  }
        printf("\nNew client connection from %s on port %d \n",
        inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
	}
 headerprinted=0;
}
	
void connect_request(int *sockfd, struct sockaddr_in *my_addr)
{
	int yes = 1;
		
	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket"); exit(1); } 
	my_addr->sin_family = AF_INET;
	my_addr->sin_port = htons(6900);
	my_addr->sin_addr.s_addr = INADDR_ANY;
	memset(my_addr->sin_zero, ' ', sizeof my_addr->sin_zero);
		
	if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
		perror("setsockopt"); exit(1); }
		
	if (bind(*sockfd, (struct sockaddr *)my_addr, sizeof(struct sockaddr)) == -1) {
		perror("Unable to bind"); exit(1); }
	if (listen(*sockfd, 10) == -1) { perror("listen"); exit(1); }
	printf("\nServer Waiting for client on port 6900 ...");
	fflush(stdout);
}

int main()
{
	fd_set master;
	fd_set read_fds;
	int fdmax, i,jn;
	int sockfd= 0;
	struct sockaddr_in my_addr, client_addr;
	FD_ZERO(&master);
	FD_ZERO(&read_fds); 
	connect_request(&sockfd, &my_addr);
	
	FD_SET(sockfd, &master); 
	fdmax = sockfd;
	
	starttime = time(NULL);   
	   
	while(1){ 
		read_fds = master;
		if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){ perror("select"); exit(4); }
		
		for (i = 0; i <= fdmax; i++){
			if (FD_ISSET(i, &read_fds)){
				  if (i == sockfd)
					connection_accept(&master, &fdmax, sockfd, &client_addr);
				  else
					new_recv(i, &master, sockfd, fdmax,my_addr, client_addr);
			 }
		}//end for loop
	//*******************************main processing****************************************
	   curtime =time(NULL);
	      secs = curtime-starttime; 
	                  //dtermine the end  
	                  end=ras; 
	                  if(end%14==0){cmpp=0;}else{cmpp=cmpp+1;}  
		if(startprocessing==1)
		{
		 
		sh=0; cm=0; rp=0; op=0; wa=0; min=0; wa2=0; wa3=0; wa4=0; ixx=0;
		  //copy from the busyblist to the working array
		  }
		  if(startprocessing==1){
		  if(end>0){
		  
		  
		  for(x=bgg;x<end;x++){
		                              workingArr[wa] = busylist[x]; 
		  strcpy(workingArr[wa].process_status,"inProgress");
		    fileptrstatus=fopen("statuss.txt","a"); 
		  fprintf(fileptrstatus,"\n%s|%s|%s",workingArr[wa].commandd,workingArr[wa].processedstring,workingArr[wa].stringoptions); 
		  fprintf(fileptrstatus,"|%s|%s", workingArr[wa].sender_id, workingArr[wa].jobId);
		  fprintf(fileptrstatus,"|%s|%d|%s",workingArr[wa].sourceIP, workingArr[wa].portNo, workingArr[wa].daterecv);
		  fprintf(fileptrstatus,"|%s|%d|%s;",workingArr[wa].timerecv, workingArr[wa].charlength,workingArr[wa].process_status);
		    fclose(fileptrstatus);
                       wa=wa+1;
                    } //end for loop 
		  //order the tasks in their priority arrays  /////////////
                  //Adding to first priority 
                            strcpy(tempstrg,workingArr[0].processedstring); 
                   min = strlen(tempstrg); 
                   prior1pos = 0;
                   }//end if
                   }
                   if(startprocessing==1){
                   if(wa>1){
                   for(ax=1;ax<wa;ax++){
                       strcpy(tempstrg,workingArr[ax].processedstring);
                     newMin = strlen(tempstrg); 
                     if(newMin<min){
                       min = newMin;
                       prior1pos = ax; 
                     }//end if
                   }/*end for loop*/ }/*end if*/
                   }
                    if(startprocessing==1){               
                   if(wa>0){
                   for(ddx=0;ddx<wa;ddx++){  
                      strcpy(tempstrg,workingArr[ddx].processedstring);
                       
                     if(strlen(tempstrg)==min){
                     strcpy(workingArr[ddx].priorityNo,"prior_1_");
                     shortask[sh] = workingArr[ddx];
                     sh = (sh+1)%50; 
                     }else{
                     workingArr2[wa2] = workingArr[ddx]; wa2=wa2+1; 
                     }  
                    }//end for loop 
                     }//end if
                     }
                     //...........adding to second priority 
                     if(startprocessing==1){
                     if(wa2>0){
                     for(vvx=0;vvx<wa2;vvx++){ 
                     cpystruct=workingArr2[vvx]; 
                     strcpy(sender_ids[vvx],cpystruct.sender_id);  
                     }
                      
                  for(xi=0;xi<wa2;xi++){  occ=0;
                  strcpy(sender_idcopy,sender_ids[xi]);   
                     for(iix = 0;iix<wa2;iix++){ 
                      if(!strcmp(sender_idcopy,sender_ids[iix])){ occ=occ+1; }
                     }//end for loop 
                     occurr[xi] = occ; 
                   }  
                 maxoc = occurr[0]; maxpos = 0;
                 }//end if(wa2>0)
                 } 
                 if(startprocessing==1){
                  if(wa2>1){
                  for(c=1;c<wa2;c++){
                  newMax = occurr[c];
                  if(newMax > maxoc){
                  maxoc = newMax; 
                  }  }/*end for loop*/ 
                 for(hh=0;hh<wa2;hh++){
                    if(occurr[hh]==maxoc){ strcpy(commonID,sender_ids[hh]); } 
                    if(!strcmp(commonID,workingArr2[hh].sender_id )){
                      strcpy(workingArr2[hh].priorityNo,"prior_2_");
                      mostcommon[cm] = workingArr2[hh];  
                      cm = (cm+1)%10;
                     }else{
                     workingArr3[wa3] = workingArr2[hh]; wa3=wa3+1;
                     }  
                  }//end for loop   
                 }//end if (wa>1) 
                 }
                 if(startprocessing==1){
                 //=====adding third priority=======
                  if(wa3>0){
                   for(bxxx = 0;bxxx<wa3;bxxx++){  
                     if((!strcmp(workingArr3[bxxx].commandd,"replace")) || (!strcmp(workingArr3[bxxx].commandd,"Replace"))){ 
                       strcpy(workingArr3[bxxx].priorityNo,"prior_3_");
                       replacetask[rp] = workingArr3[bxxx];  
                      rp = (rp+1)%20;
                     }else{
                     workingArr4[wa4] = workingArr3[bxxx]; wa4=wa4+1;
                     }  
                 }/*end for loop*/}//end if 
                 }
                 if(startprocessing==1){
                 //.====================.adding to fourth==============
                  if(wa4>0){
                  for(cxx = 0;cxx<wa4;cxx++){   
                       strcpy(workingArr4[cxx].priorityNo,"prior_0_");
                       otherpri[op] = workingArr4[cxx];  
                      op = (op+1)%50;  
                   }/*end for loop*/ 
                 }//end if 
                 }
		  //*********=======calling main processor to process========************ 
		     if(startprocessing==1){
                if(sh>0){
                  
                
                for(i1=0;i1<sh;i1++){
                 tempstruct = mainproc(shortask[i1]); 
                 
                 strcpy(tempstruct.process_status,"Finished");
		    fileptrstatus=fopen("statuss.txt","a"); 
		  fprintf(fileptrstatus,"\n%s|%s|%s",tempstruct.commandd,tempstruct.processedstring,tempstruct.stringoptions); 
		  fprintf(fileptrstatus,"|%s|%s", tempstruct.sender_id, tempstruct.jobId);
		  fprintf(fileptrstatus,"|%s|%d|%s",tempstruct.sourceIP,tempstruct.portNo,tempstruct.daterecv);
		  fprintf(fileptrstatus,"|%s|%d|%s;",tempstruct.timerecv, tempstruct.charlength,tempstruct.process_status);
		    fclose(fileptrstatus);
                 
                 readylist[nextready] = tempstruct;
                 nextready = (nextready+1)%200;
                 //write all the attributes to a readyList file 
                   fileptrready=fopen("readylistt.txt","a");
                 fprintf(fileptrready,"\n %s|%s",tempstruct.commandd,tempstruct.processedstring);
                 fprintf(fileptrready,"|%s|%s",tempstruct.stringoptions,tempstruct.sender_id);
                 fprintf(fileptrready,"|%s|%s|%d",tempstruct.jobId, tempstruct.sourceIP, tempstruct.portNo);
                 fprintf(fileptrready,"|%s|%s|%s",tempstruct.daterecv,tempstruct.timerecv,tempstruct.processingDuration);
                 fprintf(fileptrready,"|%s|%d|%s",tempstruct.priorityNo,tempstruct.charlength,tempstruct.resultStr);
                 fprintf(fileptrready,"|%s;",tempstruct.process_status);
                   fclose(fileptrready);  
                   
                  printf(" %s %s  >> %s",tempstruct.processedstring,tempstruct.stringoptions,tempstruct.resultStr);
                 } }
                 }
                 if(startprocessing==1){
                if(cm>0){
                for(i2=0;i2<cm;i2++){ 
                tempstruct = mainproc(mostcommon[i2]); 
                
                 strcpy(tempstruct.process_status,"Finished");
		    fileptrstatus=fopen("statuss.txt","a"); 
		  fprintf(fileptrstatus,"\n%s|%s|%s",tempstruct.commandd,tempstruct.processedstring,tempstruct.stringoptions); 
		  fprintf(fileptrstatus,"|%s|%s", tempstruct.sender_id, tempstruct.jobId);
		  fprintf(fileptrstatus,"|%s|%d|%s",tempstruct.sourceIP,tempstruct.portNo,tempstruct.daterecv);
		  fprintf(fileptrstatus,"|%s|%d|%s;",tempstruct.timerecv, tempstruct.charlength,tempstruct.process_status);
		    fclose(fileptrstatus);
                 
                 readylist[nextready] = tempstruct;  
                 nextready = (nextready+1)%200;
                 //write all the attributes to a readylist file 
                   fileptrready=fopen("readylistt.txt","a");
                 fprintf(fileptrready,"\n %s|%s",tempstruct.commandd,tempstruct.processedstring);
                 fprintf(fileptrready,"|%s|%s",tempstruct.stringoptions,tempstruct.sender_id);
                 fprintf(fileptrready,"|%s|%s|%d",tempstruct.jobId, tempstruct.sourceIP, tempstruct.portNo);
                 fprintf(fileptrready,"|%s|%s|%s",tempstruct.daterecv,tempstruct.timerecv,tempstruct.processingDuration);
                 fprintf(fileptrready,"|%s|%d|%s",tempstruct.priorityNo,tempstruct.charlength,tempstruct.resultStr);
                 fprintf(fileptrready,"|%s;",tempstruct.process_status);
                   fclose(fileptrready);
                  
                } }
                if(rp>0){
                for(i3=0;i3<rp;i3++){  
                tempstruct = mainproc(replacetask[i3]);
                
                 strcpy(tempstruct.process_status,"Finished");
		    fileptrstatus=fopen("statuss.txt","a"); 
		  fprintf(fileptrstatus,"\n%s|%s|%s",tempstruct.commandd,tempstruct.processedstring,tempstruct.stringoptions); 
		  fprintf(fileptrstatus,"|%s|%s", tempstruct.sender_id, tempstruct.jobId);
		  fprintf(fileptrstatus,"|%s|%d|%s",tempstruct.sourceIP,tempstruct.portNo,tempstruct.daterecv);
		  fprintf(fileptrstatus,"|%s|%d|%s;",tempstruct.timerecv, tempstruct.charlength,tempstruct.process_status);
		    fclose(fileptrstatus);
                  
                 readylist[nextready] = tempstruct;  
                 nextready = (nextready+1)%200;
                 //write all the attributes to a file
                   fileptrready=fopen("readylistt.txt","a");
                 fprintf(fileptrready,"\n %s|%s",tempstruct.commandd,tempstruct.processedstring);
                 fprintf(fileptrready,"|%s|%s",tempstruct.stringoptions,tempstruct.sender_id);
                 fprintf(fileptrready,"|%s|%s|%d",tempstruct.jobId, tempstruct.sourceIP, tempstruct.portNo);
                 fprintf(fileptrready,"|%s|%s|%s",tempstruct.daterecv,tempstruct.timerecv,tempstruct.processingDuration);
                 fprintf(fileptrready,"|%s|%d|%s",tempstruct.priorityNo,tempstruct.charlength,tempstruct.resultStr);
                 fprintf(fileptrready,"|%s;",tempstruct.process_status);
                   fclose(fileptrready);
                    
                } }
                if(op>0){
                for(i4=0;i4<op;i4++){
                tempstruct = mainproc(otherpri[i4]); 
                
                 strcpy(tempstruct.process_status,"Finished");
		    fileptrstatus=fopen("statuss.txt","a"); 
		  fprintf(fileptrstatus,"\n%s|%s|%s",tempstruct.commandd,tempstruct.processedstring,tempstruct.stringoptions); 
		  fprintf(fileptrstatus,"|%s|%s", tempstruct.sender_id, tempstruct.jobId);
		  fprintf(fileptrstatus,"|%s|%d|%s",tempstruct.sourceIP,tempstruct.portNo,tempstruct.daterecv);
		  fprintf(fileptrstatus,"|%s|%d|%s;",tempstruct.timerecv, tempstruct.charlength,tempstruct.process_status);
		    fclose(fileptrstatus);
                 
                 readylist[nextready] = tempstruct;  
                 nextready = (nextready+1)%200;
                 //write all the attributes to a file
                   fileptrready=fopen("readylistt.txt","a");
                 fprintf(fileptrready,"\n %s|%s",tempstruct.commandd,tempstruct.processedstring);
                 fprintf(fileptrready,"|%s|%s",tempstruct.stringoptions,tempstruct.sender_id);
                 fprintf(fileptrready,"|%s|%s|%d",tempstruct.jobId, tempstruct.sourceIP, tempstruct.portNo);
                 fprintf(fileptrready,"|%s|%s|%s",tempstruct.daterecv,tempstruct.timerecv,tempstruct.processingDuration);
                 fprintf(fileptrready,"|%s|%d|%s",tempstruct.priorityNo,tempstruct.charlength,tempstruct.resultStr);
                 fprintf(fileptrready,"|%s;",tempstruct.process_status);
                   fclose(fileptrready);
                   

                } } 
		  //send a copy of results to the clients in a loop
		                //dtermine the endd 
	                  if((endr-bggr)>=8){ endr=bggr+8;
	                  }else{ endr=nextready; }
	      if((endr-bggr)>0){
		  for(zx=bggr;zx<endr;zx++){
		      structosend = readylist[zx]; 
		      //call the send to all function
		      for (jn = 0; jn <= fdmax; jn++){ 
			       send_to_all(jn, sockfd, structosend, &master ); 
		       } } }
		       bggr = endr+1; endr=bggr;
		       startprocessing=0;
		  
		  printf("\n----- processing complete -------- \n---------------------------------------------------------------\n"); 
		 bgg=end+1;
		 end=bgg; 
		}//end if (cmpp >= 8) 
	//********************************************	
	}//end while(1)
	
	
	return 0;
}

//===============================================================================================================================

struct myjobs mainproc(struct myjobs mainjob){
    int a,bg,b,c=0;
    char cmmd[5];
    time_t strtm,finitm,processingdur;
    struct timeval start, end; 
    long mtime, mstime, seconds, useconds;    
 
    gettimeofday(&start, NULL);
    usleep(2000);
     gettimeofday(&end, NULL); 
       seconds  = end.tv_sec  - start.tv_sec;
       useconds = end.tv_usec - start.tv_usec; 
       mtime = seconds + useconds;
       mstime = useconds; 
     
    for(a=0;a<strlen(mainjob.commandd);a++){ sprintf(&cmmd[a],"%c",mainjob.commandd[a]); }

    struct myjobs readytask;
    struct myjobs pastask;
     strtm = time(NULL);
    pastask = mainjob;
      sprintf(&cmmd[0],"%c",mainjob.commandd[0]);
      sprintf(&cmmd[1],"%c",mainjob.commandd[1]);
      sprintf(&cmmd[2],"%c",mainjob.commandd[2]);


       if(strcmp(cmmd,"rev")==0 || strcmp(cmmd,"Rev")==0){
                  readytask = revproc(pastask);
       }else if(strcmp(cmmd,"dou")==0 || strcmp(cmmd,"Dou")==0){
                  readytask = dblproc(pastask);
       }else if(strcmp(cmmd,"del")==0 || strcmp(cmmd,"Del")==0){
                readytask = delproc(pastask);
       }else if(strcmp(cmmd,"rep")==0 || strcmp(cmmd,"Rep")==0){
                  readytask = replproc(pastask);
       }else if(strcmp(cmmd,"enc")==0 || strcmp(cmmd,"Enc")==0){
                  readytask = encrproc(pastask);
       }else if(strcmp(cmmd,"dec")==0 || strcmp(cmmd,"Dec")==0){
                  readytask = decrproc(pastask);
       }else if(strcmp(cmmd,"ENC")==0){
                  readytask = encrproc2(pastask);
       }else if(strcmp(cmmd,"DEC")==0){
                  readytask = decrproc2(pastask);
       }else{
         //unknown command.
       }
       //determine time of returning
       //proc
      
       //finitm = time(NULL);
       //processingdur = (finitm*10000000)+strtm*10000000;
       sprintf(readytask.processingDuration,"%ld %s",mstime,"msec");
    return readytask;

}/*end of mainproc function*/



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct myjobs encrproc2(struct myjobs encrtask){
   /*declaring variables : */
   int j=0,k=0,i=0,m,t,s,u,mm=0,w,bg=0,v=0,ii=0,pos=1,chgate=1, flag=0,flush,flush2, cur=0,chweight,wtleft=0,wtright=0;
   char srcharry[17] , descharry[17] ,wtstr[5], finalencrr[1003];
   char *dd;
   char alph[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

        for(j=0;j<strlen(encrtask.processedstring);j++){  if(encrtask.processedstring[j] == ' ' || encrtask.processedstring[j] == ';'){break;}

                chgate=1; cur = 0; flag=0;
                for(flush2=0;flush2<sizeof(descharry);flush2++){srcharry[flush2]=' '; descharry[flush2]=' ';}

            for(k=0;k<sizeof(alph);k++){
                if(alph[k]==encrtask.processedstring[j]){
                    pos=k;
                }/*end of if*/
            }/*end of iner for loop, looping through alph[]*/

            chweight=pos;

          while(flag == 0){

            if(chweight<10 && chweight > 0){
                                       ii=0;
                for(m=0; m<(sizeof(srcharry)-1); m++){
                    if(m==cur){
                        wtstr[0] = alph[chweight+26];
                        descharry[cur] = wtstr[0];
                         ii=1;
                         flag=1;

                      }/*end of if(i==cur)*/
                      descharry[m+ii] = srcharry[m];
                      if(srcharry[m] == ' '){continue;}
                }/*end of for loop, copying srcharry[] into tempcahrry[]*/
                chweight =-9;

            }else{
               while(chweight > 9){ ii=0;
                for(i=0; i < sizeof(srcharry);i++){

                    if(i==cur){
                        wtleft = (int)chweight/10;
                        wtright = chweight%10;
                        sprintf ( &wtstr[0], "%d", wtleft);
                        if((chweight-1)<27){
                        sprintf ( &wtstr[1], "%c", alph[chweight-1]);
                        }else{
                        sprintf ( &wtstr[1], "%c", alph[(chweight-1)-26]);
                        }/*end of if((chweight-1)<27) {..} else {..} */
                        sprintf ( &wtstr[2], "%d", wtright);
                        descharry[cur]   =  wtstr[0];
                        descharry[cur+1] =  wtstr[1];
                        descharry[cur+2] =  wtstr[2];
                        ii=3;
                    }/*end of if(i==cur) elsse part */

                    descharry[i+ii] = srcharry[i];

                }/*end of for loop, copying srcharry[] into tempcahrry[] , else part*/

                for(v=0;v<sizeof(descharry);v++){
                    srcharry[v] = descharry[v];
                } /*copying everything in descharry into srcharry */
cur+=2;
               /* printf("\ncontents of srcharry  : %s",srcharry);
                printf("\nvalue of cur : == %d ==",cur); */
                   chweight -= 9;
               }/*end of while loop, overwrighting tempcharyy[]*/

            }/*end of if (chweight<10) {..} else {..}*/

            chgate++;
          }/*end of while loop ,checking if flag=1  ..*/

               for(w=bg;w<sizeof(descharry);w++){//finalencr[w] = descharry[w];
                if(descharry[w] == ' '){ break;}else{ sprintf(&encrtask.resultStr[mm],"%c",descharry[w]);   /*dd=descharry[w]; strcat(finalencrr,dd) ;*/ }
                mm++;
                if(mm==sizeof(encrtask.resultStr)-2){break;}
                }
        }/*end of main for loop, looping through string*/
           return encrtask;
     } /* end of enccription function */

     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     struct myjobs encrproc(struct myjobs encrtask){
   /*declaring variables : */
   int j=0,k=0,i=0,m,mid,capi=0,t,s,xx,len,u,mm=0,w,bg=0,v=0,ii=0,pos=1,chgate=1, flag=0,flush,flush2, cur=0,chweight,wtleft=0,wtright=0;
   char srcharry[17] , descharry[17] ,wtstr[5], finalencrr[1003];
   char dd[] = {'r','o','g','e','r','s',' ',' '};
   char alph[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};

        for(j=0;j<strlen(encrtask.processedstring);j++){  if(encrtask.processedstring[j] == ' ' || encrtask.processedstring[j] == ';'){break;}

                chgate=1; cur = 0; capi=0; len=0; flag=0;
                for(flush2=0;flush2<sizeof(descharry);flush2++){srcharry[flush2]=' '; descharry[flush2]=' ';}

            for(k=0;k<sizeof(alph);k++){
                if(alph[k]==encrtask.processedstring[j]){
                    pos=k;
                }/*end of if*/
            }/*end of iner for loop, looping through alph[]*/

            chweight=pos;

          while(flag == 0){

            if(chweight<10 && chweight > 0){
                                       ii=0;
                for(m=0; m<(sizeof(srcharry)-1); m++){
                           len=strchNo(srcharry);

                           mid=(int)(len/2);
                    if(m==mid){
                        wtstr[0] = alph[chweight+26];
                        descharry[mid] = wtstr[0];
                         ii=1;
                         flag=1;
                         capi=1;
                     }
                      descharry[m+ii] = srcharry[m];
                      if(srcharry[m] == ' '){continue;}
                }/*end of for loop, copying srcharry[] into tempcahrry[]*/
                chweight =-9;

            }else{
               while(chweight > 9){ ii=0;
                for(i=0; i < sizeof(srcharry);i++){

                    if(i==cur){
                        wtleft = (int)chweight/10;
                        wtright = chweight%10;
                        sprintf ( &wtstr[0], "%d", wtleft);
                        if((chweight-1)<27){
                        sprintf ( &wtstr[1], "%c", alph[chweight-1]);
                        }else{
                        sprintf ( &wtstr[1], "%c", alph[(chweight-1)-26]);
                        }/*end of if((chweight-1)<27) {..} else {..} */
                        sprintf ( &wtstr[2], "%d", wtright);
                        descharry[cur]   =  wtstr[0];
                        descharry[cur+1] =  wtstr[1];
                        descharry[cur+2] =  wtstr[2];
                        ii=3;
                    }/*end of if(i==cur) elsse part */

                    descharry[i+ii] = srcharry[i];

                }/*end of for loop, copying srcharry[] into tempcahrry[] , else part*/

                for(v=0;v<sizeof(descharry);v++){
                    srcharry[v] = descharry[v];
                } /*copying everything in descharry into srcharry */
cur+=2;
               /* printf("\ncontents of srcharry  : %s",srcharry);
                printf("\nvalue of cur : == %d ==",cur); */
                   chweight -= 9;
               }/*end of while loop, overwrighting tempcharyy[]*/

            }/*end of if (chweight<10) {..} else {..}*/

            chgate++;
          }/*end of while loop ,checking if flag=1  ..*/

               for(w=bg;w<sizeof(descharry);w++){//finalencr[w] = descharry[w];
                if(descharry[w] == ' '){ break;}else{ sprintf(&encrtask.resultStr[mm],"%c",descharry[w]);   /*dd=descharry[w]; strcat(finalencrr,dd) ;*/ }
                mm++;
                if(mm==sizeof(encrtask.resultStr)-2){break;}
                }
        }/*end of main for loop, looping through string*/
           return encrtask;
     } /* end of enccription function */

  int strchNo(char arr[]){ int a=0,n=1;  char temmp[40]; while(arr[a] != ' '){ n++; a++; } return n; }


 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     struct myjobs decrproc2(struct myjobs decrtask){
   /*declaring variables : */
    int th,val,nextchr=0,nsb4uppercase,lcasecharsb4,validNosAfterUpper,nsb4UpperCase,x,upperCasePos;
                char encriptedchar, finalstring[1200],wts[3];
   int j=0,k=0,i=0,m,uu,t,s,u,mm=0,w,bg=0,v=0,ii=0,pos=1,chgate=1, flag=0,flush,flush2, cur=0,chweight,wtleft=0,wtright=0;
   char srcharry[17] , descharry[17] ,wtstr[5], finalencrr[1003],destArry[80];
   char *dd;
   char alph[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

        //for(j=0;j<strlen(decrtask.processedstring);j++){  if(decrtask.processedstring[j] == ' ' || decrtask.processedstring[j] == ';'){break;}

                for(flush2=0;flush2<sizeof(descharry);flush2++){srcharry[flush2]=' '; descharry[flush2]=' ';}
           //====================================================
	        for(i=0; i<sizeof(decrtask.processedstring); i++){ if(decrtask.processedstring[i] != ' '&& bg==0){  bg=i;  break;}  } //grab the reeal beginning of the string, ignoring first spaces.
    for(ii=bg; ii<sizeof(decrtask.processedstring); ii++){
            if(decrtask.processedstring[ii]=='\0'){break;}
            if(ii==bg){
				if(decrtask.processedstring[bg]=='A' || decrtask.processedstring[bg]=='B' || decrtask.processedstring[bg]=='C' ||
                    decrtask.processedstring[bg]=='D'||decrtask.processedstring[bg]=='E' || decrtask.processedstring[bg]=='F' ||
                     decrtask.processedstring[bg]=='G' || decrtask.processedstring[bg]=='H' || decrtask.processedstring[bg]=='I'){
				                for(th=27; th<=35; th++){ if(alph[th]==decrtask.processedstring[bg]){  val=th;  }  }
				                sprintf(&encriptedchar,"%c",alph[val-26]);
				                sprintf(&finalstring[nextchr],"%c",encriptedchar); nextchr++;
                                bg = ii+1;
			       } else if(decrtask.processedstring[bg]==' '){ bg = ii+1;
				   }else if(decrtask.processedstring[ii]=='0' || decrtask.processedstring[ii]=='1' || decrtask.processedstring[ii]=='2' ||
                     decrtask.processedstring[ii]=='3' || decrtask.processedstring[ii]=='4' || decrtask.processedstring[ii]=='5' ||
                     decrtask.processedstring[ii]=='6' || decrtask.processedstring[ii]=='7' || decrtask.processedstring[ii]=='8' ||
                     decrtask.processedstring[ii]=='9'){
						sprintf(&wts[0],"%c",decrtask.processedstring[bg]);
				        } //end of 1.3
				        nsb4uppercase=1;
						lcasecharsb4=0;
				} // end of if(ii==bg)
					else if(decrtask.processedstring[ii]=='A' || decrtask.processedstring[ii]=='B' || decrtask.processedstring[ii]=='C' || decrtask.processedstring[ii]=='D' || decrtask.processedstring[ii]=='E' ||
                       decrtask.processedstring[ii]=='F' || decrtask.processedstring[ii]=='G' || decrtask.processedstring[ii]=='H' ||
                       decrtask.processedstring[ii]=='I'){
						validNosAfterUpper=0;  upperCasePos = ii;
                        uu=ii+nsb4uppercase;
					     sprintf(&wts[1],"%c",decrtask.processedstring[uu]);
					     chweight = atoi(wts);
						sprintf(&finalstring[nextchr],"%c",alph[chweight]);
						nextchr++; /*should be global not reset */
                        bg=uu+1;
		}//End of strig[ii]==uppercase chaaracter
				/*if standing at an even position away from the bg, i must be a number */
				else if(ii>bg && ((ii-bg)%2==0)){
					if(decrtask.processedstring[ii]=='0' || decrtask.processedstring[ii]=='1' || decrtask.processedstring[ii]=='2' || decrtask.processedstring[ii]=='3' || decrtask.processedstring[ii]=='4' || decrtask.processedstring[ii]=='5' || decrtask.processedstring[ii]=='6' || decrtask.processedstring[ii]=='7'
							|| decrtask.processedstring[ii]=='8' || decrtask.processedstring[ii]=='9'){
								nsb4uppercase++;
							      }
		}// end if (2.3)
                else if(ii>bg && ((ii-bg)%2==1)){
								for(x=1; x<27; x++){
								    if(decrtask.processedstring[ii]==alph[x]){
									    lcasecharsb4++;
									    }//end if
                                    }// end loop
        }// end if (2.4)
		            } //End for loop , ii..
               for(w=0;w<sizeof(finalstring);w++){
                       if(finalstring[w] == '\0'){ break;}
                       else{ sprintf(&decrtask.resultStr[w],"%c",finalstring[w]); }
                    }
        return decrtask;
     } /* end of enccription function */

     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct myjobs decrproc(struct myjobs decrtask){
    float floatwgt;
    int th,end,val,nextchr=0,nsb4uppercase,lcasecharsb4,validNosAfterUpper,nsb4UpperCase,x,upperCasePos;
    char encriptedchar, finalstring[1200],wts[3];
    int j=0,k=0,i=0,m,xx,uu,xpos,t,s,len,u,nextbg,bgchr,chwleft,mm=0,w,bg=0,v=0,ii=0,pos=1,chgate=1, flag=0,flush,flush2, cur=0,chweight,wtleft=0,wtright=0;
    char srcharry[17] , descharry[17] ,wtstr[5], finalencrr[1003],destArry[80];
    char secondch,sha[2];
    char alph[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

                for(flush2=0;flush2<sizeof(descharry);flush2++){srcharry[flush2]=' '; descharry[flush2]=' ';}
           //====================================================
	        for(i=0; i<sizeof(decrtask.processedstring); i++){ if(decrtask.processedstring[i] != ' '&& bg==0){  bg=i;  break;}  } //grab the reeal beginning of the string, ignoring first spaces.

    for(ii=bg; ii<sizeof(decrtask.processedstring); ii++){
            if(decrtask.processedstring[ii]=='\0'){break;}
            if(ii==bg){
				       if(decrtask.processedstring[bg]=='A' || decrtask.processedstring[bg]=='B' || decrtask.processedstring[bg]=='C' ||
                         decrtask.processedstring[bg]=='D'||decrtask.processedstring[bg]=='E' || decrtask.processedstring[bg]=='F' ||
                         decrtask.processedstring[bg]=='G' || decrtask.processedstring[bg]=='H' || decrtask.processedstring[bg]=='I'){
				                for(th=27; th<=35; th++){ if(alph[th]==decrtask.processedstring[bg]){  val=th;  } }
				                sprintf(&encriptedchar,"%c",alph[val-26]);
				                sprintf(&finalstring[nextchr],"%c",encriptedchar);  nextchr=nextchr+1;
                                bg = bg+1;
				        }else{
                           sha[0] = decrtask.processedstring[bg];
                           bgchr = atoi(sha);
                           secondch = decrtask.processedstring[bg+1];
                           for(xx=1;xx<27;xx++){ if(secondch==alph[xx]){xpos=xx;} }
                           chweight = xpos+27;
                           chwleft = (int)(chweight/10);
                           if(bgchr != chwleft){ chweight = xpos+1; }
                           sprintf(&finalstring[nextchr],"%c",alph[chweight]);  nextchr=nextchr+1;
                           floatwgt = (chweight-0.1);
                           nextbg = bg + ((int)(floatwgt/9))*3;
                           bg = nextbg+1;
				         }
				  } // end of if(ii==bg)
            } //End for loop , ii..
                       for(w=0;w<sizeof(finalstring);w++){
                       if(finalstring[w] == '\0'){ break;}
                       else{ sprintf(&decrtask.resultStr[w],"%c",finalstring[w]); }
                        }
      return decrtask;
     } /* end of enccription function */


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     struct myjobs replproc(struct myjobs repltask){//1-d,3-o,4-p,6-a   1-c,2-o,3-n,5-i,6-d  difference
   /*declaring variables : */
   int i,a,x;
   char xx[2],destArr[80];  bbzero(destArr); bbzero(repltask.resultStr);
       for(i=0;i<sizeof(destArr);i++){
          if(repltask.processedstring[i]=='\0'){break;}
                 for(a=0;a<strlen(repltask.stringoptions);a+=4){
                        if(repltask.stringoptions[a]=='\0'){break;}
                        sprintf(&xx[0],"%c",repltask.stringoptions[a]);
                          x = atoi(xx)-1;
                          if(x==i){
                          destArr[i]=repltask.stringoptions[a+2];  i++;
                        }
                   }//end of the inner for loop ..
        destArr[i] = repltask.processedstring[i];
       }//end of the for loop
       strcpy(repltask.resultStr,destArr);
    return repltask;
   }//end of the replace function
   void bbzero(char * strg){ for(int i=0;i<sizeof(strg);i++){ strg[i]='\0'; } }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct myjobs delproc(struct myjobs deletef){
struct myjobs job;
job = deletef;
char dbf[10]="Delete";  char arr2[20]; int com[15]; char b[20];
int l,i=0,d,f,g,h,n,j=0,k, x[20],we; 
char z[20],ll[20],r[8][3]; 

l = strlen(job.stringoptions);
bbzero(arr2);
for(i=0,j=0; i<l; i++,j++){
               if(i%2==0){
                   z[i/2] = job.stringoptions[i];
                   ll[0] = job.stringoptions[i];
                   strcpy(r[i/2],ll);
                    }
                if(i==(l-1)){  we = i/2; } 
                } 
int len = l-we;
int e = atoi(z);
for(d=0;d<len;d++){
 x[d] = atoi(r[d]);
} 
int rn = strlen(job.processedstring);
int ww = sizeof(x)/sizeof(int);
int fr = rn-len+1;
int flag=0;
int nop=0; 
for(i=0; i<fr+1; i++){
flag=0;
    for(j=0; j<(l-we); j++){
      if(i==(x[j]-1)){ flag++;    i++; nop++; }

          arr2[i-nop]= job.processedstring[i];
                }
             strcpy(job.resultStr,arr2);
             }
return job;
 }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct myjobs dblproc(struct myjobs job){
  int k,j;
    char strr[50];
	//printf("Doubled is %s" ,job.processedstring);
	int l = 2*(strlen(job.processedstring));
	for(k=0; k<l;k++){
      strr[k] = job.processedstring[k];
    //printf("%c" ,job.processedstring[k]);
     }
     strr[k] = '\0';
     strcat(strr,job.processedstring);
     strcpy(job.resultStr,strr);
//     printf("Doubled string is %s",job.resultStr);

    return job;

        }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct myjobs revproc(struct myjobs job){
    int i,j,l;
    char temp,cpystring[80];
    strcpy(cpystring,job.processedstring);
    for (i=0, j=(strlen(job.processedstring))-1; i < j; i++, j--) {
        temp = cpystring[i];
        cpystring[i] = cpystring[j];
        cpystring[j] = temp;
     }
     strcpy(job.resultStr,cpystring);
     return job;
     }






















