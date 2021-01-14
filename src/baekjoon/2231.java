import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    //나머지 저장하는 배열
    static int[] remainder = new int[42];
    //서로 다른 것의 개수를 세는 변수
    static int count ;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int i=0;i<10;i++){
            int num = Integer.parseInt(br.readLine());
            //나머지를 인덱스로 사용하고, 해당 나머지가 이전에 나온 수가 아닐 시 해당 인덱스의 값을 증가시킴.
            if(remainder[num%42]==0){
                remainder[num%42]++;
                count++;
            }
        }
        System.out.println(count);
    }
}
