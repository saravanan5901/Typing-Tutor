#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define CLEAR system("cls");

typedef struct userd
{
			char name[100];
        	char password[100];
}userstruct;

void welcome();							//flow of control: main()->welcome()
int mainmenu();							//						  ->newuser()---------------|			 ->practice()--->statistics---------------->(again)account()
int user();								//				->user()<							->account()<-->game()--------------------------------|
int newuser();							//->mainmenu()<			  ->loginto()->login()------|			 
int login();							//				->exit											
int account();							//
int game();
int practice();
int loginto();
int lesson();
void statistics();

void welcome()
{
        	char topic_text[2000] = "\
	                                        000000  00  00  00000   000000  00  00   00000       \n\r\
	                                          00     0000   00  00    00    00   0  00           \n\r\
	                                          00      00    00000     00    0 0  0  00 000       \n\r\
	                                          00      00    00        00    0  0 0  00  00       \n\r\
	                                          00      00    00      000000  00  00   00000       \n\r\
	                                                                                        \n\r\
	                                        000000  00  00  000000  000000  00000               \n\r\
	                                          00    00  00    00    00  00  00  00              \n\r\
	                                          00    00  00    00    00  00  00000               \n\r\
	                                          00    00  00    00    00  00  00  00              \n\r\
	                                          00    000000    00    000000  00   00             \
										\n\n\n\n\n\n\r                                                  BY SANJAY AND SARAVANAN \n";
	        CLEAR
	        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%s", topic_text);
		    sleep(3);
}

int mainmenu()
{
label1:     CLEAR

			int option;

        	printf("\t\t\t\t\t\t\t\tT Y P I N G  T U T O R\n");
			printf("\n\n\n\n\t\t\t\t\t\t\t\t1]...SELECT USER");
        	printf("\n\t\t\t\t\t\t\t\t2]...QUIT\n");
  			option = getch();
        	if (option == '1')
        	{
	                user();
	        }
	        else if (option == '2')
	        {
	                exit(0);
	        }
	        else
	        {
	                printf("\n userse 1 or 2 only to choose \n");
    	            sleep(2);
                	goto label1;
        	}
}
	
int user()
{
label2:     CLEAR

	        int option;
	
	        printf("\t\t\t\t\t\t\t\tT Y P I N G  T U T O R\n");
	        printf("\n\n\n\n\t\t\t\t\t\t\t\t1]...NEW USER");
	        printf("\n\t\t\t\t\t\t\t\t2]...LOGIN");
	        printf("\n\t\t\t\t\t\t\t\t0]...back\n");
	        option = getch();
	        if (option == '0')
	        {
	                mainmenu();
	        }
	        else if (option == '1')
	        {
	                newuser();
	        }
	        else if (option == '2')
	        {
    	            loginto();
        	}
        	else
        	{
	                printf("\n use 1 or 2 only to choose \n");
	                sleep(2);
	                goto label2;
	        }
}

int newuser()
{
label3:     CLEAR
	        printf("\t\t\t\t\t\t\t\tT Y P I N G  T U T O R\n");
			printf("\t\t\t\t\t\t\t\ttype back to return\n");
	
			FILE *filepointer;
	        userstruct user1;
	
	        filepointer = fopen("Userdata.txt","a+");
	        printf("\nEnter your name:");
	        scanf("%s",user1.name);
	        if (!(strcmp(user1.name,"back")))
	        {
		        	user();
			}
	
        	printf("\nEnter your password:");
        	scanf("%s", user1.password);
        	if (!(strcmp(user1.password,"back")))
        	{
		        	user();
			}
	        if (!(strcmp(user1.name,user1.password)))
	        {
	                printf("\n The password is too simple!!!");
	                sleep(2);
        	        goto label3;
        	}
        	if (strlen(user1.password) < 5)
        	{
		            printf("\n The password is too simple!!!");
	                sleep(2);
	                goto label3;
	        }

	        fwrite(&user1,sizeof(userstruct),1,filepointer);
	        fclose(filepointer);
			account(user1);
}

int loginto()
{
label4:     CLEAR
			printf("\t\t\t\t\t\t\t\tT Y P I N G  T U T O R\n");

            FILE *filepointer;
            int option , i = 0 ;
            userstruct user1[100];

            filepointer = fopen("Userdata.txt","r+");
  			while (fread(&user1[i],sizeof(userstruct),1,filepointer))
  			{
	        		printf("\n\n\n\n\t\t\t\t\t\t\t\t%d]...%s", i+1, user1[i].name);
    	            i++;
            }
            printf("\n\n\n\n\t\t\t\t\t\t\t\t0]...press 0 to go back");
			printf("\nSelect the user:");
            option = getch();
            if (option == '0')
            {
                	user();
			}
			else if (option < '0' || option > '9')
			{
					printf("\nselect by pressing the numbers");
                    sleep(1);
                    goto label4;
			}
			else
			{
					login(user1[(option-'0')-1]);
			}
}

int login(userstruct user1)
{
label5:     CLEAR

			char inputpassword[100];

            printf("\t\t\t\t\t\t\t\tT Y P I N G  T U T O T");
            printf("\n\t\t\t\t\t\t\t\t[type back to return]");
            printf("\n\n\n\n\t\t\t\t\t\t\t\tUSERNAME:%s",user1.name);
            printf("\n\t\t\t\t\t\t\t\tPassword:");
            scanf("%s", inputpassword);
            if (!strcmp(inputpassword,user1.password))
            {
            		account(user1);
            }
            else if (!strcmp(inputpassword,"back"))
            {
            	  	loginto();
			}
            else 
            {
                    printf("\nWRONG PASSWORD!!!");
					sleep(2);
                    goto label5;
            }
}

int account(userstruct user1)
{
label6:     CLEAR
        	printf("\n\t\t\t\t\t\t\t\tT Y P I N G  T U T O R\n");
	
	        int option;
	
	        printf("\n\n\t\t\t\t\t\t\t\t%s",user1.name);
	        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t1]...PRACTICE");
	        printf("\n\t\t\t\t\t\t\t\t2]...GAMES");
	        printf("\n\t\t\t\t\t\t\t\t3]...LOGOUT\n");
	        option = getch();
	        if (option == '1')
	        {
	                practice(user1);
	        }
	        else if (option == '2')
	        {
		                if(game() == 5)
		                {
				                	goto label6;
						}
	        }
	        else if (option == '3')
	        {
			            user();
	        }
	        else
        	{
	                    printf("\nUse 1 to 3 only");
	                    sleep(2);
	                    goto label6;
	        }
}

int practice(userstruct user1)
{
			CLEAR
			printf("\n\t\t\t\t\t\t\t\tT Y P I N G  T U T O R\n");
			printf("\n\n\t\t\t\t\t\t\t\t%s\n\n\n",user1.name);
	
			int lesson_number,option;
	
			for (lesson_number=1 ; lesson_number<9 ; lesson_number++)
			{
					printf("\t\t\t\t\t\t\t\t%d]...lesson.%d\n", lesson_number, lesson_number);
			}
			printf("\t\t\t\t\t\t\t\t0]...press 0 for back\n");
			option = getch();
			switch (option)
			{
					case '0': account(user1);
								break;
					case '1': lesson(user1,"lesson1.txt");
								break;
					case '2': lesson(user1,"lesson2.txt");
								break;
					case '3': lesson(user1,"lesson3.txt");
								break;
					case '4': lesson(user1,"lesson4.txt");
								break;
					case '5': lesson(user1,"lesson5.txt");
								break;
					case '6': lesson(user1,"lesson6.txt");
								break;
					case '7': lesson(user1,"lesson7.txt");
								break;
					case '8': lesson(user1,"lesson8.txt");
								break;		
			}
}

int lesson(userstruct user1,char lesson_name[])
{
			CLEAR
	
			long int final_time, initial_time;
			char character_from_file;
	        int number_of_keys_pressed = 0, flag_variable;
			char character_from_user;
			int number_of_mistaked_keys = 0;
	
			printf("\n\t\t\t\t\t\t\t\tT Y P I N G  T U T O R\n");
	        printf("\n\n\t\t\t\t\t\t\t\t%s\n\n", user1.name);
	
			FILE *filepointer;
	
	        filepointer = fopen(lesson_name,"r");
	        character_from_file = fgetc(filepointer);
	        while (character_from_file!='$')												//every lesson file are terminated with '$' character
	        {																			//printing the whole lesson
		        	printf("%c", character_from_file);
	    	    	character_from_file = fgetc(filepointer);
			}
			
			rewind(filepointer);
			
			printf("\n\n\n");
			character_from_file = fgetc(filepointer);
			initial_time = clock();
	
			while (character_from_file != '$')											//terminates after the lesson completes
			{
					while (character_from_file != '\n')										//iterates for each line i.e.,for each '\n' character
					{
							character_from_user = getch();
							if ((int)character_from_user == 27)													//if user presses esc key, the practice is over
							{
									goto label7;
							}
							if (character_from_user == character_from_file)					//if the user presses the correct key ,it is printed
							{
									flag_variable = 0;
									number_of_keys_pressed++;
									printf("%c",character_from_user);
							}	
							else
							{
									flag_variable = 1;
									number_of_keys_pressed++;
									number_of_mistaked_keys++;
							}		
							if (flag_variable == 0)
							{
									character_from_file = fgetc(filepointer);
									if (character_from_file == '$')
									{
											goto label7;
									}
							}
					}
					
					if (character_from_user = getch())
					{
							printf("\n");
					}
					character_from_file = fgetc(filepointer);
			}
label7: 	final_time = clock();
			fclose(filepointer);
			statistics(user1 ,initial_time ,final_time ,number_of_keys_pressed ,number_of_mistaked_keys );
}

void statistics(userstruct user1 ,long int initial_time ,long int final_time ,int number_of_keys_pressed ,int number_of_mistaked_keys )
{
			CLEAR
			printf("\n\t\t\t\t\t\t\t\tT Y P I N G  T U T O R\n");
    		printf("\n\n\t\t\t\t\t\t\t\t%s\n\n", user1.name);
			int timetaken;
			timetaken = (double)((final_time - initial_time)/CLOCKS_PER_SEC);
	
			printf("\nTime taken by you =%d", timetaken);	
			
			double keys_per_minute;
			keys_per_minute = (double)(number_of_keys_pressed/(timetaken*0.0166));
			
			printf("\nYour speed is(in keys per minute)=%0.2lf", keys_per_minute);
		
			printf("\nYour speed is(in words per minute(approx))=%0.2lf", keys_per_minute/5.0);
			
			double accuracy;
			accuracy = 100-((double)number_of_mistaked_keys/number_of_keys_pressed*100);
	
			printf("\nYour accuracy is =%0.2lfpercent", accuracy);
			getch();
			account (user1);
}


int game()
{  
	       
			int life=3 ,random_letter ,i ,j ;
			char input;
			long int initial_time , final_time ;
			int time_taken=0;
			int score = 0;
	
label8: 	srand(time(0));
			random_letter = 65+(rand() % (90-65 + 1));							//generates a number between 65 to 90 i.e., A to Z
label9:		initial_time = clock();
			for (i = 0 ; i <  2 ; i++)	
			{
					CLEAR
					printf("life=%d", life);	
					for(j = 0 ; j < i ; j++)
					{
						   	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		        	}
					printf("\t\t\t\t\t\t\t\t%c\n\t\t\t\t\t\t\t\t", random_letter);
					sleep(1);
			}
			CLEAR
			printf("\t\t\t\t\t\t\t\t");
			input = getch();
			final_time = clock();
			
			time_taken = 0;
			time_taken = (double)((final_time - initial_time)/CLOCKS_PER_SEC);
			if (time_taken > 2)
			{
					goto label10;
			}
			if (input == random_letter)
			{
					score = score + 2;
					goto label8;
	        }
	        else
			{
label10:			life--;
	    			score--;
					if (life == 0)
		    		{
			 				printf("game over!!!!!!!!!!!!!!!!!!!!!!!");
							sleep(2);
							CLEAR
							printf("\n\n\n\n\n\t\t\t\tYour score is::::::%d ", score);
							getch();
			    			return 5;	
					}
			     	goto label9;	
			}
}

int main()
{
		welcome();
        mainmenu();
        return 0;
}

