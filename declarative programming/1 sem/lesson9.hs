data List a = Nil | Cons a (List a)
    deriving Show

fromList :: List a -> [a]
fromList Nil = []
fromList (Cons x xs) = x : fromList xs

toList :: [a] -> List a
toList [] = Nil
toList (x:xs) = Cons x (toList xs)

data Nat = Zero | Suc Nat
    deriving Show

fromNat :: Nat -> Integer
fromNat Zero     = 0
fromNat (Suc n)  = fromNat n + 1

toNat :: Integer -> Nat
toNat n
  | n < 0     = error "Negative number cannot be converted to Nat"
  | n == 0    = Zero
  | otherwise = Suc (toNat (n - 1))

addNat :: Nat -> Nat -> Nat
addNat Zero n     = n
addNat (Suc m) n  = Suc (addNat m n)

mulNat :: Nat -> Nat -> Nat
mulNat Zero _     = Zero
mulNat (Suc m) n  = addNat n (mulNat m n)

facNat :: Nat -> Nat
facNat Zero     = Suc Zero
facNat (Suc n)  = mulNat (Suc n) (facNat n)
