#include "pm.h"

int verifyPass(char *pass)
{
    int i = 0;
    int length = strlen(pass);
    int flag_upper = 0;
    int flag_lower = 0;
    int flag_digit = 0;

    while (pass[i])
    {
        if (isupper(pass[i]))
            flag_upper++;
        if (islower(pass[i]))
            flag_lower++;
        if (isdigit(pass[i]))
            flag_digit++;
        i++;
    }
    if (flag_digit < 1 || flag_lower < 1 || flag_upper < 1 || length < 6)
        return 1;
    return (0);
}

void exit_prog(t_pm *pm)
{
    ft_lstclear(&pm->account_lst);
    free(pm->master_pass);
    exit(1);
}

int login(t_pm *pm)
{
    char *input;

    while (1)
    {
        input = readline("password: ");
        if (!strcmp("exit", input)) 
        {
            free(input);
            exit_prog(pm);
        }
        else if (!strcmp(pm->master_pass, input))
        {
            free(input);
            return (0);
        }
        free(input);
    }
    return (0);
}

void init_master(t_pm *pm)
{
    char* line = NULL;
    size_t len = 0;
    FILE* fmaster;
    fmaster = fopen("master.txt", "r");
    if (fmaster == NULL)
    {
        fmaster = fopen("master.txt", "a");
        while (1)
        {
            pm->master_pass = readline("New password: ");
            if (!verifyPass(pm->master_pass))
            {
                fprintf(fmaster,"%s", pm->master_pass);
                fflush(fmaster); 
                break;
            }
            else
            {
                printf("\x1B[31mInvalid Weak Password. Please try again.\x1B[0m\n");
            }
        }
    }
    else
    {
        fmaster = fopen("master.txt", "r");
        while (getline(&line, &len, fmaster) != -1)
        {
            pm->master_pass = strdup(line);
        }
        if (line != NULL) {
            free(line);
        }
        if(!login(pm))
            return;
        fclose(fmaster);
    }
}

void menu_options(char *option, t_pm *acc_lst)
{
    char *input;
    if (!strcmp(option, "1"))
    {
        add_account(acc_lst);
        add_to_file(&acc_lst->account_lst, "crediential.csv");
    }
    else if (!strcmp(option, "2"))
    {
        input = readline("Enter Website: ");
        viewAccountByWebsite(&acc_lst->account_lst, input);
        free(input);
    }
    else if (!strcmp(option, "3"))
    {
        encryption("crediential.csv");
        encryption("master.txt");
        exit_prog(acc_lst);
    }
    else
        printf("\x1B[31mInvalid option. Please try again.\x1B[0m\n");
}

int main()
{
    t_pm pm;
    decryption("crediential.csv");
    char *input;
    pm.master_pass = NULL;
    pm.account_lst = NULL;
    decryption("master.txt");
    init_master(&pm);
    parse_csv(&pm.account_lst, "crediential.csv");
    while (1)
    {
        printf("\x1B[36m1. Add Account\n");
        printf("2. Show Accounts\n");
        printf("3. Exit\n\x1B[0m");
        input = readline("");
        menu_options(input, &pm);
        if (strcmp(input, "exit") == 0)
            break;
    }
    return (0);
}