# include <stdio.h>

main()
{
	
	
	int r=0;
	int a=1;
	int b=0;
	int o=0; 
	
	scanf("%d",&r);
	if (r==0){
		printf("ling");
	}
	else{
		if(r<0){
			printf("fu ");
			r=-r;
		}
		o=r;
		for(;r>9;r/=10){
				a*=10;
			}
			for(;a>0;a/=10){
				b=o/a;
				switch(b){
					case 1:
						printf("yi");
						break;
					case 2:
						printf("er");
						break;
					case 3:
						printf("san");
						break;
					case 4:
						printf("si");
						break;
					case 5:
						printf("wu");
						break;
					case 6:
						printf("liu");
						break;
					case 7:
						printf("qi");
						break;
					case 8:
						printf("ba");
						break;
					case 9:
						printf("jiu");
						break;
					case 0:
						printf("ling");
						break;
				}
				o=o%a;
				if(a/10>0){
					printf(" ");
				}
			}
		
	}
	return 0;
	
}
