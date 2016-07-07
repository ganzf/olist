/*
** new.c for new in /home/ganz_f/OriasDev/olist/src/manager
**
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
**
** Started on  Wed Jul  6 17:25:24 2016 Felix Ganz
** Last update Thu Jul  7 09:33:40 2016 Felix Ganz
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "olist.h"

int			add_list_to_manager(t_list_manager *manager,
					    t_list *list)
{
  int			idx;

  idx = 0;
  while (manager->managed_lists[idx] != NULL
	 && idx < manager->size)
    idx += 1;
  if (idx == manager->size)
    {
      fprintf(stderr, T_R"add_list_to_manager:"
	      T_END"\tManager "T_B"%s"
	      T_END" is full. Could not add "T_B"%s"
	      T_END" list.\n", manager->name, list->name);
      return (false);
    }
  manager->managed_lists[idx] = list;
  return (true);
}

static void		nullset(t_list **managed_list, int size)
{
  int			idx;

  idx = 0;
  while (idx < size)
    {
      managed_list[idx] = NULL;
      idx += 1;
    }
}

t_list_manager		*create_list_manager(char *name,
					     int size)
{
  static int		id = 0;
  t_list_manager	*new;
  t_list		**managed_lists;

  if (name == NULL)
    return (NULL);
  if ((new = malloc(sizeof(t_list_manager))) == NULL)
    return (NULL);
  new->id = id;
  new->size = size;
  new->created_at = time(NULL);
  if ((new->name = strdup(name)) == NULL)
    {
      free(new);
      return (NULL);
    }
  if ((managed_lists = malloc(sizeof(t_list *) * (size + 1))) == NULL)
    return (NULL);
  nullset(managed_lists, size + 1);
  new->managed_lists = managed_lists;
  id += 1;
  return (new);
}
