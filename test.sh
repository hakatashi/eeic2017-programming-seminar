#!/usr/bin/env bash

shopt -s globstar

testKadaiScripts() {
  assertEquals 1 1

  for i in **/*.c; do
    echo "Testing $i..."

    gcc -Wall "$i" -o temp

    infile="test/$i.in.txt"
    outfile="test/$i.out.txt"
    headfile="test/$i.head.txt"

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
      assertTrue "<${result:0:1000}...> did not head with <$expected>" "[[ '$result' == '$expected'* ]]"
    fi
  done
}

. shunit2-master/source/2.1/src/shunit2
