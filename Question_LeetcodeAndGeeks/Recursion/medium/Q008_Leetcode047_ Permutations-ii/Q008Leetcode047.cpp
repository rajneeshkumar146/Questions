
auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> sans;

    void permute(vector<int> &nums, vector<bool> &vis, int count)
    {
        if (count == nums.size())
        {
            ans.push_back(sans);
            return;
        }

        unordered_set<int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!vis[i] && map.count(nums[i]) == 0)
            {
                vis[i] = true;
                sans.push_back(nums[i]);
                map.insert(nums[i]);

                permute(nums, vis, count + 1);
                sans.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        if (nums.size() == 0)
            return ans;
        vector<bool> vis(nums.size(), false);
        permute(nums, vis, 0);
        return ans;
    }
};