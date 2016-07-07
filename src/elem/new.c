/*
** new.c for new in /home/ganz_f/OriasDev/olist
**
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
**
** Started on  Thu Jul  7 09:17:52 2016 Felix Ganz
** Last update Thu Jul  7 11:24:20 2016 Felix Ganz
*/

#include <stdlib.h>
#include "olist.h"

static t_elem	*last_elem(t_elem *elems)
{
  t_elem	*tmp;

  tmp = elems;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  return (tmp);
}

t_elem		*add_elem_to_list(t_list *list, void *data)
{
  static int	id = 0;
  t_elem	*new;
  t_elem	*last;

  if (list == NULL || (new = malloc(sizeof(t_elem))) == NULL)
    return (NULL);
  new->id = id;
  new->created_at = time(NULL);
  new->list = list;
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  if (list->elems == NULL)
    list->elems = new;
  else
    {
      last = last_elem(list->elems);
      last->next = new;
      new->prev = last;
    }
  id += 1;
  list->size += 1;
  return (new);
}
