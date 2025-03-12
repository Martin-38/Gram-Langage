#include <iostream>
#include "lexer.h"
#include "automate.h"
#include <string>


int main(void) {
   string chaine("3*2+22");
   Automate* automate = new Automate(chaine);
   automate->run();
   delete automate;
   return 0;
}

