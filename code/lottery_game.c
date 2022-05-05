/*
Program Desc: 
Lotto Game that allows to enter 6 numbers and give them a set of options
{
    1. Enter any 6 Numbers (1 - 42 Inclusive) AND different from each other
    {
        Checks if the values are different from the rest in the array.
    }
    2. Display your chosen lotto Numbers 
    {
        Display the valid array from option 1.
    }
    3. Sort your lotto Numbers
    {
        Using Insertion sort sort the array into ascending order
    }
    4. Compare for winning Numbers
    {
        Checking the frequency of winning numbers appear in the sorted array
    }
    5. Show Frequency of Numbers selected
    {
        Show the frequency of the numbers that have been entered
    }
    6. Close Program
}

Author: Ernest John Decina
Date: 13th March 2022

Due Date: 20th March 2022
Edited By:
*/

// Libraries 
#include <stdio.h>

// Symbolic Names
#define SIZE_ARRAY 6
#define LIMIT 42

// Function Signatures
int user_input_array(int *, int *); // Input numbers into array
void display_array(int *); // Display content of array
int insertion_sort_array(int *); // Sort array in order
int compare_array(int *); // Counts winning numbers then compares to any jackopts
void frequency_array(int *); // Prints frequency of a number
void end_program(char *); // Ends Program
void clear_buffer(void); // Clears input buffer


int main()
{
    // Variables
    int user_nums[SIZE_ARRAY] = {0};
    int frequency_nums[LIMIT] = {0};
    char menu_status = 'n';
    int array_status = 0;
    int sort_status = 0;
    int compare_status = 0;
    int frequency_status = 0; 
    int menu_option = 0;

    // Menu Display
    do
    {
        // Printing Out Menu
        printf("\n\n\n1.Enter any 6 Numbers (1 - 42 Inclusive) AND different from each other");
        printf("\n2.Display your chosen lotto Numbers");
        printf("\n3.Sort your lotto Numbers");
        printf("\n4.Compare for winning Numbers");
        printf("\n5.Show Frequency of Numbers selected");
        printf("\n6.Close Program"); 

        // Scanning User Input
        printf("\n\nChoose option: ");
        scanf("%d", &menu_option);

        switch (menu_option)
        {
            // 1.Enter 6 Numbers
            case 1:
            {
                // Call Function
                array_status = user_input_array(user_nums, frequency_nums);

                break;
            } // End case 1:

            // 2.Display 6 Numbers
            case 2:
            {
                // Checking if Numbers have been entered.
                if(array_status == 1)
                {
                    display_array(user_nums);
                } // End if
                else
                {
                    printf("\nNo numbers have been Entered.");
                } // End else

                break;
            } // End case 2:

            // 3.Array Insertion_Sort
            case 3:
            {
                // Function call
                if(array_status == 1)
                {
                    sort_status = insertion_sort_array(user_nums);
                } // End if
                else
                {
                    printf("\nNo numbers have been Entered.");
                } // End else


                break;
            } // End case 3:

            // 4.Compare Winning Values
            case 4:
            {
                // Checking if Numbers have been sorted
                if(sort_status == 1)
                {
                    compare_status = compare_array(user_nums);

                    // Reset Values
                    sort_status = 0;
                    array_status = 0;
                    
                    // Reset User nums back to 0
                    for (register int i = 0; i < SIZE_ARRAY; i++)
                    {
                        user_nums[i] = 0;
                    } // End for
                } // End if
                else
                {
                    printf("\nNumbers havent been sorted.");
                } // End else

                break;
            } // End case 4:

            // 5.Show Frequency
            case 5:
            {
                // Checking if Numbers have been compared 
                frequency_array(frequency_nums);

                break;
            } // End case5:

            // 6.End Program
            case 6:
            {
                end_program(&menu_status);
                break;
            } // End case 5:

            default:
            {
                printf("\nInvalid Input, Try again.");

                break;
            } // End default
        } // End Switch
 
        clear_buffer(); // Clearing Input Buffer
    } while (menu_status == 'n');
    
    // End Program
    return 0;

} // End main

// Functions
//
// user_input_array(int [])
// allows user to input values into the array using pointer notation
// parameter 1: int *input, inputs data using pointer to the array located in main 
// parameter 2: int *frequency, checks number then increments it using pointer to the array located in main
int user_input_array(int *input, int *frequency)
{
    // Entering Values into Array using Pass by Refrence
    for (register int i = 0; i < SIZE_ARRAY; i++)
    {
        printf("\nEnter number %d: ", (i + 1));
        clear_buffer();
        scanf("%d", (input + i));

        // Checking is in range
        while (*(input + i) > 42 || *(input + i) < 0 || *(input + i) == 0)
        {
            printf("\nInvalid Number Entered. Try again.");

            // Re Trying Enter
            printf("\nEnter number %d: ", (i + 1));
            clear_buffer();
            scanf("%d", input + i);

        } // End While
        
        // Checking number is different
        for (register int j = 0; j < i; j++)
        {
            // While loop incase user input same number again
            while (*(input + i) == *(input + j))
            {
                printf("\nInvalid Number Entered. Try again.");

                // Re Trying Enter
                printf("\nEnter number %d: ", (i + 1));
                clear_buffer();
                scanf("%d", input + i);
                
            }  // End While
            
        } // End for

        // Incrementing Frequency
        *(frequency + (*(input + i)-1)) = *(frequency + (*(input + i) - 1)) + 1; // 1 == frequency[0] Therefore *(sorted + i)-1)
        
    } // End for

    return 1;    
} // End user_input_array(int [])

// display_array(int *)
// displays the contents of the array to the user in the terminal
// parameter 1: inr pointer to an array to access its contents with creating copy 
void display_array(int *array_nums)
{
    // Displaying Values in the user_nums[]
    printf("\nNumbers you Entered are:");
    for (register int i = 0; i < SIZE_ARRAY; i++)
    {
        printf("\nNumber %d: %d", (i + 1), *(array_nums + i));
    } // End for
    
} // End 

// insertion_sort_array(int *)
// sorts the array in asceding order using insertion sort
// parameter 1: int *unsorted, puts the unsorted array into an insertion array algo then sorts it in ascending order
int insertion_sort_array(int *unsorted)
{
    int swap = 0;

    for(register int i = 1; i < SIZE_ARRAY; i++)
    {
        int current = *unsorted + i; // First Element 
        register int j = i;
        while(j > 0 && *(unsorted + j - 1) > *(unsorted + j))
        {
            // Swap && Finding correct position
            swap = *(unsorted + j);
            *(unsorted + j) = *(unsorted + j - 1);
            *(unsorted + j - 1) = swap;

            j--;
        } // End while
    } // End for

    // Return
    return 1;
} // End sort_array(int [])

// int compare_array(int *)
// Counts the amount of winning numbers then matches it with a winning prize
// parameter 1: int pointer to the storted array 
int compare_array(int *(sorted))
{
    // Variables
    static int winning_nums[SIZE_ARRAY] = {1, 3, 5, 7, 9, 11}; // Winning numbers
    int matching_nums = 0;
    int mid = (winning_nums[2] + winning_nums[3]) / 2;

    // Compare Values of sorted[] with winning_nums[]
    for (register int i = 0; i < SIZE_ARRAY; i++)
    { 
        if (*(sorted + i) < mid)
        {
            for (register int  j = 0; j < 3; j++)
            {
                // Checking if Numbers Match
                if (*(sorted + i) == winning_nums[j])
                {
                    matching_nums++;
                } // End if
            } // End for
        } // End if
        else
        {
            for (register int  j = 3; j < SIZE_ARRAY; j++)
            {
                // Checking if Numbers Match
                if (*(sorted + i) == winning_nums[j])
                {
                    matching_nums++;
                } // End if
            } // End for
        } // End else
    } // End for

    printf("");

    // Checking JackPot
    switch (matching_nums)
    {
        case 3:
        {
            printf("\nMatch 3: Cinema pass");
            break;
        } // End 3

        case 4:
        {
            printf("\nMatch 4: Weekend away");
            break;
        } // End 4

        case 5:
        {
            printf("\nMatch 5: New car");
            break;
        } // End 5

        case 6:
        {
            printf("\nMatch 6: Jackpot");
            break;
        } // End 6

        default:
        {
            printf("\nNo Winning Prizes");
            break;
        }// End default
    } // End Switch
    
    // Returning status
    return 1;

} // End compare_array(int [])

// void frequency_array(int *number_frequency)
// displays the frequency of numbers used in the program to the terminal
// parameter 1: int pointer to the frequency array with increments of the times the numbers been used
void frequency_array(int *number_frequency)
{
    for (register int i = 0; i < LIMIT; i++)
    {
        if(*(number_frequency + i) != 0)
        {
            printf("\nnumber %d has been %d", (i + 1), *(number_frequency + i));
        } // End if
    } // End for
} // End frequency_array(int *)

// void end_program(char *)
// ends the program
// parameter 1: char pointer with the defrerence value
void end_program(char *menu_char)
{
    // Asking user if they're sure
    clear_buffer(); // Clear Buffer
    printf("\nAre you sure? (y/n): ");
    scanf("%c", menu_char);
    
    // Error Checking
    while (*menu_char != 'y' && *menu_char != 'n')
    {
        printf("\nIvalid Input, try again (y/n): ");
        clear_buffer(); // Clear Buffer
        scanf("%c", menu_char);
    } // End while
} // End void end_program(char *);

// void clear_buffer(void)
// Clears input buffer
void clear_buffer(void)
{
    while(getchar() != '\n');
} // End clear_buffer(void)
