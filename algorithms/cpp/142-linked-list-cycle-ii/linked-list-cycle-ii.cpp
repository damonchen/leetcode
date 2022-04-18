#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void print(ListNode *head) {
  ListNode *p = head;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

void freeList(ListNode *head) {
  ListNode *p = head;
  while (p) {
    ListNode *temp = p->next;
    delete p;
    p = temp;
  }
}

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr) {
      return nullptr;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    while(true) {
      // 无环
      if(fast == nullptr || fast->next == nullptr) {
        return nullptr;
      }

      slow = slow->next;
      fast = fast->next->next;

      // 环中相遇了
      if(fast == slow) {
        break;
      }

    }

    slow = head;
    // 当相遇的时候，就是交点
    while(fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }

    return fast;
  }
};

int main() {
  Solution s = Solution();
  ListNode head = ListNode(3);
  ListNode two = ListNode(2);
  // ListNode zero = ListNode(0);
  // ListNode four = ListNode(4);
  head.next = &two;
  two.next = &head;
  // two.next = &zero;
  // zero.next = &four;
  // four.next = &two;
  // print(&head);
  ListNode *node =  s.detectCycle(&head);
  cout << node->val << endl;
  // free(head);
}
