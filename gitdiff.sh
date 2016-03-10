#!/usr/bin/sh

echo "Listing changes for super module"
git diff $1 --name-only
subs=(`git submodule | awk '{print $2}'`)
for sub in ${subs[*]}; do
   lastrevision=`git diff  $1 $sub | fgrep "Subproject" | head -n1 | awk '{print $3}'`
   cd $sub
   echo "Listing changes for $sub"
   git diff $lastrevision --name-only
   cd ..
done

