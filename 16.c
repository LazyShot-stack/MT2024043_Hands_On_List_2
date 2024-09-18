/*
============================================================================
Name : 16.c
Author : Dhruvik Patel - MT2024043
Description :Write a program to send and receive data from parent to child 
vice versa. Use two way communication.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>

int main()
{
	int p_fd[2];
	int c_fd[2];
        int p_val = pipe(p_fd);
	int c_val = pipe(c_fd);
        if(p_val==-1 || c_val==-1)
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
	char buff[10];
        if(c_id==0)
        {
                close(p_fd[1]);
                int rcount = read(p_fd[0],&buff,sizeof(buff));
                if(rcount==-1)
                {
                        printf("Error in reading data from parent\n");
                        return 0;
                }
                printf("Data received from parent:\n");
                printf("%s\n",buff);
		printf("Child to parent\n");
		printf("Enter the data to send to parent process\n");
                scanf("%[^\n]",buff);
                close(c_fd[0]);
                int wcount = write(c_fd[1],&buff,sizeof(buff));
                if(wcount==-1)
                {
                        printf("Error in sending data to parent  process \n");
                        return 0;
                }
                printf("Data has been sent to parent process\n");

        }
        else
        {
		printf("Parent to child\n");
                printf("Enter the data to send to child process\n");
                scanf("%[^\n]",buff);
                close(p_fd[0]);
                int wcount = write(p_fd[1],&buff,sizeof(buff));
                if(wcount==-1)
                {
                        printf("Error in sending data to child process \n");
                        return 0;
                }
                printf("Data has been sent to child process\n");
		close(c_fd[1]);
                int rcount = read(c_fd[0],&buff,sizeof(buff));
                if(rcount==-1)
                {
                        printf("Error in reading data from child\n");
                        return 0;
                }
                printf("Data received from child:\n");
                printf("%s\n",buff);

        }

	return 0;
}

/*
Parent to child
Enter the data to send to child process
Hii child
Data has been sent to child process
Data received from parent:
Hii child
Child to parent
Enter the data to send to parent process
I am good
Data has been sent to parent process
Data received from child:
I am good
*/
