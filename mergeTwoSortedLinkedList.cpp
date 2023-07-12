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
class Solution
 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *headNewList= nullptr;
        ListNode *tailNewList=nullptr;
        if(!list1)
        {
            return list2; 
          
        }
        if(!list2)
        {
            return list1;
        }

        while(list1 && list2)
        {
            if(list1->val==list2->val)
            {
                if(!headNewList)
                {
                    headNewList= new ListNode(list1->val);
                    headNewList->next=new ListNode(list2->val);
                    tailNewList=headNewList->next;
                }
                else
                {
                    tailNewList->next= new ListNode(list1->val);
                    tailNewList->next->next=new ListNode(list2->val);
                    tailNewList=tailNewList->next->next;
                }
                list1=list1->next;
                list2=list2->next;
            }
            else if(list1->val<list2->val)
            {
                if(!headNewList)
                {
                    headNewList= new ListNode(list1->val);
                    tailNewList=headNewList;
                }
                else
                {
                    tailNewList->next=new ListNode(list1->val);
                    tailNewList=tailNewList->next;
                }
                list1=list1->next;
            }
            else if(list1->val>list2->val)
            {
                if(!headNewList)
                {
                    headNewList= new ListNode(list2->val);
                    tailNewList=headNewList;
                }
                else
                {
                    tailNewList->next=new ListNode(list2->val);
                    tailNewList=tailNewList->next;
                }
                list2=list2->next;
            }

        }
        if(list1)
        {
            while(list1)
            {
                if(!headNewList)
                {
                    headNewList= new ListNode(list1->val);
                    tailNewList=headNewList;
                }
                  else
                {
                    tailNewList->next= new ListNode(list1->val);;
                    tailNewList=tailNewList->next;
                }
                list1=list1->next;
            }
        }
        if(list2)
        {
            while(list2)
            {
                if(!headNewList)
                {
                    headNewList= new ListNode(list2->val);
                    tailNewList=headNewList;
                }
                else
                {
                    tailNewList->next=new ListNode(list2->val);
                    tailNewList=tailNewList->next;
                }
                list2=list2->next;
            }
        }
       return headNewList;
    }
};
