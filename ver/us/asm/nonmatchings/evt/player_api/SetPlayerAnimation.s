.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPlayerAnimation
/* F5A34 802D1084 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F5A38 802D1088 AFBF0010 */  sw        $ra, 0x10($sp)
/* F5A3C 802D108C 8C82000C */  lw        $v0, 0xc($a0)
/* F5A40 802D1090 0C0B1EAF */  jal       get_variable
/* F5A44 802D1094 8C450000 */   lw       $a1, ($v0)
/* F5A48 802D1098 3C040008 */  lui       $a0, 8
/* F5A4C 802D109C 3C03802E */  lui       $v1, %hi(playerNpc)
/* F5A50 802D10A0 8C639D20 */  lw        $v1, %lo(playerNpc)($v1)
/* F5A54 802D10A4 34840003 */  ori       $a0, $a0, 3
/* F5A58 802D10A8 AC620028 */  sw        $v0, 0x28($v1)
/* F5A5C 802D10AC 3C018011 */  lui       $at, %hi(gPlayerAnimation)
/* F5A60 802D10B0 AC22F080 */  sw        $v0, %lo(gPlayerAnimation)($at)
/* F5A64 802D10B4 14440004 */  bne       $v0, $a0, .L802D10C8
/* F5A68 802D10B8 0000202D */   daddu    $a0, $zero, $zero
/* F5A6C 802D10BC 0080282D */  daddu     $a1, $a0, $zero
/* F5A70 802D10C0 0C0B2D5B */  jal       exec_ShakeCam1
/* F5A74 802D10C4 24060002 */   addiu    $a2, $zero, 2
.L802D10C8:
/* F5A78 802D10C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* F5A7C 802D10CC 24020002 */  addiu     $v0, $zero, 2
/* F5A80 802D10D0 03E00008 */  jr        $ra
/* F5A84 802D10D4 27BD0018 */   addiu    $sp, $sp, 0x18
