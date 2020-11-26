#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HeapCapacity 64
typedef struct TreeNode *HuffmanTree;
struct TreeNode{
	int weight;
	HuffmanTree Left,Right;
};

typedef struct HeapNode *MinHeap;
struct HeapNode{
	HuffmanTree *Data;
	int Size;
};
HuffmanTree createHuffman();
void insertHeap(MinHeap H,HuffmanTree huff);
MinHeap createHeap(){
	MinHeap H=(MinHeap)malloc(sizeof(struct HeapNode));
	H->Data=(HuffmanTree*)malloc(sizeof(struct TreeNode)*HeapCapacity);
	H->Size=0;
	HuffmanTree huff=createHuffman();
	H->Data[0]=huff;
	return H;
}
HuffmanTree createHuffman(){
	HuffmanTree T=(HuffmanTree)malloc(sizeof(struct TreeNode));
	T->weight=0;
	T->Left=NULL;
	T->Right=NULL;
	return T;
}
MinHeap initHeap(int N,int F[]){
	MinHeap H=createHeap();
	HuffmanTree huff;
	char c;
	int f,i;
	for(i=0;i<N;i++){
		getchar();
		scanf("%c %d",&c,&f);
		F[i]=f;
		huff=createHuffman();
		huff->weight=f;
		insertHeap(H,huff);
	}
	return H;
}
void insertHeap(MinHeap H,HuffmanTree huff){
	int i=++H->Size;
	for(;H->Data[i/2]->weight>huff->weight;i/=2){
		H->Data[i]=H->Data[i/2];
	}
	H->Data[i]=huff;
}
HuffmanTree deleteMin(MinHeap H){ 
	HuffmanTree minItem=H->Data[1];
	HuffmanTree temp=H->Data[H->Size--];
	int parent,child;
	for(parent=1;parent*2<=H->Size;parent=child){
		child=2*parent;
		if((child!=H->Size)&&(H->Data[child+1]->weight<H->Data[child]->weight))
		child++;
		if(H->Data[child]->weight<temp->weight)
		H->Data[parent]=H->Data[child];
		else {
			H->Data[parent]=temp;
			break;
		}		
	}
	H->Data[parent]=temp;
	
	return minItem;
}
HuffmanTree huffman(MinHeap H){
	HuffmanTree huff;
	int i;
	int times=H->Size;
	for(i=1;i<times;i++){
		huff=createHuffman();
		huff->Left=deleteMin(H);
		huff->Right=deleteMin(H);
		huff->weight=huff->Left->weight+huff->Right->weight;
	    insertHeap(H,huff);	
	}
	return huff;
}
int WPL(HuffmanTree huff,int depth){
	if((huff->Left==NULL)&&(huff->Right==NULL)){
//	  printf("%d\n",depth*huff->weight);
	  return depth*huff->weight;
    }
	else return WPL(huff->Left,depth+1)+WPL(huff->Right,depth+1);
}                        
int checkSubmit(char code[],HuffmanTree current){
	int i;
	for(i=0;i<strlen(code);i++){
		if(code[i]=='0'){
			if(current->Left==NULL){
				current->Left=createHuffman();
			}else if(current->Left->weight==-1)
			return 0;			
			current=current->Left;
		}
		else if(code[i]=='1'){
			if(current->Right==NULL){
				current->Right=createHuffman();
			}else if(current->Right->weight==-1)
			return 0;
			current=current->Right;			
		}
		
	}
	current->weight=-1;
	if(current->Left==NULL&&current->Right==NULL)
	return 1;
	else return 0;
}
int main()
{
	int N,x,y,p;
	scanf("%d",&N);
	int F[N];
	MinHeap H=initHeap(N,F);
//	printf("N=%d,Size=%d\n",N,H->Size);
//	p=H->Size;
//	for(x=0;x<p;x++){
//		y=deleteMin(H)->weight;
//		printf("%d\n",y);
//	}
	HuffmanTree huff=huffman(H);
	int codeLen=WPL(huff,0);
//	printf("WPL=%d\n",codeLen);
	int M;
	scanf("%d",&M);
	char ch;
	char code[N+1];
	int i;
	for(i=0;i<M;i++){
		int counter=0;
		int result=1;
		int flag=0;
		HuffmanTree head=createHuffman();
		HuffmanTree current;
		int k;
		for(k=0;k<N;k++){
			current=head;
			getchar();
			scanf("%c",&ch);
			scanf("%s",code);
			counter+=strlen(code)*F[k];
			if(flag==0){
				result=checkSubmit(code,current);
				if(result==0)
				flag=1;
			}
		}
//		if(counter==codeLen)
//		    printf("WPL:Yes\n");
//		    else printf("No,WPL=%d,counter=%d\n",codeLen,counter);
//		if(result==1)
//		    printf("prefix:Yes\n");
//		    else printf("prefix:No\n");
	    if(counter==codeLen&&result==1){
		    printf("Yes\n");
	    }else{
		    printf("No\n");
	    }
	}
	return 0;
}
