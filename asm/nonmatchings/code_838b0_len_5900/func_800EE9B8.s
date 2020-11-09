.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EE9B8
/* 87E68 800EE9B8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 87E6C 800EE9BC AFB00010 */  sw        $s0, 0x10($sp)
/* 87E70 800EE9C0 0080802D */  daddu     $s0, $a0, $zero
/* 87E74 800EE9C4 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 87E78 800EE9C8 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 87E7C 800EE9CC AFB10014 */  sw        $s1, 0x14($sp)
/* 87E80 800EE9D0 3C118011 */  lui       $s1, 0x8011
/* 87E84 800EE9D4 2631CFC8 */  addiu     $s1, $s1, -0x3038
/* 87E88 800EE9D8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 87E8C 800EE9DC AFB20018 */  sw        $s2, 0x18($sp)
/* 87E90 800EE9E0 F7BE0048 */  sdc1      $f30, 0x48($sp)
/* 87E94 800EE9E4 F7BC0040 */  sdc1      $f28, 0x40($sp)
/* 87E98 800EE9E8 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 87E9C 800EE9EC F7B80030 */  sdc1      $f24, 0x30($sp)
/* 87EA0 800EE9F0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 87EA4 800EE9F4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 87EA8 800EE9F8 86230000 */  lh        $v1, ($s1)
/* 87EAC 800EE9FC 24120001 */  addiu     $s2, $zero, 1
/* 87EB0 800EEA00 10720062 */  beq       $v1, $s2, .L800EEB8C
/* 87EB4 800EEA04 28620002 */   slti     $v0, $v1, 2
/* 87EB8 800EEA08 10400005 */  beqz      $v0, .L800EEA20
/* 87EBC 800EEA0C 24020002 */   addiu    $v0, $zero, 2
/* 87EC0 800EEA10 10600007 */  beqz      $v1, .L800EEA30
/* 87EC4 800EEA14 0000102D */   daddu    $v0, $zero, $zero
/* 87EC8 800EEA18 0803BB25 */  j         .L800EEC94
/* 87ECC 800EEA1C 00000000 */   nop      
.L800EEA20:
/* 87ED0 800EEA20 1062008C */  beq       $v1, $v0, .L800EEC54
/* 87ED4 800EEA24 0200202D */   daddu    $a0, $s0, $zero
/* 87ED8 800EEA28 0803BB25 */  j         .L800EEC94
/* 87EDC 800EEA2C 0000102D */   daddu    $v0, $zero, $zero
.L800EEA30:
/* 87EE0 800EEA30 2403FDFF */  addiu     $v1, $zero, -0x201
/* 87EE4 800EEA34 8E020000 */  lw        $v0, ($s0)
/* 87EE8 800EEA38 C61A0038 */  lwc1      $f26, 0x38($s0)
/* 87EEC 800EEA3C C614003C */  lwc1      $f20, 0x3c($s0)
/* 87EF0 800EEA40 C6160040 */  lwc1      $f22, 0x40($s0)
/* 87EF4 800EEA44 3C013FCC */  lui       $at, 0x3fcc
/* 87EF8 800EEA48 3421CCCD */  ori       $at, $at, 0xcccd
/* 87EFC 800EEA4C 44811000 */  mtc1      $at, $f2
/* 87F00 800EEA50 00431024 */  and       $v0, $v0, $v1
/* 87F04 800EEA54 2403FFF7 */  addiu     $v1, $zero, -9
/* 87F08 800EEA58 00431024 */  and       $v0, $v0, $v1
/* 87F0C 800EEA5C AE020000 */  sw        $v0, ($s0)
/* 87F10 800EEA60 C49C0028 */  lwc1      $f28, 0x28($a0)
/* 87F14 800EEA64 E61C0060 */  swc1      $f28, 0x60($s0)
/* 87F18 800EEA68 948200B0 */  lhu       $v0, 0xb0($a0)
/* 87F1C 800EEA6C C49E002C */  lwc1      $f30, 0x2c($a0)
/* 87F20 800EEA70 00021400 */  sll       $v0, $v0, 0x10
/* 87F24 800EEA74 00021C03 */  sra       $v1, $v0, 0x10
/* 87F28 800EEA78 000217C2 */  srl       $v0, $v0, 0x1f
/* 87F2C 800EEA7C 00621821 */  addu      $v1, $v1, $v0
/* 87F30 800EEA80 00031843 */  sra       $v1, $v1, 1
/* 87F34 800EEA84 44830000 */  mtc1      $v1, $f0
/* 87F38 800EEA88 00000000 */  nop       
/* 87F3C 800EEA8C 46800020 */  cvt.s.w   $f0, $f0
/* 87F40 800EEA90 4600F780 */  add.s     $f30, $f30, $f0
/* 87F44 800EEA94 4406E000 */  mfc1      $a2, $f28
/* 87F48 800EEA98 4600D306 */  mov.s     $f12, $f26
/* 87F4C 800EEA9C E61E0064 */  swc1      $f30, 0x64($s0)
/* 87F50 800EEAA0 C4980030 */  lwc1      $f24, 0x30($a0)
/* 87F54 800EEAA4 3C014080 */  lui       $at, 0x4080
/* 87F58 800EEAA8 44810000 */  mtc1      $at, $f0
/* 87F5C 800EEAAC 4407C000 */  mfc1      $a3, $f24
/* 87F60 800EEAB0 4600B386 */  mov.s     $f14, $f22
/* 87F64 800EEAB4 3C018010 */  lui       $at, 0x8010
/* 87F68 800EEAB8 E43A833C */  swc1      $f26, -0x7cc4($at)
/* 87F6C 800EEABC 3C018010 */  lui       $at, 0x8010
/* 87F70 800EEAC0 E4348340 */  swc1      $f20, -0x7cc0($at)
/* 87F74 800EEAC4 3C018010 */  lui       $at, 0x8010
/* 87F78 800EEAC8 E4368344 */  swc1      $f22, -0x7cbc($at)
/* 87F7C 800EEACC E6000018 */  swc1      $f0, 0x18($s0)
/* 87F80 800EEAD0 E6020014 */  swc1      $f2, 0x14($s0)
/* 87F84 800EEAD4 0C00A7B5 */  jal       dist2D
/* 87F88 800EEAD8 E6180068 */   swc1     $f24, 0x68($s0)
/* 87F8C 800EEADC 4600D306 */  mov.s     $f12, $f26
/* 87F90 800EEAE0 4406E000 */  mfc1      $a2, $f28
/* 87F94 800EEAE4 4407C000 */  mfc1      $a3, $f24
/* 87F98 800EEAE8 4600B386 */  mov.s     $f14, $f22
/* 87F9C 800EEAEC 0C00A720 */  jal       atan2
/* 87FA0 800EEAF0 E6000010 */   swc1     $f0, 0x10($s0)
/* 87FA4 800EEAF4 2402000F */  addiu     $v0, $zero, 0xf
/* 87FA8 800EEAF8 A602008E */  sh        $v0, 0x8e($s0)
/* 87FAC 800EEAFC 8602008E */  lh        $v0, 0x8e($s0)
/* 87FB0 800EEB00 C6020014 */  lwc1      $f2, 0x14($s0)
/* 87FB4 800EEB04 44823000 */  mtc1      $v0, $f6
/* 87FB8 800EEB08 00000000 */  nop       
/* 87FBC 800EEB0C 468031A0 */  cvt.s.w   $f6, $f6
/* 87FC0 800EEB10 46061082 */  mul.s     $f2, $f2, $f6
/* 87FC4 800EEB14 00000000 */  nop       
/* 87FC8 800EEB18 4614F501 */  sub.s     $f20, $f30, $f20
/* 87FCC 800EEB1C 3C013F00 */  lui       $at, 0x3f00
/* 87FD0 800EEB20 44812000 */  mtc1      $at, $f4
/* 87FD4 800EEB24 46061082 */  mul.s     $f2, $f2, $f6
/* 87FD8 800EEB28 00000000 */  nop       
/* 87FDC 800EEB2C 3C014170 */  lui       $at, 0x4170
/* 87FE0 800EEB30 44814000 */  mtc1      $at, $f8
/* 87FE4 800EEB34 3C038011 */  lui       $v1, 0x8011
/* 87FE8 800EEB38 8C63CFD8 */  lw        $v1, -0x3028($v1)
/* 87FEC 800EEB3C E600000C */  swc1      $f0, 0xc($s0)
/* 87FF0 800EEB40 46041082 */  mul.s     $f2, $f2, $f4
/* 87FF4 800EEB44 00000000 */  nop       
/* 87FF8 800EEB48 000310C0 */  sll       $v0, $v1, 3
/* 87FFC 800EEB4C 00431021 */  addu      $v0, $v0, $v1
/* 88000 800EEB50 00021080 */  sll       $v0, $v0, 2
/* 88004 800EEB54 C6040010 */  lwc1      $f4, 0x10($s0)
/* 88008 800EEB58 4602A500 */  add.s     $f20, $f20, $f2
/* 8800C 800EEB5C 46082103 */  div.s     $f4, $f4, $f8
/* 88010 800EEB60 E6040018 */  swc1      $f4, 0x18($s0)
/* 88014 800EEB64 4606A503 */  div.s     $f20, $f20, $f6
/* 88018 800EEB68 E614001C */  swc1      $f20, 0x1c($s0)
/* 8801C 800EEB6C 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x8)
/* 88020 800EEB70 00220821 */  addu      $at, $at, $v0
/* 88024 800EEB74 8C228350 */  lw        $v0, %lo(gPartnerAnimations+0x8)($at)
/* 88028 800EEB78 0200202D */  daddu     $a0, $s0, $zero
/* 8802C 800EEB7C 0C00EB49 */  jal       enable_npc_blur
/* 88030 800EEB80 AC820028 */   sw       $v0, 0x28($a0)
/* 88034 800EEB84 0803BB24 */  j         .L800EEC90
/* 88038 800EEB88 A6320000 */   sh       $s2, ($s1)
.L800EEB8C:
/* 8803C 800EEB8C C600001C */  lwc1      $f0, 0x1c($s0)
/* 88040 800EEB90 C6020014 */  lwc1      $f2, 0x14($s0)
/* 88044 800EEB94 46020001 */  sub.s     $f0, $f0, $f2
/* 88048 800EEB98 C602003C */  lwc1      $f2, 0x3c($s0)
/* 8804C 800EEB9C E600001C */  swc1      $f0, 0x1c($s0)
/* 88050 800EEBA0 46000106 */  mov.s     $f4, $f0
/* 88054 800EEBA4 46001080 */  add.s     $f2, $f2, $f0
/* 88058 800EEBA8 44800000 */  mtc1      $zero, $f0
/* 8805C 800EEBAC 00000000 */  nop       
/* 88060 800EEBB0 4600203E */  c.le.s    $f4, $f0
/* 88064 800EEBB4 00000000 */  nop       
/* 88068 800EEBB8 4500000A */  bc1f      .L800EEBE4
/* 8806C 800EEBBC E602003C */   swc1     $f2, 0x3c($s0)
/* 88070 800EEBC0 3C028011 */  lui       $v0, 0x8011
/* 88074 800EEBC4 8C42CFD8 */  lw        $v0, -0x3028($v0)
/* 88078 800EEBC8 000218C0 */  sll       $v1, $v0, 3
/* 8807C 800EEBCC 00621821 */  addu      $v1, $v1, $v0
/* 88080 800EEBD0 00031880 */  sll       $v1, $v1, 2
/* 88084 800EEBD4 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0xC)
/* 88088 800EEBD8 00431021 */  addu      $v0, $v0, $v1
/* 8808C 800EEBDC 8C428354 */  lw        $v0, %lo(gPartnerAnimations+0xC)($v0)
/* 88090 800EEBE0 AE020028 */  sw        $v0, 0x28($s0)
.L800EEBE4:
/* 88094 800EEBE4 8E06000C */  lw        $a2, 0xc($s0)
/* 88098 800EEBE8 8E050018 */  lw        $a1, 0x18($s0)
/* 8809C 800EEBEC 0C00EA95 */  jal       npc_move_heading
/* 880A0 800EEBF0 0200202D */   daddu    $a0, $s0, $zero
/* 880A4 800EEBF4 8602008E */  lh        $v0, 0x8e($s0)
/* 880A8 800EEBF8 3C014120 */  lui       $at, 0x4120
/* 880AC 800EEBFC 44811000 */  mtc1      $at, $f2
/* 880B0 800EEC00 44820000 */  mtc1      $v0, $f0
/* 880B4 800EEC04 00000000 */  nop       
/* 880B8 800EEC08 46800020 */  cvt.s.w   $f0, $f0
/* 880BC 800EEC0C 4600103C */  c.lt.s    $f2, $f0
/* 880C0 800EEC10 00000000 */  nop       
/* 880C4 800EEC14 45030001 */  bc1tl     .L800EEC1C
/* 880C8 800EEC18 46001006 */   mov.s    $f0, $f2
.L800EEC1C:
/* 880CC 800EEC1C 9602008E */  lhu       $v0, 0x8e($s0)
/* 880D0 800EEC20 46020003 */  div.s     $f0, $f0, $f2
/* 880D4 800EEC24 E6000054 */  swc1      $f0, 0x54($s0)
/* 880D8 800EEC28 46000086 */  mov.s     $f2, $f0
/* 880DC 800EEC2C E6000058 */  swc1      $f0, 0x58($s0)
/* 880E0 800EEC30 E602005C */  swc1      $f2, 0x5c($s0)
/* 880E4 800EEC34 2442FFFF */  addiu     $v0, $v0, -1
/* 880E8 800EEC38 A602008E */  sh        $v0, 0x8e($s0)
/* 880EC 800EEC3C 00021400 */  sll       $v0, $v0, 0x10
/* 880F0 800EEC40 04410014 */  bgez      $v0, .L800EEC94
/* 880F4 800EEC44 0000102D */   daddu    $v0, $zero, $zero
/* 880F8 800EEC48 24020002 */  addiu     $v0, $zero, 2
/* 880FC 800EEC4C 0803BB24 */  j         .L800EEC90
/* 88100 800EEC50 A6220000 */   sh       $v0, ($s1)
.L800EEC54:
/* 88104 800EEC54 3C038011 */  lui       $v1, 0x8011
/* 88108 800EEC58 8C63CFD8 */  lw        $v1, -0x3028($v1)
/* 8810C 800EEC5C C6000064 */  lwc1      $f0, 0x64($s0)
/* 88110 800EEC60 000310C0 */  sll       $v0, $v1, 3
/* 88114 800EEC64 00431021 */  addu      $v0, $v0, $v1
/* 88118 800EEC68 00021080 */  sll       $v0, $v0, 2
/* 8811C 800EEC6C 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x10)
/* 88120 800EEC70 00220821 */  addu      $at, $at, $v0
/* 88124 800EEC74 8C228358 */  lw        $v0, %lo(gPartnerAnimations+0x10)($at)
/* 88128 800EEC78 AC80001C */  sw        $zero, 0x1c($a0)
/* 8812C 800EEC7C E480003C */  swc1      $f0, 0x3c($a0)
/* 88130 800EEC80 0C00EB6B */  jal       disable_npc_blur
/* 88134 800EEC84 AC820028 */   sw       $v0, 0x28($a0)
/* 88138 800EEC88 0803BB25 */  j         .L800EEC94
/* 8813C 800EEC8C 24020001 */   addiu    $v0, $zero, 1
.L800EEC90:
/* 88140 800EEC90 0000102D */  daddu     $v0, $zero, $zero
.L800EEC94:
/* 88144 800EEC94 8FBF001C */  lw        $ra, 0x1c($sp)
/* 88148 800EEC98 8FB20018 */  lw        $s2, 0x18($sp)
/* 8814C 800EEC9C 8FB10014 */  lw        $s1, 0x14($sp)
/* 88150 800EECA0 8FB00010 */  lw        $s0, 0x10($sp)
/* 88154 800EECA4 D7BE0048 */  ldc1      $f30, 0x48($sp)
/* 88158 800EECA8 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* 8815C 800EECAC D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 88160 800EECB0 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 88164 800EECB4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 88168 800EECB8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8816C 800EECBC 03E00008 */  jr        $ra
/* 88170 800EECC0 27BD0050 */   addiu    $sp, $sp, 0x50
