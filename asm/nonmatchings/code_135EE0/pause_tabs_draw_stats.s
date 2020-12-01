.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_draw_stats
/* 137ED8 80244B98 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 137EDC 80244B9C AFB10014 */  sw        $s1, 0x14($sp)
/* 137EE0 80244BA0 8FB10040 */  lw        $s1, 0x40($sp)
/* 137EE4 80244BA4 AFB40020 */  sw        $s4, 0x20($sp)
/* 137EE8 80244BA8 0080A02D */  daddu     $s4, $a0, $zero
/* 137EEC 80244BAC AFB20018 */  sw        $s2, 0x18($sp)
/* 137EF0 80244BB0 00A0902D */  daddu     $s2, $a1, $zero
/* 137EF4 80244BB4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 137EF8 80244BB8 00C0982D */  daddu     $s3, $a2, $zero
/* 137EFC 80244BBC AFBF0024 */  sw        $ra, 0x24($sp)
/* 137F00 80244BC0 12200016 */  beqz      $s1, .L80244C1C
/* 137F04 80244BC4 AFB00010 */   sw       $s0, 0x10($sp)
/* 137F08 80244BC8 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 137F0C 80244BCC 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 137F10 80244BD0 8E040000 */  lw        $a0, ($s0)
/* 137F14 80244BD4 0C051280 */  jal       set_icon_flags
/* 137F18 80244BD8 24050020 */   addiu    $a1, $zero, 0x20
/* 137F1C 80244BDC 3C013FE0 */  lui       $at, 0x3fe0
/* 137F20 80244BE0 44811800 */  mtc1      $at, $f3
/* 137F24 80244BE4 44801000 */  mtc1      $zero, $f2
/* 137F28 80244BE8 44910000 */  mtc1      $s1, $f0
/* 137F2C 80244BEC 00000000 */  nop       
/* 137F30 80244BF0 46800021 */  cvt.d.w   $f0, $f0
/* 137F34 80244BF4 46220002 */  mul.d     $f0, $f0, $f2
/* 137F38 80244BF8 00000000 */  nop       
/* 137F3C 80244BFC 3C018027 */  lui       $at, %hi(D_8026FF80)
/* 137F40 80244C00 D422FF80 */  ldc1      $f2, %lo(D_8026FF80)($at)
/* 137F44 80244C04 46201081 */  sub.d     $f2, $f2, $f0
/* 137F48 80244C08 8E040000 */  lw        $a0, ($s0)
/* 137F4C 80244C0C 4620110D */  trunc.w.d $f4, $f2
/* 137F50 80244C10 44052000 */  mfc1      $a1, $f4
/* 137F54 80244C14 0809130E */  j         .L80244C38
/* 137F58 80244C18 00000000 */   nop      
.L80244C1C:
/* 137F5C 80244C1C 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 137F60 80244C20 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 137F64 80244C24 8E040000 */  lw        $a0, ($s0)
/* 137F68 80244C28 0C05128B */  jal       clear_icon_flags
/* 137F6C 80244C2C 24050020 */   addiu    $a1, $zero, 0x20
/* 137F70 80244C30 8E040000 */  lw        $a0, ($s0)
/* 137F74 80244C34 240500FF */  addiu     $a1, $zero, 0xff
.L80244C38:
/* 137F78 80244C38 0C0513AC */  jal       icon_set_opacity
/* 137F7C 80244C3C 00000000 */   nop      
/* 137F80 80244C40 26450016 */  addiu     $a1, $s2, 0x16
/* 137F84 80244C44 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 137F88 80244C48 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 137F8C 80244C4C 8E040000 */  lw        $a0, ($s0)
/* 137F90 80244C50 0C051261 */  jal       set_icon_render_pos
/* 137F94 80244C54 26660007 */   addiu    $a2, $s3, 7
/* 137F98 80244C58 8E040000 */  lw        $a0, ($s0)
/* 137F9C 80244C5C 0C0511F8 */  jal       draw_icon_2
/* 137FA0 80244C60 00000000 */   nop      
/* 137FA4 80244C64 3C028027 */  lui       $v0, %hi(gPauseMenuCurrentTab)
/* 137FA8 80244C68 804200D4 */  lb        $v0, %lo(gPauseMenuCurrentTab)($v0)
/* 137FAC 80244C6C 1440000C */  bnez      $v0, .L80244CA0
/* 137FB0 80244C70 00000000 */   nop      
/* 137FB4 80244C74 82830001 */  lb        $v1, 1($s4)
/* 137FB8 80244C78 3C028025 */  lui       $v0, %hi(D_8024F1D8)
/* 137FBC 80244C7C 2442F1D8 */  addiu     $v0, $v0, %lo(D_8024F1D8)
/* 137FC0 80244C80 00622021 */  addu      $a0, $v1, $v0
/* 137FC4 80244C84 90830000 */  lbu       $v1, ($a0)
/* 137FC8 80244C88 24020019 */  addiu     $v0, $zero, 0x19
/* 137FCC 80244C8C 14620004 */  bne       $v1, $v0, .L80244CA0
/* 137FD0 80244C90 0060202D */   daddu    $a0, $v1, $zero
/* 137FD4 80244C94 0240282D */  daddu     $a1, $s2, $zero
/* 137FD8 80244C98 0C090B41 */  jal       func_80242D04
/* 137FDC 80244C9C 26660006 */   addiu    $a2, $s3, 6
.L80244CA0:
/* 137FE0 80244CA0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 137FE4 80244CA4 8FB40020 */  lw        $s4, 0x20($sp)
/* 137FE8 80244CA8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 137FEC 80244CAC 8FB20018 */  lw        $s2, 0x18($sp)
/* 137FF0 80244CB0 8FB10014 */  lw        $s1, 0x14($sp)
/* 137FF4 80244CB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 137FF8 80244CB8 03E00008 */  jr        $ra
/* 137FFC 80244CBC 27BD0028 */   addiu    $sp, $sp, 0x28
