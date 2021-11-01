from collections import defaultdict

def solution(tickets):
    #특정 타겟의 인접 리스트를 구하는 함수
    def init_graph():
        routes = defaultdict(list)
        for key, val in tickets:
            routes[key].append(val)
        return routes
    
    #스택을 사용한 DFS
    def dfs():
        nonlocal routes
        stack = ["ICN"]
        path = [] #가려는 경로를 저장하는 변수
        while len(stack)>0:
            top = stack[-1]
            #특정 공항에서 출발하는 표가 없다면, 또는, 있지만 티켓을 다 써버린 경우
            if top not in routes or len(routes[top]) == 0:
                path.append(stack.pop()) #pop한 것을 path에 저장
            else:
                stack.append(routes[top].pop(0))#출발하는 표가 있다면, 해당 티켓을 지우고 스택으로 넣음
        return path[::-1]
    
    routes = init_graph()
    for r in routes:
        routes[r].sort()
    answer = dfs()
    return answer
