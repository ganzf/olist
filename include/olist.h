/*
** olist.h for olist in /home/ganz_f/OriasDev/olist
**
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
**
** Started on  Wed Jul  6 16:31:53 2016 Felix Ganz
** Last update Wed Jul  6 16:57:18 2016 Felix Ganz
*/

#ifndef OLIST_H_
# define OLIST_H_

#include <time.h>

typedef struct	s_elem
{
  void		*data;
  struct s_elem	*next;
  struct s_elem	*prev;
  struct s_list	*root;
}		t_elem;

typedef struct	s_list
{
  int		id;
  int		circular;
  int		size;
  time_t	created_at;
  char		*name;
}		t_list;

typedef struct	s_list_manager
{
  int		id;
  int		size;
  time_t	created_at;
  char		*name;
}

#endif /* !OLIST_H_ */
