#include "HistoryOrganizer.h"
#include "Reader.h"
#include "TextProcessor.h"
#include "WordFilter.h"
#include <iostream>

int main() {
	
	Reader a;
	a.uplaod();
	HistoryOrganizer h;
	h.print();
	TextProcessor t("Hi bla bla bla hi test ismail mohammed test eslam basel she he it test yo mahmoud abdelaleem rana maryam ibrahim ");
	//WordFilter a;
	//a.filter(t);
	//cout<<t.rankkingbyfreq("hi")<<endl; //return 2
	//cout << t.rankkingbyfreq("testt") << endl;  //هترجع -1 عشان هى مش موجودة
	//cout << t.rankkingbyfreq("eslam") << endl; // هترجع 3
	////t.rankkingbyfreq(); // اللى بترجع كلهم من غير بحث
	//

	return 0;
}