/*
** print_info.c for print_info in /home/ganz_f/OriasDev/olist
**
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
**
** Started on  Wed Jul  6 17:32:58 2016 Felix Ganz
** Last update Fri Jul  8 19:13:31 2016 Felix Ganz
*/

#include <stdbool.h>
#include <stdio.h>
#include "color.h"
#include "unit_test.h"
#include "olist.h"

void	print_post_it(t_post_it *post_it)
{
  printf("%s|-------------------------|"T_END"\n", post_it->color);
  printf("Title:\t%s%s"T_END"\n", post_it->color, post_it->title);
  printf("Desc:\t%s\n", post_it->description);
  printf("%s|_________________________|"T_END"\n", post_it->color);
}

void	print_elem_info(t_elem *elem)
{
  print_post_it((t_post_it *)elem->data);
  printf("Id :\t%i\n", elem->id);
  printf("L.U :\t%s\n", ctime(&elem->created_at));
}

void	print_elems_info(t_list *list)
{
  t_elem *tmp;

  if (list->size > 0)
    {
      tmp = list->elems;
      while (tmp != NULL)
	{
	  print_elem_info(tmp);
	  tmp = tmp->next;
	}
    }
}

void	print_managed_lists(const t_list_manager *manager)
{
  int	idx;

  idx = 0;
  printf(T_G"%s"T_END"\'s managed lists :\n", manager->name);
  while (manager->managed_lists[idx] != NULL)
    {
      printf("-\t-\t[ "T_B"%i"T_END" ] "T_G"%s (%i elems)"T_END"\n",
	     idx, manager->managed_lists[idx]->name,
	     manager->managed_lists[idx]->size);
      print_elems_info(manager->managed_lists[idx]);
      idx += 1;
    }
  if (manager->managed_lists[0] == NULL)
    printf("-\t-\t"T_R"No managed lists.\n"T_END);
}

void	print_manager_info(const t_list_manager *manager)
{
  printf("\n[__MANAGER_INFO__]\n");
  printf("Name:\t"T_G"%s"T_END"\n", manager->name);
  printf("Id :\t%i\n", manager->id);
  printf("L.U :\t%s\n", ctime(&manager->created_at));
  printf("Size :\t%i\n", manager->size);
  print_managed_lists(manager);
}

void	print_list_info(const t_list *list)
{
  printf("\n[__LIST_INFO__]\n");
  printf("Name:\t"T_G"%s"T_END"\n", list->name);
  printf("Id :\t%i\n", list->id);
  printf("L.U :\t%s\n", ctime(&list->created_at));
  printf("Size :\t%i\n", list->size);
  printf("Circ :\t%s\n", list->circular == false ? T_R"false"T_END : T_G"true"T_END);
}
