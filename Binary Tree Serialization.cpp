#include <iostream>
#include <vector>
#include <string>

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

/**
* This method will be invoked first, you should design your own algorithm
* to serialize a binary tree which denote by a root node to a string which
* can be easily deserialized by your own "deserialize" method later.
*/
string serialize(TreeNode *root) {
	// write your code here
	vector<TreeNode *> store(2, nullptr);
	store[1] = root;
	string result;
	for (int i = 1; i<store.size(); i++){
		if (store[i] == nullptr) continue;
		if (2 * i + 1 > store.size()){
			store.resize(2 * i + 2, nullptr);
		}
		store[2 * i] = store[i]->left;
		store[2 * i + 1] = store[i]->right;
	}

	for (int i = 1; i<store.size(); i++){
		string k;
		if (store[i] == nullptr){
			k = "#";
		}
		else{
			k = to_string(store[i]->val);
		}
		result += (k + ",");
	}
	result.resize(result.size() - 1);
	if (result.size() < 4) return result;
	int num = 0;
	reverse(result.begin(), result.end());
	while (result[num] == '#'){
		num += 2;
	}
	result = result.substr(num);
	reverse(result.begin(), result.end());
	return result;
}


TreeNode *myDe(vector<string> result, int pos){
	if (pos >= result.size() || result[pos] == "#"){
		return nullptr;
	}
	TreeNode *node = new TreeNode(stoi(result[pos]));
	node->left = myDe(result, pos * 2);
	node->right = myDe(result, pos * 2 + 1);
	return node;
}
/**
* This method will be invoked second, the argument data is what exactly
* you serialized at method "serialize", that means the data is not given by
* system, it's given by your own serialize method. So the format of data is
* designed by yourself, and deserialize it here as you serialize it in
* "serialize" method.
*/
TreeNode *deserialize(string data) {
	// write your code here
	vector<string> result(1, "#");
	string mark = ",";
	while (1){
		size_t pos = data.find(mark);
		if (pos == string::npos){
			result.push_back(data);
			break;
		}
		result.push_back(data.substr(0, pos));
		data = data.substr(pos+1);
	}
	for (int j = 1; j < result.size(); j++){
		cout << result[j] << " ";
	}
	cout << endl;
	int i = 1;
	return myDe(result, 1);
}

void main(){
	TreeNode *node[15];
	for (int i = 1; i < 15; i++){
		node[i] = new TreeNode(i);
	}
	node[1]->left = node[2];
	node[1]->right = node[3];
	node[2]->left = node[11];
	node[3]->left = node[4];
	node[3]->right = node[5];
	node[4]->left = node[6];
	node[4]->right = node[7];
	node[5]->right = node[10];
	node[7]->left = node[8];
	node[7]->right = node[9];
	node[8]->left = node[12];
	node[8]->right = node[13];
	node[13]->right = node[14];
	string r = serialize(node[1]);
	cout << r << endl;
	deserialize(r);
	getchar();
}