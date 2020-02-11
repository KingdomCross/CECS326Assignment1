/**
 * Alex Chheng
 * CECS 326 Assignment 1
 */
#include <iostream>

using namespace std;

int PID = 0; //Global value
int Memory_Block_Table = 512 - 32; //Global memory space

int * Initiate(int generate_memory_block) {
    int GMB = generate_memory_block;
    //b and c
    int * PCB;
    PCB = new int[4];

    //PID, unique process ID
    ::PID = ::PID + 1; //Adding value id
    PCB[0] = PID;

    PCB[1] = 5; //default size, accomplish not related to assignment

    int *PageTable;
    PageTable = new int[GMB];
    //Attempt to create a page table with usage of generated memory block
    PCB[2] = GMB;
    return PCB; //Store it into readyqueue
}

void PrintSystem(int * Process_Control_Block){
    int MBT = ::Memory_Block_Table; //organize
    int * PCB = Process_Control_Block; //organize pointer
    cout << MBT << " Total Block remaining" << endl; // output
    cout << PCB[0] << " PID " << PCB[1] << " Size " << PCB[2] << " Page Table" << endl; //output PCB
}

void Terminate(int generate_memory_block, int * Process_Control_Block){
    int GMB = generate_memory_block; //organize
    int * PCB = Process_Control_Block; //organize

    if(generate_memory_block == 0 || PCB == nullptr){ //Make sure there is no empty value, else return error
        cout << "Error, there is not PCB or used memory space" << endl;
        return;
    }

    int user_input;
    cout << "Input search PID value" << endl;
    cin >> user_input;
    if (PCB[0] == user_input){
        delete PCB; //delete pointer
        ::Memory_Block_Table += GMB; //restore memory block
    }
    else{
        cout << "PID value invalid" << endl;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << ::Memory_Block_Table << endl;

    int user_input_number = 0;

    int * PCB = nullptr; //Default value
    int ** ReadyQueue;
    bool exit = false; //For the while loop
    int generate_memory_block = 0;
    while (!exit){
        cout << "Select menu " << endl;
        cin >> user_input_number;
        if (user_input_number == 1){
            //a, it need to return two value and function can only return one (Memory_Block_Table, generate_memory_block)
            generate_memory_block = rand() % (120 - 25 + 1) + 25; //high = 120, low = 25, http://www.cplusplus.com/forum/beginner/102036/
            if (::Memory_Block_Table >= generate_memory_block){
                ::Memory_Block_Table -= generate_memory_block;
            } else {
                cout << "Out of memory space" << endl;
                break;
            }

            //generate PCB
            PCB = Initiate(generate_memory_block);
            ReadyQueue = &PCB; //Attempt to create another array to store pointer array
            //cout << Memory_Block_Table << " Total Block remaining" << endl;
            //cout << PCB[0] << " " << PCB[1] << " " << PCB[2] << " PCB" << endl;
            //cout << ReadyQueue << " ReadyQueue" << endl;
        }

        else if (user_input_number == 2){
            PrintSystem(PCB); //Print function
        }

        else if (user_input_number == 3){
            Terminate(generate_memory_block, PCB); //Terminate function
        }

        else if (user_input_number == 4){
            cout << "Are you sure you want to exit the program? [Press 5 to exit]" << endl;
            cin >> user_input_number;
            if (user_input_number == 5){ //Ask for user confirmation
                exit = true; //Exit program
            }
            else{
                cout << "You are continuing the program" << endl; //Continue
            }
        }

        else {
            cout << "Error, input number menu" << endl;
        }
    }
    return 0;
}
