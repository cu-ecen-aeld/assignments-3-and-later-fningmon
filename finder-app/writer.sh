#!/bin/bash

#writer.sh

# Check for required arguments (filesdir and writestr)
if [ $# -ne 2 ]; then
  echo "Error: Please provide both full path filename and write string as arguments."
  exit 1
fi

# Store arguments in variables
filename="$1"
writestr="$2"

#rm $filename

mkdir -p "$(dirname "$filename")" && touch "$filename"

if ! echo "$writestr" >> $filename; then
    echo "Fail to write to $writestr to $filename"
    exit 1
fi

#echo "Success"
exit 0
