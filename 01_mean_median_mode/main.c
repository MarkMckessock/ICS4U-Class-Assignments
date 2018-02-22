#include <stdio.h>
#include <stdlib.h>

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
  if (num_count % 2 == 0) //If there is an even # of ints, the median is halfway between the middle two values.
    return (nums[num_count/2]+nums[num_count/2-1])/(float)2; //The 2 is typecast as a float so that the answer is a float.
  else
    return nums[num_count/2];
}

int *get_mode(int nums[], int num_count){ //Returns pointer to an array of modes
  int count_nums[MAX_INT+1],max_count=0,mode_count=0,i,j,modes_index=0;
  static int modes[MAX_INT/2+2]; //Create array to hold mode values (extra element to hold null char)

  //Zero-fill the array
  for(i=0;i<=MAX_INT;i++)
    count_nums[i] = 0;

  //Determine how many of each number was entered
  for(i=0;i<num_count;i++)
    count_nums[nums[i]] += 1;

  //Find the maximum count
  for (i=0;i<=MAX_INT;i++){
    if (count_nums[i] > max_count){
      max_count = count_nums[i];
    }
  }

  //Determine if any value appears more than once. There is no mode if a number appears less than 2 times.
  if (max_count < 2){
    modes[0] = '\0';
    return NULL;
  }
  else{
    //Get number of modes
    for(i=0;i<=MAX_INT;i++){
      if (count_nums[i] == max_count)
        mode_count += 1;
      }
  }

  modes[mode_count] = '\0'; //Assign null to last element of modes array

  //Assign values to modes array
  for(i=0;i<=MAX_INT;i++){
    if (count_nums[i] == max_count){
      modes[modes_index] = i;
      modes_index ++;
    }
  }
  return modes; //Return pointer to modes array
}

int main(void){
  int A[MAX_NUMS];
  int nA,i,j;

  do {
    system("cls");
    printf("How many numbers do you want to enter? (Enter a value between %i and %i)\n",MIN_NUMS,MAX_NUMS);
    scanf("%i",&nA);
  }
  while (nA < MIN_NUMS || nA > MAX_NUMS); //Check that the user entered a valid value for nA.

  //Get values
  for (i=0;i<nA;i++){
    printf("Enter int # %i (Enter a number between %i and %i):\n",i+1,MIN_INT,MAX_INT);
    scanf("%i",&A[i]);
    if (A[i] < MIN_INT || A[i] > MAX_INT){ //Check that the user entered a valid value for each int.
      system("cls");
      i--;
    }
  }

  //Exit if no values are given
  if (nA < 1){
    system("cls");
    printf("There is no mean.\nThere is no median.\nThere is no mode.");
    return 0;
  }

  system("cls");

  //Output values
  for(i=0;i<nA;i++)
    printf("A[%i] = %i\n",i,A[i]);

  //Mean calculation
  printf("The mean is %.2f.\n",get_mean(A,nA));

  //Median calculation

  printf("The median value is %.2f.\n",get_median(A,nA));

  //Mode calculation
  int *mode_vals = get_mode(A,nA); //Stores pointer to modes array in mode_vals pointer
  if (mode_vals != NULL){
    printf("The following value(s) are the mode: ");
    i=0;
    while(*(mode_vals+i) != '\0'){ //Iterate through array of modes until null char is found (end of array)
      printf("%i ",*(mode_vals+i));
      i++;
    }
  }
  else //If get_mode returns NULL there is no mode.
    printf("There is no mode.");

  return 0;
}
