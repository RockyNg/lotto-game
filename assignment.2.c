/* Program Description :
lotto game using functions for every option
Author : Rocky Ng
Date: 09/03/18 */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 6
#define RANGE 42

//prototype
int option1(int[SIZE],int[RANGE],int[RANGE],int);
void option2(int[SIZE]);
int option3(int[SIZE]);
void option4(int[SIZE],int[SIZE],int);
void option5(int[RANGE],int[RANGE]);


int main()
{
    
    
    int option=0;
    int control=0;
    int count_array[RANGE]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,
                            15,16,17,18,19,20,21,22,23,24,25,
                            26,27,28,29,30,31,32,33,34,35,36,
                            37,38,39,40,41,42};
    int final_array[RANGE]={0};
    int your_array[SIZE]={0};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    
    //do while user hasn't entered 6
    do 
    {
        int my_array[SIZE]={1,3,5,7,9,11};
        int bonus=42;
        

        
        printf("\n\nMAIN MENU\n\n");
        printf("1)Enter any 6 numbers (1-42 inclusive) from the keyboard.\n\n");
        printf("2)Display your lotto numbers that you entered.\n\n");
        printf("3)Sort the contents of the array in increasing order\n\n");
        printf("4)Compare your chosen lotto numbers in the 1-D array with the winning numbers\n\n");
        printf("5)Display the frequency of the numbers entered\n\n");
        printf("6)Exit program\n");
        printf("\n\n");
        
        scanf("%d",&option);
        
        //check if input is a character
        char *end;
        char buf[RANGE];

    
            
            do 
            {
                
                if (!fgets(buf, sizeof buf, stdin))
                     
                break;
                   // remove \n
                     buf[strlen(buf) - 1] = 0;
                
                     int n = strtol(buf, &end, 10);
                
                } while (end != buf + strlen(buf));
                            
                
        if (option<1||option>6)
        {
            printf("Invalid Input,select again");
        }
        else
        {
            //call function1
            if(option==1)
            {
                option1(your_array,count_array,final_array,control);
            }
            
            //call function2
            if(option==2&&control==1)
            {
                option2(your_array);
            }
            
            if(option==2&&control==0)
            {
                printf("Select option1 before this option\n");
            }
            
            //call function3
            if(option==3&&control==1)
            {
                option3(your_array);
            }
            
            if(option==3&&control==0)
            {
                printf("Select option1 before this option\n");
            }

            
            //call function4
            if(option==4&&control==1)
            {
                option4(my_array,your_array,bonus);
            }
            
            if(option==4&&control==0)
            {
                printf("Select option1 before this option\n");
            }
            
            //call function5
            if(option==5&&control==1)
            {
                option5(count_array,final_array);
            }
            
            if(option==5&&control==0)
            {
                printf("Select option1 before this option\n");
            }
           
            
        }
    }
    while (option!=6);
    //end do while()
    
    return 0;
    
}//end main()

//implement option1
int option1(int create_array[SIZE],int num_array[RANGE],int last_array[RANGE],int before)

{
    int i;
    int j;
    int test[RANGE]={0};
    //enter your numbers
    printf("\n\nEnter %d numbers (1-42 inclusive) from the keyboard.\n",SIZE);
    
    
    for(i=0;i<SIZE;i++)
    {
        
        scanf("%d",&(*(create_array+i)));
        
        //check if number entered is within range
        if( (*(create_array+i))>=1 && (*(create_array+i))<=42 )
        {
            
            //check if any numbers repeat
            for(j=0;j<RANGE;j++)
            {

                if ( (*(create_array+i))==(*(create_array+j)) )
                {
                    (*(test+j))++;
                }
                if( (*(test+j))>1)
                {
                    printf("\nYou've already entered this number,enter another one\n");
                    scanf("%d",&(*(create_array+i)));
                    (*(test+j))--;                    

                }
                
                //storing the numbers you entered for option5
                if( (*(num_array+j))==  (*(create_array+i)) )
                {
                    (*(last_array+j))=((*(last_array+j))+1);
                }
            }
        }
        else
        {
            
            printf("\nInvalid Input,enter again\n");
            i--;
        }
        before=1;
        
    }
    
    //return numbers entered by user
    return *create_array,*last_array,before;
}//end option1

//implement option2
void option2(int display_array[SIZE])

{
    int i;
    printf("\n\nDisplay your lotto numbers that you entered.\n\n",SIZE);
    
    //display the numbers in the order that the user entered
    for(i=0;i<SIZE;i++)
    {
        printf("%d\n",(*(display_array+i)));
    }
   
}//end option2

//implement option3
int option3(int sort_array[SIZE])

{
    int i;
    int j;
    int temp=0;
    
    printf("\n\nSorting the contents of the array in increasing order\n\n",SIZE);
    
    //sorting array using bubble sort
    for(i=0;i<SIZE;i++)
    {
        for (j = i + 1; j < SIZE; j++)
        {
            if ( (*(sort_array+i)) > (*(sort_array+j)) ) 
            {
                temp =  (*(sort_array+i));
                (*(sort_array+i)) = (*(sort_array+j));
                (*(sort_array+j)) = temp;
            }
        }
    }
    
    //display sorted array
    for(i=0;i<SIZE;i++)
    {
        printf("%d\n",(*(sort_array+i)));
        
    }
    
    return *sort_array;
}//end option3

//implement option4
void option4(int win[SIZE],int yours[SIZE],int extra)

{
    int i;
    int j;
    int new_array[SIZE]={0};
    int bone_ness=0;
    int counter=0;

    printf("\n\nCompare your chosen lotto numbers with the winning numbers\n\n",SIZE);
    
    
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            
            //comparing user's numbers with winning numbers
            if( (*(yours+i))==  (*(win+j)) )
            {
                (*(new_array+i))=(*(yours+i));
                counter++;
                
            }
            
        }
        
        //check if user got the bonus number
        if( (*(yours+i))==  extra )
        {
            bone_ness++;
        }
        
    }
    
    //display winning numbers the user got
    printf("The winning numbers you got are:\n");
    
    for(i=0;i<SIZE;i++)
    {
        if( (*(new_array+i))!=0 )
        {
            printf("%d\n",(*(new_array+i)));
        }
    }
    
    if(bone_ness!=0)
    {
        //display if user got bonus number
        printf("Also you got number 42 as a Bonus number\n");
    }
    
    //display what prize the user won depending on the numbers they got correct
    if(counter==6)//6correct
    {
        printf("\nYou've won the Jackpot\n");
    }
    
    if(counter==5&&bone_ness==1)//5correct+bonus
    {
        printf("\nYou've won a new car\n");
    }
    
    if(counter==5&&bone_ness==0)//5correct
    {
        printf("\nYou've won a Holiday trip\n");
    }
    
    if(counter==4&&bone_ness==1)//4correct+bonus
    {
        printf("\nYou've won a Weekend away\n");
    }
    
    if(counter==4&&bone_ness==0)//4correct
    {
        printf("\nYou've won a Night out\n");
    }
    
    if(counter==3&&bone_ness==1)//3correct+bonus
    {
        printf("\nYou've won a Cinema ticket\n");
    }
    if(counter==3&&bone_ness==0)//3correct 
    {
        printf("\nYou didn't win anything\n");
    }
    if(counter<3)//less than 3 correct
    {
        printf("\nYou didn't win anything\n");
    }

}//end option4

//implement o5
void option5(int num_array[RANGE],int last_array[RANGE])

{
    int i;
    
    printf("\n\nDisplay the frequency of the numbers entered\n\n");
    
    for(i=0;i<RANGE;i++)
    {
        if( (*(last_array+i))!=0 )
        {
            printf("%d is selected %d times\n",(*(num_array+i)), (*(last_array+i)) );
        }
    }
}//end option5



    
        