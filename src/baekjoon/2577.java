import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    static int A;
    static int B;
    static int C;
    static String Multiple_str;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        A = Integer.parseInt(br.readLine());
        B = Integer.parseInt(br.readLine());
        C = Integer.parseInt(br.readLine());
        Multiple_str = Integer.toString(A * B * C);
        countNumbers();

    }

    private static void countNumbers() {
        for (int i = 0; i < 10; i++) {
            int count = 0;
            for (int j = 0; j < Multiple_str.length(); j++) {
                int at = Integer.parseInt(String.valueOf(Multiple_str.charAt(j)));
                if (at == i) {
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}
