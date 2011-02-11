/***********************************************************************************************************************
 * VStringLiteral.cpp
 *
 *  Created on: Feb 8, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#include "literals/VStringLiteral.h"

#include "ModelBase/headers/Model.h"

namespace OOVisualization {

ITEM_COMMON_DEFINITIONS(VStringLiteral)

VStringLiteral::VStringLiteral(Item* parent, OOModel::StringLiteral *literal, const Visualization::TextStyle *style) :
	VText(parent, literal->valueNode(), style)
{
}

}
