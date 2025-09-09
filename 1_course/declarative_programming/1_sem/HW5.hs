myOr :: [Bool] -> Bool
myOr = foldr (||) False

myAll :: (a -> Bool) -> [a] -> Bool
myAll p = foldr (\x acc -> p x && acc) True

myMap :: (a -> b) -> [a] -> [b]
myMap f = foldr (\x acc -> f x : acc) []

myConcatMap :: (a -> [b]) -> [a] -> [b]
myConcatMap f = foldr (\x acc -> f x ++ acc) []

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter p = foldr (\x acc -> if p x then x : acc else acc) []

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition p = foldr (\x (ts, fs) -> if p x then (x:ts, fs) else (ts, x:fs)) ([], [])

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip = foldr (\(x, y) (xs, ys) -> (x:xs, y:ys)) ([], [])

myNull :: [a] -> Bool
myNull = foldr (\_ _ -> False) True

myIntersperse :: a -> [a] -> [a]
myIntersperse sep = foldr (\x acc -> x : if null acc then [] else sep : acc) []

myGroup :: Eq a => [a] -> [[a]]
myGroup = foldr (\x acc -> if not (null acc) && x == head (head acc)
                            then (x : head acc) : tail acc
                            else [x] : acc) []

-- lagrange :: [(Double, Double)] -> (Double -> Double)
-- lagrange points x = sum [y * li x | (xi, y) <- points, let li x = product [(x - xj) / (xi - xj) | (xj, _) <- points, xj /= xi]]


li :: Double -> (Double, Double) -> [(Double, Double)] -> Double
li x (xi, _) points = foldl (\acc (xj, _) -> if xj /= xi then acc * (x - xj) / (xi - xj) else acc) 1 points


lagrange :: [(Double, Double)] -> (Double -> Double)
lagrange points x = foldl (\acc p -> acc + snd p * li x p points) 0 points



-- f = foldr (-) 0
-- g = foldl (-) 0
-- 1)f, g :: Num a => [a] -> a
-- 2)    -- xs = [1, 2, 3]
    -- f xs = foldr (-) 0 [1, 2, 3] = 1 - (2 - (3 - 0)) = 1 - (2 - 3) = 1 - (-1) = 2
    -- g xs = foldl (-) 0 [1, 2, 3] = ((0 - 1) - 2) - 3 = -1 - 2 - 3 = -6
-- 3)ys = [0, 0, 0]
-- f ys = g ys = 0
-- 4)Для равенства результатов f и g необходимо, чтобы либо:

-- элементы списка [a, b, c] вычитались одинаково независимо от порядка операций;
-- либо результат каждой операции сдвига свёртки привёл к одному и тому же значению.
-- Простейшее решение:

-- Если a = b = c = 0, тогда f [a, b, c] == g [a, b, c] == 0.
-- Другие возможные случаи требуют одинаковой симметрии относительно операций, например:

-- Если a = b = c, то результат f [a, b, c] и g [a, b, c] тоже будет одинаковым.