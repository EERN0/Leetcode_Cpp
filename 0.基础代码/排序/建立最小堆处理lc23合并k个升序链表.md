```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void upHeap(vector<ListNode *> &lists, int i){
        while(i > 0 && lists[(i-1)/2]->val > lists[i]->val)
        {
            swap(lists[(i-1)/2], lists[i]);
            i = (i-1)/2;
        }
    }

    void downHeap(vector<ListNode *> &lists, int i, int size){
        while(2*i+1 <= size)
        {
            int j = 2*i + 1;
            if(j+1 <= size && lists[j+1]->val < lists[j]->val) j++;
            if(lists[i]->val < lists[j]->val) break;
            swap(lists[i], lists[j]);
            i = j;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        vector<ListNode*> tmpList;

        // 判空
        for(int i = 0; i < lists.size(); ++i)
            if(lists[i] != nullptr) 
                tmpList.push_back(lists[i]);

        // 构造最小堆
        for(int i = 0; i < tmpList.size(); ++i)
            upHeap(tmpList, i);
        
        while(tmpList.size() > 0)
        {
            if(tmpList[0] == nullptr) return nullptr;
            ListNode *tmp = tmpList[0];
            p->next = tmp;
            p = p->next;
            if(tmp->next != nullptr)
            {
                tmpList.push_back(tmp->next);
            }
            swap(tmpList[0], tmpList[tmpList.size()-1]);
            tmpList.pop_back();
            downHeap(tmpList, 0, tmpList.size()-1);
        }
        return dummy->next;
    }
};
```