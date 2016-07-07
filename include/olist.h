/*
** olist.h for olist in /home/ganz_f/OriasDev/olist
**
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
**
** Started on  Wed Jul  6 16:31:53 2016 Felix Ganz
** Last update Thu Jul  7 09:43:30 2016 Felix Ganz
*/

#ifndef OLIST_H_
# define OLIST_H_

# include <time.h>
# include "color.h"

typedef struct		s_post_it
{
  char			*title;
  char			*description;
  char			*color;
}			t_post_it;

typedef struct		s_elem
{
  int			id;
  time_t		created_at;
  void			*data;
  struct s_elem		*next;
  struct s_elem		*prev;
  struct s_list		*list;
}			t_elem;

typedef struct		s_list
{
  int			id;
  int			circular;
  int			size;
  time_t		created_at;
  char			*name;
  t_elem		*elems;
  struct s_list_manager	*manager;
}			t_list;

typedef struct		s_list_manager
{
  int			id;
  int			size;
  time_t		created_at;
  char			*name;
  t_list		**managed_lists;
}			t_list_manager;

t_list_manager		*create_list_manager(char *name, int size);
void			print_manager_info(const t_list_manager *manager);
t_list			*create_list(const char *name, t_list_manager *manager, int circular);
void			print_list_info(const t_list *list);
int			add_list_to_manager(t_list_manager *manager, t_list *list);
t_elem			*add_elem_to_list(t_list *list, void *data);

#endif /* !OLIST_H_ */
