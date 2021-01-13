.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241468_EA9F48
/* EA9F48 80241468 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA9F4C 8024146C AFB00010 */  sw        $s0, 0x10($sp)
/* EA9F50 80241470 3C108024 */  lui       $s0, %hi(D_80243D74)
/* EA9F54 80241474 26103D74 */  addiu     $s0, $s0, %lo(D_80243D74)
/* EA9F58 80241478 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA9F5C 8024147C AFB10014 */  sw        $s1, 0x14($sp)
/* EA9F60 80241480 8E020000 */  lw        $v0, ($s0)
/* EA9F64 80241484 14400010 */  bnez      $v0, .L802414C8
/* EA9F68 80241488 0080882D */   daddu    $s1, $a0, $zero
/* EA9F6C 8024148C 0C00AFF5 */  jal       func_8002BFD4
/* EA9F70 80241490 24040040 */   addiu    $a0, $zero, 0x40
/* EA9F74 80241494 AE020000 */  sw        $v0, ($s0)
/* EA9F78 80241498 0000182D */  daddu     $v1, $zero, $zero
/* EA9F7C 8024149C 0040282D */  daddu     $a1, $v0, $zero
/* EA9F80 802414A0 0220202D */  daddu     $a0, $s1, $zero
.L802414A4:
/* EA9F84 802414A4 8C820084 */  lw        $v0, 0x84($a0)
/* EA9F88 802414A8 24840004 */  addiu     $a0, $a0, 4
/* EA9F8C 802414AC 24630001 */  addiu     $v1, $v1, 1
/* EA9F90 802414B0 ACA20000 */  sw        $v0, ($a1)
/* EA9F94 802414B4 28620010 */  slti      $v0, $v1, 0x10
/* EA9F98 802414B8 1440FFFA */  bnez      $v0, .L802414A4
/* EA9F9C 802414BC 24A50004 */   addiu    $a1, $a1, 4
/* EA9FA0 802414C0 08090541 */  j         .L80241504
/* EA9FA4 802414C4 00000000 */   nop
.L802414C8:
/* EA9FA8 802414C8 0000182D */  daddu     $v1, $zero, $zero
/* EA9FAC 802414CC 0040282D */  daddu     $a1, $v0, $zero
/* EA9FB0 802414D0 0220202D */  daddu     $a0, $s1, $zero
.L802414D4:
/* EA9FB4 802414D4 8CA20000 */  lw        $v0, ($a1)
/* EA9FB8 802414D8 24A50004 */  addiu     $a1, $a1, 4
/* EA9FBC 802414DC 24630001 */  addiu     $v1, $v1, 1
/* EA9FC0 802414E0 AC820084 */  sw        $v0, 0x84($a0)
/* EA9FC4 802414E4 28620010 */  slti      $v0, $v1, 0x10
/* EA9FC8 802414E8 1440FFFA */  bnez      $v0, .L802414D4
/* EA9FCC 802414EC 24840004 */   addiu    $a0, $a0, 4
/* EA9FD0 802414F0 3C108024 */  lui       $s0, %hi(D_80243D74)
/* EA9FD4 802414F4 26103D74 */  addiu     $s0, $s0, %lo(D_80243D74)
/* EA9FD8 802414F8 0C00B007 */  jal       func_8002C01C
/* EA9FDC 802414FC 8E040000 */   lw       $a0, ($s0)
/* EA9FE0 80241500 AE000000 */  sw        $zero, ($s0)
.L80241504:
/* EA9FE4 80241504 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA9FE8 80241508 8FB10014 */  lw        $s1, 0x14($sp)
/* EA9FEC 8024150C 8FB00010 */  lw        $s0, 0x10($sp)
/* EA9FF0 80241510 24020002 */  addiu     $v0, $zero, 2
/* EA9FF4 80241514 03E00008 */  jr        $ra
/* EA9FF8 80241518 27BD0020 */   addiu    $sp, $sp, 0x20
