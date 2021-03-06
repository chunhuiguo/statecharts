/**
* Copyright (c) 2017 committers of YAKINDU and others.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*     committers of YAKINDU - initial API and implementation
*/
#include "gtest/gtest.h"
#include "IntegerExpressions.h"

static IntegerExpressions statechart;

class StatemachineTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		integerExpressions_init(&statechart);
	}
};


TEST_F(StatemachineTest, integerExpressions) {					
	integerExpressions_enter(&statechart);
	EXPECT_TRUE(integerExpressions_isStateActive(&statechart, IntegerExpressions_main_region_StateA));
	EXPECT_TRUE(integerExpressionsIface_get_myInt1(&statechart)== 10l);
	EXPECT_TRUE(integerExpressionsIface_get_myInt2(&statechart)== 5l);
	integerExpressionsIface_raise_e1(&statechart);
	integerExpressions_runCycle(&statechart);
	EXPECT_TRUE(integerExpressionsIface_get_less(&statechart)== false);
	EXPECT_TRUE(integerExpressionsIface_get_greater(&statechart)== true);
	EXPECT_TRUE(integerExpressionsIface_get_equalOrLess(&statechart)== false);
	EXPECT_TRUE(integerExpressionsIface_get_equalOrGreater(&statechart)== true);
	EXPECT_TRUE(integerExpressionsIface_get_equal(&statechart)== false);
	EXPECT_TRUE(integerExpressionsIface_get_notEqual(&statechart)== true);
	EXPECT_TRUE(integerExpressionsIface_get_plus(&statechart)== 15l);
	EXPECT_TRUE(integerExpressionsIface_get_minus(&statechart)== 5l);
	EXPECT_TRUE(integerExpressionsIface_get_multiply(&statechart)== 50l);
	EXPECT_TRUE(integerExpressionsIface_get_division(&statechart)== 2l);
	EXPECT_TRUE(integerExpressionsIface_get_modulo(&statechart)== 0l);
	EXPECT_TRUE(integerExpressionsIface_get_negat(&statechart)== - 10l );
	EXPECT_TRUE(integerExpressionsIface_get_multiAssign(&statechart)== 20l);
	EXPECT_TRUE(integerExpressionsIface_get_divAssign(&statechart)== 2l);
	EXPECT_TRUE(integerExpressionsIface_get_plusAssign(&statechart)== 12l);
	EXPECT_TRUE(integerExpressionsIface_get_minusAssign(&statechart)== - 8l );
	EXPECT_TRUE(integerExpressionsIface_get_moduloAssign(&statechart)== 0l);
}


