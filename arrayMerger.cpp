//Created by Rob Schlom May 2019

#include <iostream>
#include <vector>
#include <stdio.h>   
#include <stdlib.h>     
#include <time.h>
#include <limits>
#include <cstddef>

void printVec(std::vector<int> nums);
void printVecOfVec(std::vector<std::vector<int> > vecs);
std::vector<int> arrayMerger(std::vector<std::vector<int> >* numbers, int p, int r);
std::vector<int> merge(std::vector<int> a, std::vector<int> b);

int main(int argc, char** argv){
	std::cout << "filling vector" << std::endl;
	std::vector<std::vector<int> > arrays;
	srand(time(NULL));
	for (int k = 0; k < 16; k++){
		std::vector<int> toSort;
		int factor = rand() %100 + 1;
		for (int i = 1; i <= 10; i++){
			int val = factor*i;
			//std::cout << "pushed: " << i << std::endl;
			toSort.push_back(val);
		}
		arrays.push_back(toSort);
	}
	/*std::vector<int> sorted;
	for (int p = 0; p < 56; p++){
		sorted.push_back(std::numerical_limits<int>::min());
	}*/
	std::cout << "unsorted:" << std::endl;
	printVecOfVec(arrays);
	std::cout << "ready to operate" << std::endl;
	std::vector<int> solution = arrayMerger(&arrays, 0, arrays.size()-1);
	std::cout << "complete" << std::endl;
	printVec(solution);
}


void printVec(std::vector<int> nums){
	for (int i = 0; i < nums.size(); i++){
		std::cout << nums[i] << ", ";
	}
	std::cout << std::endl;
}

void printVecOfVec(std::vector<std::vector<int> > vecs){
	for (int i = 0; i < vecs.size(); i++){
		std::cout << "[";
		printVec(vecs[i]); 
		std::cout << "]" << std::endl << std::endl;
	}
}

std::vector<int> arrayMerger(std::vector<std::vector<int> >* numbers, int p, int r){
	if (p < r){
		int q = (p+r)/2;
		std::vector<int> left = arrayMerger(numbers, p, q);
		std::vector<int> right = arrayMerger(numbers, q+1, r);
		return merge(left, right);
	}
	else{
		return (*numbers)[p];
	}
}

//Takes two vectors of the same length n, and merges them into a vector of length 2n
std::vector<int> merge(std::vector<int> a, std::vector<int> b){
	std::vector<int> result;
	int i = 0;
	int j = 0;
	while (i < a.size() && j < a.size()){
		if (a[i] < b[j]){
			result.push_back(a[i]);
			i++;
		}
		else{
			result.push_back(b[j]);
			j++;
		}
	}
	while (i < a.size()){
		result.push_back(a[i]);
		i++;
	}
	while (j < a.size()){
		result.push_back(b[j]);
		j++;
	}
	return result;
}