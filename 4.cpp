#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <Windows.h>

using namespace std;

struct Node
{
    string word;
    string pages;


    Node* Next;
};

typedef struct Node* (*LibraryFunction1)(string ptr, string pages);
typedef void(*LibraryFunction2)(struct Node**, struct Node*);
typedef void(*LibraryFunction3)(struct Node**, string);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    char text[] = "LIST.dll";
    wchar_t wtext[20];
    mbstowcs(wtext, text, strlen(text) + 1);
    LPWSTR ptr = wtext;
    HINSTANCE hLib;
    hLib = LoadLibrary(ptr);

    if (hLib == NULL)
    {
        printf("?? ??????? ????????? ?????????? %s!\n", text);
        return 1;
    }

    LibraryFunction1 Init;
    LibraryFunction2 AddNode;
    LibraryFunction3 Show;

    Init = (LibraryFunction1)GetProcAddress(hLib, "Init");
    AddNode = (LibraryFunction2)GetProcAddress(hLib, "AddNode");
    Show = (LibraryFunction3)GetProcAddress(hLib, "Show");

    if(Init == NULL || AddNode == NULL || Show == NULL)
        printf("?? ??????? ????????? ??????? ?? ??????????!\n");
    

    struct Node* first = Init("word", "1, 2, 3, 45, 12, 56");
    AddNode(&first, Init("war", "1, 2, 3, 4, 5"));
    AddNode(&first, Init("arr", "1, 2, 3, 4, 5"));
    Show(&first, "war");


    FreeLibrary(hLib);
    return 0;
}