from heapq import heappop, heappush
import sys

n = int(sys.stdin.readline())
left_pq, right_pq = [], []
for i in range(n):
    new_num = int(sys.stdin.readline())
    if len(left_pq) == len(right_pq):
        heappush(left_pq, -new_num)
    else:
        heappush(right_pq, new_num)
        
    if left_pq and right_pq and -left_pq[0] > right_pq[0]:
        left_pop, right_pop = heappop(left_pq), heappop(right_pq)
        heappush(left_pq, -right_pop)
        heappush(right_pq, -left_pop)
        
    print(-left_pq[0])