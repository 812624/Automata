#include"myheader.cpp"
char reg[20];
int main()
{
		input();
		re_to_nfa(reg);
		return 0;
}

void input()
{
		cout<<"Regular expression: ";
		cin>>reg;
		return;
}			
