/*
合并k个有序链表
多路归并的思路
*/
# include<bits/stdc++.h>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int main()
{

}
// 使用遍历寻找每一轮最小值
ListNode* mergeKLists1(vector<ListNode*>& lists)
{
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    bool allempty = false;
    int len = lists.size();
    if(len == 0) return head->next;
    while(1)
    {
        int maxx = INT_MAX;
        int pos = -1;
        allempty = true;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL && lists[i]->val<maxx)
            {
                    maxx = lists[i]->val;
                    pos = i;
                    allempty = false;
            }
        }
        if(!allempty)
        {
            lists[pos] = lists[pos]->next;
            temp = temp->next = new ListNode(maxx);
        }
        else
        {
            break;
        }
    }
    return head->next;
}

// 使用最小堆 优先队列
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode *head, *tail = head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head->next;
    }
};