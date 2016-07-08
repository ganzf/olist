/*
** unit_test.h for unit_test in /home/ganz_f/OriasDev/olist
** 
** Made by Felix Ganz
** Login   <ganz_f@ganz-f-pc>
** 
** Started on  Fri Jul  8 19:12:18 2016 Felix Ganz
** Last update Fri Jul  8 19:14:45 2016 Felix Ganz
*/

#ifndef UNIT_TEST_H_
# define UNIT_TEST_H_

# include "olist.h"

typedef struct		s_post_it
{
  char			*title;
  char			*description;
  char			*color;
}			t_post_it;

void			print_manager_info(const t_list_manager *manager);
void			print_list_info(const t_list *list);

#endif /* !UNIT_TEST_H_ */
