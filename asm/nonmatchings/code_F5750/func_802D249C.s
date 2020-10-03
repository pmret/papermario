.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D249C
/* F6E4C 802D249C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F6E50 802D24A0 AFB10014 */  sw        $s1, 0x14($sp)
/* F6E54 802D24A4 0080882D */  daddu     $s1, $a0, $zero
/* F6E58 802D24A8 3C028016 */  lui       $v0, 0x8016
/* F6E5C 802D24AC 8442A552 */  lh        $v0, -0x5aae($v0)
/* F6E60 802D24B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* F6E64 802D24B4 AFB00010 */  sw        $s0, 0x10($sp)
/* F6E68 802D24B8 8E30000C */  lw        $s0, 0xc($s1)
/* F6E6C 802D24BC 04400004 */  bltz      $v0, .L802D24D0
/* F6E70 802D24C0 0000302D */   daddu    $a2, $zero, $zero
/* F6E74 802D24C4 0C0B48FE */  jal       func_802D23F8
/* F6E78 802D24C8 00000000 */   nop      
/* F6E7C 802D24CC 0002302B */  sltu      $a2, $zero, $v0
.L802D24D0:
/* F6E80 802D24D0 8E050000 */  lw        $a1, ($s0)
/* F6E84 802D24D4 0C0B2026 */  jal       set_variable
/* F6E88 802D24D8 0220202D */   daddu    $a0, $s1, $zero
/* F6E8C 802D24DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* F6E90 802D24E0 8FB10014 */  lw        $s1, 0x14($sp)
/* F6E94 802D24E4 8FB00010 */  lw        $s0, 0x10($sp)
/* F6E98 802D24E8 24020002 */  addiu     $v0, $zero, 2
/* F6E9C 802D24EC 03E00008 */  jr        $ra
/* F6EA0 802D24F0 27BD0020 */   addiu    $sp, $sp, 0x20
