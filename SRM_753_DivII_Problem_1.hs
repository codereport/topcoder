-- code_report Solution
-- Video Link: https://youtu.be/mdn7bsuK0Wo
-- Problem Link: https://arena.topcoder.com/#/u/practiceCode/17449/85533/15355/2/332231

-- Solution 1

import Data.Char

howLong :: String -> Int
howLong s = foldl (+) 0 $ map (\c -> 2 * (ord c - ord 'a') + 1) s

-- Solution 2

howLong :: String -> Int
howLong s = foldl (\a b -> a + 2 * (ord b - ord 'a') + 1) 0 s
