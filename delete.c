#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage ./delete <file> ie: ./delete file.txt\n");
    }
    else
    {
        if (remove(argv[1]) == 0)
        {
            return 0;
        }
        else
        {
            printf("Unable to delete file.\n");
        }
    }
}
