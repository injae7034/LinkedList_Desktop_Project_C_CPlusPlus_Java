#ifndef _VISITINGCARDBINDER_H
#define _VISITINGCARDBINDER_H

typedef signed long int Long;
typedef enum _boolean { FALSE = 0, TRUE = 1 }Boolean;

typedef struct _personal
{
	char name[11];
	char position[8];
	char cellularPhoneNumber[12];
	char emailAddress[32];
}Personal;

typedef struct _company
{
	char name[32];
	char address[64];
	char telephoneNumber[12];
	char faxNumber[12];
	char url[32];
}Company;

typedef struct _visitingCard VisitingCard;

typedef struct _visitingCard
{
	Personal personal;
	Company company;

	VisitingCard* next;
}VisitingCard;

typedef struct _visitingCardBinder
{
	VisitingCard* first;
	Long length;
	VisitingCard* current;
}VisitingCardBinder;

void Create(VisitingCardBinder* visitingCardBinder);
VisitingCard* TakeIn(VisitingCardBinder* visitingCardBinder, VisitingCard visitingCard);
void Find(VisitingCardBinder* visitingCardBinder, char(*name), VisitingCard** (*indexes), Long* count);
VisitingCard TakeOut(VisitingCardBinder* visitingCardBinder, VisitingCard* index);
VisitingCard* First(VisitingCardBinder* visitingCardBinder);
VisitingCard* Previous(VisitingCardBinder* visitingCardBinder);
VisitingCard* Next(VisitingCardBinder* visitingCardBinder);
VisitingCard* Last(VisitingCardBinder* visitingCardBinder);
void Arrange(VisitingCardBinder* visitingCardBinder);
void Destroy(VisitingCardBinder* visitingCardBinder);

#endif // !_VISITINGCARDBINDER_H


