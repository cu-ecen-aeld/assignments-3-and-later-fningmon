#!/bin/bash

#finder.sh

#testing finder.sh

# Check for required arguments (filesdir and searchstr)
if [ $# -ne 2 ]; then
  echo "Error: Please provide both directory path and search string as arguments."
  exit 1
fi

# Store arguments in variables
filesdir="$1"
searchstr="$2"

# Check if filesdir is a directory
if [ ! -d "$filesdir" ]; then
  echo "Error: '$filesdir' is not a directory."
  exit 1
fi

# Find all files recursively and count them
total_files=$(find "$filesdir" -type f | wc -l)

# Find the number of matching lines containing searchstr
matching_lines=$(grep -r "$searchstr" "$filesdir" | wc -l)

# Print the final message
echo "The number of files are $total_files and the number of matching lines are $matching_lines"

exit 0
