.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424A0
/* 833CA0 802424A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 833CA4 802424A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 833CA8 802424A8 0080882D */  daddu     $s1, $a0, $zero
/* 833CAC 802424AC 3C05FD05 */  lui       $a1, 0xfd05
/* 833CB0 802424B0 34A50F82 */  ori       $a1, $a1, 0xf82
/* 833CB4 802424B4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 833CB8 802424B8 AFB50024 */  sw        $s5, 0x24($sp)
/* 833CBC 802424BC AFB40020 */  sw        $s4, 0x20($sp)
/* 833CC0 802424C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 833CC4 802424C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 833CC8 802424C8 0C0B1EAF */  jal       get_variable
/* 833CCC 802424CC AFB00010 */   sw       $s0, 0x10($sp)
/* 833CD0 802424D0 0220202D */  daddu     $a0, $s1, $zero
/* 833CD4 802424D4 8E30000C */  lw        $s0, 0xc($s1)
/* 833CD8 802424D8 0040982D */  daddu     $s3, $v0, $zero
/* 833CDC 802424DC 8E050000 */  lw        $a1, ($s0)
/* 833CE0 802424E0 0C0B1EAF */  jal       get_variable
/* 833CE4 802424E4 26100004 */   addiu    $s0, $s0, 4
/* 833CE8 802424E8 8E050000 */  lw        $a1, ($s0)
/* 833CEC 802424EC 26100004 */  addiu     $s0, $s0, 4
/* 833CF0 802424F0 8E150000 */  lw        $s5, ($s0)
/* 833CF4 802424F4 26100004 */  addiu     $s0, $s0, 4
/* 833CF8 802424F8 00029080 */  sll       $s2, $v0, 2
/* 833CFC 802424FC 8E63000C */  lw        $v1, 0xc($s3)
/* 833D00 80242500 8E140000 */  lw        $s4, ($s0)
/* 833D04 80242504 00721821 */  addu      $v1, $v1, $s2
/* 833D08 80242508 C4600034 */  lwc1      $f0, 0x34($v1)
/* 833D0C 8024250C 8E100004 */  lw        $s0, 4($s0)
/* 833D10 80242510 4600008D */  trunc.w.s $f2, $f0
/* 833D14 80242514 44061000 */  mfc1      $a2, $f2
/* 833D18 80242518 0C0B2026 */  jal       set_variable
/* 833D1C 8024251C 0220202D */   daddu    $a0, $s1, $zero
/* 833D20 80242520 8E62000C */  lw        $v0, 0xc($s3)
/* 833D24 80242524 0220202D */  daddu     $a0, $s1, $zero
/* 833D28 80242528 00521021 */  addu      $v0, $v0, $s2
/* 833D2C 8024252C C4400060 */  lwc1      $f0, 0x60($v0)
/* 833D30 80242530 4600008D */  trunc.w.s $f2, $f0
/* 833D34 80242534 44061000 */  mfc1      $a2, $f2
/* 833D38 80242538 0C0B2026 */  jal       set_variable
/* 833D3C 8024253C 02A0282D */   daddu    $a1, $s5, $zero
/* 833D40 80242540 8E62000C */  lw        $v0, 0xc($s3)
/* 833D44 80242544 0220202D */  daddu     $a0, $s1, $zero
/* 833D48 80242548 00521021 */  addu      $v0, $v0, $s2
/* 833D4C 8024254C C440008C */  lwc1      $f0, 0x8c($v0)
/* 833D50 80242550 4600008D */  trunc.w.s $f2, $f0
/* 833D54 80242554 44061000 */  mfc1      $a2, $f2
/* 833D58 80242558 0C0B2026 */  jal       set_variable
/* 833D5C 8024255C 0280282D */   daddu    $a1, $s4, $zero
/* 833D60 80242560 8E62000C */  lw        $v0, 0xc($s3)
/* 833D64 80242564 0220202D */  daddu     $a0, $s1, $zero
/* 833D68 80242568 00521021 */  addu      $v0, $v0, $s2
/* 833D6C 8024256C C44000B8 */  lwc1      $f0, 0xb8($v0)
/* 833D70 80242570 4600008D */  trunc.w.s $f2, $f0
/* 833D74 80242574 44061000 */  mfc1      $a2, $f2
/* 833D78 80242578 0C0B2026 */  jal       set_variable
/* 833D7C 8024257C 0200282D */   daddu    $a1, $s0, $zero
/* 833D80 80242580 8FBF0028 */  lw        $ra, 0x28($sp)
/* 833D84 80242584 8FB50024 */  lw        $s5, 0x24($sp)
/* 833D88 80242588 8FB40020 */  lw        $s4, 0x20($sp)
/* 833D8C 8024258C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 833D90 80242590 8FB20018 */  lw        $s2, 0x18($sp)
/* 833D94 80242594 8FB10014 */  lw        $s1, 0x14($sp)
/* 833D98 80242598 8FB00010 */  lw        $s0, 0x10($sp)
/* 833D9C 8024259C 24020002 */  addiu     $v0, $zero, 2
/* 833DA0 802425A0 03E00008 */  jr        $ra
/* 833DA4 802425A4 27BD0030 */   addiu    $sp, $sp, 0x30
