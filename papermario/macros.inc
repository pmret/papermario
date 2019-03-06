# common macros

# F3D vertex
.macro vertex \x, \y, \z, \u, \v, \r=0xFF, \g=0xFF, \b=0xFF, \a=0xFF
   .hword \x, \y, \z, 0, \u, \v
   .byte \r, \g, \b, \a
.endm
