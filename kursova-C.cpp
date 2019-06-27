#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>



struct pacient 
{ 
    char name[51];
	char egn[11];
	int age;
	char Dname[51];
	char diagnose[51];
}; 
typedef struct pacient  BODY; 

struct List 
{ 
    BODY body; 
    struct List *pNext; 
}; 
typedef struct List LIST; 

int enterBody(BODY *ps,LIST *pFirst); 
void printfBody(BODY s); 
LIST *insertBegin(LIST *pFirst, BODY newBody); 
void printByDoctor(LIST *pFirst, char x[]);
int endProgram(void);
void  printByAge(LIST *pFirst, int from,int to);
void removeList(LIST **pFirst);
LIST *delFirst(LIST *pFirst, BODY *delBody);
int update( char Fname[], char egn[],char diagnosa[], char Dname[],int age);
void delElement(LIST *pFirst,char egn[]);
int main() 
{ 
    LIST *pFirst=NULL, *p; 
    int res, i, mode, newgr, fn, grp, numtard; 
    BODY pacient; 
    LIST *tmp, *pAfter; 
    FILE *pOut=NULL, *pIn=NULL; 
    BODY newbody; 
    char Fname[]="Pacienti";
    system ("color 0A");
    char *menu[]={
    " ______________________________________________________________________________________________________________________ ",
	"|                                                         ____                                                         |",
	"|                                                        |    |                                                        |",
	"|                                                        |    |                                                        |",
	"|                                                   _____|    |_____                                                   |",
	"|                                                  |                |                                                  |",
	"|                                                  |_____      _____|                                                  |",
	"|                                                        |    |                                                        |",
	"|                                                        |    |                                                        |",
	"|                                                        |____|                                                        |",
	"|                                                                                                                      |",
	"|                                                                                                                      |",
	"|                                                                                                                      |",
	"|                                       Molia izberete jelanata ot vas funkcia                                         |",
	"|                                                                                                                      |",
	"|                 1-Dobaviane na pacient                                                                               |",
	"|                 2-Aktualizirane na dannite vuv fail.                                                                 |",
	"|                 3-Izvejdane na dannite za vsichki pacienti na izbran lekar.                                          |",
	"|                 4-Izvejdane na dannite za vsichki pacienti v izbran vuzrastov iinterval.                             |",
	"|                 5-Zapisvane na dannite vuv dvoichen fail.                                                            |",
	"|                 6-Izvlichane na dannite ot dvoichen fail.                                                            |",
    "|                 7-Izriazvane na element ot spisuka.                                                                  |",
	"|                                                                                                                      |",
	"|______________________________________________________________________________________________________________________|"
    }; 

    do{
	
       
        for(i=0; i<24; i++) 
        { 
            printf("%s\n", menu[i]); 
        } 
        do 
        { 
            fflush(stdin); 
            printf("\n\nIzberete rejim[1-7]: "); 
            res = scanf("%d", &mode); 
        } 
        while (res !=1); 
        switch(mode) 
        { 
        case 1: 
            for(i=0; i<1; i++) 
            { 
                res = enterBody(&pacient,pFirst); 
                if(res !=1) 
                { 
                    printf("Error in initialization %d \n", res); 
                    break; 
                } 
                p = insertBegin(pFirst, pacient); 
                if(p == NULL) 
                { 
                    printf("Not enough memory"); 
                    break; 
                } 
                pFirst = p; 
            } 
             
            break; 
      
 case 2:
       char name1[11];
       char name2[51];
       char name3[51];
       int  name4;
       char name5[11];
        { 
            if(pFirst!=NULL) 
                removeList(&pFirst); 
            do 
            { 
                fflush(stdin); 
                printf("\nEGN na tursenia pacient: "); 
                res=scanf("%s", name1); 
                if(res==EOF) 
                    break; 
            } while(res==0 || fn<0); 

        fflush(stdin); 
        printf("\nVuvedete novata diagnoza: "); 
        res=scanf("%s",name2); 
        if(res==EOF) break; 
        fflush(stdin); 
        printf("\nVuvedete novia lekuvasht lekar: "); 
        res=scanf("%s",name2); 
        if(res==EOF) break; 
        fflush(stdin); 
        printf("\nVuvedete novata vuzrast: "); 
        res=scanf("%s",&name4); 
        if(res==EOF) break; 
        fflush(stdin); 
        printf("\nVuvedete imeto na faila suhraniavash dannite a pacienta: "); 
        res=scanf("%s",name5); 
        if(res==EOF) break; 
        res=update(name5, name1, name2,name3,name4); 
        if(res==1) 
            printf("\nPacienta s egn %s beshe aktualiziran\n",name1); 
        else 
            printf("\nError while updating."); 
        } 
       
       
       
       break;
    
       case 3: 
       char doc[10];
 printf("Vuvedete imeto na  Doctora: \n"); 
            scanf("%s", &(pacient.Dname)); 
            printByDoctor(pFirst, doc); 
             break;
 
 case 4: 
 int number1;
 int number2;
 printf("Vuvedete dolnata vuzrastova granica: \n");
 scanf("%d", &number1); 
 printf("Vuvedete gornata vuzrastova granica: \n");
 scanf("%d", &number2); 
 printByAge(pFirst,number1,number2);
     
        break; 

case 5:

{ 
            pOut=fopen(Fname, "wb"); 
            if(pOut==NULL) 
            { 
                printf("Failut za zapis nemoje da bude otvoren."); 
                break; 
            } 

            for(p=pFirst; p!=NULL; p=p->pNext) 
            { 
                res=fwrite(&(p->body), sizeof(BODY), 1, pOut); 
                if(res!=1) 
                { 
                    printf("Writing error \n"); 
                    break; 
                } 
            } 
            fclose(pOut); 
        }
break;

case 6:
 {
if(pFirst!=NULL)
removeList(&pFirst);
printf("Enter file name for reading: \n");
do
{
res = scanf("%20s", Fname);
}
while(res!=1);
pIn=fopen(Fname, "rb");
if(pIn==NULL)
{
printf("Can't open file for reading.");
getchar();
break;
}
do
{
res=fread(&newbody, sizeof(BODY), 1, pIn);
if(res!=1 && !feof(pIn))
{
printf("Reading error \n");
getchar();
break;
}
else
{
p=insertBegin(pFirst, newbody);
if(p==NULL)
{
printf("Not enough memory");
getchar();
break;
}
pFirst=p;
}
} while(res==1);
pFirst = delFirst(pFirst, &pacient);
fclose(pIn);
}
getchar();

        break;
       
      
       
       case 7:
       char egn[11];
       printf("Vuvedete EGN na pacientut chiato informacia iskate da iztriete");
       scanf("%s",egn);
       delElement(pFirst,egn);
       break;
        default: 
            printf("\nBad choice!\n"); 
            
        } 
    
}
while(endProgram());
    
    return 0; 
} 




int enterBody(BODY *ps,LIST *pFirst) 
{ 
char egn1[11];
char ime[51];
char Dime[51];
char diagnoza[51];
LIST *p;
    if(ps == NULL) return 0; 
    memset(ps, 0, sizeof(BODY)); 

   
    fflush(stdin); 
    printf("\nVuvedete imeto na pacienta samo s glavni bukvi: "); 
    scanf("%s", ime); 
    for(int i=0;ime[i]!='\0';i++){
    	if(!isupper(ime[i])){
    		printf("Vuveli ste imeto nepravilno molia opitaite otnovo");
		scanf("%s", ime); 
	}
	}
	strcpy(ps->name,ime);
    fflush(stdin); 
    printf("\nVuvedetet EGN: "); 
    scanf("%s", egn1); 
     p = pFirst; 
        while(p != NULL) 
        { 
            if(!(strcmp(p->body.egn,egn1))) 
            { 
               printf("\nIma dublirane na EGN molia proverete korektnosta i opitaite pak: "); 
               printf("\nEGN: "); 
               scanf("%s", egn1);
            } 
            p=p->pNext; 
        } 
        strcpy(ps->egn,egn1);
    fflush(stdin); 
    printf("\nVuvedete vuzrast: "); 
    scanf("%d", &(ps->age)); 
    fflush(stdin); 
    printf("\nVuvedete imeto na lekuvashtia lekar: "); 
    scanf("%s", Dime); 
    for(int i=0;Dime[i]!='\0';i++){
    	if(!isupper(Dime[i])){
    		printf("Vuveli ste imeto nepravilno molia opitaite otnovo");
		scanf("%s", Dime); 
	}
	}
	strcpy(ps->Dname,Dime);
    fflush(stdin); 
    printf("\nVuvedete diagnozata: "); 
    scanf("%s", diagnoza); 
    for(int i=0;diagnoza[i]!='\0';i++){
    	if(!isupper(diagnoza[i])){
    		printf("Vuveli ste imeto na diagnozata nepravilno molia opitaite otnovo");
		scanf("%s", diagnoza); 
	}
	}
	strcpy(ps->diagnose,diagnoza);
    fflush(stdin); 
    return 1; 
    
} 

void printBody(BODY s) 
{ 
    printf("name:%s, egn:%s, age:%d, Dname:%s, diagnosa:%s\n",s.name,s.egn,s.age,s.Dname,s.diagnose);
} 






LIST *insertBegin(LIST *pFirst, BODY newBody) 
{ 
    LIST *p; 
    p = (LIST *)malloc(sizeof(LIST)); 
    if(p == NULL) 
    { 
        printf("Not enough memory\n"); 
        return NULL; 
    } 
    else 
    { 
        p->body = newBody; 
        p->pNext = pFirst; 
        pFirst = p; 
        return p; 
    } 
} 


void  printByDoctor(LIST *pFirst, char x[]) 
{ 

    LIST *p; 
    int flag = 0; 
    if(pFirst == NULL) printf("Empty list.\n"); 
    else 
    { 
        p = pFirst; 
        while(p != NULL) 
        { 
            if(strcmp(p->body.Dname,x)) 
            { 
                printBody(p->body); 
                flag++; 
            } 
            p=p->pNext; 
        } 
        if(!flag) 
            printf("\n Ne e nameren pacient s tozi lekuvasht lekar\n"); 
    } 
}


int endProgram(void){
	int choice;
	printf(" Iskate li da restartirate programata i da zapochnete otnachalo(1) ili da sprete programata(2) ");
    scanf("%d",&choice);
    switch(choice){
	case(1): system("cls");
    return 1;
	break;
	case(2):system("taskkill /F /IM ConsolePauser.exe");
	system("taskkill /F /IM Kursova2.exe");
	break;
	default:
	system("cls");
	printf("Vuveli ste nevaliden izbor");
	fflush(stdin);
	endProgram();
}
}
	
void  printByAge(LIST *pFirst, int from,int to) 
{ 

    LIST *p; 
    int flag = 0; 
    if(pFirst == NULL) printf("Empty list.\n"); 
    else 
    { 
        p = pFirst; 
        while(p != NULL) 
        { 
            if(p->body.age>=from&&p->body.age<=to) 
            { 
                printBody(p->body); 
                flag++; 
            } 
            p=p->pNext; 
        } 
        if(!flag) 
            printf("\n Ne e nameren pacient v tozi vuzrastov interval\n"); 
    } 
}

void removeList(LIST **pFirst) 
{ 
    BODY first; 
    while(*pFirst != NULL) 
        *pFirst = delFirst(*pFirst, &first); 
} 

LIST *delFirst(LIST *pFirst, BODY *delBody) 
{ 
    if(pFirst == NULL) 
    { 
        printf("Empty list!\n"); 
        return NULL; 
    } 
    else 
    { 
        LIST *p; 
        *delBody = pFirst->body; 
        p = pFirst->pNext; 
        if(p != NULL) 
            free(pFirst); 
        pFirst = p; 
        return pFirst; 
    } 
} 






int update( char Fname[], char egn[],char diagnosa[], char Dname[],int age) 
{ 
FILE *fp;
    BODY s; 
    int res; 
    if(Fname==NULL) return -1; 
    

    fp=fopen(Fname, "r+b"); 
    if(fp==NULL) 
    { 
        printf("Can't open file for reading"); 
        return 0; 
    } 

    while(1) 
    { 
        res=fread(&s, sizeof(BODY), 1, fp); 
        if(feof(fp)) break; 
        if(res!=1 && res!=feof(fp)) 
        { 
            printf("Error in reading %d\n", res); 
            return -4; 
        } 
        
        if(!(strcmp(s.egn,egn)))
        { 
        
            res=fseek(fp, ftell(fp)-sizeof(BODY), SEEK_SET); 
            if(res!=0) 
            { 
                printf("Error in position %d\n", res); 
                return -5; 
            } 
           strcpy(s.diagnose,diagnosa); 
           strcpy (s.Dname,Dname);
           s.age=age; 
            
            
            res=fwrite(&s, sizeof(BODY), 1, fp); 
            if(res!=1) 
            { 
                printf("Error in writing %d\n", res); 
                return -6; 
            } 
            fclose(fp); 
            return 1; 
        } 
    } 
    fclose(fp); 
    printf("Nemoje da bude nameren pacient s egn %s\n", egn); 
    return -4; 
} 

void delElement(LIST *pFirst,char egn[]){
	
int flag=0;
   // If linked list is empty
   if (pFirst == NULL)
      return ;
 
   // Store head node
  LIST *temp = pFirst;
  LIST *previos=NULL;
    // If head needs to be removed
    if (!(strcmp(temp->body.egn,egn)))
    {
        temp = temp->pNext;   // Change head
        free(temp);               // free old head
        return ;
    }

 
    // Find previous node of the node to be deleted
    while(temp != NULL&&strcmp(temp->body.egn,egn )) {
    	if(!(strcmp(temp->body.egn,egn ))){
    		flag=1;
		}
    	previos=temp;
    	 temp = temp->pNext; 
	}
 
   if(flag!=1){
   	printf("niama nameren chovek s tova egn!!!\n");
   	return;
   }
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    LIST *next = previos->pNext->pNext;
 
    // Unlink the node from linked list
    free(previos->pNext);  // Free memory
 
    previos->pNext = next;  // Unlink the deleted node from list

	
}



