# include <stdio.h>

int amount[]={1,5,10,25,50};
char *name[]={"penny","nickle","dime","quarter","half-dollar",};
struct{
	int amount;
	char *name;
}coins[]={
	{1,"penny"},
	{5,"nickle"},
	{10,"dime"},
	{25,"quarter"},
	{50,"half-dollar"}
	};
int main()
{
	//int key=2;
	int a=sizeof(coins)/sizeof(coins[0]);
	printf("%d\n",sizeof(coins[1]));
	return 0;
}
