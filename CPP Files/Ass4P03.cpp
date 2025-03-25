#include <iostream>
#include <vector>

int findMissingNumber(std::vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2; // Sum of first n natural numbers
    int actualSum = 0;

    for (int num : nums) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main() {
    std::vector<int> nums = {3, 0, 1}; // Example input

    int missingNumber = findMissingNumber(nums);
    std::cout << "Missing number: " << missingNumber << std::endl;

    return 0;
}
