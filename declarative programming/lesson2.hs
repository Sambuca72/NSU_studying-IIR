factorial :: Integer->Integer
factorial n | n<0 = error "negatibe n!"
factorial 0 = 1
factorial 1 = 1
factorial x = x * factorial (x-2)

faK :: Integer ->Integer-> Integer
faK m n | m==0 = n+1
faK m n| m>0 && n==0 = faK (m-1) 1
faK m n| m>0 && n>0 = faK (m-1) (faK m (n-1))

fib :: Integer -> Integer 
fib 0 = 0
fib 1 = 1
fib n = fib (n-2) + fib (n-1)

fibi :: Integer -> Integer
fibi 0 = 0 
fibi 1 = 1
fibi (-1) = 1
fibi n = fibi(n+2) - fibi(n+1)

