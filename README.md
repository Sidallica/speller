# speller
## CS50 Problem
Implement a program that spell-checks a file, a la the below, using a hash table.
```
$ ./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```
Below’s some of the output you’ll see. For information’s sake, we’ve excerpted some examples of “misspellings.” And lest we spoil the fun, we’ve omitted our own statistics for now.
```
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```
TIME IN load represents the number of seconds that speller spends executing your implementation of load. TIME IN check represents the number of seconds that speller spends, in total, executing your implementation of check. TIME IN size represents the number of seconds that speller spends executing your implementation of size. TIME IN unload represents the number of seconds that speller spends executing your implementation of unload. TIME IN TOTAL is the sum of those four measurements.

Note that these times may vary somewhat across executions of speller, depending on what else CS50 IDE is doing, even if you don’t change your code.

Incidentally, to be clear, by “misspelled” we simply mean that some word is not in the dictionary provided.


### Testing

How to check whether your program is outting the right misspelled words? Well, you’re welcome to consult the “answer keys” that are inside of the keys directory that’s inside of your speller directory. For instance, inside of keys/lalaland.txt are all of the words that your program should think are misspelled.

You could therefore run your program on some text in one window, as with the below.
```
$ ./speller texts/lalaland.txt
```
And you could then run the staff’s solution on the same text in another window, as with the below.
```
$ ~cs50/2019/fall/pset5/speller texts/lalaland.txt
```
And you could then compare the windows visually side by side. That could get tedious quickly, though. So you might instead want to “redirect” your program’s output to a file, as with the below.
```
$ ./speller texts/lalaland.txt > student.txt
$ ~cs50/2019/fall/pset5/speller texts/lalaland.txt > staff.txt
```
You can then compare both files side by side in the same window with a program like diff, as with the below.
```
$ diff -y student.txt staff.txt
```
Alternatively, to save time, you could just compare your program’s output (assuming you redirected it to, e.g., student.txt) against one of the answer keys without running the staff’s solution, as with the below.
```
$ diff -y student.txt keys/lalaland.txt
```
If your program’s output matches the staff’s, diff will output two columns that should be identical except for, perhaps, the running times at the bottom. If the columns differ, though, you’ll see a > or | where they differ. For instance, if you see
```
MISSPELLED WORDS                                                MISSPELLED WORDS

TECHNO                                                          TECHNO
L                                                               L
                                                              > Thelonious
Prius                                                           Prius
                                                              > MIA
L                                                               L
```
that means your program (whose output is on the left) does not think that Thelonious or MIA is misspelled, even though the staff’s output (on the right) does, as is implied by the absence of, say, Thelonious in the lefthand column and the presence of Thelonious in the righthand column.
