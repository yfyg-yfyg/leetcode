class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int e : arr2) {
            map.put(e,0);
        }
        
        int[] ans = new int[arr1.length];
        int end = ans.length - 1;
        
        for(int e : arr1) {
            if(map.containsKey(e)) {
               map.put(e, map.get(e) + 1);
            }
            else {
                ans[end--] = e;
            }
        }
        
        int head = 0;
        for (int e : arr2) {
            for(int i = 0; i < map.get(e); i ++) {
                ans[head++] = e;
            }
        }

        Arrays.sort(ans, head, ans.length);
        return ans;
   
    }   
     
}
