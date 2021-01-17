#!/bin/bash
perl test1.pl compiler.qon --perl > test2.pl
diff test1.pl test2.pl
perl test2.pl compiler.qon --perl > test1.pl
diff test1.pl test2.pl
