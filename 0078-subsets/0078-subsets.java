
class Solution {
    void subsets(int[] arr,int i,List<Integer> temp,List<List<Integer>> ans) {
        //base case
        if(i==arr.length) {
            // System.out.println(sum);
            ans.add(new ArrayList<>(temp));
            return;
        }
        temp.add(arr[i]);
        subsets(arr,i+1,temp,ans); //pick the element
        temp.remove(temp.size()-1);
        subsets(arr,i+1,temp,ans); //not pick the element
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        subsets(nums,0,temp,ans);
        return ans;
        
    }
}

