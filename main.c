#include <stdio.h>
#include <limits.h>

int get_squares(void);

int main()
{
    int errors_handling = 1;  // Used to handle get_squares execution errors. I was unable to reproduce any.
    errors_handling = get_squares();
    return errors_handling;
}

int get_squares(void)         // It was not clear from task if N&M are function arguments or should be entered from console.
// I decided to implement console input because it's more interesting case IMHO.  
{
    unsigned int n_size = 0;  // N max size is limited UINT_MAX (as soon as there are no limits defined in task description)
    unsigned int m_size = 0;  // M max size is limited UINT_MAX (as soon as there are no limits defined in task description)

    int c = 0;                // Number input by characters

    // This input sequence is kind of overwhelmed to protect from invalid console input
    printf("Enter an positive integer: N = ");
    while (((c = getchar()) != EOF && c != '\n') || (n_size == 0)) // Repeat while "Enter" not pressed to confirm user's input
    {
        if (c >= '0' && c <= '9')                   // Check for only numerical characters were entered
        {
            if (n_size < n_size * 10 + c - '0')     // Check for either 0 input or data type overflow
            {
                n_size = n_size * 10 + c - '0';     // Apply new digit to N size value
            }
            else
            {
                while ((c = getchar()) != EOF && c != '\n');    // Clear stdin buffer
                printf("ERROR! The value of N you entered is either 0 or too big. It should be 0 < N < %u.\nEnter an positive integer: N = ", UINT_MAX);
                n_size = 0;                         // Reset N size
            }
        }
        else if (c == EOF || c == '\n')             // Attempt to enter the EMPTY value
        {
            printf("ERROR! Empty input value.\nEnter an positive integer: N = ");
            n_size = 0;                             // Reset N size
        }
        else                                        // Not numerical character in input stream.  Clear stdin buffer and reset N size
        {
            while ((c = getchar()) != EOF && c != '\n');        // Clear stdin buffer
            printf("ERROR! N must be positive integer number.\nEnter an positive integer: N = ");
            n_size = 0;                             // Reset N size
        }
    }

    // This input sequence is kind of overwhelmed to protect from invalid console input
    printf("Enter an positive integer: M = ");
    while (((c = getchar()) != EOF && c != '\n') || (m_size == 0)) // Repeat while "Enter" not pressed to confirm user's input
    {
        if (c >= '0' && c <= '9')                   // Check for only numerical characters were entered
        {
            if (m_size < m_size * 10 + c - '0')     // Check for either 0 input or data type overflow
            {
                m_size = m_size * 10 + c - '0';     // Apply new digit to M size value
            }
            else
            {
                while ((c = getchar()) != EOF && c != '\n');    // Clear stdin buffer
                printf("ERROR! The value of N you entered is either 0 or too big. It should be 0 < M < %u.\nEnter an positive integer: M = ", UINT_MAX);
                m_size = 0;                         // Reset M size
            }
        }
        else if (c == EOF || c == '\n')             // Attempt to enter the EMPTY value
        {
            printf("ERROR! Empty input value.\nEnter an positive integer: M = ");
            m_size = 0;                             // Reset M size
        }
        else                                        // Not numerical character in input stream.  Clear stdin buffer and reset M size
        {
            while ((c = getchar()) != EOF && c != '\n');        // Clear stdin buffer
            printf("ERROR! N must be positive integer number.\nEnter an positive integer: M = ");
            m_size = 0;                             // Reset M size
        }
    }

    // Provides Input data formatted according to task requirements
    printf("Input: N = %u, M = %u\n", n_size, m_size);

    // Provides Output data formatted according to task requirements
    printf("Output: ");

    while (n_size != m_size) // Check if this rectangle is not square
    {
        if (n_size < m_size)
        {
            m_size -= n_size; // Cut square from rectangle 
            printf("%ux%u, ", n_size, n_size);
        }
        else if (n_size > m_size)
        {
            n_size -= m_size; // Cut square from rectangle 
            printf("%ux%u, ", m_size, m_size);
        }
    }

    if ((n_size == m_size) && (n_size != 0)) // Output for the last square (actually it can be the first one square)
    {
        printf("%ux%u", n_size, m_size);
    }
    return 0;
}

