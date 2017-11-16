using namespace std;

int jmp(string str)
{
    int loop = -1;
    for(int i = 0; i < length; i++)
    {
        if(str == code[i].addr)
        {
            loop = i;
        }
    }
    return loop;
}
