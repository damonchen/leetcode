#include <iostream>
#include <vector>
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
  while(p) {
    cout << p->val  << " ";
    p = p->next;
  }
  cout << endl;
}

void freeList(ListNode *head) {
  ListNode *p = head;
  while(p) {
    ListNode *temp = p->next;
    delete p;
    p = temp;
  }
}


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.empty()) {
        return nullptr;
      }

      // 缓存每条链的头部
      int size = lists.size();
      ListNode* *pointers = new ListNode*[size];
      int i = 0;
      for(vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); it++) {
        // print(*it);
        pointers[i++] = *it;
      }

      ListNode merge;
      ListNode *m = &merge;
      while(true) {
        // 找出最小值的那个链
        int index = 0;
        ListNode* mh = nullptr;

        for(int i=0; i<size; i++) {
          ListNode *h = pointers[i];
          if(h != nullptr) {
            mh = h;
            index = i;
          }
        }

        // 所有的链路都走完了
        if(mh == nullptr) {
          break;
        }

        for(int i=0; i<size; i++) {
            ListNode* h = pointers[i];
            if(h == nullptr) {
              continue;
            }

            if(mh->val > h->val) {
              mh = h;
              index = i;
            }
        }

        // 插入最小值的内容到merge链中
        m->next = mh;
        m = mh;

        // 最小值的那个链往前走一步
        pointers[index] = mh->next;
      }
      delete[] pointers;

      ListNode *r = merge.next;

      return r;
    }
};


int main() {
  Solution s = Solution();
  ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
  ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
  ListNode *l3 = new ListNode(2, new ListNode(6));
  vector<ListNode*> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);
  ListNode *m = s.mergeKLists(lists);
  print(m);

  freeList(l1);
  freeList(l2);
  freeList(l3);
}