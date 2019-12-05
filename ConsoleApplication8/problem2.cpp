#include <iostream>
#include <stdlib.h> 
using namespace std;

/*************************************************************************************************************/

int partition(int *arr, int p, int q)//part of the sort
{
	int x = arr[p];
	int i = p;
	int j;
	for (j = p + 1; j < q; j++)
	{
		if (arr[j] <= x)
		{
			i = i + 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[p]);
	return i;
}

void quickSort(int *arr, int p, int q)//sort arrays
{
	int r;
	if (p < q)
	{
		r = partition(arr, p, q);
		quickSort(arr, p, r);
		quickSort(arr, r + 1, q);
	}
}

/*************************************************************************************************************/

void Puzzle()//the main func
{
	int n_dogs, k_dogwalker, sum, max, min;
	int *dogs_size, *sub_array;
	cout << "Please enter the number of dogs " << endl;
	cin >> n_dogs;
	cout << "Please enter the number of dog walkers " << endl;
	cin >> k_dogwalker;
	if (n_dogs == k_dogwalker)//if the numbers of dogs equals to the numbers of walkers
	{
		cout << "The minimum cost is: 0";
		return;
	}
	dogs_size = new int[n_dogs];
	cout << "Enter the size of dog number 1" << endl;
	cin >> dogs_size[0];
	max = dogs_size[0];
	min = dogs_size[0];
	for (int i = 1; i < n_dogs; i++)
	{
		cout << "Enter the size of dog number" << i + 1 << endl;
		cin >> dogs_size[i];
		if (dogs_size[i] > max) max = dogs_size[i];
		if (dogs_size[i] < min) min = dogs_size[i];
	}
	if (k_dogwalker == 1)//if the number of walkers is 1
	{
		cout << "The minimum cost is:" << max - min;
		return;
	}
	quickSort(dogs_size, 0, n_dogs);//sort the sizes in the dog array
	sub_array = new int[n_dogs - 1];
	for (int i = 0; i < n_dogs - 1; i++)
	{
		sub_array[i] = dogs_size[i + 1] - dogs_size[i];
	}
	quickSort(sub_array, 0, n_dogs - 1);//sort the subs of sizes of dogs
	sum = 0;
	for (int i = 0; i <n_dogs - k_dogwalker; i++)
	{
		sum += sub_array[i];
	}
	cout << "The minimum cost is : " << sum << endl;
	delete[] dogs_size;
	delete[] sub_array;
}

/*************************************************************************************************************/

int  main()
{
	cout << "To run Second question press any button, for exit 0" << endl;
	int select;
	cin >> select;
	while (select != 0)
	{
		Puzzle();
		cout << "\nif you want to continue press any button unless 0\n";
		cin >> select;
	}
}

