.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026E260
/* 19CB40 8026E260 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19CB44 8026E264 AFB20018 */  sw        $s2, 0x18($sp)
/* 19CB48 8026E268 0080902D */  daddu     $s2, $a0, $zero
/* 19CB4C 8026E26C AFBF001C */  sw        $ra, 0x1c($sp)
/* 19CB50 8026E270 AFB10014 */  sw        $s1, 0x14($sp)
/* 19CB54 8026E274 AFB00010 */  sw        $s0, 0x10($sp)
/* 19CB58 8026E278 8E50000C */  lw        $s0, 0xc($s2)
/* 19CB5C 8026E27C 8E050000 */  lw        $a1, ($s0)
/* 19CB60 8026E280 0C0B1EAF */  jal       get_variable
/* 19CB64 8026E284 26100004 */   addiu    $s0, $s0, 4
/* 19CB68 8026E288 0040882D */  daddu     $s1, $v0, $zero
/* 19CB6C 8026E28C 8E050000 */  lw        $a1, ($s0)
/* 19CB70 8026E290 0C0B1EAF */  jal       get_variable
/* 19CB74 8026E294 0240202D */   daddu    $a0, $s2, $zero
/* 19CB78 8026E298 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19CB7C 8026E29C 16220002 */  bne       $s1, $v0, .L8026E2A8
/* 19CB80 8026E2A0 00000000 */   nop
/* 19CB84 8026E2A4 8E510148 */  lw        $s1, 0x148($s2)
.L8026E2A8:
/* 19CB88 8026E2A8 0C09A75B */  jal       get_actor
/* 19CB8C 8026E2AC 0220202D */   daddu    $a0, $s1, $zero
/* 19CB90 8026E2B0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19CB94 8026E2B4 8FB20018 */  lw        $s2, 0x18($sp)
/* 19CB98 8026E2B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 19CB9C 8026E2BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 19CBA0 8026E2C0 24020002 */  addiu     $v0, $zero, 2
/* 19CBA4 8026E2C4 03E00008 */  jr        $ra
/* 19CBA8 8026E2C8 27BD0020 */   addiu    $sp, $sp, 0x20
