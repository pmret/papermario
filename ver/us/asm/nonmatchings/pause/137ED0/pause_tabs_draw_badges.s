.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_draw_badges
/* 138000 80244CC0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 138004 80244CC4 AFB10014 */  sw        $s1, 0x14($sp)
/* 138008 80244CC8 8FB10040 */  lw        $s1, 0x40($sp)
/* 13800C 80244CCC AFB40020 */  sw        $s4, 0x20($sp)
/* 138010 80244CD0 0080A02D */  daddu     $s4, $a0, $zero
/* 138014 80244CD4 AFB20018 */  sw        $s2, 0x18($sp)
/* 138018 80244CD8 00A0902D */  daddu     $s2, $a1, $zero
/* 13801C 80244CDC AFB3001C */  sw        $s3, 0x1c($sp)
/* 138020 80244CE0 00C0982D */  daddu     $s3, $a2, $zero
/* 138024 80244CE4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 138028 80244CE8 12200016 */  beqz      $s1, .L80244D44
/* 13802C 80244CEC AFB00010 */   sw       $s0, 0x10($sp)
/* 138030 80244CF0 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 138034 80244CF4 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 138038 80244CF8 8E040004 */  lw        $a0, 4($s0)
/* 13803C 80244CFC 0C051280 */  jal       set_hud_element_flags
/* 138040 80244D00 24050020 */   addiu    $a1, $zero, 0x20
/* 138044 80244D04 3C013FE0 */  lui       $at, 0x3fe0
/* 138048 80244D08 44811800 */  mtc1      $at, $f3
/* 13804C 80244D0C 44801000 */  mtc1      $zero, $f2
/* 138050 80244D10 44910000 */  mtc1      $s1, $f0
/* 138054 80244D14 00000000 */  nop
/* 138058 80244D18 46800021 */  cvt.d.w   $f0, $f0
/* 13805C 80244D1C 46220002 */  mul.d     $f0, $f0, $f2
/* 138060 80244D20 00000000 */  nop
/* 138064 80244D24 3C018027 */  lui       $at, %hi(D_8026FF88)
/* 138068 80244D28 D422FF88 */  ldc1      $f2, %lo(D_8026FF88)($at)
/* 13806C 80244D2C 46201081 */  sub.d     $f2, $f2, $f0
/* 138070 80244D30 8E040004 */  lw        $a0, 4($s0)
/* 138074 80244D34 4620110D */  trunc.w.d $f4, $f2
/* 138078 80244D38 44052000 */  mfc1      $a1, $f4
/* 13807C 80244D3C 08091358 */  j         .L80244D60
/* 138080 80244D40 00000000 */   nop
.L80244D44:
/* 138084 80244D44 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 138088 80244D48 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 13808C 80244D4C 8E040004 */  lw        $a0, 4($s0)
/* 138090 80244D50 0C05128B */  jal       clear_hud_element_flags
/* 138094 80244D54 24050020 */   addiu    $a1, $zero, 0x20
/* 138098 80244D58 8E040004 */  lw        $a0, 4($s0)
/* 13809C 80244D5C 240500FF */  addiu     $a1, $zero, 0xff
.L80244D60:
/* 1380A0 80244D60 0C0513AC */  jal       set_hud_element_alpha
/* 1380A4 80244D64 00000000 */   nop
/* 1380A8 80244D68 26450016 */  addiu     $a1, $s2, 0x16
/* 1380AC 80244D6C 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 1380B0 80244D70 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 1380B4 80244D74 8E040004 */  lw        $a0, 4($s0)
/* 1380B8 80244D78 0C051261 */  jal       set_hud_element_render_pos
/* 1380BC 80244D7C 26660007 */   addiu    $a2, $s3, 7
/* 1380C0 80244D80 8E040004 */  lw        $a0, 4($s0)
/* 1380C4 80244D84 0C0511F8 */  jal       draw_icon_2
/* 1380C8 80244D88 00000000 */   nop
/* 1380CC 80244D8C 3C028027 */  lui       $v0, %hi(gPauseMenuCurrentTab)
/* 1380D0 80244D90 804200D4 */  lb        $v0, %lo(gPauseMenuCurrentTab)($v0)
/* 1380D4 80244D94 1440000C */  bnez      $v0, .L80244DC8
/* 1380D8 80244D98 00000000 */   nop
/* 1380DC 80244D9C 82830001 */  lb        $v1, 1($s4)
/* 1380E0 80244DA0 3C028025 */  lui       $v0, %hi(D_8024F1D8)
/* 1380E4 80244DA4 2442F1D8 */  addiu     $v0, $v0, %lo(D_8024F1D8)
/* 1380E8 80244DA8 00622021 */  addu      $a0, $v1, $v0
/* 1380EC 80244DAC 90830000 */  lbu       $v1, ($a0)
/* 1380F0 80244DB0 2402001A */  addiu     $v0, $zero, 0x1a
/* 1380F4 80244DB4 14620004 */  bne       $v1, $v0, .L80244DC8
/* 1380F8 80244DB8 0060202D */   daddu    $a0, $v1, $zero
/* 1380FC 80244DBC 0240282D */  daddu     $a1, $s2, $zero
/* 138100 80244DC0 0C090B41 */  jal       func_80242D04
/* 138104 80244DC4 26660006 */   addiu    $a2, $s3, 6
.L80244DC8:
/* 138108 80244DC8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 13810C 80244DCC 8FB40020 */  lw        $s4, 0x20($sp)
/* 138110 80244DD0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 138114 80244DD4 8FB20018 */  lw        $s2, 0x18($sp)
/* 138118 80244DD8 8FB10014 */  lw        $s1, 0x14($sp)
/* 13811C 80244DDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 138120 80244DE0 03E00008 */  jr        $ra
/* 138124 80244DE4 27BD0028 */   addiu    $sp, $sp, 0x28
