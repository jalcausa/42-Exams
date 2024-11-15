#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{	
		int op1 = atoi(argv[1]);
		int op2 = atoi(argv[3]);
		char op = argv[2][0];
		if (op == '+')
			printf("%d", op1+op2);
		else if (op == '*')
	                printf("%d", op1*op2);
		else if (op == '-')
	                printf("%d", op1-op2);
		else if (op == '/')
	                printf("%d", op1/op2);
		else if (op == '%')
	                printf("%d", op1&op2);
	}
	printf("\n");
	return(0);
}
