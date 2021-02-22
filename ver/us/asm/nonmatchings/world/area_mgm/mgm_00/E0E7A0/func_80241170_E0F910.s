.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241170_E0F910
/* E0F910 80241170 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E0F914 80241174 AFB10014 */  sw        $s1, 0x14($sp)
/* E0F918 80241178 0080882D */  daddu     $s1, $a0, $zero
/* E0F91C 8024117C AFB00010 */  sw        $s0, 0x10($sp)
/* E0F920 80241180 0000802D */  daddu     $s0, $zero, $zero
/* E0F924 80241184 AFBF0018 */  sw        $ra, 0x18($sp)
/* E0F928 80241188 0C039D91 */  jal       find_item
/* E0F92C 8024118C 2404007C */   addiu    $a0, $zero, 0x7c
/* E0F930 80241190 04400003 */  bltz      $v0, .L802411A0
/* E0F934 80241194 00000000 */   nop
/* E0F938 80241198 0809046C */  j         .L802411B0
/* E0F93C 8024119C 24100002 */   addiu    $s0, $zero, 2
.L802411A0:
/* E0F940 802411A0 0C039D91 */  jal       find_item
/* E0F944 802411A4 2404007B */   addiu    $a0, $zero, 0x7b
/* E0F948 802411A8 04430001 */  bgezl     $v0, .L802411B0
/* E0F94C 802411AC 24100001 */   addiu    $s0, $zero, 1
.L802411B0:
/* E0F950 802411B0 0220202D */  daddu     $a0, $s1, $zero
/* E0F954 802411B4 3C05FE36 */  lui       $a1, 0xfe36
/* E0F958 802411B8 34A53C85 */  ori       $a1, $a1, 0x3c85
/* E0F95C 802411BC 0C0B2026 */  jal       set_variable
/* E0F960 802411C0 0200302D */   daddu    $a2, $s0, $zero
/* E0F964 802411C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* E0F968 802411C8 8FB10014 */  lw        $s1, 0x14($sp)
/* E0F96C 802411CC 8FB00010 */  lw        $s0, 0x10($sp)
/* E0F970 802411D0 24020002 */  addiu     $v0, $zero, 2
/* E0F974 802411D4 03E00008 */  jr        $ra
/* E0F978 802411D8 27BD0020 */   addiu    $sp, $sp, 0x20
/* E0F97C 802411DC 00000000 */  nop
