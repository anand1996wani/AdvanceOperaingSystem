#include <stdio.h>
#include <stdlib.h>
void initialize()
{
	char questions[50][250];
	char options[50][100];
	char temp[20000];
	FILE *fp;
	if((fp=fopen("questions.txt", "r"))==NULL){
            printf("Cannot open file \n");
            exit(0);
        }
        int i=0;char c;
        while (c!= EOF)
            c= temp[i++] = fgetc(fp);
        temp[i]='\0';
        fclose(fp);
        int first = 1;
        int index=0; int k=0; int flagQues=0;
        for(int j=0;j<i;j++){
             if(temp[j]==')' && first){
             	flagQues=1;
             	first = 0;
             	continue;
             }
             if(temp[j]!='\n'){
                if(flagQues)
        	   questions[index][k++]=temp[j];
             }
             else{
             	questions[index][k]='\0';
             	index++;
             	k=0;
             	flagQues=0;
             	first = 1;
             }
        }
        
        char tempAns[20000];
	FILE *fp2;
	if((fp2=fopen("answers.txt", "r"))==NULL){
            printf("Cannot open file \n");
            exit(0);
        }
        i=0;char c2;
        while (c2!= EOF)
            c2= tempAns[i++] = fgetc(fp2);
        tempAns[i]='\0';
        fclose(fp2);
        index=0; k=0; int flagAns=0;
        for(int j=0;j<i;j++){
             if(tempAns[j]==')'){
             	flagAns=1;
             	continue;
             }
             if(tempAns[j]!='\n'){
                if(flagAns)
        	   options[index][k++]=tempAns[j];
             }
             else{
             	options[index][k]='\0';
             	index++;
             	k=0;
             	flagAns=0;
             }
        }
        printf("Questions buffer : \n%s\n\n",temp);
        printf("Answers buffer :\n%s\n\n",tempAns);
        printf("Questions array : \n");
        for(i =0;i<50;i++){
        	printf("%s\n",questions[i]);
        }
        printf("Answers array :\n");
	for(i =0;i<50;i++){
        	printf("%s\n",options[i]);
        }
}
int main()
{
	 initialize();
	 return 0;
}
