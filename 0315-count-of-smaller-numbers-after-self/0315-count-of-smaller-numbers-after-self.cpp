class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        vector<pair<int, int>> temp(n);

        function<void(int, int)> mergeSort = [&](int left, int right) {
            if (left >= right) return;

            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);

            int i = left, j = mid + 1, k = left;
            int count = 0;

            while (i <= mid && j <= right) {
                if (arr[i].first <= arr[j].first) {
                    result[arr[i].second] += count;
                    temp[k++] = arr[i++];
                } else {
                    count++;
                    temp[k++] = arr[j++];
                }
            }

            while (i <= mid) {
                result[arr[i].second] += count;
                temp[k++] = arr[i++];
            }

            while (j <= right) {
                temp[k++] = arr[j++];
            }

            for (int p = left; p <= right; p++) {
                arr[p] = temp[p];
            }
        };

        mergeSort(0, n - 1);
        return result;
    }
};