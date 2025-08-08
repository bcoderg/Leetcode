class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //solve optimal one
    int n1 = nums1.size() , n2 = nums2.size();
    if(n1>n2){
        return findMedianSortedArrays(nums2,nums1);
    }
    int half = (n1+n2+1)/2 , tot = n1+n2;
    int low=0 , high=n1;
    while(low<=high){
        int mid1 = (low+high)>>1;
        int mid2=half-mid1;
        int l1=INT_MIN , l2=INT_MIN , r1=INT_MAX , r2=INT_MAX;
        if(mid1-1>=0)l1=nums1[mid1-1];
        if(mid1 < n1)r1=nums1[mid1];
        if(mid2-1>=0)l2=nums2[mid2-1];
        if(mid2<n2)r2=nums2[mid2];
        
        //perfect match case
        if(l1<=r2 && l2<=r1){
        if(tot%2 ==0)return (double)((max(l1,l2) + min(r1,r2))/2.0);
        return max(l1,l2);
        }
        else if(l1>r2){
            high = mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
    
    return 0.0;
    }
};