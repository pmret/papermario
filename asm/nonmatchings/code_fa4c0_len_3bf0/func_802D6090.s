.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D6090
/* FAA40 802D6090 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FAA44 802D6094 AFB10014 */  sw        $s1, 0x14($sp)
/* FAA48 802D6098 0080882D */  daddu     $s1, $a0, $zero
/* FAA4C 802D609C AFBF0018 */  sw        $ra, 0x18($sp)
/* FAA50 802D60A0 AFB00010 */  sw        $s0, 0x10($sp)
/* FAA54 802D60A4 8E30000C */  lw        $s0, 0xc($s1)
/* FAA58 802D60A8 8E050000 */  lw        $a1, ($s0)
/* FAA5C 802D60AC 0C0B1EAF */  jal       get_variable
/* FAA60 802D60B0 26100004 */   addiu    $s0, $s0, 4
/* FAA64 802D60B4 0220202D */  daddu     $a0, $s1, $zero
/* FAA68 802D60B8 8E050000 */  lw        $a1, ($s0)
/* FAA6C 802D60BC 0C0B1EAF */  jal       get_variable
/* FAA70 802D60C0 0040802D */   daddu    $s0, $v0, $zero
/* FAA74 802D60C4 0200202D */  daddu     $a0, $s0, $zero
/* FAA78 802D60C8 0C052BE3 */  jal       func_8014AF8C
/* FAA7C 802D60CC 0040282D */   daddu    $a1, $v0, $zero
/* FAA80 802D60D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* FAA84 802D60D4 8FB10014 */  lw        $s1, 0x14($sp)
/* FAA88 802D60D8 8FB00010 */  lw        $s0, 0x10($sp)
/* FAA8C 802D60DC 24020002 */  addiu     $v0, $zero, 2
/* FAA90 802D60E0 03E00008 */  jr        $ra
/* FAA94 802D60E4 27BD0020 */   addiu    $sp, $sp, 0x20
