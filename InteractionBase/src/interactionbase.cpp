/***********************************************************************************************************************
 * interactionbase.cpp
 *
 *  Created on: Jan 11, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#include "interactionbase.h"

#include "GenericHandler.h"
#include "HText.h"
#include "HExtendable.h"

#include "VisualizationBase/headers/items/VExtendable.h"
#include "VisualizationBase/headers/items/VList.h"
#include "VisualizationBase/headers/items/Text.h"
#include "VisualizationBase/headers/items/VText.h"
#include "ModelBase/headers/test_nodes/BinaryNode.h"

#include "SelfTest/headers/SelfTestSuite.h"


Q_EXPORT_PLUGIN2( interactionbase, Interaction::InteractionBase )

namespace Interaction {

bool InteractionBase::initialize(Envision::EnvisionManager&)
{
	Visualization::VExtendable::setInteractionHandler(HExtendable::instance());
	Visualization::VList::setInteractionHandler(GenericHandler::instance());
	Visualization::Text::setInteractionHandler(HText::instance());
	Visualization::VText::setInteractionHandler(HText::instance());
	return true;
}

void InteractionBase::selfTest(QString testid)
{
	TestNodes::BinaryNode::init();

	if (testid.isEmpty()) SelfTest::TestManager<InteractionBase>::runAllTests().printResultStatistics();
	else SelfTest::TestManager<InteractionBase>::runTest(testid).printResultStatistics();
}

}