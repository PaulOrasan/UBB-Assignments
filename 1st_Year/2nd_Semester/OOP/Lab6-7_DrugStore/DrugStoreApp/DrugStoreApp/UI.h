#ifndef UI_H
#define UI_H
#include "Service.h"
#include "Drug.h"
class UI
{
	private:
		const Service& serv;
	public:
		UI(const Service& serv) noexcept : serv(serv)  {}
		void runApp();
		void showMenu();
		void uiAddDrug();
		void uiDeleteDrug();
		void uiUpdateDrug();
		void uiFindDrug();
		void uiShowAllDrugs();
		void showDrug(const Drug& drug);
};
#endif

