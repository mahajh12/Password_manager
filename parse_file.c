#include "pm.h"

int parse_csv(t_data **acc_lst, const char *filename)
{
    FILE *confidential_file;
    confidential_file = fopen(filename, "r");
    if (confidential_file == NULL)
        return (1);
    char line[256];
    int firstLine = 1;
    while (fgets(line, sizeof(line), confidential_file)) 
    {
        if (firstLine) 
        {
            firstLine = 0;
            continue; 
        }
        char *website = strtok(line, ",");
        char *username = strtok(NULL, ",");
        char *password = strtok(NULL, ",");
        if (website && username && password)
        {
            password[strcspn(password, "\n")] = '\0';
            add_to_lst(username, password , website, acc_lst);
        } 
        else 
            printf("Invalid line in the CSV file\n");
    }
    fclose(confidential_file);
    return 0;
}