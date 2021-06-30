.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242084_8EDEA4
/* 8EDEA4 80242084 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDEA8 80242088 AFB00010 */  sw        $s0, 0x10($sp)
/* 8EDEAC 8024208C 0080802D */  daddu     $s0, $a0, $zero
/* 8EDEB0 80242090 10A00002 */  beqz      $a1, .L8024209C
/* 8EDEB4 80242094 AFBF0014 */   sw       $ra, 0x14($sp)
/* 8EDEB8 80242098 AE000074 */  sw        $zero, 0x74($s0)
.L8024209C:
/* 8EDEBC 8024209C 8E020074 */  lw        $v0, 0x74($s0)
/* 8EDEC0 802420A0 24420010 */  addiu     $v0, $v0, 0x10
/* 8EDEC4 802420A4 AE020074 */  sw        $v0, 0x74($s0)
/* 8EDEC8 802420A8 28420100 */  slti      $v0, $v0, 0x100
/* 8EDECC 802420AC 14400002 */  bnez      $v0, .L802420B8
/* 8EDED0 802420B0 240200FF */   addiu    $v0, $zero, 0xff
/* 8EDED4 802420B4 AE020074 */  sw        $v0, 0x74($s0)
.L802420B8:
/* 8EDED8 802420B8 C6000074 */  lwc1      $f0, 0x74($s0)
/* 8EDEDC 802420BC 46800020 */  cvt.s.w   $f0, $f0
/* 8EDEE0 802420C0 44050000 */  mfc1      $a1, $f0
/* 8EDEE4 802420C4 0C04DF62 */  jal       set_screen_overlay_params_front
/* 8EDEE8 802420C8 0000202D */   daddu    $a0, $zero, $zero
/* 8EDEEC 802420CC 8E020074 */  lw        $v0, 0x74($s0)
/* 8EDEF0 802420D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8EDEF4 802420D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EDEF8 802420D8 384200FF */  xori      $v0, $v0, 0xff
/* 8EDEFC 802420DC 2C420001 */  sltiu     $v0, $v0, 1
/* 8EDF00 802420E0 00021040 */  sll       $v0, $v0, 1
/* 8EDF04 802420E4 03E00008 */  jr        $ra
/* 8EDF08 802420E8 27BD0018 */   addiu    $sp, $sp, 0x18
