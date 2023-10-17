#include "pm.h"

void viewAccountByWebsite(t_data **acc_lst, const char *website)
{
    t_data *current = *acc_lst;
    int found = 0;

    while (current != NULL) {
        t_credential *credential = current->credential;
        if (strcmp(credential->website, website) == 0)
        {
            printf("Website: %s\n", credential->website);
            printf("Username: %s\n", credential->username);
            printf("Password: %s\n", credential->password);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found)
        printf("No account found for website: %s\n", website);
}
