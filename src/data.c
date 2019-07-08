#include <data.h>

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