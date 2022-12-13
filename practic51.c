#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h> // system("cls");
#include <time.h>

#define ESC 27

int verify_int(int *), random(int, int), var_str_size, b, cmpfunc(const void *, const void *), verify_choise_case(int);
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
            int n_size, str_size, choise_case;

            do
            {
                printf("\nNumber of elements: ");
            } while ((verify_int(&n_size) == 1));
            do
            {
                printf("Size of each string: ");
            } while ((verify_int(&str_size) == 1));

            char list[n_size][str_size + 1];
            char *addr[n_size];

            printf("\nGenerated list: \n\n");
            generateList(n_size, str_size, addr, list);
            displayList(n_size, str_size, list);

            do
            {
                printf("Choose the way of sorting array, 1 for quicksort or 2 for bubble sort: ");
            } while ((verify_int(&choise_case) == 1) || (verify_choise_case(choise_case) == 1));

            clock_t t;
            t = clock();
            if (choise_case == 1)
            {
                qsort(addr, n_size, sizeof(int), cmpfunc);
            }
            else
            {
                sort(addr, n_size);
            }
            t = clock() - t;
            double time_taken = ((double)t) / CLOCKS_PER_SEC;

            printf("\nSorted list in %.50f: \n\n", time_taken);
            displayList(n_size, str_size, list);
        }
    } while (key != ESC);
}

int verify_choise_case(int var_choise_case)
{
    if ((var_choise_case == 1) || (var_choise_case == 2))
    {
        return 0;
    }
    printf("Invalid choise of case. Try again!\n");
    return 1;
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

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort(char **pointers, int size)
{
    for (short i = 0; i < size - 1; i++)
    {
        for (short j = i + 1; j < size; j++)
        {
            if (strcmp(pointers[i], pointers[j]) > 0)
            {
                char temp[strlen(pointers[j])];
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