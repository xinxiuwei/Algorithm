#include<stdio.h>
#include<string.h>
int main()
    {
    int minSize,maxSize,n,count=0;
    
    scanf("%d%d",&minSize,&maxSize);
    scanf("%d",&n);
    int* fishSize=new int[n];
    for(int i=0;i<n;i++)
        {
        scanf("%d",&fishSize[i]);
    }
    
    
    int* Size=new int[maxSize-minSize+1];
    memset(Size,0,maxSize-minSize);
    for(int i=minSize;i<=maxSize;i++)
        {
        for(int j=0;j<n;j++)
            {
            if((2*fishSize[j]<=i && i<=10*fishSize[j] )||( 2*i<=fishSize[j] && fishSize[j]<=10*i))
                {
                Size[i-minSize]=1;//1表示被吃
                break;
            }
 
        }
    }
    for(int i=0;i<maxSize-minSize+1;i++)
        {
        if(Size[i]==0)
            {
            count++;
        }
            
    }
    printf("%d\n",count);
        
    
    return 0;
    
}