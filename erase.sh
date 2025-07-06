#!/bin/bash

rm -f README.md
find src/common -type d -name 'flatbuffers' -print0 | xargs -0 rm -r
find src/common -name '*.fbs' -print0 | xargs -0 rm
# rm -r -f external/
