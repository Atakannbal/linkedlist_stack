#include <stdio.h>
#include <stdlib.h>
#define bool int

/*

Linked list ve Stack kullanarak
{[( }]) parantezleri ile yazýlmýþ bir Matematiksel ifadenin parantezlerinin doðruluðunu kontrol eden program

*/

typedef struct node
{
char data;
struct node *next;
}node;

node * head = NULL;

void push(int veri)
{
    node * yeniNode = malloc(sizeof(node));
    yeniNode->data = veri;

    if(head == NULL) // STACK BOS ISE
    {
        head = yeniNode;
        head->next = NULL;
        return;
    }

    yeniNode->next = head;
    head = yeniNode;
}

int pop()
{
    char ref = head->data;  // bunu parantezKapandiMi'da kullanmak için return edicez

    int *silinecek = head;

    if(head==NULL) // STACK BOS ISE
    {
        printf("STACK BOS POP EDILECEK BIR SEY YOK");
        return;
    }

    head = head->next;
    free(silinecek);

    return ref;
}


bool parantezKapandiMi(char karakter1, char karakter2)
{
   if (karakter1 == '(' && karakter2 == ')')
     return 1;
   else if (karakter1 == '{' && karakter2 == '}')
     return 1;
   else if (karakter1 == '[' && karakter2 == ']')
     return 1;
   else
     return 0;
}

bool parantezlerDengeliMi(char exp[])
{
 int i = 0;
    while(exp[i])
    {
        if(exp[i] == '{' || exp[i]== '(' || exp[i]=='[')
        push(exp[i]);

        if(exp[i] == '}' || exp[i] == ')' || exp[i]==']')
        {
            if(head == NULL)
            return 0;

            else if(!parantezKapandiMi(pop(),exp[i]))
            return 0;
        }
        i++;
    }

if (head==NULL)
   return 1;
else
   return 0;
}


void yazdir()
{
    node *trav = head;
    if (trav==NULL)
    {
        printf("STACK BOS");
        return;
    }

    while(trav != NULL)
    {
        printf("----->%d", trav->data);
        trav = trav->next;
    }
}

bool kontrolEt(char dizi[])
{
    if (parantezlerDengeliMi(dizi))
        printf("Gecerli \n");
    else
        printf("Gecerli degil\n");
};

int main()
{
    char dizi[100] = "{(2+3)*9}";
    kontrolEt(dizi);

    return 0;
}
