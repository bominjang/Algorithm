def solution(arr, start, end):
    global cnt
    if (start == end or start > end):
        return cnt
    if (arr[start] == arr[end]):
        return solution(arr, start + 1, end - 1)
    else:
        if (arr[start] < arr[end]):
            cnt += 1
            arr[start + 1] = arr[start] + arr[start + 1]
            return solution(arr, start + 1, end)
        else:
            cnt += 1
            arr[end - 1] = arr[end] + arr[end - 1]
            return solution(arr, start, end - 1)

    return answer


n = int(input())
arr = input().split(" ")
for i in range(n):
    arr[i] = int(float(arr[i]))

start = int(0);
end = int(n - 1);
cnt = 0

print(solution(arr, start, end))
