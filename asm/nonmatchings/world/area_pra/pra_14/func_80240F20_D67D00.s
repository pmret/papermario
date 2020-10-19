.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D68C20
/* D68C20 80240F20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D68C24 80240F24 AFB00010 */  sw        $s0, 0x10($sp)
/* D68C28 80240F28 3C108024 */  lui       $s0, 0x8024
/* D68C2C 80240F2C 26101930 */  addiu     $s0, $s0, 0x1930
/* D68C30 80240F30 AFBF0018 */  sw        $ra, 0x18($sp)
/* D68C34 80240F34 AFB10014 */  sw        $s1, 0x14($sp)
/* D68C38 80240F38 8E020000 */  lw        $v0, ($s0)
/* D68C3C 80240F3C 14400010 */  bnez      $v0, .L80240F80
/* D68C40 80240F40 0080882D */   daddu    $s1, $a0, $zero
/* D68C44 80240F44 0C00AB39 */  jal       heap_malloc
/* D68C48 80240F48 24040040 */   addiu    $a0, $zero, 0x40
/* D68C4C 80240F4C AE020000 */  sw        $v0, ($s0)
/* D68C50 80240F50 0000182D */  daddu     $v1, $zero, $zero
/* D68C54 80240F54 0040282D */  daddu     $a1, $v0, $zero
/* D68C58 80240F58 0220202D */  daddu     $a0, $s1, $zero
.L80240F5C:
/* D68C5C 80240F5C 8C820084 */  lw        $v0, 0x84($a0)
/* D68C60 80240F60 24840004 */  addiu     $a0, $a0, 4
/* D68C64 80240F64 24630001 */  addiu     $v1, $v1, 1
/* D68C68 80240F68 ACA20000 */  sw        $v0, ($a1)
/* D68C6C 80240F6C 28620010 */  slti      $v0, $v1, 0x10
/* D68C70 80240F70 1440FFFA */  bnez      $v0, .L80240F5C
/* D68C74 80240F74 24A50004 */   addiu    $a1, $a1, 4
/* D68C78 80240F78 080903EF */  j         .L80240FBC
/* D68C7C 80240F7C 00000000 */   nop      
.L80240F80:
/* D68C80 80240F80 0000182D */  daddu     $v1, $zero, $zero
/* D68C84 80240F84 0040282D */  daddu     $a1, $v0, $zero
/* D68C88 80240F88 0220202D */  daddu     $a0, $s1, $zero
.L80240F8C:
/* D68C8C 80240F8C 8CA20000 */  lw        $v0, ($a1)
/* D68C90 80240F90 24A50004 */  addiu     $a1, $a1, 4
/* D68C94 80240F94 24630001 */  addiu     $v1, $v1, 1
/* D68C98 80240F98 AC820084 */  sw        $v0, 0x84($a0)
/* D68C9C 80240F9C 28620010 */  slti      $v0, $v1, 0x10
/* D68CA0 80240FA0 1440FFFA */  bnez      $v0, .L80240F8C
/* D68CA4 80240FA4 24840004 */   addiu    $a0, $a0, 4
/* D68CA8 80240FA8 3C108024 */  lui       $s0, 0x8024
/* D68CAC 80240FAC 26101930 */  addiu     $s0, $s0, 0x1930
/* D68CB0 80240FB0 0C00AB4B */  jal       heap_free
/* D68CB4 80240FB4 8E040000 */   lw       $a0, ($s0)
/* D68CB8 80240FB8 AE000000 */  sw        $zero, ($s0)
.L80240FBC:
/* D68CBC 80240FBC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D68CC0 80240FC0 8FB10014 */  lw        $s1, 0x14($sp)
/* D68CC4 80240FC4 8FB00010 */  lw        $s0, 0x10($sp)
/* D68CC8 80240FC8 24020002 */  addiu     $v0, $zero, 2
/* D68CCC 80240FCC 03E00008 */  jr        $ra
/* D68CD0 80240FD0 27BD0020 */   addiu    $sp, $sp, 0x20
