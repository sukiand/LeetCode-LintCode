#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct value{
	int num;
	vector<string> original;
};

vector<string> anagrams(vector<string> &strs){
	unordered_map <string, value> record;
	for (auto i = 0; i < strs.size(); i++){
		value tmp;
		tmp.num = 0;
		tmp.original.push_back(strs[i]);
		sort(strs[i].begin(), strs[i].end());
		auto got = record.find(strs[i]);
		if (got == record.end()){
			record[strs[i]] = tmp;
		}
		else{
			got->second.num++;
			got->second.original.push_back(tmp.original[0]);
		}
	}
	vector<string> result;
	for (auto i = record.begin(); i != record.end(); i++){
		if (i->second.num){
			result.reserve(result.size()+ i->second.original.size());
			result.insert(result.end(), i->second.original.begin(), i->second.original.end());
		}
	}
	return result;
}

int main(int argc, char **argv){
	vector<string> k;
	k.push_back("lint"); 
	k.push_back("intl");
	k.push_back("inlt");
	k.push_back("code");
	k = anagrams(k);
	for (int i = 0; i < k.size(); i++){
		cout << k[i].c_str()<<endl;
	}
	getchar();
}