//假设有一个迷宫，里面有障碍物，迷宫用二维矩阵表示，标记为0的地方表示可以通过，标记为1的地方表示障碍物，不能通过。
//现在给一个迷宫出口，让你判断是否可以从入口进来之后，走出迷宫，每次可以向任意方向走。
//假设是一个10*10的迷宫，入口在(1,1)的位置，出口在(8,10)的位置，通过(1,1)一步可以走到的位置有两个(1,2)，(2,1)
//但是这两个点并不是出口，需要继续通过这两个位置进一步搜索，假设现在在(1,2),下一次一步可以到达的新的位置为(1,3)，(2,2)。
//而通过（2，1）可以一步到达的新的位置为（2，2），（3，1），但是这里（2，2）是重复的，
//所以每一个点在走的过程中需要标记是否已经走过了。
//两步之后，还没没有走到出口，这时候需要通过新加入的点再去探索下一步能走到哪些新的点上，重复这个过程，直到走到出口为止。
//代码解析这个过程，最关键的步骤用当前位置带出新的位置，新的位置可以存放在一个vector或者队列中。
//位置需要用坐标表示，这里封装出一个node。


struct node
{
    int x;
    比特科技
        int y;

};
//queue实现
bool Bfs(vector<vector<int>> graph, int startx, int starty, int destx, int desty) {
    //迷宫的大小
    int m = graph.size();
    int n = graph[0].size();
    //存储迷宫中的位置
    queue<node> q;
    //标记迷宫中的位置是否被走过
    vector<vector<int>> book;
    book.resize(m);
    for (size_t i = 0; i < m; i++)
        book[i].resize(n, 0);
    q.push(node(startx, starty));
    //标记已经走过
    book[startx][starty] = 1;
    //四个行走的方向，上下左右
    int next[4][2] = { { -1, 0  }, { 1, 0  }, { 0, -1  }, { 0, 1  }  };
    //标记是否可以出去
    bool flag = false;
    while (!q.empty())
    {
        //当前位置带出所有新的位置, 可以向上下左右走
        for (size_t i = 0; i < 4; ++i)
        {
            //计算新的位置
            int nx = q.front()._x + next[i][0];
            int ny = q.front()._y + next[i][1];
            //新的位置越界，继续下一个
            if (nx >= m || nx < 0 || ny >= n || ny < 0)
            {
                continue;
            }
            //如果新的位置无障碍并且之前也没走过，保存新的位置
            if (graph[nx][ny] == 0 && book[nx][ny] == 0)
            {
                q.push(node(nx, ny));
                //标记已被走过
                book[nx][ny] = 1;
            }
            //如果新的位置为目标位置,则结束查找
            if (nx == destx && ny == desty)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        //否则，用新的位置继续向后走
        q.pop();
    } 
    return flag; 
}

//vector实现
bool Bfs(vector<vector<int>> graph, int startx, int starty,int destx, int desty) {
       //迷宫的大小
       int m = graph.size();
       int n = graph[0].size();
       
      //存储迷宫中的位置
       vector<node> queue;
       queue.resize(m*n);
       
           
       //标记迷宫中的位置是否被走过
       vector<vector<int>> book;
       book.resize(m);
       for(size_t i = 0; i < m; i++)
               book[i].resize(n, 0);
       
       int head = 0;
       int tail = 1;
       queue[head].x = startx;
       queue[head].y = starty;
       //标记已经走过
       book[startx][starty] = 1;
       //四个行走的方向，上下左右
       int next[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
       //标记是否可以出去
       bool flag = false;
       
       while(head < tail)
          {
                   //当前位置带出所有新的位置, 可以向上下左右走
                       for(size_t i = 0; i < 4; ++i)
                      {
                               //计算新的位置
                               int nx = queue[head].x + next[i][0];
                               int ny = queue[head].y + next[i][1];
                               //新的位置越界，继续下一个
                               if(nx >= m || nx < 0 || ny >= n || ny < 0)
                                {
                                      continue;
                                }
                               //如果新的位置无障碍并且之前也没走过，保存新的位置
                                   if(graph[nx][ny] == 0 && book[nx][ny] == 0)
                                   {                                   
                                           queue[tail].x = nx;                                             
                                           queue[tail].y = ny;
                                           //标记已被走过
                                           book[nx][ny] = 1;
                                           ++tail;
                                   }
                               //如果新的位置为目标位置,则结束查找
                                   if(nx == destx && ny == desty)
                                   {
                                           flag = true;
                                           break;
                                   }
                          }
                   if(flag)
                           break;
                   //否则，用新的位置继续向后走
                   ++head;
              }
       return flag;
}

int main()
{
    int sx, sy, ex, ey;
    vector<vector<int>> graph;
    int m, n;
    cout << "请输入迷宫的大小: 行，列" << endl;
    cin >> m >> n;
    graph.resize(m);
    for (size_t i = 0; i < m; ++i)
    {
        graph[i].resize(n);
    }
    cout << "请输入迷宫的元素" << endl;
    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }
    while (1)
    {
        cout << "请输入迷宫入口和出口" << endl;
        cin >> sx >> sy >> ex >> ey;
        cout << "是否可以走出迷宫： " << Bfs(graph, sx, sy, ex, ey) << endl;

    }
    return 0; 
}
