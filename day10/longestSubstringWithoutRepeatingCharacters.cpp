/*
o(n),o(m) where m is the no of unique characters

brute force would be to check till we find a repeating character and then go back the index of the first occurrence of that character
we can track that character and its index using a hashmap o(n^2),o(m) 

optimal approach is to use sliding window technique
we will use two pointers left and right initially at 0
we will move the right pointer and keep adding characters to a set until we find a repeating character
when we find a repeating character we will move the left pointer until we remove that repeating character from the set
we will keep track of the maximum length of the substring without repeating characters by using ans = r - l + 1

*/

    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0;
        unordered_set<char> st;
        while(r < s.length()){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                if(r-l+1 > ans)
                    ans = r-l+1;
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return ans;
    }

/*
very optimized solution is to use an boolean array of size 128 to track the characters instead of a set
*/

    int lengthOfLongestSubstring(string s) {
        vector<bool> appeared(128, false);
        int l = 0;
        int r = 0;

        int max_len = 0;

        while (r < s.size()) {
            if (!appeared[s[r]]) {
                appeared[s[r]] = true;
                max_len = max(max_len, r - l + 1);
                r++;
            }
            else {
                appeared[s[l]] = false;
                l++;
            }
        }
        return max_len;
    }