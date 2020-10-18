.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD114_324F10
/* 324F24 802BD114 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 324F28 802BD118 AFBF0014 */  sw        $ra, 0x14($sp)
/* 324F2C 802BD11C AFB00010 */  sw        $s0, 0x10($sp)
/* 324F30 802BD120 10A00003 */  beqz      $a1, .L802BD130
/* 324F34 802BD124 8C90014C */   lw       $s0, 0x14c($a0)
/* 324F38 802BD128 0C03BB31 */  jal       func_800EECC4
/* 324F3C 802BD12C 0200202D */   daddu    $a0, $s0, $zero
.L802BD130:
/* 324F40 802BD130 0C03BB3A */  jal       func_800EECE8
/* 324F44 802BD134 0200202D */   daddu    $a0, $s0, $zero
/* 324F48 802BD138 8FBF0014 */  lw        $ra, 0x14($sp)
/* 324F4C 802BD13C 8FB00010 */  lw        $s0, 0x10($sp)
/* 324F50 802BD140 0002102B */  sltu      $v0, $zero, $v0
/* 324F54 802BD144 03E00008 */  jr        $ra
/* 324F58 802BD148 27BD0018 */   addiu    $sp, $sp, 0x18
