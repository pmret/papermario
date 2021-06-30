.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD27C_31CDEC
/* 31CDEC 802BD27C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31CDF0 802BD280 AFBF0014 */  sw        $ra, 0x14($sp)
/* 31CDF4 802BD284 AFB00010 */  sw        $s0, 0x10($sp)
/* 31CDF8 802BD288 10A00003 */  beqz      $a1, .L802BD298
/* 31CDFC 802BD28C 8C90014C */   lw       $s0, 0x14c($a0)
/* 31CE00 802BD290 0C03BB31 */  jal       partner_init_get_out
/* 31CE04 802BD294 0200202D */   daddu    $a0, $s0, $zero
.L802BD298:
/* 31CE08 802BD298 0C03BB3A */  jal       partner_get_out
/* 31CE0C 802BD29C 0200202D */   daddu    $a0, $s0, $zero
/* 31CE10 802BD2A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 31CE14 802BD2A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 31CE18 802BD2A8 0002102B */  sltu      $v0, $zero, $v0
/* 31CE1C 802BD2AC 03E00008 */  jr        $ra
/* 31CE20 802BD2B0 27BD0018 */   addiu    $sp, $sp, 0x18
