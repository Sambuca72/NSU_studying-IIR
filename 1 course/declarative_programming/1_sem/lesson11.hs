data Tree a = Empty | Node a (Tree a) (Tree a)
    deriving (Show, Eq)

tree1 = Node 6
                (Node 4 Empty Empty)
                (Node 3
                        (Node 2 Empty Empty)
                        (Node 5 Empty Empty))

tree2 = Node 4
                (Node 2 
                        (Node 1 Empty Empty)
                        (Node 3 Empty Empty))
                (Node 6 
                        (Node 5 Empty Empty)
                        (Node 7 Empty Empty))
valAtRoot :: Tree a -> Maybe a
valAtRoot Empty = Nothing
valAtRoot (Node x _ _) = Just x

treeSize::Tree a->Int
treeSize Empty = 0
treeSize (Node x l r ) = 1+treeSize r +treeSize r

treeVal ::Num a=> Tree a -> a
treeVal Empty = 0
treeVal (Node x l r)= x + treeVal l + treeVal r

mapTree :: (a->b)->Tree a -> Tree b
mapTree _ Empty = Empty
mapTree f (Node x l r) = Node (f x) (mapTree f l) (mapTree f r)

preorder :: Tree a -> [a]
preorder Empty = []
preorder (Node x l r) = [x]++preorder l ++ preorder r

inorder :: Tree a -> [a]
inorder Empty = []
inorder (Node x l r) = inorder l ++ [x] ++ inorder r

postorder :: Tree a -> [a]
postorder Empty = []
postorder (Node x l r) = postorder l ++ postorder r ++ [x] 

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert x Empty = Node x Empty Empty
treeInsert x (Node value left right)
    | x < value  = Node value (treeInsert x left) right
    | x > value  = Node value left (treeInsert x right)
    | otherwise  = Node value left right  

treeSearch :: (Ord a) => a -> Tree a -> Bool
treeSearch _ Empty = False  
treeSearch x (Node value left right)
    | x == value = True     
    | x < value  = treeSearch x left  
    | x > value  = treeSearch x right 
