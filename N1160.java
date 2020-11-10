class Solution {
    public int countCharacters(String[] words, String chars) {
        char[] map = new char['z' - 'A' + 1];
        
        for(int i = 0; i < chars.length(); i ++) {
            map[chars.charAt(i) - 'A'] ++;
        }
        
        return Arrays.stream(words).filter(str -> {
            char[] mapWord = new char['z' - 'A' + 1];
            for (int i = 0; i < str.length(); i ++) {
                mapWord[str.charAt(i) - 'A'] ++;
            }
            
            for (int i = 0; i < mapWord.length; i ++) {
                if (mapWord[i] > map[i])
                    return false;
            }
            return true;
        }).map(str-> str.length()).reduce(0, Integer::sum);
        
        
    }
}

