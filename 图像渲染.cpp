/*
 * 把和初始坐标开始，颜色值相同的点的颜色全部改为新的颜色
 * 并且只要某个点颜色被更改，则继续以此点向周围渲染
 * 比如题目的意思: 以位置（1，1）开始，向外渲染，只要渲染点的颜色值和（1，1）位置的颜色值相同，则继续向
 * 外渲染
 * 1 1 1
 * 1 1 0
 * 1 0 1
 * 2 2 2
 * 2 2 0
 * 2 0 1
 * 这里每一个符合要求的点都要向四个方向渲染
 * 边界：位置是否越界
 * 这里需要用的标记，避免重复修改，使时间复杂度不超过O(row * col)
 * */

#include <vector>
#include <iostream>
using namespace std;
//四个方向的位置更新：顺时针更新
int nextPosition[4][2] = { { 0, 1  }, { 1, 0  }, { 0, -1  }, { -1, 0  }  };
class Solution {
    public:
        void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& book, 
                int sr, int sc, int oldColor, int newColor)
        {
            //处理当前逻辑，修改颜色，并且标记已经修改过了
            image[sr][sc] = newColor;
            book[sr][sc] = 1;
            //遍历每一种可能，四个方向
            for (int k = 0; k < 4; ++k)
            {
                int newSr = sr + nextPosition[k][0];
                int newSc = sc + nextPosition[k][1];
                //判断新位置是否越界
                if (newSr >= row || newSr < 0 || newSc >= col || newSc < 0)
                    continue;
                //如果颜色符合要求，并且之前也没有渲染过，则继续渲染
                if (image[newSr][newSc] == oldColor && book[newSr][newSc] == 0)
                {
                    dfs(image, row, col, book, newSr, newSc, oldColor, newColor);
                }
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int
                newColor) {
            if (image.empty())
                return image;
            int row = image.size();
            int col = image[0].size();
            //建立标记
            vector<vector<int>> book;
            book.resize(row);
            for (int i = 0; i < row; ++i)
            {
                book[i].resize(col, 0);
            }
            //获取旧的颜色
            int oldColor = image[sr][sc];
            dfs(image, row, col, book, sr, sc, oldColor, newColor);
            return image;
        }
};

