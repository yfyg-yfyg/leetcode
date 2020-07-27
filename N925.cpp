class Solution {

private:
    int searchLetter(const string &typed, char character, 
                     int pos, int count) {

       // cout << "char: " << character << " pos: " << pos << " count:" << count <<endl;
        
        int repeat = 0;
        int i = pos;
        for (; i < typed.length(); i ++) {
            if (typed[i] == character)
                repeat ++;
            else 
                break;
        }

        if (repeat >= count)  {
      //      cout << "repeat: " << repeat << endl;
            return i;
        }
        else {
      //      cout << "not find !" << endl;
            return -1;
        }
    }

public:
    bool isLongPressedName(string name, string typed) {
        
        char letter = name[0];
        int count = 1;
        int pos_typed = 0;
        int pos = 1;
        for (; pos < name.length(); pos ++) {
            if (name[pos] == letter) {
                count ++;
            }
            else {
                pos_typed = searchLetter(typed, letter, pos_typed, count);
                if (pos_typed == -1)
                    return false;
                else {
                    count = 1;
                    letter = name[pos];
                }
            }
        }
       
        pos_typed = searchLetter(typed, letter, pos_typed, count);
        if (pos_typed == -1)
          return false;
   
        if (pos_typed < typed.length())
            return false;
        else  
            return true;
     }
};

