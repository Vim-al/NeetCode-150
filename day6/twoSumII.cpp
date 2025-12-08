/*
o(n), o(1)

brute force would be to iterate through all pairs and find the target o(n^2), o(1)

optimized would be to use two pointers since they are sorted. if the sum is greater than the target then that means
the right element must be smaller and vice versa.
*/

    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j){
            if(numbers[i]+numbers[j] == target)
                return {i+1,j+1};
            else if(numbers[i]+numbers[j] > target)
                j--;
            else
                i++;
        }
        return {0,0};
    }