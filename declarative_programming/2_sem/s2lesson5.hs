import Control.Monad.State
import Control.Monad.Writer
-- import Control.Monad.Maybe
import qualified Data.Map as M
-- import Control.Monad.Class





{-
Реализуйте функцию paren таким образом, чтобы функция parensMatch, проверяющая правильность расстановки скобок в строке, работала корректно.
ghci>parensMatch "()"
True
ghci>parensMatch "("
False
ghci>parensMatch "())"
False
ghci>parensMatch "(()(()()))"
True
ghci>parensMatch "(()((()))"
False
ghci>parensMatch "(()))("
False
-}

paren :: Char -> State Int ()
paren s = do
    cnt <- get
    case s of
        '(' -> put (cnt + 1)
        ')' -> put (cnt + 1)
        _ -> return ()

parensMatch :: String -> Bool
parensMatch s = count == 0
  where (_,count) = runState (mapM_ paren s) 0


-- {-
-- Реализуйте функции push, pop и empty для работы со стеком, который реализован с помощью списка, хранящегося в состоянии.
-- -}

push :: a -> State [a] ()
push a = do 
  st <- get
  put (a:st)

pop :: State [a] a
pop = do
  st <- get
  case st of
    [] -> error "Empty list"
    _ -> do 
         put(tail st)
         return (head st)
  

empty :: State [a] Bool
empty = do
  st <- get
  case st of
    [] -> return True
    _ -> return False


stack :: State [Int] (Int,Int,Int)
stack = do
  -- push 42
  push 43
  push 44
  x <- pop
  y <- pop
  z <- pop
  return (x,y,z)

r = evalState stack []

-- {-
-- Напишите функцию, которая печатает значение из состояния с приветствием, 
-- увеличивает его на 1 и возвращает исходное значение, преобразованное в строку:
-- ghci> runStateT sPrintIncAccum 10
-- Hello, 10
-- ("10",11)
-- -}
sPrintIncAccum :: (Num a, Show a) => StateT a IO String
sPrintIncAccum = do 
  st <- get 
  lift (print("Hello" ++ show st))
  put (st + 1)
  return (show st)


data Expr = Num Integer | 
            Var Name |
            Bin Op Expr Expr | 
            Let Name Expr Expr
data Op = Add | Mul | Sub | Div
          
type Name = String

instance Show Op where
    show Add = " + "
    show Mul = " * "
    show Sub = " - "
    show Div = " / "

apply :: Op -> Integer -> Integer -> Integer
apply Add = (+)
apply Sub = (-)
apply Mul = (*)
apply Div = div

instance Show Expr where
    show (Num n) = show n
    show (Var x) = x
    show (Bin op e1 e2) = "(" ++ show e1 ++ show op ++ show e2 ++ ")"
    show (Let x e1 e2) = "(let " ++ x ++ " = " ++ show e1 ++ " in " ++ show e2 ++ ")"



-- {-
-- Для выражений напишите функцию eval, которая
-- - вычисляет значение выражения, если это возможно (поскольку окружение не задано, в выражении не должно быть переменных)
-- - логгирует вычисления

-- Чем отличаются варианты 11 и 12?

-- ghci> e = (Bin Add (Bin Add (Num 2) (Num 3)) (Num 1))
-- ghci> e
-- ((2 + 3) + 1)
-- ghci> runWriterT (eval11 e)
-- Just (6,"add 2 3;add 5 1;")
-- ghci> runWriter $ runMaybeT (eval12 e)
-- (Just 6,"add 2 3;add 5 1;")
-- ghci> runWriterT (eval11 v)
-- Nothing
-- ghci> runWriter $ runMaybeT (eval12 v)
-- (Nothing,"add 2 3;var x is not defined")
-- -}

a = Num 5
b = Var "p"

eval11 :: Expr -> WriterT String Maybe Integer
eval11 (Num n) =  return n
-- eval11 (Var x) =  x
eval11 (Bin o e1 e2) = do
  v1<- eval11 e1
  v2<- eval11 e2
  case o of
    Add -> 
    Mul ->
    Sub ->
    Div ->


-- eval12 :: Expr -> MaybeT (Writer String) Integer
-- eval12 _ = undefined

-- ---
-- {-
-- Напишите функцию eval, которая вычисляет значение выражения в **окружении**, **если это возможно**. 
-- Используйте `Reader/ReaderT` и `Maybe/MaybeT`

-- -}
-- type Env = M.Map Name Integer
-- eval2 = undefined

-- {-
-- Добавьте логгирование к предыдущей функции.
-- -}

-- eval3 = undefined