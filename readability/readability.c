#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float l = 0;
float w = 0;
float s = 0;
float index = 0;

int main(void)
{
    string text = get_string("Text: \n");
    l = count_letters(text);
    w = count_words(text);
    s = count_sentences(text);
    //printf("%f letters , %f words , %f sentences \n",l,w,s);
    float li = l / w * 100;
    float se = s / w * 100;
    index = 0.0588 * li - 0.296 * se - 15.8;
    index = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}
int count_words(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words;
}
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == 46) || (text[i] == 63) || (text[i] == 33))
        {
            sentences++;
        }
    }
    return sentences;

}