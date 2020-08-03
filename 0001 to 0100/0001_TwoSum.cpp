class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash-map to store the explored numbers and their index
        unordered_map<int, int> m;
        vector<int> result; // to store the result (ie. indices of numbers whose sum equals to target)
            
        int n = nums.size();
        for(int i=0; i<n; i++) {
            // check whether 'target-currentNumber' is there in the hash-map or not
            // if it is there then we got the numbers whose sum is equal to target
            if(m.find(target-nums[i]) != m.end()) {
                result.push_back(m[target-nums[i]]);
                result.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        
        return result;
    }
};