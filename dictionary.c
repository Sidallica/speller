// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

//Variable to store number of words in dictionary
int numWords = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hashIndex = hash(word);

    //Create temporary cursor node
    node *cursor;

    //Copying word from dictionary to node
    cursor = table[hashIndex];

    //Loop until end of linked list
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        //Set n to next node
        cursor = cursor->next;
    }

    free(cursor);
    //Return false if word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //First letter A or a = 0; B or b = 1; ... Z or z = 25
    int hashIndex = (((int) toupper(word[0])) - 65) * 26;

    if (strlen(word) > 1)
    {
        if (isalpha(word[1]))
        {
            hashIndex += ((int) toupper(word[1])) - 65;
        }
    }
    return hashIndex;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Open Dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    //Read strings from dictionary
    //String to store word
    char *word = malloc((LENGTH + 1) * sizeof(char));
    //Varable to store hash number
    int hashIndex = 0;
    while (fscanf(dict, "%s", word) != EOF)
    {
        //Allocating memory to store new node
        node *n = malloc(sizeof(node));
        //Cheching if memory was allocated sucessfully
        if (n == NULL)
        {
            return false;
        }
        //Copying word from dictionary to node
        strcpy(n->word, word);
        n->next = NULL;

        //Getting index of linked list to store the word in the hash table
        hashIndex = hash(n->word);

        //Inserting new word to the start of the linked list
        n->next = table[hashIndex];
        table[hashIndex] = n;

        //Increment number of words in dictionary
        numWords++;
    }

    //Close dictionary file
    fclose(dict);

    //Free memory
    free(word);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //Return number of words in dictionary
    return numWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //Allocating memory to store cursor node
    node *cursor;


    //Allocating memory to store temp node
    node *temp;

    //Iterating through hash table
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];

        //Iterating through linked list at table[i]
        while (cursor != NULL)
        {
            //Set temp to cursor
            temp = cursor;

            //Set cursor to next node
            cursor = cursor->next;

            //Free previous node
            free(temp);

            numWords--;
        }

    }
    free(cursor);
    return true;
}
