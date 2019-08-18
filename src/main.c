#include<stdio.h>
//#include<conio.h>
#include<string.h>                                                                 
#include<stdbool.h>
#include<data.h>                                                               

extern int no_of_notes_user[DENOMINATION_MAX];
extern item_list_e item[];

void init_data()
{
	// initialize no of notes of each currency
	init_no_of_notes();
}

void disp_purchased_items(int items[], int no_of_items)
{
	item_list_e *item_handle = NULL;
	int i = 0;

	printf("\nList of items you have purchased : \n\n");
	for(; i < no_of_items; i++)
	{
		item_handle = get_item_handle(items[i]);
		printf("%s\n", get_item_name(item_handle));
	}
}

void return_remaining_balance(int remaining_balance)
{
	int note = DENOMINATION_1000;
	int no_of_notes = 0;
	int no_of_return_notes = 0;

	printf("\nPlease take back your remaining balance.\n");
	for(; note > -1 ; note--)
	{
		no_of_notes = remaining_balance/map_enum_to_note(note);
		if(!no_of_notes)
			continue;

		no_of_return_notes = no_of_notes;
		no_of_notes -= no_of_notes_user[note];
		no_of_notes_user[note] = 0;

		if(no_of_notes)
			no_of_notes = return_notes_to_user(note, no_of_notes);

		remaining_balance -= ((no_of_return_notes - no_of_notes) * map_enum_to_note(note));

		printf("\nNo of notes = %d of denomination = %d\n", no_of_return_notes - no_of_notes, map_enum_to_note(note));
	}
}

void disp_items()
{
	int i = 0;
	printf("\n----------------------------------------------------------------\n");
	printf("\n Item Name  Item Code  Item Price Item quantity\n");
	for(; i < MAX_ITEMS; i++)
	{
		if(item[i].quantity)
			printf("\n %s  %d  %d  %d \n", item[i].name, item[i].code, item[i].price, item[i].quantity);
	}
	printf("\n----------------------------------------------------------------\n");
}

void disp_item_menu(int total, int temp_total)
{
	int user_items[50];
	int user_input = 0;
	int i = 0;
	item_list_e *item_handle = NULL;
	int remaining_balance = total;

	printf("\nStart entering the item code of the item you want to buy.\n");
	printf("\nPress 0 anytime in between to finish your purchase.\n");

	while(true)
	{
		disp_items();

		printf("\nEnter item code : ");
		if(scanf("%d",&user_input) != 1)
		{
			printf("\nERROR : Non numeric value encountered\n");
			fflush(stdin);
			continue;
		}
		else if(user_input >= ITEM_CODE_MAX)
		{
			printf("\nERROR : Wrong item code.\n");
			continue;
		}

		if(user_input == 0)
			break;

		item_handle = get_item_handle(user_input);
		if(!item_handle)
		{
			printf("\nERROR : Something went wrong..... Please try again\n");
			continue;
		}

		if(!check_item_availability(item_handle))
		{
			printf("\nERROR : Selected item is out of stock.\n");
			continue;
		}

		if(get_item_price(item_handle) > remaining_balance)
		{
			printf("\nERROR : Selected item price is more than the remaining balance. Please select other item within remaining balance\n");
			continue;
		}

		remaining_balance -= get_item_price(item_handle);
		user_items[i] = user_input;
		update_item_quantity(&item_handle);
		i++;

		printf("\nBalnce remaining is = %d\n", remaining_balance);
	}

	disp_purchased_items(user_items, i);
	printf("\nBalnce remaining after purchasing is = %d\n", remaining_balance);

	return_remaining_balance(remaining_balance);
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

	disp_item_menu(total,0);
                         /*
	int i = 0;
	for (i;i<MAX;i++)
	{
			printf("value of temp[%d] = %d\n",i,temp_db[i]);
	}
					   */
	getchar();
	return 0;
}
