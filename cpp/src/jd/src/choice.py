import threading
import time

l = [i for i in range(100000)]
sum_=0

def single():
    global sum_
    for i in l:
        sum_+=i
    
    return sum_


def multiple(n):
    step = 100000//n
    
    def process(start,end):
        global sum_
        tmp = 0
        for i in range(start,end):
            tmp+=l[i]
        
        sum_+=tmp
    t = []
    for i in range(n):
        tt = threading.Thread(target=process,args=(i*step,(i+1)*step))
        tt.start()
        t.append(tt)
    
    for s in t:
        s.join()
    
    return sum_




if __name__ == "__main__":
    start_time = time.time()
    print(single())
    end_time = time.time()
    print("single threa costs: ",end_time-start_time)
    sum_=0

    start_time = time.time()
    print(multiple(5))
    end_time = time.time()
    print("multiple threads: ",end_time-start_time)

    '''
    4999950000
    single threa costs:  0.008413553237915039
    4999950000
    multiple threads:  0.009425640106201172
    '''