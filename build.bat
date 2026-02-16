set -e

EXECUTABLE="ConfigCreator"

mkdir -p "build"
cd "build"

cmake ..

cmake --build . --config Debug

pause