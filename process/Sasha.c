#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
void child(char*);
int main(){
	char arr[10] = {0};
	while(strcmp(arr,"exit") != 0){
	//scanf("%s",arr);
	fgets(arr,10,stdin);
	child(arr);
	}
}
void child(char arr[]){
	char command[50];
	strcpy(command, arr);
	strcat(command, "> file.txt"); 
	if(system(command) != 0){
		perror("system");
		exit(1);
	}
	pid_t pid = fork();
	if(!pid){
		execlp(arr,arr,NULL);
		exit(1);
	}
	wait(NULL);

}
