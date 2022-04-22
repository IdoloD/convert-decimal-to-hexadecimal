#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

struct hex_struct {
char* nums;
int top;
int size;
};

void reverse(char* nums, int top) {
int i;
for(i=0; i < top/2; i++) {
char swap_var = nums[i];
nums[i] = nums[(top-1)-i];
nums[(top-1)-i] = swap_var;
}

}

int main () {
int dec_num;
struct hex_struct hex_num;

hex_num.top = 0;
hex_num.size = 4;
hex_num.nums = (char*)malloc(hex_num.size*sizeof(char));


do {
printf("Enter a decimal positive number: ");
scanf("%d", &dec_num);
fflush(stdin);
} while (dec_num < 0);
printf("\n\n");

while (dec_num > 0) {

if(hex_num.top == hex_num.size) {
hex_num.size *= 2;
hex_num.nums = (char*)realloc(hex_num.nums, hex_num.size*sizeof(char));
if(DEBUG)
printf("[debug] Reallocated memory from %d byte to %d byte\n", hex_num.size/2, hex_num.size);
}

int quoz = dec_num % 16;
dec_num /= 16;

char char_quoz;
if (quoz < 10)
char_quoz = (char)(48+quoz);
else if(quoz >= 10)
char_quoz = (char)(55+quoz);

hex_num.nums[hex_num.top] = char_quoz;
hex_num.top++;
}
hex_num.nums[hex_num.top] = '\0';

reverse(hex_num.nums, hex_num.top);
printf("the number in hexadecimal is: %s\n", hex_num.nums);

printf("Press a button to continue...");
getchar();
return 0;
}
