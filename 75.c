#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    // Hash map using array (for simplicity)
    // Assuming sum range won't exceed -10000 to 10000
    int hash[20001];
    
    for(int i = 0; i < 20001; i++)
        hash[i] = -2; // initialize with -2 (means not visited)

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum becomes 0 → subarray from 0 to i
        if(sum == 0)
            max_len = i + 1;

        // If sum seen before
        if(hash[sum + 10000] != -2) {
            int prev_index = hash[sum + 10000];
            if(i - prev_index > max_len)
                max_len = i - prev_index;
        } else {
            // Store first occurrence
            hash[sum + 10000] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLen(arr, n));
    return 0;
}
