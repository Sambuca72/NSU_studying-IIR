frequencies:: Eq a => [a]-> [(a,Int)]
frequencies [] = []
frequencies (x:xs) = (x,count x xs+1) : frequencies (filter(/=x) xs)
    where 
        count y = length.filter(==y)