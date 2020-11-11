class Solution {
    
     static private int calMinFreq(String str) {
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
    
    static private int calMinFreq1(String str) {
        int[] freq = new int[26];
        for (int i = 0; i < str.length(); i ++) {
            freq[str.charAt(i) - 'a'] ++;
        }

        int minFreq= 0; 
        for (int i = 0; i < 26; i ++) {
            if (freq[i] != 0) {
                minFreq = freq[i];
                break;
            }
        }


        return minFreq;
    }

    static private int binarySearch(int[] array, int value) {
        int low = 0, mid = 0, high = array.length - 1;
        
        while(low <= high) {
            mid = (low + high) / 2;
            if (array[mid] <= value) {
                low = mid + 1;
            }
            else if (array[mid] > value) {
                high = mid - 1;
            }
            else {
                break;
            }
        }
        
       return  array.length - low ;
    }
    
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        
        int[] queriesFreq = Arrays.stream(queries).mapToInt(Solution::calMinFreq).toArray();
        int[] wordsFreq = Arrays.stream(words).mapToInt(Solution::calMinFreq).sorted().toArray();

        return Arrays.stream(queriesFreq).map( query -> Solution.binarySearch(wordsFreq, query)).toArray();
    }
}

