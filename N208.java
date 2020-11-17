class Trie {
    Map<Character, Trie> edges;
    Boolean end;

    /** Initialize your data structure here. */
    public Trie() {
        edges = new HashMap<>();
        end = false;
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie currentNode = this;
        
        for (Character c : word.toCharArray()) {
            if (currentNode.edges.containsKey(c)) {
                currentNode = currentNode.edges.get(c);
            }
            else {
                Trie node = new Trie();
                currentNode.edges.put(c, node);
                currentNode = node;
            }
        }
        
        currentNode.end = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Trie currentNode = this;
        
        for (Character c : word.toCharArray()) {
            if (currentNode.edges.containsKey(c)) {
                currentNode = currentNode.edges.get(c);
            }
            else 
                return false;
        }
        
        return currentNode.end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Trie currentNode = this;

        for (Character c : prefix.toCharArray()) {
            if (currentNode.edges.containsKey(c)) {
                currentNode = currentNode.edges.get(c);
            }
            else 
                return false;
        }

        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */

