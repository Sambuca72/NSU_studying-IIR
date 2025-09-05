data Expr = Var |
            Num Integer |
            Add Expr Expr |
            Sub Expr Expr

eval :: Expr -> Maybe Integer
eval Var = Nothing
eval (Num n) = Just n
eval (Add e1 e2) = do 
    v1 <- eval e1
    v2 <- eval e2
    return (v1+v2)
eval (Sub e1 e2) = do 
    v1 <- eval e1
    v2 <- eval e2
    return (v1 - v2)

-- eval :: Expr -> Maybe Integer
-- eval Var = Nothing
-- eval (Num n) = Just n
-- eval (Add e1 e2) =
--     eval e1 >>= \v1 ->
--     eval e2 >>= \v2 ->
--     return (v1 + v2)
-- eval (Sub e1 e2) =
--     eval e1 >>= \v1 ->
--     eval e2 >>= \v2 ->
--     return (v1 - v2)


import qualified Data.Map as Map

data Person = Person { name :: String, surname :: String }
    deriving (Show, Eq)

grades :: Map.Map Integer Integer
grades = Map.fromList [(124001, 2), (124002, 4)]

studentIds :: Map.Map String Integer
studentIds = Map.fromList [("Ivanov I.", 124001), ("Petrov P.", 124002),
("Sidorova S.", 124003)]

parse :: String -> Maybe Person
parse s = case words s of
[name, surname] -> Just (Person name surname)
_ -> Nothing

checkGrade :: String -> Maybe Integer
checkGrade input = do
    person <- parse input
    studetId 