-- concat'[]=[]
-- concat'(x:xs)=x++concat'xs

foldr'::(a->b->b) -> b ->[a] ->b
foldr' f c [] = c
foldr' f c (x:xs)=x`f`(foldr' f c xs)

lenght :: [a] -> Integer
lenght xs = foldr (\x xs -> xs+1) 0 xs -- \ - обозначает что задам функцию

sumSquares :: [Integer]-> Integer
sumSquares xs = foldr (\x xs -> xs+x^2) 0 xs
    
sumPosSquares :: [Integer]-> Integer
sumPosSquares xs = foldr (\x xs -> if x>0 then xs+x^2 else xs + 0) 0 xs