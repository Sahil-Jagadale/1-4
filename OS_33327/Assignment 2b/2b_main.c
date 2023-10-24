#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

void sort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main(){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the numbers: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	pid_t pid = fork();
	
	if(pid<0){
		printf("Fork Failed!\n");
		return 1;
	}
	else if(pid==0){
		printf("Main process(PID: %d) started\n",getpid());
		sort(arr,n);
		printf("Sorted Array: ");
		for(int i=0;i<n;i++){
			printf("%d ",arr[i]);
		}
		
		char *args[n+2];
		args[0]="./cp";
		for(int i=0;i<n;i++){
			char buffer[10];
			snprintf(buffer,sizeof(buffer),"%d",arr[i]);
			args[i+1]=strdup(buffer);
		}
		args[n+1]= NULL ;
		execve(args[0],args,NULL);
		perror("execve");
		printf("Main process(PID: %d) completed\n",getpid());
		return 1;
	}
	else{
		printf("Parent process(PID: %d) started",getppid());
		wait(NULL);
		printf("Parent process completed\n");
	}
	return 0;
}
		
		
		
		
		
		
