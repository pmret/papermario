.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD1B0
/* 325120 802BD1B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 325124 802BD1B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 325128 802BD1B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 32512C 802BD1BC 10A00003 */  beqz      $a1, .L802BD1CC
/* 325130 802BD1C0 8C90014C */   lw       $s0, 0x14c($a0)
/* 325134 802BD1C4 0C03BA65 */  jal       func_800EE994
/* 325138 802BD1C8 0200202D */   daddu    $a0, $s0, $zero
.L802BD1CC:
/* 32513C 802BD1CC 0C03BA6E */  jal       func_800EE9B8
/* 325140 802BD1D0 0200202D */   daddu    $a0, $s0, $zero
/* 325144 802BD1D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 325148 802BD1D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 32514C 802BD1DC 0002102B */  sltu      $v0, $zero, $v0
/* 325150 802BD1E0 03E00008 */  jr        $ra
/* 325154 802BD1E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 325158 802BD1E8 00000000 */  nop       
/* 32515C 802BD1EC 00000000 */  nop       
