    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Step 1: make an output array filled with 1s
        vector<int> answer(n, 1);

        // Step 2: build prefix products (left to right)
        int prefix = 1; // running product of everything BEFORE i
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;   // at position i, store product of all left side
            prefix *= nums[i];    // update prefix by multiplying current number
        }

        // Step 3: build suffix products (right to left)
        int suffix = 1; // running product of everything AFTER i
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;  // multiply the "before" with the "after"
            suffix *= nums[i];    // update suffix by multiplying current number
        }

        return answer;
    }
