#include <bits/stdc++.h>
using namespace std;

int **pic;

typedef struct node
{
	int value,path,size,x,y;
	struct node *NW,*NE,*SW,*SE;
}Node;

int DtoF(int a)
{
	int b,result=0,len=0;
	while(a>0)
	{
		b=a%5;
		a/=5;
		for(int i=0;i<len;i++)
			b*=10;
		result+=b;
		len++;
	}
	return result;
}

int FtoD(int a)
{
	int b,result=0,len=0;
	while(a>0)
	{
		b=a%10;
		a/=10;
		for(int i=0;i<len;i++)
			b*=5;
		result+=b;
		len++;
	}
	return result;
}

bool is_same(Node *tar)
{
	int first=pic[tar->y][tar->x];
	for(int i=tar->y;i<tar->y+tar->size;i++)
		for(int j=tar->x;j<tar->x+tar->size;j++)
			if(pic[i][j]!=first)
				return false;
	return true;
}

void init(Node *tar,int level)
{
	int e=1;
	for(int i=0;i<level;i++)
		e*=10;
	tar->NW=new Node;
	tar->NE=new Node;
	tar->SW=new Node;
	tar->SE=new Node;
	tar->NW->value=tar->NE->value=tar->SW->value=tar->SE->value=-1;
	tar->NW->path=tar->path+1*e;
	tar->NE->path=tar->path+2*e;
	tar->SW->path=tar->path+3*e;
	tar->SE->path=tar->path+4*e;
	tar->NW->size=tar->NE->size=tar->SW->size=tar->SE->size=tar->size/2;
	tar->NW->x=tar->SW->x=tar->x;
	tar->NW->y=tar->NE->y=tar->y;
	tar->NE->x=tar->SE->x=tar->x+tar->size/2;
	tar->SW->y=tar->SE->y=tar->y+tar->size/2;
	tar->NW->NW=NULL;
	tar->NW->NE=NULL;
	tar->NW->SW=NULL;
	tar->NW->SE=NULL;
	tar->NE->NW=NULL;
	tar->NE->NE=NULL;
	tar->NE->SW=NULL;
	tar->NE->SE=NULL;
	tar->SW->NW=NULL;
	tar->SW->NE=NULL;
	tar->SW->SW=NULL;
	tar->SW->SE=NULL;
	tar->SE->NW=NULL;
	tar->SE->NE=NULL;
	tar->SE->SW=NULL;
	tar->SE->SE=NULL;
}

void Divide(Node *root,int level)
{
	Node *tmp=root;
	if(is_same(root))
	{
		root->value=pic[root->y][root->x];
		return;
	}
	init(tmp,level);
	level++;
	Divide(tmp->NW,level);
	Divide(tmp->NE,level);
	Divide(tmp->SW,level);
	Divide(tmp->SE,level);
}

int get_res(Node *root,int tar,int *res,int cnt)
{
	Node *tmp=root;
	if(tmp!=NULL)
	{
		if(tmp->value==tar)
		{
			res[cnt]=FtoD(tmp->path);
			cnt++;
		}
		cnt=get_res(tmp->NW,tar,res,cnt);
		cnt=get_res(tmp->NE,tar,res,cnt);
		cnt=get_res(tmp->SW,tar,res,cnt);
		cnt=get_res(tmp->SE,tar,res,cnt);
	}
	return cnt;
}

void get_pic(int input,int x,int y,int size)
{
	size/=2;
	if(input%10==2)
		x+=size;
	else if(input%10==3)
		y+=size;
	else if(input%10==4)
	{
		x+=size;
		y+=size;
	}
	input/=10;
	if(input!=0)
		get_pic(input,x,y,size);
	else
	{
		for(int i=y;i<y+size;i++)
			for(int j=x;j<x+size;j++)
				pic[i][j]=1;
	}
}

void printer(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(pic[i][j]==0)
				printf(".");
			else
				printf("*");
		}
		printf("\n");
	}
}

int main(int argc,char *argv[])
{
	int tmp,level=0,result[100],count=0,p_size=atoi(argv[1]);
	int input,d_size;
	char *str;
	Node *root=new Node;
	if(argv[1][0]!='-')
	{
		for(int i=0;i<100;i++)
			result[i]=0;
		root->value=-1;
		root->path=0;
		root->size=p_size;
		root->x=root->y=0;
		root->NW=NULL;
		root->NE=NULL;
		root->SW=NULL;
		root->SE=NULL;
		pic=new int*[root->size];
		for(int i=0;i<root->size;i++)
		{
			pic[i]=new int[root->size];
			printf("Input %d's numbers: ",i+1);
			scanf("%d",&tmp);
			for(int j=root->size-1;j>-1;j--)
			{
				pic[i][j]=tmp%10;
				tmp/=10;
			}
		}
		if(is_same(root))
		{
			printf("0");
			count=1;
		}
		else
		{
			Divide(root,level);
			count=get_res(root,1,result,count);
			sort(result,result+100);
			for(int i=100-count;i<100;i++)
				if(result[i]!=0)
					printf("%d ",result[i]);
		}
		printf("\nTotal number of black nodes = %d\n",count);
	}
	else
	{
		p_size*=-1;
		pic=new int*[p_size];
		for(int i=0;i<p_size;i++)
			pic[i]=new int[p_size];
		printf("Input the black block number: ");
		while(1)
		{
			scanf("%d",&input);
			if(input<=0)
				break;
			input=DtoF(input);
			get_pic(input,0,0,p_size);
		}
		if(input==0)
			for(int i=0;i<p_size;i++)
			{
				for(int j=0;j<p_size;j++)
					printf("*");
				printf("\n");
			}
		else
			printer(p_size);
	}
	for(int i=0;i<p_size;i++)
		delete [] pic[i];
	delete [] pic;
	return 0;
}
