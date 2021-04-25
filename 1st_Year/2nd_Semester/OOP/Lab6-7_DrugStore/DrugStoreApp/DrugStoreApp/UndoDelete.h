#ifndef UNDO_DELETE_H
#define UNDO_DELETE_H
#include "Repository.h"
#include "Drug.h"
#include "UndoAction.h"
class UndoDelete : public UndoAction
{
private:
	Repository& repo;
	Drug addedDrug;
public:
	UndoDelete(Repository& rep, const Drug& drug) : repo{ rep }, addedDrug{ drug } {}

	/*
	* Method that adds a removed drug back in the repository
	*/
	void doUndo() override {
		repo.addDrug(addedDrug);
	}
};
#endif
