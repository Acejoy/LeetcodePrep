import math 

def uniquePaths(m,n):
    return math.factorial(m+n-1-1)//(math.factorial(m-1)*math.factorial(n-1))

if __name__ == "__main__":
    rows = 3
    cols = 7
    print(f'The no of unique paths are:{uniquePaths(rows,cols)}.')