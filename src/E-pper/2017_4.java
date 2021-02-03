import java.util.*;
public class number_4 {

 public static void main(String[] args) {
  // TODO Auto-generated method stub
  Scanner sc = new Scanner(System.in);
  int total, price, change;
  int coin[]={500, 100, 50, 10, 5, 1};
  int cnt=0;
  total = sc.nextInt();
  price = sc.nextInt();
  change = total -price;
  for(int i=0 ; i<6 ; i++){
   cnt += change/coin[i];
   change = change % coin[i];
  }
  System.out.println(cnt);
 }

}
