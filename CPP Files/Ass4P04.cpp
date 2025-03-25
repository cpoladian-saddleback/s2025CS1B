#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;

    for (int num : nums) {
        // Start sequence only if num is the beginning of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;

            // Count consecutive numbers
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }

            longestStreak = std::max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

int main() {
    std::vector<int> nums = {100, 4, 200, 1, 3, 2}; // Example input
    std::cout << "Longest Consecutive Sequence Length: " << longestConsecutive(nums) << std::endl;
    return 0;
}
