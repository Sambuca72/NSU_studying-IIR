-- revn1 :: Integer -> Integer
-- revn1 =  read. reverse . show -- функция принимает на вход целочисленное число, переводит его в строку, переворачивает, после чего возвразает в типе integer

reve :: Integer -> Integer
reve n = kk n 0
  where
    kk 0 k = k
    kk x k = kk ( div x  10) (k * 10 + ( mod x 10))

del::Integer-> Integer -> Bool
del n 1 = True
del n m = if mod n m == 0
        then False
        else del n (m-1)

isprimen2 :: Integer -> Bool
isprimen2 n | n<2 = False
isprimen2 2 = True
isprimen2 3 = True
isprimen2 n = del n (n-1)

bibipn3 :: Integer -> Integer
bibipn3 n = fib n 0 1
  where
    fib 0 a _ = a
    fib n a b = fib (n-1) b (a + b)


geomimn4 :: Double -> Double -> Double -> Double
geomimn4 q n 0 = 0
geomimn4 q b n = b + (geomimn4 q (q*b) (n-1))

geomimn5 :: Double -> Double -> Double 
geomimn5 q b = if abs(q)<1 then b/(1-q) else error "-"

c :: (Double,Double,Double, Double)->Double
c (q, b, e, n) = if abs(q) < 1 then
    if abs(geomimn4 q b n - b / (1 - q)) < e then n
    else c(q, b, e, n + b)
  else error "pupu"

geomimn6 :: Double -> Double -> Double -> Double
geomimn6 q b e = c(q, b, e, 0)
