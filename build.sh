#!/bin/sh

project_home=`dirname $0`
profile=$1

valid_profile="yes"
case ${profile} in
    debug | release)
        ;;
    * )
        echo "please select throw following build version:"
        echo "* debug"
        echo "* release"
        valid_profile="false"
        ;;
esac
if [ "yes" != "${valid_profile}" ] ; then
    exit 1
fi

build_dir="${project_home}/build"
current_output_dir="${build_dir}/${profile}"

rm -rf "${current_output_dir}"
mkdir -p "${current_output_dir}"

cd "${current_output_dir}"
cmake -DCMAKE_BUILD_TYPE=${profile} ../..
make
