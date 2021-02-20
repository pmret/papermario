.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800ED9F8
/* 86EA8 800ED9F8 3C038011 */  lui       $v1, %hi(D_8010CFC8)
/* 86EAC 800ED9FC 8463CFC8 */  lh        $v1, %lo(D_8010CFC8)($v1)
/* 86EB0 800EDA00 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 86EB4 800EDA04 AFB10034 */  sw        $s1, 0x34($sp)
/* 86EB8 800EDA08 AFB3003C */  sw        $s3, 0x3c($sp)
/* 86EBC 800EDA0C 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* 86EC0 800EDA10 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* 86EC4 800EDA14 AFB20038 */  sw        $s2, 0x38($sp)
/* 86EC8 800EDA18 3C12800B */  lui       $s2, %hi(gCameras)
/* 86ECC 800EDA1C 26521D80 */  addiu     $s2, $s2, %lo(gCameras)
/* 86ED0 800EDA20 AFBF0044 */  sw        $ra, 0x44($sp)
/* 86ED4 800EDA24 AFB40040 */  sw        $s4, 0x40($sp)
/* 86ED8 800EDA28 AFB00030 */  sw        $s0, 0x30($sp)
/* 86EDC 800EDA2C F7B80058 */  sdc1      $f24, 0x58($sp)
/* 86EE0 800EDA30 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 86EE4 800EDA34 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 86EE8 800EDA38 2C620033 */  sltiu     $v0, $v1, 0x33
/* 86EEC 800EDA3C 104003CA */  beqz      $v0, .L800EE968
/* 86EF0 800EDA40 0080882D */   daddu    $s1, $a0, $zero
/* 86EF4 800EDA44 00031080 */  sll       $v0, $v1, 2
/* 86EF8 800EDA48 3C018011 */  lui       $at, %hi(jtbl_8010C218)
/* 86EFC 800EDA4C 00220821 */  addu      $at, $at, $v0
/* 86F00 800EDA50 8C22C218 */  lw        $v0, %lo(jtbl_8010C218)($at)
/* 86F04 800EDA54 00400008 */  jr        $v0
/* 86F08 800EDA58 00000000 */   nop
glabel L800EDA5C_86F0C
/* 86F0C 800EDA5C 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 86F10 800EDA60 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 86F14 800EDA64 44806000 */  mtc1      $zero, $f12
/* 86F18 800EDA68 3C028011 */  lui       $v0, %hi(D_8010CFBC)
/* 86F1C 800EDA6C 8C42CFBC */  lw        $v0, %lo(D_8010CFBC)($v0)
/* 86F20 800EDA70 C6220038 */  lwc1      $f2, 0x38($s1)
/* 86F24 800EDA74 C624003C */  lwc1      $f4, 0x3c($s1)
/* 86F28 800EDA78 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 86F2C 800EDA7C C42ACFC0 */  lwc1      $f10, %lo(D_8010CFC0)($at)
/* 86F30 800EDA80 3C0141A0 */  lui       $at, 0x41a0
/* 86F34 800EDA84 44814000 */  mtc1      $at, $f8
/* 86F38 800EDA88 C6200040 */  lwc1      $f0, 0x40($s1)
/* 86F3C 800EDA8C 00021100 */  sll       $v0, $v0, 4
/* 86F40 800EDA90 00438021 */  addu      $s0, $v0, $v1
/* 86F44 800EDA94 C6160004 */  lwc1      $f22, 4($s0)
/* 86F48 800EDA98 C6060008 */  lwc1      $f6, 8($s0)
/* 86F4C 800EDA9C C614000C */  lwc1      $f20, 0xc($s0)
/* 86F50 800EDAA0 4608503C */  c.lt.s    $f10, $f8
/* 86F54 800EDAA4 E7A20020 */  swc1      $f2, 0x20($sp)
/* 86F58 800EDAA8 E7A40024 */  swc1      $f4, 0x24($sp)
/* 86F5C 800EDAAC E7A00028 */  swc1      $f0, 0x28($sp)
/* 86F60 800EDAB0 3C018010 */  lui       $at, %hi(D_800F833C)
/* 86F64 800EDAB4 E422833C */  swc1      $f2, %lo(D_800F833C)($at)
/* 86F68 800EDAB8 3C018010 */  lui       $at, %hi(D_800F8340)
/* 86F6C 800EDABC E4248340 */  swc1      $f4, %lo(D_800F8340)($at)
/* 86F70 800EDAC0 3C018010 */  lui       $at, %hi(D_800F8344)
/* 86F74 800EDAC4 E4208344 */  swc1      $f0, %lo(D_800F8344)($at)
/* 86F78 800EDAC8 45020008 */  bc1fl     .L800EDAEC
/* 86F7C 800EDACC 46083000 */   add.s    $f0, $f6, $f8
/* 86F80 800EDAD0 460A4081 */  sub.s     $f2, $f8, $f10
/* 86F84 800EDAD4 3C013F00 */  lui       $at, 0x3f00
/* 86F88 800EDAD8 44810000 */  mtc1      $at, $f0
/* 86F8C 800EDADC 00000000 */  nop
/* 86F90 800EDAE0 46001302 */  mul.s     $f12, $f2, $f0
/* 86F94 800EDAE4 00000000 */  nop
/* 86F98 800EDAE8 46083000 */  add.s     $f0, $f6, $f8
.L800EDAEC:
/* 86F9C 800EDAEC 460C0000 */  add.s     $f0, $f0, $f12
/* 86FA0 800EDAF0 46040001 */  sub.s     $f0, $f0, $f4
/* 86FA4 800EDAF4 3C013E00 */  lui       $at, 0x3e00
/* 86FA8 800EDAF8 44811000 */  mtc1      $at, $f2
/* 86FAC 800EDAFC 00000000 */  nop
/* 86FB0 800EDB00 46020002 */  mul.s     $f0, $f0, $f2
/* 86FB4 800EDB04 00000000 */  nop
/* 86FB8 800EDB08 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 86FBC 800EDB0C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 86FC0 800EDB10 3C014040 */  lui       $at, 0x4040
/* 86FC4 800EDB14 44811000 */  mtc1      $at, $f2
/* 86FC8 800EDB18 46002000 */  add.s     $f0, $f4, $f0
/* 86FCC 800EDB1C E6220018 */  swc1      $f2, 0x18($s1)
/* 86FD0 800EDB20 E620003C */  swc1      $f0, 0x3c($s1)
/* 86FD4 800EDB24 8E660028 */  lw        $a2, 0x28($s3)
/* 86FD8 800EDB28 8E670030 */  lw        $a3, 0x30($s3)
/* 86FDC 800EDB2C 0C00A7B5 */  jal       dist2D
/* 86FE0 800EDB30 E7A00024 */   swc1     $f0, 0x24($sp)
/* 86FE4 800EDB34 3C014049 */  lui       $at, 0x4049
/* 86FE8 800EDB38 44811800 */  mtc1      $at, $f3
/* 86FEC 800EDB3C 44801000 */  mtc1      $zero, $f2
/* 86FF0 800EDB40 46000106 */  mov.s     $f4, $f0
/* 86FF4 800EDB44 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 86FF8 800EDB48 46002021 */  cvt.d.s   $f0, $f4
/* 86FFC 800EDB4C 4620103E */  c.le.d    $f2, $f0
/* 87000 800EDB50 00000000 */  nop
/* 87004 800EDB54 45000033 */  bc1f      .L800EDC24
/* 87008 800EDB58 00000000 */   nop
/* 8700C 800EDB5C C622003C */  lwc1      $f2, 0x3c($s1)
/* 87010 800EDB60 C660002C */  lwc1      $f0, 0x2c($s3)
/* 87014 800EDB64 4602003E */  c.le.s    $f0, $f2
/* 87018 800EDB68 00000000 */  nop
/* 8701C 800EDB6C 45000029 */  bc1f      .L800EDC14
/* 87020 800EDB70 00000000 */   nop
/* 87024 800EDB74 3C013E80 */  lui       $at, 0x3e80
/* 87028 800EDB78 44810000 */  mtc1      $at, $f0
/* 8702C 800EDB7C 00000000 */  nop
/* 87030 800EDB80 46002002 */  mul.s     $f0, $f4, $f0
/* 87034 800EDB84 00000000 */  nop
/* 87038 800EDB88 0803B709 */  j         .L800EDC24
/* 8703C 800EDB8C E6200018 */   swc1     $f0, 0x18($s1)
.L800EDB90:
/* 87040 800EDB90 3C0140C0 */  lui       $at, 0x40c0
/* 87044 800EDB94 44810000 */  mtc1      $at, $f0
.L800EDB98:
/* 87048 800EDB98 0803B76E */  j         .L800EDDB8
/* 8704C 800EDB9C E6200018 */   swc1     $f0, 0x18($s1)
.L800EDBA0:
/* 87050 800EDBA0 C634000C */  lwc1      $f20, 0xc($s1)
/* 87054 800EDBA4 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 87058 800EDBA8 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 8705C 800EDBAC AE200018 */  sw        $zero, 0x18($s1)
/* 87060 800EDBB0 AE200014 */  sw        $zero, 0x14($s1)
/* 87064 800EDBB4 000218C0 */  sll       $v1, $v0, 3
/* 87068 800EDBB8 00621821 */  addu      $v1, $v1, $v0
/* 8706C 800EDBBC 00031880 */  sll       $v1, $v1, 2
/* 87070 800EDBC0 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0x14)
/* 87074 800EDBC4 00431021 */  addu      $v0, $v0, $v1
/* 87078 800EDBC8 8C42835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($v0)
/* 8707C 800EDBCC 0803B76E */  j         .L800EDDB8
/* 87080 800EDBD0 AE220028 */   sw       $v0, 0x28($s1)
.L800EDBD4:
/* 87084 800EDBD4 C634000C */  lwc1      $f20, 0xc($s1)
/* 87088 800EDBD8 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 8708C 800EDBDC 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 87090 800EDBE0 AE200018 */  sw        $zero, 0x18($s1)
/* 87094 800EDBE4 AE200014 */  sw        $zero, 0x14($s1)
/* 87098 800EDBE8 000310C0 */  sll       $v0, $v1, 3
/* 8709C 800EDBEC 00431021 */  addu      $v0, $v0, $v1
/* 870A0 800EDBF0 00021080 */  sll       $v0, $v0, 2
/* 870A4 800EDBF4 3C038010 */  lui       $v1, %hi(gPartnerAnimations+0x14)
/* 870A8 800EDBF8 00621821 */  addu      $v1, $v1, $v0
/* 870AC 800EDBFC 8C63835C */  lw        $v1, %lo(gPartnerAnimations+0x14)($v1)
/* 870B0 800EDC00 24020005 */  addiu     $v0, $zero, 5
/* 870B4 800EDC04 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 870B8 800EDC08 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 870BC 800EDC0C 0803B76E */  j         .L800EDDB8
/* 870C0 800EDC10 AE230028 */   sw       $v1, 0x28($s1)
.L800EDC14:
/* 870C4 800EDC14 3C014100 */  lui       $at, 0x4100
/* 870C8 800EDC18 44810000 */  mtc1      $at, $f0
/* 870CC 800EDC1C 00000000 */  nop
/* 870D0 800EDC20 E6200018 */  swc1      $f0, 0x18($s1)
.L800EDC24:
/* 870D4 800EDC24 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 870D8 800EDC28 C422CFC0 */  lwc1      $f2, %lo(D_8010CFC0)($at)
/* 870DC 800EDC2C 3C0141A0 */  lui       $at, 0x41a0
/* 870E0 800EDC30 44810000 */  mtc1      $at, $f0
/* 870E4 800EDC34 00000000 */  nop
/* 870E8 800EDC38 4600103C */  c.lt.s    $f2, $f0
/* 870EC 800EDC3C 00000000 */  nop
/* 870F0 800EDC40 45000005 */  bc1f      .L800EDC58
/* 870F4 800EDC44 00000000 */   nop
/* 870F8 800EDC48 3C014080 */  lui       $at, 0x4080
/* 870FC 800EDC4C 44810000 */  mtc1      $at, $f0
/* 87100 800EDC50 00000000 */  nop
/* 87104 800EDC54 E6200018 */  swc1      $f0, 0x18($s1)
.L800EDC58:
/* 87108 800EDC58 3C128011 */  lui       $s2, %hi(D_8010CFBC)
/* 8710C 800EDC5C 2652CFBC */  addiu     $s2, $s2, %lo(D_8010CFBC)
/* 87110 800EDC60 3C148011 */  lui       $s4, %hi(D_8010CD38)
/* 87114 800EDC64 2694CD38 */  addiu     $s4, $s4, %lo(D_8010CD38)
.L800EDC68:
/* 87118 800EDC68 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 8711C 800EDC6C C7AE0028 */  lwc1      $f14, 0x28($sp)
/* 87120 800EDC70 4406B000 */  mfc1      $a2, $f22
/* 87124 800EDC74 4407A000 */  mfc1      $a3, $f20
/* 87128 800EDC78 0C00A720 */  jal       atan2
/* 8712C 800EDC7C 00000000 */   nop
/* 87130 800EDC80 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 87134 800EDC84 C7AE0028 */  lwc1      $f14, 0x28($sp)
/* 87138 800EDC88 4406B000 */  mfc1      $a2, $f22
/* 8713C 800EDC8C 4407A000 */  mfc1      $a3, $f20
/* 87140 800EDC90 0C00A7B5 */  jal       dist2D
/* 87144 800EDC94 46000506 */   mov.s    $f20, $f0
/* 87148 800EDC98 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 8714C 800EDC9C C6260018 */  lwc1      $f6, 0x18($s1)
/* 87150 800EDCA0 46000106 */  mov.s     $f4, $f0
/* 87154 800EDCA4 4604303C */  c.lt.s    $f6, $f4
/* 87158 800EDCA8 00000000 */  nop
/* 8715C 800EDCAC 45000026 */  bc1f      .L800EDD48
/* 87160 800EDCB0 00000000 */   nop
/* 87164 800EDCB4 C622003C */  lwc1      $f2, 0x3c($s1)
/* 87168 800EDCB8 C660002C */  lwc1      $f0, 0x2c($s3)
/* 8716C 800EDCBC 4602003E */  c.le.s    $f0, $f2
/* 87170 800EDCC0 00000000 */  nop
/* 87174 800EDCC4 45020011 */  bc1fl     .L800EDD0C
/* 87178 800EDCC8 460030A1 */   cvt.d.s  $f2, $f6
/* 8717C 800EDCCC 3C013E80 */  lui       $at, 0x3e80
/* 87180 800EDCD0 44810000 */  mtc1      $at, $f0
/* 87184 800EDCD4 00000000 */  nop
/* 87188 800EDCD8 46002002 */  mul.s     $f0, $f4, $f0
/* 8718C 800EDCDC 00000000 */  nop
/* 87190 800EDCE0 4606003E */  c.le.s    $f0, $f6
/* 87194 800EDCE4 00000000 */  nop
/* 87198 800EDCE8 45030033 */  bc1tl     .L800EDDB8
/* 8719C 800EDCEC E6200018 */   swc1     $f0, 0x18($s1)
/* 871A0 800EDCF0 3C013D80 */  lui       $at, 0x3d80
/* 871A4 800EDCF4 44810000 */  mtc1      $at, $f0
/* 871A8 800EDCF8 00000000 */  nop
/* 871AC 800EDCFC 46002002 */  mul.s     $f0, $f4, $f0
/* 871B0 800EDD00 00000000 */  nop
/* 871B4 800EDD04 0803B6E6 */  j         .L800EDB98
/* 871B8 800EDD08 46003000 */   add.s    $f0, $f6, $f0
.L800EDD0C:
/* 871BC 800EDD0C 3C014018 */  lui       $at, 0x4018
/* 871C0 800EDD10 44810800 */  mtc1      $at, $f1
/* 871C4 800EDD14 44800000 */  mtc1      $zero, $f0
/* 871C8 800EDD18 00000000 */  nop
/* 871CC 800EDD1C 4622003C */  c.lt.d    $f0, $f2
/* 871D0 800EDD20 00000000 */  nop
/* 871D4 800EDD24 4501FF9A */  bc1t      .L800EDB90
/* 871D8 800EDD28 00000000 */   nop
/* 871DC 800EDD2C 3C013FF0 */  lui       $at, 0x3ff0
/* 871E0 800EDD30 44810800 */  mtc1      $at, $f1
/* 871E4 800EDD34 44800000 */  mtc1      $zero, $f0
/* 871E8 800EDD38 00000000 */  nop
/* 871EC 800EDD3C 46201000 */  add.d     $f0, $f2, $f0
/* 871F0 800EDD40 0803B6E6 */  j         .L800EDB98
/* 871F4 800EDD44 46200020 */   cvt.s.d  $f0, $f0
.L800EDD48:
/* 871F8 800EDD48 8E430000 */  lw        $v1, ($s2)
/* 871FC 800EDD4C 3C028011 */  lui       $v0, %hi(D_8010CFB8)
/* 87200 800EDD50 8C42CFB8 */  lw        $v0, %lo(D_8010CFB8)($v0)
/* 87204 800EDD54 1062FF92 */  beq       $v1, $v0, .L800EDBA0
/* 87208 800EDD58 00000000 */   nop
/* 8720C 800EDD5C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87210 800EDD60 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 87214 800EDD64 8E660028 */  lw        $a2, 0x28($s3)
/* 87218 800EDD68 0C00A7B5 */  jal       dist2D
/* 8721C 800EDD6C 8E670030 */   lw       $a3, 0x30($s3)
/* 87220 800EDD70 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 87224 800EDD74 C422CFC0 */  lwc1      $f2, %lo(D_8010CFC0)($at)
/* 87228 800EDD78 4602003E */  c.le.s    $f0, $f2
/* 8722C 800EDD7C 00000000 */  nop
/* 87230 800EDD80 4501FF94 */  bc1t      .L800EDBD4
/* 87234 800EDD84 E7A0002C */   swc1     $f0, 0x2c($sp)
/* 87238 800EDD88 8E420000 */  lw        $v0, ($s2)
/* 8723C 800EDD8C 24420001 */  addiu     $v0, $v0, 1
/* 87240 800EDD90 AE420000 */  sw        $v0, ($s2)
/* 87244 800EDD94 28420028 */  slti      $v0, $v0, 0x28
/* 87248 800EDD98 50400001 */  beql      $v0, $zero, .L800EDDA0
/* 8724C 800EDD9C AE400000 */   sw       $zero, ($s2)
.L800EDDA0:
/* 87250 800EDDA0 8E420000 */  lw        $v0, ($s2)
/* 87254 800EDDA4 00021100 */  sll       $v0, $v0, 4
/* 87258 800EDDA8 00548021 */  addu      $s0, $v0, $s4
/* 8725C 800EDDAC C6160004 */  lwc1      $f22, 4($s0)
/* 87260 800EDDB0 0803B71A */  j         .L800EDC68
/* 87264 800EDDB4 C614000C */   lwc1     $f20, 0xc($s0)
.L800EDDB8:
/* 87268 800EDDB8 8E250018 */  lw        $a1, 0x18($s1)
/* 8726C 800EDDBC 4406A000 */  mfc1      $a2, $f20
/* 87270 800EDDC0 0220202D */  daddu     $a0, $s1, $zero
/* 87274 800EDDC4 0C00EA95 */  jal       npc_move_heading
/* 87278 800EDDC8 AE26000C */   sw       $a2, 0xc($s1)
/* 8727C 800EDDCC 8E220000 */  lw        $v0, ($s1)
/* 87280 800EDDD0 30424000 */  andi      $v0, $v0, 0x4000
/* 87284 800EDDD4 104002E4 */  beqz      $v0, .L800EE968
/* 87288 800EDDD8 24020001 */   addiu    $v0, $zero, 1
/* 8728C 800EDDDC 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 87290 800EDDE0 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 87294 800EDDE4 0803BA5A */  j         .L800EE968
/* 87298 800EDDE8 00000000 */   nop
glabel L800EDDEC_8729C
/* 8729C 800EDDEC 3C048011 */  lui       $a0, %hi(D_8010CFBC)
/* 872A0 800EDDF0 2484CFBC */  addiu     $a0, $a0, %lo(D_8010CFBC)
/* 872A4 800EDDF4 8C830000 */  lw        $v1, ($a0)
/* 872A8 800EDDF8 3C028011 */  lui       $v0, %hi(D_8010CFB8)
/* 872AC 800EDDFC 8C42CFB8 */  lw        $v0, %lo(D_8010CFB8)($v0)
/* 872B0 800EDE00 106202D9 */  beq       $v1, $v0, .L800EE968
/* 872B4 800EDE04 24620001 */   addiu    $v0, $v1, 1
/* 872B8 800EDE08 AC820000 */  sw        $v0, ($a0)
/* 872BC 800EDE0C 28420028 */  slti      $v0, $v0, 0x28
/* 872C0 800EDE10 50400001 */  beql      $v0, $zero, .L800EDE18
/* 872C4 800EDE14 AC800000 */   sw       $zero, ($a0)
.L800EDE18:
/* 872C8 800EDE18 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 872CC 800EDE1C 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 872D0 800EDE20 8C820000 */  lw        $v0, ($a0)
/* 872D4 800EDE24 3C013FA6 */  lui       $at, 0x3fa6
/* 872D8 800EDE28 34216666 */  ori       $at, $at, 0x6666
/* 872DC 800EDE2C 44810000 */  mtc1      $at, $f0
/* 872E0 800EDE30 00021100 */  sll       $v0, $v0, 4
/* 872E4 800EDE34 00438021 */  addu      $s0, $v0, $v1
/* 872E8 800EDE38 C6160004 */  lwc1      $f22, 4($s0)
/* 872EC 800EDE3C C6060008 */  lwc1      $f6, 8($s0)
/* 872F0 800EDE40 C614000C */  lwc1      $f20, 0xc($s0)
/* 872F4 800EDE44 3C108011 */  lui       $s0, %hi(D_8010CFC8)
/* 872F8 800EDE48 2610CFC8 */  addiu     $s0, $s0, %lo(D_8010CFC8)
/* 872FC 800EDE4C A620008E */  sh        $zero, 0x8e($s1)
/* 87300 800EDE50 E6200014 */  swc1      $f0, 0x14($s1)
/* 87304 800EDE54 E6360060 */  swc1      $f22, 0x60($s1)
/* 87308 800EDE58 E6260064 */  swc1      $f6, 0x64($s1)
/* 8730C 800EDE5C E6340068 */  swc1      $f20, 0x68($s1)
/* 87310 800EDE60 86020000 */  lh        $v0, ($s0)
/* 87314 800EDE64 24120001 */  addiu     $s2, $zero, 1
/* 87318 800EDE68 14520005 */  bne       $v0, $s2, .L800EDE80
/* 8731C 800EDE6C 00000000 */   nop
/* 87320 800EDE70 3C0140C0 */  lui       $at, 0x40c0
/* 87324 800EDE74 44810000 */  mtc1      $at, $f0
/* 87328 800EDE78 00000000 */  nop
/* 8732C 800EDE7C E6200018 */  swc1      $f0, 0x18($s1)
.L800EDE80:
/* 87330 800EDE80 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87334 800EDE84 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 87338 800EDE88 8E260060 */  lw        $a2, 0x60($s1)
/* 8733C 800EDE8C 0C00A7B5 */  jal       dist2D
/* 87340 800EDE90 8E270068 */   lw       $a3, 0x68($s1)
/* 87344 800EDE94 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87348 800EDE98 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 8734C 800EDE9C 8E260060 */  lw        $a2, 0x60($s1)
/* 87350 800EDEA0 8E270068 */  lw        $a3, 0x68($s1)
/* 87354 800EDEA4 0C00A720 */  jal       atan2
/* 87358 800EDEA8 E6200010 */   swc1     $f0, 0x10($s1)
/* 8735C 800EDEAC E620000C */  swc1      $f0, 0xc($s1)
/* 87360 800EDEB0 C6200010 */  lwc1      $f0, 0x10($s1)
/* 87364 800EDEB4 3C014049 */  lui       $at, 0x4049
/* 87368 800EDEB8 44811800 */  mtc1      $at, $f3
/* 8736C 800EDEBC 44801000 */  mtc1      $zero, $f2
/* 87370 800EDEC0 46000021 */  cvt.d.s   $f0, $f0
/* 87374 800EDEC4 4620103C */  c.lt.d    $f2, $f0
/* 87378 800EDEC8 00000000 */  nop
/* 8737C 800EDECC 45000005 */  bc1f      .L800EDEE4
/* 87380 800EDED0 00000000 */   nop
/* 87384 800EDED4 3C014248 */  lui       $at, 0x4248
/* 87388 800EDED8 44810000 */  mtc1      $at, $f0
/* 8738C 800EDEDC 00000000 */  nop
/* 87390 800EDEE0 E6200010 */  swc1      $f0, 0x10($s1)
.L800EDEE4:
/* 87394 800EDEE4 C6220064 */  lwc1      $f2, 0x64($s1)
/* 87398 800EDEE8 C620003C */  lwc1      $f0, 0x3c($s1)
/* 8739C 800EDEEC 46001101 */  sub.s     $f4, $f2, $f0
/* 873A0 800EDEF0 C6200010 */  lwc1      $f0, 0x10($s1)
/* 873A4 800EDEF4 46000086 */  mov.s     $f2, $f0
/* 873A8 800EDEF8 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 873AC 800EDEFC 4604103C */  c.lt.s    $f2, $f4
/* 873B0 800EDF00 00000000 */  nop
/* 873B4 800EDF04 45000002 */  bc1f      .L800EDF10
/* 873B8 800EDF08 E7A40024 */   swc1     $f4, 0x24($sp)
/* 873BC 800EDF0C E7A4002C */  swc1      $f4, 0x2c($sp)
.L800EDF10:
/* 873C0 800EDF10 86020000 */  lh        $v0, ($s0)
/* 873C4 800EDF14 14520026 */  bne       $v0, $s2, .L800EDFB0
/* 873C8 800EDF18 2402000A */   addiu    $v0, $zero, 0xa
/* 873CC 800EDF1C 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 873D0 800EDF20 C420CFC0 */  lwc1      $f0, %lo(D_8010CFC0)($at)
/* 873D4 800EDF24 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 873D8 800EDF28 4600103C */  c.lt.s    $f2, $f0
/* 873DC 800EDF2C 00000000 */  nop
/* 873E0 800EDF30 4500000B */  bc1f      .L800EDF60
/* 873E4 800EDF34 00000000 */   nop
/* 873E8 800EDF38 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 873EC 800EDF3C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 873F0 800EDF40 AE20001C */  sw        $zero, 0x1c($s1)
/* 873F4 800EDF44 8E660028 */  lw        $a2, 0x28($s3)
/* 873F8 800EDF48 0C00A720 */  jal       atan2
/* 873FC 800EDF4C 8E670030 */   lw       $a3, 0x30($s3)
/* 87400 800EDF50 24020005 */  addiu     $v0, $zero, 5
/* 87404 800EDF54 E620000C */  swc1      $f0, 0xc($s1)
/* 87408 800EDF58 0803BA5A */  j         .L800EE968
/* 8740C 800EDF5C A6020000 */   sh       $v0, ($s0)
.L800EDF60:
/* 87410 800EDF60 C6200018 */  lwc1      $f0, 0x18($s1)
/* 87414 800EDF64 46001003 */  div.s     $f0, $f2, $f0
/* 87418 800EDF68 4600040D */  trunc.w.s $f16, $f0
/* 8741C 800EDF6C 44028000 */  mfc1      $v0, $f16
/* 87420 800EDF70 00000000 */  nop
/* 87424 800EDF74 A622008E */  sh        $v0, 0x8e($s1)
/* 87428 800EDF78 00021400 */  sll       $v0, $v0, 0x10
/* 8742C 800EDF7C 00021403 */  sra       $v0, $v0, 0x10
/* 87430 800EDF80 2842000A */  slti      $v0, $v0, 0xa
/* 87434 800EDF84 10400002 */  beqz      $v0, .L800EDF90
/* 87438 800EDF88 2402000A */   addiu    $v0, $zero, 0xa
/* 8743C 800EDF8C A622008E */  sh        $v0, 0x8e($s1)
.L800EDF90:
/* 87440 800EDF90 8622008E */  lh        $v0, 0x8e($s1)
/* 87444 800EDF94 C6200010 */  lwc1      $f0, 0x10($s1)
/* 87448 800EDF98 44821000 */  mtc1      $v0, $f2
/* 8744C 800EDF9C 00000000 */  nop
/* 87450 800EDFA0 468010A0 */  cvt.s.w   $f2, $f2
/* 87454 800EDFA4 46020003 */  div.s     $f0, $f0, $f2
/* 87458 800EDFA8 0803B7ED */  j         .L800EDFB4
/* 8745C 800EDFAC E6200018 */   swc1     $f0, 0x18($s1)
.L800EDFB0:
/* 87460 800EDFB0 A622008E */  sh        $v0, 0x8e($s1)
.L800EDFB4:
/* 87464 800EDFB4 8622008E */  lh        $v0, 0x8e($s1)
/* 87468 800EDFB8 C6220014 */  lwc1      $f2, 0x14($s1)
/* 8746C 800EDFBC 44822000 */  mtc1      $v0, $f4
/* 87470 800EDFC0 00000000 */  nop
/* 87474 800EDFC4 46802120 */  cvt.s.w   $f4, $f4
/* 87478 800EDFC8 46041082 */  mul.s     $f2, $f2, $f4
/* 8747C 800EDFCC 00000000 */  nop
/* 87480 800EDFD0 46041082 */  mul.s     $f2, $f2, $f4
/* 87484 800EDFD4 00000000 */  nop
/* 87488 800EDFD8 3C013F00 */  lui       $at, 0x3f00
/* 8748C 800EDFDC 44810000 */  mtc1      $at, $f0
/* 87490 800EDFE0 00000000 */  nop
/* 87494 800EDFE4 46001082 */  mul.s     $f2, $f2, $f0
/* 87498 800EDFE8 00000000 */  nop
/* 8749C 800EDFEC C7A00024 */  lwc1      $f0, 0x24($sp)
/* 874A0 800EDFF0 46020000 */  add.s     $f0, $f0, $f2
/* 874A4 800EDFF4 3C014034 */  lui       $at, 0x4034
/* 874A8 800EDFF8 44811800 */  mtc1      $at, $f3
/* 874AC 800EDFFC 44801000 */  mtc1      $zero, $f2
/* 874B0 800EE000 46040003 */  div.s     $f0, $f0, $f4
/* 874B4 800EE004 E620001C */  swc1      $f0, 0x1c($s1)
/* 874B8 800EE008 46000021 */  cvt.d.s   $f0, $f0
/* 874BC 800EE00C 4620103C */  c.lt.d    $f2, $f0
/* 874C0 800EE010 00000000 */  nop
/* 874C4 800EE014 45000005 */  bc1f      .L800EE02C
/* 874C8 800EE018 00000000 */   nop
/* 874CC 800EE01C 3C0141A0 */  lui       $at, 0x41a0
/* 874D0 800EE020 44810000 */  mtc1      $at, $f0
/* 874D4 800EE024 00000000 */  nop
/* 874D8 800EE028 E620001C */  swc1      $f0, 0x1c($s1)
.L800EE02C:
/* 874DC 800EE02C 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 874E0 800EE030 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 874E4 800EE034 C6200038 */  lwc1      $f0, 0x38($s1)
/* 874E8 800EE038 C622003C */  lwc1      $f2, 0x3c($s1)
/* 874EC 800EE03C C6240040 */  lwc1      $f4, 0x40($s1)
/* 874F0 800EE040 000310C0 */  sll       $v0, $v1, 3
/* 874F4 800EE044 00431021 */  addu      $v0, $v0, $v1
/* 874F8 800EE048 00021080 */  sll       $v0, $v0, 2
/* 874FC 800EE04C 3C038010 */  lui       $v1, %hi(gPartnerAnimations+0x8)
/* 87500 800EE050 00621821 */  addu      $v1, $v1, $v0
/* 87504 800EE054 8C638350 */  lw        $v1, %lo(gPartnerAnimations+0x8)($v1)
/* 87508 800EE058 24020002 */  addiu     $v0, $zero, 2
/* 8750C 800EE05C 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 87510 800EE060 A422CFC8 */  sh        $v0, %lo(D_8010CFC8)($at)
/* 87514 800EE064 E6200060 */  swc1      $f0, 0x60($s1)
/* 87518 800EE068 E6220064 */  swc1      $f2, 0x64($s1)
/* 8751C 800EE06C E6240068 */  swc1      $f4, 0x68($s1)
/* 87520 800EE070 0803BA5A */  j         .L800EE968
/* 87524 800EE074 AE230028 */   sw       $v1, 0x28($s1)
glabel L800EE078_87528
/* 87528 800EE078 C620001C */  lwc1      $f0, 0x1c($s1)
/* 8752C 800EE07C C6220014 */  lwc1      $f2, 0x14($s1)
/* 87530 800EE080 46020001 */  sub.s     $f0, $f0, $f2
/* 87534 800EE084 C622003C */  lwc1      $f2, 0x3c($s1)
/* 87538 800EE088 46001080 */  add.s     $f2, $f2, $f0
/* 8753C 800EE08C 4480A000 */  mtc1      $zero, $f20
/* 87540 800EE090 00000000 */  nop
/* 87544 800EE094 4614003E */  c.le.s    $f0, $f20
/* 87548 800EE098 E620001C */  swc1      $f0, 0x1c($s1)
/* 8754C 800EE09C 4500000A */  bc1f      .L800EE0C8
/* 87550 800EE0A0 E622003C */   swc1     $f2, 0x3c($s1)
/* 87554 800EE0A4 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 87558 800EE0A8 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 8755C 800EE0AC 000218C0 */  sll       $v1, $v0, 3
/* 87560 800EE0B0 00621821 */  addu      $v1, $v1, $v0
/* 87564 800EE0B4 00031880 */  sll       $v1, $v1, 2
/* 87568 800EE0B8 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0xC)
/* 8756C 800EE0BC 00431021 */  addu      $v0, $v0, $v1
/* 87570 800EE0C0 8C428354 */  lw        $v0, %lo(gPartnerAnimations+0xC)($v0)
/* 87574 800EE0C4 AE220028 */  sw        $v0, 0x28($s1)
.L800EE0C8:
/* 87578 800EE0C8 8E250018 */  lw        $a1, 0x18($s1)
/* 8757C 800EE0CC 8E26000C */  lw        $a2, 0xc($s1)
/* 87580 800EE0D0 0C00EA95 */  jal       npc_move_heading
/* 87584 800EE0D4 0220202D */   daddu    $a0, $s1, $zero
/* 87588 800EE0D8 C620001C */  lwc1      $f0, 0x1c($s1)
/* 8758C 800EE0DC 4614003E */  c.le.s    $f0, $f20
/* 87590 800EE0E0 00000000 */  nop
/* 87594 800EE0E4 45000220 */  bc1f      .L800EE968
/* 87598 800EE0E8 00000000 */   nop
/* 8759C 800EE0EC C622003C */  lwc1      $f2, 0x3c($s1)
/* 875A0 800EE0F0 C6200064 */  lwc1      $f0, 0x64($s1)
/* 875A4 800EE0F4 4600103C */  c.lt.s    $f2, $f0
/* 875A8 800EE0F8 00000000 */  nop
/* 875AC 800EE0FC 4500021A */  bc1f      .L800EE968
/* 875B0 800EE100 00000000 */   nop
/* 875B4 800EE104 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 875B8 800EE108 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 875BC 800EE10C 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 875C0 800EE110 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 875C4 800EE114 000310C0 */  sll       $v0, $v1, 3
/* 875C8 800EE118 00431021 */  addu      $v0, $v0, $v1
/* 875CC 800EE11C 00021080 */  sll       $v0, $v0, 2
/* 875D0 800EE120 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x10)
/* 875D4 800EE124 00220821 */  addu      $at, $at, $v0
/* 875D8 800EE128 8C228358 */  lw        $v0, %lo(gPartnerAnimations+0x10)($at)
/* 875DC 800EE12C E634001C */  swc1      $f20, 0x1c($s1)
/* 875E0 800EE130 E620003C */  swc1      $f0, 0x3c($s1)
/* 875E4 800EE134 AE220028 */  sw        $v0, 0x28($s1)
/* 875E8 800EE138 8E660028 */  lw        $a2, 0x28($s3)
/* 875EC 800EE13C 0C00A720 */  jal       atan2
/* 875F0 800EE140 8E670030 */   lw       $a3, 0x30($s3)
/* 875F4 800EE144 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 875F8 800EE148 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 875FC 800EE14C 8E260060 */  lw        $a2, 0x60($s1)
/* 87600 800EE150 8E270068 */  lw        $a3, 0x68($s1)
/* 87604 800EE154 3C108011 */  lui       $s0, %hi(D_8010CFC8)
/* 87608 800EE158 2610CFC8 */  addiu     $s0, $s0, %lo(D_8010CFC8)
/* 8760C 800EE15C E620000C */  swc1      $f0, 0xc($s1)
/* 87610 800EE160 0C00A7B5 */  jal       dist2D
/* 87614 800EE164 A6000000 */   sh       $zero, ($s0)
/* 87618 800EE168 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 8761C 800EE16C C422CFC0 */  lwc1      $f2, %lo(D_8010CFC0)($at)
/* 87620 800EE170 4602003C */  c.lt.s    $f0, $f2
/* 87624 800EE174 00000000 */  nop
/* 87628 800EE178 450001FB */  bc1f      .L800EE968
/* 8762C 800EE17C E7A0002C */   swc1     $f0, 0x2c($sp)
/* 87630 800EE180 2402000F */  addiu     $v0, $zero, 0xf
/* 87634 800EE184 0803BA5A */  j         .L800EE968
/* 87638 800EE188 A6020000 */   sh       $v0, ($s0)
glabel L800EE18C_8763C
/* 8763C 800EE18C 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 87640 800EE190 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 87644 800EE194 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87648 800EE198 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 8764C 800EE19C 8E660028 */  lw        $a2, 0x28($s3)
/* 87650 800EE1A0 8E670030 */  lw        $a3, 0x30($s3)
/* 87654 800EE1A4 3C028011 */  lui       $v0, %hi(D_8010CFBC)
/* 87658 800EE1A8 8C42CFBC */  lw        $v0, %lo(D_8010CFBC)($v0)
/* 8765C 800EE1AC C622003C */  lwc1      $f2, 0x3c($s1)
/* 87660 800EE1B0 00021100 */  sll       $v0, $v0, 4
/* 87664 800EE1B4 00438021 */  addu      $s0, $v0, $v1
/* 87668 800EE1B8 46006006 */  mov.s     $f0, $f12
/* 8766C 800EE1BC C6160004 */  lwc1      $f22, 4($s0)
/* 87670 800EE1C0 C614000C */  lwc1      $f20, 0xc($s0)
/* 87674 800EE1C4 46007106 */  mov.s     $f4, $f14
/* 87678 800EE1C8 E7A00020 */  swc1      $f0, 0x20($sp)
/* 8767C 800EE1CC E7A20024 */  swc1      $f2, 0x24($sp)
/* 87680 800EE1D0 0C00A7B5 */  jal       dist2D
/* 87684 800EE1D4 E7A40028 */   swc1     $f4, 0x28($sp)
/* 87688 800EE1D8 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 8768C 800EE1DC C422CFC0 */  lwc1      $f2, %lo(D_8010CFC0)($at)
/* 87690 800EE1E0 4602003E */  c.le.s    $f0, $f2
/* 87694 800EE1E4 00000000 */  nop
/* 87698 800EE1E8 450000A5 */  bc1f      .L800EE480
/* 8769C 800EE1EC E7A0002C */   swc1     $f0, 0x2c($sp)
/* 876A0 800EE1F0 3C048011 */  lui       $a0, %hi(D_8010CFCA)
/* 876A4 800EE1F4 2484CFCA */  addiu     $a0, $a0, %lo(D_8010CFCA)
/* 876A8 800EE1F8 84820000 */  lh        $v0, ($a0)
/* 876AC 800EE1FC 1440002D */  bnez      $v0, .L800EE2B4
/* 876B0 800EE200 00000000 */   nop
/* 876B4 800EE204 962200A8 */  lhu       $v0, 0xa8($s1)
/* 876B8 800EE208 C660002C */  lwc1      $f0, 0x2c($s3)
/* 876BC 800EE20C 00021400 */  sll       $v0, $v0, 0x10
/* 876C0 800EE210 00021C03 */  sra       $v1, $v0, 0x10
/* 876C4 800EE214 000217C2 */  srl       $v0, $v0, 0x1f
/* 876C8 800EE218 00621821 */  addu      $v1, $v1, $v0
/* 876CC 800EE21C 866200B0 */  lh        $v0, 0xb0($s3)
/* 876D0 800EE220 00031843 */  sra       $v1, $v1, 1
/* 876D4 800EE224 00431023 */  subu      $v0, $v0, $v1
/* 876D8 800EE228 44821000 */  mtc1      $v0, $f2
/* 876DC 800EE22C 00000000 */  nop
/* 876E0 800EE230 468010A0 */  cvt.s.w   $f2, $f2
/* 876E4 800EE234 46020000 */  add.s     $f0, $f0, $f2
/* 876E8 800EE238 C622003C */  lwc1      $f2, 0x3c($s1)
/* 876EC 800EE23C 46020001 */  sub.s     $f0, $f0, $f2
/* 876F0 800EE240 3C013FA0 */  lui       $at, 0x3fa0
/* 876F4 800EE244 44811800 */  mtc1      $at, $f3
/* 876F8 800EE248 44801000 */  mtc1      $zero, $f2
/* 876FC 800EE24C 46000021 */  cvt.d.s   $f0, $f0
/* 87700 800EE250 46220002 */  mul.d     $f0, $f0, $f2
/* 87704 800EE254 00000000 */  nop
/* 87708 800EE258 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 8770C 800EE25C 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 87710 800EE260 000310C0 */  sll       $v0, $v1, 3
/* 87714 800EE264 00431021 */  addu      $v0, $v0, $v1
/* 87718 800EE268 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 8771C 800EE26C 00021080 */  sll       $v0, $v0, 2
/* 87720 800EE270 460010A1 */  cvt.d.s   $f2, $f2
/* 87724 800EE274 46201080 */  add.d     $f2, $f2, $f0
/* 87728 800EE278 AE200018 */  sw        $zero, 0x18($s1)
/* 8772C 800EE27C AE200014 */  sw        $zero, 0x14($s1)
/* 87730 800EE280 462010A0 */  cvt.s.d   $f2, $f2
/* 87734 800EE284 E622003C */  swc1      $f2, 0x3c($s1)
/* 87738 800EE288 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 8773C 800EE28C 00220821 */  addu      $at, $at, $v0
/* 87740 800EE290 8C22835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($at)
/* 87744 800EE294 E7A20024 */  swc1      $f2, 0x24($sp)
/* 87748 800EE298 AE220028 */  sw        $v0, 0x28($s1)
/* 8774C 800EE29C 826300B4 */  lb        $v1, 0xb4($s3)
/* 87750 800EE2A0 2402000C */  addiu     $v0, $zero, 0xc
/* 87754 800EE2A4 50620076 */  beql      $v1, $v0, .L800EE480
/* 87758 800EE2A8 A4800000 */   sh       $zero, ($a0)
/* 8775C 800EE2AC 0803B920 */  j         .L800EE480
/* 87760 800EE2B0 00000000 */   nop
.L800EE2B4:
/* 87764 800EE2B4 C66200A8 */  lwc1      $f2, 0xa8($s3)
/* 87768 800EE2B8 3C014334 */  lui       $at, 0x4334
/* 8776C 800EE2BC 44810000 */  mtc1      $at, $f0
/* 87770 800EE2C0 C64C006C */  lwc1      $f12, 0x6c($s2)
/* 87774 800EE2C4 4600103C */  c.lt.s    $f2, $f0
/* 87778 800EE2C8 3C01C2B4 */  lui       $at, 0xc2b4
/* 8777C 800EE2CC 44810000 */  mtc1      $at, $f0
/* 87780 800EE2D0 45000003 */  bc1f      .L800EE2E0
/* 87784 800EE2D4 00000000 */   nop
/* 87788 800EE2D8 3C0142B4 */  lui       $at, 0x42b4
/* 8778C 800EE2DC 44810000 */  mtc1      $at, $f0
.L800EE2E0:
/* 87790 800EE2E0 0C00A6C9 */  jal       clamp_angle
/* 87794 800EE2E4 46006300 */   add.s    $f12, $f12, $f0
/* 87798 800EE2E8 44070000 */  mfc1      $a3, $f0
/* 8779C 800EE2EC C6600028 */  lwc1      $f0, 0x28($s3)
/* 877A0 800EE2F0 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 877A4 800EE2F4 C424CFC0 */  lwc1      $f4, %lo(D_8010CFC0)($at)
/* 877A8 800EE2F8 26240060 */  addiu     $a0, $s1, 0x60
/* 877AC 800EE2FC E6200060 */  swc1      $f0, 0x60($s1)
/* 877B0 800EE300 3C014120 */  lui       $at, 0x4120
/* 877B4 800EE304 44810000 */  mtc1      $at, $f0
/* 877B8 800EE308 C662002C */  lwc1      $f2, 0x2c($s3)
/* 877BC 800EE30C 46002101 */  sub.s     $f4, $f4, $f0
/* 877C0 800EE310 E6220064 */  swc1      $f2, 0x64($s1)
/* 877C4 800EE314 C6600030 */  lwc1      $f0, 0x30($s3)
/* 877C8 800EE318 44062000 */  mfc1      $a2, $f4
/* 877CC 800EE31C 26250068 */  addiu     $a1, $s1, 0x68
/* 877D0 800EE320 0C00A7E7 */  jal       add_vec2D_polar
/* 877D4 800EE324 E6200068 */   swc1     $f0, 0x68($s1)
/* 877D8 800EE328 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 877DC 800EE32C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 877E0 800EE330 8E260060 */  lw        $a2, 0x60($s1)
/* 877E4 800EE334 0C00A720 */  jal       atan2
/* 877E8 800EE338 8E270068 */   lw       $a3, 0x68($s1)
/* 877EC 800EE33C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 877F0 800EE340 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 877F4 800EE344 8E260060 */  lw        $a2, 0x60($s1)
/* 877F8 800EE348 8E270068 */  lw        $a3, 0x68($s1)
/* 877FC 800EE34C 0C00A7B5 */  jal       dist2D
/* 87800 800EE350 46000506 */   mov.s    $f20, $f0
/* 87804 800EE354 3C014000 */  lui       $at, 0x4000
/* 87808 800EE358 44811000 */  mtc1      $at, $f2
/* 8780C 800EE35C E7A0002C */  swc1      $f0, 0x2c($sp)
/* 87810 800EE360 4600103C */  c.lt.s    $f2, $f0
/* 87814 800EE364 00000000 */  nop
/* 87818 800EE368 45000022 */  bc1f      .L800EE3F4
/* 8781C 800EE36C E6220018 */   swc1     $f2, 0x18($s1)
/* 87820 800EE370 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 87824 800EE374 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 87828 800EE378 3C048010 */  lui       $a0, %hi(gPartnerAnimations)
/* 8782C 800EE37C 24848348 */  addiu     $a0, $a0, %lo(gPartnerAnimations)
/* 87830 800EE380 E634000C */  swc1      $f20, 0xc($s1)
/* 87834 800EE384 000310C0 */  sll       $v0, $v1, 3
/* 87838 800EE388 00431021 */  addu      $v0, $v0, $v1
/* 8783C 800EE38C 00021080 */  sll       $v0, $v0, 2
/* 87840 800EE390 00442021 */  addu      $a0, $v0, $a0
/* 87844 800EE394 8E220000 */  lw        $v0, ($s1)
/* 87848 800EE398 8C830018 */  lw        $v1, 0x18($a0)
/* 8784C 800EE39C 30424000 */  andi      $v0, $v0, 0x4000
/* 87850 800EE3A0 14400004 */  bnez      $v0, .L800EE3B4
/* 87854 800EE3A4 AE230028 */   sw       $v1, 0x28($s1)
/* 87858 800EE3A8 3C018010 */  lui       $at, %hi(D_800F803A)
/* 8785C 800EE3AC 0803B919 */  j         .L800EE464
/* 87860 800EE3B0 A420803A */   sh       $zero, %lo(D_800F803A)($at)
.L800EE3B4:
/* 87864 800EE3B4 3C038010 */  lui       $v1, %hi(D_800F803A)
/* 87868 800EE3B8 2463803A */  addiu     $v1, $v1, %lo(D_800F803A)
/* 8786C 800EE3BC 94620000 */  lhu       $v0, ($v1)
/* 87870 800EE3C0 24420001 */  addiu     $v0, $v0, 1
/* 87874 800EE3C4 A4620000 */  sh        $v0, ($v1)
/* 87878 800EE3C8 00021400 */  sll       $v0, $v0, 0x10
/* 8787C 800EE3CC 00021403 */  sra       $v0, $v0, 0x10
/* 87880 800EE3D0 2842000B */  slti      $v0, $v0, 0xb
/* 87884 800EE3D4 14400023 */  bnez      $v0, .L800EE464
/* 87888 800EE3D8 00000000 */   nop
/* 8788C 800EE3DC C6740080 */  lwc1      $f20, 0x80($s3)
/* 87890 800EE3E0 AE200018 */  sw        $zero, 0x18($s1)
/* 87894 800EE3E4 AE200014 */  sw        $zero, 0x14($s1)
/* 87898 800EE3E8 E6340034 */  swc1      $f20, 0x34($s1)
/* 8789C 800EE3EC 0803B90E */  j         .L800EE438
/* 878A0 800EE3F0 8C820014 */   lw       $v0, 0x14($a0)
.L800EE3F4:
/* 878A4 800EE3F4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 878A8 800EE3F8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 878AC 800EE3FC 8E660028 */  lw        $a2, 0x28($s3)
/* 878B0 800EE400 0C00A720 */  jal       atan2
/* 878B4 800EE404 8E670030 */   lw       $a3, 0x30($s3)
/* 878B8 800EE408 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 878BC 800EE40C 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 878C0 800EE410 46000506 */  mov.s     $f20, $f0
/* 878C4 800EE414 E634000C */  swc1      $f20, 0xc($s1)
/* 878C8 800EE418 AE200018 */  sw        $zero, 0x18($s1)
/* 878CC 800EE41C AE200014 */  sw        $zero, 0x14($s1)
/* 878D0 800EE420 000310C0 */  sll       $v0, $v1, 3
/* 878D4 800EE424 00431021 */  addu      $v0, $v0, $v1
/* 878D8 800EE428 00021080 */  sll       $v0, $v0, 2
/* 878DC 800EE42C 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 878E0 800EE430 00220821 */  addu      $at, $at, $v0
/* 878E4 800EE434 8C22835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($at)
.L800EE438:
/* 878E8 800EE438 3C048011 */  lui       $a0, %hi(D_8010CFCA)
/* 878EC 800EE43C 2484CFCA */  addiu     $a0, $a0, %lo(D_8010CFCA)
/* 878F0 800EE440 AE220028 */  sw        $v0, 0x28($s1)
/* 878F4 800EE444 84830000 */  lh        $v1, ($a0)
/* 878F8 800EE448 24020002 */  addiu     $v0, $zero, 2
/* 878FC 800EE44C 10620004 */  beq       $v1, $v0, .L800EE460
/* 87900 800EE450 2402000C */   addiu    $v0, $zero, 0xc
/* 87904 800EE454 826300B4 */  lb        $v1, 0xb4($s3)
/* 87908 800EE458 14620002 */  bne       $v1, $v0, .L800EE464
/* 8790C 800EE45C 00000000 */   nop
.L800EE460:
/* 87910 800EE460 A4800000 */  sh        $zero, ($a0)
.L800EE464:
/* 87914 800EE464 8E250018 */  lw        $a1, 0x18($s1)
/* 87918 800EE468 4406A000 */  mfc1      $a2, $f20
/* 8791C 800EE46C 0220202D */  daddu     $a0, $s1, $zero
/* 87920 800EE470 0C00EA95 */  jal       npc_move_heading
/* 87924 800EE474 AC86000C */   sw       $a2, 0xc($a0)
/* 87928 800EE478 0803BA5A */  j         .L800EE968
/* 8792C 800EE47C 00000000 */   nop
.L800EE480:
/* 87930 800EE480 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87934 800EE484 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 87938 800EE488 8E660028 */  lw        $a2, 0x28($s3)
/* 8793C 800EE48C 0C00A7B5 */  jal       dist2D
/* 87940 800EE490 8E670030 */   lw       $a3, 0x30($s3)
/* 87944 800EE494 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 87948 800EE498 C422CFC0 */  lwc1      $f2, %lo(D_8010CFC0)($at)
/* 8794C 800EE49C 4602003E */  c.le.s    $f0, $f2
/* 87950 800EE4A0 00000000 */  nop
/* 87954 800EE4A4 45010130 */  bc1t      .L800EE968
/* 87958 800EE4A8 E7A0002C */   swc1     $f0, 0x2c($sp)
/* 8795C 800EE4AC 3C0142B4 */  lui       $at, 0x42b4
/* 87960 800EE4B0 4481C000 */  mtc1      $at, $f24
/* 87964 800EE4B4 3C128011 */  lui       $s2, %hi(D_8010CFBC)
/* 87968 800EE4B8 2652CFBC */  addiu     $s2, $s2, %lo(D_8010CFBC)
/* 8796C 800EE4BC 3C148011 */  lui       $s4, %hi(D_8010CD38)
/* 87970 800EE4C0 2694CD38 */  addiu     $s4, $s4, %lo(D_8010CD38)
.L800EE4C4:
/* 87974 800EE4C4 82020000 */  lb        $v0, ($s0)
/* 87978 800EE4C8 14400024 */  bnez      $v0, .L800EE55C
/* 8797C 800EE4CC 00000000 */   nop
/* 87980 800EE4D0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87984 800EE4D4 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 87988 800EE4D8 4406B000 */  mfc1      $a2, $f22
/* 8798C 800EE4DC 4407A000 */  mfc1      $a3, $f20
/* 87990 800EE4E0 0C00A720 */  jal       atan2
/* 87994 800EE4E4 00000000 */   nop
/* 87998 800EE4E8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 8799C 800EE4EC C62E0040 */  lwc1      $f14, 0x40($s1)
/* 879A0 800EE4F0 8E660028 */  lw        $a2, 0x28($s3)
/* 879A4 800EE4F4 8E670030 */  lw        $a3, 0x30($s3)
/* 879A8 800EE4F8 0C00A720 */  jal       atan2
/* 879AC 800EE4FC 46000506 */   mov.s    $f20, $f0
/* 879B0 800EE500 4600A306 */  mov.s     $f12, $f20
/* 879B4 800EE504 0C00A70A */  jal       get_clamped_angle_diff
/* 879B8 800EE508 46000386 */   mov.s    $f14, $f0
/* 879BC 800EE50C 46000005 */  abs.s     $f0, $f0
/* 879C0 800EE510 4618003C */  c.lt.s    $f0, $f24
/* 879C4 800EE514 00000000 */  nop
/* 879C8 800EE518 45010010 */  bc1t      .L800EE55C
/* 879CC 800EE51C 00000000 */   nop
/* 879D0 800EE520 8E430000 */  lw        $v1, ($s2)
/* 879D4 800EE524 3C028011 */  lui       $v0, %hi(D_8010CFB8)
/* 879D8 800EE528 8C42CFB8 */  lw        $v0, %lo(D_8010CFB8)($v0)
/* 879DC 800EE52C 1062000B */  beq       $v1, $v0, .L800EE55C
/* 879E0 800EE530 24620001 */   addiu    $v0, $v1, 1
/* 879E4 800EE534 AE420000 */  sw        $v0, ($s2)
/* 879E8 800EE538 28420028 */  slti      $v0, $v0, 0x28
/* 879EC 800EE53C 50400001 */  beql      $v0, $zero, .L800EE544
/* 879F0 800EE540 AE400000 */   sw       $zero, ($s2)
.L800EE544:
/* 879F4 800EE544 8E420000 */  lw        $v0, ($s2)
/* 879F8 800EE548 00021100 */  sll       $v0, $v0, 4
/* 879FC 800EE54C 00548021 */  addu      $s0, $v0, $s4
/* 87A00 800EE550 C6160004 */  lwc1      $f22, 4($s0)
/* 87A04 800EE554 0803B931 */  j         .L800EE4C4
/* 87A08 800EE558 C614000C */   lwc1     $f20, 0xc($s0)
.L800EE55C:
/* 87A0C 800EE55C 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 87A10 800EE560 A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 87A14 800EE564 0803BA5A */  j         .L800EE968
/* 87A18 800EE568 00000000 */   nop
glabel L800EE56C_87A1C
/* 87A1C 800EE56C 8E620004 */  lw        $v0, 4($s3)
/* 87A20 800EE570 3C030010 */  lui       $v1, 0x10
/* 87A24 800EE574 00431024 */  and       $v0, $v0, $v1
/* 87A28 800EE578 144000FB */  bnez      $v0, .L800EE968
/* 87A2C 800EE57C 00000000 */   nop
/* 87A30 800EE580 3C038011 */  lui       $v1, %hi(D_8010CFCE)
/* 87A34 800EE584 8463CFCE */  lh        $v1, %lo(D_8010CFCE)($v1)
/* 87A38 800EE588 10600006 */  beqz      $v1, .L800EE5A4
/* 87A3C 800EE58C 00000000 */   nop
/* 87A40 800EE590 24020001 */  addiu     $v0, $zero, 1
/* 87A44 800EE594 10620048 */  beq       $v1, $v0, .L800EE6B8
/* 87A48 800EE598 00000000 */   nop
/* 87A4C 800EE59C 0803BA5A */  j         .L800EE968
/* 87A50 800EE5A0 00000000 */   nop
.L800EE5A4:
/* 87A54 800EE5A4 0C0394D2 */  jal       func_800E5348
/* 87A58 800EE5A8 00000000 */   nop
/* 87A5C 800EE5AC 3C014334 */  lui       $at, 0x4334
/* 87A60 800EE5B0 44816000 */  mtc1      $at, $f12
/* 87A64 800EE5B4 0C00A6C9 */  jal       clamp_angle
/* 87A68 800EE5B8 460C0300 */   add.s    $f12, $f0, $f12
/* 87A6C 800EE5BC C6620028 */  lwc1      $f2, 0x28($s3)
/* 87A70 800EE5C0 E6220060 */  swc1      $f2, 0x60($s1)
/* 87A74 800EE5C4 C662002C */  lwc1      $f2, 0x2c($s3)
/* 87A78 800EE5C8 E6220064 */  swc1      $f2, 0x64($s1)
/* 87A7C 800EE5CC C6620030 */  lwc1      $f2, 0x30($s3)
/* 87A80 800EE5D0 26240060 */  addiu     $a0, $s1, 0x60
/* 87A84 800EE5D4 E6220068 */  swc1      $f2, 0x68($s1)
/* 87A88 800EE5D8 866200B2 */  lh        $v0, 0xb2($s3)
/* 87A8C 800EE5DC 44070000 */  mfc1      $a3, $f0
/* 87A90 800EE5E0 44828000 */  mtc1      $v0, $f16
/* 87A94 800EE5E4 00000000 */  nop
/* 87A98 800EE5E8 46808420 */  cvt.s.w   $f16, $f16
/* 87A9C 800EE5EC 44068000 */  mfc1      $a2, $f16
/* 87AA0 800EE5F0 0C00A7E7 */  jal       add_vec2D_polar
/* 87AA4 800EE5F4 26250068 */   addiu    $a1, $s1, 0x68
/* 87AA8 800EE5F8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87AAC 800EE5FC C62E0040 */  lwc1      $f14, 0x40($s1)
/* 87AB0 800EE600 8E260060 */  lw        $a2, 0x60($s1)
/* 87AB4 800EE604 0C00A7B5 */  jal       dist2D
/* 87AB8 800EE608 8E270068 */   lw       $a3, 0x68($s1)
/* 87ABC 800EE60C 3C018010 */  lui       $at, %hi(D_800F802C)
/* 87AC0 800EE610 C422802C */  lwc1      $f2, %lo(D_800F802C)($at)
/* 87AC4 800EE614 468010A0 */  cvt.s.w   $f2, $f2
/* 87AC8 800EE618 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 87ACC 800EE61C 46020003 */  div.s     $f0, $f0, $f2
/* 87AD0 800EE620 3C018010 */  lui       $at, %hi(D_800F8030)
/* 87AD4 800EE624 E4208030 */  swc1      $f0, %lo(D_800F8030)($at)
/* 87AD8 800EE628 E6200018 */  swc1      $f0, 0x18($s1)
/* 87ADC 800EE62C 46000021 */  cvt.d.s   $f0, $f0
/* 87AE0 800EE630 26240028 */  addiu     $a0, $s1, 0x28
/* 87AE4 800EE634 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 87AE8 800EE638 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 87AEC 800EE63C 3C014010 */  lui       $at, 0x4010
/* 87AF0 800EE640 44811800 */  mtc1      $at, $f3
/* 87AF4 800EE644 44801000 */  mtc1      $zero, $f2
/* 87AF8 800EE648 000310C0 */  sll       $v0, $v1, 3
/* 87AFC 800EE64C 00431021 */  addu      $v0, $v0, $v1
/* 87B00 800EE650 4622003C */  c.lt.d    $f0, $f2
/* 87B04 800EE654 00000000 */  nop
/* 87B08 800EE658 45000003 */  bc1f      .L800EE668
/* 87B0C 800EE65C 00021080 */   sll      $v0, $v0, 2
/* 87B10 800EE660 0803B99B */  j         .L800EE66C
/* 87B14 800EE664 24430004 */   addiu    $v1, $v0, 4
.L800EE668:
/* 87B18 800EE668 24430018 */  addiu     $v1, $v0, 0x18
.L800EE66C:
/* 87B1C 800EE66C 3C028010 */  lui       $v0, %hi(gPartnerAnimations)
/* 87B20 800EE670 24428348 */  addiu     $v0, $v0, %lo(gPartnerAnimations)
/* 87B24 800EE674 00431021 */  addu      $v0, $v0, $v1
/* 87B28 800EE678 8C420000 */  lw        $v0, ($v0)
/* 87B2C 800EE67C AC820000 */  sw        $v0, ($a0)
/* 87B30 800EE680 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 87B34 800EE684 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 87B38 800EE688 8E260060 */  lw        $a2, 0x60($s1)
/* 87B3C 800EE68C 0C00A720 */  jal       atan2
/* 87B40 800EE690 8E270068 */   lw       $a3, 0x68($s1)
/* 87B44 800EE694 3C038011 */  lui       $v1, %hi(D_8010CFCE)
/* 87B48 800EE698 2463CFCE */  addiu     $v1, $v1, %lo(D_8010CFCE)
/* 87B4C 800EE69C 94620000 */  lhu       $v0, ($v1)
/* 87B50 800EE6A0 46000506 */  mov.s     $f20, $f0
/* 87B54 800EE6A4 3C018010 */  lui       $at, %hi(D_800F8034)
/* 87B58 800EE6A8 E4348034 */  swc1      $f20, %lo(D_800F8034)($at)
/* 87B5C 800EE6AC E634000C */  swc1      $f20, 0xc($s1)
/* 87B60 800EE6B0 24420001 */  addiu     $v0, $v0, 1
/* 87B64 800EE6B4 A4620000 */  sh        $v0, ($v1)
.L800EE6B8:
/* 87B68 800EE6B8 3C098010 */  lui       $t1, %hi(D_800F802C)
/* 87B6C 800EE6BC 2529802C */  addiu     $t1, $t1, %lo(D_800F802C)
/* 87B70 800EE6C0 8D280000 */  lw        $t0, ($t1)
/* 87B74 800EE6C4 1100007E */  beqz      $t0, .L800EE8C0
/* 87B78 800EE6C8 3C040001 */   lui      $a0, 1
/* 87B7C 800EE6CC 27A50020 */  addiu     $a1, $sp, 0x20
/* 87B80 800EE6D0 C6220038 */  lwc1      $f2, 0x38($s1)
/* 87B84 800EE6D4 862200A8 */  lh        $v0, 0xa8($s1)
/* 87B88 800EE6D8 C6200040 */  lwc1      $f0, 0x40($s1)
/* 87B8C 800EE6DC 27A60024 */  addiu     $a2, $sp, 0x24
/* 87B90 800EE6E0 E7A00028 */  swc1      $f0, 0x28($sp)
/* 87B94 800EE6E4 44820000 */  mtc1      $v0, $f0
/* 87B98 800EE6E8 00000000 */  nop
/* 87B9C 800EE6EC 46800020 */  cvt.s.w   $f0, $f0
/* 87BA0 800EE6F0 E7A20020 */  swc1      $f2, 0x20($sp)
/* 87BA4 800EE6F4 862200A8 */  lh        $v0, 0xa8($s1)
/* 87BA8 800EE6F8 C622003C */  lwc1      $f2, 0x3c($s1)
/* 87BAC 800EE6FC 24420001 */  addiu     $v0, $v0, 1
/* 87BB0 800EE700 46001080 */  add.s     $f2, $f2, $f0
/* 87BB4 800EE704 44820000 */  mtc1      $v0, $f0
/* 87BB8 800EE708 00000000 */  nop
/* 87BBC 800EE70C 46800020 */  cvt.s.w   $f0, $f0
/* 87BC0 800EE710 27A2002C */  addiu     $v0, $sp, 0x2c
/* 87BC4 800EE714 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 87BC8 800EE718 E7A20024 */  swc1      $f2, 0x24($sp)
/* 87BCC 800EE71C AFA20010 */  sw        $v0, 0x10($sp)
/* 87BD0 800EE720 C620000C */  lwc1      $f0, 0xc($s1)
/* 87BD4 800EE724 27A70028 */  addiu     $a3, $sp, 0x28
/* 87BD8 800EE728 E7A00014 */  swc1      $f0, 0x14($sp)
/* 87BDC 800EE72C 862300A6 */  lh        $v1, 0xa6($s1)
/* 87BE0 800EE730 2502FFFF */  addiu     $v0, $t0, -1
/* 87BE4 800EE734 AD220000 */  sw        $v0, ($t1)
/* 87BE8 800EE738 44830000 */  mtc1      $v1, $f0
/* 87BEC 800EE73C 00000000 */  nop
/* 87BF0 800EE740 46800020 */  cvt.s.w   $f0, $f0
/* 87BF4 800EE744 0C0371DE */  jal       func_800DC778
/* 87BF8 800EE748 E7A00018 */   swc1     $f0, 0x18($sp)
/* 87BFC 800EE74C 14400017 */  bnez      $v0, .L800EE7AC
/* 87C00 800EE750 00000000 */   nop
/* 87C04 800EE754 C624003C */  lwc1      $f4, 0x3c($s1)
/* 87C08 800EE758 C666002C */  lwc1      $f6, 0x2c($s3)
/* 87C0C 800EE75C 862200A8 */  lh        $v0, 0xa8($s1)
/* 87C10 800EE760 46062001 */  sub.s     $f0, $f4, $f6
/* 87C14 800EE764 24420005 */  addiu     $v0, $v0, 5
/* 87C18 800EE768 44821000 */  mtc1      $v0, $f2
/* 87C1C 800EE76C 00000000 */  nop
/* 87C20 800EE770 468010A1 */  cvt.d.w   $f2, $f2
/* 87C24 800EE774 46000021 */  cvt.d.s   $f0, $f0
/* 87C28 800EE778 46200005 */  abs.d     $f0, $f0
/* 87C2C 800EE77C 4620103C */  c.lt.d    $f2, $f0
/* 87C30 800EE780 00000000 */  nop
/* 87C34 800EE784 45000018 */  bc1f      .L800EE7E8
/* 87C38 800EE788 00000000 */   nop
/* 87C3C 800EE78C 46043001 */  sub.s     $f0, $f6, $f4
/* 87C40 800EE790 3C014120 */  lui       $at, 0x4120
/* 87C44 800EE794 44811000 */  mtc1      $at, $f2
/* 87C48 800EE798 00000000 */  nop
/* 87C4C 800EE79C 46020003 */  div.s     $f0, $f0, $f2
/* 87C50 800EE7A0 46002000 */  add.s     $f0, $f4, $f0
/* 87C54 800EE7A4 0803B9FA */  j         .L800EE7E8
/* 87C58 800EE7A8 E620003C */   swc1     $f0, 0x3c($s1)
.L800EE7AC:
/* 87C5C 800EE7AC 866200B0 */  lh        $v0, 0xb0($s3)
/* 87C60 800EE7B0 C660002C */  lwc1      $f0, 0x2c($s3)
/* 87C64 800EE7B4 44821000 */  mtc1      $v0, $f2
/* 87C68 800EE7B8 00000000 */  nop
/* 87C6C 800EE7BC 468010A0 */  cvt.s.w   $f2, $f2
/* 87C70 800EE7C0 46020000 */  add.s     $f0, $f0, $f2
/* 87C74 800EE7C4 C622003C */  lwc1      $f2, 0x3c($s1)
/* 87C78 800EE7C8 46020001 */  sub.s     $f0, $f0, $f2
/* 87C7C 800EE7CC 3C013E00 */  lui       $at, 0x3e00
/* 87C80 800EE7D0 44812000 */  mtc1      $at, $f4
/* 87C84 800EE7D4 00000000 */  nop
/* 87C88 800EE7D8 46040002 */  mul.s     $f0, $f0, $f4
/* 87C8C 800EE7DC 00000000 */  nop
/* 87C90 800EE7E0 46001080 */  add.s     $f2, $f2, $f0
/* 87C94 800EE7E4 E622003C */  swc1      $f2, 0x3c($s1)
.L800EE7E8:
/* 87C98 800EE7E8 3C018010 */  lui       $at, %hi(D_800F8030)
/* 87C9C 800EE7EC C4208030 */  lwc1      $f0, %lo(D_800F8030)($at)
/* 87CA0 800EE7F0 C6220038 */  lwc1      $f2, 0x38($s1)
/* 87CA4 800EE7F4 C624003C */  lwc1      $f4, 0x3c($s1)
/* 87CA8 800EE7F8 C6260040 */  lwc1      $f6, 0x40($s1)
/* 87CAC 800EE7FC E6200018 */  swc1      $f0, 0x18($s1)
/* 87CB0 800EE800 3C018010 */  lui       $at, %hi(D_800F8034)
/* 87CB4 800EE804 C4208034 */  lwc1      $f0, %lo(D_800F8034)($at)
/* 87CB8 800EE808 C6280018 */  lwc1      $f8, 0x18($s1)
/* 87CBC 800EE80C 0000202D */  daddu     $a0, $zero, $zero
/* 87CC0 800EE810 E620000C */  swc1      $f0, 0xc($s1)
/* 87CC4 800EE814 E7A20020 */  swc1      $f2, 0x20($sp)
/* 87CC8 800EE818 E7A40024 */  swc1      $f4, 0x24($sp)
/* 87CCC 800EE81C E7A60028 */  swc1      $f6, 0x28($sp)
/* 87CD0 800EE820 E7A80010 */  swc1      $f8, 0x10($sp)
/* 87CD4 800EE824 C620000C */  lwc1      $f0, 0xc($s1)
/* 87CD8 800EE828 27A50020 */  addiu     $a1, $sp, 0x20
/* 87CDC 800EE82C E7A00014 */  swc1      $f0, 0x14($sp)
/* 87CE0 800EE830 862200A8 */  lh        $v0, 0xa8($s1)
/* 87CE4 800EE834 27A60024 */  addiu     $a2, $sp, 0x24
/* 87CE8 800EE838 44820000 */  mtc1      $v0, $f0
/* 87CEC 800EE83C 00000000 */  nop
/* 87CF0 800EE840 46800020 */  cvt.s.w   $f0, $f0
/* 87CF4 800EE844 E7A00018 */  swc1      $f0, 0x18($sp)
/* 87CF8 800EE848 862200A6 */  lh        $v0, 0xa6($s1)
/* 87CFC 800EE84C 27A70028 */  addiu     $a3, $sp, 0x28
/* 87D00 800EE850 44820000 */  mtc1      $v0, $f0
/* 87D04 800EE854 00000000 */  nop
/* 87D08 800EE858 46800020 */  cvt.s.w   $f0, $f0
/* 87D0C 800EE85C 0C0376B9 */  jal       func_800DDAE4
/* 87D10 800EE860 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 87D14 800EE864 10400010 */  beqz      $v0, .L800EE8A8
/* 87D18 800EE868 00000000 */   nop
/* 87D1C 800EE86C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 87D20 800EE870 C6260038 */  lwc1      $f6, 0x38($s1)
/* 87D24 800EE874 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 87D28 800EE878 46060001 */  sub.s     $f0, $f0, $f6
/* 87D2C 800EE87C C6240040 */  lwc1      $f4, 0x40($s1)
/* 87D30 800EE880 3C0140A0 */  lui       $at, 0x40a0
/* 87D34 800EE884 44814000 */  mtc1      $at, $f8
/* 87D38 800EE888 46041081 */  sub.s     $f2, $f2, $f4
/* 87D3C 800EE88C 46080003 */  div.s     $f0, $f0, $f8
/* 87D40 800EE890 46003180 */  add.s     $f6, $f6, $f0
/* 87D44 800EE894 46081083 */  div.s     $f2, $f2, $f8
/* 87D48 800EE898 46022100 */  add.s     $f4, $f4, $f2
/* 87D4C 800EE89C E6260038 */  swc1      $f6, 0x38($s1)
/* 87D50 800EE8A0 0803BA5A */  j         .L800EE968
/* 87D54 800EE8A4 E6240040 */   swc1     $f4, 0x40($s1)
.L800EE8A8:
/* 87D58 800EE8A8 8E250018 */  lw        $a1, 0x18($s1)
/* 87D5C 800EE8AC 8E26000C */  lw        $a2, 0xc($s1)
/* 87D60 800EE8B0 0C00EA95 */  jal       npc_move_heading
/* 87D64 800EE8B4 0220202D */   daddu    $a0, $s1, $zero
/* 87D68 800EE8B8 0803BA5A */  j         .L800EE968
/* 87D6C 800EE8BC 00000000 */   nop
.L800EE8C0:
/* 87D70 800EE8C0 0C03BD17 */  jal       clear_partner_move_history
/* 87D74 800EE8C4 0220202D */   daddu    $a0, $s1, $zero
/* 87D78 800EE8C8 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 87D7C 800EE8CC 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 87D80 800EE8D0 3C014387 */  lui       $at, 0x4387
/* 87D84 800EE8D4 44810000 */  mtc1      $at, $f0
/* 87D88 800EE8D8 AE200018 */  sw        $zero, 0x18($s1)
/* 87D8C 800EE8DC AE200014 */  sw        $zero, 0x14($s1)
/* 87D90 800EE8E0 000310C0 */  sll       $v0, $v1, 3
/* 87D94 800EE8E4 00431021 */  addu      $v0, $v0, $v1
/* 87D98 800EE8E8 00021080 */  sll       $v0, $v0, 2
/* 87D9C 800EE8EC 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* 87DA0 800EE8F0 00220821 */  addu      $at, $at, $v0
/* 87DA4 800EE8F4 8C22835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($at)
/* 87DA8 800EE8F8 AE220028 */  sw        $v0, 0x28($s1)
/* 87DAC 800EE8FC C64C006C */  lwc1      $f12, 0x6c($s2)
/* 87DB0 800EE900 46006300 */  add.s     $f12, $f12, $f0
/* 87DB4 800EE904 C66000A8 */  lwc1      $f0, 0xa8($s3)
/* 87DB8 800EE908 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 87DBC 800EE90C A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 87DC0 800EE910 3C018011 */  lui       $at, %hi(D_8010CFCA)
/* 87DC4 800EE914 A420CFCA */  sh        $zero, %lo(D_8010CFCA)($at)
/* 87DC8 800EE918 3C018011 */  lui       $at, %hi(D_8010CFCE)
/* 87DCC 800EE91C A420CFCE */  sh        $zero, %lo(D_8010CFCE)($at)
/* 87DD0 800EE920 0C00A6C9 */  jal       clamp_angle
/* 87DD4 800EE924 46006301 */   sub.s    $f12, $f12, $f0
/* 87DD8 800EE928 0803BA5A */  j         .L800EE968
/* 87DDC 800EE92C E620000C */   swc1     $f0, 0xc($s1)
glabel L800EE930_87DE0
/* 87DE0 800EE930 0220202D */  daddu     $a0, $s1, $zero
/* 87DE4 800EE934 0C03BE0B */  jal       func_800EF82C
/* 87DE8 800EE938 24050001 */   addiu    $a1, $zero, 1
/* 87DEC 800EE93C 0803BA5A */  j         .L800EE968
/* 87DF0 800EE940 00000000 */   nop
glabel L800EE944_87DF4
/* 87DF4 800EE944 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 87DF8 800EE948 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 87DFC 800EE94C 000218C0 */  sll       $v1, $v0, 3
/* 87E00 800EE950 00621821 */  addu      $v1, $v1, $v0
/* 87E04 800EE954 00031880 */  sll       $v1, $v1, 2
/* 87E08 800EE958 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0x14)
/* 87E0C 800EE95C 00431021 */  addu      $v0, $v0, $v1
/* 87E10 800EE960 8C42835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($v0)
/* 87E14 800EE964 AE220028 */  sw        $v0, 0x28($s1)
.L800EE968:
glabel L800EE968_87E18
/* 87E18 800EE968 8FBF0044 */  lw        $ra, 0x44($sp)
/* 87E1C 800EE96C 8FB40040 */  lw        $s4, 0x40($sp)
/* 87E20 800EE970 8FB3003C */  lw        $s3, 0x3c($sp)
/* 87E24 800EE974 8FB20038 */  lw        $s2, 0x38($sp)
/* 87E28 800EE978 8FB10034 */  lw        $s1, 0x34($sp)
/* 87E2C 800EE97C 8FB00030 */  lw        $s0, 0x30($sp)
/* 87E30 800EE980 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 87E34 800EE984 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 87E38 800EE988 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 87E3C 800EE98C 03E00008 */  jr        $ra
/* 87E40 800EE990 27BD0060 */   addiu    $sp, $sp, 0x60
