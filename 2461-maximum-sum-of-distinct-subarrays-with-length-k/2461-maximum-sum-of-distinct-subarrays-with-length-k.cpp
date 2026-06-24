class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        long long sum=0;
        long long ans=0;
        unordered_set<int> st;
        int l=0;
	    for(int i=0;i<arr.size();i++){
            while(st.contains(arr[i])){
                sum-=arr[l];
                st.erase(arr[l++]);
            }
            st.insert(arr[i]);
            sum+=arr[i];
            if(i - l + 1 > k) {
                sum -= arr[l];
                st.erase(arr[l]);
                l++;
            }
            if(i-l+1==k) ans=max(ans,sum);
	    }
	    return ans;
    }
};