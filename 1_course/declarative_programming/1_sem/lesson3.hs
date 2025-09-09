plusn' :: Int -> (Int -> Int)
plusn' n = let f x = x+n in f 


plusn'' :: Int -> Int -> Int
plusn'' n x = x + n

sumints :: Int -> Int -> Int
sumints a b = if  b/=(a-1) then b+sumints a (b-1) else 0

sq :: Int -> Int -> Int 
sq a b | b == a = b^2
        | b < a = sq b a
        | otherwise = b^2 +sq a (b-1)

higherOrderSum :: (Int -> Int) -> Int -> Int -> Int
higherOrderSum f a b | a > b = 0
higherOrderSum f a b = f a + higherOrderSum f (a+1) b

pip :: (Int -> Int) -> Int -> Int -> Int
pip f a b |a>b = 0
pip f a b = a + pip f (f a) b
