#ifndef linkedList_Control
#define linkedList_Control
#endif
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "STDTypesAnd_defs.h" 
   
    /*
        * liked list and all functions declarations 
    */

 u16 count=0;     
 u32 resrves[5]={0};     //!    Used in reserves solts..
 u32 resrves_index[5]={0};  //! comtainer to hold solts time and numbers ..             
typedef struct {
    u8 name [100];
    u8 age;
    u8 gender[10];
    s32 id;
    struct node* next;
}node;
typedef node* link;
link current =NULL;
link tail=NULL;
link head=NULL;
link ptrSearch=NULL;


                    //! **************************************** Functions Declarations ***************************************** 
void insert (){
    static u8 no_in_first=0;
    s32 id_test;
    printf("Add new patient!\n");
    printf("enter id\n");
    scanf("%d",&id_test);
    if(no_in_first++)
    if(search(id_test) >= 0){
        printf("user already added\n");
        return;
    }    
    link add=(link)malloc(sizeof(node));
    assert(add);
    printf("enter patient name , age , gender \n");
    getchar();
    scanf("%[^\n]",&(add->name));
    scanf("%d",&(add->age));
    do{                                           //# to avoid any wrong input from user
    printf("Gender ONLY ( Male Or Female )\n");    
    getchar();
    scanf("%9s",&(add->gender)); 
    upper((add->gender));
    } while (strcmp(add->gender, "MALE") != 0 && strcmp(add->gender, "FEMALE") != 0); 
    add->id=id_test; // scanf("%d",&(add->id));
    fflush(stdin);
    if(!head)
        head=add;
    else{ for(current=head;current->next;current=current->next){}
            current->next=add;
        }
    add->next=NULL;
    tail=add;
}

bool first (u8 * namee , u8 *agee , u8 *ganderr ,s32 * id){ 
assert(head);
if(!head) return false;
current=head;
*namee=current->name;
*agee=current->age;
*ganderr=current->gender;
*id=current->id;
return true;
}

bool next (u8 * namee , u8 *agee , u8 *ganderr ,s32 * id){
    assert(current);
    if(!current->next) return false;
    current = current->next;
    *namee = current->name;
    *agee = current->age;
    *ganderr = current->gender;
    *id = current->id;
    return true;
}

int search (s32 id){ 
    //assert(head);
        int n = 0;
        if(!head){
            printf("list is empty\n");
            return -1;
        } 
        for(ptrSearch =head ; ptrSearch ; ptrSearch=ptrSearch->next){
            if(ptrSearch->id == id){
                return n;  
            }
            n++;
        }
        printf("patient not found\n");
        return -1;
}

void show(s32 n){ 
    if(n<0) return;
    printf("Name : %s\nAge : %d\nGender : %s\nID : %d\n",ptrSearch->name,ptrSearch->age,ptrSearch->gender,ptrSearch->id);
}


void update(s32 n){ 
    if(n<0)
            return;
        else{    
    printf("Update current patient!\n");
    printf("enter New name , age , gender \n");
    getchar();
    scanf("%[^\n]",&(ptrSearch->name));
    scanf("%d",&(ptrSearch->age));
    do{                                           //# to avoid any wrong input from user
    printf("Gender ONLY ( Male Or Female )\n");    
    getchar();
    scanf("%9s",&(ptrSearch->gender)); 
    upper((ptrSearch->gender));
    } while ( strcmp(ptrSearch->gender, "MALE") != 0 && strcmp(ptrSearch->gender, "FEMALE") != 0);
    // scanf("%d",ptrSearch->id);
    printf("Updated!\n");
    }
}
void Reserve(s32 n){ 
    static u16 res=0;
    if(n<0) return;
        else{
            //! "there are 5 available slots\n 1 : 2pm to 2:30pm\n 2 : 2:30pm to 3pm\n 3 : 3pm to 3:30pm\n 4 : 4pm to 4:30pm\n 5 : 4:30pm to 5pm.\n" ;   
        printf("there are %d available slots\n",5-count);
        for(u8 i =0 ; i<5 && count<5 ; i++){
        if(resrves[i])
            continue;
        else
            printf("-> %d : %gpm to %gpm\n",i+1,time_format1(i),time_format2(i)); 
        }
        if(count==5) 
        return ;       
        do{
            printf("Choose from available slots : ");
            scanf("%d",&res);
            }while((res<1 || res>5) || resrves_index[res-1]); 
            printf("DONE!\n");
            resrves_index[res-1] =res;
            resrves[res-1] = ptrSearch->id;
            count++;    
        }
}
void show_Reserves(){ 
    if(!count) {printf("empty today\n"); return;}
    printf("there are %d Reserved slots\n",count);
        for(u8 i =0 ;i<5 ; i++){
        if(!resrves[i])
            continue;
        else
            printf("patient id :%d\n",resrves[i]);
            printf("-> %d : %gpm to %gpm\n",i+1,time_format1(i),time_format2(i));
        }  
}
void cancel(s32 n){
    for(u8 i =0 ;i<5 ; i++){ 
        if(resrves[i] ==ptrSearch->id){
            resrves[i]=0;
            count--;
            printf("canceld!\n");
            return;
            }
            printf("not reserved yet !\n");
    }
}
bool delete_Patient(int n){
        if(n<0) return false;
        current=head;
        for(int i=1 ; i<n ;i++)
            current =current->next;
        if(n)    
            current->next =ptrSearch->next;
        else{
            current =ptrSearch->next;
            head =current;
        }    
        if(ptrSearch->next ==NULL)
            tail =current;
        free (ptrSearch);
        return true;    
    }
    void displayAll(){
        assert(head);
        if(!head){
            printf("list is empty !\n");
        return;
        }
        for(link ptr =head ; ptr ; ptr=ptr->next){
            printf("Name : %s\nAge : %d\nGender : %s\nID : %d\n",ptr->name,ptr->age,ptr->gender,ptr->id);
        }
    }
    void upper(u8 *str){
    for (u8 i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
    }    
void free_del(){  
    for(link ptr =head ; ptr ; ptr=ptr->next){
        free(ptr);
    }
}