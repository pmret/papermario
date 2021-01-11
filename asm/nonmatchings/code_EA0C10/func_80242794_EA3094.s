.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242794_EA3094
/* EA3094 80242794 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA3098 80242798 AFB10014 */  sw        $s1, 0x14($sp)
/* EA309C 8024279C 0080882D */  daddu     $s1, $a0, $zero
/* EA30A0 802427A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA30A4 802427A4 AFB00010 */  sw        $s0, 0x10($sp)
/* EA30A8 802427A8 8E30000C */  lw        $s0, 0xc($s1)
/* EA30AC 802427AC 8E050000 */  lw        $a1, ($s0)
/* EA30B0 802427B0 0C0B53A3 */  jal       func_802D4E8C
/* EA30B4 802427B4 26100004 */   addiu    $s0, $s0, 4
/* EA30B8 802427B8 0C00F94D */  jal       func_8003E534
/* EA30BC 802427BC 0040202D */   daddu    $a0, $v0, $zero
/* EA30C0 802427C0 10400005 */  beqz      $v0, .L802427D8
/* EA30C4 802427C4 00000000 */   nop      
/* EA30C8 802427C8 8E050000 */  lw        $a1, ($s0)
/* EA30CC 802427CC 844600A8 */  lh        $a2, 0xa8($v0)
/* EA30D0 802427D0 0C0B551A */  jal       func_802D5468
/* EA30D4 802427D4 0220202D */   daddu    $a0, $s1, $zero
.L802427D8:
/* EA30D8 802427D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA30DC 802427DC 8FB10014 */  lw        $s1, 0x14($sp)
/* EA30E0 802427E0 8FB00010 */  lw        $s0, 0x10($sp)
/* EA30E4 802427E4 24020002 */  addiu     $v0, $zero, 2
/* EA30E8 802427E8 03E00008 */  jr        $ra
/* EA30EC 802427EC 27BD0020 */   addiu    $sp, $sp, 0x20
