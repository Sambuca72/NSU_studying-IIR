lenghts' :: [String]->[Int]
-- lenghts' []=[0]
lenghts' xs = map length xs

doubleAll :: Num a => [a] -> [a]
doubleAll []=[]
doubleAll (x:xs) = (2*x) : doubleAll xs

doubleAll' :: Num a => [a] -> [a]
doubleAll' xs = [x*2 |x <- xs]

doubleAll'' :: Num a => [a]-> [a]
doubleAll'' xs = map (*2) xs

lenght' :: [a]->Integer
lenght' xs = sum (map (\x -> 1) xs)

reverse' :: [a] -> [a]
reverse' = foldl (\acc x -> x:acc)  [] 

last' :: [a] -> a
last' = foldl1(\_ x -> x)

prefixes :: String -> [String]
prefixes  = foldr (\x acc -> []:map (x:) acc) [[]]

suffixes :: String -> [String]
suffixes = foldr (\x acc -> (x:head acc):acc) [[]]