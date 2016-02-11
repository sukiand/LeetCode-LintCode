//Given an array S of n integers, find three integers in S such that the sum is closest to 
//a given number, target.Return the sum of the three integers.You may assume that each 
//input would have exactly one solution.
//
//For example, given array S = { -1 2 1 - 4 }, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	int threeSumClosest(vector<int> & nums, int target){
		sort(nums.begin(), nums.end());
		int length = nums.size();
		if (length < 3){
			return 0;
		}
		int minSum, maxSum;
		minSum = nums[0] + nums[1] + nums[2];
		if (minSum - target >= 0){
			return minSum;
		}
		maxSum = nums[length - 1] + nums[length - 2] + nums[length - 3];
		if (maxSum - target <= 0){
			return maxSum;
		}
		vector<int>::size_type i, j, k;
		bool flag = true;
		for (i = 0; i < length - 2; i++){
			j = i + 1;
			k = length - 1;
			while (j<k)
			{
				maxSum = nums[i] + nums[j] + nums[k];
				if (flag){
					minSum = maxSum;
					flag = false;
				}
				else{
					if (abs(minSum - target) > abs(maxSum - target))
					{
						minSum = maxSum;
					}
				}
				if (maxSum > target){
					k--;
				}
				else if (maxSum < target){
					j++;
				}
				else {
					return target;
				}
			}	
		}
		return minSum;
	}
};