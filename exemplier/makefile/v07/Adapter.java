/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "The make command" / Chapitre "Commande make"
 *
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 * Adapter.java
 * @author Alain Lebret
 * @version	1.0 – 1998
 */
class Adapter extends WindowAdapter {
	TestingFrame theTestingFrame = null;
       
	Adapter(TestingFrame aFrame) {
		this.theTestingFrame = aFrame;
	}
       
	public void windowClosing(WindowEvent we) {
		theTestingFrame.setVisible(false);
		System.exit(0);
	}
}