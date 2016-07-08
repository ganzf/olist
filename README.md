# olist - A linked list manager
   Make it easy!

# Use

Create a new linked list manager with "new_list_manager("name")"
You can now add lists to the list_manager "name", with "new_list(list_manager, "list_name")".
You can now add elements to the list "list_name" with add_to_list(elem, list)

The reason you have lists_manager is that you can more easily free your lists with functions such as
- delete_all_lists(list_manager)
- delete_list(list)

Also elems are simple : they use void * pointers to create flexibility. Simply create your own type of data and you can use olist. (For example, make a simple post_it structure, like I did!)

# Repository

Use make to build the library and the unit test program.
Use make test_c, test_f, test_r... to control unit tests program.
