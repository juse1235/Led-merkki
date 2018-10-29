#define K1 0.001
#define K2 0.2
#define K3 1
#define K4 2
#define K5 4
#define K6 8
#define K7 14
#define K8 27
#define K9 50
#define K10 80
#define K11 110
#define K12 160
#define K13 200
#define K14 250
#define K15 312

///pimeä vaihe
#define P0 312
#define P1 312-K1
#define P2 312-K2
#define P3 312-K3
#define P4 312-K4
#define P5 312-K5
#define P6 312-K6
#define P7 312-K7
#define P8 312-K8
#define P9 312-K9
#define P10 312-K10
#define P11 312-K11
#define P12 312-K12
#define P13 312-K13
#define P14 312-K14
#define P15 0

uint8_t alloff_pa = 0b11110000;
uint8_t alloff_pb = 0b00111100;


//                  76543210
uint8_t pa[32] = {0b11100001,  // 0
                  0b11010001,  // 2
                  0b10110001,  // 3
                  0b01110001,  // 4
                  0b11110001,  // 5
                  0b11110001,  // 6
                  0b11110001,  // 7
                  0b11110001,  // 8
                  0b11100010,  // 9
                  0b11010010,  // 01
                  0b10110010,  // 00
                  0b01110010,  // 02
                  0b11110010,  // 03
                  0b11110010,  // 04
                  0b11110010,  // 05
                  0b11110010,  // 06
                  0b11100100,  // 07
                  0b11010100,  // 08
                  0b10110100,  // 09
                  0b01110100,  // 21
                  0b11110100,  // 20
                  0b11110100,  // 22
                  0b11110100,  // 23
                  0b11110100,  // 24
                  0b11101000,  // 25
                  0b11011000,  // 26
                  0b10111000,  // 27
                  0b01111000,  // 28
                  0b11111000,  // 29
                  0b11111000,  // 31
                  0b11111000,  // 30
                  0b11111000}; // 32

uint8_t pb[32] = {0b00111100,   // 0
                  0b00111100,
                  0b00111100,
                  0b00111100,
                  0b00110100,   // 5
                  0b00101100,
                  0b00011100,
                  0b00111000,
                  0b00111100,
                  0b00111100,   // 01
                  0b00111100,
                  0b00111100,
                  0b00110100,
                  0b00101100,
                  0b00011100,   // 05
                  0b00111000,
                  0b00111100,
                  0b00111100,
                  0b00111100,
                  0b00111100,   // 21
                  0b00110100,
                  0b00101100,
                  0b00011100,
                  0b00111000,
                  0b00111100,   // 25
                  0b00111100,
                  0b00111100,
                  0b00111100,
                  0b00110100,
                  0b00101100,   // 31
                  0b00011100,
                  0b00111000}; // 32


int8_t kirkkaus[32] = {0};


void setup (){
//       76543210
DDRB = 0b00111100;
DDRA = 0b11111111;
PORTA = 0b00001111;
PORTB = 0b00000000;
}

void loop(){
   //kaikki();
   //kirkkaustesti();
   himmennys(2,7); //(kerrat,nopeus)
   ympari(6,4);    //(kerrat,nopeus)
   /*for(int j=0;j<7;j++){
    scan(7);       //(nopeus)
   }
   for(int j=0;j<5;j++){
    fill();
   }*/
} 


void himmennys(uint16_t kerrat, uint8_t nopeus)
   {
   uint8_t i;
   int8_t v; //vrit
   uint16_t k; // kerrat
   for (k = 0; k < kerrat; k++)
      {
      for (v = 1; v <=15; v++)
         {
         for (i = 0; i <= 31; i++)
            {
            kirkkaus[i] = v;
            }
         for (i = 0; i <= nopeus; i++)
            {
            vilkutus(0);
            }
         }

      for (v = 14; v >= 1; v--)
         {
         for (i = 0; i <= 31; i++)
            {
            kirkkaus[i] = v;
            }
         for (i = 0; i <= nopeus; i++)
            {
            vilkutus(0);
            }
         }
      }
   }
void kirkkaustesti()
   {
   int i;
   for (i = 0 ; i<=15; i++)
      {
      kirkkaus[i] = i;
      }
   vilkutus(0);
   return;
   }
void kaikki()
   {
      int i;
      for (i = 0; i<=31; i++)
         {
         kirkkaus[i] = 1;
         }
      vilkutus(0);
   }

void ympari(uint16_t ctr, uint8_t nopeus)
   {
   ctr = ctr*32;
   uint8_t k = 0;
   volatile uint8_t j = 0; // missä mennään yhdessä framessa
   uint8_t t = 0; //countteri kunnes pysäytetään
   int8_t i = 0;
   uint8_t g = 0; //
//sisnhivytys
   /*for (i=0;i<16;i++)
      {
      kirkkaus[k] = i-15;
      k++;
      }
   for (i=15; i>1; i -= 3)
      {
      kirkkaus[k] = i-15;
      k++;
      }
   for (i=0; i<15; i++)
      {
      for (g = 0; g <= nopeus; g++)
         {
         vilkutus(0);
         }
      for (k=29; k>0; k--) //29 = ledit mihin yllä asetettiin negatiiviset luvut
         {
         kirkkaus[i] = kirkkaus[i]+1;
         }
      }

   k=0;
*/

//itse kuvio looppi
   while (t < ctr)
      {
      g = nopeus;
      while (g > 0) 
         {
         g--;
         k = 0;
         for (i=0;i<16;i++)
            {
            if (k+j > 31)
               kirkkaus[k+j-32] = i;
            else
               kirkkaus[k+j] = i;
            k++;
            }
         for (i=15; i>1; i -= 3)
            {
            if (k+j > 31)
               kirkkaus[k+j-32] = i;
            else 
               kirkkaus[k+j] = i;
            k++;
            }
         vilkutus(0);
         
         }
      j++;
      if (j>31)
         j = 0;
      t++;
      }
   }

void fill(){
    for(int i=0;i<32;i++){
      kirkkaus[i] = 15;
      vilkutus(0);
      delay(10);
    }
    for(int i=0;i<32;i++){
      kirkkaus[i] = 0;
      vilkutus(0);
      delay(10);
    }

}


void scan(int nopeus){
  for(int i=0;i<14;i++){
    kirkkaus[i] = 15;
    if(i<7){
      kirkkaus[32-i] = 15;
    }
    else{
      kirkkaus[26-i] = 15;
    }
    
    if(i==6){
      for(int k=20;k<26;k++){
        kirkkaus[k] = 15;
      }
    }
    if(i==8){
      for(int k=20;k<26;k++){
        kirkkaus[k] = 0;
      }
    }
    if(i==0){
      kirkkaus[13] = 0;
    }
    else{
      kirkkaus[i-1]= 0;
      if(i<8){
        kirkkaus[33-i]= 0;
      }
      else{
        kirkkaus[27-i]= 0;
      }
    }
    for(int i=0;i<nopeus;i++){
      vilkutus(0);
    }
  }
}


/*
void tauko(uint16_t ctr)
   {
   while (ctr != 0)  
      {
      asm volatile("nop"); 
      ctr--;
      }

   }

void tauko2(uint16_t ctr)
   {
   while (ctr != 0)
      {
      _delay_ms(1);
      ctr--;
      }
   }
*/
void vilkutus(int n)
{
   uint8_t led = 0;
   uint8_t *kirkptr;
   uint8_t *paptr;
   uint8_t *pbptr;
   kirkptr = &kirkkaus[0]; //kirkkaustaulukon pointteri
   paptr = &pa[0]; //PortA taulukon pointteri
   pbptr = &pb[0];
   while (led < 32)
   {
      switch (*kirkptr)
         {
         case 0:
            break;
         case 1:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K1);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;

            break;
         case 2:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K2);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 3:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K3);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 4:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K4);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 5:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K5);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 6:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K6);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 7:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K7);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 8:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K8);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 9:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K9);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 10:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K10);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 11:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K11);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 12:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K12);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 13:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K13);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 14:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K14);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         case 15:
            PORTA = *paptr;
            PORTB = *pbptr;
            delayMicroseconds(K15);
            //PORTA = alloff_pa;
            //PORTB = alloff_pb;
            break;
         default: // negatiiviset ajatellaan nolliksi
            break;
         }

      kirkptr++;
      paptr++;
      pbptr++;
      led++;
   }

   ///sammuttelu ja venailu

  if(n==0){
    PORTA = alloff_pa;
    PORTB = alloff_pb; 
  }
   //PORTA = pa[16];
   //PORTB = pb[16];
   led = 0;
   kirkptr = &kirkkaus[0]; //kirkkaustaulukon pointteri
   while (led < 32)
      {
      switch (*kirkptr)
         {
         case 0:
            delayMicroseconds(P0);
            break;
         case 1:
            delayMicroseconds(P1);
            break;
         case 2:
            delayMicroseconds(P2);
            break;
         case 3:
            delayMicroseconds(P3);
            break;
         case 4:
            delayMicroseconds(P4);
            break;
         case 5:
            delayMicroseconds(P5);
            break;
         case 6:
            delayMicroseconds(P6);
            break;
         case 7:
            delayMicroseconds(P7);
            break;
         case 8:
            delayMicroseconds(P8);
            break;
         case 9:
            delayMicroseconds(P9);
            break;
         case 10:
            delayMicroseconds(P10);
            break;
         case 11:
            delayMicroseconds(P11);
            break;
         case 12:
            delayMicroseconds(P12);
            break;
         case 13:
            delayMicroseconds(P13);
            break;
         case 14:
            delayMicroseconds(P14);
            break;
         case 15:
            delayMicroseconds(P15);
            break;
         default:
            delayMicroseconds(P15);
            break;
         }
      kirkptr++;
      led++;
      }
   }

void allOff(){
   PORTA = alloff_pa;
   PORTB = alloff_pb;
}

