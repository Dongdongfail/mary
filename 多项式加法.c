# include <stdio.h>

int main()
{
	
	int x[100]={0};
	int a,b;
	int key=0;
	int max=0;
	int i=0;
	
	key=0;
	
	while(key!=2){
		scanf("%d %d",&a,&b);
		if(a==0){
			key++;
		}
		if(a>max){
			max=a;
		}
		if(x[a]==0){
			x[a]=b;
		}else{
			x[a]+=b;
		}
		
	}
	for(i=max;i>-1;i--){
		if(x[i]!=0){
			if(i==0){
				printf("%d",x[i]);
			}else if(i==1){
				printf("%dx",x[i]);
				if(x[0]!=0){
					printf("+");
				}
			}else{
				printf("%dx%d",x[i],i);
				for(;i>-1;i--){
					if(x[i]!=0){
						printf("+");
						break;
					}
				}
			}	
		}
	}
	return 0;		


	}
	
