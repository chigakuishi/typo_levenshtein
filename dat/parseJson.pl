#!/usr/bin/perl
use strict;
use warnings;
use JSON;

my $json;
while(<STDIN>){
  chomp;
  s/^\s*//g;
  $json .= $_;
}
my $data_ref = decode_json($json);
my $cou=0;
my $out="";
for my $item (@{$data_ref}){
  unless($item->{"rpw"} eq $item->{"tpw"}){
    if($item->{"tpw"} eq ""){
      next;
    }
    $cou++;
    $out .= $item->{"rpw"}."\n".$item->{"tpw"}."\n";
  }
}
print "$cou\n$out";
