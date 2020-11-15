# include <stdio.h>
# include <string.h>

main()
{
	char string[100];
	int count=0;
	int n=2;
	char c='.';
	
	while(n==2){
		scanf("%s",string);
		//count=strlen(string);
		count=sizeof(string)/sizeof(string[0]);
		if(string[count-1]==c){
			if (count>1){
				printf("%d",count-1);
			}
			
			n=5;
		}
		else{
			printf("%d ",count);
		}
	}
	
	return 0;
}
