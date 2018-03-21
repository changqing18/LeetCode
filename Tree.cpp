#include <iostream>
#include <vector>
#include<cctype>

using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedArrayToBST(vector<int> &nums);
TreeNode *bulid(vector<int> &nums, int position, int size);

bool isPalindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j)
            i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j)
            j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j]))
            return false; // Exit and return error if not match
    }

    return true;
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    sortedArrayToBST(nums);
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int position = nums.size();
    return bulid(nums, position / 2, position);
}

TreeNode *bulid(vector<int> &nums, int position, int size)
{
    TreeNode *node = new TreeNode(nums.at(position));
    if (size == 0)
        return NULL;
    size = size / 2;
    node->left = bulid(nums, position - size, size);
    node->right = bulid(nums, position + size, size);
    return node;
}
