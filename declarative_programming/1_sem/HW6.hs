import Data.Char (chr, ord, isAlpha, isUpper, isSpace,toLower, toUpper,)
import Data.List (nub, sort)

caesarEncrypt :: String -> Int -> String
caesarEncrypt text shift = map (shiftChar shift) text

shiftChar :: Int -> Char -> Char
shiftChar shift ch
    | isAlpha ch = chr $ base + mod (ord ch - base + shift) 26
    | otherwise  = ch
  where
    base = if isUpper ch then ord 'A' else ord 'a'

caesarDecrypt :: String -> Int -> String
caesarDecrypt text shift = caesarEncrypt text (-shift)

caesarCrack :: String -> [String]
caesarCrack text = [caesarDecrypt text shift | shift <- [1..25]]


isUnique :: String -> Bool
isUnique str = length str == length (nub str)

removeVowels :: String -> String
removeVowels = filter (`notElem` "aeiouAEIOU")

isAnagram :: String -> String -> Bool
isAnagram str1 str2 = sort (normalize str1) == sort (normalize str2)
  where
    normalize = map toLower . filter isAlpha

longestCommonPrefix :: [String] -> String
longestCommonPrefix [] = ""
longestCommonPrefix (x:xs) = foldl commonPrefix x xs
  where
    commonPrefix [] _ = []
    commonPrefix _ [] = []
    commonPrefix (x:xs) (y:ys)
      | x == y    = x : commonPrefix xs ys
      | otherwise = []

anagramsFor :: String -> [String] -> [String]
anagramsFor word = filter (\w -> isAnagram word w && map toLower word /= map toLower w)

mySplit :: Char -> String -> [String]
mySplit _ [] = []
mySplit delim str = filter (not . null) (split' str)
  where
    split' [] = [""]
    split' (c:cs)
      | c == delim = "" : split' cs
      | otherwise = (c : head rest) : tail rest
      where
        rest = split' cs

