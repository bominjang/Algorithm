import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static boolean visit[][];
    public static int map[][];
    private static int M,N,K,count, area;
    static int dx[] = {1, -1, 0,0};
    static int dy[] = {0,0,1,-1};
    public static void main(String[] args) throws IOException {

        makeMap();

        ArrayList<Integer> list = new ArrayList<>();
        count =0;

        for(int i=0;i<M;i++) { //
            for (int j = 0; j < N; j++) { //
                area =0;
                if (map[i][j] == 0) {
                    count++;
                    dfs(i, j);
                    list.add(area);
                }
            }
        }

        System.out.println(count);

        list.sort(null);

        for(int a:list){
            System.out.print(a+" ");
        }

    }

    private static void makeMap() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine(), " ");

        M = Integer.parseInt(st.nextToken()); //행
        N = Integer.parseInt(st.nextToken()); //열
        K = Integer.parseInt(st.nextToken());

        map = new int[M][N];
        visit = new boolean[M][N];

        int leftbelowX, leftbelowY, rightUpX, rightUpY ;

        for(int i=0;i<K;i++){
            st = new StringTokenizer(br.readLine(), " ");

            leftbelowX = Integer.parseInt(st.nextToken());
            leftbelowY = Integer.parseInt(st.nextToken());
            rightUpX = Integer.parseInt(st.nextToken());
            rightUpY = Integer.parseInt(st.nextToken());

            for(int m = leftbelowY; m<rightUpY;m++){
                for(int j = leftbelowX;j<rightUpX;j++){
                    map[m][j] = 1;
                }
            }
        }
    }

    private static void dfs(int x, int y){
        map[x][y] = 1;
        area++;

        for(int i = 0; i<4; i++){
            int locX = x + dx[i];
            int locY = y + dy[i];

            if(0<=locX && locX < M && 0<=locY && locY < N){
                if(map[locX][locY] == 0){
                    dfs(locX,locY);
                }
            }
        }


    }
}
