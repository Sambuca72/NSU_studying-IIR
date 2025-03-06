module Main where

import Test.Hspec
import Test.QuickCheck
import Morse
import Data.Maybe (isJust)
import Data.Char (toLower)

main :: IO ()
main = hspec $ do
  describe "charToMorse" $ do
    it "кодирует 'a' в '.-'" $
      charToMorse 'a' `shouldBe` Just ".-"
      
    it "кодирует 'z' в '--..'" $
      charToMorse 'z' `shouldBe` Just "--.."

    it "возвращает Nothing для пробела" $
      charToMorse ' ' `shouldBe` Nothing

  describe "stringToMorse" $ do
    it "кодирует 'sos' в ['...', '---', '...']" $
      stringToMorse "sos" `shouldBe` Just ["...", "---", "..."]

    it "возвращает Nothing для строки с пробелами" $
      stringToMorse "hello world" `shouldBe` Nothing

  describe "morseToChar" $ do
    it "декодирует '...' в 's'" $
      morseToChar "..." `shouldBe` Just 's'

    it "возвращает Nothing для неправильного кода Морзе" $
      morseToChar "-.-.-" `shouldBe` Nothing

  describe "morseToString" $ do
    it "декодирует ['...', '---', '...'] в 'sos'" $
      morseToString ["...", "---", "..."] `shouldBe` Just "sos"

    it "возвращает Nothing для некорректного списка" $
      morseToString ["...", "---", "--.-."] `shouldBe` Nothing