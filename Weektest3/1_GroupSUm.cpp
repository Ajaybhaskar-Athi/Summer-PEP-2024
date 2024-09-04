/*


The positive odd numbers are sorted in ascending order as 1, 3, 5, 7, 9, 11, 13, 15, and grouped as (1), (3, 5), (7, 9, 11), and so on.

Thus, the first group is (1), the second group is (3,5), the third group is (7,9,11). In general, the kth group contains the next elements of the sequence.

Given k, find the sum of the elements of the kith group. For example, for k = 3, the answer is 27

Input Format

• The first line contains a single integer k

Output Format

• Print the sum of the elements of the kith group

Constraints

1<=k10%

Sample Input

3

Sample Output

27

cpp code
2*/


#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    // Determine the starting number of the k-th group
    int startNum = 1;
    int previousGroupsSize = 0;

    // Calculate the sum of the sizes of all previous groups
    for (int i = 1; i < k; ++i) {
        previousGroupsSize += i;
    }

    // The first element of the k-th group
    startNum = 1 + 2 * previousGroupsSize;

    // Calculate the sum of the k-th group
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += startNum;
        startNum += 2;  // Move to the next odd number
    }

    cout << sum << endl;

    return 0;
}


//this gives soime test cases failed

3