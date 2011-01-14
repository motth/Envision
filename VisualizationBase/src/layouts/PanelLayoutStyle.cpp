/***********************************************************************************************************************
 * PanelLayoutStyle.cpp
 *
 *  Created on: Dec 14, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#include "layouts/PanelLayoutStyle.h"
#include "Styles.h"

namespace Visualization {

PanelLayoutStyle::PanelLayoutStyle() :
	orientation_(HorizontalOrientation), alignment_(CenterAlignment), spaceBetweenElements_(5)
{
}

PanelLayoutStyle* PanelLayoutStyle::getDefault()
{
	static PanelLayoutStyle defaultStyle;
	return &defaultStyle;
}

void PanelLayoutStyle::setOrientation(Orientation orientation)
{
	orientation_ = orientation;
}

void PanelLayoutStyle::setAlignment(Alignment alignment)
{
	alignment_ = alignment;
}

void PanelLayoutStyle::setSpaceBetweenElements(int space)
{
	if ( space >= 0 ) spaceBetweenElements_ = space;
}

void PanelLayoutStyle::load()
{
	LayoutStyle::load();
	Styles::load("orientation", (int&) orientation_);
	Styles::load("alignment", (int&) alignment_);
	Styles::load("spaceBetweenElements", spaceBetweenElements_);
}
}