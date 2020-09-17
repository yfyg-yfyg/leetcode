class Solution {
    private boolean isMultiPattern(String str, String sub) {
        if (str.length() % sub.length() != 0) {
            return false;
        }
        else {
            String multi_sub = sub;
            int factor = str.length() / sub.length();
            for (int i = 1; i < factor; i ++) {
                multi_sub += sub;
            }

            return multi_sub.equals(str);
        }
    } 

    public String gcdOfStrings(String str1, String str2) {
        String shorter, longer;

        if (str1.length() < str2.length()) {
            shorter = str1;
            longer = str2;
        }
        else {
            shorter = str2;
            longer = str1;
        }

        for(int i = shorter.length(); i > 0; i --) {
            if ( shorter.length() % i == 0 ) {
                String sub = shorter.substring(0, i);
                if(isMultiPattern(shorter, sub) && isMultiPattern(longer, sub)) {
                    return sub;
                }
            }
        }

        return "";
    }
}

