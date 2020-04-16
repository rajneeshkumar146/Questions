#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    std::ios::sync_with_stdio(false);
    int total = 0;
    int n(gas.size()), start(0), backupPetrol(0);

    for (int i = 0; i < n; i++)
    {
        backupPetrol += gas[i] - cost[i];
        if (backupPetrol < 0)
        {
            total += backupPetrol;
            start = i + 1;
            backupPetrol = 0;
        }
    }

    return (start == n || total + backupPetrol < 0) ? -1 : start;
}