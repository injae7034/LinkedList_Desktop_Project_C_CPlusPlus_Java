#ifndef _WORDCARDBINDER_H
#define _WORDCARDBINDER_H

typedef signed long int Long;
typedef enum _boolean { _FALSE = 0, _TRUE = 1 }Boolean;
typedef struct _word
{
	char spellings[64];
	char partOfSpeech[8];
	char meanings[32];
	char example[128];
}Word;
typedef struct _wordCard WordCard;
typedef struct _wordCard
{
	Word word;
	WordCard* next;
}WordCard;
typedef struct _wordCardBinder
{
	WordCard* first;
	Long length;
	WordCard* current;
}WordCardBinder;

void Create(WordCardBinder* wordCardBinder);
Long Load(WordCardBinder* wordCardBinder);
WordCard* TakeIn(WordCardBinder* wordCardBinder, WordCard wordCard);
void FindBySpellings(WordCardBinder* wordCardBinder, char(*spellings), WordCard** (*indexes), Long* count);
void FindByMeanings(WordCardBinder* wordCardBinder, char(*meanings), WordCard** (*indexes), Long* count);
WordCard TakeOut(WordCardBinder* wordCardBinder, WordCard* index);
void Arrange(WordCardBinder* wordCardBinder);
WordCard* First(WordCardBinder* wordCardBinder);
WordCard* Previous(WordCardBinder* wordCardBinder);
WordCard* Next(WordCardBinder* wordCardBinder);
WordCard* Last(WordCardBinder* wordCardBinder);
Long Save(WordCardBinder* wordCardBinder);
void Destroy(WordCardBinder* wordCardBinder);

#endif // !_WORDCARDBINDER_H

