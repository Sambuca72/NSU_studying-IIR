import qualified Data.Map as M
import Control.Monad.Reader
import Control.Monad.Writer
import Control.Monad.State
import Control.Monad

-- newtype Reader r a = Reader { runReader :: r -> a }

-- reader :: (r -> a) -> Reader r a
-- runReader :: Reader r a -> r -> a

-- ask :: Reader r r
-- asks :: (r -> a) -> Reader r a 
-- local :: (r -> r) -> Reader r a -> Reader r a

data Expr = Num Integer |
    Var Name |
    Bin Op Expr Expr |
    Let Name Expr Expr

type Name = String

data Op = Add | Mul | Sub | Div

apply :: Op -> Integer -> Integer -> Integer
apply Add = (+)
apply Sub = (-)
apply Mul = (*)
apply Div = div

evalR :: Expr -> Reader (M.Map Name Integer) Integer
evalR (Num n) = return n
evalR (Var x) = do
        env <- ask
        case M.lookup x env of
            Just n -> return n
            Nothing -> return 0
evalR (Bin op e1 e2) = do
        v1 <- evalR e1
        v2 <- evalR e2
        return (apply op v1 v2)
-- evalR (Let x e1 e2) = do
--     f <- evalR e1
--     local(M.insert x f) ask

minusLoggerR :: (Show a, Num a) => a -> [a] -> Writer String a
minusLoggerR acc []= do
    tell (show acc)
    return acc
minusLoggerR acc (x:xs)= do
        tell "("
        tell (show x ++ "-")
        y<- minusLoggerR acc xs
        tell ")"
        return (x-y)

sumNotTwice :: [Int] -> Int
sumNotTwice xs = fst $ runState (foldM f2 0 xs) []

f2 :: Int -> Int -> State [Int] Int
f2 acc x = do 
        env <- get
        if x `notElem` env
            then do
                put (x:env)
                return(x+acc)
            else return acc

