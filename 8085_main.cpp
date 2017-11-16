#include "all.h"
#include "opcode.h"
#include "inputs.h"
#include "run.h"
#include "compiler.h"

using namespace std;

int main()
{
    int ch = 1;
    cout << "Enter 1 to type the code \t\t 2 to get code from file \t\t 3 to exit \n";
    cin >> ch;
    if(ch == 1) get_code_write();
    else if(ch == 2)
    {
        cout << "Enter file name \n";
        string temp;
        cin >> temp;
        get_code_file(temp);
    }
    else
    {
        cout << "Thank You\n";
        return 0;
    }
    compile();
    cout << "Enter 1 to run in debugger mode 2 to run in normal mode \n";
    cin >> ch;
    if(ch == 1) debugger();
    else if(ch == 2)
    {
        non_debugger();
    }
    else
    {
        cout << "WRONG CHOICE";
        return 0;
    }
    cout << "Value of register A is " << registers[0] << "\n";
    cout << "Value of register B is " << registers[1] << "\n";
    cout << "Value of register C is " << registers[2] << "\n";
    cout << "Value of register D is " << registers[3] << "\n";
    cout << "Value of register E is " << registers[4] << "\n";
    cout << "Value of register H is " << registers[7] << "\n";
    cout << "Value of register L is " << registers[11] << "\n";
}
