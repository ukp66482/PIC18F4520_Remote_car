#include <xc.h>
#include <pic18f4520.h>

char mystring[20];
int lenStr = 0;

void UART_INIT(){
    TRISCbits.TRISC6 = 1; //TX set 
    TRISCbits.TRISC7 = 1; //RX set               
    
    // Setting 9600 bit/s baud rate
    TXSTAbits.SYNC = 0; //Asynchronous transmission           
    BAUDCONbits.BRG16 = 0;          
    TXSTAbits.BRGH = 1;
    SPBRG = 51;      
    
    //Serial enable
    RCSTAbits.SPEN = 1; //Enable serial port
    
    PIR1bits.TXIF = 1; //Set when TXREG empty
    PIR1bits.RCIF = 0; //Setting when reception is complete 
    
    TXSTAbits.TXEN = 1; //Enable transmission Tx           
    RCSTAbits.CREN = 1; //Enable receive Rx             
    
    //setting TX/RX interrupt
    PIE1bits.TXIE = 0; //Disable transmission interrupt      
    IPR1bits.TXIP = 0;             
    PIE1bits.RCIE = 1; //Enable receiving priority              
    IPR1bits.RCIP = 0; //Set receiving low priority interrupt   
    
    }

void UART_Write(unsigned char data){ //Output on terminal
    while(!TXSTAbits.TRMT); //TRMT which is set when the TSR empty
    TXREG = data; //write to TXREG will send data 
}

void UART_Write_Text(char* text){ // Output on Terminal, limit:10 chars
    for(int i=0;text[i]!='\0';i++)
        UART_Write(text[i]);
}

void ClearBuffer(){
    for(int i = 0; i < 10 ; i++)
        mystring[i] = '\0';
    lenStr = 0;
}

void MyusartRead(){
    mystring[lenStr] = RCREG;
    UART_Write(mystring[lenStr]);
    lenStr++;
    lenStr %= 10;
    return ;
}

char *GetString(){
    return mystring;
}


void __interrupt(low_priority)LOW_ISR(void){
    if(PIR1bits.RCIF)
    {
        if(RCSTAbits.OERR)
        {
            CREN = 0;
            Nop();
            CREN = 1;
        }     
        MyusartRead();
        //PIR1bits.RCIF = 0; cleared when RCREG is read automatically
    }
    return;
}