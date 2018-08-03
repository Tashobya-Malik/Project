#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
	
#define BUFSIZE 1024
int dx;
//======================================
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
char senderIDvar[12],jobIDvar[12];
//==============================
		
void send_recv(int i, int sockfd)
{
	char send_buf[BUFSIZE];
	char recv_buf[BUFSIZE];
	int nbyte_recvd; 
         char cc[3], msgvar[1200] ; 
         long zz;
         int flush2,a=0,tokenCount=1,tokenpos1=0,tokenpos2=0,tokenpos3=0,taskprocessing=0,jobCount=0,jobc=0;
         char c,tasksList[1200];
  //=====================================================================
	
	if (i == 0){
		//fgets(send_buf, BUFSIZE, stdin);
		
		/**********************************************/
		printf("\nSend jobs : \n\t");
         fgets(tasksList,sizeof(tasksList),stdin);
         if(tasksList[0]=='p' && tasksList[1]=='p'){ 
              for(dx=0;dx<sizeof(job.commandd);dx++){  job.commandd[dx]='\0'; }
              strcpy(job.commandd,"pp");
              send(sockfd,&job,sizeof(job),0);
         }else{

             while(tasksList[a] != '\0'){
                if(taskprocessing==0){
                    if(tasksList[a]==' '){
                       a++;
                    }else{
                       taskprocessing=1;
                       tokenCount=1;
                    }
                }//end if.

                if(taskprocessing==1){
                        if(tasksList[a]==';'){
                                /*============ a structure is now created, we can send it to the server ============*/
                                sprintf(jobIDvar,"%s%d%d",senderIDvar,0,jobc); jobc++;
                                strcpy(job.sender_id,senderIDvar);
                                strcpy(job.jobId,jobIDvar);
                                send(sockfd,&job,sizeof(job),0); 
                                
                                for(zz=0;zz<300000000;zz++){   if(zz==300000000-2){}   }
 
                                jobCount++; 
                                for(flush2=0;flush2<sizeof(job.stringoptions);flush2++){job.stringoptions[flush2]=' '; job.stringoptions[flush2]=' ';}
                                /*========================*/
                            tokenpos1=0; tokenpos2=0; tokenpos3=0;
                            taskprocessing = 0;
                            a=a+1;
                        }
                        else if(tasksList[a] != ' ' && tasksList[a-1] == ' '){
                                if(tokenCount==1){
                                sprintf(&job.commandd[0],"%c",tasksList[a]);
                                tokenpos1++;
                                }
                              else if(tokenCount==2){
       
                                sprintf(&job.processedstring[0],"%c",tasksList[a]);
                            
                                tokenpos2++;}
                              else if(tokenCount==3){
                                 sprintf(&job.stringoptions[0],"%c",tasksList[a]);
                                 tokenpos3++;}
                              else{} 
                            a=a+1;
                        }else if(tasksList[a] == ' '){
                            a=a+1;

                        }else if(tasksList[a] != ' '){
                            if(tokenCount==1){
                                sprintf(&job.commandd[tokenpos1],"%c",tasksList[a]);
                                tokenpos1++;}
                              else if(tokenCount==2){
                                sprintf(&job.processedstring[tokenpos2],"%c",tasksList[a]);
                                 tokenpos2++;}
                              else if(tokenCount==3){
                                sprintf(&job.stringoptions[tokenpos3],"%c",tasksList[a]);
                                 tokenpos3++;}
                              else{}
                          if(tasksList[a] != ' ' && tasksList[a+1] == ' '){ tokenCount++;}
                          a=a+1;
                        }//else{}//end else
                 }//end if (processing on ) .
              }/*end whhile looping through tasksList*/
            }
		/**********************************************/
 	}else {
		nbyte_recvd = read(sockfd, &structosend, sizeof(structosend)); 
		
		if(!strcmp(structosend.sender_id,senderIDvar)){
		printf("\n %s %s %s : _________ %s ..  priorityNo =%s processing duration =%s ",structosend.commandd,structosend.processedstring,structosend.stringoptions , structosend.resultStr,structosend.priorityNo,structosend.processingDuration);
		 }
		fflush(stdout);
	}
}
 
 void connect_request(int *sockfd, struct sockaddr_in *server_addr)
{
	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}
	server_addr->sin_family = AF_INET;
	server_addr->sin_port = htons(6900);
	server_addr->sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(server_addr->sin_zero, ' ', sizeof server_addr->sin_zero);
	
	if(connect(*sockfd, (struct sockaddr *)server_addr, sizeof(struct sockaddr)) == -1) {
		perror("connect");
		exit(1);
	}
}
	
int main()
{
	int sockfd, fdmax, i;
	struct sockaddr_in server_addr;
	fd_set master;
	fd_set read_fds;
	
	connect_request(&sockfd, &server_addr);
	FD_ZERO(&master);
        FD_ZERO(&read_fds);
        FD_SET(0, &master);
        FD_SET(sockfd, &master);
	fdmax = sockfd;
	//prompt for the sender ID
	printf("\nFIRST ENTER YOUR ID : \t"); scanf("%s",senderIDvar);  
	
	while(1){
		read_fds = master;
		if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
			perror("select");
			exit(4);
		}
		
		for(i=0; i <= fdmax; i++ )
			if(FD_ISSET(i, &read_fds))
				send_recv(i, sockfd);
	}
	printf("client-quited\n");
	close(sockfd);
	return 0;
}
