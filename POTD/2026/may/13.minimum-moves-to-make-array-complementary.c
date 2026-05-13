int minMoves(int* nums, int n, int limit) {
    int *one = (int*) malloc((2 * limit + 2) * sizeof(int));
    int *sum = (int*) malloc((2 * limit + 2) * sizeof(int));
    for (int i = 0; i < 2 * limit + 2; i++) one[i] = sum[i] = 0; 
    for (int i = 0; i < n / 2; i++) {
        int max = nums[i] > nums[n-i-1] ? nums[i] : nums[n-i-1];
        int min = nums[i] < nums[n-i-1] ? nums[i] : nums[n-i-1];
        one[min+1]++; one[max+limit+1]--;
        sum[nums[i]+nums[n-i-1]]++;
    }
    int curr = 0, ans = n;
    for(int i = 2; i <= 2 * limit; i++) {
        one[i] = curr += one[i];
        int op = one[i] - sum[i];
        op += 2 * (n / 2 - one[i]);
        ans = ans < op ? ans : op;
    }
    return ans;
}