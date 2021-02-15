class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        
        int answer = n-lost.length;
        
        for(int lst : lost){
            for(int i=0;i<reserve.length;i++){
                if(lst==reserve[i]||reserve[i]!=0&&Math.abs(lst-reserve[i])==1){
                    answer++;
                    reserve[i]=0;
                    break;
                }
            }
        }
        
        return answer;
    }
}
