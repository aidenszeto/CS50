// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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

bool loaded = false;

// Number of buckets in hash table
const unsigned int N = 26;
int words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = table[index];
    while(cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int n = (int) tolower(word[0]) - 97;
    return n;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary and check if it is valid
    FILE *dictionaryPointer = fopen(dictionary, "r");
    if (dictionaryPointer == NULL)
    {
        printf("Dictionary cannot be found");
        return false;
    }

    // Put words into hash table
    char *temp = malloc(LENGTH);
    if (temp == NULL)
    {
        printf("No more memory");
        return false;
    }

    while (fscanf(dictionaryPointer, "%s", temp) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("No more memory");
            return false;
        }
        strcpy(n->word, temp);
        int index = hash(n->word);
        n->next = table[index];
        table[index] = n;
        words++;
    }
    fclose(dictionaryPointer);
    free(temp);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *tmp;
    node *cursor;

    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }

        cursor = table[i];
        tmp = cursor;
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        free(cursor);
    }
    return true;
}
