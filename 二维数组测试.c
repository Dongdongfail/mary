# include <stdio.h>

int main()
{
	const int size;
	scanf("%d",&size);
	int a[size][size];
	int maxi=0,i,j,e,f,q;
	int key=0;
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%d",&a[i][j]);
		}
	}
//每行选最大的数 
	for(i=0;i<size;i++){
		key=0;
		maxi=0;
		for(j=0;j<size;j++){
			if(a[i][j]>maxi){
				maxi=a[i][j];
				f=j;
				e=i;
			}
		}
		for(q=0;q<size&&key==0;q++){
			if(a[q][f]<maxi){
				key=-1;
				break;
			}
		}
		if(key==0){
			printf("%d %d",e,f);
			break;
		}
	}
	if(key==-1){
		printf("NONE");
	}
	
	
	return 0;
}
