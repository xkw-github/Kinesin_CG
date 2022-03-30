#!/bin/csh


rm -rf tem.pdb coord.dat

echo 0 > a
trjconv -s run.tpr -f traj_comp.xtc  -n index.ndx -o tem.pdb < a
grep ATOM tem.pdb |awk '{print $6,$7,$8}' > coord.dat

gcc -lm contact.c
./a.out

rm -rf tem.pdb coord.dat

