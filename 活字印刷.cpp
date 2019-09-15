/*
 * 此题组合的长度不唯一，最小组合长度为1， 最大组合长度为tiles的长度。
 * 按照题意tiles中每一个位置的字符在组合中只能出现一次， 所以可以用一个标记辅助
 * 当去组合新的组合时，可以与tiles中的每一个位置组合，但是如果当前位置已经在当前组合中出现过，则跳过
 * 虽然此题中每一个位置的字符在组合中只能出现一次，但是tiles中可能有相同的字符，所以需要考虑重复的组合
 * 而unordered_set可以天然去重，可以用其去重
 * DFS + 回溯：
 * 1.当前组合不为空, 则插入set中
 * 2.继续给当前组合拼接新的组合，尝试拼接tiles每一个位置的字符
 * 3.如果当前位置已在组合中出现过，返回到2，否则标记当前位置，继续拼接更长的组合
 * 4.回溯，尝试组合其它位置，返回2
 * 当所有位置都已经使用过时，当前递归就结束了，继续向上层DFS回退
 * 最终返回set的大小即为组合数目。
 * */
class Solution {
    public:
        void dfs(string& tiles, string curStr, vector<int>& usedIdx, unordered_set<string>&  totalString)
              {
                       if(!curStr.empty()) {
                                  totalString.insert(curStr);
                    }
                       //标记保证所有位都用完之后，就结束了
                       for(int i = 0; i < tiles.size(); ++i)
                         {
                               //当前位置的字符已用过，直接跳过
                               if(usedIdx[i])
                                  continue;
                                
                               usedIdx[i] = 1;
                               dfs(tiles, curStr + tiles[i], usedIdx, totalString);
                               //回溯，尝试其它字符
                               usedIdx[i] = 0;  
                    }       
            }
           int numTilePossibilities(string tiles) {
                   if(tiles.empty())
                           return 0;
                   unordered_set<string> totalString;
                   //标记全部初始化为未使用
                       vector<int> usedIdx(tiles.size(), 0);
                   dfs(tiles, "", usedIdx, totalString);
                   return totalString.size();
        }
};
