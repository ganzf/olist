/*
** print_info.c for print_info in /home/ganz_f/OriasDev/olist
** 
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
** 
** Started on  Wed Jul  6 17:32:58 2016 Felix Ganz
** Last update Wed Jul  6 17:48:35 2016 Felix Ganz
*/

#include <stdio.h>
#include "olist.h"

void	print_manager_info(t_list_manager *manager)
{
  printf("Name:\t%s\n", manager->name);
  printf("Id :\t%i\n", manager->id);
  printf("L.U :\t%i\n", (int)manager->created_at);
  printf("Size :\t%i\n", manager->size);
}
