#ifndef PM_H
# define PM_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include <readline/readline.h>

typedef struct credential
{
    char *website;
    char *username;
    char *password;
} t_credential;

typedef struct data
{
	char		content;
    t_credential *credential;
	struct data *next;
}	t_data;

typedef struct pm
{
    t_data *account_lst;
    char *master_pass;
} t_pm;


void    encryption(const char *filename);
void    decryption(const char *filename);
void    add_account(t_pm *acc_lst);
void    add_to_lst(char *usr, char *pass, char *web, t_data **acc_lst);
void    add_to_file(t_data **acc_lst, const char *filename);
void    viewAccountByWebsite(t_data **acc_lst, const char *website);
void    ft_lstadd_back(t_data **lst, t_data *new);
void    ft_lstadd_front(t_data **lst, t_data *new);
void    ft_lstdelone(t_data *lst);
void    ft_lstclear(t_data **lst);
void    print_list(t_data *head);
int     parse_csv(t_data **acc_lst, const char *filename);
int     ft_lstsize(t_data *lst);
t_data  *ft_lstnew(t_credential *content);
t_data  *ft_lstlast(t_data *lst);

#endif