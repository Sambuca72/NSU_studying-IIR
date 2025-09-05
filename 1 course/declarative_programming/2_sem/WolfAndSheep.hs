module WolfsAndSheep where

import Control.Monad.Trans.Except
import Control.Monad.Trans.Writer
import Control.Monad (guard)
import Control.Monad.Trans


data Position = Position {f :: Char, r :: Int} 
        deriving (Eq)

instance Show Position where
    show :: Position -> String
    show (Position f r) = f : show r


data Step = Step {from :: Position, to :: Position} 
        deriving (Eq)

instance Show Step where
    show (Step f t) = show f ++ " -> " ++ show t

data Game = Game {sheep :: Position, wolfs :: [Position]} 
        deriving (Eq)


instance Show Game where
    show (Game s w) = "Board:\n" ++ unlines [row r | r <- [8,7..1]]
      where
        row r = unwords [cell f r | f <- ['a'..'h']]
        cell f r
            | Position f r == s = "S"
            | Position f r `elem` w = "W"
            | otherwise = "."

data GameResult = SheepWin | WolfsWin 
        deriving (Show)

startSheep :: Position
startSheep = Position 'c' 1

startWolfs :: [Position]
startWolfs = [Position f 8 | f <- "bdfh"]

startGame :: Game
startGame = Game startSheep startWolfs

-- tSheep :: Position 
-- tSheep = Position 'e' 3 

-- tWolfs :: [Position]
-- tWolfs = [Position 'a' 7, Position 'c' 7, Position 'f' 8, Position 'h' 8]

-- tGame :: Game 
-- tGame = Game tSheep tWolfs

tSheep :: Position 
tSheep = Position 'f' 4 

tWolfs :: [Position]
tWolfs = [Position 'b' 6, Position 'c' 7, Position 'f' 8, Position 'h' 8]

tGame :: Game 
tGame = Game tSheep tWolfs


possibleSheepSteps :: Game -> [Step] --list comprehension
possibleSheepSteps (Game s w) = 
    [Step s (Position f' r') 
    | (df, dr) <- [(1, 1), (1, -1), (-1, 1), (-1, -1)]
    ,let f'= toEnum (fromEnum (f s) + df)
    , let r' = r s + dr
    , f' >= 'a' && f' <= 'h'
    , r' >= 1 && r' <= 8
    , Position f' r' `notElem` w 
    ]

possibleSheepStepsDo :: Game -> [Step] --list comprehension
possibleSheepStepsDo (Game s w) = do
    (df, dr) <- [(1, 1), (1, -1), (-1, 1), (-1, -1)]
    let f'= toEnum (fromEnum (f s) + df)
    let r' = r s + dr
    guard (f' >= 'a' && f' <= 'h')
    guard (r' >= 1 && r' <= 8)
    guard (Position f' r' `notElem` w)
    return (Step s (Position f' r')) 
    

possibleWolfsSteps :: Game -> [Step] --list comprehension
possibleWolfsSteps (Game s ws) = 
    [Step w (Position f' r') 
    | w<- ws
    ,(df, dr) <- [(-1, -1), (1, -1)]
    ,let f'= toEnum (fromEnum (f w) + df)
    , let r' = r w + dr
    , f' >= 'a' && f' <= 'h'
    , r' >= 1 && r' <= 8
    , Position f' r' `notElem` ws
    ]



possibleWolfsStepsDo :: Game -> [Step] --list comprehension
possibleWolfsStepsDo (Game s ws) = do 
    w <- ws
    (df, dr) <- [(1, -1), (-1, -1)]
    let f' = toEnum (fromEnum (f w) + df)
    let r' = r w + dr
    guard (f' >= 'a' && f' <= 'h')
    guard (r' >= 1 && r' <= 8)
    guard (Position f' r' /= s)
    guard (Position f' r' `notElem` ws)
    return (Step w (Position f' r'))
    


simpleTurn :: Game -> Either GameResult Game
simpleTurn game@(Game s ws) = do
    let sheepMoves = possibleSheepSteps game 
    case sheepMoves of
        [] -> Left WolfsWin
        (Step _ s':_) -> do
            if r s' == 8 then Left SheepWin  
            else do
                let g' = Game s' ws
                let wolfMoves = possibleWolfsSteps g'
                case wolfMoves of
                    [] -> Left SheepWin 
                    (Step w w':_) -> Right $ Game s' (w' : filter (/= w) ws)


run :: (a -> Either GameResult a) -> a -> GameResult
run turn game =
    case turn game of
        Left winner -> winner  
        Right newGame -> run turn newGame  


loggedTurn :: Game -> (WriterT [Step] (Either GameResult)) Game
loggedTurn game@(Game s ws) = do
    let sheepMoves = possibleSheepSteps game 
    case sheepMoves of
        [] -> lift $ Left WolfsWin
        (Step _ s' : _) -> do
            tell [Step s s']
            if r s' == 8 then lift $ Left SheepWin
            else do 
                let g' = Game s' ws 
                let wolfMoves = possibleWolfsSteps g' 
                case wolfMoves of 
                    [] -> lift $ Left SheepWin
                    (Step w w':_) -> do 
                        tell [Step w w']
                        return $ Game s' (w' : filter (/=w) ws)

loggedTurn' :: Game -> ExceptT GameResult (Writer [Step]) Game
loggedTurn' game@(Game s ws) = do
    let sheepMoves = possibleSheepSteps game
    case sheepMoves of
        [] -> throwE WolfsWin  
        (Step _ s':_) -> do
            lift $ tell [Step s s']  
            if r s' == 8 
                then throwE SheepWin  
                else do
                    let g' = Game s' ws
                    let wolfMoves = possibleWolfsSteps g'
                    case wolfMoves of
                        [] -> throwE SheepWin 
                        (Step w w':_) -> do
                            lift $ tell [Step w w']  
                            return $ Game s' (w' : filter (/= w) ws)  -- Обновляем игру


runGameWithLog :: Game -> (Either GameResult Game, [Step])
runGameWithLog game = runWriter (runExceptT (gameLoop game))

gameLoop :: Game -> ExceptT GameResult (Writer [Step]) Game
gameLoop game = do
    nextGame <- loggedTurn' game
    gameLoop nextGame  
  `catchE` (\res -> throwE res)  



