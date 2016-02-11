/*Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.*/

/*especially input:
1 unordered: [-3,75,3,0], 0
2 the same numbers: [0,7,-9,0], 0
3 very long: [1,2,3,4,5,.................]   ,a big number of the last two.\
4 ....
*/

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
	//improved, 21ms
	vector<int> twoSum(vector<int> &numbers, int target){
		unordered_map<int, int> valueHash;
		unordered_map<int, int>::iterator got;
		vector<int>::size_type index1;
		vector<int> return_value(2);

		//do not insert the same value as key again. 1 check the sum 2 not insert
		//find if have the value of  (target - inserting)
		for (index1 = 0; index1 < numbers.size(); index1++){
			got = valueHash.find(numbers[index1]);
			if (got == valueHash.end()){
				//not find the same num
				got = valueHash.find(target - numbers[index1]);
					if (got != valueHash.end()){
						return_value[0] = got->second + 1;
						return_value[1] = index1 + 1;
						return return_value;
					}
				valueHash.insert({ numbers[index1], index1 }); //method 1
				//valueHash.insert(make_pair(numbers[index1], index1));//method 2
				//pair<int, int> insertPair(numbers[index1], index1);/* method 3
				//valueHash.insert(insertPair);							method 3 */
			}
			else{
				//find the same value, examine if the sum equal to the target
				if (numbers[index1] + numbers[index1] == target){
					return_value[0] = got->second + 1;
					return_value[1] = index1 + 1;
					return return_value;
				}
				continue;
			}

		}
		// insert completed
		
	}


	//brilliant algorithm, use a hash to store. and to find the target-numbers[index1]. cost O(n), 30ms.
	vector<int> twoSum_30ms(vector<int> &numbers, int target){
		unordered_map<int, int> valueHash;
		unordered_map<int, int>::iterator got;
		vector<int>::size_type index1;
		vector<int> return_value(2);

		for (index1 = 0; index1 < numbers.size(); index1++){
			got = valueHash.find(numbers[index1]);
			if (got == valueHash.end()){
				//not find the same num
				valueHash.insert({ numbers[index1], index1 }); //method 1
				//valueHash.insert(make_pair(numbers[index1], index1));//method 2
				//pair<int, int> insertPair(numbers[index1], index1);/* method 3
				//valueHash.insert(insertPair);							method 3 */
			}
			else{
				//find the same value, examine if the sum equal to the target
				if (numbers[index1] + numbers[index1] == target){
					return_value[0] = got->second + 1;
					return_value[1] = index1 + 1;
					return return_value;
				}
			
			}
			
		}
		// insert completed
		for (index1 = 0; index1 < numbers.size(); index1++){
			got = valueHash.find(numbers[index1]);
			if (got == valueHash.end()){
				continue;
			}
			else{
				valueHash.erase(numbers[index1]);
				got = valueHash.find(target - numbers[index1]);
					if (got == valueHash.end()){
						continue;
					} 
					else{
						return_value[0] = index1 + 1;
						return_value[1] = got->second + 1;
						return return_value;
					}
				}
			}	
		}

	//it's a easy algorithm, but cost O(n*n), will cost a lot of time. Save memory space.
	vector<int> twoSum_Simple(vector<int> &numbers, int target){
		for (vector<int>::size_type index1 = 0; index1 < numbers.size()-1; index1++){
			for (vector<int>::size_type index2 = index1 + 1; index2 < numbers.size(); index2++){
				if (numbers[index1] + numbers[index2] == target)
				{
					vector<int> return_value(2);
					return_value[0] = index1 + 1;
					return_value[1] = index2 + 1;
					return return_value;
				}
				else{
					continue;
				}
			}
		}
	}
};

