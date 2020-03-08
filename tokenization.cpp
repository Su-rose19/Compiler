#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string line,op="+-*/%";
    int f;
    ifstream myfile ("inputtoken.cpp");
    ofstream myfile2("out.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line<<endl;
            myfile2<<line<<endl;
            // f=line.find("main()");
            if(line.find("#include")!=string::npos)
            {
                printf("  :   headerfile\n");
                myfile2<<"  :   headerfile\n";
            }
            else if(line.find("main()")!=string::npos)
            {
                printf("  :   mainfunction\n");
                myfile2<<"  :   mainfunction\n";
            }
            else if(line.find("printf")!=string::npos)
            {
                printf("  :   given output, printf is   library function\n");
                myfile2<<"  :   given output, printf is   library function\n";
            }
            else if(line.find("scanf")!=string::npos)
            {
                printf("  :   taken input, scanf is   library function\n");
                myfile2<<"  :   taken input, scanf is   library function\n";
            }
            else if(line.find("int")!=string::npos)
            {
                printf("  :   declare variable int type data\n");
                myfile2<<"  :   declare variable int type data\n";
            }
            else if(line.find("float")!=string::npos)
            {
                printf("  :   declare variable float type data\n");
                myfile2<<"  :   declare variable float type data\n";
            }
            else if(line.find("string")!=string::npos)
            {
                printf("  :   declare string\n");
                myfile2<<"  :   declare string\n";
            }
            else if(line.find("char")!=string::npos)
            {
                printf("  :   declare variable char type\n");
                myfile2<<"  :  declare variable char type\n";
            }
            else if(line.find("return")!=std::string::npos)
            {
                printf("  :   return from function\n");
                myfile2<<"  :   return from function\n";
            }
            else
            {
                for(int j=0; j<op.length(); j++)
                    if(line.find(op[j])!=std::string::npos)
                    {
                        printf("  :   mathematical operation\n");
                        myfile2<<"  :   mathematical operation\n";
                    }
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    return 0;
}
