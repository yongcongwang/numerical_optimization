#!/bin/bash
# By yongcong.wang @ 17/07/2022

export WORK_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/.."

cd ${WORK_PATH}
cmake -Bbuild -H.
make -C build -j$(nproc)

echo "Build successfully!"
