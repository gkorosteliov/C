#include <iostream>
#include <vector>

//Write a function flip(arr, k) that reverses the order of the first k elements in the array arr.
//Write a function pancakeSort(arr) that sorts and returns the input array. 

using namespace std;
void flip(vector<int>& arr, int pos)
{
    int temp, start = 0;
    while (start < pos) {
        temp = arr[start];
        arr[start] = arr[pos];
        arr[pos] = temp;
        start++;
        pos--;
    }
}
vector<int> pancakeSort(const vector<int>& arr1)
{
   vector<int> arr=arr1;
   for (int curr_size = arr.size(); curr_size > 1; --curr_size)
    {
        int max, i;
        for (max = 0, i = 0; i < curr_size; ++i)
        {
            if (arr[i] > arr[max])
            max = i;          
        }

        if (max < curr_size-1)
        {
            flip(arr, max);
            flip(arr, curr_size-1);
        }
    }
    return arr;
}

int main() {
  const vector<int>& arr {1, 5, 4, 3, 2};
  pancakeSort(arr);
  return 0;
}
