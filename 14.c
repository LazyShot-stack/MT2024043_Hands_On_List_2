/*
============================================================================
Name : 14.c
Author : Dhruvik Patel - MT2024043
Description : Write a simple program to create a pipe, write to the pipe, read 
from pipe and display on the monitor.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>

int main()
{
	int fd[2];
	int val  = pipe(fd);
	if(val==-1)
	{
		printf("Error in creating pipe\n");
		return 0;
	}
	char wbuff[10];
	printf("Enter the Text to be written to pipe\n");
	scanf("%[^\n]",wbuff);
	int wcount = write(fd[1],&wbuff,sizeof(wbuff));
	close(fd[1]);
	printf("Writing text to pipe\n");
	char rbuff[10];
	int rcount = read(fd[0],&rbuff,wcount);
	printf("Reading text from pipe\n");
	write(1,&rbuff,rcount);
	printf("\n");
	close(fd[0]);
	return 0;
}

/*
Enter the Text to be written to pipe
Hello 
Writing text to pipe
Reading text from pipe
Hello�v�
*/
