#include <unordered_map>


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> inventory;

        for(int i = 0;i<nums.size();i++){
            if(inventory[nums[i]] == 0){
                inventory[nums[i]] = 1;
            }else{
                return true;
            }
        }
        return false;
    }
};