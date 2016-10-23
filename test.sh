#!/usr/bin/env bash

shopt -s globstar

testKadaiScripts() {
  assertEquals 1 1

  for i in **/*.c; do
    echo "Testing $i..."

    gcc -Wall "$i" -o temp -lm

    infile="test/$i.in.txt"
    outfile="test/$i.out.txt"
    headfile="test/$i.head.txt"
    tailfile="test/$i.tail.txt"
    matchfile="test/$i.match.txt"

    if test -e "$infile"; then
      result=`./temp < $infile`
    else
      result=`./temp 0<&-`
    fi

    if test -e "$outfile"; then
      expected=`cat "$outfile"`
      assertEquals "$expected" "$result"
    fi

    if test -e "$headfile"; then
      expected=`cat "$headfile"`
      assertTrue "<${result:0:1000}...> doesn't head with <$expected>" "[[ '$result' == '$expected'* ]]"
    fi

    if test -e "$tailfile"; then
      expected=`cat "$tailfile"`
      assertTrue "<${result:0:1000}...> doesn't tail with <$expected>" "[[ '$result' == *'$expected' ]]"
    fi

    if test -e "$matchfile"; then
      expected=`cat "$matchfile"`
      assertTrue "<${result:0:1000}...> doesn't include <$expected>" "[[ '$result' == *'$expected'* ]]"
    fi

    if test ! -e "$outfile" && test ! -e "$headfile" && test ! -e "$tailfile" && test ! -e "$matchfile"; then
      echo "WARNING: $i has no spec files"
    fi

    rm temp*
  done
}

. shunit2-master/source/2.1/src/shunit2
