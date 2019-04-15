#include <stdio.h>
#include <time.h>
#define MAXN 5
#define MAXNN 25

int a[MAXN][MAXN];
int b[MAXNN]={0};
int searchSquare(int n);
int judgeSquare();
int N,NN,stdsum;
int totalcount,partcount;


int main(){

	 clock_t start,finish;
	 
	  totalcount=0;
	  partcount=0;
	
    printf("put a number between 3 and 5:\n");
    scanf("%d",&N);
	start = clock();

	NN=N*N;
	stdsum=(1+NN)*N/2;
    searchSquare(0);

	  finish=clock();
	  printf("找出所有排列的时间为time=%f ms\n",(double)finish-start/CLK_TCK);
	  printf("totalcount:%d\n",totalcount);
	   printf("searchdecount:%d\n",partcount);

    return 0;
}

int searchSquare(int n){
   int i,j;
    if(n==NN){
        if(judgeSquare()){
            printf("[");
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    printf("%d ",a[i][j]);
                }
            }
            printf("]\n\n");
			totalcount++;
        }
    }
    else{
        for(i=1;i<=NN;i++){
            if(b[i]==0){
                b[i]=1;
                a[n/N][n%N]=i;
                 searchSquare(n+1);
                b[i]=0;
            }
        }
    }
	return 0;
}

int judgeSquare(){
    int j,i;
    int sum1, sum2;
	int rsum[3]={0};
	int csum[3]={0};

    sum1 = 0;
    sum2 = 0;

	partcount++;

	for(i=0;i<N;i++){

		sum1 +=a[i][i];         
        sum2 += a[i][N- 1-i]; 
		for(j=0;j<N;j++){
			rsum[i]+=a[i][j];
			csum[i]+=a[j][i];
		}
	}
	for(i=0;i<N;i++){
		if(csum[i]!=stdsum|| rsum[i]!=stdsum){
		return 0;
		}
	}
	
    
    if (sum1 !=stdsum || stdsum != sum2)
        return 0;
    else
        return 1;
}
