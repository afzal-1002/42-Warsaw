#include "../../push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int arr[], int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = arr[end];
	i = start;
	j = start;
	while (i < end)
	{
		if (arr[i] < pivot)
		{
			swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	// 👑 PUT PIVOT IN CORRECT PLACE
	swap(&arr[j], &arr[end]);
	// 🔁 SORT LEFT & RIGHT
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void	bubble_sort(int *arr, int size)
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("%d moves", i);
}

int	is_sorted(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}
