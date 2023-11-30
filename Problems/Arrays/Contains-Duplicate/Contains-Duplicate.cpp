﻿#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

// Using hash table - Time O(n)

class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> s(begin(nums), end(nums));
        return s.size() != nums.size();
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 3, 1};

    // Print input
    std::cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << "";
        if (i < nums.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    Solution sol;
    bool result = sol.containsDuplicate(nums);

    // Print output
    std::cout << "Output: " << std::boolalpha << result << std::endl;

    return 0;
}