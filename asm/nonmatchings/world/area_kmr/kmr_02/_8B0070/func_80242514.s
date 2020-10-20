.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242514
/* 8B2584 80242514 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8B2588 80242518 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8B258C 8024251C 0080882D */  daddu     $s1, $a0, $zero
/* 8B2590 80242520 AFBF0034 */  sw        $ra, 0x34($sp)
/* 8B2594 80242524 AFB60030 */  sw        $s6, 0x30($sp)
/* 8B2598 80242528 AFB5002C */  sw        $s5, 0x2c($sp)
/* 8B259C 8024252C AFB40028 */  sw        $s4, 0x28($sp)
/* 8B25A0 80242530 AFB30024 */  sw        $s3, 0x24($sp)
/* 8B25A4 80242534 AFB20020 */  sw        $s2, 0x20($sp)
/* 8B25A8 80242538 AFB00018 */  sw        $s0, 0x18($sp)
/* 8B25AC 8024253C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 8B25B0 80242540 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 8B25B4 80242544 8E30000C */  lw        $s0, 0xc($s1)
/* 8B25B8 80242548 8E160000 */  lw        $s6, ($s0)
/* 8B25BC 8024254C 26100004 */  addiu     $s0, $s0, 4
/* 8B25C0 80242550 0C0B1EAF */  jal       get_variable
/* 8B25C4 80242554 02C0282D */   daddu    $a1, $s6, $zero
/* 8B25C8 80242558 44820000 */  mtc1      $v0, $f0
/* 8B25CC 8024255C 00000000 */  nop       
/* 8B25D0 80242560 46800020 */  cvt.s.w   $f0, $f0
/* 8B25D4 80242564 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8B25D8 80242568 8E140000 */  lw        $s4, ($s0)
/* 8B25DC 8024256C 26100004 */  addiu     $s0, $s0, 4
/* 8B25E0 80242570 0220202D */  daddu     $a0, $s1, $zero
/* 8B25E4 80242574 0C0B1EAF */  jal       get_variable
/* 8B25E8 80242578 0280282D */   daddu    $a1, $s4, $zero
/* 8B25EC 8024257C 0220202D */  daddu     $a0, $s1, $zero
/* 8B25F0 80242580 8E150000 */  lw        $s5, ($s0)
/* 8B25F4 80242584 4482B000 */  mtc1      $v0, $f22
/* 8B25F8 80242588 00000000 */  nop       
/* 8B25FC 8024258C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8B2600 80242590 0C0B1EAF */  jal       get_variable
/* 8B2604 80242594 02A0282D */   daddu    $a1, $s5, $zero
/* 8B2608 80242598 2404FFFC */  addiu     $a0, $zero, -4
/* 8B260C 8024259C 44820000 */  mtc1      $v0, $f0
/* 8B2610 802425A0 00000000 */  nop       
/* 8B2614 802425A4 46800020 */  cvt.s.w   $f0, $f0
/* 8B2618 802425A8 0C00EABB */  jal       get_npc_unsafe
/* 8B261C 802425AC E7A00014 */   swc1     $f0, 0x14($sp)
/* 8B2620 802425B0 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 8B2624 802425B4 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 8B2628 802425B8 3C014334 */  lui       $at, 0x4334
/* 8B262C 802425BC 44816000 */  mtc1      $at, $f12
/* 8B2630 802425C0 00041880 */  sll       $v1, $a0, 2
/* 8B2634 802425C4 00641821 */  addu      $v1, $v1, $a0
/* 8B2638 802425C8 00031880 */  sll       $v1, $v1, 2
/* 8B263C 802425CC 00641823 */  subu      $v1, $v1, $a0
/* 8B2640 802425D0 000320C0 */  sll       $a0, $v1, 3
/* 8B2644 802425D4 00641821 */  addu      $v1, $v1, $a0
/* 8B2648 802425D8 000318C0 */  sll       $v1, $v1, 3
/* 8B264C 802425DC 3C01800B */  lui       $at, 0x800b
/* 8B2650 802425E0 00230821 */  addu      $at, $at, $v1
/* 8B2654 802425E4 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 8B2658 802425E8 460C0300 */  add.s     $f12, $f0, $f12
/* 8B265C 802425EC 0C00A6C9 */  jal       clamp_angle
/* 8B2660 802425F0 0040982D */   daddu    $s3, $v0, $zero
/* 8B2664 802425F4 27B00010 */  addiu     $s0, $sp, 0x10
/* 8B2668 802425F8 0200202D */  daddu     $a0, $s0, $zero
/* 8B266C 802425FC 27B20014 */  addiu     $s2, $sp, 0x14
/* 8B2670 80242600 0240282D */  daddu     $a1, $s2, $zero
/* 8B2674 80242604 3C064170 */  lui       $a2, 0x4170
/* 8B2678 80242608 8E67000C */  lw        $a3, 0xc($s3)
/* 8B267C 8024260C 0C00A7E7 */  jal       add_vec2D_polar
/* 8B2680 80242610 46000506 */   mov.s    $f20, $f0
/* 8B2684 80242614 0200202D */  daddu     $a0, $s0, $zero
/* 8B2688 80242618 3C064120 */  lui       $a2, 0x4120
/* 8B268C 8024261C 4407A000 */  mfc1      $a3, $f20
/* 8B2690 80242620 0C00A7E7 */  jal       add_vec2D_polar
/* 8B2694 80242624 0240282D */   daddu    $a1, $s2, $zero
/* 8B2698 80242628 0220202D */  daddu     $a0, $s1, $zero
/* 8B269C 8024262C C7A00010 */  lwc1      $f0, 0x10($sp)
/* 8B26A0 80242630 4600008D */  trunc.w.s $f2, $f0
/* 8B26A4 80242634 44061000 */  mfc1      $a2, $f2
/* 8B26A8 80242638 0C0B2026 */  jal       set_variable
/* 8B26AC 8024263C 02C0282D */   daddu    $a1, $s6, $zero
/* 8B26B0 80242640 0220202D */  daddu     $a0, $s1, $zero
/* 8B26B4 80242644 4600B08D */  trunc.w.s $f2, $f22
/* 8B26B8 80242648 44061000 */  mfc1      $a2, $f2
/* 8B26BC 8024264C 0C0B2026 */  jal       set_variable
/* 8B26C0 80242650 0280282D */   daddu    $a1, $s4, $zero
/* 8B26C4 80242654 0220202D */  daddu     $a0, $s1, $zero
/* 8B26C8 80242658 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 8B26CC 8024265C 4600008D */  trunc.w.s $f2, $f0
/* 8B26D0 80242660 44061000 */  mfc1      $a2, $f2
/* 8B26D4 80242664 0C0B2026 */  jal       set_variable
/* 8B26D8 80242668 02A0282D */   daddu    $a1, $s5, $zero
/* 8B26DC 8024266C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 8B26E0 80242670 8FB60030 */  lw        $s6, 0x30($sp)
/* 8B26E4 80242674 8FB5002C */  lw        $s5, 0x2c($sp)
/* 8B26E8 80242678 8FB40028 */  lw        $s4, 0x28($sp)
/* 8B26EC 8024267C 8FB30024 */  lw        $s3, 0x24($sp)
/* 8B26F0 80242680 8FB20020 */  lw        $s2, 0x20($sp)
/* 8B26F4 80242684 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8B26F8 80242688 8FB00018 */  lw        $s0, 0x18($sp)
/* 8B26FC 8024268C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 8B2700 80242690 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 8B2704 80242694 24020002 */  addiu     $v0, $zero, 2
/* 8B2708 80242698 03E00008 */  jr        $ra
/* 8B270C 8024269C 27BD0048 */   addiu    $sp, $sp, 0x48
