import java.util.Scanner;


public class Main {
    private static boolean visit[];
    private static int arr[];

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String[] NM = scan.nextLine().split(" ");

        int N = Integer.parseInt(NM[0]);
        int M = Integer.parseInt(NM[1]);
        
        arr = new int[M];
        visit = new boolean[N];
        dfs(N,M,0);

    }

    public static void dfs(int N, int M, int depth){
        if(depth==M){
            for(int val:arr){
                System.out.print(val + " ");
            }
            System.out.println();
            return;
        }
        
        for(int i=0;i<N;i++){
            if(!visit[i]){
                visit[i]=true;
                arr[depth] = i+1;
                dfs(N, M, depth+1);
                visit[i] = false;
            }
        }
    }
}
