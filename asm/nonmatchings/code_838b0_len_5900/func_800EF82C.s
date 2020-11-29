.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF82C
/* 88CDC 800EF82C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 88CE0 800EF830 AFB20038 */  sw        $s2, 0x38($sp)
/* 88CE4 800EF834 0080902D */  daddu     $s2, $a0, $zero
/* 88CE8 800EF838 AFB40040 */  sw        $s4, 0x40($sp)
/* 88CEC 800EF83C 00A0A02D */  daddu     $s4, $a1, $zero
/* 88CF0 800EF840 AFB3003C */  sw        $s3, 0x3c($sp)
/* 88CF4 800EF844 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* 88CF8 800EF848 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* 88CFC 800EF84C 3C058011 */  lui       $a1, %hi(D_8010CFCE)
/* 88D00 800EF850 24A5CFCE */  addiu     $a1, $a1, %lo(D_8010CFCE)
/* 88D04 800EF854 24020001 */  addiu     $v0, $zero, 1
/* 88D08 800EF858 AFBF0044 */  sw        $ra, 0x44($sp)
/* 88D0C 800EF85C AFB10034 */  sw        $s1, 0x34($sp)
/* 88D10 800EF860 AFB00030 */  sw        $s0, 0x30($sp)
/* 88D14 800EF864 84A30000 */  lh        $v1, ($a1)
/* 88D18 800EF868 94A40000 */  lhu       $a0, ($a1)
/* 88D1C 800EF86C 10620044 */  beq       $v1, $v0, .L800EF980
/* 88D20 800EF870 28620002 */   slti     $v0, $v1, 2
/* 88D24 800EF874 10400118 */  beqz      $v0, .L800EFCD8
/* 88D28 800EF878 00000000 */   nop      
/* 88D2C 800EF87C 14600116 */  bnez      $v1, .L800EFCD8
/* 88D30 800EF880 24820001 */   addiu    $v0, $a0, 1
/* 88D34 800EF884 C662002C */  lwc1      $f2, 0x2c($s3)
/* 88D38 800EF888 3C018010 */  lui       $at, %hi(D_800F8024)
/* 88D3C 800EF88C C4208024 */  lwc1      $f0, %lo(D_800F8024)($at)
/* 88D40 800EF890 46800020 */  cvt.s.w   $f0, $f0
/* 88D44 800EF894 E6400060 */  swc1      $f0, 0x60($s2)
/* 88D48 800EF898 44060000 */  mfc1      $a2, $f0
/* 88D4C 800EF89C 3C018010 */  lui       $at, %hi(D_800F8028)
/* 88D50 800EF8A0 C4208028 */  lwc1      $f0, %lo(D_800F8028)($at)
/* 88D54 800EF8A4 46800020 */  cvt.s.w   $f0, $f0
/* 88D58 800EF8A8 26500060 */  addiu     $s0, $s2, 0x60
/* 88D5C 800EF8AC C64C0038 */  lwc1      $f12, 0x38($s2)
/* 88D60 800EF8B0 C64E0040 */  lwc1      $f14, 0x40($s2)
/* 88D64 800EF8B4 44070000 */  mfc1      $a3, $f0
/* 88D68 800EF8B8 26510068 */  addiu     $s1, $s2, 0x68
/* 88D6C 800EF8BC A4A20000 */  sh        $v0, ($a1)
/* 88D70 800EF8C0 AE470068 */  sw        $a3, 0x68($s2)
/* 88D74 800EF8C4 0C00A720 */  jal       atan2
/* 88D78 800EF8C8 E6420064 */   swc1     $f2, 0x64($s2)
/* 88D7C 800EF8CC 0200202D */  daddu     $a0, $s0, $zero
/* 88D80 800EF8D0 3C0640A0 */  lui       $a2, 0x40a0
/* 88D84 800EF8D4 44070000 */  mfc1      $a3, $f0
/* 88D88 800EF8D8 0220282D */  daddu     $a1, $s1, $zero
/* 88D8C 800EF8DC 3C018010 */  lui       $at, %hi(D_800F8034)
/* 88D90 800EF8E0 AC278034 */  sw        $a3, %lo(D_800F8034)($at)
/* 88D94 800EF8E4 0C00A7E7 */  jal       add_vec2D_polar
/* 88D98 800EF8E8 AE47000C */   sw       $a3, 0xc($s2)
/* 88D9C 800EF8EC 3C108010 */  lui       $s0, %hi(D_800F802C)
/* 88DA0 800EF8F0 2610802C */  addiu     $s0, $s0, %lo(D_800F802C)
/* 88DA4 800EF8F4 C64C0038 */  lwc1      $f12, 0x38($s2)
/* 88DA8 800EF8F8 C64E0040 */  lwc1      $f14, 0x40($s2)
/* 88DAC 800EF8FC 8E460060 */  lw        $a2, 0x60($s2)
/* 88DB0 800EF900 8E470068 */  lw        $a3, 0x68($s2)
/* 88DB4 800EF904 24020012 */  addiu     $v0, $zero, 0x12
/* 88DB8 800EF908 0C00A7B5 */  jal       dist2D
/* 88DBC 800EF90C AE020000 */   sw       $v0, ($s0)
/* 88DC0 800EF910 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 88DC4 800EF914 C6020000 */  lwc1      $f2, ($s0)
/* 88DC8 800EF918 468010A0 */  cvt.s.w   $f2, $f2
/* 88DCC 800EF91C 46020003 */  div.s     $f0, $f0, $f2
/* 88DD0 800EF920 3C018010 */  lui       $at, %hi(D_800F8030)
/* 88DD4 800EF924 E4208030 */  swc1      $f0, %lo(D_800F8030)($at)
/* 88DD8 800EF928 E6400018 */  swc1      $f0, 0x18($s2)
/* 88DDC 800EF92C 46000021 */  cvt.d.s   $f0, $f0
/* 88DE0 800EF930 26440028 */  addiu     $a0, $s2, 0x28
/* 88DE4 800EF934 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 88DE8 800EF938 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 88DEC 800EF93C 3C014010 */  lui       $at, 0x4010
/* 88DF0 800EF940 44811800 */  mtc1      $at, $f3
/* 88DF4 800EF944 44801000 */  mtc1      $zero, $f2
/* 88DF8 800EF948 000310C0 */  sll       $v0, $v1, 3
/* 88DFC 800EF94C 00431021 */  addu      $v0, $v0, $v1
/* 88E00 800EF950 4620103E */  c.le.d    $f2, $f0
/* 88E04 800EF954 00000000 */  nop       
/* 88E08 800EF958 45000003 */  bc1f      .L800EF968
/* 88E0C 800EF95C 00021080 */   sll      $v0, $v0, 2
/* 88E10 800EF960 0803BE5B */  j         .L800EF96C
/* 88E14 800EF964 24430018 */   addiu    $v1, $v0, 0x18
.L800EF968:
/* 88E18 800EF968 24430004 */  addiu     $v1, $v0, 4
.L800EF96C:
/* 88E1C 800EF96C 3C028010 */  lui       $v0, %hi(gPartnerAnimations)
/* 88E20 800EF970 24428348 */  addiu     $v0, $v0, %lo(gPartnerAnimations)
/* 88E24 800EF974 00431021 */  addu      $v0, $v0, $v1
/* 88E28 800EF978 8C420000 */  lw        $v0, ($v0)
/* 88E2C 800EF97C AC820000 */  sw        $v0, ($a0)
.L800EF980:
/* 88E30 800EF980 3C038010 */  lui       $v1, %hi(D_800F802C)
/* 88E34 800EF984 2463802C */  addiu     $v1, $v1, %lo(D_800F802C)
/* 88E38 800EF988 8C620000 */  lw        $v0, ($v1)
/* 88E3C 800EF98C 104000C0 */  beqz      $v0, .L800EFC90
/* 88E40 800EF990 2442FFFF */   addiu    $v0, $v0, -1
/* 88E44 800EF994 16800092 */  bnez      $s4, .L800EFBE0
/* 88E48 800EF998 AC620000 */   sw       $v0, ($v1)
/* 88E4C 800EF99C 8E420000 */  lw        $v0, ($s2)
/* 88E50 800EF9A0 30421000 */  andi      $v0, $v0, 0x1000
/* 88E54 800EF9A4 14400003 */  bnez      $v0, .L800EF9B4
/* 88E58 800EF9A8 00000000 */   nop      
/* 88E5C 800EF9AC C660002C */  lwc1      $f0, 0x2c($s3)
/* 88E60 800EF9B0 E640003C */  swc1      $f0, 0x3c($s2)
.L800EF9B4:
/* 88E64 800EF9B4 C642001C */  lwc1      $f2, 0x1c($s2)
/* 88E68 800EF9B8 44802000 */  mtc1      $zero, $f4
/* 88E6C 800EF9BC 00000000 */  nop       
/* 88E70 800EF9C0 46041032 */  c.eq.s    $f2, $f4
/* 88E74 800EF9C4 00000000 */  nop       
/* 88E78 800EF9C8 45010060 */  bc1t      .L800EFB4C
/* 88E7C 800EF9CC 00000000 */   nop      
/* 88E80 800EF9D0 C6400014 */  lwc1      $f0, 0x14($s2)
/* 88E84 800EF9D4 46001001 */  sub.s     $f0, $f2, $f0
/* 88E88 800EF9D8 C642003C */  lwc1      $f2, 0x3c($s2)
/* 88E8C 800EF9DC 46001080 */  add.s     $f2, $f2, $f0
/* 88E90 800EF9E0 E640001C */  swc1      $f0, 0x1c($s2)
/* 88E94 800EF9E4 4604003E */  c.le.s    $f0, $f4
/* 88E98 800EF9E8 00000000 */  nop       
/* 88E9C 800EF9EC 4500000A */  bc1f      .L800EFA18
/* 88EA0 800EF9F0 E642003C */   swc1     $f2, 0x3c($s2)
/* 88EA4 800EF9F4 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 88EA8 800EF9F8 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 88EAC 800EF9FC 000218C0 */  sll       $v1, $v0, 3
/* 88EB0 800EFA00 00621821 */  addu      $v1, $v1, $v0
/* 88EB4 800EFA04 00031880 */  sll       $v1, $v1, 2
/* 88EB8 800EFA08 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0xC)
/* 88EBC 800EFA0C 00431021 */  addu      $v0, $v0, $v1
/* 88EC0 800EFA10 8C428354 */  lw        $v0, %lo(gPartnerAnimations+0xC)($v0)
/* 88EC4 800EFA14 AE420028 */  sw        $v0, 0x28($s2)
.L800EFA18:
/* 88EC8 800EFA18 C642001C */  lwc1      $f2, 0x1c($s2)
/* 88ECC 800EFA1C 4604103E */  c.le.s    $f2, $f4
/* 88ED0 800EFA20 00000000 */  nop       
/* 88ED4 800EFA24 45000049 */  bc1f      .L800EFB4C
/* 88ED8 800EFA28 27A50020 */   addiu    $a1, $sp, 0x20
/* 88EDC 800EFA2C C6400038 */  lwc1      $f0, 0x38($s2)
/* 88EE0 800EFA30 46001085 */  abs.s     $f2, $f2
/* 88EE4 800EFA34 E7A00020 */  swc1      $f0, 0x20($sp)
/* 88EE8 800EFA38 864200A8 */  lh        $v0, 0xa8($s2)
/* 88EEC 800EFA3C C6440040 */  lwc1      $f4, 0x40($s2)
/* 88EF0 800EFA40 0040182D */  daddu     $v1, $v0, $zero
/* 88EF4 800EFA44 44820000 */  mtc1      $v0, $f0
/* 88EF8 800EFA48 00000000 */  nop       
/* 88EFC 800EFA4C 46800020 */  cvt.s.w   $f0, $f0
/* 88F00 800EFA50 44833000 */  mtc1      $v1, $f6
/* 88F04 800EFA54 00000000 */  nop       
/* 88F08 800EFA58 468031A0 */  cvt.s.w   $f6, $f6
/* 88F0C 800EFA5C 46001080 */  add.s     $f2, $f2, $f0
/* 88F10 800EFA60 C640003C */  lwc1      $f0, 0x3c($s2)
/* 88F14 800EFA64 27A2002C */  addiu     $v0, $sp, 0x2c
/* 88F18 800EFA68 46060000 */  add.s     $f0, $f0, $f6
/* 88F1C 800EFA6C E7A40028 */  swc1      $f4, 0x28($sp)
/* 88F20 800EFA70 E7A2002C */  swc1      $f2, 0x2c($sp)
/* 88F24 800EFA74 E7A00024 */  swc1      $f0, 0x24($sp)
/* 88F28 800EFA78 AFA20010 */  sw        $v0, 0x10($sp)
/* 88F2C 800EFA7C C640000C */  lwc1      $f0, 0xc($s2)
/* 88F30 800EFA80 E7A00014 */  swc1      $f0, 0x14($sp)
/* 88F34 800EFA84 864200A6 */  lh        $v0, 0xa6($s2)
/* 88F38 800EFA88 27A60024 */  addiu     $a2, $sp, 0x24
/* 88F3C 800EFA8C 44820000 */  mtc1      $v0, $f0
/* 88F40 800EFA90 00000000 */  nop       
/* 88F44 800EFA94 46800020 */  cvt.s.w   $f0, $f0
/* 88F48 800EFA98 E7A00018 */  swc1      $f0, 0x18($sp)
/* 88F4C 800EFA9C 8E440080 */  lw        $a0, 0x80($s2)
/* 88F50 800EFAA0 0C0371DE */  jal       func_800DC778
/* 88F54 800EFAA4 27A70028 */   addiu    $a3, $sp, 0x28
/* 88F58 800EFAA8 10400028 */  beqz      $v0, .L800EFB4C
/* 88F5C 800EFAAC 00000000 */   nop      
/* 88F60 800EFAB0 C640001C */  lwc1      $f0, 0x1c($s2)
/* 88F64 800EFAB4 3C0141B0 */  lui       $at, 0x41b0
/* 88F68 800EFAB8 44811000 */  mtc1      $at, $f2
/* 88F6C 800EFABC 46000005 */  abs.s     $f0, $f0
/* 88F70 800EFAC0 46020000 */  add.s     $f0, $f0, $f2
/* 88F74 800EFAC4 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 88F78 800EFAC8 4600103E */  c.le.s    $f2, $f0
/* 88F7C 800EFACC 00000000 */  nop       
/* 88F80 800EFAD0 4500001E */  bc1f      .L800EFB4C
/* 88F84 800EFAD4 26440028 */   addiu    $a0, $s2, 0x28
/* 88F88 800EFAD8 C6400018 */  lwc1      $f0, 0x18($s2)
/* 88F8C 800EFADC 3C014010 */  lui       $at, 0x4010
/* 88F90 800EFAE0 44811800 */  mtc1      $at, $f3
/* 88F94 800EFAE4 44801000 */  mtc1      $zero, $f2
/* 88F98 800EFAE8 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 88F9C 800EFAEC 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 88FA0 800EFAF0 46000021 */  cvt.d.s   $f0, $f0
/* 88FA4 800EFAF4 000310C0 */  sll       $v0, $v1, 3
/* 88FA8 800EFAF8 00431021 */  addu      $v0, $v0, $v1
/* 88FAC 800EFAFC 4620103E */  c.le.d    $f2, $f0
/* 88FB0 800EFB00 00000000 */  nop       
/* 88FB4 800EFB04 45000003 */  bc1f      .L800EFB14
/* 88FB8 800EFB08 00021080 */   sll      $v0, $v0, 2
/* 88FBC 800EFB0C 0803BEC6 */  j         .L800EFB18
/* 88FC0 800EFB10 24430018 */   addiu    $v1, $v0, 0x18
.L800EFB14:
/* 88FC4 800EFB14 24430004 */  addiu     $v1, $v0, 4
.L800EFB18:
/* 88FC8 800EFB18 3C028010 */  lui       $v0, %hi(gPartnerAnimations)
/* 88FCC 800EFB1C 24428348 */  addiu     $v0, $v0, %lo(gPartnerAnimations)
/* 88FD0 800EFB20 00431021 */  addu      $v0, $v0, $v1
/* 88FD4 800EFB24 8C420000 */  lw        $v0, ($v0)
/* 88FD8 800EFB28 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 88FDC 800EFB2C AC820000 */  sw        $v0, ($a0)
/* 88FE0 800EFB30 8E420000 */  lw        $v0, ($s2)
/* 88FE4 800EFB34 2403F7FF */  addiu     $v1, $zero, -0x801
/* 88FE8 800EFB38 AE400014 */  sw        $zero, 0x14($s2)
/* 88FEC 800EFB3C AE40001C */  sw        $zero, 0x1c($s2)
/* 88FF0 800EFB40 E640003C */  swc1      $f0, 0x3c($s2)
/* 88FF4 800EFB44 00431024 */  and       $v0, $v0, $v1
/* 88FF8 800EFB48 AE420000 */  sw        $v0, ($s2)
.L800EFB4C:
/* 88FFC 800EFB4C 3C018010 */  lui       $at, %hi(D_800F8030)
/* 89000 800EFB50 C4208030 */  lwc1      $f0, %lo(D_800F8030)($at)
/* 89004 800EFB54 E6400018 */  swc1      $f0, 0x18($s2)
/* 89008 800EFB58 3C018010 */  lui       $at, %hi(D_800F8034)
/* 8900C 800EFB5C C4208034 */  lwc1      $f0, %lo(D_800F8034)($at)
/* 89010 800EFB60 8E450018 */  lw        $a1, 0x18($s2)
/* 89014 800EFB64 44060000 */  mfc1      $a2, $f0
/* 89018 800EFB68 0240202D */  daddu     $a0, $s2, $zero
/* 8901C 800EFB6C 0C00EA95 */  jal       npc_move_heading
/* 89020 800EFB70 AE46000C */   sw       $a2, 0xc($s2)
/* 89024 800EFB74 26450028 */  addiu     $a1, $s2, 0x28
/* 89028 800EFB78 C6400018 */  lwc1      $f0, 0x18($s2)
/* 8902C 800EFB7C 3C014010 */  lui       $at, 0x4010
/* 89030 800EFB80 44811800 */  mtc1      $at, $f3
/* 89034 800EFB84 44801000 */  mtc1      $zero, $f2
/* 89038 800EFB88 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 8903C 800EFB8C 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 89040 800EFB90 46000021 */  cvt.d.s   $f0, $f0
/* 89044 800EFB94 000310C0 */  sll       $v0, $v1, 3
/* 89048 800EFB98 00431021 */  addu      $v0, $v0, $v1
/* 8904C 800EFB9C 00021080 */  sll       $v0, $v0, 2
/* 89050 800EFBA0 4620103E */  c.le.d    $f2, $f0
/* 89054 800EFBA4 00000000 */  nop       
/* 89058 800EFBA8 45000003 */  bc1f      .L800EFBB8
/* 8905C 800EFBAC 0040182D */   daddu    $v1, $v0, $zero
/* 89060 800EFBB0 0803BEEF */  j         .L800EFBBC
/* 89064 800EFBB4 24430018 */   addiu    $v1, $v0, 0x18
.L800EFBB8:
/* 89068 800EFBB8 24630004 */  addiu     $v1, $v1, 4
.L800EFBBC:
/* 8906C 800EFBBC 3C028010 */  lui       $v0, %hi(gPartnerAnimations)
/* 89070 800EFBC0 24428348 */  addiu     $v0, $v0, %lo(gPartnerAnimations)
/* 89074 800EFBC4 00431021 */  addu      $v0, $v0, $v1
/* 89078 800EFBC8 8C420000 */  lw        $v0, ($v0)
/* 8907C 800EFBCC 0240202D */  daddu     $a0, $s2, $zero
/* 89080 800EFBD0 0C00E2BF */  jal       npc_do_world_collision
/* 89084 800EFBD4 ACA20000 */   sw       $v0, ($a1)
/* 89088 800EFBD8 0803BF17 */  j         .L800EFC5C
/* 8908C 800EFBDC 24050001 */   addiu    $a1, $zero, 1
.L800EFBE0:
/* 89090 800EFBE0 C644003C */  lwc1      $f4, 0x3c($s2)
/* 89094 800EFBE4 C666002C */  lwc1      $f6, 0x2c($s3)
/* 89098 800EFBE8 46062001 */  sub.s     $f0, $f4, $f6
/* 8909C 800EFBEC 3C014014 */  lui       $at, 0x4014
/* 890A0 800EFBF0 44811800 */  mtc1      $at, $f3
/* 890A4 800EFBF4 44801000 */  mtc1      $zero, $f2
/* 890A8 800EFBF8 46000021 */  cvt.d.s   $f0, $f0
/* 890AC 800EFBFC 46200005 */  abs.d     $f0, $f0
/* 890B0 800EFC00 4620103C */  c.lt.d    $f2, $f0
/* 890B4 800EFC04 00000000 */  nop       
/* 890B8 800EFC08 45000009 */  bc1f      .L800EFC30
/* 890BC 800EFC0C 00000000 */   nop      
/* 890C0 800EFC10 46043001 */  sub.s     $f0, $f6, $f4
/* 890C4 800EFC14 3C013F00 */  lui       $at, 0x3f00
/* 890C8 800EFC18 44811000 */  mtc1      $at, $f2
/* 890CC 800EFC1C 00000000 */  nop       
/* 890D0 800EFC20 46020002 */  mul.s     $f0, $f0, $f2
/* 890D4 800EFC24 00000000 */  nop       
/* 890D8 800EFC28 46002000 */  add.s     $f0, $f4, $f0
/* 890DC 800EFC2C E640003C */  swc1      $f0, 0x3c($s2)
.L800EFC30:
/* 890E0 800EFC30 3C018010 */  lui       $at, %hi(D_800F8030)
/* 890E4 800EFC34 C4208030 */  lwc1      $f0, %lo(D_800F8030)($at)
/* 890E8 800EFC38 E6400018 */  swc1      $f0, 0x18($s2)
/* 890EC 800EFC3C 3C018010 */  lui       $at, %hi(D_800F8034)
/* 890F0 800EFC40 C4208034 */  lwc1      $f0, %lo(D_800F8034)($at)
/* 890F4 800EFC44 8E450018 */  lw        $a1, 0x18($s2)
/* 890F8 800EFC48 44060000 */  mfc1      $a2, $f0
/* 890FC 800EFC4C 0240202D */  daddu     $a0, $s2, $zero
/* 89100 800EFC50 0C00EA95 */  jal       npc_move_heading
/* 89104 800EFC54 AE46000C */   sw       $a2, 0xc($s2)
/* 89108 800EFC58 24050001 */  addiu     $a1, $zero, 1
.L800EFC5C:
/* 8910C 800EFC5C C6400018 */  lwc1      $f0, 0x18($s2)
/* 89110 800EFC60 3C014010 */  lui       $at, 0x4010
/* 89114 800EFC64 44811800 */  mtc1      $at, $f3
/* 89118 800EFC68 44801000 */  mtc1      $zero, $f2
/* 8911C 800EFC6C 46000021 */  cvt.d.s   $f0, $f0
/* 89120 800EFC70 4622003C */  c.lt.d    $f0, $f2
/* 89124 800EFC74 00000000 */  nop       
/* 89128 800EFC78 45030001 */  bc1tl     .L800EFC80
/* 8912C 800EFC7C 0000282D */   daddu    $a1, $zero, $zero
.L800EFC80:
/* 89130 800EFC80 0C00F598 */  jal       func_8003D660
/* 89134 800EFC84 0240202D */   daddu    $a0, $s2, $zero
/* 89138 800EFC88 0803BF36 */  j         .L800EFCD8
/* 8913C 800EFC8C 00000000 */   nop      
.L800EFC90:
/* 89140 800EFC90 2403FFBF */  addiu     $v1, $zero, -0x41
/* 89144 800EFC94 8E420000 */  lw        $v0, ($s2)
/* 89148 800EFC98 3C048011 */  lui       $a0, %hi(D_8010CFD8)
/* 8914C 800EFC9C 8C84CFD8 */  lw        $a0, %lo(D_8010CFD8)($a0)
/* 89150 800EFCA0 00431024 */  and       $v0, $v0, $v1
/* 89154 800EFCA4 000418C0 */  sll       $v1, $a0, 3
/* 89158 800EFCA8 00641821 */  addu      $v1, $v1, $a0
/* 8915C 800EFCAC 00031880 */  sll       $v1, $v1, 2
/* 89160 800EFCB0 3C048011 */  lui       $a0, %hi(D_8010CFCE)
/* 89164 800EFCB4 2484CFCE */  addiu     $a0, $a0, %lo(D_8010CFCE)
/* 89168 800EFCB8 AE420000 */  sw        $v0, ($s2)
/* 8916C 800EFCBC 94820000 */  lhu       $v0, ($a0)
/* 89170 800EFCC0 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 89174 800EFCC4 00230821 */  addu      $at, $at, $v1
/* 89178 800EFCC8 8C23835C */  lw        $v1, %lo(gPartnerAnimations+0x14)($at)
/* 8917C 800EFCCC 24420001 */  addiu     $v0, $v0, 1
/* 89180 800EFCD0 A4820000 */  sh        $v0, ($a0)
/* 89184 800EFCD4 AE430028 */  sw        $v1, 0x28($s2)
.L800EFCD8:
/* 89188 800EFCD8 8FBF0044 */  lw        $ra, 0x44($sp)
/* 8918C 800EFCDC 8FB40040 */  lw        $s4, 0x40($sp)
/* 89190 800EFCE0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 89194 800EFCE4 8FB20038 */  lw        $s2, 0x38($sp)
/* 89198 800EFCE8 8FB10034 */  lw        $s1, 0x34($sp)
/* 8919C 800EFCEC 8FB00030 */  lw        $s0, 0x30($sp)
/* 891A0 800EFCF0 03E00008 */  jr        $ra
/* 891A4 800EFCF4 27BD0048 */   addiu    $sp, $sp, 0x48
/* 891A8 800EFCF8 00000000 */  nop       
/* 891AC 800EFCFC 00000000 */  nop       
