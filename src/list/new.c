/*
** new.c for new in /home/ganz_f/OriasDev/olist
** 
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
** 
** Started on  Wed Jul  6 17:51:43 2016 Felix Ganz
** Last update Wed Jul  6 17:52:11 2016 Felix Ganz
*/

#include <stdlib.h>
#include <string.h>
#include "olist.h"

t_list			*create_list(char *name)
{
  static int		id = 0;
  t_list		*new;

  if (name == NULL)
    return (NULL);
  if ((new = malloc(sizeof(t_list_manager))) == NULL)
    return (NULL);
  new->id = id;
  new->size = 0;
  new->created_at = time(NULL);
  if ((new->name = strdup(name)) == NULL)
    {
      free(new);
      return (NULL);
    }
  return (new);
}
