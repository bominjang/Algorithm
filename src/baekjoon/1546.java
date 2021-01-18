import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static double M;
    static double[] scores;
    static int sub_num;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sub_num = Integer.parseInt(br.readLine());
        
        // 점수 배열 생성 
        scores = new double[sub_num];
        
        //점수 입력 받기 
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i =0;i<sub_num;i++){
            scores[i] = Double.parseDouble(st.nextToken());
            //입력 받음과 동시에 Max값 계
            if(i==0){
                M=scores[0];
            }else if(M<scores[i]){
                M = scores[i];
            }
        }
        System.out.println(getAverage());
    }

    public static double getAverage(){
        double sum = 0;
        double avg = 0;
        // for문 돌면서 값 변경 & 평균값 계산
        for(int j=0;j<sub_num;j++){
            scores[j] = scores[j]/M*100;
            sum += scores[j];
            if(j==sub_num-1){
                avg = sum/(double)sub_num;
            }
        }
        return avg;
    }
}
