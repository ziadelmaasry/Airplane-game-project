void welcome()
{
	glColor3f(0.3,0.56,0.84);   //welcome background
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0);
	glColor3f(0.137,0.137,0.556);
	glVertex3f(100.0,0.0,0.0);
	glColor3f(0.196,0.196,0.8);
	glVertex3f(100.0,100.0,0.0);
	glVertex3f(0.0,100.0,0.0);
	glEnd();
	drawJet();

	// button 1 .. PLAY
	glColor3f(0.196,0.196,0.8);
	glRectf(39.5,39.5,60.5,45.5);

	glColor3f(0.8,0.8,0.8);
	glRectf(40,40,60,45);
	glColor3f(0.137,0.137,0.556);
	drawString(47,42,0,GLUT_BITMAP_HELVETICA_18,"PLAY");

	// button 2 .. instructions
	glColor3f(0.196,0.196,0.8);
	glRectf(39.5,29.5,60.5,35.5);

	glColor3f(0.8,0.8,0.8);
	glRectf(40,30,60,35);
	glColor3f(0.137,0.137,0.556);
	drawString(41,31,0,GLUT_BITMAP_HELVETICA_18,"INSTRUCTIONS");

	// button 3 .. ABOUT
	glColor3f(0.196,0.196,0.8);
	glRectf(39.5,19.5,60.5,25.5);

	glColor3f(0.8,0.8,0.8);
	glRectf(40,20,60,25);
	glColor3f(0.137,0.137,0.556);
	drawString(46,21,0,GLUT_BITMAP_HELVETICA_18,"ABOUT");

	// button 4 .. exit
	glColor3f(0.196,0.196,0.8);
	glRectf(39.5,9.5,60.5,15.5);

	glColor3f(0.8,0.8,0.8);
	glRectf(40,10,60,15);
	glColor3f(0.137,0.137,0.556);
	drawString(47,11,0,GLUT_BITMAP_HELVETICA_18,"EXIT");


	glPushMatrix();

	glColor3f(0.8,0.8,0.8);
	drawString(25.5,92,0,GLUT_BITMAP_TIMES_ROMAN_24,"Simulation For Real-world Events of Airplane");
	drawString(35.5,80,0,GLUT_BITMAP_TIMES_ROMAN_24,"AIRPLANE GAME");
	glPopMatrix();
	glColor3f(0.137,0.137,0.556);

}

void drawBuilding()
{
	glPushMatrix();						// 3D part
	if(buildColor==0)
		glColor3f(0.1,0.0,0.0);
	else if (buildColor ==1)
		glColor3f(0.1,0.1,0.0);
	else
		glColor3f(0.0,0.1,0.1);

	glTranslatef(b.block_x,b.no_floors*10.0+10,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(5.0,3.0,0.0);
	glVertex3f(20.0,3.0,0.0);
	glVertex3f(20.0,-b.no_floors*10.0,0.0);
	glVertex3f(0.0,-b.no_floors*10.0,0.0);
	glEnd();
	glPopMatrix();

	for(int i=1;i<=b.no_floors;i++)
	{
		glPushMatrix();

		if(buildColor==0)
			glColor3f(0.8,0.0,0.0);
		else if (buildColor ==1)
			glColor3f(0.8,0.8,0.0);
		else
			glColor3f(0.0,0.8,0.8);

		glTranslatef(b.block_x,10.0*i,0.0);   //base
		glBegin(GL_POLYGON);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(15.0,0.0,0.0);
		glVertex3f(15.0,10.0,0.0);
		glVertex3f(0.0,10.0,0.0);
		glEnd();
		glColor3f(1.0,1.0,1.0);     // left window
		glBegin(GL_POLYGON);
		glVertex3f(2.5,5.0,0.0);
		glVertex3f(5.5,5.0,0.0);
		glVertex3f(5.5,8.0,0.0);
		glVertex3f(2.5,8.0,0.0);
		glEnd();
		glColor3f(1.0,1.0,1.0);     // left window
		glBegin(GL_POLYGON);
		glVertex3f(2.5,0.0,0.0);
		glVertex3f(5.5,0.0,0.0);
		glVertex3f(5.5,3.0,0.0);
		glVertex3f(2.5,3.0,0.0);
		glEnd();
		glColor3f(1.0,1.0,1.0);     // right window
		glBegin(GL_POLYGON);
		glVertex3f(12.5,5.0,0.0);
		glVertex3f(9.5,5.0,0.0);
		glVertex3f(9.5,8.0,0.0);
		glVertex3f(12.5,8.0,0.0);
		glEnd();
		glColor3f(1.0,1.0,1.0);     // right window
		glBegin(GL_POLYGON);
		glVertex3f(12.5,.0,0.0);
		glVertex3f(9.5,0.0,0.0);
		glVertex3f(9.5,3.0,0.0);
		glVertex3f(12.5,3.0,0.0);
		glEnd();
		glPopMatrix();
	}
	glPushMatrix();

	if(buildColor==0)
		glColor3f(0.8,0.0,0.0);
	else if (buildColor ==1)
		glColor3f(0.8,0.8,0.0);
	else
		glColor3f(0.0,0.8,0.8);

	glTranslatef(b.block_x,10.0,0.0);   //base
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(15.0,0.0,0.0);
	glVertex3f(15.0,10.0,0.0);
	glVertex3f(0.0,10.0,0.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);     // door
	glBegin(GL_POLYGON);
	glVertex3f(5.5,0.0,0.0);
	glVertex3f(9.5,0.0,0.0);
	glVertex3f(9.5,6.0,0.0);
	glVertex3f(5.5,6.0,0.0);
	glEnd();
	glPopMatrix();
}

void drawCloud()
{
	glColor3f(1.0,1.0,1.0);
	glTranslatef(s.block_x,s.block_y,0.0);
	glutSolidSphere(5,100,10);
	glTranslatef(6,-3.0,0.0);
	glutSolidSphere(5,100,10);
	glTranslatef(0,6.0,0.0);
	glutSolidSphere(5,100,10);
	glTranslatef(6,-3.0,0.0);
	glutSolidSphere(5,100,10);

}
