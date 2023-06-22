from pwn import *

p = process('./ssp_001')
context.log_level = 'debug'
