instance Show Expr where
    show (Num n) = show n
    show Var = "x"
    show (Add ex1 ex2) = "(" ++ show ex1 ++ " + " ++ show ex2 ++ ")"
    show (Sub ex1 ex2) = "(" ++ show ex1 ++ " - " ++ show ex2 ++ ")"
    show (Mul ex1 ex2) ="(" ++ show ex1 ++ "*" ++ show ex2 ++ ")"
data Expr = Num Integer |
    Add Expr Expr |
    Sub Expr Expr |
    Mul Expr Expr |
    Var
    
        
size :: Expr -> Int
size (Num n) = 0
size (Add a b) = 1 +size a +size b
size (Mul a b) = 1 + size a + size base 


eval :: Expr -> Maybe Integer
eval p = case p of
        Num n -> Just n
        Var -> Nothing
        Add a b -> eval a + eval b
        Sub c d ->  eval c - eval d
        Mul a b -> eval a * eval b

funM :: Maybe Integer -> Maybe Integer -> (Integer-> Integer -> Integer)-> Maybe Integer
funM Nothing _ _ = Nothing
funM _ Nothing _ = Nothing
funM (Just x) (Just y) op= Just(x 'op' y)


data Tree a = Empty | Node a (Tree a) (Tree a)
deriving (Show, Eq)

tree1 = Node 3
                (Node 1 Empty (Node 2 Empty Empty))
                (Node 5 (Node 4 Empty Empty) Empty)

tree2 = Node 4
                (Node 2 
                        (Node 1 
                                (Node 0 Empty Empty) 
                                Empty) 
                        (Node 3 Empty Empty))
                (Node 6 
                        (Node 5 Empty Empty) 
                        (Node 7 Empty Empty))