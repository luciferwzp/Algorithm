/*
 * 深度优先不适合解此题，递归深度太大，会导致栈溢出
 * 本题的密码为4位密码，每位密码可以通过拨动一次进行改变，注意这里的数的回环以及拨动的方向
 * 拨动方向：向前，向后
 * 回环：如果当前是9，0时，向前，向后拨动需要变成最小最大，而不是简单的自加自减
 * */
class Solution {
    public:
        int openLock(vector<string>& deadends, string target) {
            // 哈希表的查找更快
            unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
            //如果"0000"在死亡字符串中，则永远到达不了
            if(deadendsSet.find("0000") != deadendsSet.end())
                return -1;
            //初始化队列
            queue<string> que;
            que.push("0000");
            //加标记，已经搜索过的字符串不需要再次搜索
            unordered_set<string> book;
            book.insert("0000");
            int step = 0;
            while (!que.empty()) {
                int n = que.size();
                //从上一步转换之后的字符串都需要进行验证和转换
                //并且只算做一次转换，类似于层序遍历，转换的步数和层相同
                //同一层的元素都是经过一步转换得到的
                for (int i = 0; i < n; i++) {
                    string curStr = que.front();
                    que.pop();
                    if (curStr == target) return step;
                    //四位密码锁，每个位置每次都可以转一次
                    for (int j = 0; j < 4; j++) {
                        string newStr1 = curStr, newStr2 = curStr;
                        //当前位置可以向前或者向后拨一位
                        newStr1[j] = newStr1[j] == '9' ? '0' : newStr1[j] + 1;
                        newStr2[j] = newStr2[j] == '0' ? '9' : newStr2[j] - 1;
                        if (deadendsSet.find(newStr1) == deadendsSet.end() 
                                                       && book.find(newStr1) == book.end()) {
                            que.push(newStr1);
                            book.insert(newStr1);
                        }
                        if (deadendsSet.find(newStr2) == deadendsSet.end() 
                                                       && book.find(newStr2) == book.end()) {
                            que.push(newStr2);
                            book.insert(newStr2);
                        }
                    }
                }
                step++;
            }
            return -1;
        }
};
