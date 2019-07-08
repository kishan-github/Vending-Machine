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

void disp_item_menu(int total, int temp_total)
{
	printf("\n\n*#*#*#*#*WELCOME#*#*#*#*#*\n\n");

	if(temp_total<total)
	{
		printf("You have Rs. %d left, please select accordingly :-)\nChoose from below options!!!\n\n1. Item @Rs.10\n2. Item @Rs.20\n3. Item @Rs.30\n4. Item @Rs.40",temp_total);
		temp_total = temp_total + 10;
	}
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

int get_temp_db_value()
{
	return 100;
}

int update_temp_db(int curr)
{
	printf("\ninside update db, db updated!!!\n");
}

int display_curr_menu()
{                                                                                  
        int curr=0;                                                                
        bool res;                                                                  
        char ch;                                                                   
        int i;                                                                     
        int scan=1;                                                                
                                                                                   
        printf("Enter currency notes\n");                                       
        scan = scanf("%d",&curr);                                               
        res = validate_currency(curr);                                          
        if(!res)                                                                
        {                                                                       
                curr = 0;                                                       
                printf("Invalid Currency note inserted, retry\n");              
                display_curr_menu();                                                 
        }                                                                       
        else                                                                    
        {    
		update_temp_db(curr);
                printf("Rs. %d note received, Do you want to enter more? (Y/N)\n",curr);
                scanf(" %c",&ch);                                               
                if(ch == 'Y' | ch =='y')                                                   
                        display_curr_menu();                                         
                else                                                            
                        return get_temp_db_value();                                       
        }                                                                       
}                                                                               
int main()                                                                      
{                                                                               
        int total;                                                                 
        total = display_curr_menu();                                                    
        printf("\nexit code = %d",total);                                         

	disp_item_menu(total,0);
                         /*                                                       
        int i = 0;                                                              
        for (i;i<MAX;i++)                                                       
        {                                                                       
                printf("value of temp[%d] = %d\n",i,temp_db[i]);                
        }                                                                       
                           */                                                    
	getch();
        return 0;                                                               
}
