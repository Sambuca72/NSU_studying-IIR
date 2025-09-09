-----------------------------------------------------------------------------
-- |
-- Module      :  SQLHSExample
-- Copyright   :  (c) 2019-2021 Konstantin Pugachev
--                (c) 2019 Denis Miginsky
-- License     :  MIT
--
-- Maintainer  :  K.V.Pugachev@inp.nsk.su
-- Stability   :  experimental
-- Portability :  portable
--
-- The SQLHSExample module provides examples of using SQLHS/SQLHSSugar module.
--
-----------------------------------------------------------------------------

import SQLHSSugar
import DBReader

-- CATEGORY:     WARE,    CLASS
-- MANUFACTURER: RECIPE_ID, COMPANY
-- MATERIAL:     RECIPE_ID, WARE,   AMOUNT
-- PRODUCT:      RECIPE_ID, WARE,   AMOUNT, PRICE

main = readDB' defaultDBName >>= executeSomeQueries

executeSomeQueries :: (Named Table, Named Table, Named Table, Named Table) -> IO ()
executeSomeQueries (categories, manufacturers, materials, products) = do
  test "task1" task1
  test "task2" task2
  test "task3" task3
  test "task31" task31
   -- test "lecPlan2" lecPlan2
  -- test "lecPlan3" lecPlan3
  -- test "lecPlan4" lecPlan4
  -- test "lecPlan4'" lecPlan4'
  
  where
    test msg p = do
      putStrLn $ "===== execute " ++ msg ++ " ====="
      -- putStrLn . debugTable $ p & enumerate
      printResult $ p & enumerate

    task1 =
      categories // "c" `wher` col "c.CLASS" `eq` str "Mineral"
      `hjoin` (materials// "m" `indexby` col "WARE") `on` col "c.WARE"
      `hjoin` (products// "p" `indexby` col "RECIPE_ID") `on` col "m.RECIPE_ID"
      `orderby` ["p.WARE" : asc]
      `select` ["p.WARE"] & distinct

    task12 = categories // "c" `wher` col "c.CLASS" `eq` str "Mineral"
    `njoin` (materials//"m" `indexby` col "WARE" & flatten) `mjoin` (products// "p" `indexby` col "RECIPE_ID" & flatten) `on` 
    
    
    task2 = 
      categories // "c1" `wher` col "c1.CLASS" `eq` str "Mineral"
      `hjoin`(materials// "m" `indexby` col "WARE") `on` col "c1.WARE"
      `hjoin`
      ((categories // "c2" `wher` col "c2.CLASS" `eq` str "Stuff"
      `hjoin` (products // "p" `indexby` col "WARE") `on` col "c2.WARE") `indexby` col "RECIPE_ID") `on` col "m.RECIPE_ID"
      `orderby` ["p.RECIPE_ID" : asc]
      `select` ["p.RECIPE_ID", "m.WARE", "p.WARE"]
      &limit 0 50

    task3 = 
        manufacturers// "m1" 
        -- `njoin` manufacturers// "m2" `on` "m1.COMPANY" `jeq` "m2.COMPANY"
        `hjoin` (materials// "m" `indexby` col "RECIPE_ID") `on` col "m1.RECIPE_ID"
        `hjoin` (products// "p" `indexby` col "WARE") `on` col "m.WARE"
        `hjoin` (manufacturers// "m2" `indexby` col "RECIPE_ID") `on` col "p.RECIPE_ID"
        `wher` col "m2.COMPANY"  `eq` col "m1.COMPANY"
        `orderby` ["m1.COMPANY" : asc]
        `select` ["m1.COMPANY"] & distinct

    task31 = 
        manufacturers// "m1" 
        -- `njoin` manufacturers// "m2" `on` "m1.COMPANY" `jeq` "m2.COMPANY"
        `hjoin` (manufacturers // "m2" `indexby` col "COMPANY") `on` col "m1.COMPANY"
        `hjoin` (materials// "m" `indexby` col "RECIPE_ID") `on` col "m1.RECIPE_ID"
        `hjoin` (products// "p" `indexby` col "RECIPE_ID") `on` col "m2.RECIPE_ID"
        `wher` col "m.WARE"  `eq` col "p.WARE"
        `orderby` ["m1.COMPANY" : asc]
        `select` ["m1.COMPANY"] & distinct



      -- manufacturers // "fst" 
      -- `njoin` manufacturers // "snd" `on` "fst.COMPANY" `jeq` "snd.COMPANY"
      -- `hjoin` (materials // "m" `indexby` col "RECIPE_ID") `on` col "fst.RECIPE_ID"
      -- `hjoin` (products // "p" `indexby` col "WARE") `on` col "m.WARE"
      -- `hjoin` (manufacturers // "snd" `indexby` col "RECIPE_ID") `on` col "p.RECIPE_ID"
      -- `orderby` ["fst.COMPANY" : asc]
      -- `select` ["fst.COMPANY"] & distinct
        -- `hjoin`(manufacturers// "m2" `indexby` col "COMPANY") on col "m1.COMPANY"

      -- `njoin` materials// "m" `on` "c1.WAREw" `jeq` "m.WARE"
    
    -- lecPlan1' = 
    --   -- MANUFACTURER NL_JOIN PRODUCT ON m.RECIPE_ID=p.RECIPE_ID
    --   manufacturers // "m" `njoin` products // "p" `on` "m.RECIPE_ID" `jeq` "p.RECIPE_ID"
    --   -- -> NL_JOIN CATEGORY ON c.WARE=p.WARE
    --   `njoin` categories // "c" `on` "p.WARE" `jeq` "c.WARE"
    --   -- -> FILTER c.CLASS='Raw food'
    --   `wher` col "CLASS" `eq` str "Raw food"
    --   -- -> SORT_BY p.WARE
    --   `orderby` ["p.WARE":asc]
    --   -- -> MAP (p.WARE, m.COMPANY)
    --   `select` ["p.WARE", "m.COMPANY"]
    --   -- -> DISTINCT
    --   & distinct 
    --   -- -> TAKE 10
    --   & limit 0 10
  
    -- lecPlan2 = 
    --   -- CATEGORY FILTER c.CLASS='Raw food'
    --   categories // "c" `wher` col "c.CLASS" `eq` str "Raw food"
    --   -- -> NL_JOIN PRODUCT ON c.WARE=p.WARE
    --   `njoin` products // "p" `on` "c.WARE" `jeq` "p.WARE"
    --   -- -> NL_JOIN MANUFACTURER ON m.RECIPE_ID=p.RECIPE_ID
    --   `njoin` manufacturers // "m" `on` "p.RECIPE_ID" `jeq` "m.RECIPE_ID"
    --   -- -> SORT_BY p.WARE
    --   `orderby` ["p.WARE":asc]
    --   -- -> MAP (p.WARE, m.COMPANY)
    --   `select` ["p.WARE", "m.COMPANY"]
    --   -- ->DISTINCT
    --   & distinct 
    --   -- -> TAKE 10
    --   & limit 0 10
  
    -- lecPlan3 = 
    --   -- CATEGORY FILTER c.CLASS='Raw food'
    --   categories // "c" `wher` col "c.CLASS" `eq` str "Raw food"  
    --   -- -> HASH_JOIN PRODUCT INDEX BY WARE ON c.WARE=p.WARE
    --   `hjoin` (products // "p" `indexby` col "WARE") `on` col "c.WARE"
    --   -- -> HASH_JOIN MANUFACTURER INDEX BY RECIPE_ID ON m.RECIPE_ID=p.RECIPE_ID
    --   `hjoin` (manufacturers // "m" `indexby` col "RECIPE_ID") `on` col "p.RECIPE_ID"
    --   -- -> SORT_BY p.WARE
    --   `orderby` ["p.WARE":asc]
    --   -- -> MAP (p.WARE, m.COMPANY)
    --   `select` ["p.WARE", "m.COMPANY"]
    --   -- ->DISTINCT
    --   & distinct 
    --   -- -> TAKE 10
    --   & limit 0 10

    -- lecPlan4 = 
    --   -- CATEGORY FILTER c.CLASS='Raw food'
    --   (categories // "c" `indexby` col "WARE" & flatten) `wher` col "CLASS" `eq` str "Raw food"
    --   -- -> MERGE_JOIN PRODUCT INDEX BY WARE ON c.WARE=p.WARE
    --   `mjoin` (products // "p" `indexby` col "WARE" & flatten) `on` "c.WARE" `jeq` "p.WARE"
    --   -- -> HASH_JOIN MANUFACTURER INDEX BY RECIPE_ID ON m.RECIPE_ID=p.RECIPE_ID
    --   `hjoin` (manufacturers // "m" `indexby` col "RECIPE_ID") `on` col "p.RECIPE_ID"
    --   -- -> MAP (p.WARE, m.COMPANY)
    --   `select` ["p.WARE", "m.COMPANY"]
    --   -- ->DISTINCT
    --   & distinct 
    --   -- -> TAKE 10
    --   & limit 0 10
  
    -- lecPlan4' = 
    --   -- CATEGORY FILTER c.CLASS='Raw food'
    --   (categories // "c" `indexby` col "WARE" & flatten) `wher` col "CLASS" `eq` str "Raw food"
    --   -- -> HASH_JOIN PRODUCT INDEX BY WARE ON c.WARE=p.WARE
    --   `hjoin` (products // "p" `indexby` col "WARE") `on` col "c.WARE"
    --   -- -> HASH_JOIN MANUFACTURER INDEX BY RECIPE_ID ON m.RECIPE_ID=p.RECIPE_ID
    --   `hjoin` (manufacturers // "m" `indexby` col "RECIPE_ID") `on` col "p.RECIPE_ID"
    --   -- -> MAP (p.WARE, m.COMPANY)
    --   `select` ["p.WARE", "m.COMPANY"]
    --   -- ->DISTINCT
    --   & distinct 
    --   -- -> TAKE 10
    --   & limit 0 10