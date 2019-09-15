class Solution {
    public:
           void dfs(vector<int>& candidates, vector<vector<int>>& solutions,
                            vector<int>& solution, int curSum, 
                            int prevPosition, int target)
              {
                  //边界，如果大于等于目标，则结束
                  if(curSum >= target)
                  {
                      //等于目标，找到一个组合
                      if(curSum == target)
                        solutions.push_back(solution);
                        return;     
                    }
                  //可以从上一个位置开始，因为元素可以重复
                  for(int i = prevPosition; i < candidates.size(); ++i)
                  {
                      //单个值已经大于目标，直接跳过
                      if(candidates[i] > target)
                         continue;
         
                      solution.push_back(candidates[i]);
                      dfs(candidates, solutions, solution, curSum + candidates[i], i, target);
                      //回溯，向上回退
                      solution.pop_back();        
                    }
            }
           vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                   vector<vector<int>> solutions;
                   vector<int> solution;
                   if(candidates.empty())
                           return solutions;
                   int curSum = 0;
                   dfs(candidates, solutions, solution, curSum, 0, target);
                   return solutions;
        }
};
