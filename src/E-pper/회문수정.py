def solution(arr, start, end):
    cnt = 0
    
    if(start == end or start>end):
        return cnt
    
    # 배열 원소 비교
    if(arr[start]==arr[end]):
        return (solution(arr, start+1, end-1))
    else:
        if(arr[start]<arr[end]):
            arr[start+1] = arr[start]+arr[start+1]
            cnt += 1
            return solution(arr, start+1, end)
        else:
            arr[end-1] = arr[end]+arr[end-1]
            cnt += 1
            return solution(arr, start, end-1)
