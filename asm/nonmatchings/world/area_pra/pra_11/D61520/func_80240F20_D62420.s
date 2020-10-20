.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D62420
/* D62420 80240F20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D62424 80240F24 AFB00010 */  sw        $s0, 0x10($sp)
/* D62428 80240F28 3C108024 */  lui       $s0, 0x8024
/* D6242C 80240F2C 26101610 */  addiu     $s0, $s0, 0x1610
/* D62430 80240F30 AFBF0018 */  sw        $ra, 0x18($sp)
/* D62434 80240F34 AFB10014 */  sw        $s1, 0x14($sp)
/* D62438 80240F38 8E020000 */  lw        $v0, ($s0)
/* D6243C 80240F3C 14400010 */  bnez      $v0, .L80240F80
/* D62440 80240F40 0080882D */   daddu    $s1, $a0, $zero
/* D62444 80240F44 0C00AB39 */  jal       heap_malloc
/* D62448 80240F48 24040040 */   addiu    $a0, $zero, 0x40
/* D6244C 80240F4C AE020000 */  sw        $v0, ($s0)
/* D62450 80240F50 0000182D */  daddu     $v1, $zero, $zero
/* D62454 80240F54 0040282D */  daddu     $a1, $v0, $zero
/* D62458 80240F58 0220202D */  daddu     $a0, $s1, $zero
.L80240F5C:
/* D6245C 80240F5C 8C820084 */  lw        $v0, 0x84($a0)
/* D62460 80240F60 24840004 */  addiu     $a0, $a0, 4
/* D62464 80240F64 24630001 */  addiu     $v1, $v1, 1
/* D62468 80240F68 ACA20000 */  sw        $v0, ($a1)
/* D6246C 80240F6C 28620010 */  slti      $v0, $v1, 0x10
/* D62470 80240F70 1440FFFA */  bnez      $v0, .L80240F5C
/* D62474 80240F74 24A50004 */   addiu    $a1, $a1, 4
/* D62478 80240F78 080903EF */  j         .L80240FBC
/* D6247C 80240F7C 00000000 */   nop      
.L80240F80:
/* D62480 80240F80 0000182D */  daddu     $v1, $zero, $zero
/* D62484 80240F84 0040282D */  daddu     $a1, $v0, $zero
/* D62488 80240F88 0220202D */  daddu     $a0, $s1, $zero
.L80240F8C:
/* D6248C 80240F8C 8CA20000 */  lw        $v0, ($a1)
/* D62490 80240F90 24A50004 */  addiu     $a1, $a1, 4
/* D62494 80240F94 24630001 */  addiu     $v1, $v1, 1
/* D62498 80240F98 AC820084 */  sw        $v0, 0x84($a0)
/* D6249C 80240F9C 28620010 */  slti      $v0, $v1, 0x10
/* D624A0 80240FA0 1440FFFA */  bnez      $v0, .L80240F8C
/* D624A4 80240FA4 24840004 */   addiu    $a0, $a0, 4
/* D624A8 80240FA8 3C108024 */  lui       $s0, 0x8024
/* D624AC 80240FAC 26101610 */  addiu     $s0, $s0, 0x1610
/* D624B0 80240FB0 0C00AB4B */  jal       heap_free
/* D624B4 80240FB4 8E040000 */   lw       $a0, ($s0)
/* D624B8 80240FB8 AE000000 */  sw        $zero, ($s0)
.L80240FBC:
/* D624BC 80240FBC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D624C0 80240FC0 8FB10014 */  lw        $s1, 0x14($sp)
/* D624C4 80240FC4 8FB00010 */  lw        $s0, 0x10($sp)
/* D624C8 80240FC8 24020002 */  addiu     $v0, $zero, 2
/* D624CC 80240FCC 03E00008 */  jr        $ra
/* D624D0 80240FD0 27BD0020 */   addiu    $sp, $sp, 0x20
