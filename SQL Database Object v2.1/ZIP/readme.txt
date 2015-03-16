March 15, 2015

This is version 2.1 of the SQL Database Object. This component is provided free for personal, professional, and commercial use. 

Installation Instructions:

In this ZIP file, you will find sql.mfx file (main extension), an Examples directory with sample programs for each of MMF2 Standard and Developer, a Help directory containing documentation, and a database viewer helper program in the DBViewer directory. Plus this readme.txt file.

1. Put a copy of sql.mfx into the following 2 directories:
	(Multimedia Fusion 2 install folder)\Extensions\ 
	(Multimedia Fusion 2 install folder)\Data\Runtime\ 

2. Put the contents of the Help directory in this ZIP file into the Help directory under MMF install folder, so the result looks like:
	(Multimedia Fusion 2 install folder)\Help\SQLDB\SQLDB.htm (and 3 other files)

3. Put the SQLDB Viewer.exe program (found in the DBViewer directory) and the sample database somewhere convenient, it will be very useful to test out your SQL statements and see what is in your database. There is a small readme.txt file for this program in the DBViewer directory.

Installation is now complete.

To use:

- From an application in MMF2, drop the SQLDB object onto a frame. Click the Help button for detailed information and API reference.
- Now add events in your application to first open a new database, then start submitting SQL statements to the object. When your application ends, close the database file. 
- If you want to create a brand new database to use in your MMF application, you can do this through the object. Basically, just open a database that does not exist and it will be created. You then need to submit CREATE TABLE statements to it.
- Refer to the various examples, and I suggest you find a good SQL reference book.

JSJ






 
