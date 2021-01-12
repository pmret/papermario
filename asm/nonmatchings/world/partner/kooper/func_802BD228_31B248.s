.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD228_31B248
/* 31B248 802BD228 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31B24C 802BD22C AFBF0014 */  sw        $ra, 0x14($sp)
/* 31B250 802BD230 AFB00010 */  sw        $s0, 0x10($sp)
/* 31B254 802BD234 10A00003 */  beqz      $a1, .L802BD244
/* 31B258 802BD238 8C90014C */   lw       $s0, 0x14c($a0)
/* 31B25C 802BD23C 0C03BB31 */  jal       func_800EECC4
/* 31B260 802BD240 0200202D */   daddu    $a0, $s0, $zero
.L802BD244:
/* 31B264 802BD244 0C03BB3A */  jal       func_800EECE8
/* 31B268 802BD248 0200202D */   daddu    $a0, $s0, $zero
/* 31B26C 802BD24C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 31B270 802BD250 8FB00010 */  lw        $s0, 0x10($sp)
/* 31B274 802BD254 0002102B */  sltu      $v0, $zero, $v0
/* 31B278 802BD258 03E00008 */  jr        $ra
/* 31B27C 802BD25C 27BD0018 */   addiu    $sp, $sp, 0x18
