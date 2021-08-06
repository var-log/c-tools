#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Usage ./move <input file> <output file> ie: ./move /home/user/docs/input.txt /home/user/input.txt\n");
    }
    else
    {
        FILE* ptr = fopen(argv[1], "r");
        if (ptr == NULL)
        {
            printf("File not found.\n");
        }
        else
        {
            char ch;
            FILE* ptr2 = fopen(argv[2], "w");
            while((ch = fgetc(ptr)) != EOF)
            {
                fputc(ch, ptr2);
            }
            fclose(ptr);
            fclose(ptr2);
        }
        remove(argv[1]);
    }
}