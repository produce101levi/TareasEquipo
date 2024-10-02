#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonSubstring(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    int maxLength = 0;  // Length of longest common substring
    int endIndex = 0;   // End index of the longest common substring in X

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    // Extract the longest common substring
    if (maxLength == 0) {
        return "";
    }
    return X.substr(endIndex - maxLength + 1, maxLength);
}

int main() {
    string X = "Hello World!";
    string Y = "I just came to say 'Hello'";

    string result = longestCommonSubstring(X, Y);
    cout << "Longest Common Substring: " << result << endl;

    return 0;
}
