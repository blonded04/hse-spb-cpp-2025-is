#!/bin/bash
set -euo pipefail
[ "$#" -ge 1 ] || (echo "Expected at least one argument: command to run" && exit 1)

rm -f 21-change-header.01.out
diff -w <("$@" 21-change-header.01.in 21-change-header.01.out) <(cat <<EOF
1 -4 3
EOF
)
cmp 21-change-header.01.{out,sol}
echo OK
