#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    bool isSafety(ListNode *tmp, int &k)
    {
        int i = 0;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            i++;
            if(i >= k) return true;
        }
        return i >= k;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *pre = NULL, *tail = head;
        if(k <= 1) return head;
        while (isSafety(tail, k))
        {
            ListNode *t_tail = tail->next,*t_tmp,*start = tail;
            for (int i = 0; i < k - 1; i++)
            {
                t_tmp = t_tail->next;
                t_tail->next = tail;
                tail = t_tail;
                t_tail = t_tmp;
            }
            start->next = t_tmp;
            if(pre == nullptr){
                head = tail;
            }else{
                pre->next = tail;
            }
            pre = start;
            tail = start->next;
        }
        return head;
    }
};
int main()
{
    Solution a;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, NULL)))), *tmp = head;
    ListNode *t = head->next->next, *tail = head;
    t = NULL;
    while (tail != NULL)
    {
        cout << tail->val << endl;
        tail = tail->next;
    }
    // cout<<head<<endl;
    // cout<<head<<endl;
    tail = a.reverseKGroup(head, 1);
    while (tail != NULL)
    {
        cout << tail->val << endl;
        tail = tail->next;
    }
    system("pause");
    return 0;
}