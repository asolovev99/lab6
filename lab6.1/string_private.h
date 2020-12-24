#pragma once

typedef struct CustomString CustomString;

CustomString* create(char* raw);

int get_length(CustomString* string);

int compare(struct CustomString* string, struct CustomString* right);

CustomString* concat(CustomString* left, CustomString* right);

int index_of(CustomString* target, CustomString* substring);


//void print_CustomString(CustomString* string);