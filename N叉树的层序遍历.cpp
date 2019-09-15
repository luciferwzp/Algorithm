//广度搜索

class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>> treeVec;
            if (root == nullptr) 
                return treeVec;
            //临时存放每一层的元素
            vector<int> newFloor;
            queue<Node*> q; q.push(root);
            while (q.size()){
                //获取当前层元素个数，即整个队列元素
                int size = q.size();
                //存放新层元素之前先清空
                newFloor.clear();
                while (size--){
                    auto node = q.front();
                    q.pop();
                    newFloor.push_back(node->val);
                    //孩子入队
                    for (auto& child : node->children){
                        if (child) 
                            q.push(child);
                    }
                }
                //新层有元素,则放入vector
                if (!newFloor.empty()) 
                    treeVec.push_back(newFloor);
            }
            return treeVec;
        }
};

