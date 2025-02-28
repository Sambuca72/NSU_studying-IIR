f1 :: Double -> Double
f1 x  = (x^2) / (1+x)

f2 :: Double -> Double
f2 x = (3*x - x**3)**(0.5)

f3 :: Double->Double
f3  x = logBase 10 (x**2-21)

f4 :: Double -> Double 
f4 x = logBase 2 (logBase 3 (logBase 4 (x)))

f5 :: Double -> Double
f5 x= (sin 2*x)**0.5 - (sin 3*x)**0.5

distance :: Double -> Double -> Double -> Double -> Double
distance x1 y1 x2 y2 = ((x1-x2)**2 - (y1-y2)**2)**0.5

leap :: Int -> Bool
leap x = if  rem x 400==0 then True else if rem x 100 ==0 then False else if rem x 4==0 then True else False