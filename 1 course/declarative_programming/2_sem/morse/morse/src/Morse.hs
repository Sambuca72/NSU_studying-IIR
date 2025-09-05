module Morse where

import qualified Data.Map as M

type Morse = String

morseCodes :: M.Map Char Morse
morseCodes = M.fromList [
    ('a', ".-"),
    ('b', "-..."),
    ('c', "-.-."),
    ('d', "-.."),
    ('e', "."),
    ('f', "..-."),
    ('g', "--."),
    ('h', "...."),
    ('i', ".."),
    ('j', ".---"),
    ('k', "-.-"),
    ('l', ".-.."),
    ('m', "--"),
    ('n', "-."),
    ('o', "---"),
    ('p', ".--."),
    ('q', "--.-"),
    ('r', ".-."),
    ('s', "..."),
    ('t', "-"),
    ('u', "..-"),
    ('v', "...-"),
    ('w', ".--"),
    ('x', "-..-"),
    ('y', "-.--"),
    ('z', "--.."),
    ('1', ".----"),
    ('2', "..---"),
    ('3', "...--"),
    ('4', "....-"),
    ('5', "....."),
    ('6', "-...."),
    ('7', "--..."),
    ('8', "---.."),
    ('9', "----."),
    ('0', "-----")
  ]

reverseMorseCode :: M.Map Morse Char
reverseMorseCode = M.fromList $ map (\(k, v) -> (v, k)) $ M.toList morseCodes

charToMorse :: Char -> Maybe Morse
charToMorse c = M.lookup c morseCodes
            -- where
            --   lc = toLower c

stringToMorse :: String -> Maybe [Morse]
stringToMorse = mapM charToMorse

morseToChar :: Morse -> Maybe Char
morseToChar = flip M.lookup reverseMorseCode {-flip :: (a -> b -> c) -> b -> a -> c
                                                flip f x y = f y x-}

morseToString :: [Morse] -> Maybe String
morseToString = mapM morseToChar