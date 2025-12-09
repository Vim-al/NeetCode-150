/*
o(n), o(1)

brute force would be to sort the array and then find the longest consecutive sequence o(nlogn), o(1)

optimized would be to use the o(1) lookup of hashset (unordered_set to be precise) 
an other hint is to only start counting when we find the start of a sequence (i.e num-1 not in set)
this hint would help us int avoiding unnecessary repetitions of finding sequence

*/

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(auto it: s){
            if(s.find(it-1) == s.end()){
                int temp = 1;
                while(s.find(it+temp) != s.end()){
                    temp++;
                }
                if(temp > ans){
                    ans = temp;
                }
            }
        }
        return ans;
    }