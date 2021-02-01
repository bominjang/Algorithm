import java.util.Scanner;

public class Solution {
   
   static int solution(int n, int m){
      // answer은 재고가 떨어지는데 걸리는 날짜
      int answer=0;
      // m일에 한 번 재고가 들어오는 날짜 flag
      int p=0;
      // (1) 재고가 0이 될때까지 반복 
      while(n>0){      
         // (2) 재고는 1씩 감소, 날짜는 1씩 증가 
         n--;
         answer++;
         p++;
         // (3) 만약 m일이 지나면 재고 n은 1증가, 날짜 p는 다시 0
         if(p==m){
            n++;
            p=0;
         }
      }
      return answer;
   }
   
   public static void main(String[] args) {
      Scanner scanner=new Scanner(System.in);
      int n=scanner.nextInt();
      int m= scanner.nextInt();
      int answer=solution(n,m);
      System.out.println(answer);
   }

}
