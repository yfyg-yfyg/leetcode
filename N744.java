class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int left = 0, right = letters.length - 1;
        
        if (target >= letters[letters.length-1] || target < letters[0])
            return letters[0];
        
        while (left < right) {
            int mid = (left + right) / 2 ;
            
            if (letters[mid] <= target) {
                left = mid + 1;
            }
            else if(letters[mid] > target) {
                right = mid;
            }
        }
        
        return letters[right];
    }
}

