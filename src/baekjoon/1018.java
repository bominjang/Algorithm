import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static boolean[][] arr;
    public static int min = 64;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        arr = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();

            for (int j = 0; j < M; j++) {
                if (str.charAt(j) == 'W') {
                    arr[i][j] = true;
                } else {
                    arr[i][j] = false;
                }
            }
        }


        int N_row = N - 7;
        int M_col = M-7;

        for(int i=0;i<N_row;i++){
            for(int j=0;j<M_col;j++){
                find(i,j);
            }
        }
        System.out.println(min);
    }
    public static void find(int x, int y) {

        int end_x = x+8;
        int end_y = y+8;
        int count = 0;

        boolean TF = arr[x][y]; //첫번째 칸의 색

        for(int i=x;i<end_x;i++){
            for(int j=y;j<end_y;j++){
                //올바른 색이 아닐 경우 count 1증가
                if(arr[i][j] != TF){
                    count++;
                }

                TF = (!TF);
            }
            TF = !TF;
        }

        //첫번째 칸을 기준으로 할 때의 색칠할 개수 count와 첫번째 칸의 색에 반대되는 색을 기준으로 할때의 색칠할 개수 (64-count) 중
        // 최솟값을 count에 저장.

        count = Math.min(count, 64-count);

        min = Math.min(min, count);
    }
}
