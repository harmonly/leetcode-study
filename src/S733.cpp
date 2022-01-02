#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int x, int y, int color, int newColor)
    {
        if (x >= image.size() || x < 0 || y >= image[0].size() || y < 0)
            return;
        if (image[x][y] == color)
        {
            image[x][y] = newColor;
            dfs(image, x - 1, y, color, newColor);
            dfs(image, x, y - 1, color, newColor);
            dfs(image, x + 1, y, color, newColor);
            dfs(image, x, y + 1, color, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int currColor = image[sr][sc];
        if (currColor != newColor)
            dfs(image, sr, sc, currColor, newColor);
        return image;
    }
};

int main()
{
    vector<vector<int>> image = {{0, 0, 0}, {0, 1, 1}};
    int sr = 1, sc = 1, newColor = 1;
    image = Solution().floodFill(image, sr, sc, newColor);
    return 0;
}