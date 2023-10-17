#include "pm.h"

void add_to_file(t_data **acc_lst, const char *filename)
{
    FILE *credential_file = fopen(filename, "w");
    if (credential_file == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    fprintf(credential_file, "Website,Username,Password\n");
    t_data *current = *acc_lst;
    while (current != NULL)
    {
        t_credential *credential = current->credential;
        fprintf(credential_file, "%s,%s,%s\n", credential->website, credential->username, credential->password);
        current = current->next;
    }
    fclose(credential_file);
}

void add_to_lst(char *usr, char *pass, char *web, t_data **acc_lst)
{
    t_credential *add_acc;
    t_data *new_acc;

    add_acc = malloc(sizeof(t_credential));
    if (add_acc == NULL)
        return;
    add_acc->website = strdup(web);
    add_acc->username = strdup(usr);
    add_acc->password = strdup(pass);
    new_acc = ft_lstnew(add_acc);
    ft_lstadd_back(acc_lst, new_acc);
}

void add_account(t_pm *pm)
{
    char *user_input = readline("username: ");
    char *website_input = readline("Website name: ");
    char *pass_input = readline("Password: ");
    add_to_lst(user_input, pass_input, website_input, &pm->account_lst);
}