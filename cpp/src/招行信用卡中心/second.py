# n = int(input())

# tasks = []

# for i in range(n):
#     s = [int(i) for i in input().split()]
#     if s!=[0] :
#         tasks.append(s[1:])
#     else: tasks.append([])

# print(tasks)
# label = [0 for i in range(n)]

# out = []

# def do_task(i):
#     if label[i] == 1:
#         return 0
#     else:
#         label[i] = 1
#         todo = 1
#         for x in tasks[i]:
#             if label[x-1] == 0:
#                 todo+=do_task(x-1)
#         return todo

# for i,x in enumerate(tasks):
#     todo = do_task(i)
#     out.append(todo)

# tmp = ""

# for i in range(len(out)):
#     tmp = tmp+str(out[i])+" "
# print(tmp)