/*
============================================================================
Name : 17_a.c
Author : Dhruvik Patel - MT2024043
Description :Write a program to execute ls -l | wc
a. use dup
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	int fd[2];
	int val = pipe(fd);
	if(val==-1)
	{
		printf("Error in creating pipe\n");
		return 0;
	}
	int cid = fork();
	if(cid==0)
	{
		close(1);
		close(fd[0]);
		int f = dup(fd[1]);
		execl("/usr/bin/ls","ls","-l",NULL);
	}
       	else 
	{
		close(0);
		close(fd[1]);
		int f = dup(fd[0]);
		execl("/usr/bin/wc","wc",NULL);
	}
	return 0;
}

//     36     317    1974

