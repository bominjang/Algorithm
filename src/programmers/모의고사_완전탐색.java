import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    int[] score;
    public int[] solution(int[] answers) {
        int[][] supoja = new int[][]{{1,2,3,4,5},
                {2,1,2,3,2,4,2,5},
                {3,3,1,1,2,2,4,4,5,5}};
        score = new int[supoja.length];

        checkAnswers(answers, supoja);

        int max = findMax();
        if(max==0){
            return new int[] {};
        }

        List<Integer> winner = new ArrayList<Integer>();
        for (int i = 0; i < 3; i++) {
            if (score[i] == max) {
                winner.add(i);
            }
        }

        int[] answer = new int[winner.size()];
        for (int i = 0; i < winner.size(); i++) {
            answer[i] = winner.get(i) + 1;
        }
        Arrays.sort(answer);

        return answer;
    }

    private int findMax() {
        int max = 0;
        for (int i = 0; i < 3; i++) {
            if (score[i] > max) {
                max = score[i];
            }
        }
        if(max==0){ return 0;}

        return max;
    }

    private void checkAnswers(int[] answers, int[][] supoja) {
        for(int i=0;i<answers.length;i++){
            for(int j =0;j<supoja.length;j++){
                if(answers[i]==supoja[j][i % supoja[j].length]){
                    score[j]++;
                }
            }
        }
    }
}
