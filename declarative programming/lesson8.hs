data Dayoftheweek = Monday|Tuesday|Wednesday|Thursday|Friday|Saturday|Sunday
    deriving(Eq,Show)
isWeekend :: Dayoftheweek -> Bool 
isWeekend Saturday = True
isWeekend Sunday = True
isWeekend _ = False

data Shape = Circle Double | Rectangle Double Double
    deriving(Show)

area :: Shape -> Double
area (Circle r) = pi*r^2
area (Rectangle a b) = a*b

perimeter :: Shape -> Double
perimeter (Circle r) = 2*pi*r
perimeter (Rectangle a b) = (a+b)*2

isSquare :: Shape -> Bool
isSquare shape = case shape of 
    Circle r -> False
    Rectangle a b -> if a==b then True else False

data Point a = Point a a
    deriving (Eq,Show)

ecDi :: Point Double -> Point Double -> Double
ecDi (Point x y) (Point x1,y1) = sqrt((x-x1)^2+(y-y1)^2)

data List a = Nil | Cons a (List a)
    deriving Show