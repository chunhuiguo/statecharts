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
import org.yakindu.scr.namedinterfaceaccess.NamedInterfaceAccessStatemachine;
import org.yakindu.scr.namedinterfaceaccess.NamedInterfaceAccessStatemachine.State;	

/**
 * Unit TestCase for NamedInterfaceAccess
 */
@SuppressWarnings("all")
public class NamedInterfaceAccess {
	
	private NamedInterfaceAccessStatemachine statemachine;	
	
	
	
	@Before
	public void namedInterfaceAccess_setUp() {
		statemachine = new NamedInterfaceAccessStatemachine();
		statemachine.init();
	}

	@After
	public void namedInterfaceAccess_tearDown() {
		statemachine = null;
	}
	
	@Test
	public void safeOpenSuccess() {
		statemachine.enter();
		statemachine.runCycle();
		statemachine.getSCIUser().raiseNumberPressed(3l);
		statemachine.runCycle();
		statemachine.getSCIUser().raiseNumberPressed(7l);
		statemachine.runCycle();
		statemachine.getSCIUser().raiseNumberPressed(5l);
		statemachine.runCycle();
		assertTrue(statemachine.getSCISafe().isRaisedOpen());
	}
}
