#include <iostream>

using namespace std;

int * Initiate(int generate_memory_block) {

    //b and c
    int * PCB;
    PCB = new int[4];
    PCB[0] = rand();

    PCB[1] = 5; //default size, accomplish not related to assignment

    int *PageTable;
    PageTable = new int[generate_memory_block];

    PCB[2] = *PageTable;
    return PCB;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int Memory_Block_Table = 512 - 32;
    cout << Memory_Block_Table << endl;

    int user_input_number = 0;

    while (user_input_number != 5){
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
            int * PCB = Initiate(generate_memory_block);
            cout << Memory_Block_Table << " Total Block remaining" << endl;
            cout << PCB[0] << " " << PCB[1] << " " << PCB[2] << " PCB" << endl;
        }

        if (user_input_number == 2){
            for (int n = 0; n < 10000; n++){
                cout << rand() % (120 - 25 + 1) + 25 << endl;
            }
            cout << endl;
        }

        else {
            cout << "Error, input number menu" << endl;
        }
    }
    return 0;
}
