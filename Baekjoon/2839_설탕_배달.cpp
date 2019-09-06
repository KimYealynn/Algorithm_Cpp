#include <iostream>

using namespace std;

int main() {
   int sugar, num = -1;
   int five = 0;
   int three = 0;
   scanf("%d", &sugar);
   
   if (sugar % 5 == 0) num = sugar / 5;
   else if (sugar == 3) num = 1;
   else {
      for (three = 1; 3 * three < sugar; three++)
      {
         if ((sugar - 3 * three) % 5 == 0)
         {
            five = (sugar - 3 * three) / 5;
            num = five + three;
            break;
         }
         else if (sugar % 3 == 0) num = sugar / 3;
      }
   }
   cout << num;

   return 0;
}