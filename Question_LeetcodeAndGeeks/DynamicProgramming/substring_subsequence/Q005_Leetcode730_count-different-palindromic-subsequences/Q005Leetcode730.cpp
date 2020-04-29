#include <iostream>
#include <vector>
#include <climits>

#define vi vector<int>
#define vii vector<vi>
using namespace std;


  public int countPalindromicSubsequences(String s) {
        int n = s.length();
        int[] rightNext = rightNext(s, new int[] {n, n, n, n});
        int[] leftNext = leftNext(s, new int[] {-1, -1, -1, -1});
        int[][] dp = new int[n][n];
        for (int d = 0; d < n; d++) {
            for (int i = 0, j = i+d; j < n; i++, j++) {
                if (i == j) dp[i][j] = 1;
                else if (s.charAt(i) != s.charAt(j)) dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                else {
                    int r = rightNext[i], l = leftNext[j];
                    int extra = (r < l) ? - dp[r+1][l-1] : (r == l) ? 1 : 2;
                    dp[i][j] = 2*dp[i+1][j-1] + extra;
                }
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + 1000000007 : dp[i][j] % 1000000007;
            }
        }
        return dp[0][n - 1];
    }
	private int[] leftNext(String s, int[] rec) {
        int n = s.length(), res[] = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = rec[s.charAt(i) - 'a'];
            rec[s.charAt(i) - 'a'] = i;
        }
        return res;
    }
    private int[] rightNext(String s, int[] rec) {
        int n = s.length(), res[] = new int[n];
        for (int i = n-1; i >= 0; i--) {
            res[i] = rec[s.charAt(i) - 'a'];
            rec[s.charAt(i) - 'a'] = i;
        }
        return res;
    }