import Text.ParserCombinators.Parsec

-- Определенные типы данных
data Graph = Digraph ID [Node] [Edge] [Attr]
  deriving (Show)

data Node = Node ID [Attr]
  deriving (Show)

data Edge = Edge ID ID [Attr]
  deriving (Show)

data Attr = Attr ID ID
  deriving (Show)

type ID = String


identifier :: Parser String
identifier = many1 alphaNum


attrList :: Parser [Attr]
attrList = between (char '[') (char ']') $ sepBy attr (char ',' <|> char ';')
  where
    attr = do
      skipMany space
      key <- identifier
      skipMany space
      char '='
      skipMany space
      value <- identifier
      return $ Attr key value


nodeStmt :: Parser Node
nodeStmt = do
  nid <- identifier
  skipMany space
  attrs <- option [] attrList
  return $ Node nid attrs  


edgeOp :: Parser String
edgeOp = string "->"


edgeStmt :: Parser [Edge]
edgeStmt = do
  from <- identifier
  skipMany space
  edges <- edgeRHS from
  return edges


edgeRHS :: ID -> Parser [Edge]
edgeRHS from = do
  op <- edgeOp
  skipMany space
  to <- identifier
  skipMany space
  attrs <- option [] attrList
  rest <- optionMaybe (skipMany space >> edgeRHS to)
  case rest of
    Nothing -> return [Edge from to attrs]
    Just moreEdges -> return (Edge from to attrs : moreEdges)


graphAttr :: Parser Attr
graphAttr = do
  key <- identifier
  skipMany space
  char '='
  skipMany space
  value <- identifier
  return $ Attr key value


stmt :: Parser (Maybe Node, [Edge], Maybe Attr)
stmt = do
  skipMany space
  result <- try (graphAttr >>= \a -> return (Nothing, [], Just a))
        <|> try (edgeStmt >>= \es -> return (Nothing, es, Nothing))
        <|> try (nodeStmt >>= \n -> return (Just n, [], Nothing))
  skipMany space
  optional (char ';')
  skipMany space
  return result


stmtList :: Parser ([Node], [Edge], [Attr])
stmtList = do
  skipMany space
  stmts <- many stmt
  skipMany space
  lookAhead (char '}')  
  let nodes = [n | (Just n, _, _) <- stmts]
      edges = concat [es | (_, es, _) <- stmts]
      attrs = [a | (_, _, Just a) <- stmts]
  return (nodes, edges, attrs)


graph :: Parser Graph
graph = do
  skipMany space
  string "digraph"
  spaces
  graphName <- identifier
  spaces
  char '{'
  skipMany space
  (nodes, edges, attrs) <- stmtList
  char '}'
  skipMany space
  return $ Digraph graphName nodes edges attrs


main :: IO ()
main = do
  text <- readFile "graph.txt"
  let result = parse graph "" text
  case result of
    Left e -> print e
    Right g -> do
      putStrLn "Read graph:"
      print g