/*
** main.c for main in /home/ganz_f/OriasDev/olist
**
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
**
** Started on  Wed Jul  6 16:29:26 2016 Felix Ganz
** Last update Thu Jul  7 10:11:12 2016 Felix Ganz
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "olist.h"

static t_post_it	*create_post_it(char *title,
					char *description,
					char *color)
{
  t_post_it		*new;

  if ((new = malloc(sizeof(t_post_it))) == NULL
      || (new->title = strdup(title)) == NULL
      || (new->description = strdup(description)) == NULL
      || (new->color = strdup(color)) == NULL)
    return (NULL);
  return (new);
}

t_elem		*test_elem_creation(t_list *list)
{
  t_elem	*elem;
  t_post_it	*new;
  t_elem	*elem2;
  t_post_it	*new2;

  printf("\t["T_G"Test"T_END"] Elem creation.\n");
  if ((new = create_post_it("Courses",
			    "Il faudrait acheter a manger!!",
			    T_R)) == NULL)
    return (NULL);
  if ((elem = add_elem_to_list(list, new)) == NULL)
    {
      printf("[ "T_R"KO"T_END" ]\tElem creation failed.\n");
      return (NULL);
    }
  if ((new2 = create_post_it("Travail",
			    "Il faudrait aller travailler !!!!!",
			    T_B)) == NULL)
    return (NULL);
  if ((elem2 = add_elem_to_list(list, new2)) == NULL)
    {
      printf("[ "T_R"KO"T_END" ]\tElem creation failed.\n");
      return (NULL);
    }
  print_list_info(list);
  printf("[ "T_G"OK"T_END" ]\tElem creation successful.\n");
  print_manager_info(list->manager);
  return (elem);
}

t_list		*test_list_creation(t_list_manager *manager)
{
  t_list	*list;
  t_list	*list2;

  printf("\t["T_G"Test"T_END"] List creation.\n");
  if ((list = create_list("First list", manager, false)) == NULL
      || (list2 = create_list("Second list", manager, true)) == NULL)
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
      || (list = test_list_creation(manager)) == NULL
      || (test_elem_creation(list)) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
