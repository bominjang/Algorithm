import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N  = Integer.parseInt(br.readLine());

        System.out.println(fibo(N));
    }

    public static int fibo(int N){
        if(N==0) return 0;
        if(N==1) return 1;
        return fibo(N-1)+fibo(N-2);
    }

}

// Scanner보다 BufferedReader가 시간이 적게 걸림.
// 피보나치는 재귀말고 for문으로도 구현할 수 있음
/*
@author kdgyun
*/
