using namespace std;

void adressing()
{
    
    stringstream ss;
    ss << starting_address;
    string s = ss.str();
    starting_address = hexToDec(s);
    int addre[length+1];
    addre[1] = starting_address;
    for(int i = 2; i <= length; i++)
    {
        addre[i] = addre[i-1] + c(code[i-1].mnemonic);
    }
    for(int i = 1; i <= length; i++)
    {
        code[i].addr = (decToHex(addre[i]));
    }
}
void get_code_write()
{
    string str = "";
    int temp = 0;
    cout << "Enter Starting Address \n";
    cin >> starting_address;
    int temp2 = starting_address;
    stringstream ss;
    ss << temp2;
    string s = ss.str();
    temp2 = hexToDec(s);
    int addre1[100];
    addre1[0] = temp2;
    int abc = 1,PC = 0;
    while(1)
    {
        str.clear();
        getline(cin,str);
        cout << decToHex(addre1[abc-1]) << ": ";
        addre1[0] += 4  ;
        PC += 3;
        if(str == "HLT") break;
        if(str == "START") continue;
        length++;
        string temp1 = "";
        int i = 0;
        while(str[i] != ' ')
        {
            temp1 += str[i];
            i++;
        }
        addre1[abc] = addre1[abc-1] + c(temp1);
        abc++;
        i++;
        PC += c(temp1);
        code[temp].mnemonic = temp1;
        if(i == str.size()) continue;
        temp1 = "";
        while(str[i] != ',' && i < str.size())
        {
            temp1 += str[i];
            i++;
        }
        i+=2;
        code[temp].reg1 = temp1;
        if(i == str.size()) continue;
        temp1 = "";
        while(str[i] != ' ' && i < str.size())
        {
            temp1 += str[i];
            i++;
        }
        code[temp].reg2 = temp1;
        temp++;
    }
    cout << "\n";
    adressing();
}

void get_code_file(string file_name)
{
    ifstream obj(file_name);
    string str = "";
    int temp = 0;
    obj >> starting_address;
    while(1)
    {
        str.clear();
        getline(obj,str);
        if(str == "HLT") break;
        if(str == "START") continue;
        length++;
        string temp1 = "";
        int i = 0;
        while(str[i] != ' ')
        {
            temp1 += str[i];
            i++;
        }
        i++;
        code[temp].mnemonic = temp1;
        if(i == str.size()) continue;
        temp1 = "";
        while(str[i] != ',' && i < str.size())
        {
            temp1 += str[i];
            i++;
        }
        i+=2;
        code[temp].reg1 = temp1;
        if(i == str.size()) continue;
        temp1 = "";
        while(str[i] != ' ' && i < str.size())
        {
            temp1 += str[i];
            i++;
        }
        code[temp].reg2 = temp1;
        temp++;
    }
    adressing();
    cout << "\n";
}
