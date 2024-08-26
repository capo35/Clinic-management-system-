
#ifndef STDTypesAnd_defs
#define STDTypesAnd_defs

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

#endif
#include <stdio.h>
#define print_AdminCases do{ \
        printf("*************************************&&******************************************\n\
            For Add new patient : 1\n\
            For Edit patient record : 2\n\
            For Reserve a slot with the doctor : 3\n\
            For Cancel reservation : 4\n\
            For Show Patient :5\n\
            delete patient information :6\n\
            Display All patients informations :7\n\
            Switching -> USER Mode :10\n\
            For EXITE PRESS 0\n");} while (0)
#define print_UserCases do{  \
        printf("*************************************&&******************************************\n\
             For View patient record : 1\n\
             For View todays reservations : 2\n\
             For EXITE PRESS 0\n");} while (0) 
        
#define time_format1(i) (2.0+0.5*i)
#define time_format2(i) (2.5+0.5*i)


//! functions prototypes
void insert (); // insert data for patient and check first if it exists or not 
bool first(u8 * namee , u8 *agee , u8 *ganderr ,s32 * id);
bool next(u8 * namee , u8 *agee , u8 *ganderr ,s32 * id);
int search (s32 id); // search for patient by id
void show(s32 n);   // show one pateint
void update(s32 n); // update patient data
void Reserve(s32 n);    // reserve a solt with a doctor
void show_Reserves();   // show for user
void cancel(s32 n);     // cancel reserves
bool delete_Patient(int n); // delete patient 
void displayAll();  // display all students
void free_del();    // free memory

