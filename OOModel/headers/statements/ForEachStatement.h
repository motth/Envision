/***********************************************************************************************************************
 * ForEachStatement.h
 *
 *  Created on: Jan 31, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef FOREACHSTATEMENT_H_
#define FOREACHSTATEMENT_H_

#include "Statement.h"

#include "../FormalArgument.h"
#include "../expressions/Expression.h"


namespace OOModel {

class OOMODEL_API ForEachStatement: public Statement
{
	EXTENDABLENODE_DECLARE_STANDARD_METHODS(ForEachStatement)

	ATTRIBUTE(FormalArgument, var, setVar);
	ATTRIBUTE(Expression, collection, setCollection);
	ATTRIBUTE(Statement, body, setBody);
};

}

#endif /* FOREACHSTATEMENT_H_ */