#include "sort.h"

/**
 * selection_sort - function to perform selection sort on an array
 * @array: argument of type 'int *'
 *	array to be sorted
 * @size: argument of type "size_t"
 *	size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	/* code only runs if size of array is greater then 2 */
	if (size > 2)
	{
		for (i = 0; i < (size - 1); i++)
		{
			min = i;

			for (j = i + 1; j < size; j++)
			{
				/* check if array at j is less then array at min */
				if (array[j] < array[min])
				{
					/* update min */
					min = j;
				}
			}
			if (min != i)
			{
				temp = array[i];
				array[i] = array[min];
				array[min] = temp;
				print_array(array, size);
			}
		}
	}
}
