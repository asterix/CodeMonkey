#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* sum = new ListNode(0);
        ListNode* temp = sum;
        
        int carry = 0;
        
        while(l1 != nullptr || l2 != nullptr)
        {
            if(l1 != nullptr)
            {
               temp->val += l1->val;
               l1 = l1->next;
            }
            
            if(l2 != nullptr)
            {
                temp->val += l2->val;
                l2 = l2->next;
            }
            
            temp->val += carry;
            carry = temp->val / 10;
            temp->val = temp->val % 10;
            
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        
        temp->val = carry;
        return sum;
    }

};

void freeMemory(ListNode *s)
{
   while(s != nullptr)
   {
      ListNode *temp = s;
      s = s->next;
      delete temp;
   }
}

int main(int argc, char** argv)
{
   ListNode *a = new ListNode(9), *b = new ListNode(8);

   a->next = new ListNode(7); b->next = new ListNode(6);
   a->next->next = new ListNode(8); b->next->next = new ListNode(3);

   Solution s;

   ListNode *c = s.addTwoNumbers(a, b);

   while(c != nullptr)
   {
      cout << c->val << " ";
      c = c->next;
   }

   freeMemory(a);
   freeMemory(b);
   freeMemory(c);
   
   return 0;
}



