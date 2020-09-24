.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A56F8
/* 41A488 802A56F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 41A48C 802A56FC 3C04001D */  lui       $a0, 0x1d
/* 41A490 802A5700 34840043 */  ori       $a0, $a0, 0x43
/* 41A494 802A5704 24020033 */  addiu     $v0, $zero, 0x33
/* 41A498 802A5708 AFA20010 */  sw        $v0, 0x10($sp)
/* 41A49C 802A570C 24020001 */  addiu     $v0, $zero, 1
/* 41A4A0 802A5710 24A5000F */  addiu     $a1, $a1, 0xf
/* 41A4A4 802A5714 3C07802B */  lui       $a3, 0x802b
/* 41A4A8 802A5718 8CE7D624 */  lw        $a3, -0x29dc($a3)
/* 41A4AC 802A571C 24C60002 */  addiu     $a2, $a2, 2
/* 41A4B0 802A5720 AFBF0018 */  sw        $ra, 0x18($sp)
/* 41A4B4 802A5724 0C04993B */  jal       draw_string
/* 41A4B8 802A5728 AFA20014 */   sw       $v0, 0x14($sp)
/* 41A4BC 802A572C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 41A4C0 802A5730 03E00008 */  jr        $ra
/* 41A4C4 802A5734 27BD0020 */   addiu    $sp, $sp, 0x20
