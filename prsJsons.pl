#!/usr/bin/perl
use warnings;
use strict;
use utf8;
use Encode;
use JSON;

my $cou=0;
my $i=0;
my $out="";
OUT: while(<STDIN>){
  $i++;
  chomp;
  my $one= eval{decode_json( $_ )};
  if($@) { warn "$i WARNING: $@"; }
  unless(exists($one->{"origin"}) && exists($one->{"agains"})){
    next OUT;
  }
  my $origin = $one->{"origin"};
  for my $type (@{$one->{"agains"}}){
    unless(exists($type->{"typed"})){
      next OUT;
    }
    unless($origin eq $type->{"typed"}){
      $cou++;
      $out .= encode("UTF-8",($origin." ".$type->{"typed"}."\n"));
    }
  }
}
print "$cou\n$out";
