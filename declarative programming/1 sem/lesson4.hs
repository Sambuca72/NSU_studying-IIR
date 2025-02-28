s :: [Int]
s=[]
s1:: [Int]
s1 = [1]

s2:: [Int]
s2=1:(2:[])

s3 = 5 : s2

c :: (Int, Char, Double)
c = (1,'a',1.25)

-- fe :: [a]-> abs
-- fe [] = error "empty"
-- fe (x:xs) = x

se :: [a]-> a
se [] = error "empty"
se (x:y:xs)=y

sum' :: [Int] -> Int
sum' [] = 0
sum' (x : xs) = x + sum' xs

replicate' :: Int -> a -> [a]
replicate' 0 _ = []
replicate' n x = x : replicate' (n - 1) x

