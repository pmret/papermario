.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B0_926BA0
/* 926BA0 802401B0 3C01C019 */  lui       $at, 0xc019
/* 926BA4 802401B4 3421999A */  ori       $at, $at, 0x999a
/* 926BA8 802401B8 44810000 */  mtc1      $at, $f0
/* 926BAC 802401BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 926BB0 802401C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 926BB4 802401C4 0080802D */  daddu     $s0, $a0, $zero
/* 926BB8 802401C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 926BBC 802401CC C60C008C */  lwc1      $f12, 0x8c($s0)
/* 926BC0 802401D0 46806320 */  cvt.s.w   $f12, $f12
/* 926BC4 802401D4 46006302 */  mul.s     $f12, $f12, $f0
/* 926BC8 802401D8 0C00A6C9 */  jal       clamp_angle
/* 926BCC 802401DC 00000000 */   nop      
/* 926BD0 802401E0 3C05FE36 */  lui       $a1, 0xfe36
/* 926BD4 802401E4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 926BD8 802401E8 44060000 */  mfc1      $a2, $f0
/* 926BDC 802401EC 0C0B2190 */  jal       set_float_variable
/* 926BE0 802401F0 0200202D */   daddu    $a0, $s0, $zero
/* 926BE4 802401F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 926BE8 802401F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 926BEC 802401FC 24020002 */  addiu     $v0, $zero, 2
/* 926BF0 80240200 03E00008 */  jr        $ra
/* 926BF4 80240204 27BD0018 */   addiu    $sp, $sp, 0x18
