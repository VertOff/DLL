#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

struct Node
{
    string word;
    string pages;


    Node* Next;
};


extern "C" __declspec(dllexport) struct Node* Init(string word, string pages)
{
    struct Node* elem;
    elem = (struct Node*)malloc(sizeof(struct Node));
    elem->word = word;
    elem->pages = pages;
    elem->Next = NULL;
    return elem;
}

extern "C" __declspec(dllexport) void AddNode(struct Node** first, struct Node* newelem)
{
    struct Node** temp, * p;
    temp = first;

    while ((*temp)->Next != NULL)
    {
        if ((*temp)->word[0] <= newelem->word[0])
        {
            temp = &((*temp)->Next);
        } 
    }
    //if ((*temp)->word <= newelem->word && (*temp)->Next == NULL)
    //{
    //    (*temp)->Next = newelem;
    //    return;
    //}
    //if ((*temp)->word >= newelem->word)
    //{
    //    p = (*temp);
    //    (*temp) = newelem;
    //    newelem->Next = p;
    //}
}

extern "C" __declspec(dllexport) void Show(struct Node** first, string word)
{
    struct Node** temp;
    temp = first;

   // while((*temp)->word == word && (*temp)->Next != NULL)
    //{
        cout << (*temp)->pages << endl;
        temp = &((*temp)->Next);
    //}
}