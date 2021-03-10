def solution(src):
	result = ""
	
	# 앞문자가 1이면 result에 1을 저장하고 배열 형태 변경
	if(src.startswith("1")):
		result += "1"
		src = src[1:]
	
	compare = src[0]
	count = 0 # 연속하는 문자 개수
	
	
	for i in range(len(src)-1):
		if(src[i] != stc[i+1]):
			result += chr('A'+count)
			count=0
		else:
			count += 1
	
	result += chr('A'+count)
  return result
