# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
from pip._vendor.distlib.compat import raw_input


def solution(num_arr, n):
    if (len(num_arr) == 1):
        return num_arr[0]

    sorted_arr = sorted(num_arr)
    sol = (sorted_arr[0] + sorted_arr[1]) / 2.0

    for i in range(2, n):
        sol = (sol + sorted_arr[i]) / 2.0
    return sol;



n = int(raw_input())
num_arr = []
for i in range(n):
    num_arr.append(int(raw_input()))
print("%.6f" % solution(num_arr, n))

