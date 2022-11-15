#include <iostream>

int main()
{
    int size;
    int num;
    int sizeHolder;

    int *A;
    int i = 0;
   
    while (!std::cin.eof())
    {
        // get the size
        std::cin >> size;
        sizeHolder = size;
        size *= 2;

        // allocate twice the memory
        A = new int[size];

        //read all the inputs except the size 
        while (size)
        {
            std::cin >> num;
            A[i] = num;
            i++;
            size--;
        }
        std::cout << sizeHolder << std::endl;

        // start from the center of the array... and go the end;
        //  while j starts at start of the array to the center
        int end = sizeHolder;
        for (int j = 0; j < sizeHolder; j++)
        {
            A[j] = A[j] * A[end];
            end++;
            std::cout << A[j] << " ";
        }

        //free mem

        delete[] A;
        i = 0;

        std::cout << std::endl;
    }
}