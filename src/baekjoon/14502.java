import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        origin = new int[N][M];
        map = new int[N][M];
        for(int i = 0 ; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j< M ; j++) {
                origin[i][j] = Integer.parseInt(st.nextToken());
                if(origin[i][j] == 2) {
                    viruses.add(new virus(i, j));
                }
            }
        }
        
        dfs(0, 0, 0);
        System.out.println(max);
    }
    static int N, M;
    static int[][] origin, map;
    
    static ArrayList<virus> viruses = new ArrayList<virus>();
    static class virus{
        int y, x;
        public virus(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
    static int max = 0;
    static void dfs(int iy, int ix, int cnt) {
        
        if(cnt == 3) {
            Queue<virus> q = new LinkedList<virus>();
            for(int v = 0 ; v < viruses.size() ; v++) {
                q.add(viruses.get(v));
            }
            
            for(int i = 0 ; i < N ; i++) {
                for(int j = 0 ; j< M ; j++) {
                    map[i][j] = origin[i][j];
                }
            }
            
            virus cur;
            int ny, nx;
            while(!q.isEmpty()) {
                cur = q.poll();
                for(int dir = 0 ; dir < 4 ; dir++) {
                    ny = cur.y + delta[dir][0];
                    nx = cur.x + delta[dir][1];
                    if(!(ny>= 0 && ny < N && nx >= 0 && nx < M))
                        continue;
                    if(map[ny][nx] == 0) {
                        map[ny][nx] = 2;
                        q.add(new virus(ny, nx));
                    }
                }
            }
            
            int cntSafe = 0;
            for(int i = 0 ; i < N ; i++) {
                for(int j = 0 ; j< M ; j++) {
                    if(map[i][j] == 0)
                        cntSafe++;
                }
            }
            if(max < cntSafe)
                max = cntSafe;
            
            return;
        }
        
        if(iy == N)
            return;
        
        if(origin[iy][ix] == 0 && cnt < 3) {
            origin[iy][ix] = 1;
            if(ix < M-1)
                dfs(iy, ix+1, cnt+1);
            else
                dfs(iy+1, 0, cnt+1);
            origin[iy][ix] = 0;
        }
        if(ix < M-1)
            dfs(iy, ix+1, cnt);
        else
            dfs(iy+1, 0, cnt);
    }
    static int[][] delta = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
    };
}
