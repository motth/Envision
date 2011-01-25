/***********************************************************************************************************************
 * CommandPrompt.h
 *
 *  Created on: Jan 18, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef COMMANDPROMPT_H_
#define COMMANDPROMPT_H_

#include "interactionbase_api.h"
#include "CommandPromptStyle.h"
#include "../commands/CommandSuggestion.h"
#include "../commands/CommandResult.h"

#include "VisualizationBase/headers/Styles.h"
#include "VisualizationBase/headers/items/Item.h"
#include "VisualizationBase/headers/items/Text.h"
#include "VisualizationBase/headers/layouts/SequentialLayout.h"\

#include <QtCore/QList>

namespace Interaction {

class INTERACTIONBASE_API CommandPrompt : public Visualization::Item
{
	ITEM_COMMON(CommandPrompt, Visualization::Item)

	public:
		CommandPrompt(Visualization::Item* commandReceiver, const CommandPromptStyle* style = Visualization::Styles::item<CommandPrompt>("default"));
		virtual ~CommandPrompt();

		void setResult(CommandResult* result);
		void addSuggestion(CommandSuggestion* suggestion);
		void addSuggestions(const QList<CommandSuggestion*>& suggestions);

		void removeResult();
		void removeSuggestions();

		CommandResult* result();
		QList<CommandSuggestion*>& suggestions();

		Visualization::Item* commandReceiver();

		QString text() const;
		void initializeCommand();
		void takeSuggestion(CommandSuggestion* suggestion);

		void showPrompt();
		void hidePrompt();

	protected:
		virtual void determineChildren();
		virtual void updateGeometry(int availableWidth, int availableHeight);

	private:
		Visualization::Item* commandReceiver_;
		Visualization::SequentialLayout* layout;
		Visualization::SequentialLayout* suggestionContainer;
		Visualization::SequentialLayout* errorContainer;
		Visualization::Text* command;

		int commandSelectedFirst;
		int commandSelectedLast;

		CommandResult* result_;
		QList<CommandSuggestion*> suggestions_;	//Suggestions from the result do not appear here.

		// This is true when the item is created and is set to false after the first update.
		bool justCreated;
};

inline Visualization::Item* CommandPrompt::commandReceiver() { return commandReceiver_; }
inline QString CommandPrompt::text() const {return command->getText();}

inline CommandResult* CommandPrompt::result() { return result_; }
inline QList<CommandSuggestion*>& CommandPrompt::suggestions() { return suggestions_; }

}

#endif /* COMMANDPROMPT_H_ */