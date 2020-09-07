/*
uijin.lee
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
       std::vector<int> result;
		int nodeNum = 0;
		Recursive(root1, &result, &nodeNum);
        if(nodeNum > 5000)
        {
            result.clear();
            return result;
        }
		nodeNum = 0;
		Recursive(root2, &result, &nodeNum);
        
		std::sort(result.begin(), result.end());

		return  result;
    }
    
     vector<int> Recursive(TreeNode* root, vector<int>* result, int* num)
	{		
		TreeNode* curr = nullptr;
		if (root != nullptr)
		{
			curr = root;
		}
		else
		{
			return *result;
		}

        if(*num <= 5000)
		{
			if (curr->val >= -1 * (10 * 10 * 10 * 10 * 10) && curr->val <= (10 * 10 * 10 * 10 * 10))
			{
			    (*num)++;
				(*result).push_back(curr->val);
			}

			Recursive(curr->left, result, num);
			Recursive(curr->right, result, num);
		}

		return *result;
     }
};