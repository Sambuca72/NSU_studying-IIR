data BoolExpr = BoolLit Bool|
                IntLit Integer | 
                Add BoolExpr BoolExpr|
                Sub BoolExpr BoolExpr|
                Not BoolExpr|
                And BoolExpr BoolExpr|
                Or BoolExpr BoolExpr|
                Eq BoolExpr BoolExpr|
                Gt BoolExpr BoolExpr
                deriving (Show,Eq)

expr1 = BoolLit True                     
expr2 = Not (BoolLit True)               
expr3 = Or (BoolLit True) (BoolLit False) 
expr4 = Gt (Add (IntLit 5) (IntLit 6)) (IntLit 5) 

boolEval:: BoolExpr -> Bool
boolEval (BoolLit b) = b
boolEval (Not ex) = not (boolEval ex)
boolEval (And ex1 ex2) = (boolEval ex1) && (boolEval ex2)
boolEval (Or ex1 ex2) = (boolEval ex1) || (boolEval ex2)
boolEval (Eq a b) = (intEval a) == (intEval b) where
          intEval (IntLit n) = n
          intEval (Add a b) = (intEval a) + (intEval b)
          intEval (Sub a b) = (intEval a) - (intEval b)
          intEval _ = error "not an integer"
boolEval (Gt a b) = (intEval a) > (intEval b) where
          intEval (IntLit n) = n
          intEval (Add a b) = (intEval a) + (intEval b)
          intEval (Sub a b) = (intEval a) - (intEval b)
          intEval _ = error "not an integer"
boolEval _ = error "expression is wrong"

data Bin = End | O Bin | I Bin
            deriving Eq
instance Show Bin where
    show End = "0"
    show bin = reverse (showBin bin)

showBin :: Bin -> String
showBin End = ""
showBin (O b) = '0' : showBin b
showBin (I b) = '1' : showBin b


inc :: Bin -> Bin
inc End = I End
inc (O b) = I b
inc (I b) = O (inc b)

fromBin :: Bin -> Int
fromBin End       = 0                          
fromBin (O b)     = 2 * fromBin b              
fromBin (I b)     = 1 + 2 * fromBin b          

toBin :: Int -> Bin
toBin 0 = O End              
toBin 1 = I End              
toBin n 
  | n `mod` 2 == 0 = O (toBin (n `div` 2)) 
  | otherwise      = I (toBin (n `div` 2)) 

pls :: Bin -> Bin -> Bin
pls End b = b                           
pls a End = a
pls (O a) (O b) = O (pls a b)           
pls (O a) (I b) = I (pls a b)           
pls (I a) (O b) = I (pls a b)           
pls (I a) (I b) = O (pls (pls a b) (I End)) 

mlt :: Bin -> Bin -> Bin
mlt End _ = End                        
mlt _ End = End
mlt (O a) b = O (mlt a b)              
mlt (I a) b = pls b (O (mlt a b))      

  




