#include <stdio.h>
#include <stdlib.h>

void print_table(float tax_rate, float *price_1, float *price_8){
  float sum = 0,*current_item;
  system("cls");
  printf("Purchase Order:\n======================\nCost\t\tFinal Cost\n");
  for (current_item=price_1;current_item>=(price_8);current_item-=1){
    printf("$%.2f\t\t$%.2f\n",*current_item,*current_item*(tax_rate/100+1));
    sum += *current_item;
  }
  printf("The average cost was $%f\n",sum/8);
  system("pause");
}

int main(void){
  float price_1,price_2,price_3,price_4,price_5,price_6,price_7,price_8,tax_rate,temp,*current_item,*next_item;
  int j;
  //float *p_price_1=&price_1,*p_price_2=&price_2,*p_price_3=&price_3,*p_price_4=&price_4,*p_price_5=&price_5,*p_price_6=&price_6,*p_price_7=&price_7,*p_price_8=&price_8;

  //Get 8 prices
  for (current_item=&price_1;current_item>=(&price_8);current_item-=1){
    printf("Enter the price for the item:\n");
    scanf("%f",current_item);
    system("cls");
  }

  //Get tax rate
  printf("Enter the tax rate: %%");
  scanf("%f",&tax_rate);

  print_table(tax_rate,&price_1,&price_8);

  //Sort prices
  for (j=0;j<8;j++){
    for (current_item=&price_1;current_item>=(&price_8)+j;current_item-=1){
      if (*current_item > *(current_item-1)){
        temp = *(current_item-1);
        next_item = current_item-1;
        *next_item = *current_item;
        *current_item = temp;
      }
    }
  }
  print_table(tax_rate,&price_1,&price_8);
}
