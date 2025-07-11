#include "tay_nguyen_campaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;         
const int MAX_LINE_LENGTH = 100;

void ghan(int &num1, int &num2, int n);

// Task 0: Read input file
bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E)
{
  char data[MAX_LINES][MAX_LINE_LENGTH];
  int numLines = 0;

  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    return false;
  }

  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH))
  {
    numLines++;
  }
  ifs.close();

  if (numLines < MAX_LINES)
  {
    return false;
  }

  // TODO: Extract values from the `data` array and store them in respective variables
  
  int i=1, j=0; 
  LF1[0]= 0 ;
  while (data[0][i] != ']')
  {
    
    if (data[0][i] ==',') {
      j++;
      LF1[j] = 0;
    } 
    else LF1[j]=LF1[j]*10+(data[0][i]-'0'); 
    i++; 
  }

  i=1, j=0; 
  LF2[0]= 0;
while (data[1][i] != ']')
  {
    if (data[1][i] == ',') {
    j++;
    LF2[j] = 0; 
    }
    else LF2[j]=LF2[j]*10+(data[1][i]-'0'); 
    i++; 
  }
  for(int i=0; i<17; i++) {
    ghan(LF1[i],LF2[i],3000);
  }
  
  
  i=0;
  EXP1 = 0;
  EXP2 = 0;
  T1=0,T2=0;
  E=0; 
  while (data[2][i] != ' ') 
  {
  EXP1=EXP1*10+(data[2][i]-'0');
  i++;
  }
  i++;
  while (data[2][i] != ' ' && data[2][i]!='\0') 
  {
  EXP2=EXP2*10+(data[2][i]-'0');
  i++;
  }
  ghan(EXP1,EXP2,1000);
  
  
  i=0;
  while (data[3][i] != ' ') 
  {
  T1=T1*10+(data[3][i]-'0');
  i++;
  }
  i++;
  while (data[3][i] != ' ' && data[3][i]!='\0') 
  {
  T2=T2*10+(data[3][i]-'0');
  i++;
  }
  ghan(T1,T2,3000);
  
  
  i=0;
  while (data[4][i] != ' ' && data[4][i]!='\0') 
  {
  E=E*10+(data[4][i]-'0');
  i++;
  }
  ghan(E,E,99);
  return true;
}

// Task 1
int gatherForces(int LF1[], int LF2[])

{
  int LF = 0; 
  int power[17] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 15, 18, 20, 30, 40, 50, 70};
  for (int i = 0; i < 17; i++) {
    LF += (LF1[i] + LF2[i]) * power[i];
  }
  return LF;
}


// Task 2
int size=3;
int findmax (int x[], int size) {
    int max = x[0]; 
    for (int i = 1; i < size; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    return max; 
  }

  string determineRightTarget(const string &target)
{
// TODO: Implement this function
int x[3]={0},dem=0,i=0;
while(target[i]!='\0'){
  if(target[i] >='0' && target[i]<='9') {
    dem++;
    if(dem>3) return "INVALID";
    while(target[i] >='0' && target[i]<='9') {
      x[dem-1]=x[dem-1]*10+(target[i]-'0');
      i++;
    }
  }
  i++;
}

int ID;
if (dem==0) return "INVALID";  
else if (dem==1) ID=x[0]; 
else if (dem==2) ID=(x[0]+x[1])%5+3; 
else if (dem==3) ID=findmax(x, 3)%5+3;
switch (ID)
{
  case 3: return "Buon Ma Thuot"; 
  case 4: return "Duc Lap"; 
  case 5: return "Dak Lak"; 
  case 6: return "National Route 21";  
  case 7: return "National Route 14"; 
  default: return "INVALID"; 
}
 return " "; 
  }




string change (string &s, int size); 
string decodeTarget(const string &message, int EXP1, int EXP2)
{
  // TODO: Implement this function
  string arr[5] = {
    "Buon Ma Thuot",
    "Duc Lap",
    "Dak Lak",
    "National Route 21",
    "National Route 14"
};

  //CAESAR
  int check=10; 
  int d=(EXP1+EXP2)%26; 
  int i=0,size=message.length();
  string s(size, ' '); 
  if (EXP1>=300 && EXP2 >=300){
  
  
  while (i<size)
  {
    if (message[i]>='A' && message[i] <= 'Z')
    {
      s[i]=char((message[i]- 'A' +d + 26) % 26 + 'A');
    }
    else if (message[i]>='a' && message[i] <= 'z')
    {
      s[i]=char((message[i]- 'a' +d + 26) % 26 + 'a');
    }
    else if(!(message[i]==' ' || (message[i]<='9' && message[i]>='0') )) return "INVALID";
    i++; 
  }
  s= change(s,size);
}


  //đảo chuỗi
else if (EXP1<300 || EXP2 <300)
{
  int a=0;
  for (int i=message.length()-1; i>=0; i--)
  {
    s[a]=message[i];
    a++; 
  }
  s= change(s, size);
} 
for(int i=0;i<5;i++) {
  if(arr[i]==s) return arr[i];
}
return "INVALID";
}

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  // TODO: Implement this function
  double a=T1;
  double b=T2;
  if (E == 0) {
    double deltaT1 = (LF1 * 1.0 / (LF1 + LF2)) * (a + b) * (1 + (EXP1 - EXP2) / 100.0);
    double deltaT2 = (a + b) - deltaT1;

    a += deltaT1 ; 
    b += deltaT2 ;
  }
  else if (E >= 1 && E <= 9) {
      a -= ((double)E * 0.01 * a) ;
      b -= ((double)E * 0.005 * b) ;
  } else if (E >= 10 && E <= 29) {
      a += E * 50;
      b += E * 50;
  } else if (E >= 30 && E <= 59) {
      a += ((double)E * 0.005 * a) ;
      b += ((double)E * 0.002 * b) ;
  } 
  T1=ceil(a);
  T2=ceil(b);
  ghan(T1,T2,3000);
}



// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
  // TODO: Implement this function

double S = (LF1 + LF2)+ (EXP1 + EXP2) * 5.0 + (T1 + T2) * 2.0;

for (int i = 0; i < 10; i++)
{
for (int j = 0; j < 10; j++)
{
if (i % 2 == 1)  // hàng lẻ
{
    S -= (battleField[i][j] * 3.0) / 2.0;
}
else             // hàng chẵn
{
  S -= (battleField[i][j] * 2.0) / 3.0;
}
}
}

//làm tròn 
if (S > (int)S) { 
  S = (int)S + 1; // Nếu có phần thập phân, tăng lên 1
} else {
  S = (int)S; // Nếu đã là số nguyên, giữ nguyên
}
return S; 
}


// Task 5
int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
  int arr[25]; 
  int a=0; 
  for (int i=0; i<5; i++) {
    for (int j=0; j<5; j++)
    {
      arr[a]=supply[i][j]; 
      a++; 
    }
  }

  int count=1;
  while (count!=0) 
  {
    count =0; 
    for (int i=0; i<24; i++) {
      if (arr[i]>arr[i+1]) {
        int temp; 
        temp = arr[i]; 
        arr[i]=arr[i+1]; 
        arr[i+1]=temp; 
        count++; 
      }
    }
  }
  
  
  int num=0,min=INT_MAX;
  for (int i=0; i<21; i++)
  {
    if (arr[i]+arr[21]+arr[22]+arr[23]+arr[24]<shortfall) break; 
    for (int j=1; j<22; j++)
    {
      if (arr[i]+arr[j]+arr[22]+arr[23]+arr[24]<shortfall) break; 
      for (int k=2; k<23; k++)
      {
        if (arr[i]+arr[j]+arr[k]+arr[23]+arr[24]<shortfall) break; 
        for (int m=3; m<24; m++)
        {
          if (arr[i]+arr[j]+arr[k]+arr[m]+arr[24]<shortfall) break; 
          for (int n=4; n<25; n++)
          {
            num=arr[i]+arr[j]+arr[k]+arr[m]+arr[n];
            if(num==shortfall)  return shortfall;
            if(num<min && num>shortfall) {
              min=num;
              break;
            }  
          }
        }
      }
    }
  }
  if(min==INT_MAX) return 0;
  return min;
}

//ham tu tao
string change (string &s, int size)
{
  int i=1;
  if (s[0]>='a' && s[0]<='z') s[0]=toupper(s[0]); 
  while (i<size)
  {
    if (s[i-1]==' ') {
      s[i]=toupper(s[i]); 
    }
    else s[i]=tolower(s[i]); 
    i++; 
  }
  return s; 
}
void ghan(int &num1, int &num2, int n){
  if(num1>n) num1=n;
  else if(num1<0) num1 =0;
  if(num2>n) num2=n;
  else if(num2<0) num2 =0;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
