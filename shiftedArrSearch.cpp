#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//find position af an element in a shifted array of int(s)

int recursiveSearch(const vector<int>& shiftArr, int left, int right, int target)
{
  if (left > right) {
    return -1;
  }
  int mid = (left + right) / 2;
  if (shiftArr[mid] == target) {
    return mid;
  }
  if (shiftArr[left] < shiftArr[mid]) {
    if (target >= shiftArr[left] && target <= shiftArr[mid]) {
      return recursiveSearch(shiftArr, left, mid - 1, target);
    } else {
      return recursiveSearch(shiftArr, mid + 1, right, target);
    }
  } else {
    if (target >= shiftArr[mid] && target <= shiftArr[right]) {
      return recursiveSearch(shiftArr, mid + 1, right, target);
    } else {
      return recursiveSearch(shiftArr, left, mid - 1, target);
    }
  }
}


int shiftedArrSearch( const vector<int>& shiftArr, int num ) 
{
  return recursiveSearch(shiftArr, 0, shiftArr.size()-1, num);
}

int main() {
  const vector<int> shiftArr {17, 19, 20, 2, 4, 6, 8, 9, 10, 12};
  int num = 2;
  int res = shiftedArrSearch(shiftArr, num);
  return 0;
}

