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

    ListNode* reverseLink(ListNode *head) {
      ListNode* last = nullptr;
      while(head != nullptr) {
        ListNode *temp = head->next;
        head->next = last;
        last = head;
        head = temp;
      }
      return last;
    }

    ListNode* findMiddle(ListNode *head) {
      ListNode *p1 = head;
      ListNode *p2 = head;

      while(p2  && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
      }
      return p1;
    }

    bool isPalindrome(ListNode *head) {

      // 统计个数
      ListNode* m = findMiddle(head);
      ListNode* t = reverseLink(m);
      ListNode* h = head;
      while(t != nullptr && h != nullptr) {
        if(h->val != t->val) {
          return false;
        }
        h = h->next;
        t = t->next;
      }
      return true;
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
  // ListNode *head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1, new ListNode(5)))));
  print(head);
  cout << s.isPalindrome(head) << endl;
  free(head);
}


