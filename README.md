# libft_tester

How to Test the Project

This repository includes a tester to validate the libft implementation.

Steps

First, compile the library with bonus functions by running make bonus in the root of the project.

Then, navigate to the tester folder and run make m.

Output Meanings

During execution, the tester will display the following statuses:

OK → functional test passed
MOK → memory allocation test passed
KO → test failed
MKO → memory allocation/size failure
LEAKS.KO → memory leak detected

If no KO, MKO, or LEAKS.KO messages appear, your implementation passed all tests successfully.
