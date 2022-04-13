#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* middleNode(ListNode* head) {
      ListNode *p1 = head;
      ListNode *p2 = head;
      while(p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
      }

      return p1;
    }
};



void print(ListNode *head) {
  ListNode *p = head;
  while(p) {
    cout << p->val  << endl;
    p = p->next;
  }
}

void free(ListNode *head) {
  ListNode *p = head;
  while(p) {
    ListNode *temp = p->next;
    delete p;
    p = temp;
  }
}


int main() {
  Solution s = Solution();
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  // ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
  print(head);
  cout << s.middleNode(head)->val << endl;
  free(head);
}

