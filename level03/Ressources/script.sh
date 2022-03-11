i=1
while [[ $i -lt 22 ]]; do
    echo -e '\n' $((322424845 - $i))
	(python -c "print 0x1337d00d - $i" ; cat) | ./level03
    (( i++ ))
done
