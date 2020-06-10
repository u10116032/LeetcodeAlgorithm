# LeetcodeAlgorithm
Practice of leetcode

## Dynamic Programming
### possible process of thinking [Induction]
 - Since DP means optimal substructure which is closed to mathematical induction, in many dp problems, there can be some n represent array size, string length, tree height, etc.
 - Then you consider the situation when n=1, n=2, n=3, n=4, n=5, ..., this procedure may cost lots of time until you found many processes are repeated and can be cached. You can cache whatever you want. Remember don't directly define what your dp array cache and solve the problem by your definition. You solve the problem then you define what dp cache.
 - In this way, you found the so-called Bellman equation.
 - Problems which doesn't have an obvious n, or doesn't have such n(such as each dp used to save a statement), or has two or more n-s, are often hard to solve.
 - Figure out whether P(a+1,b+1) can be solved by P(a,b+1) and P(a+1,b), then you will find P(a+1,b+1) = P(a,b+1)+P(a+1,b)-P(a,b)+D(a+1,b+1)(Inclusion–exclusion principle)

| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 1035| Uncrossed Lines|[1035.cpp](1035.cpp)|Medium|Longest Common Sequence|
| 10| Regular Expression Matching|[10.cpp](10.cpp)|Medium|variation of LCS|
| 22| Generate Parentheses|[22.cpp](22.cpp)|Medium|Catalan Number, could use DP or recursive(backtracking)|
| 44| Wildcard Matching|[44.cpp](44.cpp)|Hard|DP or Greedy. **Compare to 10.**|
| 518| Coin Change 2|[518.cpp](518.cpp)|Medium|0/1 Knapsack Problem. Backtracking will TLE|

## Searching
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 33| Search in Rotated Sorted Array|[33.cpp](33.cpp)|Medium|Boundary checking with binary search|
| 34| Find First and Last Position of Element in Sorted Array|[34.cpp](34.cpp)|Medium|twice binary search|
| 35| Search Insert Position|[35.cpp](35.cpp)|Easy||
| 392| Is Subsequence|[392.cpp](392.cpp)|Easy|LCSequence/binary search|
| 528| Random Pick with Weight|[528.cpp](528.cpp)|Easy|binary search **REGION**|


## Recursive (Backtracking)
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 31| Next Permutation|[31.cpp](31.cpp)|Medium|backtracking may TLE, **tricky**|
| 37| Sudoku Solver|[37.cpp](37.cpp)|Hard|backtracking, mind end up criteria.|
| 38| Count and Say|[38.cpp](38.cpp)|Easy|moving comparison|
| 39| Combination Sum|[39.cpp](39.cpp)|Medium|each entry could be used several times.|
| 40| Combination Sum II|[40.cpp](40.cpp)|Medium|each entry could be used only once.|
| 46| Permutations|[46.cpp](46.cpp)|Medium|allow duplicate|
| 47| Permutations II|[47.cpp](47.cpp)|Medium|no duplicate allowed, hashtable or **call by value**|
| 51| N-Queens|[51.cpp](51.cpp)|Hard|recursive vs stack|
| 52| N-Queens II|[52.cpp](52.cpp)|Hard|Don't need 2-d table to place Q. Use **diagonal flag** with 1-d bool array.|


## Tree
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 226| Invert Binary Tree|[226.cpp](226.cpp)|Easy||


## Divide & Conquer
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 23| Merge k Sorted Lists|[23.cpp](23.cpp)|Hard|**Iterative split arrays equally in 2^n**|

## LinkedList
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 19| Remove Nth Node From End of List|[19.cpp](19.cpp)|Medium|2 pointers|
| 21| Merge Two Sorted Lists|[21.cpp](21.cpp)|Easy||
| 24| Swap nodes in Pairs|[24.cpp](24.cpp)|Medium|Header pointer|
| 25| Reverse Nodes in k-Group|[25.cpp](25.cpp)|Hard||
| 237| Delete Node in a Linked List|[237.cpp](237.cpp)|Easy||

## Stack
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 20| Valid Parentheses|[20.cpp](20.cpp)|Easy|check empty stack in iteration|
| 32| Longest Valid Parentheses|[32.cpp](32.cpp)|Hard|**Great stack example to check**|

## String
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 12| Integer to Roman|[12.cpp](12.cpp)|Medium|Elegant dictionary|
| 13| Roman to Integer|[13.cpp](13.cpp)|Easy|No additional dictionary entry. Inverse parsing should be ok.|
| 28|  Implement strStr()|[28.cpp](28.cpp)|Easy|**Knuth-Morris-Pratt**|
| 30|  Substring with Concatenation of All Words|[30.cpp](30.cpp)|Hard|Bottom up early stop instead of frequency comparison.|
| 43|  Multiply Strings|[43.cpp](43.cpp)|Medium|basic multiplication|

## Array
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 525| Contiguous Array|[525.cpp](525.cpp)|Medium|Use map to record index of accumulated sum|
| 11| Container With Most Water|[11.cpp](11.cpp)|Medium|two pointer|
| 14| Longest Common Prefix|[14.cpp](14.cpp)|Easy||
| 15| 3Sum|[15.cpp](15.cpp)|Medium| Greedy / sandwitch(boudary) search|
| 16| 3Sum Closest|[16.cpp](16.cpp)|Medium| 3Sum|
| 17| Letter Combinations of a Phone Number|[17.cpp](17.cpp)|Medium| greedy|
| 18| 4Sum|[18.cpp](18.cpp)|Medium| **General way for N SUM**|
| 26| Remove Duplicates from Sorted Array|[26.cpp](26.cpp)|Easy||
| 27| Remove Element|[27.cpp](27.cpp)|Easy||
| 36| Valid Sudoku|[36.cpp](36.cpp)|Medium|indexing|
| 41| First Missing Positive|[41.cpp](41.cpp)|Hard|Correct Slot Filling|
| 42| Trapping Rain Water|[42.cpp](42.cpp)|Hard|Greedy. Graham's Scan or **2 pointers sandwitch search**|
| 45| Jump Game II|[45.cpp](45.cpp)|Hard|**2 pointers (start/end)**|
| 48| Rotate Image|[48.cpp](48.cpp)|medium|clockwise / anticlockwise|
| 49| Group Anagrams|[49.cpp](49.cpp)|medium||
| 406|  Queue Reconstruction by Height|[406.cpp](406.cpp)|Medium|**insert after sorting**|
| 1029| Two City Scheduling|[1029.cpp](1029.cpp)|Easy||

## Numeric
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 9| Palindrome Number|[9.cpp](9.cpp)|Easy|take care of overflow INT_MAX|
| 29| Divide Two Integers|[29.cpp](29.cpp)|Medium|bit operating|
| 50| Pow(x, n)|[50.cpp](50.cpp)|Medium|bit operating|
| 231| Power of Two|[231.cpp](231.cpp)|Easy|!n&(n-1)|

## Graph
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 886| Possible Bipartition|[886.cpp](886.cpp)|Medium|bipartite + dfs/bfs|
| 207| Course Schedule|[207.cpp](207.cpp)|Medium|Detect cyclic in directed graph.|
