#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h> // system("cls");

#define ESC 27

int verify_int(int *), random(int, int), var_str_size, b;
void clear(), sort(char **, int), generateList(int, int, char **, char[][var_str_size + 1]), displayList(int, int, char[][b + 1]);

int main()
{
    char key;
    do
    {
        printf("Press any button to keep going or escape to quit.");
        key = getch();
        if (key != ESC)
        {
            int n_size, str_size;

            do
            {
                printf("\nNumber of elements:\n");
            } while ((verify_int(&n_size) == 1));
            do
            {
                printf("Size of each string:\n");
            } while ((verify_int(&str_size) == 1));

            char list[n_size][str_size + 1];
            char *addr[n_size];

            printf("\nGenerated list: \n\n");
            generateList(n_size, str_size, addr, list);
            displayList(n_size, str_size, list);
            sort(addr, n_size);

            getch();

            printf("\nSorted list: \n\n");
            displayList(n_size, str_size, list);
        }
    } while (key != ESC);
}

void generateList(int var_n_str, int var_str_size, char **pointer_to_arr, char (*array)[var_str_size + 1])
{
    char index;
    for (int i = 0; i < var_n_str; i++)
    {
        int j = 0;

        do
        {
            index = random(65, 122);
            if ((index >= 65 && index <= 90) || (index >= 97 && index <= 122))
            {
                array[i][j] = index;
                j++;
            }
        } while (j < var_str_size);

        array[i][j] = '\0';
        pointer_to_arr[i] = array[i];
    }
}

int random(int bottom, int top)
{
    return bottom + rand() % (top - bottom + 1);
}

void displayList(int a, int b, char array[][b + 1])
{
    for (int i = 0; i < a; i++)
    {
        printf("%d --> %s\n", i + 1, array[i]);
    }
}

void sort(char **pointers, int size)
{
    for (short i = 0; i < size - 1; i++)
    {
        for (short j = i + 1; j < size; j++)
        {
            if (strcmp(pointers[i], pointers[j]) > 0)
            {
                char temp[strlen(pointers[j]) + 1];
                strcpy(temp, pointers[j]);
                strcpy(pointers[j], pointers[i]);
                strcpy(pointers[i], temp);
            }
        }
    }
}

int verify_int(int *variable_int)
{
    char ch;
    scanf("%d%c", variable_int, &ch);
    if (ch != '\n')
    {
        printf("Invalid number. Try again!\n");
        clear();
        return 1;
    }
    else
    {
        if (*variable_int > 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void clear()
{
    int character;
    while ((character = getchar()) != '\n' && character != EOF) // end of file
        ;
}