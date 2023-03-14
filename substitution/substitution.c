#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string s = argv[argc - 1];
    if (argc > 3)
    {
        printf("ERROR\n");
        return 1;
    }
    if (argc < 1)
    {
        printf("ENTER KEY\n");
        return 1;
    }
    int n = strlen(argv[argc - 1]);
    if (n != 26)
    {
        printf("KEY MUST BE 26 CHARACTERS\n");
        return 1;
    }
    for (int i = 0; i < n ; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            printf("NOT ONLY LETTERS\n");
            return 1;
        }
    }
    //int check = error(s);
    int sum = 0;
    for (int d = 0; d < n; d++)
    {
        //toupper = char toupper((int) keys[i]);
        sum += (int)toupper(s[d]);
    }
    if (sum != 2015)
    {
        printf("DUPLICATA\n");
        return 1;
    }

    for (int t = 0; t < n; t++)
    {
        for (int h = 0; h < n; h++)
        {
            if (t == h)
            {
                continue;
            }
            if (islower(s[t]))
            {
                char current_key_letter = s[t];
            }
            else
            {
                char current_key_letter = s[t] + 'A' - 'a';
            }
            if (s[t] == s[h])
            {
                printf("Key must contain 26 unique characters.\n");
                return 1;
            }
        }

    }


    string plain = get_string("plaintext: ");

    int q = strlen(plain);
    int trans = 0;
    char translation[q];

    for (int z = 0 ; z < q; z++)
    {
        if (isalpha(plain[z]) != 0)
        {
            if (isupper(plain[z]) != 0)
            {
                trans = (plain[z]) - 65;
                translation[z] = tolower(s[trans]);
                translation[z] = toupper(translation[z]);
            }
            else
            {
                trans = (plain[z]) - 97;
                translation[z] = tolower(s[trans]);
            }
        }
        else
        {
            translation[z] = plain[z];
        }
    }
    translation[q] = '\0';
    printf("ciphertext: %s", translation);
    printf("\n");
    return 0;
}

