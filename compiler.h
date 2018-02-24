void compile()
{
    
    for(int i = 1; i < length-1; i++)
    {
        if(c(code[i].mnemonic) == -1 )
        {
            cout << "ERROR AT LINE " << i;
            exit(0);
        }
        else
        {
            if(code[i].mnemonic == "SET")
            {
                int mem = hexToDec(code[i].reg1);
                if(mem > 28671 || code[i].reg1.size() > 4)
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
                check_FF(code[i].reg2,i);
            }
            if(code[i].mnemonic == "LDA" || code[i].mnemonic == "STA")
            {
                int mem = hexToDec(code[i].reg1);
                if(mem > 28671 || code[i].reg1.size() > 4)
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "MOV")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L')
                {
                    if(code[i].reg2[0] == 'A' || code[i].reg2[0] == 'B' || code[i].reg2[0] == 'C' || code[i].reg2[0] == 'D' || code[i].reg2[0] == 'E' || code[i].reg2[0] == 'H' || code[i].reg2[0] == 'L');
                    else
                    {
                        cout << "ERROR AT LINE " << i;
                        exit(0);
                    }
                }
                else
                {
                    cout << "ERROR AT LINE " << i;
                }
            }
            if(code[i].mnemonic == "MVI")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
                check_FF(code[i].reg2,i);
            }
            if(code[i].mnemonic == "LXI")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
                int mem = hexToDec(code[i].reg2);
                if(mem > 28671 || code[i].reg1.size() > 4)
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "LHLD")
            {
                int mem = hexToDec(code[i].reg1);
                if(mem > 28671 || code[i].reg1.size() > 4)
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "SHLD")
            {
                int mem = hexToDec(code[i].reg1);
                if(mem > 28671 || code[i].reg1.size() > 4)
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "STAX")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "XCHG")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "ADD")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L' || code[i].reg1[0] == 'M');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "ADI")
            {
                check_FF(code[i].reg1,i);
            }
            if(code[i].mnemonic == "SUB")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L' || code[i].reg1[0] == 'M');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "INR")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L' || code[i].reg1[0] == 'M');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "DCR")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L' || code[i].reg1[0] == 'M');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "INX")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "DCX")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "DAD")
            {
                if(code[i].reg1[0] == 'A' || code[i].reg1[0] == 'B' || code[i].reg1[0] == 'C' || code[i].reg1[0] == 'D' || code[i].reg1[0] == 'E' || code[i].reg1[0] == 'H' || code[i].reg1[0] == 'L');
                else
                {
                    cout << "ERROR AT LINE " << i;
                    exit(0);
                }
            }
            if(code[i].mnemonic == "SUI")
            {
                check_FF(code[i].reg1,i);
            }
        }
    }
}
