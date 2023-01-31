# Spell-Checker

## Summary

A program that spell-checks a file using a hash table implemented in C. 
This program was part of the problem sets from CS50x: Introduction to Computer Science by Harvard University.

## Code Files

### dictionary.c

The dictionary (for checking the spellings) will be loaded into a hash table, which can be looked up when checking if each word is spelt correctly. 
The aim is to minimise this lookup time by using an appropriate hash function.

The functions to be defined within dictionary.c are as follows:

*load()* must take the dictionary and load it into a hash table using an appropriate hash function.

*hash()* is the aforementioned hash function that determines the hash code for each entry to the hash table.

*size()* must return the number of words in the dictionary, if it is successfully loaded.

*check()* must check if a word is in the dictionary and thus spelt correctly.

*unload()* removes the dictionary data structure from memory once the entire document has been spell checked.

### speller.c

A function called getrusage will be used for “benchmarking” (i.e., timing the execution of) implementations of check, load, size, and unload. 
Ultimately, each misspelling will be reported in that file along with a bunch of statistics.

### dictionaries

Within the default dictionary (large.txt) are 143,091 words, all of which must be loaded into memory.

### Makefile

A configuration file that tells make exactly what to do. Program will be compiled with executing command 'make speller'.





