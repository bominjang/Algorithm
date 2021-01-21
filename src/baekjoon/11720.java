import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N  = Integer.parseInt(br.readLine());
        String numbers = br.readLine();

        System.out.println(getSum(N, numbers));
    }

    public static int getSum(int N, String numbers){
        int sum = 0;
        String[] numbersArray = numbers.split("");

        for(int i=0;i<N;i++){
            sum += Integer.parseInt(numbersArray[i]);
        }
        return sum;
    }

}
