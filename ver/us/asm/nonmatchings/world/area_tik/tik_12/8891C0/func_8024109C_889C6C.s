.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024109C_889C6C
/* 889C6C 8024109C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 889C70 802410A0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 889C74 802410A4 0080882D */  daddu     $s1, $a0, $zero
/* 889C78 802410A8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 889C7C 802410AC AFB00018 */  sw        $s0, 0x18($sp)
/* 889C80 802410B0 8E30000C */  lw        $s0, 0xc($s1)
/* 889C84 802410B4 8E050000 */  lw        $a1, ($s0)
/* 889C88 802410B8 0C0B1EAF */  jal       get_variable
/* 889C8C 802410BC 26100004 */   addiu    $s0, $s0, 4
/* 889C90 802410C0 0C04417A */  jal       get_entity_by_index
/* 889C94 802410C4 0040202D */   daddu    $a0, $v0, $zero
/* 889C98 802410C8 8E100000 */  lw        $s0, ($s0)
/* 889C9C 802410CC C444004C */  lwc1      $f4, 0x4c($v0)
/* 889CA0 802410D0 3C014148 */  lui       $at, 0x4148
/* 889CA4 802410D4 44810000 */  mtc1      $at, $f0
/* 889CA8 802410D8 3C013F33 */  lui       $at, 0x3f33
/* 889CAC 802410DC 34213333 */  ori       $at, $at, 0x3333
/* 889CB0 802410E0 44811000 */  mtc1      $at, $f2
/* 889CB4 802410E4 AFA00014 */  sw        $zero, 0x14($sp)
/* 889CB8 802410E8 46002100 */  add.s     $f4, $f4, $f0
/* 889CBC 802410EC E7A20010 */  swc1      $f2, 0x10($sp)
/* 889CC0 802410F0 8C450048 */  lw        $a1, 0x48($v0)
/* 889CC4 802410F4 8C470050 */  lw        $a3, 0x50($v0)
/* 889CC8 802410F8 44062000 */  mfc1      $a2, $f4
/* 889CCC 802410FC 0C01C5D4 */  jal       func_80071750
/* 889CD0 80241100 0000202D */   daddu    $a0, $zero, $zero
/* 889CD4 80241104 0220202D */  daddu     $a0, $s1, $zero
/* 889CD8 80241108 0200282D */  daddu     $a1, $s0, $zero
/* 889CDC 8024110C 0C0B2026 */  jal       set_variable
/* 889CE0 80241110 0040302D */   daddu    $a2, $v0, $zero
/* 889CE4 80241114 8FBF0020 */  lw        $ra, 0x20($sp)
/* 889CE8 80241118 8FB1001C */  lw        $s1, 0x1c($sp)
/* 889CEC 8024111C 8FB00018 */  lw        $s0, 0x18($sp)
/* 889CF0 80241120 24020002 */  addiu     $v0, $zero, 2
/* 889CF4 80241124 03E00008 */  jr        $ra
/* 889CF8 80241128 27BD0028 */   addiu    $sp, $sp, 0x28
