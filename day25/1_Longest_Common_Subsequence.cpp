#include <bits/stdc++.h>
using namespace std;

// class solutionn
// {
// public:
//     int helper(int idx1, int idx2, string s1, string s2, vector<vector<int>> &dp)
//     {
//         if (idx1 < 0 || idx2 < 0)
//             return dp[idx1][idx2] = 0;
//         if (dp[idx1][idx2] != -1)
//             return dp[idx1][idx2];
//         if (s1[idx1] == s2[idx2])
//             return dp[idx1][idx2] = 1 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);
//         return dp[idx1][idx2] = max(helper(idx1 - 1, idx2, s1, s2, dp), helper(idx1, idx2 - 1, s1, s2, dp));
//     }
//     int lcs(string s1, string s2)
//     {
//         int n1 = s1.size() - 1, n2 = s2.size() - 1;
//         vector<vector<int>> dp(n1, vector<int>(n2, -1));
//         return helper(n1, n2, s1, s2, dp);
//     }
// };


int Lcs(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Code to reconstruct the LCS string
    string res = "";
    int i = n1, j = n2;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            res += s1[i - 1];
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(res.begin(), res.end());
    cout << "Length of subsequence is: " << dp[n1][n2] << endl;
    cout << "Longest common subsequence is: " << res << endl;

    return dp[n1][n2];
}

int main() {
    Lcs("abcde", "ace");
    return 0;
}