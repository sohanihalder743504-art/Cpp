class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());

        vector<int> result(n);
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums2[i], i});
        }

        sort(arr.begin(), arr.end());

        int left = 0, right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (nums1[right] > arr[i].first) {
                result[arr[i].second] = nums1[right];
                right--;
            } else {
                result[arr[i].second] = nums1[left];
                left++;
            }
        }

        return result;
    }
};