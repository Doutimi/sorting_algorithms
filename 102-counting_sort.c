#include "sort.h"

/**
 * counting_sort - Algorithm that sorts the array in order ascended
 *@array: type array of integers.
 *@size: type size of array.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sort, sum, max;
	size_t a;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	max = array[0];
	for (a = 1; a < size; a++)
		max = (array[a] > max) ? array[a] : max;
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (a = 0; a < (size_t)(max + 1); a++)
		count[a] = 0;

	for (a = 0; a < size; a++)
		count[array[a]]++;

	for (a = 0, sum = 0; a < (size_t)(max + 1); a++)
	{
		count[a] += sum;
		sum = count[a];
	}
	print_array(count, max + 1);

	for (a = 0; a < size; a++)
	{
		sort[count[array[a]] - 1] = array[a];
		count[array[a]]--;
	}
	for (a = 0; a < size; a++)
		array[a] = sort[a];

	free(sort);
	free(count);
}

