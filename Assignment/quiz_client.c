/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "quiz.h"
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 

void 
assignment_1(char *host)
{
	CLIENT *clnt;
	char tempOption;
	int option = 0;
	int myId = -1;
	int countQuestion=0;
	char password[10];
#ifndef	DEBUG
	clnt = clnt_create (host, ASSIGNMENT, ASSIGNMENTVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	while(1){
		printf("Enter The Option\n");
		printf("1. : LogIn \n");
		printf("2. : SignUp \n");
		scanf("%d",&option);
		if(option==1){
			printf("Enter Your Id :");
			scanf("%d",&myId);
			printf("Enter Your Password : ");
			scanf("%s",password);
			//printf("password length for login what u entered: %d",strlen(password));
			credentials in;
			in.clientId = myId;
			strcpy(in.password,password);
			serverEvaluate *out;
			if((out = login_1(&in,clnt))==NULL){
				printf("Error\n");
			}
			//printf("out - > correct : %d", out->correct);
			if(out->correct == 1){
				printf("Welcome Back!! Login Successful !! \n");
				break;	
			}else{
				printf("Incorrect Login. Try Again!!\n ");		
			}
		}else if(option==2){
			printf("Choose Your Password : ");
			scanf("%s",password);
			credentials in;
			//printf("Password check from client%s:",in.password);
			assignId *out;	
			strcpy(in.password , password); 
			//printf("Password check from client%s:",in.password);
			//printf("password length : %d",strlen(in.password));
			in.clientId = -1;
			if((out = getid_1(&in,clnt))==NULL){
				printf("Error\n");
			}
			printf("Your Id is : %d\n",out->clientId);
			myId = out->clientId;
			break;		
		}else{
			printf("Plaese Select A Correct Option.\n");
		}
	}
		
	while(1){
		
		printf("1 : Send question\n");
		printf("2 : Get my Score\n");
		printf("3 : Get my Rank\n");
		printf("4 : Exit\n");
		scanf("%d",&option);
		/*if(tempOption <48 || tempOption > 57) continue;
		else option = tempOption-'0';*/
 
		/*if(option==0){
			assignId *out;
			clientSend in;
			in.option = option;
			in.clientId = -1;
			if((out = getid_1(&in,clnt))==NULL){
				printf("Error\n");
			}
			printf("Your Id is : %d\n",out->clientId);
			myId = out->clientId;
		}else*/
		
		if(option==1 ){
		   option = 1;
		   if(countQuestion<50){
			countQuestion++;
			clientSend in;
			in.option = option;
			serverQuiz *out;
			in.clientId = myId;
			if((out = getquestion_1(&in,clnt))==NULL){
				printf("Error\n");
			}
			printf("Question %d) %s\n",countQuestion,out->question);
			//printf("Options : %s\n",out->option);
			serverEvaluate *get;
			clientAns send;
			char ans[100];
			printf("Your answer : ");
			scanf("%s",ans);
			//fgets(ans,100,stdin);
			fflush(stdin);
			send.clientId=myId;
			strcpy(send.answer,ans);
			if((get = evaluateanswer_1(&send,clnt))==NULL){
				printf("Error\n");
			}
			if(get->correct) 
				printf("Correct answer.\n");
			else
				printf("Incorrect answer.\n");
	           }
		   else {
			printf("You have completed the test . Thank you.\n ");
	           }	
			
		}else if(option==2){
			option = 2;
			serverEvaluate *out; //Using correct ver for getting score
			clientSend in;
			in.clientId = myId;
			in.option = option;
			if((out = getscore_1(&in,clnt))==NULL){
				printf("Error\n");
			}
			printf("Your Score Is %d \n",out->correct);
		}else if(option==3){
			option = 3;
			rank *out;
			clientSend in;
			in.clientId=myId;
			in.option=option;
			if((out = getrank_1(&in,clnt))==NULL){
				printf("Error\n");
			}
			printf("Your current session rank Is  %d \n",out->sessionRank);
			printf("Your global rank Is  %d \n",out->globalRank);
			
		}
		else if(option==4){
			option = 4;
			printf("Client Closing Down\n");
			clientSend in;
			in.option = option;
			in.clientId = myId;
			serverEvaluate *out;
			if((out = exit_1(&in,clnt))==NULL){
				printf("Error\n");
			}
			printf("Thank You.\n");
			break;
		}else{
			printf("Please Enter Valid Option\n");
		}
	}
	/*
	result_1 = optionproc_1(&optionproc_1_arg, clnt);
	if (result_1 == (optionOut *) NULL) {
		clnt_perror (clnt, "call failed");
	}*/
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	assignment_1 (host);
exit (0);
}
