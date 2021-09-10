.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240314_DDF624
/* DDF624 80240314 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DDF628 80240318 AFB1001C */  sw        $s1, 0x1c($sp)
/* DDF62C 8024031C 0080882D */  daddu     $s1, $a0, $zero
/* DDF630 80240320 AFBF0028 */  sw        $ra, 0x28($sp)
/* DDF634 80240324 AFB30024 */  sw        $s3, 0x24($sp)
/* DDF638 80240328 AFB20020 */  sw        $s2, 0x20($sp)
/* DDF63C 8024032C AFB00018 */  sw        $s0, 0x18($sp)
/* DDF640 80240330 8E30000C */  lw        $s0, 0xc($s1)
/* DDF644 80240334 8E050000 */  lw        $a1, ($s0)
/* DDF648 80240338 0C0B1EAF */  jal       evt_get_variable
/* DDF64C 8024033C 26100004 */   addiu    $s0, $s0, 4
/* DDF650 80240340 8E050000 */  lw        $a1, ($s0)
/* DDF654 80240344 26100004 */  addiu     $s0, $s0, 4
/* DDF658 80240348 0220202D */  daddu     $a0, $s1, $zero
/* DDF65C 8024034C 0C0B1EAF */  jal       evt_get_variable
/* DDF660 80240350 0040982D */   daddu    $s3, $v0, $zero
/* DDF664 80240354 8E050000 */  lw        $a1, ($s0)
/* DDF668 80240358 26100004 */  addiu     $s0, $s0, 4
/* DDF66C 8024035C 0220202D */  daddu     $a0, $s1, $zero
/* DDF670 80240360 0C0B1EAF */  jal       evt_get_variable
/* DDF674 80240364 0040902D */   daddu    $s2, $v0, $zero
/* DDF678 80240368 0220202D */  daddu     $a0, $s1, $zero
/* DDF67C 8024036C 8E050000 */  lw        $a1, ($s0)
/* DDF680 80240370 0C0B1EAF */  jal       evt_get_variable
/* DDF684 80240374 0040802D */   daddu    $s0, $v0, $zero
/* DDF688 80240378 24040001 */  addiu     $a0, $zero, 1
/* DDF68C 8024037C 0080282D */  daddu     $a1, $a0, $zero
/* DDF690 80240380 AFB00010 */  sw        $s0, 0x10($sp)
/* DDF694 80240384 0040802D */  daddu     $s0, $v0, $zero
/* DDF698 80240388 0260302D */  daddu     $a2, $s3, $zero
/* DDF69C 8024038C 0C04DFB0 */  jal       set_screen_overlay_center_worldpos
/* DDF6A0 80240390 0240382D */   daddu    $a3, $s2, $zero
/* DDF6A4 80240394 44900000 */  mtc1      $s0, $f0
/* DDF6A8 80240398 00000000 */  nop
/* DDF6AC 8024039C 46800020 */  cvt.s.w   $f0, $f0
/* DDF6B0 802403A0 44050000 */  mfc1      $a1, $f0
/* DDF6B4 802403A4 0C04E035 */  jal       set_screen_overlay_alpha
/* DDF6B8 802403A8 24040001 */   addiu    $a0, $zero, 1
/* DDF6BC 802403AC 3C05437F */  lui       $a1, 0x437f
/* DDF6C0 802403B0 0C04DF69 */  jal       set_screen_overlay_params_back
/* DDF6C4 802403B4 2404000B */   addiu    $a0, $zero, 0xb
/* DDF6C8 802403B8 8FBF0028 */  lw        $ra, 0x28($sp)
/* DDF6CC 802403BC 8FB30024 */  lw        $s3, 0x24($sp)
/* DDF6D0 802403C0 8FB20020 */  lw        $s2, 0x20($sp)
/* DDF6D4 802403C4 8FB1001C */  lw        $s1, 0x1c($sp)
/* DDF6D8 802403C8 8FB00018 */  lw        $s0, 0x18($sp)
/* DDF6DC 802403CC 24020002 */  addiu     $v0, $zero, 2
/* DDF6E0 802403D0 03E00008 */  jr        $ra
/* DDF6E4 802403D4 27BD0030 */   addiu    $sp, $sp, 0x30
