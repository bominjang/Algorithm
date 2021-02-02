import java.util.Scanner;
 
public class Q2 {
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n, sum = 0, score, n_students = 0;
        int []scores;
        double avg;
        
        // 학생 수를 입력 받아서 n에 저장하기.
        n = scanner.nextInt();
        scores= new int[n];
        
        // 각 학생의 점수를 입력 받아서 []scores에 저장하기
        // sum은 모든 학생 점수의 합.
        for(int i=0; i<n; i++){
            score = scanner.nextInt();
            scores[i] = score;
            sum += score;
        }
 
        // 평균 구하기
        avg = (double)sum / n;
 
        // 평균을 넘는 학생의 수를 n_students에 세기
        for(int i=0; i<n; i++)
            if(scores[i] > avg)
                n_students++;
        
        // 결과 출력
        System.out.println(
                String.format("%.3f%%", (double)n_students / n * 100));
    }
}
