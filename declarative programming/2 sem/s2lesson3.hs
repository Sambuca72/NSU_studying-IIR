import qualified Data.Map as M

headE :: [a] -> Either String a
headE [] = Left "there are no head"
headE (x:xs) = Right x

tailE :: [a] -> Either String [a]
tailE [] = Left "there are no tail"
tailE (x:xs) = Right xs

sumFirst :: Num a => [a] -> Either String a
sumFirst xs = (+) <$> headE xs <*>(tailE xs >>= headE)



data Expr = Num Integer |
    Var Name |
    Bin Op Expr Expr |
    Let Name Expr Expr

data Op = Add | Mul | Sub | Div

type Name = String
data ExprErr = DivisionByZero | UnsetVariable Name
    deriving (Show, Eq)


evalE :: Expr -> M.Map Name Integer -> Either ExprErr Integer
evalE (Num n) _ = Right n
evalE (Var x) env = case M.lookup x env of 
                        Just v -> Right v
                        Nothing -> Left (UnsetVariable x)
evalE (Bin op e1 e2) env = do
    v1 <- evalE e1 env -- v1::
    v2 <- evalE e2 env
    case op of
        Add -> return $ (v1 + v2)
        Mul -> return $ (v1 * v2)
        Sub -> return $ (v1 - v2)
        Div -> if v2 == 0 
                then Left DivisionByZero
                else Right (v1 `div` v2)
evalE (Let x e1 body) env = do
    v <- evalE e1 env
    evalE body (M.insert x v env)
