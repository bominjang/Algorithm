import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);

        System.out.println(arithmetic_sequence(scn.nextInt()));
        scn.close();
    }

    public static int arithmetic_sequence(int num){
        int cnt = 0; //한수 개수

        if(num<100){
            return num;
        }
        else{
            cnt = 99;
            if(num == 1000){ // 예외처
                num = 999;
            }

            for(int i=100;i<=num;i++){
                int hun = i/100; // 100의 자릿수
                int ten = (i/10)%10; // 10의 자릿수
                int one = i%10; //1의 자릿

                if((hun-ten) == (ten-one)){ //각 자리가 등차수열을 이루면
                    cnt++;
                }
            }
        }

        return cnt;
    }

}
