/*
** main.c for main in /home/ganz_f/OriasDev/olist
**
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
**
** Started on  Wed Jul  6 16:29:26 2016 Felix Ganz
** Last update Thu Jul  7 08:42:22 2016 Felix Ganz
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "olist.h"

t_list		*test_list_creation(t_list_manager *manager)
{
  t_list	*list;
  t_list	*list2;

  printf("\t["T_G"Test"T_END"] List creation.\n");
  if ((list = create_list("First list", manager)) == NULL
      || (list2 = create_list("Second list", manager)) == NULL)
    {
      printf("[ "T_R"KO"T_END" ]\tList creation failed.\n");
      return (NULL);
    }
  print_list_info(list);
  print_list_info(list2);
  printf("[ "T_G"OK"T_END" ]\tList creation successful.\n");
  print_manager_info(manager);
  return (list);
}

t_list_manager		*test_manager_creation()
{
  char			*name;
  t_list_manager	*manager;

  printf("\t["T_G"Test"T_END"] Manager creation.\n");
  if ((name = strdup("First manager")) == NULL
      || (manager = create_list_manager(name, 5)) == NULL)
    {
      printf("[ "T_R"KO"T_END" ]\tManager creation failed.\n");
      return (NULL);
    }
  free(name);
  print_manager_info(manager);
  printf("[ "T_G"OK"T_END" ]\tManager creation successful.\n");
  return (manager);
}

int			main(void)
{
  t_list_manager	*manager;
  t_list		*list;

  if ((manager = test_manager_creation()) == NULL
      || (list = test_list_creation(manager)) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
