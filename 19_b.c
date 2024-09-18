/*
===============================================================================
Name : 19_b.c
Author : Dhruvik Patel - MT2024043
Description :Create a FIFO file by
b. mkfifo library function
===============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
        int val = mkfifo("fifofile",0000);
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
//FIFO file created sucessfully!

