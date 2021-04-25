#ifndef UNDO_ADD_H
#define UNDO_ADD_H
#include "UndoAction.h"
#include "Repository.h"
#include "Drug.h"
class UndoAdd : public UndoAction
{
private:
	Repository& repo;
	int id;
public:
	/*
	* Constructor
	*/
	UndoAdd(Repository& rep, const Drug& newDrug) noexcept : repo{ rep }, id{ newDrug.getID() } {}

	/*
	* Method that removes an added drug from the repository
	*/
	void doUndo() override {
		repo.deleteDrug(id);
	}
};
#endif
