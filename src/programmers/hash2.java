import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        boolean finish = false;

        Arrays.sort(phone_book, (s1,s2)->s1.length()-s2.length());
        
        for(int i=0;i<phone_book.length;i++){
            if (finish){
                break;
            }
            String current = phone_book[i];
            int cur_len = current.length();
            for (int j=i+1; j<phone_book.length;j++){
                String compare = phone_book[j];
                
                if(current.equals(compare.substring(0,cur_len))){
                    answer = false;
                    finish = true;
                    break;
                }
            }
        }
        return answer;
    }
}
