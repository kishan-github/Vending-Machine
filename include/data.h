#include<stdbool.h>

#define INITIAL_NOTES 10

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

// function declaration
void init_no_of_notes();
int get_no_of_notes(note_type_e note);
void set_no_of_notes(note_type_e note);
bool is_valid_note_type(note_type_e note);
note_type_e map_user_input_to_enum(int currency);