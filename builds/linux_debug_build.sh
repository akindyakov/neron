cat ../README
echo ------------------------------------------------------
echo generating makefiles
echo ------------------------------------------------------
sh clean_build.sh

echo create product directory
mkdir product/
mkdir product/debug/

cd product/debug/

cmake ../../../

echo ------------------------------------------------------
echo building 
echo ------------------------------------------------------

make
