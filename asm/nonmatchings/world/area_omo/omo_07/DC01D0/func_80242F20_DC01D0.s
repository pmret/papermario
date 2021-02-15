.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F20_DC01D0
/* DC01D0 80242F20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DC01D4 80242F24 AFB00010 */  sw        $s0, 0x10($sp)
/* DC01D8 80242F28 3C108024 */  lui       $s0, %hi(D_80245E00_DC30B0)
/* DC01DC 80242F2C 26105E00 */  addiu     $s0, $s0, %lo(D_80245E00_DC30B0)
/* DC01E0 80242F30 AFBF0018 */  sw        $ra, 0x18($sp)
/* DC01E4 80242F34 AFB10014 */  sw        $s1, 0x14($sp)
/* DC01E8 80242F38 8E020000 */  lw        $v0, ($s0)
/* DC01EC 80242F3C 14400010 */  bnez      $v0, .L80242F80
/* DC01F0 80242F40 0080882D */   daddu    $s1, $a0, $zero
/* DC01F4 80242F44 0C00AB39 */  jal       heap_malloc
/* DC01F8 80242F48 24040040 */   addiu    $a0, $zero, 0x40
/* DC01FC 80242F4C AE020000 */  sw        $v0, ($s0)
/* DC0200 80242F50 0000182D */  daddu     $v1, $zero, $zero
/* DC0204 80242F54 0040282D */  daddu     $a1, $v0, $zero
/* DC0208 80242F58 0220202D */  daddu     $a0, $s1, $zero
.L80242F5C:
/* DC020C 80242F5C 8C820084 */  lw        $v0, 0x84($a0)
/* DC0210 80242F60 24840004 */  addiu     $a0, $a0, 4
/* DC0214 80242F64 24630001 */  addiu     $v1, $v1, 1
/* DC0218 80242F68 ACA20000 */  sw        $v0, ($a1)
/* DC021C 80242F6C 28620010 */  slti      $v0, $v1, 0x10
/* DC0220 80242F70 1440FFFA */  bnez      $v0, .L80242F5C
/* DC0224 80242F74 24A50004 */   addiu    $a1, $a1, 4
/* DC0228 80242F78 08090BEF */  j         .L80242FBC
/* DC022C 80242F7C 00000000 */   nop
.L80242F80:
/* DC0230 80242F80 0000182D */  daddu     $v1, $zero, $zero
/* DC0234 80242F84 0040282D */  daddu     $a1, $v0, $zero
/* DC0238 80242F88 0220202D */  daddu     $a0, $s1, $zero
.L80242F8C:
/* DC023C 80242F8C 8CA20000 */  lw        $v0, ($a1)
/* DC0240 80242F90 24A50004 */  addiu     $a1, $a1, 4
/* DC0244 80242F94 24630001 */  addiu     $v1, $v1, 1
/* DC0248 80242F98 AC820084 */  sw        $v0, 0x84($a0)
/* DC024C 80242F9C 28620010 */  slti      $v0, $v1, 0x10
/* DC0250 80242FA0 1440FFFA */  bnez      $v0, .L80242F8C
/* DC0254 80242FA4 24840004 */   addiu    $a0, $a0, 4
/* DC0258 80242FA8 3C108024 */  lui       $s0, %hi(D_80245E00_DC30B0)
/* DC025C 80242FAC 26105E00 */  addiu     $s0, $s0, %lo(D_80245E00_DC30B0)
/* DC0260 80242FB0 0C00AB4B */  jal       heap_free
/* DC0264 80242FB4 8E040000 */   lw       $a0, ($s0)
/* DC0268 80242FB8 AE000000 */  sw        $zero, ($s0)
.L80242FBC:
/* DC026C 80242FBC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DC0270 80242FC0 8FB10014 */  lw        $s1, 0x14($sp)
/* DC0274 80242FC4 8FB00010 */  lw        $s0, 0x10($sp)
/* DC0278 80242FC8 24020002 */  addiu     $v0, $zero, 2
/* DC027C 80242FCC 03E00008 */  jr        $ra
/* DC0280 80242FD0 27BD0020 */   addiu    $sp, $sp, 0x20
