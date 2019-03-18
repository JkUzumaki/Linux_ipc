#include<stdio.h>
void add();
void sub();
void mul();
void div();
int main()
{
	int flag = 1;
	int choice = 0;
	while(flag == 1){
		printf("Enter the operation that you want to perform\n");
		printf("1. Addition\n2. Subract\n3. Multiply\n4. Division\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				add();
				break;
			case 2:
				sub();
				break;
			case 3:
				mul();
				break;
			case 4:
				div();
				break;
			case 5:
				flag = 0;
				printf("Operation erminated\n");
			default:
				printf("Invalid choice\n");
		}	
	}
	return 0;
}
