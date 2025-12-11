/*
o(n), o(1) should research this one

optimized would be to use prefix and suffix arrays to track the highest wall and then to calculate the water trapped using the formula
min(prefix[i], suffix[i]) - height[i] o(n), o(n)

the logic to get to this approach is as follows:
1. for each index i, we need to find the maximum height of wall to its left and to its right
2. the water that can be trapped on top of the wall at index i is determined by the shorter of these two walls minus the height of the wall at index i itself
3. by precomputing the maximum heights to the left and right for each index, we can efficiently calculate the total trapped water in a single pass through the height array.
4. finally, we sum up the water trapped at each index to get the total amount of trapped water.

there is another approach using 2 pointers left and right and tracking leftmax and rightmax o(n), o(1) ((should research this one))

*/


    int trap(vector<int>& h) {
        int n = h.size();
        if(n <= 2) return 0;

        vector<int> left(n), right(n);

        left[0] = h[0];
        for(int i = 1; i < n; i++)
            left[i] = max(left[i-1], h[i]);

        right[n-1] = h[n-1];
        for(int i = n-2; i >= 0; i--)
            right[i] = max(right[i+1], h[i]);

        int water = 0;
        for(int i = 0; i < n; i++)
            water += min(left[i], right[i]) - h[i];

        return water;
    }


    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int res=0;
        int maxleft=0,maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft){
                    maxleft=height[left];
                }else{
                    res+= maxleft-height[left];
                }
                left++;
            }else{
                if(height[right]>=maxright){
                    maxright=height[right];
                }else{
                    res+= maxright-height[right];
                }
                right--;
            }
        }
        return res;
    }


    