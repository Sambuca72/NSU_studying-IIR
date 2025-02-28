data Tree a = Empty | Node a (Tree a) (Tree a)
                deriving (Read, Eq)

instance Show a => Show (Tree a) where
    show tree = drawTree tree 0
      where
        drawTree :: Show a => Tree a -> Int -> String
        drawTree Empty _ = ""
        drawTree (Node value left right) indent =
            replicate indent ' ' ++ show value ++ "\n" ++
            drawTree left (indent + 4) ++
            drawTree right (indent + 4)

tree2 = Node 4                                                              
                (Node 2 
                        Empty
                        (Node 3 Empty Empty))
                (Node 6 
                        (Node 5 Empty Empty)
                        (Node 7 Empty Empty))

-- 4
--     2
--         1
--         3
--     6
--         5
--         7


isMirror :: Tree a -> Tree a -> Bool
isMirror Empty Empty = True
isMirror (Node _ left1 right1) (Node _ left2 right2) =
    isMirror left1 right2 && isMirror right1 left2
isMirror _ _ = False

isSymmetric :: Tree a -> Bool
isSymmetric Empty = True
isSymmetric (Node _ left right) = isMirror left right


insert :: (Ord a) => a -> Tree a -> Tree a
insert x Empty = Node x Empty Empty
insert x (Node value left right)
    | x < value = Node value (insert x left) right
    | x > value = Node value left (insert x right)
    | otherwise = Node value left right  

buildBST :: (Ord a) => [a] -> Tree a
buildBST = foldr insert Empty

deleteMin :: (Ord a) => Tree a -> (Tree a, a)
deleteMin Empty = error "Tree is empty"
deleteMin (Node value Empty right) = (right, value)  
deleteMin (Node value left right) =
    let (newLeft, minValue) = deleteMin left
    in (Node value newLeft right, minValue)


deleteValue :: (Ord a) => a -> Tree a -> Tree a
deleteValue _ Empty = Empty  
deleteValue x (Node value left right)
    | x < value = Node value (deleteValue x left) right  
    | x > value = Node value left (deleteValue x right)  
    | otherwise = deleteNode (Node value left right)    


deleteNode :: (Ord a) => Tree a -> Tree a
deleteNode (Node _ Empty right) = right  
deleteNode (Node _ left Empty) = left    
deleteNode (Node _ left right) =         
    let (rightSubtree, minValue) = deleteMin right
    in Node minValue left rightSubtree
