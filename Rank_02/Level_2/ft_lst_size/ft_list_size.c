#include "ft_list.h"

int	ft_lst_size(t_list *begin_list)
{
	int i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		++i;
	}
	return (i);
}
/*
#include <stdio.h>
int main()
{
    	t_list node1, node2, node3;

	node1.data = "Node 1";
	node1.next = &node2;

	node2.data = "Node 2";
	node2.next = &node3;

	node3.data = "Node 3";
	node3.next = NULL;

	int size = ft_lst_size(&node1);
	printf("Size of the list: %d\n", size);  // Debería imprimir 3

}
*/
