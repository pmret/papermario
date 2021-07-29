.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AD40
/* E1440 8014AD40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E1444 8014AD44 AFB00010 */  sw        $s0, 0x10($sp)
/* E1448 8014AD48 3C108016 */  lui       $s0, %hi(gMusicSettings)
/* E144C 8014AD4C 26109AF0 */  addiu     $s0, $s0, %lo(gMusicSettings)
/* E1450 8014AD50 AFB10014 */  sw        $s1, 0x14($sp)
/* E1454 8014AD54 0000882D */  daddu     $s1, $zero, $zero
/* E1458 8014AD58 AFBF0018 */  sw        $ra, 0x18($sp)
.L8014AD5C:
/* E145C 8014AD5C 96020000 */  lhu       $v0, ($s0)
/* E1460 8014AD60 30420001 */  andi      $v0, $v0, 1
/* E1464 8014AD64 10400006 */  beqz      $v0, .L8014AD80
/* E1468 8014AD68 26310001 */   addiu    $s1, $s1, 1
/* E146C 8014AD6C 8E040018 */  lw        $a0, 0x18($s0)
/* E1470 8014AD70 0C01567F */  jal       func_800559FC
/* E1474 8014AD74 00000000 */   nop
/* E1478 8014AD78 14400005 */  bnez      $v0, .L8014AD90
/* E147C 8014AD7C 24020001 */   addiu    $v0, $zero, 1
.L8014AD80:
/* E1480 8014AD80 2A220002 */  slti      $v0, $s1, 2
/* E1484 8014AD84 1440FFF5 */  bnez      $v0, .L8014AD5C
/* E1488 8014AD88 26100030 */   addiu    $s0, $s0, 0x30
/* E148C 8014AD8C 0000102D */  daddu     $v0, $zero, $zero
.L8014AD90:
/* E1490 8014AD90 8FBF0018 */  lw        $ra, 0x18($sp)
/* E1494 8014AD94 8FB10014 */  lw        $s1, 0x14($sp)
/* E1498 8014AD98 8FB00010 */  lw        $s0, 0x10($sp)
/* E149C 8014AD9C 03E00008 */  jr        $ra
/* E14A0 8014ADA0 27BD0020 */   addiu    $sp, $sp, 0x20
