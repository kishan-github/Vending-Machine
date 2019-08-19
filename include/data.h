#include<stdbool.h>

#define INITIAL_NOTES 10
#define MAX_ITEMS 6
#define FAILURE 0

// enum to store the type of notes available
typedef enum note_type
{
	DENOMINATION_10,
	DENOMINATION_20,
	DENOMINATION_50,
	DENOMINATION_100,
	DENOMINATION_500,
	DENOMINATION_1000,
	DENOMINATION_MAX
}note_type_e;

// enum to store the item code
typedef enum item_code
{
	ITEM_CODE_1 = 1,
	ITEM_CODE_2,
	ITEM_CODE_3,
	ITEM_CODE_4,
	ITEM_CODE_5,
	ITEM_CODE_6,
	ITEM_CODE_MAX
}item_code_e;

// Structure to store items
typedef struct item_list
{
	char name[10];
	int code;
	int price;
	int quantity;
}item_list_e;

// function declaration
void init_no_of_notes();
int get_no_of_notes(note_type_e note);
void set_no_of_notes(note_type_e note);
int return_notes_to_user(note_type_e note, int no_of_note);
bool is_valid_note_type(note_type_e note);
int map_enum_to_note(note_type_e note);
note_type_e map_user_input_to_enum(int currency);
item_list_e* get_item_handle(item_code_e code);
bool check_item_availability(item_list_e *item);
int get_item_price(item_list_e *item);
void update_item_quantity(item_list_e **item);
char* get_item_name(item_list_e *item);
