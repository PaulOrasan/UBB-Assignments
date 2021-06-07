#ifndef UI_H
#define UI_H
#include "Service.h"
#include "Drug.h"
class UI
{
	private:
		Service& serv;
		void showMenu();
		void uiAddDrug();
		void uiDeleteDrug();
		void uiUpdateDrug();
		void uiFindDrug();
		void uiShowAllDrugs();
		void uiSortDrugs();
		void uiFilterDrugs();
		void uiAddPrescription();
		void uiCheckPrescription();
		void uiEmptyPrescription() noexcept;
		void uiGeneratePrescription();
		void uiCountProducer();
		void uiExportRecipe();
		void uiUndo();
		void showDrug(const Drug& drug);
		void showDrugs(const std::vector<Drug>& v);
	public:
		UI(Service& serv) noexcept : serv(serv)  {}
		void runApp();
		
};
#endif

