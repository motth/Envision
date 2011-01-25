/***********************************************************************************************************************
 * ListPut.h
 *
 *  Created on: Jan 24, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef LISTPUT_H_
#define LISTPUT_H_

#include "UndoCommand.h"

namespace Model {

class ListPut: public UndoCommand
{
	private:
		QVector<Node*>& nodes;
		Node* newNode;
		int putPosition;
		int oldSize;

	public:
		ListPut(Node *target, QVector<Node*>& nodes, Node* newNode, int position);
		virtual ~ListPut();

		void redo();
		void undo();
};

}

#endif /* LISTPUT_H_ */