/*
 * Sorting.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: bill
 */

#include "Sorting.h"

void merge(int arr[], int size, int low, int middle, int high) {
    int temp[size];
    for(int i = low; i <= high; ++i) {
    	temp[i] = arr[i];
    }
    int i = low, j = middle + 1, k = low;
    while(i <= middle && j <= high) {
    	if(temp[i] <= temp[j]) {
    		arr[k] = temp[i];
    		++i;
    	} else {
    		arr[k] = temp[j];
    		++j;
    	}
    	++k;
    }
    while(i <= middle) {
    	arr[k] = temp[i];
    	k++;
    	i++;
    }
}

void mergeSort(int arr[], int size, int low, int high) {
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergeSort(arr, size, low, mid);
        mergeSort(arr, size, mid+1, high);
        merge(arr, size, low, mid, high);
    }
    return;
}

// average O(n log n), worse case O(n^2)
void quickSort(int arr[], int left, int right) {
	int i = left;
	int j = right;
	int temp;
	int pivot = arr[(left + right) / 2];
	while(i <= j) {
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if(left < j)
		quickSort(arr,left,j);
	if(i < right )
		quickSort(arr,i,right);
}

// O(n^2)
void selectionSort(int arr[], int size) {
	int temp, i = 0, j = 0;
	while(i < size - 1) {
		j = i + 1;
		while(j < size) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

// O(n^2)
void insertionSort(int arr[], int size) {
	int temp, j = 0;
	for(int i = 1; i < size; ++i) {
		j = i;
		while(j > 0 && arr[j - 1] > arr[j]) {
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
}

// Average: O(log n)
// Best: O(1)
// Worst: O(log n)
int binary_search(int A[], int key, int imin, int imax)
{
  // test if array is empty
  if (imax < imin)
    // set is empty, so return value showing not found
    return 0;
  else
    {
      // calculate midpoint to cut set in half
      int imid = A[(imin + imax) / 2];

      // three-way comparison
      if (A[imid] > key)
        // key is in lower subset
        return binary_search(A, key, imin, imid - 1);
      else if (A[imid] < key)
        // key is in upper subset
        return binary_search(A, key, imid + 1, imax);
      else
        // key has been found
        return imid;
    }
}


void genAry(int arr[], int arr2[], int size) {
	int j = 0;
	for(int i = 0; i < size; i++) {
		j = rand() % 9999;
		*(arr + i) = j;
		*(arr2 + i) = j;
	}
}

void printMoreFrequent(const char *p) {
	int startChar = 'A';
	int endChar = 'Z';
	int pos = 0;
	std::vector<char> charV;
	std::vector<int> countV;
	std::vector<char>::iterator itr;
	while(*p != '\0') {
		if(*p >= startChar && *p <= endChar) {
			itr = std::find(charV.begin(), charV.end(), *p);
			if(itr != charV.end()) {
				pos = std::distance(charV.begin(),itr);
				std::cout << *p << "," << pos << "," << countV[pos] << std::endl;
				countV[pos] += 1;
			} else {
				charV.push_back(*p);
				countV.push_back(1);
			}
		}
		p++;
	}
	int high = 0;
	char cc = 0;
	for(uint i = 0; i < charV.size(); i++) {
		std::cout << charV[i] << "," << countV[i] << std::endl;
		if(countV[i] > high) {
			high = countV[i];
			cc = charV[i];
		}
	}
	std::cout << "Char: " << cc << " Count: " << high << std::endl;
}

int main_func7() {
	char p[] = "AAGGDXIDGHNNND";
	printMoreFrequent(p);
	return 0;
	const int size = 50000;
	int delta = size / 100;
	srand(time(0));
	int *nums1 = new int[size];
	int *nums2 = new int[size];
	genAry(nums1, nums2, size);

	int numbers[] = {5,10,1,6,2,9,3,8,7,4,6,11,5,2};

	//	int mid = (0 + 14) / 2;
//	std::cout << mid << "," << numbers[mid] << std::endl;
//	return 0;

//	int numbers[] = {5,10,1,6,2,9,3,8,7,4,6,11,5,7};
//	//quickSort(numbers,0,13);
//	mergeSort(numbers,14,0,13);
//	for(int i = 0; i < 14; i++) {
//		std::cout << i << "," << numbers[i] << std::endl;
//	}
//	return 0;
	//mergeSort(numbers,size,0,12);
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	std::cout << "Start time = " << currentDateTime() << std::endl;
	insertionSort(nums1,size);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - begin;
	std::cout << "End   time = " << currentDateTime() << " " << diff.count() << std::endl;
	begin = std::chrono::high_resolution_clock::now();
	std::cout << "Start time = " << currentDateTime() << std::endl;
	//quickSort(nums2,0,size-1);
	mergeSort(nums2,size,0,size - 1);
	end = std::chrono::high_resolution_clock::now();
	diff = end - begin;
	std::cout << "End   time = " << currentDateTime() << " " << diff.count() << std::endl;
	for(int i = 0; i < size; i += delta) {
		std::cout << i << "," << nums1[i] << "," << nums2[i] << "," << (nums1[i] - nums2[i]) << std::endl;
	}
	return 0;
}

