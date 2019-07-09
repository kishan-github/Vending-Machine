#include<stdio.h>
#include<conio.h>
#include<string.h>                                                                 
#include<stdbool.h>
#include<data.h>                                                               

extern int no_of_notes[DENOMINATION_MAX];
extern int no_of_notes_user[DENOMINATION_MAX];

void init_data()
{
	// initialize no of notes of each currency
	init_no_of_notes();
}

void disp_item_menu(int total, int temp_total)
{
	printf("\n\n*#*#*#*#*WELCOME#*#*#*#*#*\n\n");

	if(temp_total<total)
	{
		printf("You have Rs. %d left, please select accordingly :-)\nChoose from below options!!!\n\n1. Item @Rs.10\n2. Item @Rs.20\n3. Item @Rs.30\n4. Item @Rs.40",temp_total);
		temp_total = temp_total + 10;
	}
}

int display_curr_menu()
{                                                                                  
	int user_input = 0;
	note_type_e input_note = DENOMINATION_MAX;
	int total_amount = 0;

	printf("\nStart entering notes in denomination of :\n");
	printf("\n Rs 10 \n Rs 20 \n Rs 50 \n Rs 100 \n Rs 500 \n Rs 1000 \n");
	printf("\nYou can stop anytime by entering '0'\n");

	while(true)
	{
		printf("\nEnter currency notes : ");
		if(scanf("%d",&user_input) != 1)
		{
			printf("\nERROR : Non numeric value encountered\n");
			fflush(stdin);
			continue;
		}

		if(user_input == 0)
			break;
		
		input_note = map_user_input_to_enum(user_input);

		if(input_note == DENOMINATION_MAX)
		{
			printf("\nERROR : Denomination type is note correct\n");
		}
		else
		{
			total_amount += user_input;
			no_of_notes_user[input_note]++;
			printf("\nAmount Entered = %d . Total Amount = %d\n", user_input, total_amount);
		}

	}

	printf("\n\n\nTotal amount entered by you = %d\n", total_amount);
	return total_amount;
}                                                                               
int main()                                                                      
{
	printf("\n **************************************************** \n");
	printf("\n *                                                  * \n");
	printf("\n *        Welcome to the vending mechine            * \n");
	printf("\n *                                                  * \n");
	printf("\n **************************************************** \n");
	
	// initialize all the data first
	init_data();
	
	int total;
	total = display_curr_menu();
	printf("\nexit code = %d",total);

	//disp_item_menu(total,0);
                         /*
	int i = 0;
	for (i;i<MAX;i++)
	{
			printf("value of temp[%d] = %d\n",i,temp_db[i]);
	}
					   */
	getch();
	return 0;
}
