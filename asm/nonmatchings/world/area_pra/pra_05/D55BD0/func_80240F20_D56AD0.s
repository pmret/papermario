.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D56AD0
/* D56AD0 80240F20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D56AD4 80240F24 AFB00010 */  sw        $s0, 0x10($sp)
/* D56AD8 80240F28 3C108024 */  lui       $s0, %hi(D_80241680)
/* D56ADC 80240F2C 26101680 */  addiu     $s0, $s0, %lo(D_80241680)
/* D56AE0 80240F30 AFBF0018 */  sw        $ra, 0x18($sp)
/* D56AE4 80240F34 AFB10014 */  sw        $s1, 0x14($sp)
/* D56AE8 80240F38 8E020000 */  lw        $v0, ($s0)
/* D56AEC 80240F3C 14400010 */  bnez      $v0, .L80240F80
/* D56AF0 80240F40 0080882D */   daddu    $s1, $a0, $zero
/* D56AF4 80240F44 0C00AB39 */  jal       heap_malloc
/* D56AF8 80240F48 24040040 */   addiu    $a0, $zero, 0x40
/* D56AFC 80240F4C AE020000 */  sw        $v0, ($s0)
/* D56B00 80240F50 0000182D */  daddu     $v1, $zero, $zero
/* D56B04 80240F54 0040282D */  daddu     $a1, $v0, $zero
/* D56B08 80240F58 0220202D */  daddu     $a0, $s1, $zero
.L80240F5C:
/* D56B0C 80240F5C 8C820084 */  lw        $v0, 0x84($a0)
/* D56B10 80240F60 24840004 */  addiu     $a0, $a0, 4
/* D56B14 80240F64 24630001 */  addiu     $v1, $v1, 1
/* D56B18 80240F68 ACA20000 */  sw        $v0, ($a1)
/* D56B1C 80240F6C 28620010 */  slti      $v0, $v1, 0x10
/* D56B20 80240F70 1440FFFA */  bnez      $v0, .L80240F5C
/* D56B24 80240F74 24A50004 */   addiu    $a1, $a1, 4
/* D56B28 80240F78 080903EF */  j         .L80240FBC
/* D56B2C 80240F7C 00000000 */   nop      
.L80240F80:
/* D56B30 80240F80 0000182D */  daddu     $v1, $zero, $zero
/* D56B34 80240F84 0040282D */  daddu     $a1, $v0, $zero
/* D56B38 80240F88 0220202D */  daddu     $a0, $s1, $zero
.L80240F8C:
/* D56B3C 80240F8C 8CA20000 */  lw        $v0, ($a1)
/* D56B40 80240F90 24A50004 */  addiu     $a1, $a1, 4
/* D56B44 80240F94 24630001 */  addiu     $v1, $v1, 1
/* D56B48 80240F98 AC820084 */  sw        $v0, 0x84($a0)
/* D56B4C 80240F9C 28620010 */  slti      $v0, $v1, 0x10
/* D56B50 80240FA0 1440FFFA */  bnez      $v0, .L80240F8C
/* D56B54 80240FA4 24840004 */   addiu    $a0, $a0, 4
/* D56B58 80240FA8 3C108024 */  lui       $s0, %hi(D_80241680)
/* D56B5C 80240FAC 26101680 */  addiu     $s0, $s0, %lo(D_80241680)
/* D56B60 80240FB0 0C00AB4B */  jal       heap_free
/* D56B64 80240FB4 8E040000 */   lw       $a0, ($s0)
/* D56B68 80240FB8 AE000000 */  sw        $zero, ($s0)
.L80240FBC:
/* D56B6C 80240FBC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D56B70 80240FC0 8FB10014 */  lw        $s1, 0x14($sp)
/* D56B74 80240FC4 8FB00010 */  lw        $s0, 0x10($sp)
/* D56B78 80240FC8 24020002 */  addiu     $v0, $zero, 2
/* D56B7C 80240FCC 03E00008 */  jr        $ra
/* D56B80 80240FD0 27BD0020 */   addiu    $sp, $sp, 0x20
