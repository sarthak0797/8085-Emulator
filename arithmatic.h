using namespace std;

void ADD(char ch)
{
    if(ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' || ch == 'E' || ch == 'H' || ch == 'L')
    {
        int data = hexToDec(registers[ch-'A']);
        int data1 = hexToDec(registers[0]);
        registers[0] = decToHex(data+data1);
    }
    else if(ch == 'M')
    {
        int addre = hexToDec(registers[7])*100 + hexToDec(registers[11]);
        int data = hexToDec(memory[addre]);
        int data1 = hexToDec(registers[0]);
        registers[0] = decToHex(data+data1);
    }
    else cout << "INVLAID REGiSTER \n";
}

void ADI(string str)
{
    int data = hexToDec(str);
    int data1 = hexToDec(registers[0]);
    registers[0] = decToHex(data+data1);
}

void SUB(char ch)
{
    if(ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' || ch == 'E' || ch == 'H' || ch == 'L')
    {
        int data = hexToDec(registers[ch-'A']);
        int data1 = hexToDec(registers[0]);
        registers[0] = decToHex(data1+data);
    }
    else if(ch == 'M')
    {
        
        int addre = hexToDec(registers[7])*100 + hexToDec(registers[11]);
        int data = hexToDec(memory[addre]);
        int data1 = hexToDec(registers[0]);
        registers[0] = decToHex(data+data1);
    }
    else cout << "INVLAID REGiSTER \n";
}

void INR(char ch)
{
    int data = hexToDec(registers[ch - 'A']);
    data++;
    registers[ch - 'A'] = decToHex(data);
}

void DCR(char ch)
{
    int data = hexToDec(registers[ch - 'A']);
    data--;
    registers[ch - 'A'] = decToHex(data);
}

void INX(char ch)
{
    int data = hexToDec(registers[ch - 'A']);
    data++;
    registers[ch - 'A'] = decToHex(data);
    if(ch == 'H')
    {
        data = hexToDec(registers[11]);
        data++;
        registers[11] = decToHex(data);
    }
    else
    {
        data = hexToDec(registers[ch - 'A' + 1]);
        data++;
        registers[ch - 'A' + 1] = decToHex(data);
    }
}

void DCX(char ch)
{
    int data = hexToDec(registers[ch - 'A']);
    data--;
    registers[ch - 'A'] = decToHex(data);
    if(ch == 'H')
    {
        data = hexToDec(registers[11]);
        data--;
        registers[11] = decToHex(data);
    }
    else
    {
        data = hexToDec(registers[ch - 'A' + 1]);
        data--;
        registers[ch - 'A' + 1] = decToHex(data);
    }
}

void DAD(char ch)
{
    int data = hexToDec(registers[ch - 'A']);
    int data1 = hexToDec(registers[7]);
    registers[7] = decToHex(data+data1);
    if(ch == 'H')
    {
        data = hexToDec(registers[11]);
    }
    else
    {
        data = hexToDec(registers[ch - 'A' + 1]);
    }
    registers[11] = decToHex(data+data1);
}

void SUI(string str)
{
    int data = hexToDec(str);
    int data1 = hexToDec(registers[0]);
    registers[0] = decToHex(data1-data);
}
