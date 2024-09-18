/*
===============================================================================
Name : 18.c
Author : Dhruvik Patel - MT2024043
Description :Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
        int fd[2];
	int fd2[2];
        int val = pipe(fd);
	int val2 = pipe(fd2);
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
		int c2 = fork();
		if(c2==0)
		{
			close(1);
			close(fd2[0]);
                	int f2 = dup(fd2[1]);
			execl("/usr/bin/grep","grep","^d",NULL);
		}
		else
		{
			close(0);
			close(fd2[1]);
			int f2 = dup(fd2[0]);
			execl("/usr/bin/wc","wc",NULL);
		}
		
        }
        return 0;
}
//      0       0       0

