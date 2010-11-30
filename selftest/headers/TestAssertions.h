/***********************************************************************************************************************
 * TestAssertions.h
 *
 *  Created on: Nov 10, 2010
 *      Author: Dimitar Asenov
 **********************************************************************************************************************/

#ifndef TESTASSERTIONS_H_
#define TESTASSERTIONS_H_

/**********************************************************************************************************************/
#define CHECK_GENERIC_EQUAL(expected, actual)																								\
	try																																					\
	{																																						\
		if ( (expected) == (actual) ) testResults.addPassedCheck();																		\
		else																																				\
		{																																					\
			allChecksPassedFlag = false;																											\
			QString message = getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + "\t";							\
			message += "Actual value is different from expected";																			\
			testResults.addFailedCheck(message);																								\
		}																																					\
	} catch (...)																																		\
	{																																						\
		allChecksPassedFlag = false;																												\
		testResults.addFailedCheck(getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + " Uncaught exception");	\
		throw;																																			\
	}
/**********************************************************************************************************************/

/**********************************************************************************************************************/
#define CHECK_INT_EQUAL(expected, actual)																										\
	try																																					\
	{																																						\
		if ( (expected) == (actual) ) testResults.addPassedCheck();																		\
		else																																				\
		{																																					\
			allChecksPassedFlag = false;																											\
			QString message = getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + "\t";							\
			message += "Actual value (" + QString::number(actual);																		\
			message += ") is different from expected ("+QString::number(expected)+")";												\
			testResults.addFailedCheck(message);																								\
		}																																					\
	} catch (...)																																		\
	{																																						\
		allChecksPassedFlag = false;																												\
		testResults.addFailedCheck(getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + " Uncaught exception");	\
		throw;																																			\
	}
/**********************************************************************************************************************/

/**********************************************************************************************************************/
#define CHECK_STR_EQUAL(expected, actual)																										\
	try																																					\
	{																																						\
		if ( (expected) == (actual) ) testResults.addPassedCheck();																		\
		else																																				\
		{																																					\
			allChecksPassedFlag = false;																											\
			QString message = getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + "\t";							\
			message += "Actual value (" + QString(actual) +") is different from expected ("+QString(expected)+")";		\
			testResults.addFailedCheck(message);																								\
		}																																					\
	} catch (...)																																		\
	{																																						\
		allChecksPassedFlag = false;																												\
		testResults.addFailedCheck(getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + " Uncaught exception");	\
		throw;																																			\
	}
/**********************************************************************************************************************/

/**********************************************************************************************************************/
#define CHECK_CONDITION( condition )																											\
	try																																					\
	{																																						\
		if ( (condition) ) testResults.addPassedCheck();																					\
		else																																				\
		{																																					\
			allChecksPassedFlag = false;																											\
			QString message = getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + "\t";							\
			message += "Condition is false: " #condition;																					\
			testResults.addFailedCheck(message);																								\
		}																																					\
	} catch (...)																																		\
	{																																						\
		allChecksPassedFlag = false;																												\
		testResults.addFailedCheck(getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + " Uncaught exception");	\
		throw;																																			\
	}
/**********************************************************************************************************************/

/**********************************************************************************************************************/
#define CHECK_FOR_EXCEPTION( exception, statement )																						\
	try																																					\
	{																																						\
		statement;																																		\
		allChecksPassedFlag = false;																												\
		QString message = getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + "\t";								\
		message += "Exception " #exception " was expected but did not occur";														\
		testResults.addFailedCheck(message);																									\
	} catch (exception &e)																															\
	{																																						\
		testResults.addPassedCheck();																												\
	} catch (...)																																		\
	{																																						\
		allChecksPassedFlag = false;																												\
		testResults.addFailedCheck(getName() + "\t" + __FILE__ + ":" + QString::number(__LINE__) + " Uncaught exception");	\
		throw;																																			\
	}
/**********************************************************************************************************************/

#endif /* TESTASSERTIONS_H_ */