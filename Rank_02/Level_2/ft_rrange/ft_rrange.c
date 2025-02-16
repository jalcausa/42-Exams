#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int size = (end - start + 1);
	int *nums = (int *) malloc(size * sizeof(int));
	if (!nums)
		return (NULL);
	int i = 0;
	while (end >= start)
	{
		nums[i] = end;
		++i;
		--end;
	}
	return (nums);
}
/*
#include <stdio.h>

int main()
{
    int *arr = ft_range(0, 4);  // Prueba con (0, 4)
    int size = 5;  // Sabemos que el tamaño será 5 para este rango
    
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);  // Imprimirá 4, 3, 2, 1, 0
    }
    printf("\n");
    free(arr);  // Hay que  liberar la memoria
    return 0;
}
*/
