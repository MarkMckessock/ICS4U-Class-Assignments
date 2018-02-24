#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define MIN_NUMS 0
#define MAX_NUMS 100
#define MIN_INT 10
#define MAX_INT 50

float get_mean (int nums[],int num_count){
  int sum = 0,i;
  for (i=0;i<num_count;i++)
    sum += nums[i];
  return sum/(float)num_count;
}

void sort_array(int nums[],int num_count){
  int i,j,temp;
  for (j=1;j<=num_count;j++){
    //for (i=0;i<num_count-1;i++){
    for (i=0;i<num_count-j;i++){
      if (nums[i] > nums[i+1]){
        temp = nums[i];
        nums[i] = nums[i+1];
        nums[i+1] = temp;
      }
    }
  }
}

float get_median(int nums[], int num_count){
  sort_array(nums,num_count);
  return num_count % 2 == 0 ? (nums[num_count/2]+nums[num_count/2-1])/(float)2 : nums[num_count/2];
}

std::vector<int> get_mode(int nums[], int num_count){ //Returns pointer to an array of modes
  int max_count=0,i,j;
  std::array<int,MAX_INT+1> count_nums;
  std::vector<int> modes;

  //Zero-fill the array
  count_nums.fill(0);

  //Determine how many of each number was entered
  for(i=0;i<num_count;i++)
    count_nums[nums[i]] += 1;

  //Find the maximum count
  max_count = *std::max_element(count_nums.begin(),count_nums.end());

  //Determine if any value appears more than once. There is no mode if a number appears less than 2 times.
  if (max_count < 2)
    return modes;

  //Assign values to modes array
  for(i=0;i<=MAX_INT;i++)
    if (count_nums[i] == max_count)
      modes.push_back(i);

  return modes; //Return modes vector
}

int main(void){
  int A[MAX_NUMS];
  int nA,i,j;

  do {
    system("cls");
    std::cout << "How many numbers do you want to enter? (Enter a value between " << MIN_NUMS << " and " << MAX_NUMS << ")" <<  std::endl;
    std::cin >> nA;
  }
  while (nA < MIN_NUMS || nA > MAX_NUMS); //Check that the user entered a valid value for nA.

  //Get values
  for (i=0;i<nA;i++){
    std::cout << "Enter int # " << i+1 <<  " (Enter a number between " << MIN_INT << " and " << MAX_INT << "):" << std::endl;
    std::cin >> A[i];
    if (A[i] < MIN_INT || A[i] > MAX_INT){ //Check that the user entered a valid value for each int.
      system("cls");
      i--;
    }
  }

  //Exit if no values are given
  if (nA < 1){
    system("cls");
    std::cout << "There is no mean." << std::endl << "There is no median." << std::endl << "There is no mode." << std::endl;
    return 0;
  }

  system("cls");

  //Output values
  for(i=0;i<nA;i++)
    std::cout << "A[" << i << "] = " << A[i] << std::endl;

  //Mean calculation
  std::cout << "The mean is " << std::fixed << std::setprecision(2) << get_mean(A,nA) << "." << std::endl;

  //Median calculation
  std::cout << "The median value is " << std::fixed << std::setprecision(2) << get_median(A,nA) << "." << std::endl;

  //Mode calculation
  std::vector<int> mode_vals = get_mode(A,nA); //Stores modes vector in mode_vals.
  if (mode_vals.size()){ //Check if mode_vals is empty.
    std::cout << (mode_vals.size() > 1 ? "The following values are modes: " : "The mode is: ");
    for(i=0;i<mode_vals.size();i++)
      std::cout << mode_vals[i] << " ";
  }
  else
    std::cout << "There is no mode.";

  return 0;
}
