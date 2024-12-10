import math

ans = 0

while True:
    try:
        line = input()
    except EOFError:
        break
    target, ns = line.split(":")
    target = int(target)
    ns = list(map(int, ns.split()))
        
    def backward_pruning(index, target):
        if index == 0:
            return ns[index] == target
        if target % ns[index] == 0 and backward_pruning(index-1, target // ns[index]):
            return True
        length = int(math.log(ns[index], 10)) + 1
        if target % pow(10, length) == ns[index] and backward_pruning(index-1, target // pow(10, length)):
            return True
        if target > ns[index] and backward_pruning(index-1, target - ns[index]):
            return True
        return False

    if backward_pruning(len(ns)-1, target):
        ans += target

print(ans)
