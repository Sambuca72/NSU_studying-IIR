module Main where

import Morse
import Test.Tasty
import Test.Tasty.QuickCheck as QC
import Test.Tasty.HUnit

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup "Тесты Morse"
  [ testCase "charToMorse 'a'" $
      charToMorse 'a' @?= Just ".-"
  , testCase "charToMorse 'z'" $
      charToMorse 'z' @?= Just "--.."
  , testCase "stringToMorse \"sos\"" $
      stringToMorse "sos" @?= Just ["...", "---", "..."]
  , testCase "morseToString [\"...\", \"---\", \"...\"]" $
      morseToString ["...", "---", "..."] @?= Just "sos"
  , QC.testProperty "Декодирование кодированного текста" $
      \s -> (stringToMorse s >>= morseToString) == Just s
  ]
