/*
** new.c for new in /home/ganz_f/OriasDev/olist
** 
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
** 
** Started on  Wed Jul  6 17:51:43 2016 Felix Ganz
** Last update Fri Jul  8 19:28:00 2016 Felix Ganz
*/

#include <stdlib.h>
#include <string.h>
#include "olist.h"

static int	add_list_to_manager(t_list_manager *manager,
				    t_list *list)
{
  int		idx;

  idx = 0;
  while (manager->managed_lists[idx] != NULL
	 && idx < manager->size)
    idx += 1;
  if (idx == manager->size)
    return (false);
  manager->managed_lists[idx] = list;
  return (true);
}

t_list		*create_list(const char *name,
			     t_list_manager *manager,
			     int circular)
{
  static int	id = 0;
  t_list	*new;

  if (name == NULL || (new = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  new->id = id;
  new->size = 0;
  new->created_at = time(NULL);
  new->manager = manager;
  new->circular = circular;
  new->elems = NULL;
  if ((new->name = strdup(name)) == NULL)
    {
      free(new);
      return (NULL);
    }
  add_list_to_manager(manager, new);
  id += 1;
  return (new);
}
