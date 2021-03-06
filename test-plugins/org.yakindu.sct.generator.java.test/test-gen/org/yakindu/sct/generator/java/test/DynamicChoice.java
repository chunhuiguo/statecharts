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

package org.yakindu.sct.generator.java.test;

import org.junit.*;
import static org.junit.Assert.*;
import org.yakindu.scr.dynamicchoice.DynamicChoiceStatemachine;
import org.yakindu.scr.dynamicchoice.DynamicChoiceStatemachine.State;	

/**
 * Unit TestCase for DynamicChoice
 */
@SuppressWarnings("all")
public class DynamicChoice {
	
	private DynamicChoiceStatemachine statemachine;	
	
	
	
	@Before
	public void dynamicChoice_setUp() {
		statemachine = new DynamicChoiceStatemachine();
		statemachine.init();
	}

	@After
	public void dynamicChoice_tearDown() {
		statemachine = null;
	}
	
	@Test
	public void dynamicChoiceTest() {
		statemachine.enter();
		assertTrue(statemachine.isStateActive(State.main_region_Start));
		statemachine.runCycle();
		assertTrue(statemachine.isStateActive(State.main_region_A));
	}
}
