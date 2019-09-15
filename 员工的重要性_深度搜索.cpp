/*
 * 边界: 下属为空
 * 每次先加第一个下属的重要性
 * 按照相同的操作再去加下属的第一个下属的重要性
 * */
class Solution {
    public:
           void dfs(unordered_map<int, Employee*>& info, int& sum, int id)
              {
                       //这里无需判断边界，for循环就是一个边界，下属为空，直接结束
                       sum += info[id]->importance;
                       for(const auto& subid : info[id]->subordinates)
                          {
                                   dfs(info, sum, sub); 
                    }      
            }
           int getImportance(vector<Employee*> employees, int id) {
                   if(employees.empty())
                           return 0;
                   unordered_map<int, Employee*> info;
                   //把员工信息用map存储，方便后面的使用
                   for(const auto& e : employees)
                       info[e->id] = e;
                   
                int sum = 0;
                dfs(info, sum, id);
                return sum;
              
        }

};
class Solution {
    public:
           int DFS(unordered_map<int,Employee*>& info, int id)
              {
                       int curImpo = info[id]->importance;
                       for(const auto& sid : info[id]->subordinates)
                          {
                                   curImpo += DFS(info, sid);
                              
                    }
                       return curImpo;
                  
            }
           int getImportance(vector<Employee*> employees, int id) {
                   if(employees.empty())
                           return 0;
                   unordered_map<int,Employee*> info;
                   for(const auto& e : employees)
                      {
                               info[e->id] = e;
                }
                   return DFS(info, id);     
        }
};
