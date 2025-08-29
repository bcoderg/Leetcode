
class Solution {
    void subsets(int[] arr,int start,List<Integer> temp,List<List<Integer>> ans) {
        ans.add(new ArrayList<>(temp));
        for(int i = start ; i<arr.length ; i++)
        {
        temp.add(arr[i]);
        subsets(arr,i+1,temp,ans); //pick the element
        temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        subsets(nums,0,temp,ans);
        return ans;        
    }
}

