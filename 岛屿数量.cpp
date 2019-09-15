/*
 * 本题的意思是连在一起的陆地都算做一个岛屿，本题可以采用类似渲染的做法，尝试以每个点作为渲染的起点，可以渲染
 * 的陆地都算做一个岛屿，最后看渲染了多少次，即深度优先算法执行了多少次
 * */
int nextPosition[4][2] = { { 0, 1  }, { 1, 0  }, { 0, -1  }, { -1, 0  }  };
class Solution {
    public:
        void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& book, 
                int x, int y)
        {
            //处理当前逻辑
            book[x][y] = 1;
            //遍历每一种可能，四个方向
            for (int k = 0; k < 4; ++k)
            {
                int nX = x + nextPosition[k][0];
                int nY = y + nextPosition[k][1];
                //判断新位置是否越界
                if (nX >= row || nX < 0 || nY >= col || nY < 0)
                    continue;
                //如果符合要求，并且之前也没有渲染过，则继续渲染
                if (grid[nX][nY] == '1' && book[nX][nY] == 0)
                {
                    dfs(grid, row, col, book, nX, nY);
                }
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            if (grid.empty())
                return 0;
            int ret = 0;
            int row = grid.size();
            int col = grid[0].size();
            vector<vector<int>> book;
            book.resize(row);
            for (int i = 0; i < row; ++i)
                book[i].resize(col, 0);
            //以每一个网格点为渲染起点开始
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    if (grid[i][j] == '1' && book[i][j] == 0)
                    {
                        ++ret;
                        dfs(grid, row, col, book, i, j);
                    }
                }
            }
            return ret;
        }
};
