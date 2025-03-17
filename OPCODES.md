# Register encodings
AX - `0xAA`
BX - `OxAB`
CX - `0xAC`
DX - `0xAD`
# MOV
## Move Register to Register
Example: `mov ax, bx`
Hex: `0xA0`
Output: `A0 AA AB`
## Move Value into Register
Example `mov ax, 0x4c`
Hex: `0xA1`
Output: `A1 AA 4C`
## Move Register into Pointer
Example `mov &0xB8000 bx`
Hex: `0xA2`
Output: `A2 B8 00 AB`
