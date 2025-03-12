#include <iostream>
#include "lexer.h"
#include "automate.h"
#include <string>


int main(void) {
   string chaine("(1+34)*123");
   Automate* automate = new Automate(chaine);
   automate->run();
   delete automate;
   return 0;
}

