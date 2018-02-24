using namespace std;
int c(string str)
{
    map<string, int> op;
	op["LDA"] = 3;
	op["MOV"] = 2;
    	op["MVI"] = 2;
    	op["ADD"] = 2;
	op["ADI"] = 2;
	op["LHLD"] = 3;
	op["SHLD"] = 3;
	op["LXI"] = 3;
	op["STA"] = 2;
	op["STAX"] = 3;
	op["XCHG"] = 3;
	op["SUB"] = 3;
	op["INR"] = 3;
	op["DCR"] = 3;
	op["INX"] = 3;
	op["DCX"] = 3;
	op["DAD"] = 2;
	op["SUI"] = 2;
	op["CMA"] = 3;
	op["CMP"] = 3;
	op["JMP"] = 3;
	op["JC"] = 3;
	op["JNC"] = 3;
	op["JZ"] = 3;
	op["JNZ"] = 3;
	op["SET"] = 3;
	op["HLT"] = 3;
	if(!op[str]) return -1;
	else return op[str];
}

