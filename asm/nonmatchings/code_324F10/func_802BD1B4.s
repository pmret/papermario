.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD1B4
/* 324FC4 802BD1B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 324FC8 802BD1B8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 324FCC 802BD1BC AFB00010 */  sw        $s0, 0x10($sp)
/* 324FD0 802BD1C0 10A00003 */  beqz      $a1, .L802BD1D0
/* 324FD4 802BD1C4 8C90014C */   lw       $s0, 0x14c($a0)
/* 324FD8 802BD1C8 0C03BA65 */  jal       func_800EE994
/* 324FDC 802BD1CC 0200202D */   daddu    $a0, $s0, $zero
.L802BD1D0:
/* 324FE0 802BD1D0 0C03BA6E */  jal       func_800EE9B8
/* 324FE4 802BD1D4 0200202D */   daddu    $a0, $s0, $zero
/* 324FE8 802BD1D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 324FEC 802BD1DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 324FF0 802BD1E0 0002102B */  sltu      $v0, $zero, $v0
/* 324FF4 802BD1E4 03E00008 */  jr        $ra
/* 324FF8 802BD1E8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 324FFC 802BD1EC 00000000 */  nop       
