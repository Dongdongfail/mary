# include <stdio.h>

main()
{
	
	
	int a=0;
	int odd=0;
	int even=0;
	
	scanf("%d",&a);
	while(a!=-1){
		if(a%2==0){
			even++;
		}else{
			odd++;
		}
		scanf("%d",&a);
	}
	printf("%d %d",odd,even);
	
	return 0;
	
	
}
