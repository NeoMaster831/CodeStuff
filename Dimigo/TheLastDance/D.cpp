#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> numsr;
    for (int i = nums.size() - 1; i >= 0; i--) numsr.push_back(nums[i]);

    long long ans = 987654321234567;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            long long dsum = nums[i] + nums[j];
            long long k1 = lower_bound(nums.begin() + j + 1, nums.end(), target - dsum) - nums.begin();
            long long k2 = k1 - 1 <= j ? 2147483647 : nums[k1 - 1];
            k1 = nums[k1];
            if (abs(dsum + k1 - target) < abs(ans - target)) {
                ans = dsum + k1;
            }
            if (abs(dsum + k2 - target) < abs(ans - target)) {
                ans = dsum + k2;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> input = { 0, 0, 0 };
    int target = 1;
    cout << threeSumClosest(input, target) << '\n';
}