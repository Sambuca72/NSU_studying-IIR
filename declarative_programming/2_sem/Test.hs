import Test.Hspec

main:: IO()
main = hspec $ do
    describe "frequencies"$ do
        it "returns frecuencies of elements of a list" $ do
            frequencies [5,5,5,6,7,8] `shouldBe` [(5,3),(6,1),(7,1),(8,1)]
        it "returns frecuencies of elements of a list" $ do
            frequencies ([]::[Int]) `shouldBe` []


frequencies:: (Eq a) => [a]-> [(a,Int)]
frequencies [] = []
frequencies (x:xs) = (x,count x xs+1) : frequencies (filter(/=x) xs)
    where 
        count y = length.filter(==y)