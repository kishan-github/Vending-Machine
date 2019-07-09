#include<data.h>

// Array to store no of notes of each denomination
int no_of_notes[DENOMINATION_MAX];

// Array to store no of notes of each denomination entered by user
int no_of_notes_user[DENOMINATION_MAX];

// Basic items available
item_list_e item[] =
{
	{ .name = "Item1" , .code = ITEM_CODE_1 , .price = 10 , .quantity = 2 },
	{ .name = "Item2" , .code = ITEM_CODE_2 , .price = 20 , .quantity = 3 },
	{ .name = "Item3" , .code = ITEM_CODE_3 , .price = 30 , .quantity = 4 },
	{ .name = "Item4" , .code = ITEM_CODE_4 , .price = 70 , .quantity = 2 },
	{ .name = "Item5" , .code = ITEM_CODE_5 , .price = 150 , .quantity = 7 },
	{ .name = "Item6" , .code = ITEM_CODE_6 , .price = 200 , .quantity = 1 }
};

// initialize no of notes of each type
void init_no_of_notes()
{
	int index = 0;
	
	for(; index < DENOMINATION_MAX; index++)
		no_of_notes[index] = INITIAL_NOTES;
}

// get no of notes for specified note type
int get_no_of_notes(note_type_e note)
{
	return no_of_notes[note];
}

// set no of notes for specified note type
void set_no_of_notes(note_type_e note)
{
	no_of_notes[note]++;
}

// check the validity of the currency note
bool is_valid_note_type(note_type_e note)
{
	switch(note)
	{
		case DENOMINATION_10:
		case DENOMINATION_20:
		case DENOMINATION_50:
		case DENOMINATION_100:
		case DENOMINATION_500:
		case DENOMINATION_1000:
			 return true;
		default :
			return false;
	}
}

note_type_e map_user_input_to_enum(int currency)
{
	switch(currency)
	{
		case 10 : return DENOMINATION_10;
		case 20 : return DENOMINATION_20;
		case 50 : return DENOMINATION_50;
		case 100 : return DENOMINATION_100;
		case 500 : return DENOMINATION_500;
		case 1000 : return DENOMINATION_1000;
		default : return DENOMINATION_MAX;
	}
}

item_list_e* get_item_handle(item_code_e code)
{
	int i = 0;

	for(; i < MAX_ITEMS; i++)
	{
		if(item[i].code == code)
		{
			return &item[i];
		}
	}
	return NULL;
}

bool check_item_availability(item_list_e *item)
{
	if(item->quantity > 0)
		return true;
	else
		return false;
}

int get_item_price(item_list_e *item)
{
	return item->price;
}

void update_item_quantity(item_list_e **item)
{
	((*item)->quantity)--;
}