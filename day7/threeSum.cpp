/*
o(n^2), o(1)

brute force would be to use 3 loops and to find the the unique triplets o(n^3), o(1)

another good solution is to use hashmap to store the pairs and check for the third element in the map o(n^2), o(n)

optimized would be to sort the array and use 2 pointer approach to find the triplets(twoSumII approach)
but there are some edge cases we need to handle
1. skip duplicates for the first element
2. if the first element itself > 0 then theres no need to check anymore since the sum then will be always positive
3. if the sum = 0 then we increase the left pointer and decrease the right pointer
    3i. while moving the left and right pointers we should skip the duplicates which can be done by checking the left pointer with its previous element
    3ii. if we check for the left element then no need to check for the right
    -> this duplicate checking can be done once we find a valid triplet
*/

    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        int n = a.size();
        for(int i = 0; i < n-2; i++){
            if(a[i] > 0) 
                break;
            if(i > 0 and a[i] == a[i-1])
                continue;
            int j = i+1, k = n-1;
            while(j<k){
                if(a[i]+a[j]+a[k] == 0){
                    ans.push_back({a[i], a[j], a[k]});
                    j++;
                    k--;
                    while (j < k && a[j] == a[j - 1]) {
                        j++;
                    }
                }
                else if(a[i]+a[j]+a[k] > 0)
                    k--;
                else
                    j++;
            }
        }
        return ans;