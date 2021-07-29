.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_draw_items
/* 138128 80244DE8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 13812C 80244DEC AFB10014 */  sw        $s1, 0x14($sp)
/* 138130 80244DF0 8FB10040 */  lw        $s1, 0x40($sp)
/* 138134 80244DF4 AFB40020 */  sw        $s4, 0x20($sp)
/* 138138 80244DF8 0080A02D */  daddu     $s4, $a0, $zero
/* 13813C 80244DFC AFB20018 */  sw        $s2, 0x18($sp)
/* 138140 80244E00 00A0902D */  daddu     $s2, $a1, $zero
/* 138144 80244E04 AFB3001C */  sw        $s3, 0x1c($sp)
/* 138148 80244E08 00C0982D */  daddu     $s3, $a2, $zero
/* 13814C 80244E0C AFBF0024 */  sw        $ra, 0x24($sp)
/* 138150 80244E10 12200016 */  beqz      $s1, .L80244E6C
/* 138154 80244E14 AFB00010 */   sw       $s0, 0x10($sp)
/* 138158 80244E18 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 13815C 80244E1C 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 138160 80244E20 8E040008 */  lw        $a0, 8($s0)
/* 138164 80244E24 0C051280 */  jal       set_hud_element_flags
/* 138168 80244E28 24050020 */   addiu    $a1, $zero, 0x20
/* 13816C 80244E2C 3C013FE0 */  lui       $at, 0x3fe0
/* 138170 80244E30 44811800 */  mtc1      $at, $f3
/* 138174 80244E34 44801000 */  mtc1      $zero, $f2
/* 138178 80244E38 44910000 */  mtc1      $s1, $f0
/* 13817C 80244E3C 00000000 */  nop
/* 138180 80244E40 46800021 */  cvt.d.w   $f0, $f0
/* 138184 80244E44 46220002 */  mul.d     $f0, $f0, $f2
/* 138188 80244E48 00000000 */  nop
/* 13818C 80244E4C 3C018027 */  lui       $at, %hi(D_8026FF90)
/* 138190 80244E50 D422FF90 */  ldc1      $f2, %lo(D_8026FF90)($at)
/* 138194 80244E54 46201081 */  sub.d     $f2, $f2, $f0
/* 138198 80244E58 8E040008 */  lw        $a0, 8($s0)
/* 13819C 80244E5C 4620110D */  trunc.w.d $f4, $f2
/* 1381A0 80244E60 44052000 */  mfc1      $a1, $f4
/* 1381A4 80244E64 080913A2 */  j         .L80244E88
/* 1381A8 80244E68 00000000 */   nop
.L80244E6C:
/* 1381AC 80244E6C 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 1381B0 80244E70 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 1381B4 80244E74 8E040008 */  lw        $a0, 8($s0)
/* 1381B8 80244E78 0C05128B */  jal       clear_hud_element_flags
/* 1381BC 80244E7C 24050020 */   addiu    $a1, $zero, 0x20
/* 1381C0 80244E80 8E040008 */  lw        $a0, 8($s0)
/* 1381C4 80244E84 240500FF */  addiu     $a1, $zero, 0xff
.L80244E88:
/* 1381C8 80244E88 0C0513AC */  jal       set_hud_element_alpha
/* 1381CC 80244E8C 00000000 */   nop
/* 1381D0 80244E90 26450016 */  addiu     $a1, $s2, 0x16
/* 1381D4 80244E94 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 1381D8 80244E98 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 1381DC 80244E9C 8E040008 */  lw        $a0, 8($s0)
/* 1381E0 80244EA0 0C051261 */  jal       set_hud_element_render_pos
/* 1381E4 80244EA4 26660007 */   addiu    $a2, $s3, 7
/* 1381E8 80244EA8 8E040008 */  lw        $a0, 8($s0)
/* 1381EC 80244EAC 0C0511F8 */  jal       draw_icon_2
/* 1381F0 80244EB0 00000000 */   nop
/* 1381F4 80244EB4 3C028027 */  lui       $v0, %hi(gPauseMenuCurrentTab)
/* 1381F8 80244EB8 804200D4 */  lb        $v0, %lo(gPauseMenuCurrentTab)($v0)
/* 1381FC 80244EBC 1440000C */  bnez      $v0, .L80244EF0
/* 138200 80244EC0 00000000 */   nop
/* 138204 80244EC4 82830001 */  lb        $v1, 1($s4)
/* 138208 80244EC8 3C028025 */  lui       $v0, %hi(D_8024F1D8)
/* 13820C 80244ECC 2442F1D8 */  addiu     $v0, $v0, %lo(D_8024F1D8)
/* 138210 80244ED0 00622021 */  addu      $a0, $v1, $v0
/* 138214 80244ED4 90830000 */  lbu       $v1, ($a0)
/* 138218 80244ED8 2402001B */  addiu     $v0, $zero, 0x1b
/* 13821C 80244EDC 14620004 */  bne       $v1, $v0, .L80244EF0
/* 138220 80244EE0 0060202D */   daddu    $a0, $v1, $zero
/* 138224 80244EE4 0240282D */  daddu     $a1, $s2, $zero
/* 138228 80244EE8 0C090B41 */  jal       func_80242D04
/* 13822C 80244EEC 26660006 */   addiu    $a2, $s3, 6
.L80244EF0:
/* 138230 80244EF0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 138234 80244EF4 8FB40020 */  lw        $s4, 0x20($sp)
/* 138238 80244EF8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 13823C 80244EFC 8FB20018 */  lw        $s2, 0x18($sp)
/* 138240 80244F00 8FB10014 */  lw        $s1, 0x14($sp)
/* 138244 80244F04 8FB00010 */  lw        $s0, 0x10($sp)
/* 138248 80244F08 03E00008 */  jr        $ra
/* 13824C 80244F0C 27BD0028 */   addiu    $sp, $sp, 0x28
