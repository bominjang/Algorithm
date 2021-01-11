import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLOutput;

public class Main {
    static int N,M;
    static String cards[];
    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try{
            String[] inputStr = br.readLine().split(" ");
            cards = br.readLine().split(" ");
            N = Integer.parseInt(inputStr[0]);
            M = Integer.parseInt(inputStr[1]);
            blackJack(cards,M,N);
        }catch(IOException e){
            e.printStackTrace();
        }

    }

    private static void blackJack(String[] cards, int M,int N){
        int tmp=0;
        int A = 0;
        int B = 0;
        int C = 0;

        for(int i=0;i<N-1;i++){
            A=Integer.parseInt(cards[i]);
            for(int j=i+1;j<N-1;j++){
                B = Integer.parseInt(cards[j]);
                for(int k=j+1;k<N;k++){
                    C = Integer.parseInt(cards[k]);
                    int sum = A+B+C;
                    if(sum==M){
                        System.out.println(sum);
                        return;
                    }else if(M>sum){
                        if(M-tmp>=M-sum){
                            tmp=sum;
                        }
                    }

                }
            }
        }
        System.out.println(tmp);
    }
}
