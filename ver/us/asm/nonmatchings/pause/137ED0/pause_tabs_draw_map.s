.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8026FFA8
.double 255.0

.section .text

glabel pause_tabs_draw_map
/* 1384A0 80245160 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1384A4 80245164 AFB10014 */  sw        $s1, 0x14($sp)
/* 1384A8 80245168 8FB10040 */  lw        $s1, 0x40($sp)
/* 1384AC 8024516C AFB40020 */  sw        $s4, 0x20($sp)
/* 1384B0 80245170 0080A02D */  daddu     $s4, $a0, $zero
/* 1384B4 80245174 AFB20018 */  sw        $s2, 0x18($sp)
/* 1384B8 80245178 00A0902D */  daddu     $s2, $a1, $zero
/* 1384BC 8024517C AFB3001C */  sw        $s3, 0x1c($sp)
/* 1384C0 80245180 00C0982D */  daddu     $s3, $a2, $zero
/* 1384C4 80245184 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1384C8 80245188 12200016 */  beqz      $s1, .L802451E4
/* 1384CC 8024518C AFB00010 */   sw       $s0, 0x10($sp)
/* 1384D0 80245190 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 1384D4 80245194 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 1384D8 80245198 8E040014 */  lw        $a0, 0x14($s0)
/* 1384DC 8024519C 0C051280 */  jal       set_hud_element_flags
/* 1384E0 802451A0 24050020 */   addiu    $a1, $zero, 0x20
/* 1384E4 802451A4 3C013FE0 */  lui       $at, 0x3fe0
/* 1384E8 802451A8 44811800 */  mtc1      $at, $f3
/* 1384EC 802451AC 44801000 */  mtc1      $zero, $f2
/* 1384F0 802451B0 44910000 */  mtc1      $s1, $f0
/* 1384F4 802451B4 00000000 */  nop
/* 1384F8 802451B8 46800021 */  cvt.d.w   $f0, $f0
/* 1384FC 802451BC 46220002 */  mul.d     $f0, $f0, $f2
/* 138500 802451C0 00000000 */  nop
/* 138504 802451C4 3C018027 */  lui       $at, %hi(D_8026FFA8)
/* 138508 802451C8 D422FFA8 */  ldc1      $f2, %lo(D_8026FFA8)($at)
/* 13850C 802451CC 46201081 */  sub.d     $f2, $f2, $f0
/* 138510 802451D0 8E040014 */  lw        $a0, 0x14($s0)
/* 138514 802451D4 4620110D */  trunc.w.d $f4, $f2
/* 138518 802451D8 44052000 */  mfc1      $a1, $f4
/* 13851C 802451DC 08091480 */  j         .L80245200
/* 138520 802451E0 00000000 */   nop
.L802451E4:
/* 138524 802451E4 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 138528 802451E8 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 13852C 802451EC 8E040014 */  lw        $a0, 0x14($s0)
/* 138530 802451F0 0C05128B */  jal       clear_hud_element_flags
/* 138534 802451F4 24050020 */   addiu    $a1, $zero, 0x20
/* 138538 802451F8 8E040014 */  lw        $a0, 0x14($s0)
/* 13853C 802451FC 240500FF */  addiu     $a1, $zero, 0xff
.L80245200:
/* 138540 80245200 0C0513AC */  jal       set_hud_element_alpha
/* 138544 80245204 00000000 */   nop
/* 138548 80245208 26450017 */  addiu     $a1, $s2, 0x17
/* 13854C 8024520C 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 138550 80245210 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 138554 80245214 8E040014 */  lw        $a0, 0x14($s0)
/* 138558 80245218 0C051261 */  jal       set_hud_element_render_pos
/* 13855C 8024521C 26660007 */   addiu    $a2, $s3, 7
/* 138560 80245220 8E040014 */  lw        $a0, 0x14($s0)
/* 138564 80245224 0C0511F8 */  jal       draw_hud_element_3
/* 138568 80245228 00000000 */   nop
/* 13856C 8024522C 3C028027 */  lui       $v0, %hi(gPauseMenuCurrentTab)
/* 138570 80245230 804200D4 */  lb        $v0, %lo(gPauseMenuCurrentTab)($v0)
/* 138574 80245234 1440000C */  bnez      $v0, .L80245268
/* 138578 80245238 00000000 */   nop
/* 13857C 8024523C 82830001 */  lb        $v1, 1($s4)
/* 138580 80245240 3C028025 */  lui       $v0, %hi(D_8024F1D8)
/* 138584 80245244 2442F1D8 */  addiu     $v0, $v0, %lo(D_8024F1D8)
/* 138588 80245248 00622021 */  addu      $a0, $v1, $v0
/* 13858C 8024524C 90830000 */  lbu       $v1, ($a0)
/* 138590 80245250 2402001E */  addiu     $v0, $zero, 0x1e
/* 138594 80245254 14620004 */  bne       $v1, $v0, .L80245268
/* 138598 80245258 0060202D */   daddu    $a0, $v1, $zero
/* 13859C 8024525C 0240282D */  daddu     $a1, $s2, $zero
/* 1385A0 80245260 0C090B41 */  jal       func_80242D04
/* 1385A4 80245264 26660006 */   addiu    $a2, $s3, 6
.L80245268:
/* 1385A8 80245268 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1385AC 8024526C 8FB40020 */  lw        $s4, 0x20($sp)
/* 1385B0 80245270 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1385B4 80245274 8FB20018 */  lw        $s2, 0x18($sp)
/* 1385B8 80245278 8FB10014 */  lw        $s1, 0x14($sp)
/* 1385BC 8024527C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1385C0 80245280 03E00008 */  jr        $ra
/* 1385C4 80245284 27BD0028 */   addiu    $sp, $sp, 0x28
