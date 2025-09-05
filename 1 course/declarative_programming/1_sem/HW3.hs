predicatfunc1 :: (Int -> Bool) -> (Int -> Bool) -> Int -> Bool
predicatfunc1 p1 p2 x= (p1 x)&& (p2 x) 

f:: Double -> Double
f x =x^3-x^2+2

deltafunc2::(Double -> Double) -> Double -> Double -> Double
deltafunc2 f x h =  (f(x+h) - f x)/h

-- lim = f(x+h) - f(x)/hh


solver:: (Double -> Double) -> Double -> Double -> Double -> Double
solver f a b e | f a == 0 = a
solver f a b e | f b == 0 = b
solver f a b e | (b-a)<e = xi
               | f xi ==0 = xi
               | (b-a) >= e = if ((f a)*f(xi))<0 then solver f a xi e else solver f xi b e
        where xi=  (a+b)/ 2
    -- where   dx = (b-a)/2
    --         xi = a+dxы
    
