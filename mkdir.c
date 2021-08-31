#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage ./mkdir <path> ie: ./mkdir /home/users/newfolder\n");
    }
    else
    {
        if (mkdir(argv[1], 0777) == 0)
        {
            return 0;
        }
        else
        {
            printf("Unable to create directory.\n");
        }
    }
}