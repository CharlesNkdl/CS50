// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 600;
unsigned int countword = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int q = hash(word);
    node* ptr = table[q];
    while (ptr != NULL)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long total = 0;
    for (int i = 0; i < (strlen(word)/2); i ++)
    {
        total += (toupper(word[i]) - 'A' ) / 3;
    }
    return total;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE* dico = fopen(dictionary, "r");
    if (dictionary==NULL)
    {
        return false;
    }
    char w[LENGTH+1];
    while (fscanf(dico,"%s",w) != EOF)
    {
        node *g = malloc(sizeof(node));
        if (g == NULL)
        {
            return false;
        }
        strcpy((g->word), w);
        int l = hash(w);
        g->next = table[l];
        table[l] = g;
        countword++;
    }
    fclose(dico);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //TODO
    return countword;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //TODO
    //if (load (table) == false)
    //{
     //   return false;
    //}
    node* temp;
    node* temp2;
    for (int i = 0; i < N ; i ++)
    {
        if (table[i] != NULL)
        {
            temp = table[i];
            while (temp != NULL)
            {
                temp2 = temp->next;
                free(temp);
                temp = temp2;
            }
            temp2 = temp;
            free(temp);
        }
    }
    return true;

    return false;
}
