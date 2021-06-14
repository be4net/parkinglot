# Any target can be built right at the top of the tree. No need to manually run cmake.
#
# Example:
#   git clone "project-name.git"
#   cd "project-name"
#   make
#
# Adding the prefix "cmake_" sets variables in the cmake cache.

# Default target
all:

BASE_DIR=$(shell pwd)
BULD_DIR=./build

# Magic: Delegate all targets to cmake-generated Makefile
%:
# More magic: pass cmake_ variables as cmake cache variables.
	@env | awk '/^cmake_/ {printf("-D%s\0", substr($$0,7))}' | xargs -0 sh -c 'test $$# = 0 -a -f ${BULD_DIR}/Makefile || cmake -H./src \
	-B${BULD_DIR} \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
	-DAPPL_BASE_DIR=${BASE_DIR} \
	-G"CodeBlocks - Unix Makefiles" "$$@"' - && exec $(MAKE) -C ${BULD_DIR} $@     # No Magic, just run make in build directory
