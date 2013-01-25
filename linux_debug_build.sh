echo building
echo create build directory
sh clean_build.sh
mkdir build/
mkdir build/debug/
cd build/debug/

cmake ../../
make
