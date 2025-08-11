class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int[] ans=new int[n];
        Stack<Integer>s=new Stack<Integer>();
        for(int i=2*n - 1 ; i>=0 ; i--){
            while(!s.isEmpty() && nums[s.peek()%n]<=nums[i%n]){
                s.pop();
            }
            ans[i%n]=(s.isEmpty()) ? -1 : nums[s.peek()%n];
            s.push(i%n);
        }
        return ans;
    }
}


// 1 2 1 4 5 9 

// 0 1 2 3 4  5 
// 6 7 8 9 10 11 
 

