/*
** print_info.c for print_info in /home/ganz_f/OriasDev/olist
**
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
**
** Started on  Wed Jul  6 17:32:58 2016 Felix Ganz
** Last update Thu Jul  7 08:39:29 2016 Felix Ganz
*/

#include <stdio.h>
#include "olist.h"

void	print_managed_lists(const t_list_manager *manager)
{
  int	idx;

  idx = 0;
  printf(T_G"%s"T_END"\'s managed lists :\n", manager->name);
  while (manager->managed_lists[idx] != NULL)
    {
      printf("-\t-\t[ "T_B"%i"T_END" ] %s\n",
	     idx, manager->managed_lists[idx]->name);
      idx += 1;
    }
  if (manager->managed_lists[0] == NULL)
    printf("-\t-\t"T_R"No managed lists.\n"T_END);
}

void	print_manager_info(const t_list_manager *manager)
{
  printf("Name:\t%s\n", manager->name);
  printf("Id :\t%i\n", manager->id);
  printf("L.U :\t%i\n", (int)manager->created_at);
  printf("Size :\t%i\n", manager->size);
  print_managed_lists(manager);
}

void	print_list_info(const t_list *list)
{
  printf("Name:\t%s\n", list->name);
  printf("Id :\t%i\n", list->id);
  printf("L.U :\t%i\n", (int)list->created_at);
  printf("Size :\t%i\n", list->size);
}
