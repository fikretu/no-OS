#!/bin/bash

set -e

. ./ci/travis/lib.sh

build_default() {
    export CPPCHECK_OPTIONS="--inline-suppr ./projects/drivers/network/network.c"
    . ./ci/travis/build_projects.sh
    . ./ci/travis/cppcheck.sh
}

build_astyle() {
    . ./ci/travis/astyle.sh
}

build_${BUILD_TYPE:-default}
