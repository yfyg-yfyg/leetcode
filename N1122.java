class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {

        int[] map = new int[1001];
        for (int e : arr1) {
            map[e] ++;
        }

        int[] ans = new int[arr1.length];
        int k = 0;
        for(int e : arr2) {
            for(int i = 0; i < map[e]; i ++) {
                ans[k++] = e;
            }
            map[e] = 0;
        }

        for(int i = 0; i < 1001; i ++) {
            for(int j = 0; j < map[i]; j ++) {
                ans[k++] = i;
            }
        }

        return ans;
    }
}

