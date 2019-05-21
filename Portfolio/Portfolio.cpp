#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Investment.h"
#include "Portfolio.h"
using namespace std;

Portfolio::Portfolio()
{
	alist=NULL;
	p_size=0;
	IB=0;
}

Portfolio::~Portfolio()
{
	delete [] alist;
}

void Portfolio::list_resize(int f_size)
{
	Account **old=new Account*[p_size];
	for(int i=0;i<p_size;i++)
		old[i]=alist[i];
	delete [] alist;
	alist=new Account*[p_size+f_size];
	for(int i=0;i<p_size;i++)
		alist[i]=old[i];
	delete [] old;
}

bool Portfolio::importFile(const char *filename)
{
	int f_size;
	char firstname[20],lastname[20],tmpname[20],a_type[10],*c=NULL;
	double s_var[2],c_var,i_var_a[5],i_var_ivs[5],i_var_cvs[5],i_var_ir[5];
	FILE *fp=fopen(filename,"r");
	if(fp==NULL)
	{
		cout<<"Invalid file. No data imported"<<endl;
		return false;
	}
	fscanf(fp,"%d",&f_size);
	if(p_size==0)
		alist=new Account*[f_size];
	else
		list_resize(f_size);
	for(int i=p_size;i<p_size+f_size;i++)
	{
		fscanf(fp,"%s",lastname);
		c=strchr(lastname,',');
		while(c==NULL)
		{
			fscanf(fp,"%s",tmpname);
			strcat(lastname," ");
			strcat(lastname,tmpname);
			c=strchr(lastname,',');
		}
		for(int j=0;j<20;j++)
			if(lastname[j]==',')
				lastname[j]='\0';
		fscanf(fp,"%s%s",firstname,a_type);
		if(strcmp(a_type,"Savings")==0)
		{
			fscanf(fp,"%lf%lf",&s_var[0],&s_var[1]);
			alist[i]=new Savings(s_var[0],s_var[1]);
		}
		else if(strcmp(a_type,"Checking")==0)
		{
			fscanf(fp,"%lf",&c_var);
			alist[i]=new Checking(c_var);
		}
		else if(strcmp(a_type,"Investment")==0)
		{
			for(int j=0;j<5;j++)
				fscanf(fp,"%lf%lf%lf%lf",&i_var_a[j],&i_var_ivs[j],&i_var_cvs[j],&i_var_ir[j]);
			alist[i]=new Investment(i_var_a,i_var_ivs,i_var_cvs,i_var_ir);
		}
		strcpy(alist[i]->f_name,firstname);
		strcpy(alist[i]->l_name,lastname);
		alist[i]->getPB();
		alist[i]->getIB();
		for(int i=0;i<20;i++)
			tmpname[i]='\0';
	}
	p_size+=f_size;
	fclose(fp);
	return true;
}

bool Portfolio::createReportFile(const char* filename)
{
	int s_cnt=0,c_cnt=0,i_cnt=0;
	double s_PB=0,c_PB=0,i_PB=0;
	FILE *fp=fopen(filename,"w");
	if(fp==NULL)
	{
		cout<<"Invalid file. No data created"<<endl;
		return false;
	}
	fprintf(fp,"Banking Summary\n---------------\n\n");
	fprintf(fp,"Savings Accounts\n\nHolder's Name\t\tInitial Balance\t\tProjected Balance\n"
				"-----------------------------------------------------------------\n");
	for(int i=0;i<p_size;i++)
	{
		if(alist[i]->type=='s')
		{
			fprintf(fp,"%s %s\t\t%.2lf\t\t\t%.2lf\n",alist[i]->f_name,alist[i]->l_name,alist[i]->IB,alist[i]->PB);
			++s_cnt;
			s_PB+=alist[i]->PB;
		}
	}
	fprintf(fp,"\nChecking Accounts\n\nHolder's Name\t\tInitial Balance\t\tProjected Balance\n"
				"-----------------------------------------------------------------\n");
	for(int i=0;i<p_size;i++)
	{
		if(alist[i]->type=='c')
		{
			fprintf(fp,"%s %s\t\t%.2lf\t\t\t%.2lf\n",alist[i]->f_name,alist[i]->l_name,alist[i]->IB,alist[i]->PB);
			++c_cnt;
			c_PB+=alist[i]->PB;
		}
	}
	fprintf(fp,"\nInvestment Accounts\n\nHolder's Name\t\tInitial Balance\t\tProjected Balance\n"
				"-----------------------------------------------------------------\n");
	for(int i=0;i<p_size;i++)
	{
		if(alist[i]->type=='i')
		{
			fprintf(fp,"%s %s\t\t%.2lf\t\t\t%.2lf\n",alist[i]->f_name,alist[i]->l_name,alist[i]->IB,alist[i]->PB);
			++i_cnt;
			i_PB+=alist[i]->PB;
		}
	}
	s_PB=s_PB*1000/s_cnt;
	c_PB=c_PB*1000/c_cnt;
	i_PB=i_PB*1000/i_cnt;
	if((int)s_PB%10>=5)
		s_PB+=5;
	if((int)c_PB%10>=5)
		c_PB+=5;
	if((int)i_PB%10>=5)
		i_PB+=5;
	s_PB/=1000;
	c_PB/=1000;
	i_PB/=1000;
	fprintf(fp,"\nOverall Account distribution\n\n");
	fprintf(fp,"Savings:\t%d\t-\t%.2lf\n",s_cnt,s_PB);
	fprintf(fp,"Checking:\t%d\t-\t%.2lf\n",c_cnt,c_PB);
	fprintf(fp,"Investment:\t%d\t-\t%.2lf\n",i_cnt,i_PB);
	fclose(fp);
	return true;
}

void Portfolio::showAccounts() const
{
	cout<<"Holder\t\t\t\tType\t\tBalance"<<endl<<endl;
	for(int i=0;i<p_size;i++)
	{
		cout<<alist[i]->f_name<<" "<<alist[i]->l_name<<"\t\t";
		if(alist[i]->type=='s')
			cout<<"Savings\t\t"<<alist[i]->IB<<endl;
		else if(alist[i]->type=='c')
			cout<<"Checking\t\t"<<alist[i]->IB<<endl;
		else if(alist[i]->type=='i')
			cout<<"Investment\t\t"<<alist[i]->IB<<endl;
	}
}

