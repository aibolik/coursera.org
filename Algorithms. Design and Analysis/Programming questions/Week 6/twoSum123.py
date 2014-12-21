from multiprocessing import Pool
num_set = set()
num = 0
with open('algo1_programming_prob_2sum.txt') as f:
    for line in f:
        num_set.add(int(line))
    def find_2sum(t):
        global num_set
        for x in num_set:
            if x != t-x and t-x in num_set:
                print str(t) + ' found'
                return 1
        return 0

p = Pool(8)
print sum( p.map(find_2sum, range(-10000, 10001), chunksize=100) )
