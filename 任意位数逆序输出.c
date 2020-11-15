# include <stdio.h>

main()
{
	
	
	int r=0;
	int a=0;
	int sum=0;
	
	scanf("%d",&r);
	for(;r>0;r/=10){
		a=r%10;
		sum=sum*10+a;
	}
	printf("%d",sum);
	
	return 0;
	
	
}
