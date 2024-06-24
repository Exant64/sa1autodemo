#!/bin/bash

for i in "${@:2}"; do
    args+=("${i//\//\\}")
done

"$1" "${args[@]}"

return_code=$?
exit $return_code