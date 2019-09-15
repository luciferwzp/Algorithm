/*
 * 本题的意思被包围的区间不会存在于边界上，所以边界上的o以及与o联通的都不算做包围，只要把边界上的o以及与之联
 * 通的o进行特殊处理，剩下的o替换成x即可。故问题转化为，如何寻找和边界联通的o，我们需要考虑如下情况。
 * X X X X
 * X O O X
 * X X O X
 * X O O X
 * 从每一个边缘的o开始，只要和边缘的o联通，则它就没有被包围。
 * 1.首先寻找边上的每一个o，如果没有，表示所有的o都被包围
 * 2.对于边上的每一个o进行dfs进行扩散，先把边上的每一个o用特殊符号标记，比如*，#等，
 * 比特科技
 * 3.把和它相邻的o都替换为特殊符号，每一个新的位置都做相同的dfs操作
 * 4.所有扩散结束之后，把特殊符号的位置（和边界连通）还原为o,原来为o的位置（和边界不连通）替换为x即可。
 * 这里一定要注意这里是大'O'和大'X'
 * */
int nextPosition[4][2] = { { 0, 1  }, { 1, 0  }, { 0, -1  }, { -1, 0  }  };
class Solution {
    public:
        void dfs(vector<vector<char>>& board, int row, int col, int i, int j)
        {
                   //当前位置设为'*'
                board[i][j] = '*';
            for (int k = 0; k < 4; ++k)
            {
                           //向四个方向扩散
                    int ni = i + nextPosition[k][0];
                int nj = j + nextPosition[k][1];
                           //判断边界
                    if (ni < 0 || ni >= row
                            || nj < 0 || nj >= col)
                        continue;
                           //是'O'说明和边联通，继续搜索是否还有联通的
                    if (board[ni][nj] != '*' && board[ni][nj] != 'X')
                        dfs(board, row, col, ni, nj);

            }

        }
        void solve(vector<vector<char>>& board) {
            if (board.empty())
                return;
            寻找边上的每一个0，如果没有，
                //表示所有的0都被包围
                int row = board.size();
            int col = board[0].size();
            //寻找第一行和最后一行
            for (int j = 0; j < col; ++j)
            {
                if (board[0][j] == 'O')
                    dfs(board, row, col, 0, j);
                if (board[row - 1][j] == 'O')
                    dfs(board, row, col, row - 1, j);
            }
            //寻找第一列和最后一列
            for (int i = 0; i < row; ++i)
            {
                if (board[i][0] == 'O')
                    dfs(board, row, col, i, 0);
                if (board[i][col - 1] == 'O')
                    dfs(board, row, col, i, col - 1);
            }
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    if (board[i][j] == '*')
                        board[i][j] = 'O';
                    else if (board[i][j] == 'O')
                        board[i][j] = 'X';
                }
            }
        }
};

