import java.util.*;

class Solution {
    private static String[] map;
    private static String[] result;
    private static boolean[] visited;
    private static HashSet<Integer> list;

    public int solution(String numbers) {
        int answer = 0;

        visited = new boolean[numbers.length()];
        map = new String[numbers.length()];
        map = numbers.split("");

        list = new HashSet();

        for (int i=1; i<=numbers.length(); i++) {
            result = new String[i];
            makeNumber(0, i, numbers.length());
        }

        return list.size();
    }
    

    public void makeNumber(int current, int digit, int length) {

        if (current == digit) {
            getPrime();
        } else {

            for (int i=0; i<length; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    result[current] = map[i];
                    makeNumber(current+1, digit, length);
                    visited[i] = false; //되돌려놓기
                }
            }

        }

    }

    public void getPrime() {
        String str = "";
        for(int i=0; i<result.length; i++){
          str += result[i]; //문자형태로 된 숫자들 합치기
        }
            
        int num = Integer.parseInt(str); //숫자로 변환

        // 예외
        if(num == 1 || num == 0){
          return;
        }
            

        // 소수 검사
        boolean flag = true;
        for(int i=2; i*i<=num; i++){
            if(num % i == 0){
              flag = false;
            }
                
        }

        if(flag){
          list.add(num);
        }
            
    }
}
