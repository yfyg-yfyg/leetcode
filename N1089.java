class Solution {
    public void duplicateZeros(int[] arr) {
        int len = 0;
        int pos = 0;

        while(len < arr.length) {
            if (arr[pos++] == 0) {
                len += 2;
            }
            else {
                len ++;
            }
        }

        int index = 0;
        if (len > arr.length) {
            arr[arr.length - 1] = 0;
            pos --;
            index = arr.length -2;
        }
        else {
            index = arr.length - 1;
        }
 
        for (int i = pos - 1; i >= 0; i --) {
            if (arr[i] == 0) {
                arr[index--] = 0;
                arr[index--] = 0;
            }
            else {
                arr[index--] = arr[i];
            }
        }
    }
}

