#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H
class UndoAction
{
public:
	virtual void doUndo() = 0;
	virtual ~UndoAction() = default;
};
#endif
