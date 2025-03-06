module Main where

import System.Environment (getArgs)
import System.IO (hFlush, stdout)
import Morse (charToMorse, stringToMorse, morseToChar, morseToString)
import Data.Maybe (fromMaybe)
import Data.List (intercalate)

main :: IO ()
main = do
    args <- getArgs
    case args of
        ["to"]   -> processInput convertToMorse
        ["from"] -> processInput convertFromMorse
        _        -> putStrLn "Usage: Main.exe to|from"

processInput :: (String -> String) -> IO ()
processInput converter = do
    putStrLn "Введите строки (пустая строка для выхода):"
    processLines converter

processLines :: (String -> String) -> IO ()
processLines converter = do
    putStr "> "
    hFlush stdout
    line <- getLine
    if null line
        then return ()
        else do
            putStrLn $ converter line
            processLines converter

convertToMorse :: String -> String
convertToMorse input =
    case stringToMorse input of
        Just morse -> intercalate " " morse
        Nothing    -> "Ошибка: невозможно преобразовать"

convertFromMorse :: String -> String
convertFromMorse input =
    case morseToString (words input) of
        Just text -> text
        Nothing   -> "Ошибка: некорректный код Морзе"
