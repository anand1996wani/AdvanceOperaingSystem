struct assignId{	   
	int clientId;	
};

struct clientSend{	
	int clientId;
	int option;	
};

struct clientAns{  
	int clientId;
	char answer[100];
};

struct serverEvaluate{
	int correct;
};

struct serverQuiz{
	char question[250];
	char option[100];	
};
struct rank{
	int sessionRank;
	int globalRank;
};


struct credentials{
	int clientId;
	char password[10];
};

program ASSIGNMENT{ version
	ASSIGNMENTVERS{
		assignId GETID(credentials) = 1;
		serverQuiz GETQUESTION(clientSend) = 2;
		serverEvaluate EVALUATEANSWER(clientAns) = 3;
		serverEvaluate GETSCORE(clientSend) = 4;
		rank GETRANK(clientSend) = 5;
		serverEvaluate EXIT(clientSend) = 6;
		serverEvaluate LOGIN(credentials) = 7;
	} = 1;
} = 0x13451111;
