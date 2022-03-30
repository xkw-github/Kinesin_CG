#!/bin/csh

rm -f run.tpr

#$dir/grompp -f sd.mdp -c init.gro -p input.top -n index.ndx -o run.tpr -maxwarn 1
#grompp -f sd.mdp -c init.gro -p input.top -n index.ndx -o run.tpr 
grompp -f sd.mdp -c init.gro -p input.top -o run.tpr 

#$dir/mdrun -s run.tpr -nt 2
#$dir/mdrun -s run.tpr -ntomp 4
mdrun -s run.tpr -noddcheck -nt 16

