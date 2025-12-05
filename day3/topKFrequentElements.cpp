/*
o(n), o(n)

brute force would be to sort the elements in descending order and iterate over to find the first k unique elements

optimized would be to use bucket sort. Basically we would count the frequency of each element using hashmap
then create an array of arrays of size (nums + 1) => this +1 is to handle the edge case where all the elements are the same element
so for example [1,1,1,1,1] here the count would be 5 but if we just initialize an array of size 5 there would be only indices till 4 like 0,1,2,3,4.
the idea is to store the elements with the indices as the frequency. So 6th index would have the elements who have 6 occurrences
and then since the order of the answer doesnt matter we iterate from the last to get the highest frequency first
and then insert them into a resultant array until k becomes 0
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for(auto it: nums){
        mp[it]++;
    }

    vector<vector<int>> buckets(nums.size()+1);
    for(auto it: mp){
        buckets[it.second].push_back(it.first);
    }

    vector<int> ans;
    for(int i = nums.size(); i > 0; i--){
        if(k == 0)
            break;
        if(buckets[i].size() != 0){
            for(auto it: buckets[i]){
                ans.push_back(it);
                k--;
                if(k == 0)
                    break;
            }
        }
    }
    
    return ans;
}