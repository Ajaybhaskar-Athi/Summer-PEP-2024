// : Find Maximum Index Difference
// Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
//or simpley arr[i]<arr[j] and i<j 
// Input: arr = {10, 3, 5, 7, 8, 9, 2, 6} Output: 6

#include <iostream>
#include <vector>
#include <algorithm>

int maxIndexDiff(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;

    std::vector<int> leftMin(n);
    std::vector<int> rightMax(n);

    // Populate leftMin array
    leftMin[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        leftMin[i] = std::min(arr[i], leftMin[i - 1]);
    }

    // Populate rightMax array
    rightMax[n - 1] = arr[n - 1];
    for (int j = n - 2; j >= 0; --j) {
        rightMax[j] = std::max(arr[j], rightMax[j + 1]);
    }

    // Traverse leftMin and rightMax to find the maximum difference (j - i)
    int i = 0, j = 0, maxDiff = -1;
    while (j < n && i < n) {
        if (leftMin[i] < rightMax[j]) {
            maxDiff = std::max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }

    return maxDiff;
}

int main() {
    std::vector<int> arr = {10, 3, 5, 7, 8, 9, 2, 6};
    int maxDiff = maxIndexDiff(arr);
    std::cout << "Maximum index difference is: " << maxDiff << std::endl;
    return 0;
}
