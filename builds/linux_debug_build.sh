head README
echo building
sh clean_build.sh

echo create product directory
mkdir product/
mkdir product/debug/

cd product/debug/

cmake ../../../
make
