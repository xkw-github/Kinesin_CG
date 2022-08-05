#!/bin/csh

awk '{print $1,$2,sqrt($5*6/5/$4)}' phi.27839.pdb.sb/pair > A
awk '{print $1,$2,sqrt($5*6/5/$4)}' ATP.27842.pdb.sb/pair > B
cat A B > all
cp phi.27839.pdb.sb/phi.27839.pdb.top input.top
gcc -lm transfer.c 
./a.out > pair

#awk '{if(($2-$1)>3) print $0}' pair > tem
#mv tem pair

awk '{printf "%6d%7d\n",$1,$2}' pair > ex


set a = `awk '{if($2~/pairs/) print NR+1}' input.top`
set b = `awk '{if($2~/bonds/) print NR-2}' input.top`
set c = `awk '{if($2~/exclusion/) print NR+1}' input.top`
set d = `awk '{if($2~/angle/) print NR-2}' input.top`
set m = `awk '{if($2~/dihedral/) print NR+1}' input.top`
set n = `awk '{if($2~/system/) print NR-2}' input.top`

sed -e $a,"$b"d -e $c,"$d"d -e $m,"$n"d input.top > tem.top
sed "s/gen-pairs/xx/g;s/0.167772160E-04/0.906573791E-05/g;s/Macromolecule           3/Macromolecule           2/g" tem.top > tem1.top

set a = `awk '{if($2~/pairs/) print NR}' tem1.top`
sed -e '/pairs/r pair' -e '/exclusions/r ex' tem1.top > input.top
rm tem.top tem1.top tem2.top -f
rm ex pair -f
