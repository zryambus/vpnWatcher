baseDir=$(pwd)

if [ -d "shared/include" ]; then
    rm -rf shared/include/*
else
    mkdir shared/include
fi

# prepare includes
# Pistache
ln -s $baseDir/shared/external/pistache/include/ $baseDir/shared/include/pistache

# Msgpack
ln -s $baseDir/shared/external/msgpack-c/include/* $baseDir/shared/include/


# end prepare includes

