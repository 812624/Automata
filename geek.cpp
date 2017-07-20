#include<stdio.h>
#include"myheader.cpp"
void re_to_nfa(string reg)
{
			char final[20][20] ;
			int i,j;
			for(i = 0; i < 20; i++)
			{
				for(j = 0; j < 20; j++)
					final[i][j]='-';
			}
			int  q[20][3] = {0};
			int len=reg.size();
			i=0;
			j=0;
			while(i<len)
			{
				if(reg[i]=='a'&&reg[i+1]!='/'&&reg[i+1]!='*')
				{
					q[j][0]=j+1;
					j++;
				}
				if(reg[i]=='b'&&reg[i+1]!='/'&&reg[i+1]!='*')
				{
					q[j][1]=j+1;
					j++;
				}
				if(reg[i]=='e'&&reg[i+1]!='/'&&reg[i+1]!='*')
				{
					q[j][2]=j+1;
					j++;		
				}
				if(reg[i]=='a'&&reg[i+1]=='/'&&reg[i+2]=='b')
				{
					q[j][2]=((j+1)*10)+(j+3);
					j++;
					q[j][0]=j+1;
					j++;
					q[j][2]=j+3;
					j++;
					q[j][1]=j+1;
					j++;
					q[j][2]=j+1;
					j++;
					i=i+2;
				}
				if(reg[i]=='b'&&reg[i+1]=='/'&&reg[i+2]=='a')
				{
					q[j][2]=((j+1)*10)+(j+3);
					j++;
					q[j][1]=j+1;
					j++;
					q[j][2]=j+3;
					j++;
					q[j][0]=j+1;
					j++;
					q[j][2]=j+1;
					j++;
					i=i+2;
				}
				if(reg[i]=='a'&&reg[i+1]=='*')
				{
					q[j][2]=((j+1)*10)+(j+3);
					j++;
					q[j][0]=j+1;
					j++;
					q[j][2]=((j+1)*10)+(j-1);
					j++;
				}
				if(reg[i]=='b'&&reg[i+1]=='*')
				{
					q[j][2]=((j+1)*10)+(j+3);
					j++;
					q[j][1]=j+1;
					j++;
					q[j][2]=((j+1)*10)+(j-1);
					j++;
				}
				if(reg[i]==')'&&reg[i+1]=='*')
				{
					q[0][2]=((j+1)*10)+1;
					q[j][2]=((j+1)*10)+1;
					j++;
				}
			i++;
			}
			printf("Transition function \n");
			for(i=0;i<=j;i++)
			{
					if(q[i][0]!=0){
						printf("\n q[%d,a]-->%d",i,q[i][0]);
						final[i][q[i][0]] = 'a';
					}
					if(q[i][1]!=0){
						printf("\n q[%d,b]-->%d",i,q[i][1]);
						final[i][q[i][1]] = 'b';
					}
					if(q[i][2]!=0)
					{
						if(q[i][2]<10){
							printf("\n q[%d,e]-->%d",i,q[i][2]);
							if(final[i][q[i][2]]=='-')
								final[i][q[i][2]] = 'e';
						}	
						else{
							printf("\n q[%d,e]-->%d & %d",i,q[i][2]/10,q[i][2]%10);
							if(final[i][(q[i][2]/10)]=='-')
							final[i][(q[i][2]/10)] = 'e';
							if(final[i][(q[i][2]/10)]=='-')
							final[i][(q[i][2]%10)] = 'e';
						}
					}
			}
			printf("\nAfter all\n");
			int n = j;
			for(i=0;i<=n;i++){
				for(j=0;j<=n;j++){
						cout<<" "<<final[i][j]<<" ";
					}cout<<endl;
			}
			draw(n+1,final);
			//nfa_to_dfa(final, n);		
}
