/***********************************************************************************************************************
 * TypedListDefinition.h
 *
 *  Created on: Jan 28, 2011
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#include "TypedList.h"

#ifndef TYPEDLISTDEFINITION_H_
#define TYPEDLISTDEFINITION_H_

namespace Model {

template<class T>
TypedList<T>::TypedList(::Model::Node* parent, ::Model::Model* model) :
	List(parent, model)
{
}

template<class T>
TypedList<T>::TypedList(::Model::Node *parent, ::Model::NodeIdType id, ::Model::PersistentStore &store, bool partialLoadHint) :
	List(parent, id, store, partialLoadHint)
{
}

template<class T> int TypedList<T>::typeId_ = -1; /* This must be set to the result of Node::registerNodeType */
template<class T> const QString TypedList<T>::typeName_ = QString("TypedListOf") + T::typeNameStatic();

template<class T>
const QString& TypedList<T>::typeName() const
{
	return typeName_;
}

template<class T>
int TypedList<T>::typeId() const
{
	return typeId_;
}

template<class T>
int TypedList<T>::typeIdStatic()
{
	return typeId_;
}

template<class T>
const QString& TypedList<T>::typeNameStatic()
{
	return typeName_;
}

template<class T>
void TypedList<T>::registerNodeType()
{
	typeId_ = Node::registerNodeType(typeNameStatic(), ::Model::createNewNode<TypedList<T> >, ::Model::createNodeFromPersistence<TypedList<T> >);
}

template<class T> T* TypedList<T>::first()
{
	return List::first<T>();
}
template<class T> T* TypedList<T>::last()
{
	return List::last<T>();
}
template<class T> T* TypedList<T>::at(int i)
{
	return List::at<T>(i);
}

}

#endif /* TYPEDLISTDEFINITION_H_ */