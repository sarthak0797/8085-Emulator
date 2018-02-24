#include "arithmatic.h"
#include "move.h"
#include "jump.h"

using namespace std;
int codes(int i)
{
    if(code[i].mnemonic == "SET")
            SET(code[i].reg1,code[i].reg2);
        if(code[i].mnemonic == "LDA")
            LDA(code[i].reg1);
        if(code[i].mnemonic == "STA")
            STA(code[i].reg1);
        if(code[i].mnemonic == "MOV")
        {
            char ch = code[i].reg1[0];
            char ch1 = code[i].reg2[0];
            MOV(ch,ch1);
        }
        if(code[i].mnemonic == "MVI")
        {
            char ch = code[i].reg1[0];
            MVI(ch,code[i].reg2);
        }
        if(code[i].mnemonic == "LXI")
        {
            char ch = code[i].reg1[0];
            LXI(ch, code[i].reg2);
        }
        if(code[i].mnemonic == "LHLD")
            LHLD(code[i].reg1);
        if(code[i].mnemonic == "SHLD")
            SHLD(code[i].reg1);
        if(code[i].mnemonic == "STAX")
        {
            STAX(code[i].reg1[0]);
            
        }
        if(code[i].mnemonic == "XCHG")
            XCHG();
        if(code[i].mnemonic == "ADD")
        {
            char ch = code[i].reg1[0];
            ADD(ch);
        }
        if(code[i].mnemonic == "ADI")
            ADI(code[i].reg1);
        if(code[i].mnemonic == "SUB")
        {
            char ch = code[i].reg1[0];
            SUB(ch);
        }
        if(code[i].mnemonic == "INR")
            INR(code[i].reg1[0]);
        if(code[i].mnemonic == "DCR")
            DCR(code[i].reg1[0]);
        if(code[i].mnemonic == "INX")
            INR(code[i].reg1[0]);
        if(code[i].mnemonic == "DCX")
            DCX(code[i].reg1[0]);
        if(code[i].mnemonic == "DAD")
            DAD(code[i].reg1[0]);
        if(code[i].mnemonic == "SUI")
            SUI(code[i].reg1);
        if(code[i].mnemonic == "JMP")
        {
            i = jmp(code[i].reg1);
            if(i == -1)
            {
                cout << "NOT A VALID ADDRESS AT JUMP COMMAND";
                exit(0);
            }
            else i--;
        }
        if(code[i].mnemonic == "JC")
        {
            int loop = i;
            while(C)
            {
                loop = jmp(code[i].reg1);
                if(loop == -1)
                {
                    cout << "NOT A VALID ADDRESS AT JUMP COMMAND";
                    exit(0);
                }
                codes(loop);
            }
        }
        if(code[i].mnemonic == "JNC")
        {
            int loop = i;
            while(!C)
            {
                loop = jmp(code[i].reg1);
                if(loop == -1)
                {
                    cout << "NOT A VALID ADDRESS AT JUMP COMMAND";
                    exit(0);
                }
                codes(loop);
            }
        }
        if(code[i].mnemonic == "JZ")
        {
            int loop = i;
            while(ZF)
            {
                loop = jmp(code[i].reg1);
                codes(loop);
            }
        }
        if(code[i].mnemonic == "JNZ")
        {
            int loop = i;
            while(!ZF)
            {
                loop = jmp(code[i].reg1);
                if(loop == -1)
                {
                    cout << "NOT A VALID ADDRESS AT JUMP COMMAND";
                    exit(0);
                }
                codes(loop);
            }
        }
        return i;
}


void non_debugger()
{
    for(int i = 1; i <= length; i++)
    {
        i = codes(i);
        if(code[i].mnemonic == "DCR" || code[i].mnemonic == "INR")
        {
            setflags(code[i].reg1[0]);
        }
        else setflags('A');
        if(code[i].mnemonic == "STA")
        {
            if(!mapp[code[i].reg1])
            {
                mapp[code[i].reg1] = 1;
                a.push_back(code[i].reg1);
            }
        }
    }
}

void debugger()
{
    while(1)
    {
        char choice;
        int brea, i = 1,mem;
        bool ch2,flag = 0;
        string str;
        cout << "Enter b to set break point \t r to run the program till break point \t s to run program one instruction at a time \t p to print value at any memory location \t q to quit debugger \n";
        cin >> choice;
        switch(choice)
        {
        case 'b':
            cout << "Enter line number where you wish to set break point";
            cin >> brea;
            continue;
        case 'r':
            while(i != brea)
            {
                if(i == length)
                {
                    flag = 1;
                    break;
                }
                i = codes(i);
                i++;
                if(code[i].mnemonic == "DCR" || code[i].mnemonic == "INR")
                {
                    setflags(code[i].reg1[0]);
                }
                else setflags('A');
                if(code[i].mnemonic == "STA")
                {
                    if(!mapp[code[i].reg1])
                    {
                        mapp[code[i].reg1] = 1;
                        a.push_back(code[i].reg1);
                    }
                }
            }
            flag = 1;
            break;
        case 's':
            do
            {
                if(i == length)
                {
                    flag = 1;
                    break;
                }
                i = codes(i);
                i++;
                if(code[i].mnemonic == "DCR" || code[i].mnemonic == "INR")
                {
                    setflags(code[i].reg1[0]);
                }
                else setflags('A');
                if(code[i].mnemonic == "STA")
                {
                    if(!mapp[code[i].reg1])
                    {
                        mapp[code[i].reg1] = 1;
                        a.push_back(code[i].reg1);
                    }
                }
                cout << "Press 1 to continue 0 to exit this mode";
                cin >> ch2;
            }while(ch2);
            continue;
        case 'p':
            cout << "Enter the memory location whose value is to be printed";
            cin >> str;
            mem = hexToDec(str);
            cout << memory[mem];
            continue;
        case 'q':
            flag = 1;
            cout << "Thank You";
            break;
        }
        if(flag) break;
    }
}
