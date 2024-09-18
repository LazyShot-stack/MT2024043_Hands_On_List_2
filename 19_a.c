/*
===============================================================================
Name : 19_a.c
Author : Dhruvik Patel - MT2024043
Description :Create a FIFO file by
a. mknod system call
===============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	int val = mknod("fifofile",S_IFIFO,0);
	if(val==-1)
	{
		printf("Error in creating fifo file\n");
		return 0;
	}	
	struct stat s;
	val = stat("fifofile",&s);
	if(s.st_mode & S_IFIFO)
	{
		printf("FIFO file created sucessfully!\n");
	}
	else
	{
		printf("FIFO file not created\n");
	}
	return 0;
}
//Error in creating fifo file

