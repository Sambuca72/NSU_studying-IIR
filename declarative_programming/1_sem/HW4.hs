
ex1 :: [(Integer, Integer, Integer)]
ex1 = [(a,b,c)|
    c <- [1..], 
    a <- [1..c-1],
    b <- [a..c-1],
    a^2+b^2==c^2 ]



collatz:: Integer -> [Integer]
collatz x | x ==1 = [1]
          | even x  = x: collatz ( x `div` 2) 
          | otherwise =  x:collatz(x*3+1)

permutations::  [Integer]->[[Integer]]
permutations [] = [[]]
permutations xs = [x : ps | x <- xs, ps <- permutations (filter (/= x) xs)]

subseq :: [Integer] -> [[Integer]]
subseq []=[[]]
subseq (x:xs) = subseq xs ++ map (x:) (subseq xs)
                
