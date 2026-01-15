#!/bin/bash
set -euo pipefail

rm -rf 03-logger-{plain,tagged}.out

echo -n "Running... "
./03-logger >03-logger.cout.out 2>03-logger.cerr.out && echo PASS  || { echo -e "\e[31;1mFAIL\e[0m"; exit 1; }

echo -n "Checking cout... "
diff -w <(cat <<EOF
This should go to cout with no tag (1/2)
This should go to cout with no tag (2/2)
[MYTAG] This should go to cout with a tag (1/2)
[MYTAG] This should go to cout with a tag (2/2)
EOF
) 03-logger.cout.out && echo PASS || { echo -e "\e[31;1mFAIL\e[0m"; exit 1; }

echo -n "Checking cerr... "
diff -w <(cat <<EOF
This should go to cerr with no tag (1/2)
This should go to cerr with no tag (2/2)
[MYTAG] This should go to cerr with a tag (1/2)
[MYTAG] This should go to cerr with a tag (2/2)
EOF
) 03-logger.cerr.out && echo PASS || { echo -e "\e[31;1mFAIL\e[0m"; exit 1; }

echo -n "Checking plain file... "
diff -w <(cat <<EOF
This should go to file with no tag (1/2)
This should go to file with no tag (2/2)
EOF
) 03-logger-plain.out && echo PASS || { echo -e "\e[31;1mFAIL\e[0m"; exit 1; }

echo -n "Checking tagged file... "
diff -w <(cat <<EOF
[MYTAG] This should go to file with a tag (1/2)
[MYTAG] This should go to file with a tag (2/2)
EOF
) 03-logger-tagged.out && echo PASS || { echo -e "\e[31;1mFAIL\e[0m"; exit 1; }

echo -e "===== \e[32;1mALL PASS\e[0m ====="
