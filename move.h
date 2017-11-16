using namespace std;

void SET(string mem_addr, string data)
{
    int mem = hexToDec(mem_addr);
    memory[mem] = data;
}

void LDA(string mem_addr)
{
    int mem = hexToDec(mem_addr);
    registers[0] = memory[mem];
}

void STA(string mem_addr)
{
    int mem = hexToDec(mem_addr);
    memory[mem] = registers[0];
}

void MOV(char treg1, char treg2)
{
    registers[treg1 - 'A'] = registers[treg2 - 'A'];
}

void MVI(char treg, string data)
{
    registers[treg - 'A'] = data;
}

void LXI(char ch, string data)
{
    string temp = "";
    string temp1 = "";
    temp += data[0];
    temp += data[1];
    temp1 += data[2];
    temp1 += data[3];
    if(ch == 'H')
    {
        registers[7] = temp;
        registers[11] = temp1;
    }
    else
    {
        registers[ch - 'A'] = temp;
        registers[ch - 'A' + 1] = temp1;
    }
}

void LHLD(string temp)
{
    int mem = hexToDec(temp);
    registers[7] = memory[mem+1];
    registers[11] = memory[mem];
}

void SHLD(string temp)
{
    int mem = hexToDec(temp);
    memory[mem+1] = registers[7];
    memory[mem] = registers[11] ;
}

void STAX(char ch)
{
    int treg1, treg2;
    if(ch == 'H')
    {
        treg1 = 7;
        treg2 = 11;
    }
    else
    {
        treg1 = ch - 'A';
        treg2 = ch - 'A' + 1;
    }
    int addre = hexToDec(registers[treg1])*100 + hexToDec(registers[treg2]);
    memory[addre] = registers[0];
}

void XCHG()
{
    string temp = registers[7];
    registers[7] = registers[3];
    registers[3] = temp;
    temp = registers[11];
    registers[11] = registers[4];
    registers[4] = temp;
}
