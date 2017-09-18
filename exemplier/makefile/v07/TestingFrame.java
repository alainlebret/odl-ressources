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
 * Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
 */
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
 
/**
 * TestingFrame.java
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version	1.0 – 1998
 */
public class TestingFrame extends Frame implements MouseListener {
	int x=0, y=0;
	String strEvent = "";
       
	TestingFrame(String title) {
		super(title);               
		addWindowListener(new Adapter(this));
		addMouseListener(this);
		setSize(500,500);
		setVisible(true);
	}
       
	public void mouseClicked(MouseEvent e) {
		strEvent = "MouseClicked";
		x = e.getX();
		y = getY();
		repaint();
 	}
	
	public void mousePressed(MouseEvent e) {
		strEvent = "MousePressed";
		x = e.getX();
		y = getY();
		repaint();
	}
 
 	public void mouseReleased(MouseEvent e) {
		strEvent = "MouseReleased";
		x = e.getX();
		y = getY();
		repaint();
 	}
 
	public void mouseEntered(MouseEvent e) {
		strEvent = "MouseEntered";
		x = e.getX();
		y = getY();
		repaint();
 	}
 
	public void mouseExited(MouseEvent e) {
 	   strEvent = "MouseExited";
	   x = e.getX();
	   y = getY();
	   repaint();
 	}
       
	public void paint(Graphics g){
		g.drawString(strEvent + " at " + x + "," + y, 100,100);
	}
       
	public static void main(String[] args) {
		TestingFrame theFrame = new TestingFrame("Frame responding to mouse events");
	}
}
