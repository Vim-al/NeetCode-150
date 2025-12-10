/*
o(n), o(1)

brute force would be to use two loops to check every possible container and find the max area o(n^2),o(1)

optimized would be to use two pointers
the trick here is to find the max area formula which is min(height[left], height[right]) * (right - left)
and other case would be to move the pointer pointing to the smaller height because moving the larger height pointer would not help in increasing the area

*/

    int minn(int a, int b){
        if(a < b){
            return a;
        }
        return b;
    }

    int maxArea(vector<int>& height) {
        int ans = 0, left = 0, right = height.size()-1, tempArea = 0;
        while(left < right){
            tempArea = (right - left) * min(height[left],height[right]);
            if(tempArea > ans){
                ans = tempArea;
                tempArea = 0;
            }
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return ans;
    }