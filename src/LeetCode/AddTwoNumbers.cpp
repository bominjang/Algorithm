/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//1. 연결리스트 시작부 2개의 노드 주소를 입력 받음.
//2. 둘 중 한개 리스트의 끝까지 반복.
//2.1. 인덱스 번째에 해당하는 양쪽 노드의 합을 구함.
//2.2. 합이 한자리 수를 넘어가는지 확인
//2.2.1. 넘어가면 -> 해당 노드 이후 다음 노드가 있는지 확인
//2.2.1.1. 있으면 다음 노드 값과 더하고 다시 자릿수 확인 반복
//2.2.1.2. 없으면 다음 노드를 carry값을 가진 노드로 만듦
//2.3. 다음 인덱스 노드로 넘어간다.
//3. 결과 연결리스트를 반환한다.
//4. 끝낸다.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answerNode = l1;
        
        while(l2 != 0){
            l1->val += l2->val;
            
            checkDigit(l1);
            
            if(l2->next != 0 && l1->next == 0){
                l1->next = new ListNode(0);
            }
            
            l1 = l1->next;
            l2 = l2->next;
            
        }
        
        return answerNode;
    }
    
    void checkDigit(ListNode* l1){
        if(l1->val >= 10){
            if(l1->next != 0){
                l1-> val = l1->val % 10;
                l1->next->val +=1;
                checkDigit(l1->next);
            }else{
                l1->val = l1->val % 10;
                l1->next = new ListNode(1);
                checkDigit(l1->next);
            }
        }
    }
};

//https://itdar.tistory.com/53 참고
