import time
from functools import lru_cache
def record_time(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"Execution time: {end - start}")
        return result
    return wrapper

@record_time
def fib2(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
        print(a)                                      
    return a

@record_time
@lru_cache()
def fib1(n):
    if n in (1, 2):
        return 1
    return fib1(n - 1) + fib1(n - 2)


for i in range(1, 100):
    print(i, fib1(i))


