./quon_new compiler.qon > test.pl
perl test.pl compiler.qon > test2.pl
diff test.pl test2.pl
perl test2.pl > test3.pl
diff test2.pl test3.pl
