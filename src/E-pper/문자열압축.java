import java.util.Scanner;

public class Solution {
   public static String solution(String s) {
	   String answer="";
	   int count=0; 
		
	   if(s.charAt(0)=='1') answer+="1";	// (1) ﻿ 첫 비트가 1인 경우에 문자열의 맨 앞부분에 1을 추가한다
		
	   for(int i=1; i< s.length();i++) {
		   // (﻿2) 비트의 입력의 변화를 찾는다
		   if(s.charAt(i) != s.charAt(i-1)) {
			   answer += (char)('A'+count);   // (﻿3) 비트를 문자로 변환한다
			   count=0;
		   }
		   else count++;
	}
		
	answer += (char)('A'+count);
		
	return answer;
   }
	
	public static void main(String[] args) {
          Scanner input = new Scanner(System.in);

          System.out.println("input str: ");
          String s = input.next();
          String answer = solution(s);
          
          System.out.println("answer: "+answer);
          input.close();
	}
}
