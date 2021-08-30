.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802196A4_465B34
/* 465B34 802196A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 465B38 802196A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 465B3C 802196AC 0080802D */  daddu     $s0, $a0, $zero
/* 465B40 802196B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 465B44 802196B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 465B48 802196B8 8E040148 */  lw        $a0, 0x148($s0)
/* 465B4C 802196BC 0C09A75B */  jal       get_actor
/* 465B50 802196C0 8E11000C */   lw       $s1, 0xc($s0)
/* 465B54 802196C4 0200202D */  daddu     $a0, $s0, $zero
/* 465B58 802196C8 8E250000 */  lw        $a1, ($s1)
/* 465B5C 802196CC 0C0B1EAF */  jal       evt_get_variable
/* 465B60 802196D0 8C500094 */   lw       $s0, 0x94($v0)
/* 465B64 802196D4 AE02000C */  sw        $v0, 0xc($s0)
/* 465B68 802196D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 465B6C 802196DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 465B70 802196E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 465B74 802196E4 24020002 */  addiu     $v0, $zero, 2
/* 465B78 802196E8 03E00008 */  jr        $ra
/* 465B7C 802196EC 27BD0020 */   addiu    $sp, $sp, 0x20
