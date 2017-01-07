#!/usr/bin/perl
use strict;
use warnings;

our $noshift = 0.1;
our $side = 0.1;

our $jp_noshift=[
  [split(//,'1234567890-^\\')],
  [split(//,'qwertyuiop@[')],
  [split(//,'asdfghjkl;:]')],
  [split(//,'zxcvbnm,./_')]
];
our $jp_shift=[
  [split(//,'!"#$%&\'()0=~|')],
  [split(//,'QWERTYUIOP`{')],
  [split(//,'ASDFGHJKL+*}')],
  [split(//,'ZXCVBNM<>?_')]
];
for(my $i=0;$i<=$#$jp_noshift;$i++){
  for(my $ii=0;$ii<=$#{$jp_noshift->[$i]};$ii++){
    if($jp_noshift->[$i][$ii] ne $jp_shift->[$i][$ii]){
      print "$jp_noshift->[$i][$ii] $jp_shift->[$i][$ii] $noshift\n";
    }
    if($ii>0){
      print "$jp_noshift->[$i][$ii] $jp_noshift->[$i][$ii-1] $side\n";
      print "$jp_shift->[$i][$ii] $jp_shift->[$i][$ii-1] $side\n";
    }
    if($i>0){
      if($#{$jp_noshift->[$i-1]}>=$ii){
        print "$jp_noshift->[$i][$ii] $jp_noshift->[$i-1][$ii] $side\n";
        print "$jp_shift->[$i][$ii] $jp_shift->[$i-1][$ii] $side\n";
      }
      if($#{$jp_noshift->[$i-1]}>=$ii+1){
        print "$jp_noshift->[$i][$ii] $jp_noshift->[$i-1][$ii+1] $side\n";
        print "$jp_shift->[$i][$ii] $jp_shift->[$i-1][$ii+1] $side\n";
      }
    }
  }
}
