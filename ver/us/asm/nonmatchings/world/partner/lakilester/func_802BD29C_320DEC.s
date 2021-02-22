.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD29C_320DEC
/* 320DEC 802BD29C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 320DF0 802BD2A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 320DF4 802BD2A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 320DF8 802BD2A8 10A00003 */  beqz      $a1, .L802BD2B8
/* 320DFC 802BD2AC 8C90014C */   lw       $s0, 0x14c($a0)
/* 320E00 802BD2B0 0C03BB31 */  jal       func_800EECC4
/* 320E04 802BD2B4 0200202D */   daddu    $a0, $s0, $zero
.L802BD2B8:
/* 320E08 802BD2B8 0C03BB3A */  jal       func_800EECE8
/* 320E0C 802BD2BC 0200202D */   daddu    $a0, $s0, $zero
/* 320E10 802BD2C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 320E14 802BD2C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 320E18 802BD2C8 0002102B */  sltu      $v0, $zero, $v0
/* 320E1C 802BD2CC 03E00008 */  jr        $ra
/* 320E20 802BD2D0 27BD0018 */   addiu    $sp, $sp, 0x18
