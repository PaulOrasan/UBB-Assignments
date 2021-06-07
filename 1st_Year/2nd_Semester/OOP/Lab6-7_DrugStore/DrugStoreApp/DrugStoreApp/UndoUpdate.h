#ifndef UNDO_UPDATE_H
#define UNDO_UPDATE_H
#include "Repository.h"
#include "Drug.h"
#include "UndoAction.h"
class UndoUpdate : public UndoAction
{
private:
	Repository& repo;
	int drugID;
	double oldPrice;
public:
	UndoUpdate(Repository& rep, const Drug& drug) noexcept : repo{ rep }, drugID{ drug.getID() }, oldPrice{ drug.getPrice() }  {}

	/*
	* Method that restores a drug's price to its old form
	*/
	void doUndo() override {
		repo.updateDrug(drugID, oldPrice);
	}
};
#endif

