#include <stdio.h>
#include <stdlib.h>
const int MAX_STATE_COUNT = 8;
const int GENERATION_COUNT = 50;
const int ARRAY_LENGTH = 100;

void print_state(int state_to_print[], int state_length)
{ //decides which character to print
    int i;
    for (i = 0; i < state_length; i++)
    {
        if (state_to_print[i] == 0)
            printf("_ ");
        if (state_to_print[i] == 1)
            printf("# ");
    }
    printf("\n");
}

void initialize_array(int array_to_initialize[], int state_length)
{ // fill array with 0
    int i;
    for (i = 0; i < state_length; i++)
    {
        array_to_initialize[i] = 0;
    }
}

void swap_arrays(int current_state[], int next_state[], int array_length)
{ // swap next state with current state
    int i;
    for (i = 0; i < array_length; i++)
    {
        current_state[i] = next_state[i];
    }
}

void calculate_next_state(int current_state[], int next_state[], int rule[])
{ // look the 3 value and calculate nexr state by rule
    int i;
    for (i = 0; i < ARRAY_LENGTH; i++)
    {
        if (current_state[i] == 0 && current_state[i + 1] == 0 && current_state[i + 2] == 0)
        {
            next_state[i + 1] = rule[0];
        }
        if (current_state[i] == 0 && current_state[i + 1] == 0 && current_state[i + 2] == 1)
        {
            next_state[i + 1] = rule[1];
        }
        if (current_state[i] == 0 && current_state[i + 1] == 1 && current_state[i + 2] == 0)
        {
            next_state[i + 1] = rule[2];
        }
        if (current_state[i] == 0 && current_state[i + 1] == 1 && current_state[i + 2] == 1)
        {
            next_state[i + 1] = rule[3];
        }
        if (current_state[i] == 1 && current_state[i + 1] == 0 && current_state[i + 2] == 0)
        {
            next_state[i + 1] = rule[4];
        }
        if (current_state[i] == 1 && current_state[i + 1] == 0 && current_state[i + 2] == 1)
        {
            next_state[i + 1] = rule[5];
        }
        if (current_state[i] == 1 && current_state[i + 1] == 1 && current_state[i + 2] == 0)
        {
            next_state[i + 1] = rule[6];
        }
        if (current_state[i] == 1 && current_state[i + 1] == 1 && current_state[i + 2] == 1)
        {
            next_state[i + 1] = rule[7];
        }
    }
}

void main()
{
    int i;
    int middle_point = (ARRAY_LENGTH / 2) - 1;
    int current_state[100], next_state[100];
    int rule[8] = {0, 1, 1, 1, 1, 0, 0, 0};

    initialize_array(current_state, ARRAY_LENGTH); // fill array with 0
    initialize_array(next_state, ARRAY_LENGTH);    // fill array with 0
    current_state[middle_point] = 1;               // middle point equals to 1
    print_state(current_state, ARRAY_LENGTH);      // print first state

    for (i = 1; i < GENERATION_COUNT; i++)
    { // In this loop send array to functions
        calculate_next_state(current_state, next_state, rule);
        swap_arrays(current_state, next_state, ARRAY_LENGTH);
        print_state(current_state, ARRAY_LENGTH);
    }
    system("PAUSE");
}
