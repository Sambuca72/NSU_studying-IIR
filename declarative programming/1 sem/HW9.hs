import qualified Data.Map as Map
import System.IO
import Text.Regex.Posix 
import Data.Maybe 
import Data.List

type Phonebook = Map.Map String String

-- Основное меню программы
main :: IO ()
main = do
    putStrLn "Телефонный справочник запущен!"
    phonebookMenu Map.empty

-- Основное меню для взаимодействия
phonebookMenu :: Phonebook -> IO ()
phonebookMenu phonebook = do
    putStrLn "\nВыберите действие:"
    putStrLn "1. Добавить контакт"
    putStrLn "2. Найти контакт"
    putStrLn "3. Удалить контакт"
    putStrLn "4. Сохранить справочник в файл"
    putStrLn "5. Загрузить справочник из файла"
    putStrLn "6. Выход"
    putStrLn "Введите номер действия: "
    choice <- getLine
    putStrLn "ok"
    case choice of
        "1" -> addContact phonebook
        "2" -> findContact phonebook
        "3" -> deleteContact phonebook
        "4" -> saveToFile phonebook
        "5" -> loadFromFile phonebook
        "6" -> putStrLn "Завершение работы программы. До свидания!"
        _   -> putStrLn "Неверный выбор, попробуйте снова." >> phonebookMenu phonebook

-- 1. Добавление контакта
addContact :: Phonebook -> IO ()
addContact phonebook = do
    putStrLn "Введите имя контакта: "
    name <- getLine
    if Map.member name phonebook
        then do
            putStrLn "Контакт с таким именем уже существует. Обновить запись? (y/n)"
            confirm <- getLine
            if confirm == "y" then do
                putStrLn "Нельзя что ли сразу записать правильный номер????"
                addNumber name phonebook           
            else phonebookMenu phonebook
        else addNumber name phonebook
  where
    addNumber name pb = do
        putStrLn "Введите номер телефона: "
        phone <- getLine
        if isValid phone
            then do
                let formattedPhone = formatPhone phone
                let updatedBook = Map.insert name formattedPhone pb
                putStrLn $"Контакт "++ name ++ " успешно добавлен/обновлен!"
                putStrLn $ "\nНомер - " ++ formattedPhone
                phonebookMenu updatedBook
            else do
                putStrLn "Неверный формат номера.Попробуйте снова."
                addNumber name pb

-- 2. Поиск контакта
findContact :: Phonebook -> IO ()
findContact phonebook = do
    putStrLn "Введите имя для поиска: "
    name <- getLine
    case Map.lookup name phonebook of
        Just number -> putStrLn $ "Номер телефона: " ++ number
        Nothing     -> putStrLn "Контакт не найден. Это точно не эффект Манделы?"
    phonebookMenu phonebook

-- 3. Удаление контакта
deleteContact :: Phonebook -> IO ()
deleteContact phonebook = do
    putStrLn "Введите имя контакта для удаления: "
    name <- getLine
    if Map.member name phonebook
        then do
            let updatedBook = Map.delete name phonebook
            putStrLn "Контакт успешно удален!"
            phonebookMenu updatedBook
        else do
            putStrLn "Контакт не найден."
            phonebookMenu phonebook


-- 4. Сохранение справочника в файл
saveToFile :: Map.Map String String -> IO ()
saveToFile phoneBook = do
    putStrLn "Файл для сохранения:"
    fileName <- getLine
    writeFile fileName (unlines [name ++ ":" ++ number | (name, number) <- Map.toList phoneBook])
    putStrLn "Справочник сохранён"
    phonebookMenu phoneBook

    
-- 5. Загрузка спраавочника из файла
-- loadFromFile :: IO ()
-- loadFromFile = do
--     putStrLn "Данные в файле должны быть записаны в формате ИМЯ: НОМЕР.Файл для загрузки:"
--     fileName <- getLine
--     contents <- readFile fileName
--     let phoneBook = Map.fromList [parseLine line | line <- lines contents, not (null line)]
--     putStrLn "Справочник загружен"
--     phonebookMenu phoneBook
--   where
--     parseLine line = case break (== ':') line of
--         (name, ':' : number) -> (name, number)
--         _                    -> ("", "")

loadFromFile :: Phonebook->IO ()
loadFromFile phonebook = do
    putStrLn "Данные в файле должны быть записаны в формате ИМЯ:НОМЕР. Введите имя файла для загрузки:"
    fileName <- getLine
    contents <- readFile fileName
    let linesList = lines contents
    let parsed = map parseLine linesList
    let invalidLines = [(line, lineNumber) | (lineNumber, (line, Nothing)) <- zip [1..] (zip linesList parsed)]
    if null invalidLines
        then do
            let phoneBook = Map.fromList [(name, number) | Just (name, number) <- parsed]
            putStrLn "Справочник загружен"
            phonebookMenu phoneBook
        else do
            putStrLn "Ошибка: обнаружены некорректные строки в файле:"
            mapM_ printInvalidLine invalidLines
            phonebookMenu phonebook
  where
    parseLine :: String -> Maybe (String, String)
    parseLine line = case break (== ':') line of
        (name, ':' : number) | not (null name) && not (null number) -> Just (name, number)
        _ -> Nothing

    printInvalidLine :: (String, Int) -> IO ()
    printInvalidLine (line, lineNumber) =
        putStrLn $ "Строка " ++ show lineNumber ++ ": \"" ++ line ++ "\" содержит некорректные данные."



-- Проверка номера телефона на соответсвие стандарту
isValid :: String -> Bool
isValid phoneNumber = phoneNumber =~ pattern
  where
    -- Регулярное выражение для проверки номера
    pattern :: String
    pattern = "^(\\+7|8)?[ -]?\\(?([0-9]{3})\\)?[ -]?([0-9]{3})[ -]?([0-9]{4})$"


-- Преобразование номера к единому формату
formatPhone :: String -> String
formatPhone phone =
    let digits = filter (`elem` ['0'..'9']) phone
    in case digits of
        ('8':rest) -> "+7-" ++ formatRest rest
        ('7':rest) -> "+7-" ++ formatRest rest
        _          -> "+7-" ++ formatRest digits
  where
    formatRest digits =
        let (a, b) = splitAt 3 digits
            (c, d) = splitAt 3 b
        in a ++ "-" ++ c ++ "-" ++ d

