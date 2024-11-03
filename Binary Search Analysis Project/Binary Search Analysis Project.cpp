#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recursiveBinarySearch(const vector<int>& vec, int target, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (vec[mid] == target)
        return mid;
    else if (vec[mid] > target)
        return recursiveBinarySearch(vec, target, left, mid - 1);
    else
        return recursiveBinarySearch(vec, target, mid + 1, right);
}

int iterativeBinarySearch(const vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int sequentialSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target)
            return i;
    }
    return -1;
}

int main() {
    vector<int> numbers = { 3, 6, 8, 12, 14, 17, 20, 25, 29, 32, 35 };
    sort(numbers.begin(), numbers.end());

    int target1 = 14;
    int target2 = 27;

    cout << "Contents of vector: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    int index = recursiveBinarySearch(numbers, target1, 0, numbers.size() - 1);
    cout << "Recursive binary search: " << target1 << " found at location " << index << endl;

    index = recursiveBinarySearch(numbers, target2, 0, numbers.size() - 1);
    cout << "Recursive binary search: " << target2 << " was not found, return value is " << index << endl;

    index = iterativeBinarySearch(numbers, target1);
    cout << "Iterative binary search: " << target1 << " found at location " << index << endl;

    index = iterativeBinarySearch(numbers, target2);
    cout << "Iterative binary search: " << target2 << " was not found, return value is " << index << endl;

    index = sequentialSearch(numbers, target1);
    cout << "Sequential search: " << target1 << " found at location " << index << endl;

    index = sequentialSearch(numbers, target2);
    cout << "Sequential search: " << target2 << " was not found, return value is " << index << endl;

    return 0;
}
