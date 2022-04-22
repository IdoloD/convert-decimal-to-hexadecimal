#include <stdio.h>
#include <stdlib.h>
//IdoloD github
#define DEBUG 1
//IdoloD github
struct hex_struct {
char* nums;
int top;
int size;
};
//https://github.com/IdoloD/convert-decimal-to-hexadecimal
void reverse(char* nums, int top) {
int i;
for(i=0; i < top/2; i++) {
char swap_var = nums[i];
nums[i] = nums[(top-1)-i];
nums[(top-1)-i] = swap_var;
}
//https://github.com/IdoloD/convert-decimal-to-hexadecimal
}
//IdoloD github
int main () {
int dec_num;
struct hex_struct hex_num;
//IdoloD github
hex_num.top = 0;
hex_num.size = 4;
hex_num.nums = (char*)malloc(hex_num.size*sizeof(char));
//IdoloD github
//https://github.com/IdoloD/convert-decimal-to-hexadecimal
//IdoloD github
do {
printf("Enter a decimal positive number: ");//IdoloD github
scanf("%d", &dec_num);
fflush(stdin);
} while (dec_num < 0);
printf("\n\n");
//IdoloD github
while (dec_num > 0) {
//IdoloD github
if(hex_num.top == hex_num.size) {
hex_num.size *= 2;
//IdoloD github
hex_num.nums = (char*)realloc(hex_num.nums, hex_num.size*sizeof(char));
if(DEBUG)
//IdoloD github
printf("[debug] Reallocated memory from %d byte to %d byte\n", hex_num.size/2, hex_num.size);
}
//IdoloD github
int quoz = dec_num % 16;
dec_num /= 16;
//https://github.com/IdoloD/convert-decimal-to-hexadecimal
char char_quoz;
if (quoz < 10)
//IdoloD github
char_quoz = (char)(48+quoz);
else if(quoz >= 10)
char_quoz = (char)(55+quoz);
//https://github.com/IdoloD/convert-decimal-to-hexadecimal
hex_num.nums[hex_num.top] = char_quoz;
hex_num.top++;
//IdoloD github
}
hex_num.nums[hex_num.top] = '\0';
//https://github.com/IdoloD/convert-decimal-to-hexadecimal
reverse(hex_num.nums, hex_num.top);
printf("the number in hexadecimal is: %s\n", hex_num.nums);
//IdoloD github
printf("Press a button to continue...");
getchar();
return 0;
}
//https://github.com/IdoloD/convert-decimal-to-hexadecimal
