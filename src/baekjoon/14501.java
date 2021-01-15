import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[] T; //상담에 걸리는 날짜
    static int[] P; //가격
    static int max;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        T = new int[N+1]; //인덱스 1부터 쓸거라 N+1로 크기 할당
        P = new int[N+1];

        StringTokenizer st;
        for(int i =1;i<=N;i++){
            st = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(st.nextToken());
            P[i] = Integer.parseInt(st.nextToken());
        }
        dfs(1,0);
        System.out.println(max);

    }

    static void dfs(int date, int tPrice){
        if(date==N+1){
            if(max<tPrice){
                max = tPrice;
            }
            return;
        }
        if(date+T[date]-1<=N){
            dfs(date+T[date], tPrice+P[date]);
        }
        dfs(date+1, tPrice);
    }
}
