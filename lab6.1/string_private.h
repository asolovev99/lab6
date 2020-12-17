#pragma once

typedef struct CustomString CustomString;

CustomString* create(char* raw);

int get_length(CustomString* string);

int compare(struct CustomString* string, struct CustomString* right);

CustomString* concat(CustomString* left, CustomString* right);

int index_of(CustomString* target, CustomString* substring);


void print_CustomString(CustomString* string);
//static struct CustomString
//{
//	char* string;
//} CustomString;
//
//struct CustomString* create(char* raw)
//{
//	struct CustomString* result = malloc(sizeof(CustomString));
//	int length_of_result = 0;
//
//	if (raw == NULL)
//	{
//		result->string = (char*)malloc(sizeof(char));
//		*(result->string) = '\0';
//	}
//	else
//	{
//		for (int i = 0; raw[i] != '\0'; i++)
//		{
//			result->string = (char*)realloc(result->string, sizeof(char) * (length_of_result + 2));
//			result->string[length_of_result] = raw[i];
//			result->string[length_of_result + 1] = '\0';
//
//		}
//	}
//	
//	return result;
//}
//
//int get_length(struct CustomString* string)
//{
//	int result = 0;
//
//	if (string->string == NULL)
//	{
//		return 0;
//	}
//
//	while (string->string[result] != '\0')
//	{
//		result++;
//	}
//
//	return result;
//}
//
//int compare(struct CustomString* string, struct CustomString* right)
//{
//	int i = 0;
//
//	if ((string->string == NULL) && (right->string == NULL))
//	{
//		return 0;
//	}
//	else if (string->string == NULL)
//	{
//		return '\0' - right->string[0];
//	}
//	else if (right->string == NULL)
//	{
//		return string->string[i] - '\0';
//	}
//	else
//	{
//		while ((string->string[i] == right->string[i]) && (string->string[i] != '\0') && (right->string[i] != '\0'))
//		{
//			i++;
//		}
//
//		return string->string[i] - right->string[i];
//	}
//}
//
//struct CustomString* concat(struct CustomString* left, struct CustomString* right)
//{
//	int lenght_of_left = get_length(left);
//	int lenght_of_right = get_length(right);
//	struct CustomString* result = malloc(sizeof(CustomString));
//	result->string = (char*)malloc(sizeof(char) * (lenght_of_left + lenght_of_right + 1));
//
//	for (int i = 0; i < lenght_of_left; i++)
//	{
//		result->string[i] = left->string[i];
//	}
//
//	for (int i = lenght_of_left; i < lenght_of_left + lenght_of_right; i++)
//	{
//		result->string[i] = right->string[i - lenght_of_left];
//	}
//
//	result->string[lenght_of_left + lenght_of_right] = '\0';
//
//	return result;
//}
//
//int index_of(struct CustomString* target, struct CustomString* substring)
//{
//	int lenght_target = get_length(target);
//	int lenght_string = get_length(substring);
//	int is_find = 0;
//	int i = 0;
//	int j = 0;
//
//	if (substring->string == NULL)
//	{
//		//printf("");// NULL - пустая строка
//		return 0;
//	}
//	else
//	{
//		i = 0;
//		while (i + lenght_string <= lenght_target)
//		{
//			is_find = 1;
//			for (j = i; (j < i + lenght_string) && is_find; j++)
//			{
//				if (target->string[j] != substring->string[j - i])
//				{
//					is_find = 0;
//				}
//			}
//			if (is_find) // Нашли
//			{
//				return i;
//			}
//
//			i++;
//		}
//
//		return -1; // Не нашли
//	}
//}