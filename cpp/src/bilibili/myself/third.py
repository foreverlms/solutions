s = input()

num = [int(i) for i in s.split(' ')[0:-1]]
k = int(input())

# for i in range(len(num)):
#     if i+k > len(num):
#         for j in range(0,len(num)-i):
#             print(str(num[len(num)-j])+"->")
#     else:
#         for j in range(k):
#             print(str(num[i+k-j])+"->")
#     i+=k

length = len(num)
