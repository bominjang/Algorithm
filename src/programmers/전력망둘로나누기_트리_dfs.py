from collections import defaultdict

def dfs(start, visit):
    global count
    visit.append(start)
    count+=1
    
    for t in tree[start]:
        if t not in visit:
            dfs(t, visit)

def solution(n, wires):
    global tree, count
    diff=[] #차이들을 저장
    tree = defaultdict(list)#default값이 list인 딕셔너리 선언. 인접리스트
    
    #트리 만들기
    for a, b in wires:
        tree[a].append(b)
        tree[b].append(a)
    #전선 하나씩 끊으면서 돌기
    for a, b in wires:
        #끊고
        tree[a].remove(b)
        tree[b].remove(a)
        #count 0으로 만들어주고
        count=0
        #개수세기. 출발
        dfs(1, [])
        #차이를 넣기
        diff.append(abs(n-2*count))
        #다시 전선 연결하기
        tree[a].append(b)
        tree[b].append(a)
    #차이들 중 최소값을 return
    return min(diff)
