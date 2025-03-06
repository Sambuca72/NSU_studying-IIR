import System.IO
import Text.Regex.PCRE


regexPattern :: String
regexPattern = "[^{}] ( { ( [^{}]+ | (?1) ) } ) [^{}]"


findBalancedWords :: String -> [String]
findBalancedWords content =
    getAllTextMatches (content =~ regexPattern :: AllTextMatches [] String)


main :: IO ()
main = do
    putStrLn "Программа для поиска сбалансированных слов в фигурных скобках."
    loop


loop :: IO ()
loop = do
    putStrLn "Введите команду: 'load' для чтения файла, 'kill' для выхода."
    putStr "> "
    hFlush stdout -- 
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

