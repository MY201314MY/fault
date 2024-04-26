path=`pwd`
project=${path}/fault

BOARD=stm32f4_disco

west build -p --build-dir ${path}/build \
    --board ${BOARD} ${project} --no-sysbuild \

