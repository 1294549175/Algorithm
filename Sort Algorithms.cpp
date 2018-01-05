#include <iostream>
#include <vector>
 
using namespace std;
 
// ����ð������
vector<int> bubbleSort_1(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}
	result = list;
	int temp;
	// Ҫ�����Ĵ���
	for (int i = 0; i < result.size() - 1; ++i){
		// �Ӻ���ǰ���εıȽ������������Ĵ�С������һ�κ󣬰������е�iС�������ڵ�i��λ����
		for (int j = result.size() - 1; j > i; j--){
			// �Ӻ���ǰ���εıȽ������������Ĵ�С������һ�κ󣬰������е�iС�������ڵ�i��λ����
			if (result[j - 1] > result[j]){
				temp = result[j - 1];
				result[j - 1] = result[j];
				result[j] = temp;
			}
		}
	}
	return result;
}

// �Ż�ð������
vector<int> bubbleSort_2(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}
 
	result = list;
	int temp;
	// Ҫ�����Ĵ���
	for (int i = 0; i < result.size() - 1; ++i){
		//������־λ
		bool bChanged = false;
		// �Ӻ���ǰ���εıȽ������������Ĵ�С������һ�κ󣬰������е�iС�������ڵ�i��λ����
		for (int j = result.size() - 1; j > i; j--){
			// �Ӻ���ǰ���εıȽ������������Ĵ�С������һ�κ󣬰������е�iС�������ڵ�i��λ����
			if (result[j - 1] > result[j]){
				temp = result[j - 1];
				result[j - 1] = result[j];
				result[j] = temp;
				bChanged = true;
			}
		}
		// �����־Ϊfalse��˵�����ֱ���û�н������Ѿ����������У����Խ�������
		if (false == bChanged){
			break;
		}
		printf("�� %d �ˣ� ", i);
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
 
	return result;
}
 
// ֱ�Ӳ�������
vector<int> insertSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}
	result = list;
	// ��1�����϶�������ģ��ӵ�2������ʼ���������β�����������
	for (int i = 1; i < result.size(); i++){
		// ȡ����i��������ǰi-1�����ȽϺ󣬲������λ��
		int temp = result[i];
		// ��Ϊǰi-1�������Ǵ�С������������У�����ֻҪ��ǰ�Ƚϵ���(list[j])��temp�󣬾Ͱ����������һλ
		int j = i - 1;
		for (j; j >= 0 && result[j] > temp; j--){
			result[j + 1] = result[j];
		}
		result[j + 1] = temp;
	}
	return result;
}

// ϣ������
vector<int> ShellSort(vector<int> list){
	vector<int> result = list;
	int n = result.size();
	for (int gap = n >> 1; gap > 0; gap >>= 1){
		for (int i = gap; i < n; i++){
			int temp = result[i];
			int j = i - gap;
			while (j >= 0 && result[j] > temp){
				result[j + gap] = result[j];
				j -= gap;
			}
			result[j + gap] = temp;
		}
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

// ���������division����
int division(vector<int> &list, int left, int right){
	// ������ߵ���(left)Ϊ��׼
	int base = list[left];
	while (left < right) {
		// �������Ҷ˿�ʼ�����������ֱ���ҵ�С��base����
		while (left < right && list[right] >= base)
			right--;
		// �ҵ��˱�baseС��Ԫ�أ������Ԫ�طŵ�����ߵ�λ��
		list[left] = list[right];
 
		// ��������˿�ʼ�����ұ�����ֱ���ҵ�����base����
		while (left < right && list[left] <= base)
			left++;
		// �ҵ��˱�base���Ԫ�أ������Ԫ�طŵ����ұߵ�λ��
		list[right] = list[left];
	}
 
	// ���base�ŵ�leftλ�á���ʱ��leftλ�õ������ֵӦ�ö���leftС��
	// ��leftλ�õ��Ҳ���ֵӦ�ö���left��
	list[left] = base;
	return left;
}
 
// ��������
void QuickSort(vector<int> &list, int left, int right){
	// ���±�һ��С�����±꣬�����Խ����
	if (left < right) {
		// ��������зָȡ���´ηָ�Ļ�׼���
		int base = division(list, left, right);
 
		// �ԡ���׼��š�����һ����ֵ���еݹ���и�����ڽ���Щ��ֵ����������
		QuickSort(list, left, base - 1);
 
		// �ԡ���׼��š��Ҳ��һ����ֵ���еݹ���и�����ڽ���Щ��ֵ����������
		QuickSort(list, base + 1, right);
	}
}

// ��ѡ������
vector<int> SelectSort(vector<int> list){
	// ��Ҫ���������Сֵ�Ĵ���
	// Ҫע��һ�㣬��Ҫ���� N �������Ѿ����� N-1 �α������Ѿ�����������
	vector<int> result = list;
	for (int i = 0; i < result.size(); i++){
		// ����������Сֵ������
		int index = i;
		// ����������Сֵ������
		for (int j = i + 1; j < result.size(); j++){
			if (result[index] > result[j]){
				index = j;
			}
		}
		// ���ҵ��ĵ�i��С����ֵ���ڵ�i��λ����
		swap(result[i], result[index]);
		cout << "��" << i + 1<< "��:\t";
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

// ������ĳ�ʼ������
void HeapAdjust(vector<int> &list, int parent, int length){
	int temp = list[parent];					// temp���浱ǰ���ڵ�
	int child = 2 * parent + 1;					// �Ȼ������
 
	while (child < length){
		// ������Һ��ӽ�㣬�����Һ��ӽ���ֵ�������ӽ�㣬��ѡȡ�Һ��ӽ��
		if (child + 1 < length && list[child] < list[child + 1]){
			child++;
		}
 
		// ������Һ��ӽ�㣬�����Һ��ӽ���ֵ�������ӽ�㣬��ѡȡ�Һ��ӽ��
		if (temp >= list[child]){
			break;
		}
 
		// �Ѻ��ӽ���ֵ���������
		list[parent] = list[child];
 
		// ѡȡ���ӽ������ӽ��,��������ɸѡ
		parent = child;
		child = 2 * parent + 1;
	}
	list[parent] = temp;
}
 
// ������
vector<int> HeadSort(vector<int> list){
	int length = list.size();
	// ѭ��������ʼ��
	for (int i = length / 2; i >= 0; i--){
		HeapAdjust(list, i, length);
	}
 
	// ����n-1��ѭ�����������
	for (int i = length - 1; i > 0; i--){
		// ���һ��Ԫ�غ͵�һԪ�ؽ��н���
		int temp = list[i];
		list[i] = list[0];
		list[0] = temp;
 
		// ɸѡ R[0] ��㣬�õ�i-1�����Ķ�
		HeapAdjust(list, 0, i);
		cout << "��" << length - i << "������:";
		for (int i = 0; i < list.size(); i++){
			cout << list[i] << " ";
		}
		cout << endl;
	}
	return list;
}

// �鲢����ĺϲ�����
void Merge(vector<int> &input, int left, int mid, int right, vector<int> temp){
	int i = left;				// i�ǵ�һ�����е��±�
	int j = mid + 1;			// j�ǵڶ������е��±�
	int k = 0;					// k����ʱ��źϲ����е��±�
	
	// ɨ���һ�κ͵ڶ������У�ֱ����һ��ɨ�����
	while (i <= mid && j <= right){
		// �жϵ�һ�κ͵ڶ���ȡ�������ĸ���С���������ϲ����У�����������ɨ��
		if (input[i] <= input[j]){
			temp[k++] = input[i++];
		}
		else{
			temp[k++] = input[j++];
		}
	}
	// ����һ�����л�ûɨ���꣬����ȫ�����Ƶ��ϲ�����
	while (i <= mid){
		temp[k++] = input[i++];
	}
 
	// ���ڶ������л�ûɨ���꣬����ȫ�����Ƶ��ϲ�����
	while (j <= right){
		temp[k++] = input[j++];
	}
 
	k = 0;
	// ���ϲ����и��Ƶ�ԭʼ������
	while (left <= right){
		input[left++] = temp[k++];
	}
}

// �鲢����
void MergeSort(vector<int> &input, int left, int right, vector<int> temp){
	if (left < right){
		int mid = (right + left) >> 1;
		MergeSort(input, left, mid, temp);
		MergeSort(input, mid + 1, right, temp);
		Merge(input, left, mid, right, temp);
	}
}
 
// �鲢����
void mergesort(vector<int> &input){
	// ������ǰ���Ƚ���һ�����ȵ���ԭ���鳤�ȵ���ʱ���飬����ݹ���Ƶ�����ٿռ�
	vector<int> temp(input.size());				
	MergeSort(input, 0, input.size() - 1, temp);
}

// �������������������������λ���ĺ���
int MaxBit(vector<int> input){
	// �������ֵ
	int max_data = input[0];
	for (int i = 1; i < input.size(); i++){
		if (input[i] > max_data){
			max_data = input[i];
		}
	}
 
	// �������ֵ��λ��
	int bits_num = 0;
	while (max_data){
		bits_num++;
		max_data /= 10;
	}
 
	return bits_num;
}
 
// ���������ȡ��xxx�ϵĵ�dλ����
int digit(int num, int d){
	int pow = 1;
	while (--d > 0){
		pow *= 10;
	}
	return num / pow % 10;
}
 
// ��������
vector<int> RadixSort(vector<int> input, int n){
	// ��ʱ���飬���������������е�����
	vector<int> bucket(n);					
	// λ���������ӵ�0��Ԫ�ص���9��Ԫ������������¼��ǰ�Ƚ�λ��0���ж��ٸ�...��9���ж��ٸ���
	vector<int> count(10);				
	// �ӵ�λ����λѭ��
	for (int d = 1; d <= MaxBit(input); d++){
		// ��������0
		for (int i = 0; i < 10; i++){
			count[i] = 0;
		}
 
		// ͳ�Ƹ���Ͱ�еĸ���
		for (int i = 0; i < n; i++){
			count[digit(input[i],d)]++;
		}
 
		/*
		* ����ĳ�ξ�������ͳ�ƺ���Ϊ��[0, 2, 3, 3, 0, 0, 0, 0, 0, 0]�򾭹��������� ���Ϊ�� [0, 2,
		* 5, 8, 8, 8, 8, 8, 8, 8]��ʵ����ֻ������[0, 2, 5, 8, 0, 0, 0, 0, 0, 0]��
		* ���������õ�����Ϊ����λ�����ڣ����Ƿֱ��ʾ���£�2��ʾ�Ƚ�λΪ1��Ԫ�ؿ��Դ��������Ϊ1��0��
		* λ�ã�5��ʾ�Ƚ�λΪ2��Ԫ�ؿ��Դ����4��3��2����(5-2=3)λ�ã�8��ʾ�Ƚ�λΪ3��Ԫ�ؿ��Դ����
		* 7��6��5����(8-5=3)λ��
		*/
		for (int i = 1; i < 10; i++){
			count[i] += count[i - 1];
		}
 
		/*
		* ע������ֻ�ܴ��������ǰѭ������Ϊ����ʱ���豣����ǰ��������õ�˳�򣬲�Ӧ�ô�
		* ��ԭ�����źõ��������ǰ����������ԭ����ǰ���ڵ�����ȥ����Ϊ�ڴ���ĳ��
		* Ԫ�ص�λ��ʱ��λ�������ǴӴ󵽵�С��count[digit(arr[i], d)]--���ķ�ʽ����
		* ��ģ����ȴ���������Ԫ�أ��ٴ������С��Ԫ�أ�����������һ��Ԫ�ؿ�ʼ����
		* ����������һ������[212,213,312]��������մӵ�һ��Ԫ�ؿ�ʼѭ���Ļ���������һ��
		* �󣨸�λ������󣬵õ�����һ������[312,212,213]����һ�κ���ûʲô���⣬�������
		* �ӵڶ��ֿ�ʼ���֣��ڶ�������󣬻�õ�[213,212,312]��������λΪ3��Ԫ�ر�Ӧ��
		* ������󣬵������ڶ��ֺ�ȴ������ǰ���ˣ����Գ���������
		*/
		for (int i = n - 1; i >= 0; i--){
			int k = digit(input[i], d);
			bucket[count[k] - 1] = input[i];
			count[k]--;
		}
 
		// ��ʱ���鸴�Ƶ� input ��
		for (int i = 0; i < n; i++){
			input[i] = bucket[i];
		}
	}
 
	return input;
}
