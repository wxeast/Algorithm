#pragma  once 
#include<assert.h>
#include<algorithm>
#include<Windows.h>
#include<stack>
//插入排序 
//最坏的情况 (接近逆序)时间复杂度   为  N*N
//最好的情况 (接近升序)时间复杂度   为 N
void InsertSort(int* array,const size_t n)
{
	assert(array);
	for(size_t  i = 1 ;i < n;++i)
	{
		int tmp = array[i];
		int end = i-1;//使用一个end来表示插入的有序数列的位置 
		//单次排序
		while(end>= 0)
		{
			//插入到一个有序的数列中 
			if(tmp < array[end])
			{
				array[end+1]  =array[end];
				--end;
			}
			else
			{
				break;
			}
		}
		//找到位置 ，，将值插入进去 
		array[end+1]  =tmp;
	}
}

void Print(int * array,const  size_t n)
{
	assert(array);
	for(size_t  i = 0 ;i< n;++i )
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void TestInsertSort()
{
	int array[] = {2,5,4,9,3,6,8,7,1,0};
	int  n= sizeof(array)/sizeof(int);
	InsertSort(array,n);
	Print(array,n);
}
//希尔排序 
//这个算法时间复杂度 不好计算
//时间复杂度大致可知在  为 [N ,N*N];
void ShellSort(int *array,const  size_t n )
{
	int gap =  n;
	//排序   直接的插入排序  
	while(gap > 1)
	{
		gap = gap/3+1;
		//预排序 gap组的数据 
		for(size_t  i = gap;i < n;++i)
		{
			int tmp =array[i];
			int end  =i-gap;
			//排序 gap间隔的数据
			while(end>=0)
			{
				if(tmp < array[end])
				{
					array[end+gap]  =array[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			array[end+gap]  =tmp;
		}
	}
}

void TestShellSort()
{
	int array[] = {2,5,4,9,3,6,8,7,1,0};
	int  n= sizeof(array)/sizeof(int);
	ShellSort(array,n);
	Print(array,n);
}
//选择排序
// 时间复杂度 为 N*N
//void SelectSort(int * array,const size_t n)
//{
//	assert(array);
//	int end  = n;//endl
//	while(end > 0)
//	{
//		end--;
//		int maxidex = 0 ;
//		//单趟排序 
//		for(size_t  i = 0 ;i <= end;++i)
//		{
//			//找到最大的值的下标
//			if(array[i] > array[maxidex])
//			{
//				maxidex = i;
//			}
//		}
//		swap(array[maxidex],array[end]);
//	}	
//}

//

//选择排序的优化  
//同时 找的最大的还有最小的 
//时间复杂度为  N*N
//求时间复杂度  此时 不要 只看循环的次数 ，，，要看结构 
//两个循环都是 都是从两边到中间 N次
void SelectSort(int *  array,const size_t  n)
{
	assert(array);
	int  left =  0;//left表示的是最左位   
	int right  = n-1;   
	while(left < right)
	{
		int  maxidex  = left ;//先定义一个基值
		int  minidex  = left;
		//单趟排序    从  left 走到right
		for(size_t   i =  left;i <=right;++i)
		{
			if(array[i]> array[maxidex])//得到最大值的下标
			{
				maxidex  =  i;
			}
			if(array[i] < array[minidex] )//得到最小值的下标 
			{
				minidex  =  i ;
			}
		}
		//此处要注意 的是  ，，，要是 maxidex的值正好就是left
		//如果要是交换的话 ，，那么就要将 最大值的位置  更改 
		swap(array[left],array[minidex]);

		if(maxidex == left)//更改最大的值的位置  
		{
			maxidex  = minidex;
		}
		swap(array[right],array[maxidex]);
		++left;
		--right;
	}
} 

void TestSelectSort()
{
	int array[] = {9,5,4,9,3,6,8,7,1,0};
	int  n= sizeof(array)/sizeof(int);
	SelectSort(array,n);
	Print(array,n);
}

//堆排序 直接使用的是 库函数 
//时间复杂度 为 N*logN
//void  HeapSort(int * array,const size_t n)
//{
//	assert(array);
//	//先建堆
//	make_heap(array,array+n);
//	for(size_t   i = 0 ;i < n-1;++i)
//	{
//		pop_heap(array,array+n-i);
//	}
//}



//堆排序    自己实现 
//需要自己实现一个向下调整的函数  
//要是   升序 ，，我们需要建立 一个大堆
//函数有一个假设就是 左右子树 都已经是 大堆
void AdjustDown(int * array, int K,const  size_t   n)
{
	int parent = K;				//定义一个父节点的下标 
	int child  = parent *2+1;	//得到一个孩子节点的下标
	while(child < n)
	{
		//找到两个孩子中最大的那个节点的下标   给 child
		if((child + 1) < n && array[child+1] >array[child])
		{
			child++;
		}
		//要是孩子节点的值大于 父节点的值  
		//将  孩子节点的值 与 父亲节点的值 进行交换
		//但会导致 子树的结构不是大堆
		//所以要继续向下调整
		if(array[child] > array[parent])
		{
			swap(array[child],array[parent]);
			parent =child;
			child = parent*2+1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int * array,const  size_t n)
{
	assert(array);
	//先对于整个数据 进行建堆
	//如果要保证左右子树都是大堆的话，，，就要从第一个非叶子节点进行 调整
	for(int i = (n-1-1)/2; i >= 0;--i)
	{
		AdjustDown(array,i,n);
	}
	int  end = n;//使用 end作为  已经得到的有序 的值   起始下标   初始值 为n；
	while(end > 1)
	{
		--end;
		swap(array[0],array[end]);
		AdjustDown(array,0,end);
	}
}
void TestHeapSort()
{
	int array[] = {9,5,4,9,3,6,8,7,1,0};
	int  n= sizeof(array)/sizeof(int);
	HeapSort(array,n);
	Print(array,n);
}
//冒泡排序 	
//时间复杂度 为 
//最坏的情况(降序的时候 )N*N
//最好的情况(升序  ) N
//但是 相对来说还是   插入排序  更优 

void BubbleSort(int *array,const size_t n  )
{
	assert(array);
	for(size_t i = 0 ;i < n-1;++i)
	{
		//单趟排序 
		//优化  使用一个数 来记录交换的次数 
		int j = 0;
		int count = 0 ;
		for(;j < n-1-i;++j)
		{
			if(array[j] > array[j+1])
			{
				swap(array[j],array[j+1]);
				count++;
			}
		}
		if(count == 0)//要是交换的次数 为0 表示 已经 是有序的了
			break;
	}
}
void TestBubbleSort()
{
	int array[] = {0,1,2,3,4,5,6,7,9,8};
	int  n= sizeof(array)/sizeof(int);
	BubbleSort(array,n);
	Print(array,n);

}

//快速排序
//快速排序一般使用的是 递归算法 
//[left,right]

//单趟排序
//1、左右指针--交换
//2、挖坑法；
//3、前后指针法


//优化  
//1、三数取中  找到中间值   (避免出现最坏的情况 )
//2、小区间优化 (当排序的区间小时    ，，，使用的快速排序  ，，，显得有点麻烦了 ，，，所以使用插入排序 ，，更快 )

//1、左右指针交换法
int PartSort1(int *  array,int left,int right)
{
	//取一个中间值作为   关键字
	int key  =  right;
	while(left < right)
	{
		//从左边找到一个比关键值大的
		while(left<right&& array[left] <=array[key] )//等号必须加上  否则出现错误(死循环)
		{
			++left;
		}
		//从右边找到一个 比 关键值小的
		while(left < right && array[right] >= array[key])
		{
			--right;
		}
		swap(array[left],array[right]);
	}
	swap(array[left],array[key]);
	return  left;//需要返回一个中间值  
}

//2、
int PartSort2(int * array,int left,int right)
{
	int key  =  array[right];//得到key值 
	while(left < right)
	{
		//将right作为坑
		//找到比key大的数  填到 坑中
		while(left < right  && array[left]<= key)
		{
			left++;
		}
		array[right] = array[left];
		if(left< right)
			--right;
		while(left <right&& array[right]>= key)
		{
			--right;
		}
		array[left]  = array[right];
		if(left<right)
			left++;
		//          0 1 2 3 4 5
	}
	array[left]  =key;
	return  left;
}

//3、
int  PartSort3(int *array,int left,int right)
{
	//assert(array);
	int cur = left;
	int prev = left-1;//用来表示 的是 比key大的前一个下标 
	int key  = array[right];
	while(cur < right)
	{
		if(array[cur] <= key)//找到一个比 key小的
		{
			prev++;//找到比 key大的 
			swap(array[cur],array[prev]);//交换 把  大的   放到后面 
		}
		cur++;//cur向后走 
	}
	++prev;
	swap(array[right],array[prev]);
	return prev;
}



//[left,right]
void QuickSort1(int * array,int left,int right)
{
	assert(array);
	//如果要是 
	if(right-left  <20)
	{
		InsertSort(array+left,right-left+1);
		return ;
	}
	int ret = PartSort2(array,left,right);//得到分割点
	//将左边的进行 排序  
	QuickSort1(array,left,ret-1);
	//将右边的进行 排序
	QuickSort1(array,ret+1,right);
}

//小区间的优化 
void QuickSort2(int * array,int left,int right)
{
	assert(array);
	//如果要是 
	if(left >= right)
		return ;
	if(right-left  <20)
	{
		InsertSort(array+left,right-left+1);
		return ;
	}
	int ret = PartSort2(array,left,right);//得到分割点
	//将左边的进行 排序  
	QuickSort2(array,left,ret-1);
	//将右边的进行 排序
	QuickSort2(array,ret+1,right);
}
//非递归实现一个快速排序 
void QuickSortNonR(int * array,const  size_t  n  )
{
	assert(array);
	stack<int> st;
	st.push(n-1);
	st.push(0);
	while(st.empty())
	{
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();
		int div  =  PartSort1(array,left,right);
		//[left,div-1];
		//[div+1.right];
		if(left < (div-1))
		{
			st.push(div-1);
			st.push(left);
		}
		if((div+1)< right)
		{
			st.push(right);
			st.push(div+1);
		}
	}
}

void TestQuickSort()
{
	int array[] = {0,1,2,3,4,5,6,7,9,8};
	int  n= sizeof(array)/sizeof(int);
	//无优化
	int  left = GetTickCount();
	QuickSort1(array,0,n-1);
	int right =  GetTickCount();
	cout<<right-left<<endl;
	//小区间的优化 
	left = GetTickCount();
	QuickSort1(array,0,n-1);
	right =  GetTickCount();
	cout<<right-left<<endl;
	//QuickSortNonR(array,n);
	Print(array,n);
}
//归并排序 
//假设 两个数组  已有序 ，，，
//然后 将两个数组里的数，，，排序
void _MergeSort(int * array,int * tmp,int left,int right)
{
	//当数组只有一个数时 ，，，，为有序
	if(left	>= right)
	{
		return ;
	}
	//让左右两个数组里的数
	int mid = left + ((right-left)>>1);
	_MergeSort(array,tmp,left,mid);
	_MergeSort(array,tmp,mid+1,right);


	//到此处说明两个集合的数已经有序  
	//
	int begin1  =left,end1 = mid;
	int begin2  = mid+1,end2 = right;
	int idex = left;
	while(begin1<= end1 && begin2<=end2)
	{
		if(array[begin1] <= array[begin2])
		{
			tmp[idex++]  = array[begin1++];
		}
		else
		{
			tmp[idex++]  = array[begin2++];
		}
	}
	while(begin1<= end1)
	{
		tmp[idex++] = array[begin1++]; 
	}
	while(begin2<= end2)
	{
		tmp[idex++] = array[begin2++]; 
	}
	while(left<=right)
	{
		array[left]  = tmp[left];
		left++;
	}
}

void MergeSort(int * array,const  size_t  n)
{
	int * tmp  = new int[n];
	_MergeSort(array,tmp,0,n-1);
	delete[] tmp;
}

void TestMergeSort()
{
	int array[] = {2,5,4,9,3,6,8,7,1,0};
	int  n= sizeof(array)/sizeof(int);
	MergeSort(array,n);
	Print(array,n);
}


//基数排序 

size_t  GetMaxDegit(int *  array,const size_t n)
{
	int base =10;
	int degit  = 1;
	for(size_t   i= 0 ;i < n;++i )
	{
		while(array[i] >= base)
		{
			++degit;
			base*= 10;
		}
	}
	return degit;
}
//先低位再高位
void  LSDSort(int *array,size_t n)
{
	int degit = GetMaxDegit(array,n);
	int base = 1;
	for(size_t  j = 0 ;j < degit;++j)
	{
		int  count[10] = {0};
		int	 start[10] = {0};
		//记录每个下标的位置 
		for(size_t i = 0 ;i < n;++i)
		{
			int num = (array[i]/base)%10;
			count[num]++;
		}
		for(size_t  i = 1 ;i < 10;++i)
		{
			start[i] = count[i-1] +start[i-1];
		}
		int * tmp = new int[n];
		for(size_t  i =  0;i < n;++i)
		{
			int num = (array[i]/base)%10;
			tmp[start[num]++] =array[i];
		}
		memcpy(array,tmp,sizeof(int)*n);
		base *= 10;
	}
}
//先高位再低位
//单趟排序 
//[left,ri]ht]   表示找到高位相等，，，，的数 低位排序  
void MSDPartSort(int *array,int left,int right,int base,int n)
{
	int  count[10] = {0};
	int	 start[10] ={left};
	//记录每个位置的数据 的个数
	for(size_t i = left ;i <= right;++i)
	{
		int num = (array[i]/base)%10;
		count[num]++;
	}
	//找到每个位置的起始位置
	for(size_t i = 1 ;i < 10;++i)
	{
		start[i] = count[i-1] +start[i-1];
	}
	int * tmp = new int[n];
	for(size_t  i =  left;i <= right;++i)
	{
		int num = (array[i]/base)%10;
		tmp[start[num]++] =array[i];
	}
	memcpy(array+left,tmp+left,sizeof(int)*(right-left+1));
	delete[] tmp;
}
void  MSDSort(int *array,size_t n)
{
	int  degit = GetMaxDegit(array,n);
	int base  = 1;
	for(size_t  i = 0;i <(degit-1);++i)
	{
		base *= 10;
	}
	for(size_t  j = 0 ;j < degit;++j)
	{
		int left  = 0;//使用 left表示的是 相同高位的数左下标的
		int right  =0 ;// 相同高位的右下标
		while(right<n)
		{
			int num1 = array[left]/(base*10);//找到每个数的高位
			int num2  =array[right]/(base*10);
			if(num1!= num2)//如果要是相等的话 
			{
				MSDPartSort(array,left,right-1,base,n);//将之前的数排序 
				left  =right;//继续向后 寻找 ，高位相等的数  
			}
			else
			{
				right++;
			}
		}
		if(left != right)//数组走到尽头之后  把但前组的数据排序  
		{
			MSDPartSort(array,left,right-1,base,n);
		}
		base /=10;//j继续向低位排序  
	}
}
void TestLSDSort()
{
	int array[] = {2,100,4,9,3,6,8,7,1,5};
	int  n= sizeof(array)/sizeof(int);
	//LSDSort(array,n);
	MSDSort(array,n);
	Print(array,n);
}