#include <iostream>
#include <string>

using namespace std;

string tenConvertTwo(int num)
{
	string result = "";
	for (int i = 1; num > 0; i *= 10)
	{
		int binary = num % 2;
		if (binary == 1)
			result += "#";
		else
			result += " ";
		num /= 2;
	}
	return result;
}

int main()
{
	int n = 0;
	
	cin >> n;
	
	int *arr1 = new int[n];
	int *arr2 = new int[n];
	int *map_arr = new int[n];
	string *mid_arr = new string[n];
	string *result_arr = new string[n];

	for (int i = 0; i < n; i++)
		cin >> arr1[i];

	for (int i = 0; i < n; i++)
		cin >> arr2[i];
	
	for (int i = 0; i < n; i++)
	{
		map_arr[i] = arr1[i] | arr2[i];
		mid_arr[i] = tenConvertTwo(map_arr[i]);
		result_arr[i] = mid_arr[i];
		
		for (int j = 0; j < n; j++)
			result_arr[i][j] = mid_arr[i][n - j - 1];
	}
	
	for (int i = 0; i < n; i++)
		cout << result_arr[i] << endl;

	delete arr1;
	delete arr2;
	delete map_arr;
	delete[] mid_arr;
	delete[] result_arr;

	return 0;
}