#include <iostream>

using namespace std;

int PID = 0;

int * Initiate(int generate_memory_block) {
    int GMB = generate_memory_block;
    //b and c
    int * PCB;
    PCB = new int[4];

    //PID, unique process ID
    ::PID = ::PID + 1;
    PCB[0] = PID;

    PCB[1] = 5; //default size, accomplish not related to assignment

    int *PageTable;
    PageTable = new int[GMB];
    //Attempt to create a page table with usage of generated memory block
    PCB[2] = GMB;
    return PCB; //Store it into readyqueue
}

void PrintSystem(int Memory_Block_Table, int * Process_Control_Block){
    int MBT = Memory_Block_Table;
    int * PCB = Process_Control_Block;
    cout << MBT << " Total Block remaining" << endl;
    cout << PCB[0] << " PID " << PCB[1] << " Size " << PCB[2] << " Page Table" << endl;
}

void Terminate(){

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int Memory_Block_Table = 512 - 32;
    cout << Memory_Block_Table << endl;

    int user_input_number = 0;

    int * PCB = nullptr;
    int ** ReadyQueue;
    bool exit = false;
    while (!exit){
        cout << "Select menu " << endl;
        cin >> user_input_number;
        if (user_input_number == 1){
            //a, it need to return two value and function can only return one (Memory_Block_Table, generate_memory_block)
            int generate_memory_block = rand() % (120 - 25 + 1) + 25; //high = 120, low = 25, http://www.cplusplus.com/forum/beginner/102036/
            if (Memory_Block_Table >= generate_memory_block){
                Memory_Block_Table -= generate_memory_block;
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
            PrintSystem(Memory_Block_Table, PCB); //Print function
        }

        else if (user_input_number == 3){
            Terminate(); //Terminate function
        }

        else if (user_input_number == 4){
            cout << "Are you sure you want to exit the program? [Press 5 to exit]" << endl;
            cin >> user_input_number;
            if (user_input_number == 5){
                exit = true;
            }
            else{
                cout << "You are continuing the program" << endl;
            }
        }

        else {
            cout << "Error, input number menu" << endl;
        }
    }
    return 0;
}
