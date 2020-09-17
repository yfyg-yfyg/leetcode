class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] array = text.split(" ");

        ArrayList<String> ans = new ArrayList<>();
        for (int i = 0; i < array.length - 2; i ++ ) {
            if (array[i].equals(first) && array[i + 1].equals(second)) {
                ans.add(array[i + 2]);
            }
        }

        return ans.toArray(new String[ans.size()]);
    }
}

