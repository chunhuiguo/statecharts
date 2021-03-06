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
#include "Operations.h"
#include "OperationsRequired.h"
class AlwaysTrueMock{
	public:
	sc_boolean (AlwaysTrueMock::*alwaysTrueBehavior)();
	sc_boolean alwaysTrue1(){
		return (true);
	}
	void setAlwaysTrueBehavior(sc_boolean (AlwaysTrueMock::*func)()){
		alwaysTrueBehavior = func;
	}
};
static AlwaysTrueMock* alwaysTrueMock;

static struct {
	sc_boolean called;
} internalOperation1 = {false};

static struct {
	sc_boolean called;
	sc_integer param1;
} internalOperation2 = {false, 0};

static struct {
	sc_boolean called;
} internalOperation3 = {false};

static struct {
	sc_boolean called;
	sc_real param1;
} internalOperation3a = {false, 0.0d};

static struct {
	sc_boolean called;
} internalOperation4 = {false};

static struct {
	sc_boolean called;
	sc_integer param1;
} internalOperation4a = {false, 0};

static struct {
	sc_boolean called;
} internalOperation5 = {false};

static struct {
	sc_boolean called;
	char const * param1;
} internalOperation5a = {false, 0};

static struct {
	sc_boolean called;
} interface1InterfaceOperation1 = {false};

static struct {
	sc_boolean called;
	sc_integer param1;
} interface1InterfaceOperation2 = {false, 0};

static struct {
	sc_boolean called;
} interface1InterfaceOperation3 = {false};

static struct {
	sc_boolean called;
	sc_real param1;
} interface1InterfaceOperation3a = {false, 0.0d};

static struct {
	sc_boolean called;
} interface1InterfaceOperation4 = {false};

static struct {
	sc_boolean called;
	sc_integer param1;
} interface1InterfaceOperation4a = {false, 0};

static struct {
	sc_boolean called;
} interface1InterfaceOperation5 = {false};

static struct {
	sc_boolean called;
	char const * param1;
} interface1InterfaceOperation5a = {false, 0};

static struct {
	sc_boolean called;
} unnamedInterfaceOperation1 = {false};

static struct {
	sc_boolean called;
	sc_integer param1;
} unnamedInterfaceOperation2 = {false, 0};

static struct {
	sc_boolean called;
} unnamedOperation3 = {false};

static struct {
	sc_boolean called;
	sc_real param1;
} unnamedOperation3a = {false, 0.0d};

static struct {
	sc_boolean called;
} unnamedOperation4 = {false};

static struct {
	sc_boolean called;
	sc_integer param1;
} unnamedOperation4a = {false, 0};

static struct {
	sc_boolean called;
} unnamedOperation5 = {false};

static struct {
	sc_boolean called;
	char const * param1;
} unnamedOperation5a = {false, 0};


static Operations statechart;

class StatemachineTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		operations_init(&statechart);
	}
};


TEST_F(StatemachineTest, operationsCalled) {					
	alwaysTrueMock = new AlwaysTrueMock();
	alwaysTrueMock->setAlwaysTrueBehavior(&AlwaysTrueMock::alwaysTrue1);
	operations_enter(&statechart);
	EXPECT_TRUE(operations_isStateActive(&statechart, Operations_main_region_A));
	operations_runCycle(&statechart);
	EXPECT_TRUE(operations_isStateActive(&statechart, Operations_main_region_B));
	EXPECT_TRUE(internalOperation1.called);
	EXPECT_TRUE(internalOperation2.called);
	EXPECT_TRUE(internalOperation2.param1 == 4l);
	EXPECT_TRUE(internalOperation3.called);
	EXPECT_TRUE(internalOperation3a.called);
	EXPECT_TRUE(internalOperation3a.param1 == 1.0);
	EXPECT_TRUE(internalOperation4.called);
	EXPECT_TRUE(internalOperation4a.called);
	EXPECT_TRUE(internalOperation4a.param1 == 5l);
	EXPECT_TRUE(internalOperation5.called);
	EXPECT_TRUE(internalOperation5a.called);
	operationsIface_raise_ev(&statechart);
	operations_runCycle(&statechart);
	EXPECT_TRUE(operations_isStateActive(&statechart, Operations_main_region_C));
	EXPECT_TRUE(interface1InterfaceOperation1.called);
	EXPECT_TRUE(interface1InterfaceOperation2.called);
	EXPECT_TRUE(interface1InterfaceOperation2.param1 == 4l);
	EXPECT_TRUE(interface1InterfaceOperation3.called);
	EXPECT_TRUE(interface1InterfaceOperation3a.called);
	EXPECT_TRUE(interface1InterfaceOperation3a.param1 == 1.0);
	EXPECT_TRUE(interface1InterfaceOperation4.called);
	EXPECT_TRUE(interface1InterfaceOperation4a.called);
	EXPECT_TRUE(interface1InterfaceOperation4a.param1 == 5l);
	EXPECT_TRUE(interface1InterfaceOperation5.called);
	EXPECT_TRUE(interface1InterfaceOperation5a.called);
	operationsIface_raise_ev(&statechart);
	operations_runCycle(&statechart);
	EXPECT_TRUE(operations_isStateActive(&statechart, Operations_main_region_D));
	EXPECT_TRUE(unnamedInterfaceOperation1.called);
	EXPECT_TRUE(unnamedInterfaceOperation2.called);
	EXPECT_TRUE(unnamedInterfaceOperation2.param1 == 4l);
	EXPECT_TRUE(unnamedOperation3.called);
	EXPECT_TRUE(unnamedOperation3a.called);
	EXPECT_TRUE(unnamedOperation3a.param1 == 1.0);
	EXPECT_TRUE(unnamedOperation4.called);
	EXPECT_TRUE(unnamedOperation4a.called);
	EXPECT_TRUE(unnamedOperation4a.param1 == 5l);
	EXPECT_TRUE(unnamedOperation5.called);
	EXPECT_TRUE(unnamedOperation5a.called);
}


void operationsInternal_internalOperation1(const Operations* statechart){
internalOperation1.called = true;
}
sc_boolean operationsInternal_internalOperation2(const Operations* statechart, const sc_integer param1){
internalOperation2.called = true;
internalOperation2.param1 = param1;
return true;
}
sc_real operationsInternal_internalOperation3(const Operations* statechart){
internalOperation3.called = true;
return 0.0d;
}
sc_real operationsInternal_internalOperation3a(const Operations* statechart, const sc_real param1){
internalOperation3a.called = true;
internalOperation3a.param1 = param1;
return 0.0d;
}
sc_integer operationsInternal_internalOperation4(const Operations* statechart){
internalOperation4.called = true;
return 0;
}
sc_integer operationsInternal_internalOperation4a(const Operations* statechart, const sc_integer param1){
internalOperation4a.called = true;
internalOperation4a.param1 = param1;
return 0;
}
sc_string operationsInternal_internalOperation5(const Operations* statechart){
internalOperation5.called = true;
return 0;
}
sc_string operationsInternal_internalOperation5a(const Operations* statechart, const sc_string param1){
internalOperation5a.called = true;
internalOperation5a.param1 = param1;
return 0;
}
void operationsIfaceInterface1_interfaceOperation1(const Operations* statechart){
interface1InterfaceOperation1.called = true;
}
sc_boolean operationsIfaceInterface1_interfaceOperation2(const Operations* statechart, const sc_integer param1){
interface1InterfaceOperation2.called = true;
interface1InterfaceOperation2.param1 = param1;
return true;
}
sc_real operationsIfaceInterface1_interfaceOperation3(const Operations* statechart){
interface1InterfaceOperation3.called = true;
return 0.0d;
}
sc_real operationsIfaceInterface1_interfaceOperation3a(const Operations* statechart, const sc_real param1){
interface1InterfaceOperation3a.called = true;
interface1InterfaceOperation3a.param1 = param1;
return 0.0d;
}
sc_integer operationsIfaceInterface1_interfaceOperation4(const Operations* statechart){
interface1InterfaceOperation4.called = true;
return 0;
}
sc_integer operationsIfaceInterface1_interfaceOperation4a(const Operations* statechart, const sc_integer param1){
interface1InterfaceOperation4a.called = true;
interface1InterfaceOperation4a.param1 = param1;
return 0;
}
sc_string operationsIfaceInterface1_interfaceOperation5(const Operations* statechart){
interface1InterfaceOperation5.called = true;
return 0;
}
sc_string operationsIfaceInterface1_interfaceOperation5a(const Operations* statechart, const sc_string param1){
interface1InterfaceOperation5a.called = true;
interface1InterfaceOperation5a.param1 = param1;
return 0;
}
void operationsIface_unnamedInterfaceOperation1(const Operations* statechart){
unnamedInterfaceOperation1.called = true;
}
sc_boolean operationsIface_unnamedInterfaceOperation2(const Operations* statechart, const sc_integer param1){
unnamedInterfaceOperation2.called = true;
unnamedInterfaceOperation2.param1 = param1;
return true;
}
sc_real operationsIface_unnamedOperation3(const Operations* statechart){
unnamedOperation3.called = true;
return 0.0d;
}
sc_real operationsIface_unnamedOperation3a(const Operations* statechart, const sc_real param1){
unnamedOperation3a.called = true;
unnamedOperation3a.param1 = param1;
return 0.0d;
}
sc_integer operationsIface_unnamedOperation4(const Operations* statechart){
unnamedOperation4.called = true;
return 0;
}
sc_integer operationsIface_unnamedOperation4a(const Operations* statechart, const sc_integer param1){
unnamedOperation4a.called = true;
unnamedOperation4a.param1 = param1;
return 0;
}
sc_string operationsIface_unnamedOperation5(const Operations* statechart){
unnamedOperation5.called = true;
return 0;
}
sc_string operationsIface_unnamedOperation5a(const Operations* statechart, const sc_string param1){
unnamedOperation5a.called = true;
unnamedOperation5a.param1 = param1;
return 0;
}
sc_boolean operationsIface_alwaysTrue(const Operations* statechart){
sc_boolean (AlwaysTrueMock::*func)() = alwaysTrueMock->alwaysTrueBehavior;
return (alwaysTrueMock->*func)();

}
