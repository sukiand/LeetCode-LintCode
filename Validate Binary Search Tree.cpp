#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode {
	public:
		int val;
		TreeNode *left, *right;
		TreeNode(int val) {
			this->val = val;
			this->left = this->right = NULL;
			
		}
};

vector<int> traversal(TreeNode *root){
	stack<TreeNode *> store;
	vector<int> result;
	TreeNode *p = root;

	while (p != nullptr || (!store.empty())){
		
		if (p == nullptr){
			p = store.top();
			store.pop();
			result.push_back(p->val);
			p = p->right;
			continue;
		}
		if (p->left == nullptr){
			result.push_back(p->val);
			p = p->right;
			continue;
		}
		else{
			store.push(p);
			p = p->left;
			continue;
		}
	}
	return result;
}

bool isValidBST(TreeNode *root) {
	// write your code here
	vector<int> result = traversal(root);
	cout << result.size() << endl;
	if (result.size() < 2) {
		return true;
	}
	for (int i = 1; i < result.size(); i++){
		if (result[i - 1] >= result[i]){
			return false;
		}
	}
	return true;
}

void main(){
	TreeNode *root = new TreeNode(1);
	TreeNode *p = new TreeNode(2);
	root->right = p;
	p->left = new TreeNode(3);
	cout <<isValidBST(root);
	getchar();
}