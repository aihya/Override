i=1
while [[ $i -lt 22 ]]; do
    echo $i
    python -c "print 0x1337d00d - $i" | ./level03
    (( i++ ))
done
