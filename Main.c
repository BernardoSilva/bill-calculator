#include <stdio.h>
#include <ctype.h>


const char OPTION_NEW_ROW = '1';
const char OPTION_DISPLAY_RESULT = '2';
const char OPTION_EXIT = '0';
const char OPTION_EXIT_CONFIRM = 'y';
const char OPTION_EXIT_CANCEL = 'n';
const int IVA = 23; // value in % (percentage)

/* function declaration goes here.*/
int isValidMainMenuOption( char option );
int isValidExitOption( char option );
int askExitConfirmation();
void drawMainMenu();
void askBillValues(float *totalBillWater, float *totalBillWaste, float *totalBillWaterWaste, float *totalBillTRH);
void displayResults(float totalBillWater, float totalBillWaste, float totalBillWaterWaste, float totalBillTRH, int numUsers);




int main()
{
    char option, exitConfirmation;
    int numUsers = 0;
    float totalBillWater = 0, totalBillWaste = 0, totalBillWaterWaste = 0, totalBillTRH = 0;
    
    while ( option != OPTION_EXIT ) {
        option = ' ';
        exitConfirmation = ' ';
        do {
            drawMainMenu();
            scanf(" %c", &option);
            option = tolower(option);
        } while ( isValidMainMenuOption( option ) == 0);
        
        if(option == OPTION_EXIT) {
            do {
                printf("\nTem a certeza que quer sair do programa? (S)im (N)ao\n");
                scanf( " %c", &exitConfirmation );
                exitConfirmation = tolower( exitConfirmation );
            } while( isValidExitOption( exitConfirmation ) != 1 );
            
            if( exitConfirmation  == OPTION_EXIT_CANCEL) {
                 option = ' '; // cancel the exit option
            }
        }
        
        switch (option) {
            case OPTION_NEW_ROW:
                    askBillValues(&totalBillWater, &totalBillWaste, &totalBillWaterWaste, &totalBillTRH);
                    numUsers++;
                break;
                
            case OPTION_DISPLAY_RESULT:
                    displayResults(totalBillWater, totalBillWaste, totalBillWaterWaste, totalBillTRH, numUsers);
                break;
                
            case OPTION_EXIT:
                    printf("\n\nObrigado por usar o nosso programa!\n");
                break;
        }
    }
    return 0;
}

/**
 * Validate the user option input for the main menu
 * this function return 2 possible int values:
 *  0 - invalid
 *  1 - valid
 */
int isValidMainMenuOption( char option ){
    switch (option) {
        case OPTION_EXIT:
        case OPTION_NEW_ROW:
        case OPTION_DISPLAY_RESULT:
                return 1;
            break;
        
        default: 
                return 0; 
            break;
    }
    
    printf("\nOpcao invalida!\n\n");
    return 0;
}

/**
 * Validate the user option input for the main menu
 * this function return 2 possible int values:
 *  0 - invalid
 *  1 - valid
 */
int isValidExitOption( char option ) {
    switch (option) {
        case OPTION_EXIT_CONFIRM:
        case OPTION_EXIT_CANCEL:
                return 1;
            break;
        default:
                return 0;
            break;
    }
}

/**
 * Function just to draw the main Menu
 */
void drawMainMenu() {
    printf("\n\n*************************************\n");
    printf("* 1 - Introduzir dados de faturacao *\n");
    printf("* 2 - Apresentar resultados         *\n");
    printf("* 0 - Terminar programa             *\n");
    printf("*************************************\n");
    printf("Selecione uma opcao: ");
}

/**
 * Function to ask the user bill values for each specific entity
 */
void askBillValues(float *totalBillWater, float *totalBillWaste, float *totalBillWaterWaste, float *totalBillTRH) {
    float tmpBillValue = 0.0;

    do {
        printf("Introduza o a conta da agua?");
        scanf("%2f", &tmpBillValue);
    } while (tmpBillValue <= 0 );
    *totalBillWater += tmpBillValue;
    tmpBillValue = 0;

    do {
        printf("Introduza o a conta de residuos?");
        scanf("%2f", &tmpBillValue);
    } while (tmpBillValue <= 0 );
    *totalBillWaste += tmpBillValue;
    tmpBillValue = 0;

    do {
        printf("Introduza o a conta de drenagem de aguas residuais?");
        scanf("%2f", &tmpBillValue);
    } while (tmpBillValue <= 0 );
    *totalBillWaterWaste += tmpBillValue;
    tmpBillValue = 0;

    do {
        printf("Introduza o a conta TRH?");
        scanf("%2f", &tmpBillValue);
    } while (tmpBillValue <= 0 );
    *totalBillTRH += tmpBillValue;
    tmpBillValue = 0;
}

/**
 * Display the bills average value, the total bill and the total taxed
 */
void displayResults(float totalBillWater, float totalBillWaste, float totalBillWaterWaste, float totalBillTRH, int numUsers) {
    float total = totalBillWater + totalBillWaste + totalBillWaterWaste + totalBillTRH;
    float totalTaxed = total + (total*(IVA/100.0)); 

    printf("\nAgua \t\t\t\t %.2f	\n", totalBillWater/numUsers);
    printf("Residuos \t\t\t %.2f \n", totalBillWater/numUsers);
    printf("Drenagem aguas residuais \t %.2f \n", totalBillWater/numUsers);
    printf("TRH \t\t\t\t %.2f \n", totalBillWater/numUsers);

    printf("\n----------------------------------------------\n");

    printf("Total s/ IVA \t\t\t %.2f \n", total );
    printf("Total c/ IVA \t\t\t %.2f \n", totalTaxed );
}
