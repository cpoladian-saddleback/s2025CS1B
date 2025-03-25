#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap; // Stores {value: index}
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if complement exists in the map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return indices of the two numbers
        }

        // Store the current number and its index in the map
        numMap[nums[i]] = i;
    }

    return {}; // Return empty vector if no solution found
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "[" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "No solution found\n";
    }

    return 0;
}
