// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 50000;
//to count number of words
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);

    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(table[index]->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // inspired by YouTube tutorials on DSA by Prof. Rob Edwards
    int hash = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hash = (hash * 31 + toupper(word[i]));
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open and read the file
    FILE *input = fopen(dictionary, "r");

    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    //allocate memory for reading words dynamically
    char *stringer = malloc(LENGTH + 1);

    if (stringer == NULL)
    {
        return false; //if no memory available for stringer
    }

    //read one word at a time
    while (fscanf(input, "%s", stringer) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false; //if no memory available for node n
        }
        int index = hash(stringer);
        strcpy(n->word, stringer);
        if (table[index] == NULL) //check if first node of the hash table
        {
            n->next = NULL;
        }

        else
        {
            n->next = table[index]; //for the nodes after first element
        }

        table[index] = n; //point table to the next node same as n
        word_count++;
    }
    fclose(input);
    free(stringer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // word count already counted in the load function
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // unload with temp scoping through all hashes
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }
    }
    return true;
}
