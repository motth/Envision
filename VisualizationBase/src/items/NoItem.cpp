/***********************************************************************************************************************
 * NoItem.cpp
 *
 *  Created on: Dec 15, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#include "items/NoItem.h"

namespace Visualization {

NoItem::NoItem(Item* parent) : Item(parent)
{
}

bool NoItem::needsUpdate()
{
	return false;
}

void NoItem::determineChildren() {};
void NoItem::updateState() {};
void NoItem::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) {};

}
