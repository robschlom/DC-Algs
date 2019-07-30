//Created by Rob Schlom May 2019

#include <iostream>
#include <vector>
#include <stdio.h>   
#include <stdlib.h>     
#include <time.h>

void printVec(std::vector<int> nums);
void minMaxMerge(std::vector<int>* numbers, int p, int r);
void mergeMM(std::vector<int>* numbers, int p, int q, int r);

int main(int argc, char** argv){
	std::cout << "filling vector" << std::endl;
	std::vector<int> toSort;
	srand(time(NULL));
	for (int i = 500; i >0; i--){
		int val = rand() % 1000 + 1;
		//std::cout << "pushed: " << i << std::endl;
		toSort.push_back(val);
	}
	std::cout << "unsorted:" << std::endl;
	printVec(toSort);
	std::cout << "ready to operate" << std::endl;
	minMaxMerge(&toSort, 0, toSort.size()-1);
	std::cout << "complete" << std::endl;
	printVec(toSort);
}


void printVec(std::vector<int> nums){
	for (int i = 0; i < nums.size(); i++){
		std::cout << nums[i] << ", ";
	}
	std::cout << std::endl;
}

void minMaxMerge(std::vector<int>* numbers, int p, int r){
	if (p < r){
		int q = (p+r)/2;
		minMaxMerge(numbers, p, q);
		minMaxMerge(numbers, q+1, r);
		mergeMM(numbers, p, q, r);
	}
}

void mergeMM(std::vector<int>* numbers, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	std::vector<int> left;
	std::vector<int> right;
	for (int i = 0; i < n1; i++){
		left.push_back((*numbers)[p+i]);
	}
	for (int j = 0; j < n2; j++){
		right.push_back((*numbers)[q+j+1]);
	}
	//put min in leftmost spot with 1 comparison
	if (right[0] < left[0]){
		int temp = left[0];
		left[0] = right[0];
		right[0] = temp;
	}
	//Put max on rightmost spot
	if (left[left.size()-1] > right[right.size()-1]){
		int temp = right[right.size()-1];
		right[right.size()-1] = left[left.size()-1];
		left[left.size()-1] = temp;
	}
	//recombine left and right with min on left, max on right
	for (int k = 0; k < left.size(); k++){
		(*numbers)[p+k] = left[k];
	}
	for (int l = 0; l < right.size(); l++){
		(*numbers)[q+l+1] = right[l];
	}
}