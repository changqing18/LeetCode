#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = left(nums, target);
        if (l < 0 || l >= n || nums[l] != target)
            return {-1, -1};
        return {l, left(nums, target + 1) - 1};
    }

  private:
    int left(vector<int> &nums, int target)
    {
        int n = nums.size(), l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};