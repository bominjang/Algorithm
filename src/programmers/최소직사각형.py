import numpy as np
def solution(sizes):
    return max(max(x) for x in sizes)* max(min(x) for x in sizes)
#긴 길이들 중 최댓값, 짧은길이들 중 최댓값
