#include<stdio.h>
#include<string.h>                                                                 
#include<stdbool.h>                                                                
                                                                                   
enum currency {                                                                    
        TWOTHOUSAND,                                                               
        FIVEHUNDRED,                                                               
        TWOHUNDRED,                                                                
        HUNDRED,                                                                   
        FIFTY,                                                                     
        TWENTY,                                                                    
        TEN,                                                                       
        MAX                                                                        
} notes;                                                                           
                                                                                   
char temp_db[MAX];                                                                 
char base_db[MAX];                                                                 

void disp_item_menu()
{
	printf("This is the item menu");
}

bool validate_currency(int curr)                                                   
{                                                                                  
        bool res;                                                                  
        int value;                                                                 
        switch(curr)                                                               
        {                                                                          
        case 2000:                                                                 
                res = true;                                                        
                value = TWOTHOUSAND;                                               
                break;                                                             
        case 500:                                                                  
                res = true;                                                        
                value = FIVEHUNDRED;                                               
                break;                                                             
        case 200:                                                                  
                res = true;                                                        
                value = TWOHUNDRED;                                                
                break;                                                             
        case 100:                                                                  
                res = true;                                                        
                value = HUNDRED;                                                   
                break;                                                             
        case 50:                                                                   
                res = true;                                                        
                value = FIFTY;                                                     
                break;                                                             
        case 20:                                                                   
                res = true;                                                        
                value = TWENTY;                                                    
                break;                                                             
        case 10:                                                                   
                res = true;                                                        
                value = TEN;                                                       
                break;                                                             
        default:                                                                   
                res = false;                                                       
                break;                                                             
        }                                                                          
        temp_db[value]++;                                                          
        return res;                                                                
}                                                                                  
                                                                                   
void populate_temp_db()                                                                 
{                                                                                  
        int i = 0;                                                                 
        for(i;i++;i<MAX)                                                           
        {                                                                          
                temp_db[i]=temp_db[i] + base_db[i];                                
        }                                                                          
}                                                                                  
int display_menu()
{                                                                                  
        int curr=0;                                                                
        bool res;                                                                  
        char ch;                                                                   
        int i;                                                                     
        int scan=1;                                                                
                                                                                   
        printf("Enter currency notes\n");                                       
//        fflush(stdin);                                                          
        scan = scanf("%d",&curr);                                               
        printf("\n\n\n value of scan = %d",curr);                               
 /*       if(scan==0)                                                             
        {                                                                       
               printf("Invalid Currency note inserted, retry\n");               
               curr = 0;                                                        
               return 10;                                                       
               display_menu();                                                  
        }                                                                       
        //fflush(stdin);                                                        
        res = validate_currency(curr);                                          
        if(!res)                                                                
        {                                                                       
                curr = 0;                                                       
                printf("Invalid Currency note inserted, retry\n");              
                display_menu();                                                 
        }                                                                       
        else                                                                    
        {                                                                       
                printf("Rs. %d note received, Do you want to enter more? (Y/N)\n",curr);
                scanf(" %c",&ch);                                               
                //fflush(stdin);                                                
                if(ch == 'Y')                                                   
                        display_menu();                                         
                else                                                            
                        printf("Proceeding to item menu");                      
                        disp_item_menu();                                       
        }                                                                       
   */                                                                             
        return curr;                                                            
}                                                                               
int main()                                                                      
{                                                                               
        int ch;                                                                 
        ch = display_menu();                                                    
        printf("\nexit code = %d",ch);                                         
                         /*                                                       
        int i = 0;                                                              
        for (i;i<MAX;i++)                                                       
        {                                                                       
                printf("value of temp[%d] = %d\n",i,temp_db[i]);                
        }                                                                       
                           */                                                     
        return 0;                                                               
}
