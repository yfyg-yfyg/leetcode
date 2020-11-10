class Solution {
    public int countCharacters(String[] words, String chars) {
        HashMap<Character, Integer>  map = new HashMap<>();
        
        for(int i = 0; i < chars.length(); i ++) {
           map.merge(chars.charAt(i), 1, (a, b) -> a + 1); 
        }
        
        return Arrays.stream(words).filter(str -> {
            HashMap<Character, Integer>  mapWord = new HashMap<>();
            for (int i = 0; i < str.length(); i ++) {
                mapWord.merge(str.charAt(i), 1, (a, b) -> a + 1); 
            }
            
            for(Map.Entry<Character, Integer> entry : mapWord.entrySet()) {
                if (entry.getValue() > map.getOrDefault(entry.getKey(), 0))
                    return false;
            } 
            
            return true;
        }).map(str-> str.length()).reduce(0, Integer::sum);
        
        
    }
}

