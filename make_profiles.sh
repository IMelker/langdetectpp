#!/bin/bash

git submodule update --init --recursive

#PROFILES=`ls external/langdetect/langdetect/profiles`
#echo $PROFILES

mkdir -p ./langdetectpp/src/profiles/langs

for PROFILE in `ls ./external/langdetect/langdetect/profiles`
do
    SOURCE=./external/langdetect/langdetect/profiles/${PROFILE}
    python ./scripts/transform_profile.py header $SOURCE > ./langdetectpp/src/profiles/langs/${PROFILE}.h
    python ./scripts/transform_profile.py impl $SOURCE > ./langdetectpp/src/profiles/langs/${PROFILE}.cpp
    echo $SOURCE
done
