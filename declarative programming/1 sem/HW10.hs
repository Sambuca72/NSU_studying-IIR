import System.IO
import Text.Regex.Posix

-- Функция для проверки баланса скобок
isBalanced :: String -> Bool
isBalanced = go 0
  where
    go 0 [] = True          -- Баланс соблюдён
    go n [] = False         -- Если остались открытые скобки, баланс нарушен
    go n ('{':xs) = go (n + 1) xs
    go n ('}':xs) = n > 0 && go (n - 1) xs
    go n (_:xs) = go n xs   -- Пропускаем все остальные символы

-- Функция для поиска слов с равным количеством фигурных скобок
findBalancedWords :: String -> [String]
findBalancedWords content =
    filter isBalanced matches
  where
    matches = getAllTextMatches (content =~ "\\{+[^{}]+\\}+" :: AllTextMatches [] String)

-- Основная программа
main :: IO ()
main = do
    putStrLn "Программа для поиска сбалансированных слов в фигурных скобках."
    loop

-- Бесконечный цикл
loop :: IO ()
loop = do
    putStrLn "Введите команду: 'load' для чтения файла, 'kill' для выхода."
    putStr "> "
    hFlush stdout 
    command <- getLine
    case command of
        "kill" -> putStrLn "Программа завершена."
        "load" -> do
            putStrLn "Чтение файла 'text.txt'..."
            content <- readFile "text.txt"
            let matches = findBalancedWords content
            if null matches
                then putStrLn "Совпадений не найдено."
                else do
                    putStrLn "Найденные слова:"
                    mapM_ putStrLn matches
            loop
        _ -> do
            putStrLn "Неизвестная команда. Попробуйте снова."
            loop
