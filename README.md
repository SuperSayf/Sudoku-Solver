# Sudoku Solver

This project was for my COMS1017A course, which required us to code up a solution to solve
a 9x9, 16x16 and 25x25 sudoku grid within a reasonable execution speed using C++


## Features

- Hidden singles alogrithm
- Naked singles alogrithm


  
## Optimizations

- Dynamic "next candidate" search function
- Dynamic bruteforce function
- Suppressed optimizations for faster execution times
    ```javascript
    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma")
    ```

  
## Usage/Examples
9x9
```
*Input*
0 4 0 0 0 0 1 7 9           
0 0 2 0 0 8 0 5 4
0 0 6 0 0 5 0 0 8
0 8 0 0 7 0 9 1 0
0 5 0 0 9 0 0 3 0
0 1 9 0 6 0 0 4 0
3 0 0 4 0 0 7 0 0
5 7 0 1 0 0 2 0 0
9 2 8 0 0 0 0 6 0

*Output*
8 4 5 6 3 2 1 7 9
7 3 2 9 1 8 6 5 4
1 9 6 7 4 5 3 2 8
6 8 3 5 7 4 9 1 2
4 5 7 2 9 1 8 3 6
2 1 9 8 6 3 5 4 7
3 6 1 4 2 9 7 8 5
5 7 4 1 8 6 2 9 3
9 2 8 3 5 7 4 6 1
```

16x16
```
*Input*
0 0 0 0 7 0 0 0 0 0 0 0 0 E 0 2
7 0 B 0 0 0 0 0 A 0 2 D 0 F 0 5
1 0 G E 3 B 2 0 5 0 0 0 0 0 0 D
0 2 0 5 0 0 0 0 0 0 7 0 0 8 B 0
2 0 0 0 0 0 G 0 0 6 0 0 0 0 0 0
0 B 1 C E 0 0 0 8 0 5 7 0 A 0 0
F 0 0 G 0 0 0 0 1 0 9 2 0 0 6 4
0 0 5 0 2 0 0 7 0 0 0 4 8 1 0 B
0 0 4 0 0 0 0 8 0 A 0 B C 0 0 1
0 0 8 6 0 E 0 3 D 0 0 0 0 9 0 0
0 0 D F B G 5 4 0 0 3 0 0 0 0 A
0 G 0 9 C 0 0 0 0 0 0 6 B 0 8 0
0 0 0 D 6 0 0 0 0 1 F G 0 0 7 0
E 0 0 A 0 C B 0 9 0 0 0 0 5 0 0
0 0 3 0 5 0 0 0 0 B 0 0 D 0 E 0
0 0 0 0 0 1 0 G 3 E C 0 A 0 0 0

*Output*
D A F 8 7 9 4 5 B C 6 1 G E 3 2
7 9 B 4 G 8 E C A 3 2 D 6 F 1 5
1 C G E 3 B 2 6 5 9 8 F 7 4 A D
3 2 6 5 F A D 1 G 4 7 E 9 8 B C
2 8 9 7 1 4 G A C 6 B 3 F D 5 E
4 B 1 C E 6 3 D 8 F 5 7 2 A 9 G
F E A G 8 5 C B 1 D 9 2 3 7 6 4
6 D 5 3 2 F 9 7 E G A 4 8 1 C B
5 3 4 2 9 7 6 8 F A E B C G D 1
B 7 8 6 A E 1 3 D 2 G C 5 9 4 F
C 1 D F B G 5 4 7 8 3 9 E 6 2 A
A G E 9 C D F 2 4 5 1 6 B 3 8 7
8 5 C D 6 3 A E 2 1 F G 4 B 7 9
E 6 2 A 4 C B F 9 7 D 8 1 5 G 3
G F 3 1 5 2 7 9 6 B 4 A D C E 8
9 4 7 B D 1 8 G 3 E C 5 A 2 F 6
```

25x25
```
*Input*
F D P 3 A 1 7 2 C 8 5 O E K L 4 9 J G M H N 6 I B
7 E M O 9 N 5 K F 3 H J 6 A 1 I 2 L C B P D G 4 8
0 0 1 N 0 G 0 0 0 0 8 0 0 0 F 0 0 O 0 0 K 2 0 0 0
4 0 0 H 0 O 6 P 0 0 0 0 0 B N 0 0 8 7 0 0 5 M 0 J
0 0 I 0 0 0 B J E 0 G 2 0 0 7 0 0 0 P 0 F 3 0 0 1
0 I 0 A 1 0 M C 4 7 0 N 8 0 0 G 0 0 0 9 0 0 2 L 0
0 3 J 0 0 0 0 L 9 0 1 0 0 P 0 0 O 0 0 0 0 0 0 5 D
G 0 0 4 0 0 N 0 3 K 0 0 O 0 0 0 M 0 E 2 0 I 0 J P
0 H 0 0 O 0 0 0 0 I 0 M J 0 G B L F K 0 4 0 0 N 0
0 0 0 P 0 J 0 G 0 0 A 0 4 9 D 7 0 H 3 0 0 C F E 0
9 0 0 0 0 A 0 7 O J L 0 0 I 0 0 0 0 0 0 0 0 8 0 M
0 0 0 B M 0 0 0 2 0 0 0 0 O 5 3 7 A 4 0 G J I 0 6
C O 0 0 0 3 0 0 M 0 F 4 G N H 0 D 0 0 8 0 0 0 A L
N 0 A 6 8 0 E 5 G D 7 K 0 0 0 0 B 0 0 0 2 O 0 0 0
I 0 G 0 0 0 0 0 0 0 0 6 0 0 C F J 9 0 5 0 0 0 0 3
0 A 8 7 0 0 L M 0 4 D I K 0 E 0 0 B 0 G 0 1 0 0 0
0 G 0 0 N 0 3 6 P A B 0 2 J 0 D 0 0 0 0 I 0 0 M 0
D P 0 F 0 K G 0 J 0 0 0 7 0 0 2 H 0 8 0 0 9 0 0 N
H J 0 0 0 0 0 0 1 0 0 G 0 0 A 0 K P 0 0 0 0 3 D 0
0 C O 0 0 D 0 0 0 H 0 0 9 6 0 J 3 4 I 0 A L 0 2 0
3 0 0 I 5 0 1 0 0 0 M 0 0 2 4 0 E C D 0 0 0 N 0 0
8 0 B G 0 0 C 3 0 0 J A 0 0 0 0 0 M 2 P 0 K 0 0 5
0 0 0 C P 0 0 B 0 0 K 0 0 0 3 0 0 0 0 1 0 F J 0 0
A 0 6 9 0 0 J 0 0 2 0 C I 0 8 0 G 0 0 F 1 E 0 0 4
2 0 E 0 0 9 0 0 7 G O 0 0 0 6 N 4 0 0 K 0 0 P 3 I

*Output*
F D P 3 A 1 7 2 C 8 5 O E K L 4 9 J G M H N 6 I B
7 E M O 9 N 5 K F 3 H J 6 A 1 I 2 L C B P D G 4 8
J B 1 N C G D H I M 8 9 P 4 F E 6 O 5 3 K 2 L 7 A
4 K 2 H G O 6 P A L I 3 C B N 1 F 8 7 D E 5 M 9 J
5 8 I L 6 4 B J E 9 G 2 M D 7 A N K P H F 3 C O 1
B I 5 A 1 F M C 4 7 6 N 8 E K G P D J 9 3 H 2 L O
M 3 J 8 K H 2 L 9 E 1 7 F P I C O N A 4 6 G B 5 D
G 9 F 4 7 6 N D 3 K C L O H B 5 M 1 E 2 8 I A J P
E H C D O 5 P A 8 I 2 M J 3 G B L F K 6 4 7 1 N 9
L 6 N P 2 J O G B 1 A 5 4 9 D 7 8 H 3 I M C F E K
9 5 3 E F A H 7 O J L P B I 2 K C G 6 N D 4 8 1 M
P L H B M C F 1 2 N 9 8 D O 5 3 7 A 4 E G J I K 6
C O 7 K J 3 I 9 M 6 F 4 G N H P D 2 1 8 5 B E A L
N 4 A 6 8 P E 5 G D 7 K 3 1 J H B I M L 2 O 9 F C
I 2 G 1 D 8 K 4 L B E 6 A M C F J 9 O 5 N P 7 H 3
6 A 8 7 3 2 L M N 4 D I K C E 9 5 B F G J 1 O P H
K G 9 5 N 7 3 6 P A B H 2 J O D 1 E L C I 8 4 M F
D P 4 F E K G I J O 3 1 7 L M 2 H 6 8 A B 9 5 C N
H J L 2 I B 9 F 1 C 4 G 5 8 A M K P N O 7 6 3 D E
1 C O M B D 8 E 5 H N F 9 6 P J 3 4 I 7 A L K 2 G
3 F K I 5 L 1 O 6 P M B H 2 4 8 E C D J 9 A N G 7
8 N B G 4 E C 3 D F J A 1 7 9 L I M 2 P O K H 6 5
O M D C P I 4 B H 5 K E N G 3 6 A 7 9 1 L F J 8 2
A 7 6 9 L M J N K 2 P C I 5 8 O G 3 H F 1 E D B 4
2 1 E J H 9 A 8 7 G O D L F 6 N 4 5 B K C M P 3 I

```

  
## Lessons Learned

- Learnt and understood everything related to Depth First Searches using recursion
  
## Acknowledgements

 - [Hidden Singles Explanation](https://www.youtube.com/watch?v=Kay1haclE8M&t=74s)
 - [Naked Singles Explanation](https://www.youtube.com/watch?v=JGznOh9vkDQ)
 - [Sudoku Solver AI](https://github.com/corinneleopold/Sudoku_Solver_AI)

  
## Authors

- [@SuperSayf](https://github.com/SuperSayf)

  
## License

[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://choosealicense.com/licenses/gpl-3.0/)

  