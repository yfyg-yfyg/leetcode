class Solution {
    
     static public int calMinFreq(String str) {
         int count = 1;
         char minChar = str.charAt(0);
         for(int i = 1; i < str.length(); i ++) {
             if ( str.charAt(i) < minChar) {
                 minChar = str.charAt(i); 
                 count = 1;
             }
             else if (str.charAt(i) == minChar) {
                 count ++;
             }
         } 

         return count;
    }
    
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        
      /*
        Map<Character, Long> map = 
                       Arrays.stream(queries)
                       .map(str -> str.toCharArray().stream()  
                       .collect(groupingBy(Function.identity(), Collectors.counting()))); 
        
        System.out.println(map);
     */
        
      IntStream  queriesFreq = Arrays.stream(queries).mapToInt(Solution::calMinFreq);
      return queriesFreq.map( query -> {
                                  return (int) Arrays.stream(words)
                                              .mapToInt(Solution::calMinFreq)
                                              .filter(word -> word > query).count();
                            })
                            .toArray(); 
    }
}

