def peek(st):
    return st[-1]


def solution(tickets):
    tickets.sort(reverse=True)
    routes = dict()

    for t1, t2 in tickets:
        if t1 in routes:
            routes[t1].append(t2)
        else:
            routes[t1] = [t2]
    st = ['ICN'] # 항상 ICN 공항에서 출발하므로
    answer = []

    while st:
        top = peek(st)
        if top not in routes or len(routes[top])==0:
            answer.append(st.pop())
        else:
            st.append(routes[top].pop())

    answer.reverse()

    return answer


