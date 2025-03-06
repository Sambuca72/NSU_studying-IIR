import Text.Regex.Posix

isValid :: String -> Bool
isValid phone = phone =~ "^(\\+7|8)?[ -]?\\(?([0-9]{3})\\)?[ -]?([0-9]{3})[ -]?([0-9]{4})$"

