.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_init
/* 1385C8 80245288 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1385CC 8024528C AFB3001C */  sw        $s3, 0x1c($sp)
/* 1385D0 80245290 0080982D */  daddu     $s3, $a0, $zero
/* 1385D4 80245294 AFB00010 */  sw        $s0, 0x10($sp)
/* 1385D8 80245298 0000802D */  daddu     $s0, $zero, $zero
/* 1385DC 8024529C AFB20018 */  sw        $s2, 0x18($sp)
/* 1385E0 802452A0 3C128027 */  lui       $s2, %hi(gPauseMenuTabIconIDs)
/* 1385E4 802452A4 26520130 */  addiu     $s2, $s2, %lo(gPauseMenuTabIconIDs)
/* 1385E8 802452A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 1385EC 802452AC 3C118025 */  lui       $s1, %hi(D_8024F1B0)
/* 1385F0 802452B0 2631F1B0 */  addiu     $s1, $s1, %lo(D_8024F1B0)
/* 1385F4 802452B4 AFBF0020 */  sw        $ra, 0x20($sp)
.L802452B8:
/* 1385F8 802452B8 8E240000 */  lw        $a0, ($s1)
/* 1385FC 802452BC 26310004 */  addiu     $s1, $s1, 4
/* 138600 802452C0 0C050529 */  jal       create_icon
/* 138604 802452C4 26100001 */   addiu    $s0, $s0, 1
/* 138608 802452C8 0040202D */  daddu     $a0, $v0, $zero
/* 13860C 802452CC 24050080 */  addiu     $a1, $zero, 0x80
/* 138610 802452D0 0C051280 */  jal       set_icon_flags
/* 138614 802452D4 AE440000 */   sw       $a0, ($s2)
/* 138618 802452D8 2A020006 */  slti      $v0, $s0, 6
/* 13861C 802452DC 1440FFF6 */  bnez      $v0, .L802452B8
/* 138620 802452E0 26520004 */   addiu    $s2, $s2, 4
/* 138624 802452E4 24100006 */  addiu     $s0, $zero, 6
/* 138628 802452E8 3C028025 */  lui       $v0, %hi(D_8024F2C0)
/* 13862C 802452EC 2442F2C0 */  addiu     $v0, $v0, %lo(D_8024F2C0)
.L802452F0:
/* 138630 802452F0 AC530010 */  sw        $s3, 0x10($v0)
/* 138634 802452F4 2610FFFF */  addiu     $s0, $s0, -1
/* 138638 802452F8 0601FFFD */  bgez      $s0, .L802452F0
/* 13863C 802452FC 2442FFDC */   addiu    $v0, $v0, -0x24
/* 138640 80245300 3C048025 */  lui       $a0, %hi(D_8024F1E8)
/* 138644 80245304 2484F1E8 */  addiu     $a0, $a0, %lo(D_8024F1E8)
/* 138648 80245308 0C051FCC */  jal       setup_pause_menu_tab
/* 13864C 8024530C 24050007 */   addiu    $a1, $zero, 7
/* 138650 80245310 24020019 */  addiu     $v0, $zero, 0x19
/* 138654 80245314 3C018016 */  lui       $at, %hi(D_8015A2BE)
/* 138658 80245318 A422A2BE */  sh        $v0, %lo(D_8015A2BE)($at)
/* 13865C 8024531C 24020001 */  addiu     $v0, $zero, 1
/* 138660 80245320 3C018027 */  lui       $at, %hi(D_8027014C)
/* 138664 80245324 AC20014C */  sw        $zero, %lo(D_8027014C)($at)
/* 138668 80245328 A2620000 */  sb        $v0, ($s3)
/* 13866C 8024532C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 138670 80245330 8FB3001C */  lw        $s3, 0x1c($sp)
/* 138674 80245334 8FB20018 */  lw        $s2, 0x18($sp)
/* 138678 80245338 8FB10014 */  lw        $s1, 0x14($sp)
/* 13867C 8024533C 8FB00010 */  lw        $s0, 0x10($sp)
/* 138680 80245340 24020005 */  addiu     $v0, $zero, 5
/* 138684 80245344 3C018027 */  lui       $at, %hi(D_80270148)
/* 138688 80245348 AC220148 */  sw        $v0, %lo(D_80270148)($at)
/* 13868C 8024534C 03E00008 */  jr        $ra
/* 138690 80245350 27BD0028 */   addiu    $sp, $sp, 0x28
