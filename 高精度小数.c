# include <stdio.h>

main()
{
	
	int a=1;
	int b=0;
	int c=0;
	int i=0;
	int z=0;
	
	
	scanf("%d/%d",&a,&b);
	if(a/b>0){
		z=a/b;
		a=a%b;
	}
	printf("%d.",z);
	while(i<200&&a!=0){
		c=a*10/b;
		a=a*10%b;
		i+=1;
		printf("%d",c);
	}
	printf("\n");
	return 0;
}
