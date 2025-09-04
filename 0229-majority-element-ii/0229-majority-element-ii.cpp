class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //extend moore's voting algorithm by tracking 2 numbers
	int n = nums.size();
	int c1=0 , c2 =0 , ele1=INT_MIN , ele2=INT_MIN;
	for(int num: nums){
	    if(c1==0 && num!=ele2){
		ele1=num;
		c1=1;
	    }
	    else if(c2==0 && num!=ele1){
		ele2=num; 
		c2=1;
	    }
	    else if(num==ele1)c1++;
	    else if(num==ele2)c2++;
	    else{
		c1--;c2--;
	    }
	}
    c1 = 0 , c2= 0;
    for(int num:nums){
        if(num==ele1)c1++;
        if(num==ele2)c2++;
    }
    vector<int>ans;
    if(c1 > (n/3))ans.push_back(ele1);
    if(c2 > (n/3))ans.push_back(ele2); 
	return ans;
    }
};