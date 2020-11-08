class Solution {
    private int combine(int n) {
       return n *(n -1) / 2;
    }
    
    public int numEquivDominoPairs(int[][] dominoes) {
        
       // ArrayList<int[]> list = new ArrayList<>(dominoes);
        
        ArrayList<int[]> list = new ArrayList<>();
        for (int i = 0; i < dominoes.length; i ++) {
            list.add(dominoes[i]);
        }
        
        list.forEach((int[] a) -> {
            if (a[0] > a[1]) {
                int temp = 0;
                temp = a[0];
                a[0] = a[1];
                a[1] = temp;
            }
            
        });
        
        list.sort((a, b) -> {
            if (a[0] == b[0] && a[1] == b[1])
                return 0;
            else if ( a[0] < b [0]) 
                return -1;
            else if ( a[0] == b[0] && a[1] < b[1])
                return -1;
            else 
                return 1;
         } );
        
        //list.forEach(a -> System.out.println(Arrays.toString(a)));
        
        int total = 0, part = 0;
        Iterator<int[]> iter = list.iterator();
        int[] base = iter.next();
        while(iter.hasNext()) {
            int[] array = iter.next();
            if (array[0] == base[0] && 
                array[1] == base[1]) {
                part ++;
            }
            else {
                total += combine(part + 1);
               // System.out.println(total);
                part = 0;
                base = array;
            }
        }
        
        if(part != 0)
            total += combine(part + 1);
        
        return total;
        
    }
}

