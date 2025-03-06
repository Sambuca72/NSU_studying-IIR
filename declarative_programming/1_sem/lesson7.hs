norm::[Double]->Double
norm xs = sqrt(foldl(\acc x -> acc+x^2) 0 xs)

groupElem1 :: Eq a => [a] -> [[a]]
groupElem1 [] = []
groupElem1 [x]=[[x]]
groupElem1 (x1:x2:xs) | x1==x2 = (x1:g):gs
                      | otherwise = [x1] :g :gs
    where (g:gs) = groupElem1 (x2:xs)

groupElem2 :: Eq a => [a] -> [[a]]
groupElem2 [] = []
groupElem2 (x:xs) = foldr (\x acc -> if (not . null) acc && x == head (head acc)
                                     then (x : head acc) : tail acc
                                     else [x] : acc) [] (x:xs)

groupElem3 :: Eq a => [a]->[[a]]
groupElem3 (x:xs) = x: takeWhile (==x) xs : groupElem3 (dropWhile (==x) xs)

import Data.Char (toUpper)

capitalize :: String -> String
capitalize = unwords . map capitalizeWord . words
  where
    capitalizeWord [] = []                     
    capitalizeWord (x:xs) = toUpper x : xs     