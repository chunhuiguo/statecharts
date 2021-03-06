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
#include <string>
#include "gtest/gtest.h"
#include "StateIsActive.h"
#include "sc_types.h"
static StateIsActive* statechart;

class StatemachineTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new StateIsActive();
		statechart->init();
	}
	virtual void TearDown() {
		delete statechart;
	}
};


TEST_F(StatemachineTest, stateIsActive) {
	
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->isStateActive(StateIsActive::R1_R1A));
	
	EXPECT_TRUE(statechart->isStateActive(StateIsActive::R2_R2A));
	
	statechart->getDefaultSCI()->raise_event1();
	
	statechart->runCycle();;
	
	statechart->runCycle();;
	
	EXPECT_TRUE(statechart->isStateActive(StateIsActive::R1_R1B));
	
	EXPECT_TRUE(statechart->isStateActive(StateIsActive::R2_R2B));
	
}
