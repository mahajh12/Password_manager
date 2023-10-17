#include "pm.h"

void encryption(const char *filename)
{
    FILE *file = fopen(filename, "r+");
    if (file == NULL)
        return;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            if ((ch >= 'A' && ch <= 'M') || (ch >= 'a' && ch <= 'm'))
                ch += 13;
            else
                ch -= 13;
        }
        fseek(file, -1, SEEK_CUR);
        fputc(ch, file);
    }
    fclose(file);
}

void decryption(const char *filename)
{
    FILE *file = fopen(filename, "r+");
    if (file == NULL)
        return;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            if ((ch >= 'A' && ch <= 'M') || (ch >= 'a' && ch <= 'm'))
                ch += 13;
            else
                ch -= 13;
        }
        fseek(file, -1, SEEK_CUR);
        fputc(ch, file);
    }

    fclose(file);
}
