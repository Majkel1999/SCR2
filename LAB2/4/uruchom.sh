#!/bin/bash
if [ -e ./potok ]; then
	rm potok;
fi
mknod potok p
xterm -e ./pisz.sh hej -hold &
xterm -e ./pisz.sh witam -hold &
xterm -e ./czytaj.sh -hold &
xterm -e ./czytaj.sh -hold &
cat > potok
