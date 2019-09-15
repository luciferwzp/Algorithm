class Solution {
    public:
           int getImportance(vector<Employee*> employees, int id) {
                   int res = 0;
                   queue<int> q;
                   //初始化队列
                   q.push(id);
                   //把员工信息保存在map中，方便查询
                   unordered_map<int, Employee*> m;
                   for (auto e : employees) 
                           m[e->id] = e;
                   //遍历队列
                       while (!q.empty()) {
                               int t = q.front(); 
                               q.pop();
                               res += m[t]->importance;
                               for (int num : m[t]->subordinates) {
                                       q.push(num);               
                    } 
                }
                   return res;                    
        }

};
