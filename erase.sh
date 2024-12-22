#!/bin/bash

rm -f README.md
find src/common -type d -name 'flatbuffers' | xargs rm -r
find src/common -name '*.fbs' | xargs rm
# rm -r -f external/
