.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242734
/* 8B27A4 80242734 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B27A8 80242738 3C048026 */  lui       $a0, 0x8026
/* 8B27AC 8024273C 24848120 */  addiu     $a0, $a0, -0x7ee0
/* 8B27B0 80242740 3C028025 */  lui       $v0, 0x8025
/* 8B27B4 80242744 24427B00 */  addiu     $v0, $v0, 0x7b00
/* 8B27B8 80242748 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B27BC 8024274C AC820000 */  sw        $v0, ($a0)
/* 8B27C0 80242750 3C028025 */  lui       $v0, 0x8025
/* 8B27C4 80242754 24427D00 */  addiu     $v0, $v0, 0x7d00
/* 8B27C8 80242758 AC820004 */  sw        $v0, 4($a0)
/* 8B27CC 8024275C 24020020 */  addiu     $v0, $zero, 0x20
/* 8B27D0 80242760 A4820008 */  sh        $v0, 8($a0)
/* 8B27D4 80242764 A482000A */  sh        $v0, 0xa($a0)
/* 8B27D8 80242768 24020002 */  addiu     $v0, $zero, 2
/* 8B27DC 8024276C AC82000C */  sw        $v0, 0xc($a0)
/* 8B27E0 80242770 0C0496CB */  jal       set_message_images
/* 8B27E4 80242774 AC800010 */   sw       $zero, 0x10($a0)
/* 8B27E8 80242778 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B27EC 8024277C 24020001 */  addiu     $v0, $zero, 1
/* 8B27F0 80242780 03E00008 */  jr        $ra
/* 8B27F4 80242784 27BD0018 */   addiu    $sp, $sp, 0x18
