#!/bin/bash

start_time=$(date +%s.%N) 
for ((i = 0; i < 10000; i++)); do
    (
        exit 0
    ) &
    child_pid=$! 
    wait "$child_pid" 
done

end_time=$(date +%s.%N) #

temps_passe=$(echo "$end_time - $start_time" | bc)
echo "Temps écoulé pour 10000 itérations : $temps_passe secondes"
