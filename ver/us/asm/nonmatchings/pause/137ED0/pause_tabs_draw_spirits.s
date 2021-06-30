.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_draw_spirits
/* 138378 80245038 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 13837C 8024503C AFB10014 */  sw        $s1, 0x14($sp)
/* 138380 80245040 8FB10040 */  lw        $s1, 0x40($sp)
/* 138384 80245044 AFB40020 */  sw        $s4, 0x20($sp)
/* 138388 80245048 0080A02D */  daddu     $s4, $a0, $zero
/* 13838C 8024504C AFB20018 */  sw        $s2, 0x18($sp)
/* 138390 80245050 00A0902D */  daddu     $s2, $a1, $zero
/* 138394 80245054 AFB3001C */  sw        $s3, 0x1c($sp)
/* 138398 80245058 00C0982D */  daddu     $s3, $a2, $zero
/* 13839C 8024505C AFBF0024 */  sw        $ra, 0x24($sp)
/* 1383A0 80245060 12200016 */  beqz      $s1, .L802450BC
/* 1383A4 80245064 AFB00010 */   sw       $s0, 0x10($sp)
/* 1383A8 80245068 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 1383AC 8024506C 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 1383B0 80245070 8E040010 */  lw        $a0, 0x10($s0)
/* 1383B4 80245074 0C051280 */  jal       set_hud_element_flags
/* 1383B8 80245078 24050020 */   addiu    $a1, $zero, 0x20
/* 1383BC 8024507C 3C013FE0 */  lui       $at, 0x3fe0
/* 1383C0 80245080 44811800 */  mtc1      $at, $f3
/* 1383C4 80245084 44801000 */  mtc1      $zero, $f2
/* 1383C8 80245088 44910000 */  mtc1      $s1, $f0
/* 1383CC 8024508C 00000000 */  nop
/* 1383D0 80245090 46800021 */  cvt.d.w   $f0, $f0
/* 1383D4 80245094 46220002 */  mul.d     $f0, $f0, $f2
/* 1383D8 80245098 00000000 */  nop
/* 1383DC 8024509C 3C018027 */  lui       $at, %hi(D_8026FFA0)
/* 1383E0 802450A0 D422FFA0 */  ldc1      $f2, %lo(D_8026FFA0)($at)
/* 1383E4 802450A4 46201081 */  sub.d     $f2, $f2, $f0
/* 1383E8 802450A8 8E040010 */  lw        $a0, 0x10($s0)
/* 1383EC 802450AC 4620110D */  trunc.w.d $f4, $f2
/* 1383F0 802450B0 44052000 */  mfc1      $a1, $f4
/* 1383F4 802450B4 08091436 */  j         .L802450D8
/* 1383F8 802450B8 00000000 */   nop
.L802450BC:
/* 1383FC 802450BC 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 138400 802450C0 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 138404 802450C4 8E040010 */  lw        $a0, 0x10($s0)
/* 138408 802450C8 0C05128B */  jal       clear_hud_element_flags
/* 13840C 802450CC 24050020 */   addiu    $a1, $zero, 0x20
/* 138410 802450D0 8E040010 */  lw        $a0, 0x10($s0)
/* 138414 802450D4 240500FF */  addiu     $a1, $zero, 0xff
.L802450D8:
/* 138418 802450D8 0C0513AC */  jal       set_hud_element_alpha
/* 13841C 802450DC 00000000 */   nop
/* 138420 802450E0 26450016 */  addiu     $a1, $s2, 0x16
/* 138424 802450E4 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 138428 802450E8 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 13842C 802450EC 8E040010 */  lw        $a0, 0x10($s0)
/* 138430 802450F0 0C051261 */  jal       set_hud_element_render_pos
/* 138434 802450F4 26660007 */   addiu    $a2, $s3, 7
/* 138438 802450F8 8E040010 */  lw        $a0, 0x10($s0)
/* 13843C 802450FC 0C0511F8 */  jal       draw_icon_2
/* 138440 80245100 00000000 */   nop
/* 138444 80245104 3C028027 */  lui       $v0, %hi(gPauseMenuCurrentTab)
/* 138448 80245108 804200D4 */  lb        $v0, %lo(gPauseMenuCurrentTab)($v0)
/* 13844C 8024510C 1440000C */  bnez      $v0, .L80245140
/* 138450 80245110 00000000 */   nop
/* 138454 80245114 82830001 */  lb        $v1, 1($s4)
/* 138458 80245118 3C028025 */  lui       $v0, %hi(D_8024F1D8)
/* 13845C 8024511C 2442F1D8 */  addiu     $v0, $v0, %lo(D_8024F1D8)
/* 138460 80245120 00622021 */  addu      $a0, $v1, $v0
/* 138464 80245124 90830000 */  lbu       $v1, ($a0)
/* 138468 80245128 2402001D */  addiu     $v0, $zero, 0x1d
/* 13846C 8024512C 14620004 */  bne       $v1, $v0, .L80245140
/* 138470 80245130 0060202D */   daddu    $a0, $v1, $zero
/* 138474 80245134 0240282D */  daddu     $a1, $s2, $zero
/* 138478 80245138 0C090B41 */  jal       func_80242D04
/* 13847C 8024513C 26660006 */   addiu    $a2, $s3, 6
.L80245140:
/* 138480 80245140 8FBF0024 */  lw        $ra, 0x24($sp)
/* 138484 80245144 8FB40020 */  lw        $s4, 0x20($sp)
/* 138488 80245148 8FB3001C */  lw        $s3, 0x1c($sp)
/* 13848C 8024514C 8FB20018 */  lw        $s2, 0x18($sp)
/* 138490 80245150 8FB10014 */  lw        $s1, 0x14($sp)
/* 138494 80245154 8FB00010 */  lw        $s0, 0x10($sp)
/* 138498 80245158 03E00008 */  jr        $ra
/* 13849C 8024515C 27BD0028 */   addiu    $sp, $sp, 0x28
