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
package org.yakindu.sct.simulation.core.sexec.test;
import org.eclipse.xtext.junit4.InjectWith;
import org.eclipse.xtext.junit4.XtextRunner;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.yakindu.sct.model.sexec.ExecutionFlow;
import org.yakindu.sct.model.sexec.interpreter.test.util.AbstractExecutionFlowTest;
import org.yakindu.sct.model.sexec.interpreter.test.util.SExecInjectionProvider;
import org.yakindu.sct.test.models.SCTUnitTestModels;
import com.google.inject.Inject;
import static org.junit.Assert.assertTrue;
/**
 * Unit TestCase for EntryExitSelfTransition
 */
@SuppressWarnings("all")
@RunWith(XtextRunner.class)
@InjectWith(SExecInjectionProvider.class)
public class EntryExitSelfTransition extends AbstractExecutionFlowTest {
	@Before
	public void setup() throws Exception{
		ExecutionFlow flow = models.loadExecutionFlowFromResource("EntryExitSelfTransition.sct");
		initInterpreter(flow);
	}
	@Test
	public void selfTransitionToChildState() throws Exception {
		init();
		raiseEvent("e");
		interpreter.runCycle();
		assertTrue(getInteger("entries") == 1l);
		assertTrue(getInteger("exits") == 1l);
		assertTrue(isStateActive("C"));
		interpreter.exit();
	}
	@Test
	public void selfTransitionFromChildState() throws Exception {
		init();
		raiseEvent("e1");
		interpreter.runCycle();
		assertTrue(getInteger("entries") == 0l);
		assertTrue(getInteger("exits") == 0l);
		assertTrue(isStateActive("C"));
		raiseEvent("e1");
		interpreter.runCycle();
		assertTrue(isStateActive("B"));
		assertTrue(getInteger("entries") == 1l);
		assertTrue(getInteger("exits") == 1l);
		interpreter.exit();
	}
	public void init() throws Exception {
		interpreter.enter();
		interpreter.runCycle();
		assertTrue(getInteger("entries") == 1l);
		assertTrue(isStateActive("B"));
		setInteger("entries", 0l);
	}
}
