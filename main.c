#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "STDTypesAnd_defs.h"
#include "linkedList_Control.h"
/*
            **@ that's a main program for Clinic Management System
            in this file you can see all cases are avaible and some i add it 
            in linkedList_Control.h file it's the database center of my program
            in STDTypesAnd_defs.h file i defined all types and some useful macros and functions prototypes
            ! mohamed.abdallah05@eng-st.cu.edu.eg
*/
int main(){
    u8 switch_mode=-1,switch_INcase=-1,counter=0;
    s32 passcode=0,no_search=0,idd=0;
    bool flag=0;
    while (switch_mode>1 || switch_mode<0 ){
    printf("**************** For USER mode ENTER 0 && For ADMIN mode ENTER 1 ****************\n");
    scanf("%d",&switch_mode);
    switch (switch_mode)
    {
        case 0:{
                                //! **************** USER MODE *****************/
            printf("NO DATA ENTERD !\n *Switching you -> ADMIN Mode First\n");
            goto Admin_Mode;
            User_mode: 
            printf("You Are In User mode now\n");
            while (switch_INcase!=0){
            print_UserCases; // @ macro -> print cases
            printf("case : ");
            scanf("%d",&switch_INcase);     
             switch (switch_INcase){
             
             case 1:{   // For View patient record
                printf("enter id for search\n");
                scanf("%d",&idd);
                show(search(idd));
                }break;

             case 2:{   // For View todays reservations
                show_Reserves();
                }break;

             default:printf("enter a num bettwen 1-2 and 0 for ESC\n");
                break;
            }
                
            }
        }
        break;

    /*
    *******************************************************************************************************************************************
    */     
        case 1:{
                                //! **************** ADMIN MODE *****************/
            /* pass check */
            Admin_Mode :
            printf("You Are In Admin mode now\n");
            do{
            if(counter>0) printf("try agian. \n");
            printf("Please Enter The PASSCODE\n");
            scanf("%d",&passcode);
            if(passcode==1234) flag=true;
            } while (counter++!=2 && !flag);
            if(!flag) {
                printf("pls try again later..\n");
                return 0;
            }
            
            while (switch_INcase!=0){
            print_AdminCases; // @ macro -> print cases
            printf("case : ");
            scanf("%d",&switch_INcase);      
            switch (switch_INcase){
                case 1:{   // Add new patient
                insert();
                }break;

                case 2:{   // Edit patient record
                printf("enter id for Edit\n");
                scanf("%d",&idd);
                update(search(idd));    
                }break;

                case 3:{ // Reserve a slot with the doctor
                printf("enter id Reserve a slot with the doctor \n");
                scanf("%d",&idd);
                Reserve(search(idd));
                }break;

                case 4:{ // Cancel reservation
                printf("enter id for cancel reserve\n");
                scanf("%d",&idd);
                cancel(search(idd));
                }break;
                case 5:{ // show patient information
                printf("enter id for show information\n");
                scanf("%d",&idd);
                show(search(idd));
                }break;
                case 6:{ // delete patient information
                printf("enter id to delete his information\n");
                scanf("%d",&idd);
                flag=delete_Patient(search(idd));
                if(flag) printf("PATIENT WAS DELETED !\n");
                else printf("PATIENT NOT FOUND !\n");
                }break;
                case 7:{ // show all patients information
                displayAll();
                }break;
                case 10:
                if(!head) {printf("No data enterd\n"); return 0;} 
                else
                    goto User_mode;
                break;
             default:if(switch_INcase==0) break;
                printf("enter a num bettwen 1-7 and 10 To Swap To User Mode\nPress 0 for ESC\n");
                break;
             }
            }
        }
        break;
    default: 
        printf("INVALID MODE 0-1 ONLY !!\n");
        break;
    }
    }
    free_del(); //! used to free up memory .
    return 0;
}   