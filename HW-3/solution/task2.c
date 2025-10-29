#include <stdio.h>

int main()
{
    // A = 65, Z=90
    int hash_table[26] = {0};
    char duplicated_letters[13];
    char missing_letters[25];
    int missing_count = 0, duplicated_count = 0;
    char string[27]; // 26 letters + null terminator
    int string_length = 0;
    int i = 0;
    scanf("%s", string);
    for (i = 0; i < 26; i++)
    {
        if (string[i] == '\0')
        {
            string_length = i;
            break;
        }
        hash_table[string[i] - 'A'] += 1;
    }
    for (i = 0; i < string_length; i++)
    {
        if (hash_table[i] == 0)
        {
            missing_letters[missing_count] = (char)(i + 'A');
            missing_count += 1;
        }
        else if (hash_table[i] > 1)
        {
            duplicated_letters[duplicated_count] = (char)(i + 'A');
            duplicated_count += 1;
        }
    }
    if (missing_count == 0)
    {
        printf("NO MISSING");
    }
    else
    {
        for (i = 0; i < duplicated_count; i++)
        {
            printf("%c", duplicated_letters[i]);
        }
        printf("\n");
        for (i = 0; i < missing_count; i++)
        {
            printf("%c", missing_letters[i]);
        }
    }
    return 0;
}