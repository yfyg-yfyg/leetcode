class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr2.length; i ++) {
            map.put(arr2[i], i);
        }
         
        Comparator<Integer> comp = (a, b) -> {
            boolean containA = map.containsKey(a);
            boolean containB = map.containsKey(b);
            if (containA && containB) {
                return map.get(a) - map.get(b);
            }
            else if (containA) {
                return -1;
            }
            else if (containB) {
                return 1;
            }
            else {
                return a - b;
            }
        };
        
        arr1 = IntStream.of(arr1).boxed().sorted(comp).mapToInt(i -> i).toArray();
     
        
        return arr1;
        
    }   
}
