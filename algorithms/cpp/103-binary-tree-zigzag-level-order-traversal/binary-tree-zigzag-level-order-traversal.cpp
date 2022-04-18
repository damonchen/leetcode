#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void print(TreeNode *head) {
  TreeNode *p = head;
  while (p) {
    cout << p->val << " ";
    p = p->left;
  }
  cout << endl;
}

void freeList(TreeNode *head) {
  TreeNode *p = head;
  while (p) {
    TreeNode *temp = p->left;
    delete p;
    p = temp;
  }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> r ;
		if(root == nullptr) {
			return r;
		}

		if(root->left == nullptr && root->right == nullptr) {
			vector<int> i = {root->val};
			r.push_back(i);
			return r;
		}

		// 按层级遍历，用一个队列来辅助
		// TreeNode *node = root;
		queue<TreeNode*> zig;
		queue<TreeNode*> zag;
		zig.push(root);

		bool process = false;
		while(true) {
			vector<int> children;

			if(!process) {
				while(!zig.empty()) {
					TreeNode *item = zig.front();
					zig.pop();

					cout << "zig item " << item->val << endl;
					children.push_back(item->val);

					if(item->left != nullptr) {
						zag.push(item->left);
					}
					if(item->right != nullptr) {
						zag.push(item->right);
					}
					process = true;
				}
			}

			if(!process) {
				stack<int> v;
				while(!zag.empty()) {
					TreeNode *item = zag.front();
					zag.pop();

					cout << "zag item " << item->val << endl;
					// children.push_back(item->val);
					v.push(item->val);

					if(item->left != nullptr) {
						zig.push(item->left);
					}

					if(item->right != nullptr) {
						zig.push(item->right);
					}

					process = true;
				}

				while(!v.empty()) {
					children.push_back(v.top());
					v.pop();
				}
			}

			process = false;

			// cout << "r pushback" << endl;
			r.push_back(children);

			if(zig.empty() && zag.empty()) {
				break;
			}

		}

		return r;
	}
};

int main() {
  Solution s;

  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	// TreeNode *root = nullptr;
	// TreeNode *root = new TreeNode(3);
	// TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, nullptr, new TreeNode(5)));
  vector<vector<int>> r = s.zigzagLevelOrder(root);
	cout << "r size " << r.size() << endl;
	for(int i=0; i<r.size(); i++) {
		vector<int> item = r[i];
		for(int j=0; j<item.size(); j++) {
			cout << item[j] << " ";
		}
		cout << endl;
	}
}
