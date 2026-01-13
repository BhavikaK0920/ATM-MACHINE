
 #include <stdio.h>

void main() 
{
    // Initializing arrays for 5 accounts 
    int pins[5] = {1111, 2222, 3333, 4444, 5555};
    float balances[5] = {20000.50, 25000.00, 55000.75, 10000.00, 50000.25};
    
    int pin, choice, Index = -1,cnt =0;
    float amount;
    int i, authenticated = 0;

    printf("--- BANGALORE INSTITUTE OF TECHNOLOGY ATM --- \n");

    while(cnt<3)
    {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &pin);
        for (i = 0; i < 5; i++)  // Validation loop to check if PIN exists in the array
        {
            if (pin == pins[i]) 
            {
                authenticated = 1;
                Index = i; // Store the index of the matched user
                break;
            }
        }
        if(Index==-1)
        printf("Invalid PIN. Try again.\nNumber of chances left : %d",(3-1-cnt));
        if(authenticated!=1)
        cnt++;
        else
        break;
    }

    if (authenticated!=1) 
    {
        printf("Invalid PIN. Access Denied.\n");
    }
if(authenticated==1)
{
    printf("\nLogin Successful, Welcome! \nUser %d\n", Index + 1);
    printf("\n1. Check Balance\n2. Deposit\n3. Withdraw\n");
    printf("Select Option: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1: printf("Current Balance: Rs. %.2f\n", balances[Index]);
                break;
                
        case 2: printf("Enter Deposit Amount: ");
                scanf("%f", &amount);
                if (amount > 0) 
                {
                    balances[Index] += amount;
                    printf("Updated Balance: Rs. %.2f\n", balances[Index]);
                } 
                else 
                    printf("Invalid Amount.\n");
                break;  
                
        case 3: printf("Enter Withdrawal Amount: ");
                scanf("%f", &amount);
                if (amount > balances[Index]) {
                    printf("Error: Insufficient Balance!\n");
                } else if (amount <= 0) {
                    printf("Invalid Amount.\n");
                } else {
                    balances[Index] -= amount;
                    printf("Withdrawal Successful. \nRemaining: Rs. %.2f\n", balances[Index]);
                }
                break;
        default: printf("Invalid Choice.\n");
                 break;
    }
    printf("Thank you for using our ATM.\nHave a nice day!!\n");
    
}
}