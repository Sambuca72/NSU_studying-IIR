import Data.IORef
-- import Data.Char
-- main = do
--     putStrLn "Ваше имя?"
--     firstName <- getLine
--     putStrLn "Ваша фамилия?"
--     lastName <- getLine
--     let bigFirstName = map toUpper firstName
--         bigLastName = map toUpper lastName
--     putStrLn $ "Привет, " ++ bigFirstName ++ " " ++ bigLastName ++ ", как дела?"

-- readUntil::(String->Bool)->IO[String]
-- readUntil f = do
--     line <- getLine
--     if f line
--         return []
--     else do 
--         lines <- readUntil f
--         return (line:lines)




while :: IO Bool -> IO () -> IO ()
while cond op = do
  condition <- cond
  if condition
    then do
      op
      while cond op
    else return ()


main :: IO ()
main = do
  counter <- newIORef 5  
  let cond = do
        c <- readIORef counter
        putStrLn ("Current counter: " ++ show c)
        return (c > 0)
      op = do
        modifyIORef counter (\x -> x - 1)  
        putStrLn "Doing operation..."
  while cond op
