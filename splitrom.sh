if [ ! -f ./n64splitter/bin/n64split ];
then
    cd ./n64splitter
    mkdir -p ./bin
    export C_INCLUDE_PATH=../n64splitter:./ext:/usr/local/Cellar/capstone/4.0.1/include/:/usr/local/Cellar/libyaml/0.2.1/include
    export LIBRARY_PATH=/usr/local/opt/capstone/lib/:/usr/local/Cellar/libyaml/0.2.1/lib:/usr/local/Cellar/libpng/1.6.36/lib
    make
    cd ..
fi
./n64splitter/bin/n64split -v -o papermario -c PAPER_MARIO.u.yaml baserom.z64
