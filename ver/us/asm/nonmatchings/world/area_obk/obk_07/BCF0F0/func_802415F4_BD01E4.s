.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415F4_BD01E4
/* BD01E4 802415F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD01E8 802415F8 AFB00010 */  sw        $s0, 0x10($sp)
/* BD01EC 802415FC AFBF0014 */  sw        $ra, 0x14($sp)
/* BD01F0 80241600 0C090150 */  jal       func_80240540_BCF130
/* BD01F4 80241604 0080802D */   daddu    $s0, $a0, $zero
/* BD01F8 80241608 3C05FE36 */  lui       $a1, 0xfe36
/* BD01FC 8024160C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* BD0200 80241610 8C4601CC */  lw        $a2, 0x1cc($v0)
/* BD0204 80241614 0C0B2190 */  jal       set_float_variable
/* BD0208 80241618 0200202D */   daddu    $a0, $s0, $zero
/* BD020C 8024161C 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD0210 80241620 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0214 80241624 24020002 */  addiu     $v0, $zero, 2
/* BD0218 80241628 03E00008 */  jr        $ra
/* BD021C 8024162C 27BD0018 */   addiu    $sp, $sp, 0x18
