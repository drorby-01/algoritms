#include<iostream>
#include<stdlib.h>
using namespace std;

/*****************************************************************************************************************/

void insert_number_array(int *arr, int size)//insert numbers to aray
{
	for (int i = 0; i < size; i++)
	{
		cout << "enter a number" << endl;
		cin >> arr[i];
	}
}

int max(int num1, int num2)//return max between 2 numbers
{
	return num1 > num2 ? num1 : num2;
}

int min(int num1, int num2)//return min between 2 numbers
{
	return num1 < num2 ? num1 : num2;
}

void swapadrees(int **arr, int **brr)//swap arrays
{
	int **temp;
	temp = arr;
	arr = brr;
	brr = temp;
}

/*****************************************************************************************************************/

int size_array_is_one(int *arr, int *brr, int arr_size, int brr_size)//check if there arrayh is size is 1
{
	int sum;
	sum = arr_size + brr_size;
	if (sum % 2 == 1)
	{
		if (brr[brr_size / 2 - 1]<arr[0] && brr[brr_size / 2]>arr[0])
			return arr[0];
		else if (brr[brr_size / 2 - 1]<arr[0] && brr[brr_size / 2]>arr[0])
			return brr[brr_size / 2];
		else if (brr_size / 2 - 2 > 0 && brr[brr_size / 2 - 1] > arr[0] && brr[brr_size / 2 - 2] < arr[0])
			return arr[0];
		else if (brr_size / 2 - 2 > 0 && brr[brr_size / 2 - 1] > arr[0] && brr[brr_size / 2 - 2] > arr[0])
			return brr[brr_size / 2 - 2];
		else if (arr[0] > brr[brr_size / 2 - 1] && arr[0] > brr[brr_size / 2])
			return brr[brr_size / 2];
		else if (brr[brr_size / 2 - 1] == arr[0])
			return arr[0];
	}
	else
	{
		if (brr[brr_size / 2] == arr[0])
			return arr[0];
		else if (brr[brr_size / 2] > arr[0] && brr[brr_size / 2 - 1] > arr[0])
			return brr[brr_size / 2 - 1];
		else if (brr[brr_size / 2] > arr[0] && brr[brr_size / 2 - 1] < arr[0])
			return arr[0];
		else if ((brr[brr_size / 2] < arr[0] && brr[brr_size / 2 + 1] < arr[0]) || (brr[brr_size / 2] < arr[0] && brr[brr_size / 2 + 1] >= arr[0]))
			return brr[brr_size / 2];
	}
}

void size_of_arry_is_ziro(int *arr, int *brr, int arr_size, int brr_size)//check if there array his size is zero 
{
	if (arr_size == brr_size)
		cout << "there is no median" << endl;
	else if (arr_size == 0 && brr_size % 2 == 1)
		cout << "the median is" << brr[brr_size / 2];
	else if (arr_size == 0 && brr_size % 2 == 0)
		cout << "the median is " << brr[brr_size / 2 - 1];
}

/*****************************************************************************************************************/

void middle_of_sorted_araays()//the main function
{
	int *arr, *brr, size1, size2, odd_or_even = 0, sum, start = 0, end, partiton_x, partiton_y, minimum, maximum;
	cout << "enter the size of the first array" << endl;
	cin >> size1; //size of arr
	cout << "enter the size of the second  array" << endl;
	cin >> size2; //size of brr
	if (size2 < size1) swapadrees(&arr, &brr);
	end = min(size1, size2); end--;
	arr = new int[min(size1, size2) + 1];
	minimum = min(size1, size2);
	cout << "insert number to the short array" << endl;
	insert_number_array(arr, minimum); //insert number to arr-short array
	maximum = max(size1, size2);
	brr = new int[maximum];
	cout << "insert numbers to the long array " << endl;
	insert_number_array(brr, maximum); //insert number to brr-long array
	if (!minimum)//size of arr or brr is 0
	{
		size_of_arry_is_ziro(arr, brr, minimum, maximum);//func for size of arr or brr is 0
		return;
	}
	sum = size1 + size2; //check the long of the arrries toghter
	if (sum % 2 == 1) odd_or_even = 1;
	cout << "the median is: ";
	if (min(size1, size2) == 1)//size of arr or brr is 1
	{
		if (arr[0] == brr[size2 / 2])
		{
			cout << arr[0] << endl;
			return;
		}
		else
		{
			cout << size_array_is_one(arr, brr, minimum, maximum) << endl;//func for size of arr or brr is 1
			return;
		}
	}
	if (arr[minimum - 1] <= brr[0] && odd_or_even)//sum is odd
	{
		cout << brr[(maximum - minimum) / 2] << endl;
		return;
	}
	else if ((arr[minimum - 1] <= brr[0] || arr[0] >= brr[maximum - 1]) && !odd_or_even)//sum is even
	{
		if (arr[minimum - 1] <= brr[0])
		{
			if (size1 == size2)//sum is even and the sizes equals
			{
				cout << arr[minimum - 1] << endl;
				return;
			}
			else
			{
				cout << brr[(maximum - minimum - 1) / 2] << endl;
				return;
			}
		}
		else {
			if (size1 == size2)//sum is even and the sizes equals
			{
				cout << brr[maximum - 1] << endl;
				return;
			}
			else
			{
				cout << brr[(maximum - minimum - 1) / 2] << endl;
				return;
			}
		}
	}
	while (1)
	{
		partiton_x = (start + end) / 2;
		partiton_y = (size1 + size2 + 1) / 2 - partiton_x;
		if (arr[partiton_x - 1] <= brr[partiton_y] && brr[partiton_y - 1] > arr[partiton_x])
		{
			if (end == start && !odd_or_even)//check if i in situation after the serch on short array i move all number to te right size and end equal to stat
			{
				partiton_x = (start + end) / 2;
				partiton_y = (size1 + size2 + 2) / 2 - partiton_x;
				cout << min(min(brr[partiton_y - 1], arr[partiton_x]), max(brr[partiton_y - 2], arr[partiton_x - 1])) << endl;
				return;
			}
			else if (end == start&&odd_or_even)//check if i in situation after the serch on short array i move all number to te right size and end equal to stat  
			{
				partiton_x = (start + end) / 2;
				partiton_y = (size1 + size2 + 2) / 2 - partiton_x;
				cout << max(arr[partiton_x - 2], brr[partiton_y - 1]) << endl;
				return;
			}
			start = partiton_x + 1;
		}
		else
			if (arr[partiton_x - 1] > brr[partiton_y] && brr[partiton_y - 1] <= arr[partiton_x])
			{
				end = partiton_x - 1;
			}
		if (partiton_x == 0)
		{
			cout << min(brr[partiton_y - 1], brr[partiton_y]) << endl;
			return;
		}
		if ((arr[partiton_x - 1] < brr[partiton_y]) && (brr[partiton_y - 1] < arr[partiton_x]))
			break;
	}
	cout << max(arr[partiton_x - 1], brr[partiton_y - 1]) << endl;
	delete[] arr;
	delete[] brr;
}

/*****************************************************************************************************************/

int  main()
{
	cout << "To run First question press any button, for exit 0" << endl;
	int select;
	cin >> select;
	while (select != 0)
	{
		middle_of_sorted_araays();
		cout << "\nif you want to continue press any button unless 0\n";
		cin >> select;
	}
}
