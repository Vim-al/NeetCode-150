/*
o(n), o(1)

brute force would be to create an array to store only alphanumeric characters in lowercase and reverse the string and compare

optimized would be to use two pointers one at the front and one at the back. These iterate until they find the alphanumeric characters
and then compare them in lowercase and move the pointers accordingly
*/

    bool isPalindrome(string s) {
         int l = 0, r = s.length() - 1;

        while (l < r) {
            while (l < r && !alphaNum(s[l])) {
                l++;
            }
            while (r > l && !alphaNum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++; r--;
        }
        return true;
    }

    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }