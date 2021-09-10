.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415B8_BD01A8
/* BD01A8 802415B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD01AC 802415BC AFB00010 */  sw        $s0, 0x10($sp)
/* BD01B0 802415C0 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD01B4 802415C4 0C090150 */  jal       func_80240540_BCF130
/* BD01B8 802415C8 0080802D */   daddu    $s0, $a0, $zero
/* BD01BC 802415CC 3C05FE36 */  lui       $a1, 0xfe36
/* BD01C0 802415D0 34A53C80 */  ori       $a1, $a1, 0x3c80
/* BD01C4 802415D4 8C4601C8 */  lw        $a2, 0x1c8($v0)
/* BD01C8 802415D8 0C0B2190 */  jal       evt_set_float_variable
/* BD01CC 802415DC 0200202D */   daddu    $a0, $s0, $zero
/* BD01D0 802415E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD01D4 802415E4 8FB00010 */  lw        $s0, 0x10($sp)
/* BD01D8 802415E8 24020002 */  addiu     $v0, $zero, 2
/* BD01DC 802415EC 03E00008 */  jr        $ra
/* BD01E0 802415F0 27BD0018 */   addiu    $sp, $sp, 0x18
