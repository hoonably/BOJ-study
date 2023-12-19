import heapq
import sys

N = int(sys.stdin.readline())
heap1 = []
for _ in range(N):
    get_num = int(sys.stdin.readline())
    if get_num != 0:
        # push
        heapq.heappush(heap1, get_num)
    else:
        if len(heap1)==0:
            print(0)
        else:
            # pop할때 최소를 pop한다.
            print(heapq.heappop(heap1))
