//Group 9 
//Title: Sport Equipment Rental System
//Kong Hao Ming 1191202158
//Intan Nur Natasha Binti Saidan 1191202566
//Tong Lee Qi 1191202353
//Beh Jia Min 1191202274
//Adelene Ee Pei Ying 1191202622

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h> //system("pause") system("cls")
#define _WIN32_WINNT 0x05232 //definition for maximize and minimize window

//structure named item for equipment
struct item
{
	//declaration
	char name[20];
	float price;
	int quantity;
	int new_quantity;
	float total;
}equipm[20];  //declaring equipment as a global structured array with 20 element maximum and using variables in structure named item

//structure named user for admin and user
struct user
{
    char name[50];
    char username[50];
    char password[50];
    char check_username[50];
    char check_password[50];
    float phone;
    float total_price;
    int member_points;
}admin,user; //declaring admin and user as a global structured array and using variables in structure named item

//function prototype
void MaximizeOutputWindow();
void RestoreOutputWindow();
void welcome_page();
void modemenu();
void menu();
void create_admin();
void login_admin();
void create_user();
void login_user();
void admin_menu();
void admin_menu1();
void user_menu1();
void user_menu();
void equipm_info();
void edit_equipm();
void view_equipm_a();
void view_equipm_u();
void search_equipm_a();
void search_equipm_u();
void rent_equipm();
void pay_rent();
void add_equipm();

//main() function
int main()
{
	MaximizeOutputWindow(); //calling MaximizeOutputWindow(); function (line 1225) to maximize the cmd window at the start of program execution
	welcome_page();
	equipm_info();
	modemenu();	
	RestoreOutputWindow(); //calling RestoreOutputWindow(); function (line 1232) to minimize the cmd window at the end of program execution
}

//function definition void equipm_info()
void equipm_info()
{
	//setting equipment name to equipm array
	strcpy(equipm[1].name,"Badminton");
	strcpy(equipm[2].name,"Tennis");   
	strcpy(equipm[3].name,"Basketball");
	strcpy(equipm[4].name,"Skateboard");
	strcpy(equipm[5].name,"Football");
	strcpy(equipm[6].name,"Volleyball");
	strcpy(equipm[7].name,"Soccer");  
	
	//setting price to each equipment to equipm array
	equipm[1].price=20;
	equipm[2].price=30;
	equipm[3].price=35;
	equipm[4].price=40;
	equipm[5].price=45;
	equipm[6].price=50;
	equipm[7].price=55;
	
} 

//function definition void welcome_page() to display welcome page
void welcome_page()
{
	system("color 3");
	printf("\n\n\n\n");
	printf("\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t     *               __        __   _                            _                               *\n");
	printf("\t     *               \\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___                         *\n");
	printf("\t     *                \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\                        *\n");
	printf("\t     *                 \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |                       *\n");
	printf("\t     *                  \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/                        *\n");                                         
	printf("\t     *                                                                                           *\n");
	printf("\t     *      ____                   _     _____            _                            _         *\n");
	printf("\t     *     / ___| _ __   ___  _ __| |_  | ____|__ _ _   _(_)_ __  _ __ ___   ___ _ __ | |_       *\n");
	printf("\t     *     \\___ \\| '_ \\ / _ \\| '__| __| |  _| / _` | | | | | '_ \\| '_ ` _ \\ / _ \\ '_ \\| __|      *\n");
	printf("\t     *      ___) | |_) | (_) | |  | |_  | |__| (_| | |_| | | |_) | | | | | |  __/ | | | |_       *\n");
	printf("\t     *     |____/| .__/ \\___/|_|   \\__| |_____\\__, |\\__,_|_| .__/|_| |_| |_|\\___|_| |_|\\__|      *\n");
	printf("\t     *             |  _ \\|_|_ _ __ | |_ __ _| | / ___| _ |_| ___| ||_|__ _ __ ___                *\n");
	printf("\t     *             | |_) / _ \\ '_ \\| __/ _` | | \\___ \\| | | / __| __/ _ \\ '_ ` _ \\               *\n");
	printf("\t     *             |  _ <  __/ | | | || (_| | |  ___) | |_| \\__ \\ ||  __/ | | | | |              *\n");
	printf("\t     *             |_| \\_\\___|_| |_|\\__\\__,_|_| |____/ \\__, |___/\\__\\___|_| |_| |_|              *\n");
	printf("\t     *                                                 |___/                                     *\n");
	printf("\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n\n\n");
	system("pause");
	system("cls");
}

//function definition void modemenu() to prompt user to choose he/she is either an admin or normal user(customer)
void modemenu()
{
	int mode_choice;
	int cont_choice;
	
	do{
		system("color E");
		printf("\n\t                       ___  ___  ___  _____ _   _     ___  ___ _____ _   _ _   _ \n");
		printf("\t                       |  \\/  | / _ \\|_   _| \\ | |    |  \\/  ||  ___| \\ | | | | |\n");
		printf("\t                       | .  . |/ /_\\ \\ | | |  \\| |    | .  . || |__ |  \\| | | | |\n");
		printf("\t        ~~~~~~~~~~~~~~~| |\\/| ||  _  | | | | . ` |    | |\\/| ||  __|| . ` | | | |~~~~~~~~~~~~~~~\n");
		printf("\t                       | |  | || | | |_| |_| |\\  |    | |  | || |___| |\\  | |_| |\n");
		printf("\t                       \\_|  |_/\\_| |_/\\___/\\_| \\_/    \\_|  |_/\\____/\\_| \\_/\\___/ \n");
	
		printf("\n\n\t   ---------------------------------------------------------------------------------------\n");	
		printf("\t   |                            _   ___  __  __ ___ _  _           _                     |\n");
		printf("\t   |                           /_\\ |   \\|  \\/  |_ _| \\| |   ___   / |                    |\n");
		printf("\t   |                          / _ \\| |) | |\\/| || || .` |  |___|  | |                    |\n");
		printf("\t   |                         /_/ \\_\\___/|_|  |_|___|_|\\_|         |_|                    |\n");
		printf("\t   |                                                                                     |\n");
		
		printf("\t   |                          _   _ ___ ___ ___           ___                            |\n");
		printf("\t   |                         | | | / __| __| _ \\   ___   |_  )                           |\n");
		printf("\t   |                         | |_| \\__ \\ _||   /  |___|   / /                            |\n");
		printf("\t   |                          \\___/|___/___|_|_\\         /___|                           |\n");
	
		printf("\t   |                                                                                     |\n");
		printf("\t   |                       ___  _   _ ___ _____                 ____                     |\n");
		printf("\t   |                      / _ \\| | | |_ _|_   _|      ___      |__ /                     |\n");
		printf("\t   |                     | (_) | |_| || |  | |       |___|      |_ \\                     |\n");
		printf("\t   |                      \\__\\_\\\\___/|___| |_|                 |___/                     |\n"); 
		printf("\t   ---------------------------------------------------------------------------------------\n");    
	    printf("\t\t\nEnter your choice [1/2] : ");
	    scanf("%d",&mode_choice);
	    system("cls");
	    //using switch case statement to determine user's choice
	    switch(mode_choice)
    	{
	    	case 1: 
	    		admin_menu1(); //function call admin_menu1()
	    		break;
	    	case 2:
	    		user_menu1(); //function call user_menu1()
	    		break;
	    	default:
	    		printf("\n\n\t\tInvalid choice.\n\n");
	    		printf("\t\tEnter 1 to continue.\n");
	    		printf("\t\tEnter 2 to exit.\n\n");
	    		printf("\t\tChoice : ");
	    		scanf("%d",&cont_choice);
		}
	}while(cont_choice==1);
	if(cont_choice!=1)
	{
		system("cls");
		printf("\n\n\t\tTq for visiting D6A SPORT EQUIPMENT RENTAL SYSTEM\n");
		exit(1);
	}
}

//function definition void admin_menu1() to prompt admin to choose he/she wants to create account or login
void admin_menu1()
{
	int choice;
	int cont_choice;
	
	do
	{
	    system("cls");
	    system("color 2");
		printf("\n\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t*                 _       _           _                     *\n");
		printf("\t\t\t\t*                /_\\   __| |_ __ ___ (_)_ __                *\n");
		printf("\t\t\t\t*   ~~~~~~~~~~~~//_\\\\ / _` | '_ ` _ \\| | '_ \\~~~~~~~~~~~~   *\n");
		printf("\t\t\t\t*              /  _  \\ (_| | | | | | | | | | |              *\n");
		printf("\t\t\t\t*              \\_/ \\_/\\__,_|_| |_| |_|_|_| |_|              *\n");                     
		printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t|                                                           |   \n");
	 	printf("\t\t\t\t|   1. Create new account.                                  |   \n");
		printf("\t\t\t\t|   2. Login to an existing account.                        |   \n");
		printf("\t\t\t\t|   8. Back to login menu.                                  |   \n");
		printf("\t\t\t\t|                                                           |   \n");
		printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n");
		printf("\t\tEnter your choice : ");
	    scanf("%d",&choice);
		if(choice==1)
		{
			system("cls");
			create_admin(); //function call create_admin();
		}
		else if(choice==2)
		{
			system("cls");
			login_admin(); //function call login_admin();
		}
		else if(choice==8)
		{
			system("cls");
			modemenu(); //go back to login menu
		}
		else 
	    {
	    	printf("\n\n\t\tInvalid choice.\n");
	    	printf("\t\tYou have to login first to unlock full menu. \n");
	    	system("pause");
		}
    }while(choice!=1 && choice!=2 && choice!=8);
}

//function definition void admin_menu() to display the main menu and show the available features
void admin_menu()
{
	int choice;
	int cont_choice;
	
    do
    {
    printf("\n\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t*                 _       _           _                     *\n");
	printf("\t\t\t\t*                /_\\   __| |_ __ ___ (_)_ __                *\n");
	printf("\t\t\t\t*   ~~~~~~~~~~~~//_\\\\ / _` | '_ ` _ \\| | '_ \\~~~~~~~~~~~~   *\n");
	printf("\t\t\t\t*              /  _  \\ (_| | | | | | | | | | |              *\n");
	printf("\t\t\t\t*              \\_/ \\_/\\__,_|_| |_| |_|_|_| |_|              *\n");                     
	printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t|                                                           |   \n");
	printf("\t\t\t\t|   3. Edit equipment price.                                |   \n");
	printf("\t\t\t\t|   4. View available equipment.                            |   \n");
	printf("\t\t\t\t|   5. Search equipment.                                    |   \n");
	printf("\t\t\t\t|   6. Add new equipment.                                   |   \n");
	printf("\t\t\t\t|   7. Back to login menu.                                  |   \n");
	printf("\t\t\t\t|   8. Exit.                                                |   \n");
	printf("\t\t\t\t|                                                           |   \n");
	printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n");
	printf("\t\tEnter your choice : ");
    scanf("%d",&choice);
    system("cls");
    //using switch case statement to determine user's choice
    switch(choice)
    {
		case 3: //edit equipment price
			edit_equipm();
			break;
		case 4: //view equipment and price
			view_equipm_a();
			break;
		case 5: //search an equipment and its price
			search_equipm_a();
			break;
		case 6: //add new equipment
			add_equipm();
			break;
		case 7:  //go back to login menu
			system("cls");
			modemenu();
			break;
		case 8: //exit system
			system("cls");
			printf("\n\n\t\tTq for visiting D6A SPORT EQUIPMENT RENTAL SYSTEM\n");
			system("cls");
			exit(1);
			break;
		default: 
			printf("\n\n\t\tInvalid choice.\n\n");
	    	printf("\t\tEnter 1 to continue.\n");
	    	printf("\t\tEnter 2 to exit.\n\n");
	    	printf("\t\tChoice : ");
	    	scanf("%d",&cont_choice);	
	}
	}while(cont_choice==1);
	if(cont_choice!=1)
	{
		system("cls");
		printf("\n\n\t\tTq for visiting D6A SPORT EQUIPMENT RENTAL SYSTEM\n");
		exit(1);
	}
}

//function definition void create_admin() create a new account
void create_admin()
{	
	FILE *create_a; //create file pointer *create_a
   	create_a = fopen("admin.txt","w"); //file pointer create_a to open admin.txt as write mode
	//check if file exist 
 	if(create_a == NULL)	
	{
		printf("File does not exist. \n");
		exit(1);
	}
	printf("\n\n\t\tNew account regisration ...... \n");
	printf("\n\t\tEnter Username : ");
	fflush(stdin);
	gets(admin.username);
	printf("\t\tEnter Password : ");
	fflush(stdin);
	gets(admin.password);
	//write details to file
	fprintf(create_a,"\n%s %s\n",admin.password,admin.password);
	printf("\n\n\t\tRegistration successful !! \n\n");
	printf("\t\tProceed to Login...... \n\n");
	printf("\t\tPress any key to proceed to Login.\n\n");
	fflush(stdin);
	getch();
	//delay(1000);
	system("cls");
	//function call login_admin(); to login to account
	login_admin();
	
}

//function definition void login_admin() login to account
void login_admin()
{
	char cont;
	int again;
	
	FILE *check_a; //create file pointer *check_a
	check_a = fopen("admin.txt","r"); //file pointer check_a open admin.txt as read mode
	//move file cursor to begining
	rewind(check_a);
	//check if file exist
	if(check_a == NULL)	
	{
		printf("Account does not exist. Please create a new account first before proceed to login.\n");
		exit(1);
	}
		
	printf("\n\n\t\tLogin as Admin...... \n\n");
	printf("\t\tEnter Username : ");
	fflush(stdin);
	gets(admin.check_username);	
	printf("\t\tEnter password : ");
	fflush(stdin);
	gets(admin.check_password);	

	//to read until the end of the line
	while(!feof(check_a))
	{
		//comparing if the login details exist. if yes, then login success
		fscanf(check_a,"%s %s",&admin.username,&admin.password);
		if(strcmp(admin.check_username,admin.username)==0 && strcmp(admin.check_password,admin.password)==0)
		{
			printf("\n\t\tLogin successful \n");
			system("pause");
		}
		else
		{
			do
			{
				printf("\n\t\tSorry wrong username / password \n\n ");
				printf("\t\tEnter 1 to try again.\n");
				printf("\t\tEnter 2 to create new account.\n");
				printf("\t\tEnter 3 to back to main menu.\n");
				printf("\n\t\tChoice : ");
				scanf("%d",&again);
				if(again==1)
				{
					printf("\n\t\tUsername : ");
					fflush(stdin);
					gets(admin.check_username);	
					printf("\t\tPassword : ");
					fflush(stdin);
					gets(admin.check_password);	
				}
				if(again==2)
				{
					system("cls");
					create_admin();
				}
				if(again==3)
				{
					system("cls");
					admin_menu1();
				}
			}while(strcmp(admin.check_username,admin.username)!=0 || strcmp(admin.check_password,admin.password)!=0);
			printf("\n\t\tLogin successful \n");
			system("pause");
		}	
		
	}
	system("cls");
	//function call admin_menu() 
	admin_menu();
}

//function definition void edit_equipm() to let admin edit equipment price
void edit_equipm()
{
	int choice; 
	int cont_choice; 
	int cont;
	int count=0;
	int i=0;
	int is=0;
	
	//counting total number of element in the array that is currently occupied. 
	//means if there is 8 out of 20 array occupied, then it will only display 8 times. 
	for(i = 1; i<=20; i++)
	{
		if(strcmp(equipm[i].name,"")!=0)
		{
			is++;
		}
	}
	printf("\n\n\t\tnum of element is : %d \n",is); //display total elements inside the array equipm
	
	//display equipment based on the number of elements counted.
	printf("\n\n\t\tSelect equipment to edit: \n");
	for(count=1;count<=is;count++)
	{
	printf("\t\t%d. %s\n",count,equipm[count].name);		
	}
	printf("\n\n\t\tEnter your choice [1-%d] : ",is);
	scanf("%d",&choice);
	if(choice<=is)
	{
		printf("\n\n\t\tEnter new price for %s : RM ",equipm[choice].name);
		scanf("%f",&equipm[choice].price);
		printf("\n\n\t\tPrice updated successfully \n");
		printf("\t\tNew price for %s is RM %.2f \n",equipm[choice].name, equipm[choice].price );
		printf("\t\tEnter 1 to continue editing.\n");
		printf("\t\tEnter 2 to return to Main Menu.\n\n");
		printf("\t\tChoice : ");
	   	scanf("%d",&cont_choice);
		if(cont_choice==1)
		{
			edit_equipm();
		}
		else if(cont_choice==2)
		{
			system("cls");
			admin_menu();
		}
		else if(choice!=1 && choice!=2)
		{
			do
			{
				printf("\n\n\t\tInvalid choice.\n");	
				printf("\t\tEnter 1 to continue editing.\n");
		   		printf("\t\tEnter 2 to return to Main Menu.\n\n");
		  	 	printf("\t\tChoice : ");
		  	 	scanf("%d",&cont_choice);
		  	 	system("cls");
				if(cont_choice==1)
				{
					edit_equipm();
				}
				else if(cont_choice==2)
				{
					system("cls");
					admin_menu();
				}
			}while(choice!=1 && choice!=2);
		}	
	}
	
	else if(choice>is);
	{
		printf("\n\n\t\tInvalid choice.\n");
	   	printf("\t\tEnter 1 to continue editing.\n");
	   	printf("\t\tEnter 2 to return to Main Menu.\n\n");
	   	printf("\t\tChoice : ");
	   	scanf("%d",&cont_choice);
		if(cont_choice==1)
		{
			edit_equipm();
		}
		else if(cont_choice==2)
		{
			system("cls");
			admin_menu();
		}
		else if(choice!=1 && choice!=2)
		{
			do
			{
				printf("\n\n\t\tInvalid choice.\n");	
				printf("\t\tEnter 1 to continue editing.\n");
		   		printf("\t\tEnter 2 to return to Main Menu.\n\n");
		  	 	printf("\t\tChoice : ");
		  	 	scanf("%d",&cont_choice);
				if(cont_choice==1)
				{
					edit_equipm();
				}
				else if(cont_choice==2)
				{
					system("cls");
					admin_menu();
				}
			}while(choice!=1 && choice!=2);
		}	
	}
}

//function definition void view_equipm_a() to let admin view all equipment in the system and its price
void view_equipm_a()  
{
	int count=0;
	int i=0;
	int is=0;
	
	//counting total number of element in the array that is currently occupied. 
	//means if there is 8 out of 20 array occupied, then it will only display 8 times. 
	for(i = 1; i<=20; i++)
	{
		if(strcmp(equipm[i].name,"")!=0)
		{
			is++;
		}
	}
	printf("\n\n\t\tAvailable Sports Equipments : \n");
	printf("\t\tEquipment\t\tPrice (RM)\n"); 
	//display equipment based on the number of elements counted.
	for(count=1;count<=is;count++)
	{
	printf("\t\t%d. %s\t\t%.2f\n",count, equipm[count].name,equipm[count].price);
	}
	printf("\n\n\t\t");
	system("pause");
	system("cls");
	admin_menu();
}

//function definition void search_equipm_a() to let admin search equipment in the system and its price. (like search engine)
void search_equipm_a()
{
	int choice;
	char search_equipm[30];
	int count=0;
	int i=0;
	int is=0;
	
	do
	{
	printf("\n\n\t\tSearch An Equipment's Price': \n");
	printf("\t\tEnter the equipment you would like to search [Warning!! : First letter need to be Uppercase](Example: Badminton, Basketball, etc...): \n");
	fflush(stdin);
	printf("\n\t\t");
	gets(search_equipm);  //enter the name of equipment 
	
	//if it match, then it will display the price
	if(strcmp(search_equipm,equipm[1].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[1].name,equipm[1].price);
	}
	if(strcmp(search_equipm,equipm[2].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[2].name,equipm[2].price);
	}
	if(strcmp(search_equipm,equipm[3].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[3].name,equipm[3].price);
	}
	if(strcmp(search_equipm,equipm[4].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[4].name,equipm[4].price);
	}
	if(strcmp(search_equipm,equipm[5].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[5].name,equipm[5].price);
	}
	if(strcmp(search_equipm,equipm[6].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[6].name,equipm[6].price);
	}
	if(strcmp(search_equipm,equipm[7].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[7].name,equipm[7].price);
	}
	if(strcmp(search_equipm,equipm[8].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[8].name,equipm[8].price);
	}
	if(strcmp(search_equipm,equipm[9].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[9].name,equipm[9].price);
	}
	if(strcmp(search_equipm,equipm[10].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[10].name,equipm[10].price);
	}
	if(strcmp(search_equipm,equipm[11].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[11].name,equipm[11].price);
	}
	if(strcmp(search_equipm,equipm[12].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[12].name,equipm[12].price);
	}
	if(strcmp(search_equipm,equipm[13].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[13].name,equipm[13].price);
	}
	if(strcmp(search_equipm,equipm[14].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[14].name,equipm[14].price);
	}
	if(strcmp(search_equipm,equipm[15].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[15].name,equipm[15].price);
	}
	if(strcmp(search_equipm,equipm[16].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[16].name,equipm[16].price);
	}
	if(strcmp(search_equipm,equipm[17].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[17].name,equipm[17].price);
	}
	if(strcmp(search_equipm,equipm[18].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[18].name,equipm[18].price);
	}
	if(strcmp(search_equipm,equipm[19].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[19].name,equipm[19].price);
	}
	if(strcmp(search_equipm,equipm[20].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[20].name,equipm[20].price);
	}
	//if it don't match, it will display "Sorry. The Equipment you are searching is currently unavailable."
	if(strcmp(search_equipm,equipm[1].name)!=0 && strcmp(search_equipm,equipm[2].name)!=0 && strcmp(search_equipm,equipm[3].name)!=0 && strcmp(search_equipm,equipm[4].name)!=0 && strcmp(search_equipm,equipm[5].name)!=0 && strcmp(search_equipm,equipm[6].name)!=0 && strcmp(search_equipm,equipm[7].name)!=0 && strcmp(search_equipm,equipm[8].name)!=0 && strcmp(search_equipm,equipm[9].name)!=0 && strcmp(search_equipm,equipm[10].name)!=0 && strcmp(search_equipm,equipm[11].name)!=0 && strcmp(search_equipm,equipm[12].name)!=0 && strcmp(search_equipm,equipm[13].name)!=0 && strcmp(search_equipm,equipm[14].name)!=0 && strcmp(search_equipm,equipm[15].name)!=0 && strcmp(search_equipm,equipm[16].name)!=0 && strcmp(search_equipm,equipm[17].name)!=0 && strcmp(search_equipm,equipm[18].name)!=0 && strcmp(search_equipm,equipm[19].name)!=0 && strcmp(search_equipm,equipm[20].name)!=0)
	{
		printf("\t\tSorry. The Equipment you are searching is currently unavailable. \n"); 
	}
	printf("\n\n\t\tSearch another equipment?? \n\n");
	printf("\t\tEnter 1 to continue searching. \n");
	printf("\t\tEnter 2 to return to Main Menu. \n");
	printf("\n\t\t Enter your choice : ");
	scanf("%d",&choice);
	system("cls");
	}while(choice==1);
	
	if(choice==1)
	{
		system("cls");
		search_equipm_a();
	}
	if(choice==2)
	{
		system("cls");
		admin_menu();
	}
	if(choice!=1 && choice !=2)
	do
	{
		printf("\n\n\t\tPlease Enter a valid choice. \n");
		printf("\t\tEnter 1 to continue searching. \n");
		printf("\t\tEnter 2 to return to Main Menu. \n");
		printf("\n\t\tEnter your choice : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			system("cls");
			search_equipm_a();
		}
		if(choice==2)
		{
			system("cls");
			admin_menu();
		}
	}while(choice!=1 && choice!=2);
}

//function definition void add_equipm() to let admin add new equipment in the system and its price
void add_equipm()
{
	int count=1;
	int count_add=0;
	int i;
	int is=0;
	
	//count num of array occupied
	for(i = 1; i<=20; i++)
	{
		if(strcmp(equipm[i].name,"")!=0)
		{
			is++;
		}
	}
	//display number of equipment the system has currently 
	printf("\n\n\t\tnum of element is : %d \n",is);
	is=0;
	
	printf("\n\n\t\tAdd New Equipment\n");
	printf("\t\tPlease enter number of type of equipment to add [min 1 / max 12] : ");
	scanf("%d",&count_add);
	//using for loop statement, make sure the loop repeat not more than the number of equipment admin wants to add
	for(count=1;count<=count_add;count++)
	{
		printf("\n\n\t\tEnter Name of New Equipment %d : ",count);
		fflush(stdin);
		gets(equipm[7+count].name);
		printf("\n\t\tEnter Price of %s : RM ",equipm[7+count].name);
		scanf("%f",&equipm[7+count].price);
		printf("\n\t\tNew equipment updated: <%s> <RM %.2f> \n",equipm[7+count].name,equipm[7+count].price);
	}
	
	//count num of array occupied
	for(i = 1; i<=20; i++)
	{
		if(strcmp(equipm[i].name,"")!=0)
		{	
			is++;
		}
	}
	//display the new number of equipment the system has currently 
	printf("\n\n\t\tnum of element is : %d \n",is);
	is=0;
	
		printf("\n\t\tReturning to Main Menu. \n");
		printf("\n\t\t");
		system("pause");
		system("cls");
		admin_menu();
}


//start here is user part 
//function definition void user_menu1() to prompt user to choose he/she wants to create account or login
void user_menu1()
{
	int choice;
	int cont_choice;
	
	do
	{
    system("cls");
    system("color 3");
	printf("\n\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");                        
	printf("\t\t\t\t*                    /\\ /\\  ___  ___ _ __                   *\n"); 
	printf("\t\t\t\t*       ~~~~~~~~~~~~/ / \\ \\/ __|/ _ \\ '__|~~~~~~~~~~~~      *\n"); 
	printf("\t\t\t\t*                   \\ \\_/ /\\__ \\  __/ |                     *\n"); 
 	printf("\t\t\t\t*                    \\___/ |___/\\___|_|                     *\n");   
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t|                                                           |   \n");
 	printf("\t\t\t\t|   1. Create new account.                                  |   \n");
	printf("\t\t\t\t|   2. Login to an existing account.                        |   \n");
	printf("\t\t\t\t|   8. Change login mode.                                   |   \n");
	printf("\t\t\t\t|                                                           |   \n");
	printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n");
	printf("\t\tEnter your choice : ");
    scanf("%d",&choice);
    if(choice==1)
		{
			system("cls");
			create_user(); //function call create_user();
		}
		else if(choice==2)
		{
			system("cls");
			login_user(); //function call login_user();
		}
		else if(choice==8)
		{
			system("cls");
			modemenu(); //go back to login menu
		}
		else 
	    {
	    	printf("\n\n\t\tInvalid choice.\n");
	    	printf("\t\tYou have to login first to unlock full menu. \n");
	    	system("pause");
		}
    }while(choice!=1 && choice!=2 && choice!=8);
}

//function definition void user_menu() to display the main menu and show the available features
void user_menu()
{
	int choice;
	int cont_choice;
	
	do
	{
    system("cls");
    system("color 3");
    printf("\n\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");                        
	printf("\t\t\t\t*                    /\\ /\\  ___  ___ _ __                   *\n"); 
	printf("\t\t\t\t*       ~~~~~~~~~~~~/ / \\ \\/ __|/ _ \\ '__|~~~~~~~~~~~~      *\n"); 
	printf("\t\t\t\t*                   \\ \\_/ /\\__ \\  __/ |                     *\n"); 
 	printf("\t\t\t\t*                    \\___/ |___/\\___|_|                     *\n");   
    printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t|                                                           |   \n");
	printf("\t\t\t\t|   3. View available equipment.                            |   \n");
	printf("\t\t\t\t|   4. Search equipment.                                    |   \n");
	printf("\t\t\t\t|   5. Rent equipment.                                      |   \n");
	printf("\t\t\t\t|   6. Pay for equipment Rent.                              |   \n");
	printf("\t\t\t\t|   7. Back to login menu.                                  |   \n");
	printf("\t\t\t\t|   8. Exit.                                                |   \n");
	printf("\t\t\t\t|                                                           |   \n");
	printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n\n");
	printf("\t\tEnter your choice : ");
    scanf("%d",&choice);
    system("cls");
    //using switch case statement to determine user's choice
    switch(choice)
    {
		case 3: //view list of available equipment
			view_equipm_u();
			break;
		case 4: //search for a specific equipment
			search_equipm_u();
			break;
		case 5: //rent equipment
			rent_equipm();
			break;
		case 6: //pay for the rented equipment
			pay_rent();
			break;
		case 7:
			modemenu(); //go back to login menu
			break;
		case 8:
			exit(1);
			break;
		default: 
			printf("\n\n\t\tInvalid choice.\n\n");
	    	printf("\t\tEnter 1 to continue.\n");
	    	printf("\t\tEnter 2 to exit.\n\n");
	    	printf("\t\tChoice : ");
	    	scanf("%d",&cont_choice);	
	}
	}while(cont_choice==1);
	if(cont_choice!=1)
	{
		system("cls");
		printf("\n\n\t\tTq for visiting D6A SPORT EQUIPMENT RENTAL SYSTEM\n");
		exit(1);
	}	
}

//function definition void create_user() to create new user
void create_user()
{	
	FILE *create_u; //file pointer*create_u
   	create_u = fopen("user.txt","w"); //file pointer*create_u to open user.txt file as write mode
   	//check if file user.txt exist.
 	if(create_u == NULL)	
	{
		printf("File does not exist.\n");
		exit(1);
	}
	printf("\n\t\tNew account regisration ...... \n");
	//get input from user
	printf("\n\t\tEnter Username : ");
	fflush(stdin);
	gets(user.username);
	printf("\t\tEnter Password : ");
	fflush(stdin);
	gets(user.password);
	//write details to file
	fprintf(create_u,"\n%s %s\n",user.password,user.password);
	printf("\n\t\tRegistration successful !! \n\n");
	printf("\t\tProceed to Login...... \n\n");
	printf("\t\tPress any key to proceed to Login.\n");
	fflush(stdin);
	getch();
	//delay(1000);
	system("cls");
	//function call login_user();
	login_user(); 
	
}

//function definition void login_user() to login to user account
void login_user()
{	
	int again;

	FILE *check_u; //file pointer *check_u
	check_u = fopen("user.txt","r"); //file pointer *check_u to open user.txt file as read mode
	//move file cursor to begining
	rewind(check_u);
	//check if user.txt file exist
	if(check_u == NULL)	
	{
		printf("File doesn't exist.\n");
		exit(1);
	}
		
	printf("\n\n\t\tLogin as User...... \n");
	//get input from user
	printf("\n\t\tEnter Username : ");
	fflush(stdin);
	gets(user.check_username);	
	printf("\t\tEnter password : ");
	fflush(stdin);
	gets(user.check_password);	

	//to read until the end of the line
	while(!feof(check_u))
	{
		fscanf(check_u,"%s %s",&user.username,&user.password);
		if(strcmp(user.check_username,user.username)==0 && strcmp(user.check_password,user.password)==0)
		{
			printf("\n\t\tLogin successful \n");
		}
		else
		{
			do
			{
				printf("\n\t\tSorry wrong username / password \n\n ");
				printf("\t\tEnter 1 to try again.\n");
				printf("\t\tEnter 2 to create new account.\n");
				printf("\t\tEnter 3 to back to main menu.\n");
				printf("\n\t\tChoice : ");
				scanf("%d",&again);
				if(again==1)
				{
					printf("\t\tUsername : ");
					fflush(stdin);
					gets(user.check_username);	
					printf("\t\tPassword : ");
					fflush(stdin);
					gets(user.check_password);
				}
				if(again==2)
				{
					system("cls");
					create_user();
				}
				if(again==3)
				{
					system("cls");
					user_menu1();
				}	
			}while(strcmp(user.check_username,user.username)!=0 || strcmp(user.check_password,user.password)!=0);
			printf("\n\t\tLogin successful \n");
		}
		system("pause");
	}
	system("cls");
	//function call user_menu()
	user_menu();
}

//function definition void view_equipm_u() to let user viewavailable equipment and price
void view_equipm_u()  
{
	int count=0;
	int i=0;
	int is=0;
	
	//count num of array occupied
	for(i = 1; i<=20; i++)
	{
		if(strcmp(equipm[i].name,"")!=0)
		{
			is++;
		}
	}
	
	printf("\n\n\t\tAvailable Sports Equipments: \n");
	printf("\t\tEquipment\t\tPrice (RM)\n"); 
	//using for loop statement 
	//display the equipment and price number based on the number of array occupied 
	for(count=1;count<=is;count++)
	{
	printf("\t\t%d. %s\t\t%.2f\n",count, equipm[count].name,equipm[count].price);
	}
	printf("\n\n\t\t");
	system("pause");
	system("cls");
	user_menu();
}

//function definition void search_equipm_u() to let user search equipment and price
void search_equipm_u()
{
	int choice;
	char search_equipm[30];
	int count=0;
	int i=0;
	int is=0;
	
	do
	{
	printf("\n\n\t\tSearch An Equipment's Price': \n");
	printf("\t\tEnter the equipment you would like to search [Warning!! : First letter need to be Uppercase](Example: Badminton, Basketball, etc...): \n");
	fflush(stdin);
	printf("\n\t\t");
	gets(search_equipm);  //get input from user
	
	//if it match, then it will display the price 
	if(strcmp(search_equipm,equipm[1].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[1].name,equipm[1].price);
	}
	if(strcmp(search_equipm,equipm[2].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[2].name,equipm[2].price);
	}
	if(strcmp(search_equipm,equipm[3].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[3].name,equipm[3].price);
	}
	if(strcmp(search_equipm,equipm[4].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[4].name,equipm[4].price);
	}
	if(strcmp(search_equipm,equipm[5].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[5].name,equipm[5].price);
	}
	if(strcmp(search_equipm,equipm[6].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[6].name,equipm[6].price);
	}
	if(strcmp(search_equipm,equipm[7].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[7].name,equipm[7].price);
	}
	if(strcmp(search_equipm,equipm[8].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[8].name,equipm[8].price);
	}
	if(strcmp(search_equipm,equipm[9].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[9].name,equipm[9].price);
	}
	if(strcmp(search_equipm,equipm[10].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[10].name,equipm[10].price);
	}
	if(strcmp(search_equipm,equipm[11].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[11].name,equipm[11].price);
	}
	if(strcmp(search_equipm,equipm[12].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[12].name,equipm[12].price);
	}
	if(strcmp(search_equipm,equipm[13].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[13].name,equipm[13].price);
	}
	if(strcmp(search_equipm,equipm[14].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[14].name,equipm[14].price);
	}
	if(strcmp(search_equipm,equipm[15].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[15].name,equipm[15].price);
	}
	if(strcmp(search_equipm,equipm[16].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[16].name,equipm[16].price);
	}
	if(strcmp(search_equipm,equipm[17].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[17].name,equipm[17].price);
	}
	if(strcmp(search_equipm,equipm[18].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[18].name,equipm[18].price);
	}
	if(strcmp(search_equipm,equipm[19].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[19].name,equipm[19].price);
	}
	if(strcmp(search_equipm,equipm[20].name)==0)
	{
		printf("\n\n\t\tEquipment:\tPrice(RM)\n");
		printf("\t\t%s\t%.2f",equipm[20].name,equipm[20].price);
	}
	//if it don't match, it will display "Sorry. The Equipment you are searching is currently unavailable." //enter the name of equipment 
	if(strcmp(search_equipm,equipm[1].name)!=0 && strcmp(search_equipm,equipm[2].name)!=0 && strcmp(search_equipm,equipm[3].name)!=0 && strcmp(search_equipm,equipm[4].name)!=0 && strcmp(search_equipm,equipm[5].name)!=0 && strcmp(search_equipm,equipm[6].name)!=0 && strcmp(search_equipm,equipm[7].name)!=0 && strcmp(search_equipm,equipm[8].name)!=0 && strcmp(search_equipm,equipm[9].name)!=0 && strcmp(search_equipm,equipm[10].name)!=0 && strcmp(search_equipm,equipm[11].name)!=0 && strcmp(search_equipm,equipm[12].name)!=0 && strcmp(search_equipm,equipm[13].name)!=0 && strcmp(search_equipm,equipm[14].name)!=0 && strcmp(search_equipm,equipm[15].name)!=0 && strcmp(search_equipm,equipm[16].name)!=0 && strcmp(search_equipm,equipm[17].name)!=0 && strcmp(search_equipm,equipm[18].name)!=0 && strcmp(search_equipm,equipm[19].name)!=0 && strcmp(search_equipm,equipm[20].name)!=0)
	{
		printf("\t\tSorry. The Equipment you are searching is currently unavailable. \n");
	}
	printf("\n\n\t\tSearch another equipment?? \n\n");
	printf("\t\tEnter 1 to continue searching. \n");
	printf("\t\tEnter 2 to return to Main Menu. \n");
	printf("\n\t\tEnter your choice : ");
	scanf("%d",&choice);
	system("cls");
	}while(choice==1);
	
	if(choice==1)
	{
		system("cls");
		search_equipm_u();
	}
	if(choice==2)
	{
		system("cls");
		user_menu();
	}
	if(choice!=1 && choice !=2)
	do
	{
		printf("\n\n\t\tPlease Enter a valid choice. \n\n");
		printf("\t\tEnter 1 to continue searching. \n");
		printf("\t\tEnter 2 to return to Main Menu. \n\n");
		printf("\n\t\tEnter your choice : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			system("cls");
			search_equipm_u();
		}
		if(choice==2)
		{
			system("cls");
			user_menu();
		}
	}while(choice!=1 && choice!=2);
}

//function definition void rent_equipm() to let user choose the equipment to rent
void rent_equipm()
{
	int count=1;
	int choice,again;
	int quantity;
	float price=0;
	float total_price=0;
	char add;
	int i;
	int is=0;
	//count num of array occupied
	for(i = 1; i<=20; i++)
	{
		if(strcmp(equipm[i].name,"")!=0)
		{
			is++;
		}
	}
	
	printf("\n\n\t\tReady for some sports? \n");
	printf("\t\tStart by renting equipments from us!\n");
	printf("\t\tLowest Price with Quality assured!!\n");
	do
	{
	printf("\n");
	printf("\t\tWhat would you like to play?\n\n");
	printf("\t\tName\tPrice(RM)\n");
	//using for loop statement
	//display the quipment not more than the number of array occupied
	for(count=1;count<=is;count++)
	{
		printf("\t\t%d. %s %.2f \n",count,equipm[count].name, equipm[count].price);
	}
	printf("\n\t\tEnter your desired choice : ");
	scanf("%d",&choice);
	
	if(choice>0 && choice<=is)
	{
		printf("\n\t\tCurrently selected : %s \n",equipm[choice].name);
		printf("\n\t\tEnter quantity to rent : ");
		scanf("%d",&quantity);
		//calculating the price for the total sellected item and quantity
		price=equipm[choice].price*quantity;
		//calculating the total price of the rent
		total_price=total_price+price;
		printf("\n\t\tItem's price will be : RM %.2f\n",price);
		printf("\n\t\tDo you want to add another item? [Y/N] : ");
		fflush(stdin);
		scanf("%c",&add);
		printf("\t\t");
		system("cls");
	}
	else
	{
		printf("\n\n\t\tPlease Enter a valid choice. \n\n");
		printf("\t\tEnter 1 to continue.\n");
		printf("\t\tEnter 2 to return to Main Menu. \n\n");
		printf("\n\t\tEnter your choice : ");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\t\tEnter your desired choice : ");
			scanf("%d",&choice);
			printf("\n\t\tCurrently selected : %s \n",equipm[choice].name);
			printf("\n\t\tEnter quantity to rent : ");
			scanf("%d",&quantity);
			//calculating the price for the total sellected item and quantity
			price=equipm[choice].price*quantity;
			//calculating the total price of the rent
			total_price=total_price+price;
			printf("\n\t\tItem's price will be : RM %.2f\n",price);
			printf("\n\t\tDo you want to add another item? [Y/N] : ");
			fflush(stdin);
			scanf("%c",&add);
			printf("\t\t");
			system("cls");
		}
		if(again==2)
		{
			system("cls");
			user_menu();
		}
	}
	}while(add=='y' || add=='Y');
	
	printf("\n\t\t");
	system("pause");
	system("cls");
	printf("\n\n\t\tPlease pay deposit of RM150.");
	printf("\n\n\t\t");
	system("pause");
	system("cls");
	printf("\n\n\t\tThank you for paying deposit.\n\n");
	printf("\t\tKindly enjoy your game first.\n\n ");
	printf("\t\tThen, kindly return the equipment and pay the rent after you finished your game or your deposit of RM 150 will be forfeited.\n\n");
	printf("\t\tTotal rent for this session is : RM %.2f\n",total_price); //displaying the total price of the rent
	user.total_price=total_price;
	user.member_points=user.total_price*10;
	printf("\n\t\t");
	system("pause");
	system("cls");
	//function call pay_rent();
	pay_rent();
}

//function definition void pay_rent() to let user pay for the equipment rented
void pay_rent()
{
	system("color 6");
	printf("\n\n\n\t                     ----------------------------------------------------------------------------------\n");
	printf("\t                     |               ______ _____ _____  _____ ___________ _____                      |\n");
	printf("\t                     |              | ___ \\  ___/  __ \\|  ___|_   _| ___ \\_   _|                      |\n");
	printf("\t                     |              | |_/ / |__ | /  \\/| |__   | | | |_/ / | |                        |\n");
	printf("\t                     |              |    /|  __|| |    |  __|  | | |  __/  | |                        |\n");
	printf("\t                     |              | |\\ \\| |___| \\__/\\| |___ _| |_| |     | |                        |\n");
	printf("\t                     |              \\_| \\_\\____/ \\____/\\____/ \\___/\\_|     \\_/                        |\n"); 
	printf("\t                     ----------------------------------------------------------------------------------\n"); //30
	printf("\t                     |                                                                                |\n");
	printf("\t                     |                                                                                |\n");  
	printf("\t                     |                                Total Price : RM %.2f                           |\n",user.total_price);
	printf("\t                     |                        Sport Points Earned : %d                                |\n",user.member_points);
	printf("\t                     |                                                                                |\n");
	printf("\t                     |                                                                                |\n");
	printf("\t                     |                     *Thank you for visiting our system.*                       |\n");
	printf("\t                     |      **Don't forget to collect your deposit of RM 150 at the counter!**        |\n");
	printf("\t                     |                          ***Have a nice day!***                                |\n");
	printf("\t                     |                                                                                |\n");
	printf("\t                     |                                                                                |\n");
	printf("\t                     \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/ \n");      
	
	printf("\n\t\t");
	system("pause");
	//function call RestoreOutputWindow(); to restore the cmd window to when program execution ends
	RestoreOutputWindow();
	exit(1);
	
}

//function to auto maximize cmd windows when program is executed
void MaximizeOutputWindow()
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}

//function to auto restore cmd windows when program execution is completed
void RestoreOutputWindow()
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_RESTORE); // this mimics clicking on its' maximize for a second time, which puts it back to normal
}
