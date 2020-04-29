#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(numCourses, 0);
    for (vector<int> &arr : prerequisites)
        indegree[arr[1]]++;

    queue<int> que;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0)
            que.push(i);
    
    int count = 0;
    while (que.size() != 0)
    {
        int v = que.top(); que.pop();
        count++;

        
    }
}

void solve()
{
}
int main()
{
    solve();
    return 0;
}
