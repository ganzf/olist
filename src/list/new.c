/*
** new.c for new in /home/ganz_f/OriasDev/olist
** 
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
** 
** Started on  Wed Jul  6 17:51:43 2016 Felix Ganz
** Last update Thu Jul  7 08:37:30 2016 Felix Ganz
*/

#include <stdlib.h>
#include <string.h>
#include "olist.h"

t_list		*create_list(const char *name,
			     t_list_manager *manager)
{
  static int	id = 0;
  t_list	*new;

  if (name == NULL || (new = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  new->id = id;
  new->size = 0;
  new->created_at = time(NULL);
  if ((new->name = strdup(name)) == NULL)
    {
      free(new);
      return (NULL);
    }
  add_list_to_manager(manager, new);
  return (new);
}
