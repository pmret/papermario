.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DD54
/* 39154 8005DD54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 39158 8005DD58 AFB00010 */  sw        $s0, 0x10($sp)
/* 3915C 8005DD5C 0080802D */  daddu     $s0, $a0, $zero
/* 39160 8005DD60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 39164 8005DD64 C60C0084 */  lwc1      $f12, 0x84($s0)
/* 39168 8005DD68 0C00A6C9 */  jal       clamp_angle
/* 3916C 8005DD6C 46806320 */   cvt.s.w  $f12, $f12
/* 39170 8005DD70 3C014334 */  lui       $at, 0x4334
/* 39174 8005DD74 44811000 */  mtc1      $at, $f2
/* 39178 8005DD78 4600018D */  trunc.w.s $f6, $f0
/* 3917C 8005DD7C E6060084 */  swc1      $f6, 0x84($s0)
/* 39180 8005DD80 4600103E */  c.le.s    $f2, $f0
/* 39184 8005DD84 00000000 */  nop       
/* 39188 8005DD88 45030001 */  bc1tl     .L8005DD90
/* 3918C 8005DD8C 46020001 */   sub.s    $f0, $f0, $f2
.L8005DD90:
/* 39190 8005DD90 3C0142B4 */  lui       $at, 0x42b4
/* 39194 8005DD94 44812000 */  mtc1      $at, $f4
/* 39198 8005DD98 00000000 */  nop       
/* 3919C 8005DD9C 4600203E */  c.le.s    $f4, $f0
/* 391A0 8005DDA0 00000000 */  nop       
/* 391A4 8005DDA4 45030001 */  bc1tl     .L8005DDAC
/* 391A8 8005DDA8 46001001 */   sub.s    $f0, $f2, $f0
.L8005DDAC:
/* 391AC 8005DDAC 46002001 */  sub.s     $f0, $f4, $f0
/* 391B0 8005DDB0 3C0142BE */  lui       $at, 0x42be
/* 391B4 8005DDB4 44811000 */  mtc1      $at, $f2
/* 391B8 8005DDB8 00000000 */  nop       
/* 391BC 8005DDBC 46020002 */  mul.s     $f0, $f0, $f2
/* 391C0 8005DDC0 00000000 */  nop       
/* 391C4 8005DDC4 46040003 */  div.s     $f0, $f0, $f4
/* 391C8 8005DDC8 4600018D */  trunc.w.s $f6, $f0
/* 391CC 8005DDCC 44023000 */  mfc1      $v0, $f6
/* 391D0 8005DDD0 00000000 */  nop       
/* 391D4 8005DDD4 244200A0 */  addiu     $v0, $v0, 0xa0
/* 391D8 8005DDD8 AE02008C */  sw        $v0, 0x8c($s0)
/* 391DC 8005DDDC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 391E0 8005DDE0 8FB00010 */  lw        $s0, 0x10($sp)
/* 391E4 8005DDE4 24020002 */  addiu     $v0, $zero, 2
/* 391E8 8005DDE8 03E00008 */  jr        $ra
/* 391EC 8005DDEC 27BD0018 */   addiu    $sp, $sp, 0x18
