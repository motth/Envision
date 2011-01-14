/***********************************************************************************************************************
 * SequentialLayout.h
 *
 *  Created on: Dec 9, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef SEQUENTIALLAYOUT_H_
#define SEQUENTIALLAYOUT_H_

#include "../visualizationbase_api.h"

#include "Layout.h"
#include "SequentialLayoutStyle.h"

namespace Visualization {

class VISUALIZATIONBASE_API SequentialLayout: public Layout
{
	ITEM_COMMON(SequentialLayout, Layout)

	private:
		QVector<Item*> items;

	public:
		SequentialLayout(Item* parent, const SequentialLayoutStyle* style = Styles::layout<SequentialLayout>("default"));
		~SequentialLayout();

		int length() const;

		void append(Item* item);
		void prepend(Item* item);
		void insert(Item* item, int position);
		void remove(int index, bool deleteItem = true);

		template <class T> T* at(int index);

		virtual void updateState();
};

template <class T> T* SequentialLayout::at(int index) { return static_cast<T*> (items[index]); }

}

#endif /* SEQUENTIALLAYOUT_H_ */