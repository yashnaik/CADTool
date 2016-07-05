// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stdlib.h>

using namespace std;
void display(vector<string> &pieces);
int readylist(string a,string b,int c);
int mulist(string d,string x,int e);
void alaptime(string x,int y,int z);
int readylir(string a,string b,string c,string d,int e);

vector<string> inputs;
vector<string> outputs;
vector<string> wires;
vector<string> regs;
vector<string> combo;

string listarr[35];
int k8=0;
int listct[35];
int ya=1;
int h12=0;
int chemul[35];
int lat;
int ti=0;
int h11=0;
string mularr[35];
int f1=0;
int h10=0;
int chesta[35];
string check[35];
int r; //number of registers
int o; //number of outputs
int reg[35];
float delay_of_r=0;   //delay of reg component

struct node{
                string output;
                string input1;
                string input2;
                string input3;
                string operation;
                string stmt;
                string condition;
                string bracket1;
                string bracket2;
                string bracket3;
                string bracket4;
                string delay;
                int sch;
                int alaptime;
                int actime;
                int schnow;
                int schr;
                int schtime;
            };
                node line[35];
                float l2=0;
                int R_FLAG=0;

int main(int argc, char** argv) {

	if( argc != 4 && argc != 5 && argc != 2 && argc !=  7)
	{
		cerr<<endl<<"Usage: "<<argv[0]<<" { -ns -listl -listr -help } cfile verilogfile { mul add logic latency"<<endl<<endl;
		return -1;
	}

	if( string(argv[1]) == "-listl")
	{
		if( argc != 7 )
		{
			cerr<<endl<<"Usage: "<<argv[0]<<" -listl cfile verilogfile mul add logic"<<endl<<endl;
			return -1;
		}

		cout<<"Command Executed: "<<argv[0]<<" "<<argv[1]<<" "<<argv[2]<<" "<<argv[3]<<" "<<argv[4]<<" "<<argv

[5]<<" "<<argv[6]<<endl;
	}
	else if ( string(argv[1]) == "-listr" )
	{
		if( argc != 5 )
		{
			cerr<<endl<<"Usage: "<<argv[0]<<" -listr cfile verilogfile latency"<<endl<<endl;
			return -1;
		}

		cout<<"Command Executed: "<<argv[0]<<" "<<argv[1]<<" "<<argv[2]<<" "<<argv[3]<<" "<<argv[4]<<endl;
	}
	else if ( string(argv[1]) == "-ns" )
	{
		if( argc != 4 )
		{
			cerr<<endl<<"Usage: "<<argv[0]<<" -ns cfile verilogfile"<<endl<<endl;
			return -1;
		}

		cout<<"Command Executed: "<<argv[0]<<" "<<argv[1]<<" "<<argv[2]<<" "<<argv[3]<<endl;
	}
	else if(string(argv[1]) == "-help")
	{
		cerr<<endl<<"Usage: hlsyn -ns cfile verilogfile"<<endl<<" or "<<endl<<"Usage: hlsyn -listl cfile verilogfile mul add logic"<<endl<<" or"<<endl<<"Usage: hlsyn -listr cfile verilogfile latency" <<endl;
	}
	else
	{
		cerr<<endl<<"Usage: "<<argv[0]<<"{ -ns -listl -listr -help } cfile verilogfile { mul add logic latency"<<endl<< endl;
		return -1;
	}




//int main()




struct delay{
                string type;
                string quantity;
                string delay;
            };
                delay n_delay[35];

string line1;
string line2;
string line3;
string str4;
string temp;
string word;


int token_cnt=0;
int C_FLAG=0;
int W_FLAG=0;
int I_FLAG=0;
int O_FLAG=0;
int FLAG2=0;

int i=0;
int k=0;
int v1=0;
int v2=0;
int k4;
int k3;

int z1[100];
int z2[100];
int z3=0;

int i1=0;
int i2=0;

int source[35];
int sink[35];
int sinkr[35];
int sourcer[35];
int sinko[35];
float max=0;
int COUNT=0;

vector<string> pieces;
string M;
char b;
ifstream myfile1(argv[2]); ////(argv[2]);
if (myfile1.is_open())
{
    //cout<<"T";
    while(!myfile1.eof())
    {
        getline (myfile1,line1);
        if(line1.empty())
            {}
        else
        {
        if((line1.find("//") != std::string::npos))
                 {}
        else
        {
        if((line1.find_first_of('='))!=-1)
        {
                if(COUNT==0)
                {
                    cout<<"Equations are given before parameters declaration";
                    return -1;
                }
                char character1[] = {'+','-','*'};
                char character2[] = {'?',':'};
                char character3[] = {'>','<'};
                vector<string> tokens;
                stringstream s(line1);
                string temp;
                while(s>> temp)
                {
                    tokens.push_back(temp);
                }
                int pos = line1.find_first_of(character1, 0, sizeof(character1));
                if ((pos !=std::string::npos) && (tokens.size()==5))
                {
                    line[i].output=tokens[0];
                    line[i].input1=tokens[2];
                    line[i].input2=tokens[4];
                    line[i].input3="0";
                    line[i].operation=tokens[3];
                    if((line[i].operation)=="+")    {}
                    if((line[i].operation)=="*")    {}
                    if((line[i].operation)=="-")    {}
                    i=i+1;
                }
                else
                {
                int pos = line1.find_first_of(character2, 0, sizeof(character2));
                if((pos != std::string::npos) && (tokens.size()==7))
                {
                    line[i].output=tokens[0];
                    line[i].input1=tokens[2];
                    line[i].input2=tokens[4];
                    line[i].input3=tokens[6];
                    i=i+1;
                }
                else
                {
                string s1="<<";
                string s2=">>";
                if (((line1.find(s1) != std::string::npos) || (line1.find(s2) != std::string::npos)) && (tokens.size()==5))
                {
                    line[i].output=tokens[0];
                    line[i].input1=tokens[2];
                    line[i].input2=tokens[4];
                    line[i].input3="0";
                    if(line1.find(s1) != std::string::npos)
                    {
                        line[i].operation="<<";
                    }
                    else
                    {
                        line[i].operation=">>";
                    }
                    i=i+1;
                }
                else
                {
                int pos = line1.find_first_of(character3, 0, sizeof(character3));
                if((pos !=std::string::npos) && (tokens.size()==5))
                {
                    line[i].output=tokens[0];
                    line[i].input1=tokens[2];
                    line[i].input2=tokens[4];
                    line[i].input3="0";
                    line[i].operation=tokens[3];
                    if((line[i].operation)=="<")    {}
                    if((line[i].operation)==">")    {}
                    i=i+1;
                }
                else
                {
                string s1="==";
                if((line1.find(s1)!=std::string::npos) && (tokens.size()==5))
                {
                    line[i].output=tokens[0];
                    line[i].input1=tokens[2];
                    line[i].input2=tokens[4];
                    line[i].input3="0";
                    line[i].operation="==";
                    i=i+1;
                }
                else
                {
                if(tokens.size()==3)
                {
                    line[i].output=tokens[0];
                    line[i].input1=tokens[2];
                    line[i].input2="0";
                    line[i].input3="0";
                }
                else
                {
                    cout<<"invalid tokens";
                    return -1;
                }
                for(int v=0;v<outputs.size();++v)
                    if(line[i].output.compare(outputs[v])==0)
                            v1=1;
                i=i+1;
                }
                }
                }
                }

                }
        }
        else
        {
        if(line1.find("if")==std::string::npos && line1.find("while")==std::string::npos&&line1.find

("{")==std::string::npos&&line1.find("}")==std::string::npos)
        {

        COUNT=COUNT+1;
        int end;
        end = line1.find(":");
        if(end>=0)
        {
            int beginning=0;
            word = line1.substr(beginning,end);
            beginning = end + 1;
            b=word[0];
////////////////////////////////////////////////////////////inputs,outputs,regs,wires/////////////////////////////////////

///////////////////////////////
            string W="WIRES";
            string O="OUTPUTS";
            string R="REGS";
            string I="INPUTS";
            string b="{";
            string b4="}";
            combo.push_back(b4);
            combo.push_back(b);
            if((word.find(I))!=std::string::npos)
            {
                I_FLAG=1;
                line2=line1.substr(beginning);
                stringstream s(line2);
                while(s>> temp)
                {
                    inputs.push_back(temp);
                }
                for(int b1=0;b1<inputs.size();b1++)
                {
                    string b2=inputs[b1];
                    combo.push_back(b2);
                }
                for(int i7=0;i7<inputs.size();i7++)
                {
                    k4=0;
                    for(int i8=0;i8<inputs.size();i8++)
                    {
                        if((inputs[i8].compare(inputs[i7]))==0)
                        {   k4=k4+1;    }
                    }
                    if(k4>1)
                    {
                        cout<<"inputs are mentioned more than one times";
                        return -1;
                    }
                }

            }
            else
            {
            if((word.find(O))!=std::string::npos)
            {
                O_FLAG=1;
                line2=line1.substr(beginning);
                stringstream s(line2);
                while(s>> temp)
                {
                    outputs.push_back(temp);
                }
                for(int b1=0;b1<outputs.size();b1++)
                {
                    string b2=outputs[b1];
                    combo.push_back(b2);
                }
                for(int i7=0;i7<outputs.size();i7++)
                {
                    k4=0;
                    for(int i8=0;i8<outputs.size();i8++)
                    {
                        if((outputs[i8].compare(outputs[i7]))==0)
                            {   k4=k4+1;    }
                    }
                    if(k4>1)
                    {
                        cout<<"outputs are mentioned more than one times";
                        return -1;
                    }
                }
            }
            else
            if((word.find(W))!=std::string::npos)
            {
                W_FLAG=1;
                line2=line1.substr(beginning);
                stringstream s(line2);
                while(s>> temp)
                {
                    wires.push_back(temp);
                }
                for(int b1=0;b1<wires.size();b1++)
                {
                    string b2=wires[b1];
                    combo.push_back(b2);
                }
                for(int i7=0;i7<wires.size();i7++)
                {
                    k4=0;
                    for(int i8=0;i8<wires.size();i8++)
                    {
                        if((wires[i8].compare(wires[i7]))==0)
                            {   k4=k4+1;    }
                    }
                    if(k4>1)
                    {
                        cout<<"wires are mentioned more than one times";
                        return -1;
                    }
                }
            }
            else if((word.find(R))!=std::string::npos)
            {
                R_FLAG =1;
                line2=line1.substr(beginning);
                stringstream s(line2);
                while(s>> temp)
                {
                    regs.push_back(temp);
                }
                for(int b1=0;b1<regs.size();b1++)
                {
                    string b2=regs[b1];
                    combo.push_back(b2);
                }
                for(int i7=0;i7<regs.size();i7++)
                {
                    k4=0;
                    for(int i8=0;i8<regs.size();i8++)
                    {
                        if((regs[i8].compare(regs[i7]))==0)
                            {   k4=k4+1;    }
                    }
                    if(k4>1)
                    {
                        cout<<"registers are mentioned more than one times";
                        return -1;
                    }
                }
            }
            else
            {
                cout<<"Parameters are not given properly";
                return -1;
            }

            }

        }
        else
        {
            cout<<"parameters are not on single line";
            return -1;
        }
        }
        else
        {
            if(line1.find("if")!=-1)
            {
                vector<string> tokens;
                stringstream s(line1);
                string temp;
                while(s>> temp)
                {
                    tokens.push_back(temp);
                }
                for(int j=0; j<tokens.size(); j++)
                {
                    if(tokens[j]==" ")
                            continue;
                    else if(tokens[j]=="if")
                            line[i].stmt=tokens[j];
                    else if(tokens[j]=="(")
                            line[i].bracket1=tokens[j];
                    else if(tokens[j]==")")
                            line[i].bracket2=tokens[j];
                    else if(tokens[j]=="{")
                            line[i].bracket3=tokens[j];
                    else
                            line[i].condition=tokens[j];
                }
                i++;
            }
            else if(line1.find("while")!=-1)
            {
                vector<string> tokens;
                stringstream s(line1);
                string temp;
                while(s>> temp)
                {
                    tokens.push_back(temp);
                }
                for(int j=0; j<tokens.size(); j++)
                {
                    if(tokens[j]==" ")
                            continue;
                    else if(tokens[j]=="while")
                            line[i].stmt=tokens[j];
                    else if(tokens[j]=="(")
                            line[i].bracket1=tokens[j];
                    else if(tokens[j]==")")
                            line[i].bracket2=tokens[j];
                    else if(tokens[j]=="{")
                            line[i].bracket3=tokens[j];
                    else
                            line[i].condition=tokens[j];
                    }
                    i++;
            }
            else if(line1.find("{")!=-1 || line1.find("}")!=-1)
            {
                vector<string> tokens;
                stringstream s(line1);
                string temp;
                while(s>> temp)
                {
                    tokens.push_back(temp);
                }
                for(int j=0; j<tokens.size(); j++)
                {
                    if(tokens[j]=="{")
                            line[i].bracket3=tokens[j];
                    else if(tokens[j]=="}")
                            line[i].bracket4=tokens[j];
                }
                i++;
            }
        }
        }
        }
    }
}

///////////////////////////////////////////////////checking//////////////////////////////////////////////////////
for(int b=0;b<combo.size();++b)
{
    for (int b1=0;b1<combo.size();++b1)
    {
        if(combo[b]==combo[b1])
        {
        if(combo[b]!="{")

            C_FLAG=C_FLAG+1;
    }}
    if(C_FLAG>1)
    {if(combo[b]!="}"){
        cout<<"Parameters are declared more than once "<<combo[b];
        return -1;
    }
    }
    C_FLAG=0;
}

//////////////////////to check if all literals are there/////////
int v3=0;
for(int v1=0;v1<i;++v1)
{
    for(int v2=0;v2<combo.size();++v2)
    {
        if(line[v1].input1==combo[v2] || (line[v1].bracket3!="{" || line[v1].bracket4!="}"))
               v3=v3+1;
    }
    if(v3==0)
    {
        cout<<"Operand not declared 1 ";
        return -1;
    }
    v3=0;
}
v3=0;
for(int v1=0;v1<i;++v1)
{
    for(int v2=0;v2<combo.size();++v2)
    {
        if((line[v1].input2==combo[v2]) || (line[v1].input2=="0") || (line[v1].bracket3!="{" || line[v1].bracket4!="}"))
            v3=v3+1;
    }
    if(v3==0)
    {
        cout<<"Operand not declared 2";
        return -1;
    }
    v3=0;
}
v3=0;
for(int v1=0;v1<i;++v1)
{
    for(int v2=0;v2<combo.size();++v2)
    {
        if((line[v1].input3==combo[v2]) || (line[v1].input3=="0") || (line[v1].bracket3!="{" || line[v1].bracket4!="}"))
            v3=v3+1;
    }
    if(v3==0)
    {
        cout<<"Operand not declared 3";
        return -1;
    }
    v3=0;
}
v3=0;
for(int v1=0;v1<i;++v1)
{
    for(int v2=0;v2<combo.size();++v2)
    {
        if(line[v1].output==combo[v2] || (line[v1].bracket3!="{" || line[v1].bracket4!="}"))
            v3=v3+1;
    }
    if(v3==0)
    {
        cout<<"Operand not declared 4";
        return -1;
    }
    v3=0;
}

//////////////////////check if output is not assigned reg////////////
 v3=0;
for(int v1=0;v1<outputs.size();++v1)
{
    for(int v2=0;v2<i;++v2)
        if(line[v2].output==outputs[v1] )
        {
            if((line[v2].input2).compare("0")==0 || (line[v1].bracket3!="{" || line[v1].bracket4!="}"))
                {}
            else
            {
                cout<<"output register not mentioned ";
                return -1;
            }
        }
}

//////////////////////check if output is on left side of equation and input is on right side of equation//////////////////
v3=0;
for(int v1=0;v1<outputs.size();++v1)
{
    for(int v2=0;v2<i;++v2)
    {
        if((outputs[v1]==line[v2].input1) || (outputs[v1]==line[v2].input2) ||(outputs[v1]==line[v2].input3) || outputs

[v1]=="{" || outputs[v1]=="}")
            v3=v3+1;
    }
    if(v3==0)
        {}
    else
    {
        cout<<"error output variable value is assigned to some literal ";
        return -1;
    }
}
v3=0;
for(int v1=0;v1<inputs.size();++v1)
{
    for(int v2=0;v2<i;++v2)
    {
        if(inputs[v1]==line[v2].output || inputs[v1]=="{" || inputs[v1]=="}")
            v3=v3+1;
    }
    if(v3==0)
        {}
    else
    {
        cout<<"input variable is assigned some value ";
        return -1;
    }
}
}
else
{
    cout << "Unable to open file";return -1;
}

myfile1.close();



////////////////////////////////////////////////////tech_file_read////////////////////////////////////////////////////////

/////////
  /////////////////////////////////////////////////////store componets names in file//////////////////////////////
vector<string> tech_comp;
string REG="REG";
tech_comp.push_back(REG);
string ADD32="ADD32";
tech_comp.push_back(ADD32);
string SUB32="SUB32";
tech_comp.push_back(SUB32);
string MUL32="MUL32";
tech_comp.push_back(MUL32);
string COMPLT="COMPLT";
tech_comp.push_back(COMPLT);
string COMPGT="COMPGT";
tech_comp.push_back(COMPGT);
string COMPEQ="COMPEQ";
tech_comp.push_back(COMPEQ);
string MUX2x1="MUX2x1";
tech_comp.push_back(MUX2x1);
string SHL="SHL";
tech_comp.push_back(SHL);
string SHR="SHR";
tech_comp.push_back(SHR);

/////////////////////////////////////////////////////////////////actual

////////////////////////////////////////////////////////////////
/*ifstream myfile2 ("xil_s.lib");
if (myfile2.is_open())
{
    while(!myfile2.eof())
    {
        getline (myfile2,line1);
        if(line1.empty())
            {}
        else
        {
            if((line1.find("//") != std::string::npos))
            {
                if((line1.find("DELAY")!=std::string::npos))
                {
                    if((line1.find("ns")!=std::string::npos))
                        {}
                    else
                    {
                        cout<<"delay is not mentioned in nanoseconds";
                        return -1;
                    }

                }
                else
                    {}
            }
            else
            {
                 if((line1.find_first_of(':'))!=-1)
                 {
                    vector<string> tokens1;
                    stringstream s(line1);
                    string temp2;
                    while(s>> temp2)
                    {
                        tokens1.push_back(temp2);
                    }

                    n_delay[k].type=tokens1[0];
                    string k5=n_delay[k].type;
                    n_delay[k].quantity=tokens1[2];
                    string k1=n_delay[k].quantity;
                    int k2=atoi(k1.c_str());
                    n_delay[k].delay=tokens1[3];
                    if((k5.compare("REG"))==0)
                    {
                        delay_of_r=atof((n_delay[k].delay).c_str());
                    }
                    if(n_delay[k].type=="REG")
                    {
                        if(n_delay[k].quantity!="1")
                        {
                            cout<<"quantity of number of inputs to registers is wrong ";
                            return -1;
                        }
                    }
                    else if(n_delay[k].type=="MUX2x1")
                    {
                        if(n_delay[k].quantity!="3")
                        {
                            cout<<"quantity of number of inputs to mux is wrong ";
                            return -1;
                        }
                    }
                    else
                    {
                        if(n_delay[k].quantity!="2")
                        {
                            cout<<"quantity of number of inputs to component is wrong ";
                            return -1;
                        }
                    }
                    if(k2<1)
                    {
                        cout<<"number of components in line"<<k+1<<"are invalid";
                        return -1;
                    }
                    else
                        {}
                    if(((n_delay[k].delay).find_first_of('.'))==-1)
                    {
                        cout<<"delay for line"<<k+1<<"is given in  non floating form";
                        return -1;
                    }
                    else    {}
                    k3=0;
                    k4=0;
                    while(k3<10)
                    {
                        string k6=tech_comp[k3];
                        if((k5.compare(k6))==0)
                        {
                            k4=0;
                            k4=k4+1;
                        }
                        else    {}
                        k3++;
                    }
                    if(k4==0)
                    {
                        cout<<"Component names are invalid"<<endl;
                        return -1;
                    }
                    k=k+1;
                }
            }
        }
    }
}
else
{
    //cout<<"unable to open file";
    //return -1;
}*/
/*for(int i7=0;i7<10;i7++)
{
    k4=0;
    for(int i8=0;i8<10;i8++)
    {
        if(((n_delay[i8].type).compare(n_delay[i7].type))==0)
            k4=k4+1;
    }
    if(k4>1)
    {
        cout<<"components are mentioned more than one times";
        return -1;
    }
}
myfile2.close();
if(k!=10)
{
    cout<<"number of components in technology file are not valid";
    return -1;
}*/
ofstream o(argv[3]);///argv[3]
o << "`timescale 1ns / 1ps" <<endl;
o<<"module "<<string("HLSM")<<"(Clk,Rst,Start,Done ";
int h1=0;
while(h1!=inputs.size())
{
    o<<inputs[h1]<<",";
    h1++;
}
h1=0;
while(h1!=(outputs.size()-1))
{
    o<<outputs[h1]<<",";
    h1++;
}
o<<outputs[h1]<<");"<<endl<<endl;
o<<"input Clk,Rst;"<<endl;
o<<"input Start;"<<endl;
o<<" output Done;"<<endl;
h1=0;
while(h1!=inputs.size())
{
   o<<"input [31:0] "<<inputs[h1]<<";"<<endl;
   h1++;
}
h1=0;
while(h1!=outputs.size())
{
   o<<"output reg [31:0] "<<outputs[h1]<<";"<<endl;
   h1++;
}
h1=0;
while(h1!=regs.size())
{
   o<<"reg [31:0] "<<regs[h1]<<";"<<endl;
   h1++;
}
cout<<endl<<endl;
h1=0;

while(h1!=wires.size())
{
   o<<"reg [31:0] "<<wires[h1]<<";"<<endl;
   h1++;
}
h1=0;
o<<"reg state [5:0] = "<<i<<";"<<endl;
o<<endl;
/////////////////////////////states declaration/////////////
for(int t=0;t<i+3;t++)
{
    if( t<i)
    {
        o<<"parameter state"<<t+1<<" = "<<t<<";"<<endl;
    }
    else
    if(t<i+1)
    {
        o<<"parameter wait_state = "<<t<<";"<<endl;
    }
    else if(t<i+2)
    {
        o<<"parameter final_state = "<<t<<";"<<endl;
    }
    else
    {
       o<<"parameter mul_dummy ="<<t<<";"<<endl;
    }

}
o<<endl;
///////////////////////////////////////////////instantiation/////////////////////////
int out_cnt=0;
int reg_cnt=0;
int add_cnt=0;
int sub_cnt=0;
int mul_cnt=0;
int compgt_cnt=0;
int complt_cnt=0;
int compeq_cnt=0;
int mux_cnt=0;
int shr_cnt=0;
int shl_cnt=0;
ostringstream buff1;
string h4;
int COT=0;
int bb=i;
int ab=0;
int ad_num;
int mul_num;
int log_num;
if(string(argv[1])=="-listl")
{
   //(string(argv[1]=="-listl")
 ad_num=atoi(argv[5]);///////////////////////////////////change here
 mul_num=atoi(argv[4]);
 log_num=atoi(argv[6]);
if(ad_num==0||mul_num==0||log_num==0)
{
    cout<<"inadequate resources";
    return -1;
}}
int adnum=ad_num;///////////////////////////////////////////////change here
int mulnum=mul_num;
int lognum=log_num;
int ar[i];
int h5;
int h8;
int stt=0;
int h9=0;
int r6=0;
////////////////////////////////////////////////////////////////////////////listl/////////////schdeuling
for(int h4=0;h4<i;h4++)
{line[h4].sch=0;}

////////////////////////////////////////////////////////////////////////////////////////numbering^^^^^^^^^^^
for(int m1=0;m1<i;m1++)
{
if(line[m1].bracket3=="{")
{bb=m1;r6=1;
//cout<<m1+1<<"finds {";
}
if(line[m1].bracket4=="}")
{ab=m1;
//cout<<m1+1<<"finds }";
}
}
if(r6==1&&ab==0)
{ cout<<" brackets incomplete";
return -1;
}
////////////////////////////////////////////////////////listl scheduling
o<<"always@( posedge Clk ) begin"<<endl;
o<<"if( Rst == 1 ) begin"<<endl;
for(int t=0;t<inputs.size();t++)
{
	    o<<inputs[t]<<"<=0;"<<endl;
}
for(int t=0;t<outputs.size();t++)
{
        o<<outputs[t]<<"<=0;"<<endl;
}
for(int t=0;t<regs.size();t++)
{
    o<<regs[t]<<"<=0;"<<endl;
}
o<<"Done<=0"<<endl;
o<<"state<=wait_state;"<<endl;
o<<"end"<<endl<<endl;
o<<"else begin"<<endl;
o<<"case(state)"<<endl;
o<<"wait_state: begin"<<endl;
o<<"if(Start==1)"<<"begin"<<endl<<"state<=state1;"<<endl<<"end"<<endl;
o<<"else  begin"<<endl<<"state<=wait_state;"<<endl<<"end"<<endl<<"end"<<endl;
/////////////////////////////////////////listr//////////
int alap=0;
int stct=1;
int asap=0;
int mtime=1;
////////////////////////////////////////////change here/////////////////////////////
if(string(argv[1])=="-listr")  //(string(argv[1])=="-listr")
{lat=atoi(argv[4]);}
int mulsuse=1;
int addsuse=1;
int logsuse=1;
int mulsnow=mulsuse;
int addsnow=addsuse;
int logsnow=logsuse;
int sttr=0;
int k6=0;
int k7=0;
int d=1;
int adds=addsuse;
int muls=mulsuse;
int logs=logsuse;
int n1=0;
int n2=0;
int n3=0;
int k12;
int k13;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////
if(string(argv[1])=="-listr")                 //(string(argv[1])=="-listr")
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////
for(int t4=0;t4<i;t4++)
{
    for(int t3=0;t3<bb;t3++)
{
    alaptime(line[t3].output,i,t3);
}


for(int t3=bb+1;t3<ab;t3++)
{
    alaptime(line[t3].output,ab,t3);
}

if(r6==1)
{for(int t3=ab+1;t3<i;t3++)
{
    alaptime(line[t3].output,bb,t3);
}}
}
for(int t3=0;t3<i;t3++)
{
   // cout<<line[t3].alaptime;
}

for(int t5=0;t5<i;t5++)
{
    line[t5].actime=lat-line[t5].alaptime;
    //cout<<line[t5].actime;
    if(line[t5].actime==0)
    {cout<<"latency too low";
    return -1;}
    //else{cout<<line[t5].actime;}
    }

for(int t5=0;t5<i;t5++)
{
    line[t5].schr=0;
    //cout<<line[t5].schr;
    }
for(int t7=0;t7<i;t7++)
{
    if(t7<bb)
    {
for(int t6=0;t6<bb;t6++)
{
//cout<<listarr[1]<<" "<<listct[1];
   //readylir(line[t6].input1,line[t6].input2,line[t6].input3,line[t6].operation,stct-1);
    //cout<<r1<<line[t6].operation<<endl<<listarr[t6];
    if(readylist(line[t6].input1,line[t6].input2,t7)==1)
    if(readylist(line[t6].input1,line[t6].input3,t7)==1)
    {int p=line[t6].actime-mtime;
    //cout<<line[t6].actime<<" "<<mtime;
        if(line[t6].actime-mtime==0)
    {
        if(line[t6].schr==0)
       {if(line[t6].actime-mtime==0)
        {line[t6].schnow=1;
        }}}
        else if(line[t6].actime-mtime==1||line[t6].actime-mtime==2||line[t6].actime-mtime==3||line[t6].actime-mtime==4)
              {//cout<<t7;
                  if(readylist(line[t6].input1,line[t6].input2,t7)==1)
            {//cout<<t7<<endl;
                if(line[t6].input2=="0")
                {line[t6].schnow=1;}
                else if(line[t6].operation=="+"||line[t6].operation=="-")
                {
                    if(adds!=0)
                    {
                        line[t6].schnow=2;
                    }

                }
                else if(line[t6].operation=="*")
                {if(muls!=0)
                {
                    line[t6].schnow=2;
                }
                }
                else if(logs!=0)

                {line[t6].schnow=2;
                }}}}


       /* else if(line[t6].actime-mtime==2)
        {//if(readylir(line[t6].input1,line[t6].input2,line[t6].input3,line[t6].operation,stct)==1)
            {
                if(line[t6].input2=="0")
                {line[t6].schnow=1;}
                else if(line[t6].operation=="+"||line[t6].operation=="-")
                {
                    if(adds!=0)
                    {
                        line[t6].schnow=2;
                    }

                }
                else if(line[t6].operation=="*")
                {if(muls!=0)
                {
                    line[t6].schnow=2;
                }
                }
                else if(logs!=0)

                {line[t6].schnow=2;
                }
        }
    }*/

 /* back:if(k2==1)
        {if(line[t6].actime-mtime==1)
      {

      }*/

    if((line[t6].schnow==1||line[t6].schnow==2)&&line[t6].schr==0)
    {
        if(line[t6].operation=="+"||line[t6].operation=="-")
        {
            if(line[t6].schnow==1)
            {if(adds==0)
            {adds=adds+1;
                addsnow=adds;}}

            if(adds!=0)
            {if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            stct++;
            sttr=1;}
            o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            adds--;
            k6=1;
            check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }}
        else if(line[t6].operation=="*")
        {   if(line[t6].schnow==1)
            {if(muls==0)
            {muls=muls+1;
            mulsnow=muls;}}
            if(muls!=0)
            {if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            muls--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7+1;
            k8++;
            k12=t7;


        }}
         if(line[t6].input2=="0")
        {
            if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<line[t6].output<<"<="<<line[t6].input1<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }
         if(line[t6].input3!="0")
        {   if(line[t6].schnow==1)
            {if(logs==0)
            {logs=logs+1;
            logsnow=logs;}}
            if(logs!=0)
            {if(sttr==0)
            {
                 d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<"if("<<line[t6].input1<<"==1) begin"<<endl;
            o<<line[t6].output<<"<="<<line[t6].input2<<";"<<endl<<"end"<<endl;
            o<<"else  begin"<<endl<<line[t6].output<<"<="<<line[t6].input3<<";"<<endl<<"end"<<endl;
                        line[t6].schnow=0;
            line[t6].schr=1;
            logs--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }}
         if(line[t6].operation==">>"||line[t6].operation=="<<"||line[t6].operation=="<"||line[t6].operation==">"||line

[t6].operation=="==")
        {   //cout<<line[t6].operation;
            if(line[t6].schnow==1)
            {if(logs==0)
            {logs=logs+1;
            logsnow=logs;}}
            if(logs!=0)
            {
                if(sttr==0)
            {  d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            if(line[t6].operation==">>"||line[t6].operation=="<<")
            {o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;}
            else
            {
                o<<"if("<<line[t6].input1<<line[t6].operation<<line[t6].input2<<")"<<endl;
                o<<"begin"<<endl<<line[t6].output<<"<=1;"<<endl<<"end"<<endl;
                o<<"else begin"<<endl<<line[t6].output<<"<=0;"<<endl<<"end"<<endl;
            }

             line[t6].schnow=0;
            line[t6].schr=1;
            logs--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;

        }}

    }
        }



/*if(muls!=0||adds!=0||logs!=0)
{
    goto back;
    k2=1;
}*/
  //cout<<listarr[t7]<<"  "<<listct[t7]<<endl;
 if(k6==0&&k12==t7-1)
    { if(line[bb-1].schr==1&&line[bb-2].schr==1&&line[bb-3].schr==1)
    {o<<"state"<<t7+1<<" : begin"<<endl;
    o<<"state<="<<"state"<<ab+1<<";"<<endl;
    }
       else
       { o<<"state"<<t7+1<<": begin"<<endl;
      o<<"state<="<<"state"<<t7+2<<";"<<endl;
      o<<"end"<<endl;}}

  else if(line[bb-1].schr==1&&line[bb-2].schr==1&&line[bb-3].schr==1&&r6==0)
{
    if(k7==0)
    {o<<"state<=final_state;"<<endl<<"end"<<endl;
k7=1;}
}
else if(k6==1)
{
    o<<"state<="<<"state"<<t7+2<<";"<<endl<<"end"<<endl;}

sttr=0;
if(mtime<lat)
{mtime++;}
//cout<<mtime;
adds=addsnow;
muls=mulsnow;
logs=logsnow;
k6=0;
}
if(t7==bb)
{if(line[t7].stmt=="if")
{o<<"state"<<t7+1<<":"<<" begin"<<endl;
o<<"if("<<line[t7].condition<<"==1) begin"<<endl;
o<<"state<=state"<<t7+2<<";"<<endl<<"end"<<endl;
o<<"else begin"<<endl<<"state<=state"<<ab+1<<";"<<endl<<"end"<<endl;
}
if(line[t7].stmt=="while")
{o<<"state"<<stct<<":"<<" begin"<<endl;
o<<"if("<<line[t7].condition<<"==1) begin"<<endl;
o<<"state<=state"<<t7+2<<";"<<endl<<"end"<<endl;
o<<"else begin"<<endl<<"state<=state"<<ab+3<<";"<<endl<<"end"<<endl;
}

}

if(t7>bb&&t7<ab)
{
    if(n1==0)
    {
        muls=mulsuse;
        adds=addsuse;
        logs=logsuse;
        mtime=1;
        for(int h1=bb+1;h1<ab;h1++)
        {
            //cout<<line[h1].schr==0;
        }

    n1=1;
    }
    for(int t6=bb+1;t6<ab;t6++)
{//cout<<line[t6].schr;
//cout<<listarr[1]<<" "<<listct[1];
   //readylir(line[t6].input1,line[t6].input2,line[t6].input3,line[t6].operation,stct-1);
    //cout<<r1<<line[t6].operation<<endl<<listarr[t6];
    if(readylist(line[t6].input1,line[t6].input2,t7)==1)
    if(readylist(line[t6].input1,line[t6].input3,t7)==1)
    {if(line[t6].actime-mtime==0)
    {//cout<<t7;
        if(line[t6].schr==0)
       {if(line[t6].actime-mtime==0)
        {line[t6].schnow=1;
        }}}
        else if(line[t6].actime-mtime==1||line[t6].actime-mtime==2||line[t6].actime-mtime==3||line[t6].actime-mtime==4)
              {//cout<<t7;
                  if(readylist(line[t6].input1,line[t6].input2,t7)==1)
            {//cout<<t7<<endl;
                if(line[t6].input2=="0")
                {line[t6].schnow=1;}
                else if(line[t6].operation=="+"||line[t6].operation=="-")
                {
                    if(adds!=0)
                    {//cout<<t7;
                        line[t6].schnow=2;
                    }

                }
                else if(line[t6].operation=="*")
                {if(muls!=0)
                {
                    line[t6].schnow=2;
                }
                }
                else if(logs!=0)

                {line[t6].schnow=2;
                }}}}


       /* else if(line[t6].actime-mtime==2)
        {//if(readylir(line[t6].input1,line[t6].input2,line[t6].input3,line[t6].operation,stct)==1)
            {
                if(line[t6].input2=="0")
                {line[t6].schnow=1;}
                else if(line[t6].operation=="+"||line[t6].operation=="-")
                {
                    if(adds!=0)
                    {
                        line[t6].schnow=2;
                    }

                }
                else if(line[t6].operation=="*")
                {if(muls!=0)
                {
                    line[t6].schnow=2;
                }
                }
                else if(logs!=0)

                {line[t6].schnow=2;
                }
        }
    }*/

 /* back:if(k2==1)
        {if(line[t6].actime-mtime==1)
      {

      }*/
           // cout<<line[t6].schr;
    if((line[t6].schnow==1||line[t6].schnow==2&&line[t6].schr==0))
    {//cout<<t7;
        if(line[t6].operation=="+"||line[t6].operation=="-")
        {
            if(line[t6].schnow==1)
            {if(adds==0)
            {adds=adds+1;
                addsnow=adds;}}

            if(adds!=0)
            {if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            stct++;
            sttr=1;}
            o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            adds--;
            k6=1;
            check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }}
        else if(line[t6].operation=="*")
        {   if(line[t6].schnow==1)
            {if(muls==0)
            {muls=muls+1;
            mulsnow=muls;}}
            if(muls!=0)
            {if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            muls--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7+1;
            k8++;
            k13=t7;


        }}
         if(line[t6].input2=="0")
        {
            if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<line[t6].output<<"<="<<line[t6].input1<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }
         if(line[t6].input3!="0")
        {   if(line[t6].schnow==1)
            {if(logs==0)
            {logs=logs+1;
            logsnow=logs;}}
            if(logs!=0)
            {if(sttr==0)
            {
                 d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<"if("<<line[t6].input1<<"==1) begin"<<endl;
            o<<line[t6].output<<"<="<<line[t6].input2<<";"<<endl<<"end"<<endl;
            o<<"else  begin"<<endl<<line[t6].output<<"<="<<line[t6].input3<<";"<<endl<<"end"<<endl;
                        line[t6].schnow=0;
            line[t6].schr=1;
            logs--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }}
         if(line[t6].operation==">>"||line[t6].operation=="<<"||line[t6].operation=="<"||line[t6].operation==">"||line[t6].operation=="==")
        {   //cout<<line[t6].operation;
            if(line[t6].schnow==1)
            {if(logs==0)
            {logs=logs+1;
            logsnow=logs;}}
            if(logs!=0)
            {
                if(sttr==0)
            {  d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            if(line[t6].operation==">>"||line[t6].operation=="<<")
            {o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;}
            else
            {
                o<<"if("<<line[t6].input1<<line[t6].operation<<line[t6].input2<<")"<<endl;
                o<<"begin"<<endl<<line[t6].output<<"<=1;"<<endl<<"end"<<endl;
                o<<"else begin"<<endl<<line[t6].output<<"<=0;"<<endl<<"end"<<endl;
            }

             line[t6].schnow=0;
            line[t6].schr=1;
            logs--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;

        }}

    }
        }
//cout<<check[t7];

/*if(muls!=0||adds!=0||logs!=0)
{
    goto back;
    k2=1;
}*/
  //cout<<listarr[t7]<<"  "<<listct[t7]<<endl;
 if(k6==0&&k13==t7-1)
    { o<<"state"<<t7+1<<": begin"<<endl;
      o<<"state<="<<"state"<<t7+2<<";"<<endl;
      o<<"end"<<endl;}

  else if(line[ab-1].schr==1&&line[ab-2].schr==1&&line[ab-3].schr==1)
{
    if(k7==0)
    {if(line[bb].stmt=="if")
        {o<<"state<="<<"state"<<ab+1<<";"<<endl<<"end"<<endl;}
        if(line[bb].stmt=="while")
        {o<<"state<="<<"state"<<ab+1<<";"<<endl<<"end"<<endl;}

k7=1;}
}
else if(k6==1)
{
    o<<"state<="<<"state"<<t7+2<<";"<<endl<<"end"<<endl;}

sttr=0;
if(mtime<lat)
{mtime++;}
//cout<<mtime;
adds=addsnow;
muls=mulsnow;
logs=logsnow;
k6=0;
}

if(t7==ab&&r6==1)
{
    if(line[bb].stmt=="if")
    {
        o<<"state"<<t7+1<<":  begin "<<endl;
        o<<"state<=state"<<ab+3<<";"<<endl;
        o<<"end"<<endl;
    }

    if(line[bb].stmt=="while")
    {
        o<<"state"<<t7+1<<": begin"<<endl;
        o<<"state<=state"<<bb+1<<";"<<endl<<"end"<<endl;
    }
}
if(t7>ab+1&&r6==1)
{

if(n2==0)
    {
        muls=mulsuse;
        adds=addsuse;
        logs=logsuse;
        mtime=1;
        n2=1;
        k7=0;
        k6=0;
    }


for(int t6=ab+1;t6<i;t6++)
{
//cout<<listarr[1]<<" "<<listct[1];
   //readylir(line[t6].input1,line[t6].input2,line[t6].input3,line[t6].operation,stct-1);
    //cout<<r1<<line[t6].operation<<endl<<listarr[t6];
    if(readylist(line[t6].input1,line[t6].input2,t7)==1)
    if(readylist(line[t6].input1,line[t6].input3,t7)==1)
    {if(line[t6].actime-mtime==0)
    {//cout<<t7;
        if(line[t6].schr==0)
       {if(line[t6].actime-mtime==0)
        {line[t6].schnow=1;
        }}}
        else if(line[t6].actime-mtime==1||line[t6].actime-mtime==2||line[t6].actime-mtime==3||line[t6].actime-mtime==4)
              {//cout<<t7;
                  if(readylist(line[t6].input1,line[t6].input2,t7)==1)
            {//cout<<t7<<endl;
                if(line[t6].input2=="0")
                {line[t6].schnow=1;}
                else if(line[t6].operation=="+"||line[t6].operation=="-")
                {
                    if(adds!=0)
                    {
                        line[t6].schnow=2;
                    }

                }
                else if(line[t6].operation=="*")
                {if(muls!=0)
                {
                    line[t6].schnow=2;
                }
                }
                else if(logs!=0)

                {line[t6].schnow=2;
                }}}}


       /* else if(line[t6].actime-mtime==2)
        {//if(readylir(line[t6].input1,line[t6].input2,line[t6].input3,line[t6].operation,stct)==1)
            {
                if(line[t6].input2=="0")
                {line[t6].schnow=1;}
                else if(line[t6].operation=="+"||line[t6].operation=="-")
                {
                    if(adds!=0)
                    {
                        line[t6].schnow=2;
                    }

                }
                else if(line[t6].operation=="*")
                {if(muls!=0)
                {
                    line[t6].schnow=2;
                }
                }
                else if(logs!=0)

                {line[t6].schnow=2;
                }
        }
    }*/

 /* back:if(k2==1)
        {if(line[t6].actime-mtime==1)
      {

      }*/

    if((line[t6].schnow==1||line[t6].schnow==2)&&line[t6].schr==0)
    {
        if(line[t6].operation=="+"||line[t6].operation=="-")
        {
            if(line[t6].schnow==1)
            {if(adds==0)
            {adds=adds+1;
                addsnow=adds;}}

            if(adds!=0)
            {if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            stct++;
            sttr=1;}
            o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            adds--;
            k6=1;
            check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }}
        else if(line[t6].operation=="*")
        {   if(line[t6].schnow==1)
            {if(muls==0)
            {muls=muls+1;
            mulsnow=muls;}}
            if(muls!=0)
            {if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            muls--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7+1;
            k8++;
            k12=t7;


        }}
         if(line[t6].input2=="0")
        {
            if(sttr==0)
            { d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<line[t6].output<<"<="<<line[t6].input1<<";"<<endl;
            line[t6].schnow=0;
            line[t6].schr=1;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }
         if(line[t6].input3!="0")
        {   if(line[t6].schnow==1)
            {if(logs==0)
            {logs=logs+1;
            logsnow=logs;}}
            if(logs!=0)
            {if(sttr==0)
            {
                 d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            o<<"if("<<line[t6].input1<<"==1) begin"<<endl;
            o<<line[t6].output<<"<="<<line[t6].input2<<";"<<endl<<"end"<<endl;
            o<<"else  begin"<<endl<<line[t6].output<<"<="<<line[t6].input3<<";"<<endl<<"end"<<endl;
                        line[t6].schnow=0;
            line[t6].schr=1;
            logs--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;
        }}
         if(line[t6].operation==">>"||line[t6].operation=="<<"||line[t6].operation=="<"||line[t6].operation==">"||line[t6].operation=="==")
        {   //cout<<line[t6].operation;
            if(line[t6].schnow==1)
            {if(logs==0)
            {logs=logs+1;
            logsnow=logs;}}
            if(logs!=0)
            {
                if(sttr==0)
            {  d=stct;
                o<<"state"<<t7+1<<":"<<" begin"<<endl;
            sttr=1;
            stct++;}
            if(line[t6].operation==">>"||line[t6].operation=="<<")
            {o<<line[t6].output<<"<="<<line[t6].input1<<line[t6].operation<<line[t6].input2<<";"<<endl;}
            else
            {
                o<<"if("<<line[t6].input1<<line[t6].operation<<line[t6].input2<<")"<<endl;
                o<<"begin"<<endl<<line[t6].output<<"<=1;"<<endl<<"end"<<endl;
                o<<"else begin"<<endl<<line[t6].output<<"<=0;"<<endl<<"end"<<endl;
            }

             line[t6].schnow=0;
            line[t6].schr=1;
            logs--;
            k6=1;
             check[k8]=line[t6].output;
            chesta[k8]=t7;
            k8++;

        }}

    }
        }


/*if(muls!=0||adds!=0||logs!=0)
{
    goto back;
    k2=1;
}*/
  //cout<<listarr[t7]<<"  "<<listct[t7]<<endl;
 if(k6==0&&k12==t7-1)
    { if(line[ab-1].schr==1&&line[ab-2].schr==1&&line[ab-3].schr==1)
    {o<<"state"<<t7+1<<" : begin"<<endl;
    o<<"state<="<<"state"<<ab+1<<";"<<endl;
    }
       else
       { o<<"state"<<t7+1<<": begin"<<endl;
      o<<"state<="<<"state"<<t7+2<<";"<<endl;
      o<<"end"<<endl;}}

  else if(line[i-1].schr==1&&line[i-2].schr==1&&line[i-3].schr==1)
{
    if(k7==0)
    {o<<"state<=final_state;"<<endl<<"end"<<endl;
k7=1;}
}
else if(k6==1)
{
    o<<"state<="<<"state"<<t7+2<<";"<<endl<<"end"<<endl;}

sttr=0;
if(mtime<lat)
{mtime++;}
//cout<<mtime;
adds=addsnow;
muls=mulsnow;
logs=logsnow;
k6=0;






}


}
//////////////////////////////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////for list1
if(string(argv[1])=="-listl")
{
//////////////////////////////////////////////////////////////////////////
for(int h3=0;h3<i;h3++)
{
    if(h3<bb)
{


if(h3+1<bb){

}
int h4=h3;
int h6=0;
for(int h4=h3;h4<bb;h4++)

   {if(readylist(line[h4].input1,line[h4].input2,h3))
   {if(readylist(line[h4].input1,line[h4].input3,h3))
   {//
   //if(mulist(line[h4].input1,line[h4].input2,h3))
{
       if(line[h4].input3=="0"&&line[h4].input2!="0")
    {
        if(line[h4].operation=="+"||line[h4].operation=="-")//if(line[h3].operation=="*")if(line[h2].operation==">>"||

 {
    if(adnum>0&&line[h4].sch==0)

    {if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
    }
    o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
    line[h4].sch=1;
    check[h9]=line[h4].output;
    chesta[h10]=h3;
    h10++;
    h9++;
    adnum--;
    h6=1;
    line[h4].schtime=h3;
    cout<<h3;
    }
    }
    if(line[h4].operation=="*")
     {
    if(mulnum>0&&h5!=h3-1&&line[h4].sch==0)
    { h5=h3;
    if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;}
    o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
    line[h4].sch=1;
    mulnum--;
    check[h9]=line[h4].output;
    mularr[h11]=line[h4].output;
    chemul[h12]=h3;
    h11++;
    h9++;
    chesta[h10]=h3+1;
    h10++;
    h12++;


    }

    }
    if(line[h4].operation==">>"||line[h4].operation=="<<")
    {
        if(lognum>0&&line[h4].sch==0)
        {if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;}
             o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
             lognum--;
             line[h4].sch=1;
             h6=1;
             check[h9]=line[h4].output;
             line[h4].schtime=h3;
    h9++;
    chesta[h10]=h3;
    h10++;
        }
    }
    if(line[h4].operation=="==")
            {
                {if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;}
                    if(lognum>0&&line[h4].sch==0)
                o<<"if("<<line[h4].input1<<"=="<<line[h4].input2<<")"<<endl;
                o<<"begin  "<<endl<<line[h4].output<<" <= 1; "<<endl<<" end"<<endl;
                o<<"else begin"<<endl<<line[h4].output<<"<=0;"<<"end"<<endl;
                lognum--;
                line[h4].sch=1;
                h6=1;
                check[h9]=line[h4].output;
                line[h4].schtime==h3;
    h9++;
    chesta[h10]=h3;
    h10++;
            }
            }
    if(line[h4].operation=="<"||line[h4].operation==">")
        {
            if(lognum>0&&line[h4].sch==0)
            {if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;}
            o<<"if("<<line[h4].input1<<line[h4].operation<<line[h4].input2<<")"<<endl;
            o<<"begin "<<endl<<line[h4].output<<"<=1;"<<endl<<" end"<<endl;
            o<<" else begin"<<endl<<line[h4].output<<"<=0;"<<endl<<"end"<<endl;
            lognum--;
            line[h4].sch=1;
            line[h4].schtime=h3;
            h6=1;
            check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;
            }
        }}
    if(line[h4].input3!="0")
{
    if(lognum>0&&line[h4].sch==0)
    {if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;}

       o<<"if("<<line[h4].input1<<"==1"<<")"<<endl;
        o<<"begin  "<<endl<<line[h4].output<<" <="<<line[h4].input2<<";"<<endl<<" end"<<endl;
        o<<"else begin"<<endl<<line[h4].output<<"<="<<line[h4].input3<<";"<<endl<<"end"<<endl;
        lognum--;
        line[h4].sch=1;
        check[h9]=line[h4].output;
        line[h4].schtime=h3;
    h9++;
    h6=1;
    }}
    if(line[h4].input2=="0"&&line[h4].sch==0)
    {if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;}
        for(int s5=0;s5<i;s5++)
        {
            if(line[h4].input1==line[s5].output)
            { if(line[s5].schtime!=h3)
        {o<<endl<<line[h4].output<<" <="<<line[h4].input1<<";"<<endl<<endl;
        line[h4].sch=1;
        h6=1;
        //cout<<h3;
       //cout<<line[s5].schtime<<h3;
        check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;}}}
    }
}}
   }}
   ////////////////////////////////////
if(h6==0&&h5==h3-1)
   {o<<"state"<<h3+1<<": begin"<<endl;
       if(line[bb-1].sch==1&&line[bb-2].sch==1)
       {o<<endl<<"state<="<<"state"<<bb+1<<";"<<endl<<"end"<<endl;
       h8=h5+3;}
       else
       {o<<endl<<"state<="<<"state"<<h3+2<<";"<<endl<<"end"<<endl;
       }}
   else if(h3+2>i||(line[i-1].sch==1&&line[i-2].sch==1&&line[i-3].sch==1))
            {if(f1==0)
                {o<<endl<<"state<="<<"final_state;"<<endl;
                f1=1;
                }
            }
            else if(h3<bb&&h6==1)
            {if(line[bb-1].sch==1&&h5!=h3&&line[bb-2].sch==1&&line[bb-3].sch==1)
            {o<<"state<="<<"state"<<bb+1<<";"<<endl;}
              else  o<<"state<="<<"state"<<h3+2<<";"<<endl;
            }
               if(h6==1){ o<<"end"<<endl;}
  /* if(h6==0&&h5==h3)
   {
       o<<endl<<"state<="<<"mul_dummy;"<<endl;
       h8=h5+3;
   }
   else if(h3+2>i)
            {if(f1==0)
                {o<<endl<<"state<="<<"final_state;"<<endl;
                f1=1;}
            }
            else if(h3+1<bb)
            {   if(line[bb-1].sch!=1)
                {o<<"state<="<<"state"<<h3+2<<";"<<endl;
            }
            else
            {
                o<<"state<="<<"state"<<bb+1<<";"<<endl;
            }}
               if(h3+1<bb){ o<<"end"<<endl;}*/
    adnum=ad_num;

 mulnum=mul_num;

stt=0;
 lognum=log_num;

}
else if(h3==bb)
{
    if(line[h3].stmt=="if")



{       o<<"state"<<h3+1<<":"<<"begin"<<endl;
        o<<"if("<<line[h3].condition<<"==1)"<<endl<<"begin"<<endl;
        o<<"state<="<<"state"<<h3+2<<";"<<endl<<"end"<<endl;
        o<<"else"<<endl<<"begin"<<endl<<"state<="<<"state"<<ab+1<<";"<<endl<<"end"<<endl<<"end"<<endl;

    }

    if(line[h3].stmt=="while")
    {
        o<<"state"<<h3+1<<":"<<"begin"<<endl;
        o<<"if("<<line[h3].condition<<"==1)"<<endl<<"begin"<<endl;
        o<<"state<="<<"state"<<h3+2<<";"<<endl<<"end"<<endl;
        o<<"else"<<endl<<"begin"<<endl<<"state<="<<"state"<<ab+2<<";"<<endl<<"end"<<endl<<"end"<<endl;
    }
}
else if(h3>bb&&h3<ab)
{

int h4=h3;
int h6=0;
int stt=0;
for(int h4=h3;h4<ab;h4++)
   {
       if(readylist(line[h4].input1,line[h4].input2,h3))
       if(readylist(line[h4].input1,line[h4].input3,h3))
      // if(mulist(line[h4].input1,line[h4].input2,h3))
{//cout<<h3;
       if(line[h4].input3=="0"&&line[h4].input2!="0")
    {
        if(line[h4].operation=="+"||line[h4].operation=="-")//if(line[h3].operation=="*")if(line[h2].operation==">>"||

{

    if(adnum>0&&line[h4].sch==0)
    {

        if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
    o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
    line[h4].sch=1;
    check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;
    adnum--;
    h6=1;
    }
    }
    if(line[h4].operation=="*")
     {
    if(mulnum>0&&h5!=h3-1&&line[h4].sch==0)
    { h5=h3;
    if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
    o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
    line[h4].sch=1;
    mulnum--;
    check[h9]=line[h4].output;
     mularr[h11]=line[h4].output;
    h11++;
    h9++;
    chesta[h10]=h3+1;
    h10++;

    }

    }
    if(line[h4].operation==">>"||line[h4].operation=="<<")
    {
        if(lognum>0&&line[h4].sch==0)
        {
            if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
             o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
             lognum--;
             line[h4].sch=1;
             h6=1;
             check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;
        }
    }
    if(line[h4].operation=="==")
            {
                {
                    if(lognum>0&&line[h4].sch==0){
                        if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
                o<<"if("<<line[h4].input1<<"=="<<line[h4].input2<<")"<<endl;
                o<<"begin  "<<endl<<line[h4].output<<" <= 1; "<<endl<<" end"<<endl;
                o<<"else begin"<<endl<<line[h4].output<<"<=0;"<<"end"<<endl;
                lognum--;
                line[h4].sch=1;
                h6=1;
                check[h9]=line[h4].output;
                chesta[h10]=h3;
    h10++;
    h9++;}
            }
            }
    if(line[h4].operation=="<"||line[h4].operation==">")
        {
            if(lognum>0&&line[h4].sch==0)
            {
                if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
            o<<"if("<<line[h4].input1<<line[h4].operation<<line[h4].input2<<")"<<endl;
            o<<"begin "<<endl<<line[h4].output<<"<=1;"<<endl<<" end"<<endl;
            o<<" else begin"<<endl<<line[h4].output<<"<=0;"<<endl<<"end"<<endl;
            lognum--;
            line[h4].sch=1;
            h6=1;
            check[h9]=line[h4].output;
            chesta[h10]=h3;
    h10++;
    h9++;
            }
        }
    }
    if(line[h4].input3!="0")
{
    if(lognum>0&&line[h4].sch==0)
    {
        if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
       o<<"if("<<line[h4].input1<<"==1"<<")"<<endl;
        o<<"begin  "<<endl<<line[h4].output<<" <="<<line[h4].input2<<";"<<endl<<" end"<<endl;
        o<<"else begin"<<endl<<line[h4].output<<"<="<<line[h4].input3<<";"<<endl<<"end"<<endl;
        lognum--;
        h6=1;
        line[h4].sch=1;
        check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;
    }}
    if(line[h4].input2=="0"&&line[h4].sch==0)
    {if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
        o<<endl<<line[h4].output<<" <="<<line[h4].input1<<";"<<endl<<endl;
        line[h4].sch=1;
        h6=1;
        check[h9]=line[h4].output;
    h10++;
    }
}
   }

   if(h6==0&&h5==h3-1)
   {o<<"state"<<h3+1<<": begin"<<endl;
   if(line[ab-1].sch==1&&line[ab-2].sch==1)
       {o<<endl<<"state<="<<"state"<<ab+1<<";"<<endl<<"end"<<endl;
       h8=h5+3;}
       else
       {o<<endl<<"state<="<<"state"<<h3+2<<";"<<endl<<"end"<<endl;
       }
       }
   else if(h3+2>i)
            {if(f1==0)
                {o<<endl<<"state<="<<"final_state;"<<endl;
                f1=1;
                }
            }
            else if(h3<ab&&h6==1)
            {if(line[ab-1].sch==1&&h5!=h3&&line[ab-2].sch==1&&line[ab-3].sch==1)
            {o<<"state<="<<"state"<<ab+1<<";"<<endl;}
              else  o<<"state<="<<"state"<<h3+2<<";"<<endl;
            }
               if(h6==1){ o<<"end"<<endl;}
    adnum=ad_num;

 mulnum=mul_num;

stt=0;
 lognum=log_num;
}
else if(h3==ab)
{   if(line[bb].stmt=="if")
    {o<<"state"<<ab+1<<":"<<" begin"<<endl;
o<<"state<="<<"state"<<ab+2<<";"<<endl<<"end"<<endl;}
   if(line[bb].stmt=="while")
   {o<<"state"<<ab+1<<":"<<" begin"<<endl;
   o<<"state<="<<"state"<<bb+1<<";"<<endl<<"end"<<endl;}

}

 if(h3<i&&h3>ab&&r6==1)
{
    int h4=h3;
int h6=0;
int stt=0;


for(int h4=h3;h4<i;h4++)
   {
      // cout<<readylist(line[h4].input1,line[h4].input2,h3);
//cout<<h3<<"<<H3"<<endl;
//cout<<chesta[h3]<<endl;
       if(readylist(line[h4].input1,line[h4].input2,h3))
       if(readylist(line[h4].input1,line[h4].input3,h3))
{       //if(mulist(line[h4].input1,line[h4].input2,h3))
//cout<<h3<<endl;cout<<line[h4].input3<<" at "<<h4<<endl;
       if(line[h4].input3=="0"&&line[h4].input2!="0")
    {//cout<<line[h4].input3<<" at "<<h4<<endl;
        if(line[h4].operation=="+"||line[h4].operation=="-")//if(line[h3].operation=="*")if(line[h2].operation==">>"||

    {
    if(adnum>0&&line[h4].sch==0)
    {

        if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
    o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
    line[h4].sch=1;
    check[h9]=line[h4].output;
    h9++;
    adnum--;
    h6=1;
    chesta[h10]=h3;
    h10++;
    }
    }
    if(line[h4].operation=="*")
     {
    if(mulnum>0&&h5!=h3-1&&line[h4].sch==0)
    { h5=h3;
    if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
    o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
    line[h4].sch=1;
    mulnum--;
    check[h9]=line[h4].output;
    h9++;
    chemul[h12]=h3+1;
     mularr[h11]=line[h4].output;
    h11++;
    chesta[h10]=h3+1;
    h10++;
    }

    }
    if(line[h4].operation==">>"||line[h4].operation=="<<")
    {
        if(lognum>0&&line[h4].sch==0)
        {
            if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
             o<<line[h4].output<<"<="<<line[h4].input1<<" "<<line[h4].operation<<" "<<line[h4].input2<<";"<<endl;
             lognum--;
             line[h4].sch=1;
             h6=1;
             check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;
        }
    }
    if(line[h4].operation=="==")
            {
                {
                    if(lognum>0&&line[h4].sch==0){
                        if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
                o<<"if("<<line[h4].input1<<"=="<<line[h4].input2<<")"<<endl;
                o<<"begin  "<<endl<<line[h4].output<<" <= 1; "<<endl<<" end"<<endl;
                o<<"else begin"<<endl<<line[h4].output<<"<=0;"<<"end"<<endl;
                lognum--;
                line[h4].sch=1;
                h6=1;
                check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;}
            }
            }
    if(line[h4].operation=="<"||line[h4].operation==">")
        {
            if(lognum>0&&line[h4].sch==0)
            {
                if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
            o<<"if("<<line[h4].input1<<line[h4].operation<<line[h4].input2<<")"<<endl;
            o<<"begin "<<endl<<line[h4].output<<"<=1;"<<endl<<" end"<<endl;
            o<<" else begin"<<endl<<line[h4].output<<"<=0;"<<endl<<"end"<<endl;
            lognum--;
            line[h4].sch=1;
            h6=1;
            check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;
            }
        }
    }
    if(line[h4].input3!="0")
{
    if(lognum>0&&line[h4].sch==0)
    {
        if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
       o<<"if("<<line[h4].input1<<"==1"<<")"<<endl;
        o<<"begin  "<<endl<<line[h4].output<<" <="<<line[h4].input2<<";"<<endl<<" end"<<endl;
        o<<"else begin"<<endl<<line[h4].output<<"<="<<line[h4].input3<<";"<<endl<<"end"<<endl;
        lognum--;
        line[h4].sch=1;
        check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;
    h6=1;
    }}
    if(line[h4].input2=="0"&&line[h4].sch==0)
    {
        if(stt==0)
        {o<<"state"<<h3+1<<":"<<"begin"<<endl;
        stt=1;
        }
        o<<endl<<line[h4].output<<" <="<<line[h4].input1<<";"<<endl<<endl;
        line[h4].sch=1;
        h6=1;
       // cout<<stt<<"line<<";
        check[h9]=line[h4].output;
    h9++;
    chesta[h10]=h3;
    h10++;

    }
}}
//////////////////////////////////
if(h6==0&&h5==h3-1)
   {o<<"state"<<h3+1<<": begin"<<endl;
   if(line[bb-1].sch==1&&line[bb-2].sch==1)
       {o<<endl<<"state<="<<"state"<<i+1<<";"<<endl<<"end"<<endl;
       h8=h5+3;}
       else
       {o<<endl<<"state<="<<"state"<<h3+2<<";"<<endl<<"end"<<endl;

    }
       }
   else if(h3+2>i||(line[i-1].sch==1&&line[i-2].sch==1&&line[i-2].sch==1))
            {if(f1==0)
                {o<<endl<<"state<="<<"final_state;"<<endl;
                f1=1;
                }
            }
            else if(h3<i&&h6==1)
            {if(line[i-1].sch==1&&h5!=h3)
            {o<<"state<="<<"state"<<h3+2<<";"<<endl;}
              else  o<<"state<="<<"state"<<h3+2<<";"<<endl;
            }
               if(h6==1){ o<<"end"<<endl;}
   /*if(h6==0&&h5==h3)
   {
       o<<endl<<"state<="<<"mul_dummy;"<<endl;

       }
   else if(h3+2>i||(line[i-1].sch==1))
            {if(f1==0)
                {o<<endl<<"state<="<<"final_state;"<<endl;
                f1=1;
                }
            }
            else if(h3<i&&h6==1)
            {if(line[i-1].sch==1)
            {o<<"state<="<<"state"<<i+1<<";"<<endl;}
              else  o<<"state<="<<"state"<<h3+2<<";"<<endl;
            }
               if(h6==1){ o<<"end"<<endl;}*/
   adnum=ad_num;

 mulnum=mul_num;

stt=0;
 lognum=log_num;
}

//state and end
}
}
/*/////////////////////////////////////////////////////ns/////////////////////////////////////////////////////////////////////////*/
   if(string(argv[1])=="-ns")      //string(argv[1])=="-ns")
{int cal1=0;
int cal3=0;
int cal4=0;
int cal5=0;
int cal6=0;
for(int h2=0;h2<i;h2++)
{ cal1=0;
cal3=0;
int cal2=0;
    o<<"state"<<h2+1<<":"<<"begin"<<endl;
    if(line[h2].stmt=="while")
    {cal5=h2;

        for(int t1=0;t1<i;t1++)
    { if(line[t1].bracket4=="}")
    cal4=t1;
    }

        o<<"if("<<line[h2].condition<<"==1)"<<endl<<"begin"<<endl;
        o<<"state<="<<"state"<<h2+2<<";"<<endl<<"end"<<endl;
        o<<"else"<<endl<<"begin"<<endl<<"state<="<<"state"<<cal4+2<<";"<<endl<<"end"<<endl;
       cal3=1;
    }

    if(line[h2].bracket4=="}")
    { cal1=1;
    o<<endl;
       if(cal5!=0)
       {
        o<<"state<="<<"state"<<cal5+1<<";"<<endl;
       }
       else
       {
        o<<"state<="<<"state"<<h2+2<<";"<<endl<<endl;
       }
    }

    if(line[h2].stmt=="if")
    {for(int t3=0;t3<i;t3++)
    {
    if(line[t3].bracket4=="}")
    {cal6=t3;}}

        o<<"if("<<line[h2].condition<<"==1)"<<endl<<"begin"<<endl;
        o<<"state<="<<"state"<<h2+2<<";"<<endl<<"end"<<endl;
        o<<"else"<<endl<<"begin"<<endl<<"state<="<<"state"<<cal6+1<<";"<<endl<<"end"<<endl;
        cal3=1;
        cal1=1;
    }
    else if(line[h2].input3=="0"&&line[h2].input2!="0")
    {
        if(line[h2].operation=="+"||line[h2].operation=="-"||line[h2].operation=="*"||line[h2].operation==">>"||line

[h2].operation=="<<")
        {
           /* if(line[h2].operation==">>"||line[h2].operation=="<<")
            {
                o<<line[h2].output<<"
            }
            else*/
           {o<<line[h2].output<<" <= "<<line[h2].input1<<" "<<line[h2].operation<<" "<<line[h2].input2<<";"<<endl;
            if(h2+2>i)
            {
                o<<"state<="<<"final_state;"<<endl;
            }
            else
            {
                o<<"state<="<<"state"<<h2+2<<";"<<endl;
                }}
        }
        else
        {
            if(line[h2].operation=="==")
            {
                o<<"if("<<line[h2].input1<<"=="<<line[h2].input2<<")"<<endl;
                o<<"begin  "<<endl<<line[h2].output<<" <= 1; "<<endl<<" end"<<endl;
                o<<"else begin"<<endl<<line[h2].output<<"<=0;"<<"end"<<endl;
                if(h2+2>i)
                {
                    o<<"state<="<<"final_state;"<<endl;
                }
                else
                {
                    o<<"state<="<<"state"<<h2+2<<";"<<endl;
                }
                o<<"end"<<endl;
            }
        }
        if(line[h2].operation=="<"||line[h2].operation==">")
        {
            o<<"if("<<line[h2].input1<<line[h2].operation<<line[h2].input2<<")"<<endl;
            o<<"begin "<<endl<<line[h2].output<<"<=1;"<<endl<<" end"<<endl;
            o<<" else begin"<<endl<<line[h2].output<<"<=0;"<<endl<<"end"<<endl;
            if(h2+2>i)
            {
                o<<"state<="<<"final_state;"<<endl;
            }
            else
            {
                o<<"state<="<<"state"<<h2+2<<";"<<endl;
            }
        }
        o<<"end";
    }
    if(line[h2].input3!="0")

    {
        if(cal1==0)
        {
           if(cal2==0&&cal3==0)
{
       o<<"if("<<line[h2].input1<<"==1"<<")"<<endl;
        o<<"begin  "<<endl<<line[h2].output<<" <="<<line[h2].input2<<";"<<endl<<" end"<<endl;
        o<<"else begin"<<endl<<line[h2].output<<"<="<<line[h2].input3<<";"<<endl<<"end"<<endl;
        if(h2+2>i)
        {
            o<<"state<="<<"final_state;"<<endl;
        }
        else
        {
            o<<"state<="<<"state"<<h2+2<<";"<<endl;
        }
       } }o<<"end"<<endl;
    }
    if(line[h2].input2=="0")
    {
        o<<endl<<line[h2].output<<" <="<<line[h2].input1<<";"<<endl<<endl;
        if(h2+2>i)
        {
            o<<"state<="<<"final_state;"<<endl<<"end"<<endl;
        }
        else
        {
            o<<"state<="<<"state"<<h2+2<<";"<<endl<<"end"<<endl;
        }
    }
    o<<endl<<endl;

}}

/*o<<"state:mul_dummy"<<" begin"<<endl;
o<<"state<="<<"state"<<h8<<";"<<endl<<"end"<<endl;*/
o<<"final_state:"<<" begin"<<endl;
o<<"Done<=1;"<<endl<<"state<=wait_state;"<<endl<<"end"<<endl;
o<<"endcase"<<endl<<"end"<<endl<<"end"<<endl<<endl;


/*for(int z=0;z<10;z++)
{
    cout<<check[z]<<endl;
}*/
/*for(int h2=0;h2<i;h2++)
    if(line[h2].operation=="OUTPUT")
    {
        buff1.str("");
        buff1<<out_cnt;
        h4=buff1.str();
        string str="OUT";
        o<<"REG "<<str.append(h4);
        o<<"(.Clk(Clk), .Rst(Rst),.O("<<line[h2].output<<"),.I("<<line[h2].input1<<"));"<<endl;
        out_cnt=out_cnt+1;
    }
    */


    o<<"endmodule";
//readylist(line[1].input1,line[1].input2);
    return 0;
    }

//}

void display(vector<string> &pieces)
{
    for(int i=0; i<pieces.size(); i++)
    {
        string z=pieces[i];
        cout << z << endl;
    }
    cout << "\n" << endl;
}

////////////////////////////////////////////function
int readylist(string x, string y,int w)
{int z2=0;

for(int z1=0;z1<inputs.size();z1++)
{
if(x==inputs[z1]||x=="0")
{
    z2=1;

}
}
for(int z1=0;z1<35;z1++)
{
    if(check[z1]==x&&chesta[z1]!=w&&chesta[z1]-1!=w)
{
    z2=1;
    }
    }

int z3=0;
for(int z1=0;z1<inputs.size();z1++)
{
if(y==inputs[z1]||y=="0")
{
    z3=1;

}}
for(int z1=0;z1<35;z1++)
{if(check[z1]==y&&chesta[z1]!=w&&chesta[z1]-1!=w)
{z3=1;}}
if(z3==1&&z2==1)
{
    return 1;
}
else
return 0;
}

int mulist(string f,string e,int x)
{int p1=0;
int p2=0;

for(int t1=0;t1<35;t1++)
{
    if(f==mularr[t1])
    {
        if(x==chemul[t1]+1)
        {return 0;}
    }
    if(e==mularr[t1])
    {
        if(x==chemul[t1]+1)
        {return 0;}
    }
}
return 1;
}
void alaptime(string y,int x,int z)
{int i;
int v1;
int v2=0;

    for(int t=0;t<x;t++)
    {
      if(y!=line[t].input1&&y!=line[t].input2&&y!=line[t].input3)
      {
          v2++;

      }
      else if(y==line[t].input1||y==line[t].input2||y==line[t].input3)
      {
        if(line[t].alaptime==0)
        {if((line[z].alaptime)>1){}
            else if(line[z].operation=="*"){line[z].alaptime=2;}
            else {line[z].alaptime=1;}
        }
        if(line[t].alaptime==1)
        {if((line[z].alaptime)>2){}
            else if(line[z].operation=="*"){line[z].alaptime=3;}
            else {line[z].alaptime=2;}
                }
         if(line[t].alaptime==2)
         {
             if(line[z].alaptime>3){}
         else if(line[z].operation=="*"){line[z].alaptime=4;}
            else {line[z].alaptime=3;}
             }
//cout<<line[0].alaptime<<endl;

      }
if(v2==x){
line[z].alaptime=0;}
}}

int readylir(string x,string y,string z,string w,int u)
{int z5;
int z6=0;
int z7=0;
int z8=0;
int z9=0;
int z10=0;
int z11=0;
      for(int t1=0;t1<inputs.size();t1++)
      {
          if(x==inputs[t1])
          {
              z6=1;
          }
          if(y==inputs[t1]||y=="0")
          {
              z7=1;
          }
          if(z==inputs[t1]||z=="0")
          {
              z8=1;
          }
      }
      for(int t3=0;t3<35;t3++)
      {
          if(x==listarr[t3]||x=="0")
          {z5=1;}
          if(y==listarr[t3]||y=="0")
          {z9=1;}
          if(z==listarr[t3]||z=="0")
          {z10=1;}}
   /* for(int t=0;t<35;t++)
    {
     if(x==listarr[t]||x=="0")
     {if(x=="0")
     {
         z5=1;
     }
      else if(u!=listct[t])
     {if(w!="*")
     {
         z5=1;
     }
     else
     if(u!=listct[t]-1)
     {
         z5=1;
     }
     }
    }
       if(y==listarr[t]||y=="0")
     {if(y=="0")
     {
         z9=1;
     }
        else  if(u!=listct[t])
     {if(w!="*")
     {
         z9=1;
     }
     else
     if(u!=listct[t]-1)
     {
         z9=1;
     }}

     if(z==listarr[t]||z=="0")
     {if(z=="0")
     {
         z10=1;
      }
      else if(u!=listct[t])
     {if(w!="*")
     {
         z10=1;
     }
     else
     if(u!=listct[t]-1)
     {
         z10=1;
     }}}
    }
    }*/
if(z8==1&&z6==1&&z7==1)
{return 1;}
if(z5==1&&z9==1&&z10==1)
{return 1;}
else return 0;

}




































































































