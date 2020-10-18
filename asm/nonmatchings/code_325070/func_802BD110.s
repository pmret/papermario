.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD110
/* 325080 802BD110 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 325084 802BD114 AFBF0014 */  sw        $ra, 0x14($sp)
/* 325088 802BD118 AFB00010 */  sw        $s0, 0x10($sp)
/* 32508C 802BD11C 10A00003 */  beqz      $a1, .L802BD12C
/* 325090 802BD120 8C90014C */   lw       $s0, 0x14c($a0)
/* 325094 802BD124 0C03BB31 */  jal       func_800EECC4
/* 325098 802BD128 0200202D */   daddu    $a0, $s0, $zero
.L802BD12C:
/* 32509C 802BD12C 0C03BB3A */  jal       func_800EECE8
/* 3250A0 802BD130 0200202D */   daddu    $a0, $s0, $zero
/* 3250A4 802BD134 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3250A8 802BD138 8FB00010 */  lw        $s0, 0x10($sp)
/* 3250AC 802BD13C 0002102B */  sltu      $v0, $zero, $v0
/* 3250B0 802BD140 03E00008 */  jr        $ra
/* 3250B4 802BD144 27BD0018 */   addiu    $sp, $sp, 0x18
