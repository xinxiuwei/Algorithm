
/*...............

一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，
假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。n个任务可以按照任意顺序放入CPU进行处理，
现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。 

输入描述:

输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)
第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。


输出描述:
输出一个整数，表示最少需要处理的时间


解题思路：
根据题目意思，两个CPU平摊任务，然后输出执行这些任务的最小时间，
最理想的情况是，每个CPU执行的任务占所有任务的总时间的一半（wholeTime/2），
这样两个CPU执行的时间差就是最小的，输出的结果就是最小的，
但任务只能由一个CPU独立完成，所以单个任务的执行时间已经是不可分割的了。
解决的办法就是尽量让单个CPU执行的任务总时间接近wholeTime/2，越接近这个值，
则这个CPU和另一个CPU的执行时间差就必定越小。也就能得到最优解，
所以只要讨论一个CPU即可，而且希望它的执行时间越接近wholeTime/2就越好，
这就与01背包问题挂上钩了，问题转化为限制背包的容量为wholeTime/2，
每个任务转化为每个物品，物品的价值和大小都是任务的执行时间，这样一来，
只要求得背包总价值最大即可得到原问题的答案了.

.........................*/
#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
    {cd
    int n,n1=0,n2=0;
    int sum=0;
    scanf("%d",&n);
    int* length=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&length[i]);
        sum+=length[i]/1024;
    }
    int* dp=new int[sum/2+1];
    memset(dp,0,sum/2+1);
    for(int i=0;i<n;i++){
         for(int j=sum/2;j>=length[i]/1024;--j){
             dp[j]=max(dp[j],dp[j-length[i]/1024]+length[i]/1024);
         }
    }
    printf("%d",1024*max(dp[sum/2],sum-dp[sum/2]));
    
    
    return 0;
}