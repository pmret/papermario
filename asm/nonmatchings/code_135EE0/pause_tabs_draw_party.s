.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_draw_party
/* 138250 80244F10 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 138254 80244F14 AFB10014 */  sw        $s1, 0x14($sp)
/* 138258 80244F18 8FB10040 */  lw        $s1, 0x40($sp)
/* 13825C 80244F1C AFB40020 */  sw        $s4, 0x20($sp)
/* 138260 80244F20 0080A02D */  daddu     $s4, $a0, $zero
/* 138264 80244F24 AFB20018 */  sw        $s2, 0x18($sp)
/* 138268 80244F28 00A0902D */  daddu     $s2, $a1, $zero
/* 13826C 80244F2C AFB3001C */  sw        $s3, 0x1c($sp)
/* 138270 80244F30 00C0982D */  daddu     $s3, $a2, $zero
/* 138274 80244F34 AFBF0024 */  sw        $ra, 0x24($sp)
/* 138278 80244F38 12200016 */  beqz      $s1, .L80244F94
/* 13827C 80244F3C AFB00010 */   sw       $s0, 0x10($sp)
/* 138280 80244F40 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 138284 80244F44 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 138288 80244F48 8E04000C */  lw        $a0, 0xc($s0)
/* 13828C 80244F4C 0C051280 */  jal       set_icon_flags
/* 138290 80244F50 24050020 */   addiu    $a1, $zero, 0x20
/* 138294 80244F54 3C013FE0 */  lui       $at, 0x3fe0
/* 138298 80244F58 44811800 */  mtc1      $at, $f3
/* 13829C 80244F5C 44801000 */  mtc1      $zero, $f2
/* 1382A0 80244F60 44910000 */  mtc1      $s1, $f0
/* 1382A4 80244F64 00000000 */  nop       
/* 1382A8 80244F68 46800021 */  cvt.d.w   $f0, $f0
/* 1382AC 80244F6C 46220002 */  mul.d     $f0, $f0, $f2
/* 1382B0 80244F70 00000000 */  nop       
/* 1382B4 80244F74 3C018027 */  lui       $at, 0x8027
/* 1382B8 80244F78 D422FF98 */  ldc1      $f2, -0x68($at)
/* 1382BC 80244F7C 46201081 */  sub.d     $f2, $f2, $f0
/* 1382C0 80244F80 8E04000C */  lw        $a0, 0xc($s0)
/* 1382C4 80244F84 4620110D */  trunc.w.d $f4, $f2
/* 1382C8 80244F88 44052000 */  mfc1      $a1, $f4
/* 1382CC 80244F8C 080913EC */  j         .L80244FB0
/* 1382D0 80244F90 00000000 */   nop      
.L80244F94:
/* 1382D4 80244F94 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 1382D8 80244F98 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 1382DC 80244F9C 8E04000C */  lw        $a0, 0xc($s0)
/* 1382E0 80244FA0 0C05128B */  jal       clear_icon_flags
/* 1382E4 80244FA4 24050020 */   addiu    $a1, $zero, 0x20
/* 1382E8 80244FA8 8E04000C */  lw        $a0, 0xc($s0)
/* 1382EC 80244FAC 240500FF */  addiu     $a1, $zero, 0xff
.L80244FB0:
/* 1382F0 80244FB0 0C0513AC */  jal       icon_set_opacity
/* 1382F4 80244FB4 00000000 */   nop      
/* 1382F8 80244FB8 26450016 */  addiu     $a1, $s2, 0x16
/* 1382FC 80244FBC 3C108027 */  lui       $s0, %hi(gPauseMenuTabIconIDs)
/* 138300 80244FC0 26100130 */  addiu     $s0, $s0, %lo(gPauseMenuTabIconIDs)
/* 138304 80244FC4 8E04000C */  lw        $a0, 0xc($s0)
/* 138308 80244FC8 0C051261 */  jal       set_icon_render_pos
/* 13830C 80244FCC 26660007 */   addiu    $a2, $s3, 7
/* 138310 80244FD0 8E04000C */  lw        $a0, 0xc($s0)
/* 138314 80244FD4 0C0511F8 */  jal       draw_icon_2
/* 138318 80244FD8 00000000 */   nop      
/* 13831C 80244FDC 3C028027 */  lui       $v0, 0x8027
/* 138320 80244FE0 804200D4 */  lb        $v0, 0xd4($v0)
/* 138324 80244FE4 1440000C */  bnez      $v0, .L80245018
/* 138328 80244FE8 00000000 */   nop      
/* 13832C 80244FEC 82830001 */  lb        $v1, 1($s4)
/* 138330 80244FF0 3C028025 */  lui       $v0, 0x8025
/* 138334 80244FF4 2442F1D8 */  addiu     $v0, $v0, -0xe28
/* 138338 80244FF8 00622021 */  addu      $a0, $v1, $v0
/* 13833C 80244FFC 90830000 */  lbu       $v1, ($a0)
/* 138340 80245000 2402001C */  addiu     $v0, $zero, 0x1c
/* 138344 80245004 14620004 */  bne       $v1, $v0, .L80245018
/* 138348 80245008 0060202D */   daddu    $a0, $v1, $zero
/* 13834C 8024500C 0240282D */  daddu     $a1, $s2, $zero
/* 138350 80245010 0C090B41 */  jal       func_80242D04
/* 138354 80245014 26660006 */   addiu    $a2, $s3, 6
.L80245018:
/* 138358 80245018 8FBF0024 */  lw        $ra, 0x24($sp)
/* 13835C 8024501C 8FB40020 */  lw        $s4, 0x20($sp)
/* 138360 80245020 8FB3001C */  lw        $s3, 0x1c($sp)
/* 138364 80245024 8FB20018 */  lw        $s2, 0x18($sp)
/* 138368 80245028 8FB10014 */  lw        $s1, 0x14($sp)
/* 13836C 8024502C 8FB00010 */  lw        $s0, 0x10($sp)
/* 138370 80245030 03E00008 */  jr        $ra
/* 138374 80245034 27BD0028 */   addiu    $sp, $sp, 0x28
