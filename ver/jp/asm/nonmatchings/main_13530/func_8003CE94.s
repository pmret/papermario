.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003CE94
/* 18294 8003CE94 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 18298 8003CE98 AFB20018 */  sw        $s2, 0x18($sp)
/* 1829C 8003CE9C 34924000 */  ori       $s2, $a0, 0x4000
/* 182A0 8003CEA0 0240202D */  daddu     $a0, $s2, $zero
/* 182A4 8003CEA4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 182A8 8003CEA8 AFB50024 */  sw        $s5, 0x24($sp)
/* 182AC 8003CEAC AFB40020 */  sw        $s4, 0x20($sp)
/* 182B0 8003CEB0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 182B4 8003CEB4 AFB10014 */  sw        $s1, 0x14($sp)
/* 182B8 8003CEB8 0C0455FE */  jal       func_801157F8
/* 182BC 8003CEBC AFB00010 */   sw       $s0, 0x10($sp)
/* 182C0 8003CEC0 0000882D */  daddu     $s1, $zero, $zero
/* 182C4 8003CEC4 C440004C */  lwc1      $f0, 0x4c($v0)
/* 182C8 8003CEC8 3C014120 */  lui       $at, 0x4120
/* 182CC 8003CECC 44811000 */  mtc1      $at, $f2
/* 182D0 8003CED0 3C148000 */  lui       $s4, 0x8000
/* 182D4 8003CED4 46020001 */  sub.s     $f0, $f0, $f2
/* 182D8 8003CED8 36940004 */  ori       $s4, $s4, 4
/* 182DC 8003CEDC 3C150400 */  lui       $s5, 0x400
/* 182E0 8003CEE0 4600010D */  trunc.w.s $f4, $f0
/* 182E4 8003CEE4 44132000 */  mfc1      $s3, $f4
.L8003CEE8:
/* 182E8 8003CEE8 3C03800A */  lui       $v1, %hi(D_8009E9A0)
/* 182EC 8003CEEC 8C63E9A0 */  lw        $v1, %lo(D_8009E9A0)($v1)
/* 182F0 8003CEF0 00111080 */  sll       $v0, $s1, 2
/* 182F4 8003CEF4 00431021 */  addu      $v0, $v0, $v1
/* 182F8 8003CEF8 8C500000 */  lw        $s0, ($v0)
/* 182FC 8003CEFC 52000022 */  beql      $s0, $zero, .L8003CF88
/* 18300 8003CF00 26310001 */   addiu    $s1, $s1, 1
/* 18304 8003CF04 8E030000 */  lw        $v1, ($s0)
/* 18308 8003CF08 5060001F */  beql      $v1, $zero, .L8003CF88
/* 1830C 8003CF0C 26310001 */   addiu    $s1, $s1, 1
/* 18310 8003CF10 00741024 */  and       $v0, $v1, $s4
/* 18314 8003CF14 5440001C */  bnel      $v0, $zero, .L8003CF88
/* 18318 8003CF18 26310001 */   addiu    $s1, $s1, 1
/* 1831C 8003CF1C C602003C */  lwc1      $f2, 0x3c($s0)
/* 18320 8003CF20 44930000 */  mtc1      $s3, $f0
/* 18324 8003CF24 00000000 */  nop
/* 18328 8003CF28 46800020 */  cvt.s.w   $f0, $f0
/* 1832C 8003CF2C 4600103C */  c.lt.s    $f2, $f0
/* 18330 8003CF30 00000000 */  nop
/* 18334 8003CF34 45030014 */  bc1tl     .L8003CF88
/* 18338 8003CF38 26310001 */   addiu    $s1, $s1, 1
/* 1833C 8003CF3C 30628008 */  andi      $v0, $v1, 0x8008
/* 18340 8003CF40 10400008 */  beqz      $v0, .L8003CF64
/* 18344 8003CF44 00000000 */   nop
/* 18348 8003CF48 0C00F3EE */  jal       func_8003CFB8
/* 1834C 8003CF4C 0200202D */   daddu    $a0, $s0, $zero
/* 18350 8003CF50 0040182D */  daddu     $v1, $v0, $zero
/* 18354 8003CF54 5060000C */  beql      $v1, $zero, .L8003CF88
/* 18358 8003CF58 26310001 */   addiu    $s1, $s1, 1
/* 1835C 8003CF5C 0800F3DE */  j         .L8003CF78
/* 18360 8003CF60 00000000 */   nop
.L8003CF64:
/* 18364 8003CF64 96020084 */  lhu       $v0, 0x84($s0)
/* 18368 8003CF68 86030084 */  lh        $v1, 0x84($s0)
/* 1836C 8003CF6C 30424000 */  andi      $v0, $v0, 0x4000
/* 18370 8003CF70 50400005 */  beql      $v0, $zero, .L8003CF88
/* 18374 8003CF74 26310001 */   addiu    $s1, $s1, 1
.L8003CF78:
/* 18378 8003CF78 56430003 */  bnel      $s2, $v1, .L8003CF88
/* 1837C 8003CF7C 26310001 */   addiu    $s1, $s1, 1
/* 18380 8003CF80 0800F3E5 */  j         .L8003CF94
/* 18384 8003CF84 0220102D */   daddu    $v0, $s1, $zero
.L8003CF88:
/* 18388 8003CF88 2A220040 */  slti      $v0, $s1, 0x40
/* 1838C 8003CF8C 1440FFD6 */  bnez      $v0, .L8003CEE8
/* 18390 8003CF90 2402FFFF */   addiu    $v0, $zero, -1
.L8003CF94:
/* 18394 8003CF94 8FBF0028 */  lw        $ra, 0x28($sp)
/* 18398 8003CF98 8FB50024 */  lw        $s5, 0x24($sp)
/* 1839C 8003CF9C 8FB40020 */  lw        $s4, 0x20($sp)
/* 183A0 8003CFA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 183A4 8003CFA4 8FB20018 */  lw        $s2, 0x18($sp)
/* 183A8 8003CFA8 8FB10014 */  lw        $s1, 0x14($sp)
/* 183AC 8003CFAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 183B0 8003CFB0 03E00008 */  jr        $ra
/* 183B4 8003CFB4 27BD0030 */   addiu    $sp, $sp, 0x30
