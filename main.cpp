#include <iostream>

using namespace std;

int Generate_Memory_Block(int Memory_Block_Table) {
    int generate_memory_block = rand() % 100 + 25;
    if (Memory_Block_Table >= generate_memory_block){
        Memory_Block_Table -= generate_memory_block;
    } else {
        cout << "Out of memory space" << endl;
        return Memory_Block_Table;
    }
    return Memory_Block_Table;
}

int * PCB(){
    int * PCB = rand();
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
            Memory_Block_Table = Generate_Memory_Block(Memory_Block_Table);
            cout << Memory_Block_Table << " Total Block remaining" << endl;
            cout << PCB() << " PCB" << endl;
        }

        else {
            cout << "Error, input number menu" << endl;
        }
    }
    return 0;
}
