import Control.Monad.Trans.Class
import Control.Monad.Trans.State
import Control.Monad.Trans.Writer
import Data.Array
import Data.Graph
import Text.XHtml (vspace)

data Color = White | Gray | Black deriving (Eq, Show)

type Coloring = Array Vertex Color

gr :: Graph
gr = buildG (0, 2) [(0, 1), (1, 2), (2,0)]

defaultColoring :: Array Int Color
defaultColoring = array (0, 6) [(i, White) | i <- [0 .. 6]]

{-
Напишите функцию обхода графа в глубину, используя монаду StateT и монаду Writer.
Функция должна возвращать True, если в процессе обхода был найден цикл, и False в противном случае.
Выводите в лог информацию о посещенных вершинах.
Лог должен иметь следующий формат (для графа gr):
"Visiting node 0;Visiting node 6;Visiting node 4;Visiting node 2;Visiting node 3;
Again visiting 6! Found cycle!;Left node 3;Left node 2;Left node 4;Visiting node 5;
Visiting node 1;Left node 1;Left node 5;Left node 6;Left node 0;"
-}

deepFirst :: Graph -> Vertex -> (StateT Coloring) (Writer String) Bool
deepFirst g v = do
    coloring <- get
    case coloring ! v of 
        White -> do
            modify (// [(v, Gray)])
            lift $ tell ("Visiting node "++show v++";")
            results <- mapM (\w -> deepFirst g w) (g ! v)
            modify(// [(v, Black)])
            lift $ tell ("Left node "++show v ++";")
            return (or results) 
        Gray -> do 
            lift $ tell ("Again visited " ++ show v++"!")
            return True

        Black -> return False
    

{-
Используя предыдущую функцию, проверьте есть ли в графе циклы
-}
hasCycles :: Graph -> Bool
hasCycles g = fst $ runWriter $ evalStateT (deepFirst gr 0) defaultColoring 
-- (checkAll g) (defaultColoring // [(v, White) | v <- vertices g])
    -- where
    --     checkAll :: Graph -> StateT Coloring (Writer String) Bool 
    --     checkAll g = do
    --         let vs = vertices g
    --         results <- mapM (deepFirst g) vs
    --         return (or results)


{-
Напишите функцию, которая строит список вершин
графа в порядке обхода в ширину (начиная с
заданной)
-}
breadthFirst :: Graph -> Vertex -> [Vertex]
breadthFirst g v = undefined