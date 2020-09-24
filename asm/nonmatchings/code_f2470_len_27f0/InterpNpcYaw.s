.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel InterpNpcYaw
/* F34B4 802CEB04 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F34B8 802CEB08 AFB20018 */  sw        $s2, 0x18($sp)
/* F34BC 802CEB0C 0080902D */  daddu     $s2, $a0, $zero
/* F34C0 802CEB10 AFB50024 */  sw        $s5, 0x24($sp)
/* F34C4 802CEB14 26550074 */  addiu     $s5, $s2, 0x74
/* F34C8 802CEB18 AFB40020 */  sw        $s4, 0x20($sp)
/* F34CC 802CEB1C 26540078 */  addiu     $s4, $s2, 0x78
/* F34D0 802CEB20 AFB3001C */  sw        $s3, 0x1c($sp)
/* F34D4 802CEB24 AFBF0028 */  sw        $ra, 0x28($sp)
/* F34D8 802CEB28 AFB10014 */  sw        $s1, 0x14($sp)
/* F34DC 802CEB2C AFB00010 */  sw        $s0, 0x10($sp)
/* F34E0 802CEB30 8E51000C */  lw        $s1, 0xc($s2)
/* F34E4 802CEB34 10A0003B */  beqz      $a1, .L802CEC24
/* F34E8 802CEB38 2653007C */   addiu    $s3, $s2, 0x7c
/* F34EC 802CEB3C 8E250000 */  lw        $a1, ($s1)
/* F34F0 802CEB40 0C0B1EAF */  jal       get_variable
/* F34F4 802CEB44 26310004 */   addiu    $s1, $s1, 4
/* F34F8 802CEB48 0240202D */  daddu     $a0, $s2, $zero
/* F34FC 802CEB4C 0C0B36B0 */  jal       resolve_npc
/* F3500 802CEB50 0040282D */   daddu    $a1, $v0, $zero
/* F3504 802CEB54 0040802D */  daddu     $s0, $v0, $zero
/* F3508 802CEB58 12000052 */  beqz      $s0, .L802CECA4
/* F350C 802CEB5C 24020002 */   addiu    $v0, $zero, 2
/* F3510 802CEB60 C600000C */  lwc1      $f0, 0xc($s0)
/* F3514 802CEB64 E6400074 */  swc1      $f0, 0x74($s2)
/* F3518 802CEB68 8E250000 */  lw        $a1, ($s1)
/* F351C 802CEB6C 0C0B1EAF */  jal       get_variable
/* F3520 802CEB70 0240202D */   daddu    $a0, $s2, $zero
/* F3524 802CEB74 C6420074 */  lwc1      $f2, 0x74($s2)
/* F3528 802CEB78 44820000 */  mtc1      $v0, $f0
/* F352C 802CEB7C 00000000 */  nop       
/* F3530 802CEB80 46800020 */  cvt.s.w   $f0, $f0
/* F3534 802CEB84 46020001 */  sub.s     $f0, $f0, $f2
/* F3538 802CEB88 26310004 */  addiu     $s1, $s1, 4
/* F353C 802CEB8C AE500070 */  sw        $s0, 0x70($s2)
/* F3540 802CEB90 E6400078 */  swc1      $f0, 0x78($s2)
/* F3544 802CEB94 8E250000 */  lw        $a1, ($s1)
/* F3548 802CEB98 0C0B1EAF */  jal       get_variable
/* F354C 802CEB9C 0240202D */   daddu    $a0, $s2, $zero
/* F3550 802CEBA0 14400005 */  bnez      $v0, .L802CEBB8
/* F3554 802CEBA4 AE42007C */   sw       $v0, 0x7c($s2)
/* F3558 802CEBA8 C600000C */  lwc1      $f0, 0xc($s0)
/* F355C 802CEBAC C6420078 */  lwc1      $f2, 0x78($s2)
/* F3560 802CEBB0 080B3B0F */  j         .L802CEC3C
/* F3564 802CEBB4 46020000 */   add.s    $f0, $f0, $f2
.L802CEBB8:
/* F3568 802CEBB8 A600008E */  sh        $zero, 0x8e($s0)
/* F356C 802CEBBC C6420078 */  lwc1      $f2, 0x78($s2)
/* F3570 802CEBC0 3C01C334 */  lui       $at, 0xc334
/* F3574 802CEBC4 44810000 */  mtc1      $at, $f0
/* F3578 802CEBC8 00000000 */  nop       
/* F357C 802CEBCC 4600103C */  c.lt.s    $f2, $f0
/* F3580 802CEBD0 00000000 */  nop       
/* F3584 802CEBD4 45000007 */  bc1f      .L802CEBF4
/* F3588 802CEBD8 00000000 */   nop      
/* F358C 802CEBDC 3C0143B4 */  lui       $at, 0x43b4
/* F3590 802CEBE0 44810000 */  mtc1      $at, $f0
/* F3594 802CEBE4 00000000 */  nop       
/* F3598 802CEBE8 46001000 */  add.s     $f0, $f2, $f0
/* F359C 802CEBEC E6400078 */  swc1      $f0, 0x78($s2)
/* F35A0 802CEBF0 C6420078 */  lwc1      $f2, 0x78($s2)
.L802CEBF4:
/* F35A4 802CEBF4 3C014334 */  lui       $at, 0x4334
/* F35A8 802CEBF8 44810000 */  mtc1      $at, $f0
/* F35AC 802CEBFC 00000000 */  nop       
/* F35B0 802CEC00 4602003C */  c.lt.s    $f0, $f2
/* F35B4 802CEC04 00000000 */  nop       
/* F35B8 802CEC08 45000006 */  bc1f      .L802CEC24
/* F35BC 802CEC0C 00000000 */   nop      
/* F35C0 802CEC10 3C0143B4 */  lui       $at, 0x43b4
/* F35C4 802CEC14 44810000 */  mtc1      $at, $f0
/* F35C8 802CEC18 00000000 */  nop       
/* F35CC 802CEC1C 46001001 */  sub.s     $f0, $f2, $f0
/* F35D0 802CEC20 E6400078 */  swc1      $f0, 0x78($s2)
.L802CEC24:
/* F35D4 802CEC24 8E620000 */  lw        $v0, ($s3)
/* F35D8 802CEC28 1C400007 */  bgtz      $v0, .L802CEC48
/* F35DC 802CEC2C 8E500070 */   lw       $s0, 0x70($s2)
/* F35E0 802CEC30 C600000C */  lwc1      $f0, 0xc($s0)
/* F35E4 802CEC34 C6820000 */  lwc1      $f2, ($s4)
/* F35E8 802CEC38 46020000 */  add.s     $f0, $f0, $f2
.L802CEC3C:
/* F35EC 802CEC3C 24020002 */  addiu     $v0, $zero, 2
/* F35F0 802CEC40 080B3B29 */  j         .L802CECA4
/* F35F4 802CEC44 E600000C */   swc1     $f0, 0xc($s0)
.L802CEC48:
/* F35F8 802CEC48 9602008E */  lhu       $v0, 0x8e($s0)
/* F35FC 802CEC4C 24420001 */  addiu     $v0, $v0, 1
/* F3600 802CEC50 A602008E */  sh        $v0, 0x8e($s0)
/* F3604 802CEC54 00021400 */  sll       $v0, $v0, 0x10
/* F3608 802CEC58 00021403 */  sra       $v0, $v0, 0x10
/* F360C 802CEC5C C6800000 */  lwc1      $f0, ($s4)
/* F3610 802CEC60 44821000 */  mtc1      $v0, $f2
/* F3614 802CEC64 00000000 */  nop       
/* F3618 802CEC68 468010A0 */  cvt.s.w   $f2, $f2
/* F361C 802CEC6C 46020002 */  mul.s     $f0, $f0, $f2
/* F3620 802CEC70 00000000 */  nop       
/* F3624 802CEC74 C6AC0000 */  lwc1      $f12, ($s5)
/* F3628 802CEC78 C6620000 */  lwc1      $f2, ($s3)
/* F362C 802CEC7C 468010A0 */  cvt.s.w   $f2, $f2
/* F3630 802CEC80 46020003 */  div.s     $f0, $f0, $f2
/* F3634 802CEC84 46006300 */  add.s     $f12, $f12, $f0
/* F3638 802CEC88 0C00A6C9 */  jal       clamp_angle
/* F363C 802CEC8C E60C000C */   swc1     $f12, 0xc($s0)
/* F3640 802CEC90 8602008E */  lh        $v0, 0x8e($s0)
/* F3644 802CEC94 E600000C */  swc1      $f0, 0xc($s0)
/* F3648 802CEC98 8E630000 */  lw        $v1, ($s3)
/* F364C 802CEC9C 0043102A */  slt       $v0, $v0, $v1
/* F3650 802CECA0 38420001 */  xori      $v0, $v0, 1
.L802CECA4:
/* F3654 802CECA4 8FBF0028 */  lw        $ra, 0x28($sp)
/* F3658 802CECA8 8FB50024 */  lw        $s5, 0x24($sp)
/* F365C 802CECAC 8FB40020 */  lw        $s4, 0x20($sp)
/* F3660 802CECB0 8FB3001C */  lw        $s3, 0x1c($sp)
/* F3664 802CECB4 8FB20018 */  lw        $s2, 0x18($sp)
/* F3668 802CECB8 8FB10014 */  lw        $s1, 0x14($sp)
/* F366C 802CECBC 8FB00010 */  lw        $s0, 0x10($sp)
/* F3670 802CECC0 03E00008 */  jr        $ra
/* F3674 802CECC4 27BD0030 */   addiu    $sp, $sp, 0x30
