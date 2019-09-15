/*
 * 此题DFS + 回溯
 * */
static string mapString[] = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"}; 
class Solution {
    public:
           void backTrace(string& digits, vector<string>& ret, string curStr, int curDepth)
              {
                       //边界，找到一种组合，放入数组中，结束此路径，向上回溯
                           if(curDepth == digits.size())
                          {
                                   if(!curStr.empty())
                                      {
                                               ret.push_back(curStr);
                            }
                                   return;                            
                    }
                       //找到当前字符在string映射表中的位置
                       int curMapIndex = digits[curDepth] - '0';
                       string curMap = mapString[curMapIndex];
                       //遍历每一种可能的组合
                       for(auto& ch : curMap)
                          {
                                   backTrace(digits, ret, curStr + ch, curDepth + 1);     
                          }
                }
           
               vector<string> letterCombinations(string digits) {
                       vector<string> ret;
                       backTrace(digits, ret, "", 0);
                       return ret;      
            }
};
