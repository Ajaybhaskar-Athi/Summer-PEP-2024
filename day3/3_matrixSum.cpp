#include <iostream>
#include <vector>

using namespace std;

// Function to compute the space-optimized prefix sum matrix
vector<vector<int>> matrixSum(vector<vector<int>>& v, int n, int m) {
    // Calculate prefix sums for the first column
    for (int i = 1; i < n; i++) {
        v[i][0] += v[i - 1][0];
    }

    // Calculate prefix sums for the first row
    for (int i = 1; i < m; i++) {
        v[0][i] += v[0][i - 1];
    }

    // Calculate prefix sums for the rest of the matrix
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }

    return v;
}

// Function to get the sum of the submatrix using the prefix sum matrix
int getSubmatrixSum(const vector<vector<int>>& v, int x, int y) {
    return v[x - 1][y - 1];
}

int main() {
    vector<vector<int>> v = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int x = 2, y = 2;

    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> prefixSum = matrixSum(v, n, m);

    // Print the prefix sum matrix for verification
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << prefixSum[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The sum of matrix " << x << "X" << y << " is " << getSubmatrixSum(prefixSum, x, y) << endl;

    return 0;
}






//with extra space



/// 333  given a matrix , xand y values . find sum of all eelemts of x X y sub matrix in given whole matrix (prefix sum)

/*int main()
{
    vector<vector<int>> v = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int x = 2, y = 2;

    int n = v.size(), m = v[0].size(); // n= rows,m=cols;
    vector<vector<int>> prefixSum(n, vector<int>(m, 0));

    prefixSum[0][0] = v[0][0];
    for (int i = 1; i < m; i++)
    {
        prefixSum[0][i] = prefixSum[0][i - 1] + v[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        prefixSum[i][0] = prefixSum[i - 1][0] + v[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            prefixSum[i][j] = prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1] + v[i][j];
        }
    }
//printing prefix sum matrix for clarification
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << prefixSum[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The sum of matrix " << x << "X" << y << " is " << prefixSum[x - 1][y - 1] << endl;
}
*/