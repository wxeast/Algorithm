#pragma  once 
#include<assert.h>
#include<algorithm>
#include<Windows.h>
#include<stack>
//�������� 
//������ (�ӽ�����)ʱ�临�Ӷ�   Ϊ  N*N
//��õ���� (�ӽ�����)ʱ�临�Ӷ�   Ϊ N
void InsertSort(int* array,const size_t n)
{
	assert(array);
	for(size_t  i = 1 ;i < n;++i)
	{
		int tmp = array[i];
		int end = i-1;//ʹ��һ��end����ʾ������������е�λ�� 
		//��������
		while(end>= 0)
		{
			//���뵽һ������������� 
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
		//�ҵ�λ�� ������ֵ�����ȥ 
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
//ϣ������ 
//����㷨ʱ�临�Ӷ� ���ü���
//ʱ�临�Ӷȴ��¿�֪��  Ϊ [N ,N*N];
void ShellSort(int *array,const  size_t n )
{
	int gap =  n;
	//����   ֱ�ӵĲ�������  
	while(gap > 1)
	{
		gap = gap/3+1;
		//Ԥ���� gap������� 
		for(size_t  i = gap;i < n;++i)
		{
			int tmp =array[i];
			int end  =i-gap;
			//���� gap���������
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
//ѡ������
// ʱ�临�Ӷ� Ϊ N*N
//void SelectSort(int * array,const size_t n)
//{
//	assert(array);
//	int end  = n;//endl
//	while(end > 0)
//	{
//		end--;
//		int maxidex = 0 ;
//		//�������� 
//		for(size_t  i = 0 ;i <= end;++i)
//		{
//			//�ҵ�����ֵ���±�
//			if(array[i] > array[maxidex])
//			{
//				maxidex = i;
//			}
//		}
//		swap(array[maxidex],array[end]);
//	}	
//}

//

//ѡ��������Ż�  
//ͬʱ �ҵ����Ļ�����С�� 
//ʱ�临�Ӷ�Ϊ  N*N
//��ʱ�临�Ӷ�  ��ʱ ��Ҫ ֻ��ѭ���Ĵ��� ������Ҫ���ṹ 
//����ѭ������ ���Ǵ����ߵ��м� N��
void SelectSort(int *  array,const size_t  n)
{
	assert(array);
	int  left =  0;//left��ʾ��������λ   
	int right  = n-1;   
	while(left < right)
	{
		int  maxidex  = left ;//�ȶ���һ����ֵ
		int  minidex  = left;
		//��������    ��  left �ߵ�right
		for(size_t   i =  left;i <=right;++i)
		{
			if(array[i]> array[maxidex])//�õ����ֵ���±�
			{
				maxidex  =  i;
			}
			if(array[i] < array[minidex] )//�õ���Сֵ���±� 
			{
				minidex  =  i ;
			}
		}
		//�˴�Ҫע�� ����  ������Ҫ�� maxidex��ֵ���þ���left
		//���Ҫ�ǽ����Ļ� ������ô��Ҫ�� ���ֵ��λ��  ���� 
		swap(array[left],array[minidex]);

		if(maxidex == left)//��������ֵ��λ��  
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

//������ ֱ��ʹ�õ��� �⺯�� 
//ʱ�临�Ӷ� Ϊ N*logN
//void  HeapSort(int * array,const size_t n)
//{
//	assert(array);
//	//�Ƚ���
//	make_heap(array,array+n);
//	for(size_t   i = 0 ;i < n-1;++i)
//	{
//		pop_heap(array,array+n-i);
//	}
//}



//������    �Լ�ʵ�� 
//��Ҫ�Լ�ʵ��һ�����µ����ĺ���  
//Ҫ��   ���� ����������Ҫ���� һ�����
//������һ��������� �������� ���Ѿ��� ���
void AdjustDown(int * array, int K,const  size_t   n)
{
	int parent = K;				//����һ�����ڵ���±� 
	int child  = parent *2+1;	//�õ�һ�����ӽڵ���±�
	while(child < n)
	{
		//�ҵ����������������Ǹ��ڵ���±�   �� child
		if((child + 1) < n && array[child+1] >array[child])
		{
			child++;
		}
		//Ҫ�Ǻ��ӽڵ��ֵ���� ���ڵ��ֵ  
		//��  ���ӽڵ��ֵ �� ���׽ڵ��ֵ ���н���
		//���ᵼ�� �����Ľṹ���Ǵ��
		//����Ҫ�������µ���
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
	//�ȶ����������� ���н���
	//���Ҫ��֤�����������Ǵ�ѵĻ���������Ҫ�ӵ�һ����Ҷ�ӽڵ���� ����
	for(int i = (n-1-1)/2; i >= 0;--i)
	{
		AdjustDown(array,i,n);
	}
	int  end = n;//ʹ�� end��Ϊ  �Ѿ��õ������� ��ֵ   ��ʼ�±�   ��ʼֵ Ϊn��
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
//ð������ 	
//ʱ�临�Ӷ� Ϊ 
//������(�����ʱ�� )N*N
//��õ����(����  ) N
//���� �����˵����   ��������  ���� 

void BubbleSort(int *array,const size_t n  )
{
	assert(array);
	for(size_t i = 0 ;i < n-1;++i)
	{
		//�������� 
		//�Ż�  ʹ��һ���� ����¼�����Ĵ��� 
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
		if(count == 0)//Ҫ�ǽ����Ĵ��� Ϊ0 ��ʾ �Ѿ� ���������
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

//��������
//��������һ��ʹ�õ��� �ݹ��㷨 
//[left,right]

//��������
//1������ָ��--����
//2���ڿӷ���
//3��ǰ��ָ�뷨


//�Ż�  
//1������ȡ��  �ҵ��м�ֵ   (������������� )
//2��С�����Ż� (�����������Сʱ    ������ʹ�õĿ�������  �������Ե��е��鷳�� ����������ʹ�ò������� �������� )

//1������ָ�뽻����
int PartSort1(int *  array,int left,int right)
{
	//ȡһ���м�ֵ��Ϊ   �ؼ���
	int key  =  right;
	while(left < right)
	{
		//������ҵ�һ���ȹؼ�ֵ���
		while(left<right&& array[left] <=array[key] )//�Ⱥű������  ������ִ���(��ѭ��)
		{
			++left;
		}
		//���ұ��ҵ�һ�� �� �ؼ�ֵС��
		while(left < right && array[right] >= array[key])
		{
			--right;
		}
		swap(array[left],array[right]);
	}
	swap(array[left],array[key]);
	return  left;//��Ҫ����һ���м�ֵ  
}

//2��
int PartSort2(int * array,int left,int right)
{
	int key  =  array[right];//�õ�keyֵ 
	while(left < right)
	{
		//��right��Ϊ��
		//�ҵ���key�����  � ����
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

//3��
int  PartSort3(int *array,int left,int right)
{
	//assert(array);
	int cur = left;
	int prev = left-1;//������ʾ ���� ��key���ǰһ���±� 
	int key  = array[right];
	while(cur < right)
	{
		if(array[cur] <= key)//�ҵ�һ���� keyС��
		{
			prev++;//�ҵ��� key��� 
			swap(array[cur],array[prev]);//���� ��  ���   �ŵ����� 
		}
		cur++;//cur����� 
	}
	++prev;
	swap(array[right],array[prev]);
	return prev;
}



//[left,right]
void QuickSort1(int * array,int left,int right)
{
	assert(array);
	//���Ҫ�� 
	if(right-left  <20)
	{
		InsertSort(array+left,right-left+1);
		return ;
	}
	int ret = PartSort2(array,left,right);//�õ��ָ��
	//����ߵĽ��� ����  
	QuickSort1(array,left,ret-1);
	//���ұߵĽ��� ����
	QuickSort1(array,ret+1,right);
}

//С������Ż� 
void QuickSort2(int * array,int left,int right)
{
	assert(array);
	//���Ҫ�� 
	if(left >= right)
		return ;
	if(right-left  <20)
	{
		InsertSort(array+left,right-left+1);
		return ;
	}
	int ret = PartSort2(array,left,right);//�õ��ָ��
	//����ߵĽ��� ����  
	QuickSort2(array,left,ret-1);
	//���ұߵĽ��� ����
	QuickSort2(array,ret+1,right);
}
//�ǵݹ�ʵ��һ���������� 
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
	//���Ż�
	int  left = GetTickCount();
	QuickSort1(array,0,n-1);
	int right =  GetTickCount();
	cout<<right-left<<endl;
	//С������Ż� 
	left = GetTickCount();
	QuickSort1(array,0,n-1);
	right =  GetTickCount();
	cout<<right-left<<endl;
	//QuickSortNonR(array,n);
	Print(array,n);
}
//�鲢���� 
//���� ��������  ������ ������
//Ȼ�� �������������������������
void _MergeSort(int * array,int * tmp,int left,int right)
{
	//������ֻ��һ����ʱ ��������Ϊ����
	if(left	>= right)
	{
		return ;
	}
	//�������������������
	int mid = left + ((right-left)>>1);
	_MergeSort(array,tmp,left,mid);
	_MergeSort(array,tmp,mid+1,right);


	//���˴�˵���������ϵ����Ѿ�����  
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


//�������� 

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
//�ȵ�λ�ٸ�λ
void  LSDSort(int *array,size_t n)
{
	int degit = GetMaxDegit(array,n);
	int base = 1;
	for(size_t  j = 0 ;j < degit;++j)
	{
		int  count[10] = {0};
		int	 start[10] = {0};
		//��¼ÿ���±��λ�� 
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
//�ȸ�λ�ٵ�λ
//�������� 
//[left,ri]ht]   ��ʾ�ҵ���λ��ȣ����������� ��λ����  
void MSDPartSort(int *array,int left,int right,int base,int n)
{
	int  count[10] = {0};
	int	 start[10] ={left};
	//��¼ÿ��λ�õ����� �ĸ���
	for(size_t i = left ;i <= right;++i)
	{
		int num = (array[i]/base)%10;
		count[num]++;
	}
	//�ҵ�ÿ��λ�õ���ʼλ��
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
		int left  = 0;//ʹ�� left��ʾ���� ��ͬ��λ�������±��
		int right  =0 ;// ��ͬ��λ�����±�
		while(right<n)
		{
			int num1 = array[left]/(base*10);//�ҵ�ÿ�����ĸ�λ
			int num2  =array[right]/(base*10);
			if(num1!= num2)//���Ҫ����ȵĻ� 
			{
				MSDPartSort(array,left,right-1,base,n);//��֮ǰ�������� 
				left  =right;//������� Ѱ�� ����λ��ȵ���  
			}
			else
			{
				right++;
			}
		}
		if(left != right)//�����ߵ���ͷ֮��  �ѵ�ǰ�����������  
		{
			MSDPartSort(array,left,right-1,base,n);
		}
		base /=10;//j�������λ����  
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