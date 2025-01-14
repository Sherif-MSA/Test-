#include<iostream>
#include<stdio.h>
using namespace std;
class cnode
{
public:
	char x[8][8];
	cnode *pnext;
};

class clist
{
public:
	cnode * phead;
	cnode *ptail;
	clist()
	{
		phead = '\0';
		ptail = '\0';
	}
	~clist()
	{
		cnode *ptrav;
		ptrav = phead;
		while (ptrav != '\0')
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	};
	void attach(cnode*pnn)
	{
		if (phead == '\0')
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	};
	void dispall()
	{
		cnode *ptrav;
		ptrav = phead;
		while (ptrav != '\0')
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ptrav->x;
				
			}
			ptrav = ptrav->pnext;
		}
	};
};

class cstack
{
public:
	cnode * phead;
	cnode *ptail;
	cstack()
	{
		phead = NULL;
		ptail = NULL;
	}
	void push(cnode *pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	};
	cnode *pop()
	{
		if (phead == NULL)
		{
			return NULL;
		}
		cnode * ptrav = phead;
		phead = phead->pnext;
		ptrav->pnext = NULL;
		return ptrav;
	};
};

void depth1st( cnode *pcurr, cstack &s )
{
	int i;
	cnode *pchild;
	int flag;
	int hr;
	int hc;
	int r;
	int c;

	for ( i = 0 ; i < 4 ; i++ )
	{
		flag = 0;
		pchild = new cnode;
		pchild->pnext = '\0';

		for ( r = 0 ; r < 8 ; r++ )
		{
			for ( c = 0 ; c < 8 ; c++ )
			{
				pchild->x[r][c] = pcurr->x[r][c];

				if ( pcurr->x[r][c] == 'Q' )
				{
					hr = r;
					hc = c;
				}
			}
		}
		//1st child
		if ( i == 0 )
		{
			if ( pchild->x[hr][hc+1] == '@'  )
			{
				for ( r = 0 ; r < 8 ; r++ )
				{
					for ( c = 0 ; c < 8 ; c++ )
					{
						cout<<pchild->x[r][c]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			else
			{
				if ( pchild->x[hr][hc+1] == ' ' && hc+1 < 8 )
				{
					pchild->x[hr][hc] = '.';
					pchild->x[hr][hc+1] = 'Q';
					flag = 1;
				}
			}
		}
		//2nd child
		if ( i == 1 )
		{	
			if ( pchild->x[hr][hc-1] == '@' )
			{
				for ( r = 0 ; r < 8 ; r++ )
				{
					for ( c = 0 ; c < 8 ; c++ )
					{
						cout<<pchild->x[r][c]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			else
			{
				if ( pchild->x[hr][hc-1] == ' ' && hc-1 > -1 )
				{
					pchild->x[hr][hc] = '.';
					pchild->x[hr][hc-1] = 'Q';
					flag = 1;
				}
			}
		}
		//3rd child
		if ( i == 2 )
		{
			if ( pchild->x[hr+1][hc] == '@')
			{
				for ( r = 0 ; r < 8 ; r++ )
				{
					for ( c = 0 ; c < 8 ; c++ )
					{
						cout<<pchild->x[r][c]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			else
			{
				if ( pchild->x[hr+1][hc] == ' ' && hr+1 < 8 )
				{
					pchild->x[hr][hc] = '.';
					pchild->x[hr+1][hc] = 'Q';
					flag = 1;
				}
			}
		}
		//4th child
		if ( i == 3 )
		{
			if ( pchild->x[hr-1][hc] == '@' )
			{
				for ( r = 0 ; r < 8 ; r++ )
				{
					for ( c = 0 ; c < 8 ; c++ )
					{
						cout<<pchild->x[r][c]<<"|";
					}
					cout<<endl;
				}
				cout<<endl;
			}
			else
			{
				if ( pchild->x[hr-1][hc] == ' ' && hr-1 > -1 )
				{
					pchild->x[hr][hc] = '.';
					pchild->x[hr-1][hc] = 'Q';
					flag = 1;
				}
			}
		}
		if ( flag == 1 )
		{
			s.push(pchild); 
		}
	}
}

void Maze()
{
	cnode *pcurr;
	int r;
	int c;
	cstack s;
	pcurr = new cnode;

	for ( r = 0 ; r < 8 ; r++ )
	{
		for ( c = 0 ; c < 8 ; c++ )
		{
			pcurr->x[r][c] = ' ';
		}
	}
	pcurr->pnext = '\0';
	pcurr->x[0][1] = '#';
	pcurr->x[0][3] = '#';
	pcurr->x[1][5] = '#';
	pcurr->x[1][6] = '#';
	pcurr->x[2][1] = '#';
	pcurr->x[2][4] = '@';
	pcurr->x[2][5] = '#';
	pcurr->x[3][2] = '#';
	pcurr->x[3][4] = '#';
	pcurr->x[3][7] = '#';
	pcurr->x[4][0] = '#';
	pcurr->x[4][6] = '#';
	pcurr->x[4][2] = '#';
	pcurr->x[5][4] = '#';

	for ( int i = 0 ; i < 5 ; i++ )
	{
		pcurr->x[6][i] = '#';
	}
	pcurr->x[6][6] = '#';
	pcurr->x[7][0] = 'Q';

	s.push(pcurr);
	while ( s.phead != '\0' )
	{
		pcurr = s.pop();
		
		depth1st(pcurr, s );
	}
}

void main()
{
	Maze();
}