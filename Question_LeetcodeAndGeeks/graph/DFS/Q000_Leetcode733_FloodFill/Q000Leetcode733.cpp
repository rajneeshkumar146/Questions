// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void dfs(vector<vector<int>> &image, int sr, int sc, int oldColor, int newColor)
{

    image[sr][sc] = newColor;
    for (int d = 0; d < 4; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if (x >= 0 && y >= 0 && x < image.size() && y < image[0].size() && image[x][y] == oldColor)
            dfs(image, x, y, oldColor, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int oldColor = image[sr][sc];
    if (oldColor != newColor)
        dfs(image, sr, sc, oldColor, newColor);
    return image;
}