/*
============================================================================
Name : 15.c
Author : Dhruvik Patel - MT2024043
Description : Write a simple program to send some data from parent to the 
child process.
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
	int c_id = fork();
	if(c_id==-1)
	{
		printf("Error in creating child process\n");
		return 0;
	}
	char buff[50];
	if(c_id==0)
	{
		close(fd[1]);
		int rcount = read(fd[0],&buff,sizeof(buff));
		if(rcount==-1)
		{
			printf("Error in reading data from parent\n");
			return 0;
		}
		printf("Data received from parent:\n");
		printf("%s\n",buff);
	}	
	else
        {
        	printf("Enter the data to send to child process\n");
        	scanf("%[^\n]",buff);
                close(fd[0]);
                int wcount = write(fd[1],&buff,sizeof(buff));
                if(wcount==-1)
                {
                        printf("Error in sending data to child process \n");
                        return 0;
                }
		printf("Data sent to child process\n\n");
        }
	return 0;
}

/*
Enter the data to send to child process
hii child
Data sent to child process

Data received from parent:
hii child
*/
