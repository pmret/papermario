.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FD0_BAF910
/* BAF910 80241FD0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* BAF914 80241FD4 AFBF0064 */  sw        $ra, 0x64($sp)
/* BAF918 80241FD8 AFBE0060 */  sw        $fp, 0x60($sp)
/* BAF91C 80241FDC AFB7005C */  sw        $s7, 0x5c($sp)
/* BAF920 80241FE0 AFB60058 */  sw        $s6, 0x58($sp)
/* BAF924 80241FE4 AFB50054 */  sw        $s5, 0x54($sp)
/* BAF928 80241FE8 AFB40050 */  sw        $s4, 0x50($sp)
/* BAF92C 80241FEC AFB3004C */  sw        $s3, 0x4c($sp)
/* BAF930 80241FF0 AFB20048 */  sw        $s2, 0x48($sp)
/* BAF934 80241FF4 AFB10044 */  sw        $s1, 0x44($sp)
/* BAF938 80241FF8 AFB00040 */  sw        $s0, 0x40($sp)
/* BAF93C 80241FFC F7B80078 */  sdc1      $f24, 0x78($sp)
/* BAF940 80242000 F7B60070 */  sdc1      $f22, 0x70($sp)
/* BAF944 80242004 F7B40068 */  sdc1      $f20, 0x68($sp)
/* BAF948 80242008 AFA40080 */  sw        $a0, 0x80($sp)
/* BAF94C 8024200C 8C960148 */  lw        $s6, 0x148($a0)
/* BAF950 80242010 00C0902D */  daddu     $s2, $a2, $zero
/* BAF954 80242014 86C40008 */  lh        $a0, 8($s6)
/* BAF958 80242018 0C00EABB */  jal       get_npc_unsafe
/* BAF95C 8024201C 0000B82D */   daddu    $s7, $zero, $zero
/* BAF960 80242020 0040882D */  daddu     $s1, $v0, $zero
/* BAF964 80242024 9622008E */  lhu       $v0, 0x8e($s1)
/* BAF968 80242028 2442FFFF */  addiu     $v0, $v0, -1
/* BAF96C 8024202C A622008E */  sh        $v0, 0x8e($s1)
/* BAF970 80242030 00021400 */  sll       $v0, $v0, 0x10
/* BAF974 80242034 8EC30090 */  lw        $v1, 0x90($s6)
/* BAF978 80242038 00021403 */  sra       $v0, $v0, 0x10
/* BAF97C 8024203C 0062182A */  slt       $v1, $v1, $v0
/* BAF980 80242040 14600005 */  bnez      $v1, .L80242058
/* BAF984 80242044 02E0F02D */   daddu    $fp, $s7, $zero
/* BAF988 80242048 8EC20000 */  lw        $v0, ($s6)
/* BAF98C 8024204C 3C031F10 */  lui       $v1, 0x1f10
/* BAF990 80242050 00431025 */  or        $v0, $v0, $v1
/* BAF994 80242054 AEC20000 */  sw        $v0, ($s6)
.L80242058:
/* BAF998 80242058 8622008E */  lh        $v0, 0x8e($s1)
/* BAF99C 8024205C 1440025D */  bnez      $v0, .L802429D4
/* BAF9A0 80242060 00000000 */   nop      
/* BAF9A4 80242064 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAF9A8 80242068 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAF9AC 8024206C 0C00A6C9 */  jal       clamp_angle
/* BAF9B0 80242070 C44C00A8 */   lwc1     $f12, 0xa8($v0)
/* BAF9B4 80242074 3C014334 */  lui       $at, 0x4334
/* BAF9B8 80242078 44811000 */  mtc1      $at, $f2
/* BAF9BC 8024207C 00000000 */  nop       
/* BAF9C0 80242080 4602003C */  c.lt.s    $f0, $f2
/* BAF9C4 80242084 00000000 */  nop       
/* BAF9C8 80242088 45000011 */  bc1f      .L802420D0
/* BAF9CC 8024208C 00000000 */   nop      
/* BAF9D0 80242090 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* BAF9D4 80242094 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* BAF9D8 80242098 3C0142B4 */  lui       $at, 0x42b4
/* BAF9DC 8024209C 44816000 */  mtc1      $at, $f12
/* BAF9E0 802420A0 00031080 */  sll       $v0, $v1, 2
/* BAF9E4 802420A4 00431021 */  addu      $v0, $v0, $v1
/* BAF9E8 802420A8 00021080 */  sll       $v0, $v0, 2
/* BAF9EC 802420AC 00431023 */  subu      $v0, $v0, $v1
/* BAF9F0 802420B0 000218C0 */  sll       $v1, $v0, 3
/* BAF9F4 802420B4 00431021 */  addu      $v0, $v0, $v1
/* BAF9F8 802420B8 000210C0 */  sll       $v0, $v0, 3
/* BAF9FC 802420BC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* BAFA00 802420C0 00220821 */  addu      $at, $at, $v0
/* BAFA04 802420C4 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* BAFA08 802420C8 08090843 */  j         .L8024210C
/* BAFA0C 802420CC 460C0301 */   sub.s    $f12, $f0, $f12
.L802420D0:
/* BAFA10 802420D0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* BAFA14 802420D4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* BAFA18 802420D8 3C0142B4 */  lui       $at, 0x42b4
/* BAFA1C 802420DC 44816000 */  mtc1      $at, $f12
/* BAFA20 802420E0 00031080 */  sll       $v0, $v1, 2
/* BAFA24 802420E4 00431021 */  addu      $v0, $v0, $v1
/* BAFA28 802420E8 00021080 */  sll       $v0, $v0, 2
/* BAFA2C 802420EC 00431023 */  subu      $v0, $v0, $v1
/* BAFA30 802420F0 000218C0 */  sll       $v1, $v0, 3
/* BAFA34 802420F4 00431021 */  addu      $v0, $v0, $v1
/* BAFA38 802420F8 000210C0 */  sll       $v0, $v0, 3
/* BAFA3C 802420FC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* BAFA40 80242100 00220821 */  addu      $at, $at, $v0
/* BAFA44 80242104 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* BAFA48 80242108 460C0300 */  add.s     $f12, $f0, $f12
.L8024210C:
/* BAFA4C 8024210C 0C00A6C9 */  jal       clamp_angle
/* BAFA50 80242110 00000000 */   nop      
/* BAFA54 80242114 46000586 */  mov.s     $f22, $f0
/* BAFA58 80242118 3C014334 */  lui       $at, 0x4334
/* BAFA5C 8024211C 44816000 */  mtc1      $at, $f12
/* BAFA60 80242120 0C00A6C9 */  jal       clamp_angle
/* BAFA64 80242124 460CB300 */   add.s    $f12, $f22, $f12
/* BAFA68 80242128 8EC20088 */  lw        $v0, 0x88($s6)
/* BAFA6C 8024212C 14400010 */  bnez      $v0, .L80242170
/* BAFA70 80242130 46000606 */   mov.s    $f24, $f0
/* BAFA74 80242134 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAFA78 80242138 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAFA7C 8024213C 804300B4 */  lb        $v1, 0xb4($v0)
/* BAFA80 80242140 3C014200 */  lui       $at, 0x4200
/* BAFA84 80242144 4481A000 */  mtc1      $at, $f20
/* BAFA88 80242148 10600016 */  beqz      $v1, .L802421A4
/* BAFA8C 8024214C 24020001 */   addiu    $v0, $zero, 1
/* BAFA90 80242150 3C0142C8 */  lui       $at, 0x42c8
/* BAFA94 80242154 4481A000 */  mtc1      $at, $f20
/* BAFA98 80242158 14620013 */  bne       $v1, $v0, .L802421A8
/* BAFA9C 8024215C 26300038 */   addiu    $s0, $s1, 0x38
/* BAFAA0 80242160 3C0142B4 */  lui       $at, 0x42b4
/* BAFAA4 80242164 4481A000 */  mtc1      $at, $f20
/* BAFAA8 80242168 0809086B */  j         .L802421AC
/* BAFAAC 8024216C 0200202D */   daddu    $a0, $s0, $zero
.L80242170:
/* BAFAB0 80242170 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAFAB4 80242174 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAFAB8 80242178 804300B4 */  lb        $v1, 0xb4($v0)
/* BAFABC 8024217C 3C014218 */  lui       $at, 0x4218
/* BAFAC0 80242180 4481A000 */  mtc1      $at, $f20
/* BAFAC4 80242184 10600007 */  beqz      $v1, .L802421A4
/* BAFAC8 80242188 24020001 */   addiu    $v0, $zero, 1
/* BAFACC 8024218C 3C0142B4 */  lui       $at, 0x42b4
/* BAFAD0 80242190 4481A000 */  mtc1      $at, $f20
/* BAFAD4 80242194 14620004 */  bne       $v1, $v0, .L802421A8
/* BAFAD8 80242198 26300038 */   addiu    $s0, $s1, 0x38
/* BAFADC 8024219C 3C014296 */  lui       $at, 0x4296
/* BAFAE0 802421A0 4481A000 */  mtc1      $at, $f20
.L802421A4:
/* BAFAE4 802421A4 26300038 */  addiu     $s0, $s1, 0x38
.L802421A8:
/* BAFAE8 802421A8 0200202D */  daddu     $a0, $s0, $zero
.L802421AC:
/* BAFAEC 802421AC 3C15800F */  lui       $s5, %hi(gPlayerStatusPtr)
/* BAFAF0 802421B0 26B57B30 */  addiu     $s5, $s5, %lo(gPlayerStatusPtr)
/* BAFAF4 802421B4 4407C000 */  mfc1      $a3, $f24
/* BAFAF8 802421B8 862200A6 */  lh        $v0, 0xa6($s1)
/* BAFAFC 802421BC 8EA30000 */  lw        $v1, ($s5)
/* BAFB00 802421C0 44824000 */  mtc1      $v0, $f8
/* BAFB04 802421C4 00000000 */  nop       
/* BAFB08 802421C8 46804220 */  cvt.s.w   $f8, $f8
/* BAFB0C 802421CC C4600028 */  lwc1      $f0, 0x28($v1)
/* BAFB10 802421D0 44064000 */  mfc1      $a2, $f8
/* BAFB14 802421D4 26330040 */  addiu     $s3, $s1, 0x40
/* BAFB18 802421D8 E6200038 */  swc1      $f0, 0x38($s1)
/* BAFB1C 802421DC C4600030 */  lwc1      $f0, 0x30($v1)
/* BAFB20 802421E0 0260282D */  daddu     $a1, $s3, $zero
/* BAFB24 802421E4 0C00A7E7 */  jal       add_vec2D_polar
/* BAFB28 802421E8 E6200040 */   swc1     $f0, 0x40($s1)
/* BAFB2C 802421EC 862200A6 */  lh        $v0, 0xa6($s1)
/* BAFB30 802421F0 44820000 */  mtc1      $v0, $f0
/* BAFB34 802421F4 00000000 */  nop       
/* BAFB38 802421F8 46800020 */  cvt.s.w   $f0, $f0
/* BAFB3C 802421FC 4600A000 */  add.s     $f0, $f20, $f0
/* BAFB40 80242200 4406B000 */  mfc1      $a2, $f22
/* BAFB44 80242204 44050000 */  mfc1      $a1, $f0
/* BAFB48 80242208 0C00EA95 */  jal       npc_move_heading
/* BAFB4C 8024220C 0220202D */   daddu    $a0, $s1, $zero
/* BAFB50 80242210 8EC20088 */  lw        $v0, 0x88($s6)
/* BAFB54 80242214 1440005D */  bnez      $v0, .L8024238C
/* BAFB58 80242218 00000000 */   nop      
/* BAFB5C 8024221C C6200038 */  lwc1      $f0, 0x38($s1)
/* BAFB60 80242220 3C018024 */  lui       $at, %hi(D_80245490)
/* BAFB64 80242224 D4245490 */  ldc1      $f4, %lo(D_80245490)($at)
/* BAFB68 80242228 46000021 */  cvt.d.s   $f0, $f0
/* BAFB6C 8024222C 4620203C */  c.lt.d    $f4, $f0
/* BAFB70 80242230 00000000 */  nop       
/* BAFB74 80242234 45000005 */  bc1f      .L8024224C
/* BAFB78 80242238 00000000 */   nop      
/* BAFB7C 8024223C 3C0143BE */  lui       $at, 0x43be
/* BAFB80 80242240 44810000 */  mtc1      $at, $f0
/* BAFB84 80242244 00000000 */  nop       
/* BAFB88 80242248 E6200038 */  swc1      $f0, 0x38($s1)
.L8024224C:
/* BAFB8C 8024224C C6200038 */  lwc1      $f0, 0x38($s1)
/* BAFB90 80242250 3C018024 */  lui       $at, %hi(D_80245498)
/* BAFB94 80242254 D4225498 */  ldc1      $f2, %lo(D_80245498)($at)
/* BAFB98 80242258 46000021 */  cvt.d.s   $f0, $f0
/* BAFB9C 8024225C 4622003C */  c.lt.d    $f0, $f2
/* BAFBA0 80242260 00000000 */  nop       
/* BAFBA4 80242264 45000005 */  bc1f      .L8024227C
/* BAFBA8 80242268 00000000 */   nop      
/* BAFBAC 8024226C 3C01C3BE */  lui       $at, 0xc3be
/* BAFBB0 80242270 44810000 */  mtc1      $at, $f0
/* BAFBB4 80242274 00000000 */  nop       
/* BAFBB8 80242278 E6200038 */  swc1      $f0, 0x38($s1)
.L8024227C:
/* BAFBBC 8024227C C6200040 */  lwc1      $f0, 0x40($s1)
/* BAFBC0 80242280 46000021 */  cvt.d.s   $f0, $f0
/* BAFBC4 80242284 4620203C */  c.lt.d    $f4, $f0
/* BAFBC8 80242288 00000000 */  nop       
/* BAFBCC 8024228C 45000005 */  bc1f      .L802422A4
/* BAFBD0 80242290 00000000 */   nop      
/* BAFBD4 80242294 3C0143BE */  lui       $at, 0x43be
/* BAFBD8 80242298 44810000 */  mtc1      $at, $f0
/* BAFBDC 8024229C 00000000 */  nop       
/* BAFBE0 802422A0 E6200040 */  swc1      $f0, 0x40($s1)
.L802422A4:
/* BAFBE4 802422A4 C6200040 */  lwc1      $f0, 0x40($s1)
/* BAFBE8 802422A8 46000021 */  cvt.d.s   $f0, $f0
/* BAFBEC 802422AC 4622003C */  c.lt.d    $f0, $f2
/* BAFBF0 802422B0 00000000 */  nop       
/* BAFBF4 802422B4 45000005 */  bc1f      .L802422CC
/* BAFBF8 802422B8 00000000 */   nop      
/* BAFBFC 802422BC 3C01C3BE */  lui       $at, 0xc3be
/* BAFC00 802422C0 44810000 */  mtc1      $at, $f0
/* BAFC04 802422C4 00000000 */  nop       
/* BAFC08 802422C8 E6200040 */  swc1      $f0, 0x40($s1)
.L802422CC:
/* BAFC0C 802422CC C6220038 */  lwc1      $f2, 0x38($s1)
/* BAFC10 802422D0 46021082 */  mul.s     $f2, $f2, $f2
/* BAFC14 802422D4 00000000 */  nop       
/* BAFC18 802422D8 C6200040 */  lwc1      $f0, 0x40($s1)
/* BAFC1C 802422DC 46000002 */  mul.s     $f0, $f0, $f0
/* BAFC20 802422E0 00000000 */  nop       
/* BAFC24 802422E4 46001300 */  add.s     $f12, $f2, $f0
/* BAFC28 802422E8 46006004 */  sqrt.s    $f0, $f12
/* BAFC2C 802422EC 46000032 */  c.eq.s    $f0, $f0
/* BAFC30 802422F0 00000000 */  nop       
/* BAFC34 802422F4 45010003 */  bc1t      .L80242304
/* BAFC38 802422F8 00000000 */   nop      
/* BAFC3C 802422FC 0C0187BC */  jal       sqrtf
/* BAFC40 80242300 00000000 */   nop      
.L80242304:
/* BAFC44 80242304 8E260038 */  lw        $a2, 0x38($s1)
/* BAFC48 80242308 8E270040 */  lw        $a3, 0x40($s1)
/* BAFC4C 8024230C 4480A000 */  mtc1      $zero, $f20
/* BAFC50 80242310 E7A00038 */  swc1      $f0, 0x38($sp)
/* BAFC54 80242314 4600A306 */  mov.s     $f12, $f20
/* BAFC58 80242318 0C00A720 */  jal       atan2
/* BAFC5C 8024231C 4600A386 */   mov.s    $f14, $f20
/* BAFC60 80242320 46000586 */  mov.s     $f22, $f0
/* BAFC64 80242324 C7A20038 */  lwc1      $f2, 0x38($sp)
/* BAFC68 80242328 3C018024 */  lui       $at, %hi(D_802454A0)
/* BAFC6C 8024232C D42054A0 */  ldc1      $f0, %lo(D_802454A0)($at)
/* BAFC70 80242330 460010A1 */  cvt.d.s   $f2, $f2
/* BAFC74 80242334 4620103C */  c.lt.d    $f2, $f0
/* BAFC78 80242338 00000000 */  nop       
/* BAFC7C 8024233C 45000004 */  bc1f      .L80242350
/* BAFC80 80242340 0200202D */   daddu    $a0, $s0, $zero
/* BAFC84 80242344 3C064398 */  lui       $a2, 0x4398
/* BAFC88 80242348 080908DC */  j         .L80242370
/* BAFC8C 8024234C 34C68000 */   ori      $a2, $a2, 0x8000
.L80242350:
/* BAFC90 80242350 3C018024 */  lui       $at, %hi(D_802454A8)
/* BAFC94 80242354 D42054A8 */  ldc1      $f0, %lo(D_802454A8)($at)
/* BAFC98 80242358 4622003C */  c.lt.d    $f0, $f2
/* BAFC9C 8024235C 00000000 */  nop       
/* BAFCA0 80242360 450000FA */  bc1f      .L8024274C
/* BAFCA4 80242364 00000000 */   nop      
/* BAFCA8 80242368 3C0643BB */  lui       $a2, 0x43bb
/* BAFCAC 8024236C 34C68000 */  ori       $a2, $a2, 0x8000
.L80242370:
/* BAFCB0 80242370 4407B000 */  mfc1      $a3, $f22
/* BAFCB4 80242374 0260282D */  daddu     $a1, $s3, $zero
/* BAFCB8 80242378 E6340038 */  swc1      $f20, 0x38($s1)
/* BAFCBC 8024237C 0C00A7E7 */  jal       add_vec2D_polar
/* BAFCC0 80242380 E6340040 */   swc1     $f20, 0x40($s1)
/* BAFCC4 80242384 080909D3 */  j         .L8024274C
/* BAFCC8 80242388 00000000 */   nop      
.L8024238C:
/* BAFCCC 8024238C 8E220000 */  lw        $v0, ($s1)
/* BAFCD0 80242390 30420040 */  andi      $v0, $v0, 0x40
/* BAFCD4 80242394 144000B0 */  bnez      $v0, .L80242658
/* BAFCD8 80242398 27A50020 */   addiu    $a1, $sp, 0x20
/* BAFCDC 8024239C 27B40020 */  addiu     $s4, $sp, 0x20
/* BAFCE0 802423A0 0280282D */  daddu     $a1, $s4, $zero
/* BAFCE4 802423A4 27B30024 */  addiu     $s3, $sp, 0x24
/* BAFCE8 802423A8 8EA20000 */  lw        $v0, ($s5)
/* BAFCEC 802423AC 3C014032 */  lui       $at, 0x4032
/* BAFCF0 802423B0 44811800 */  mtc1      $at, $f3
/* BAFCF4 802423B4 44801000 */  mtc1      $zero, $f2
/* BAFCF8 802423B8 C440002C */  lwc1      $f0, 0x2c($v0)
/* BAFCFC 802423BC C4460028 */  lwc1      $f6, 0x28($v0)
/* BAFD00 802423C0 C4440030 */  lwc1      $f4, 0x30($v0)
/* BAFD04 802423C4 46000021 */  cvt.d.s   $f0, $f0
/* BAFD08 802423C8 46220000 */  add.d     $f0, $f0, $f2
/* BAFD0C 802423CC E7A60020 */  swc1      $f6, 0x20($sp)
/* BAFD10 802423D0 E7A40028 */  swc1      $f4, 0x28($sp)
/* BAFD14 802423D4 46200020 */  cvt.s.d   $f0, $f0
/* BAFD18 802423D8 E7A00024 */  swc1      $f0, 0x24($sp)
/* BAFD1C 802423DC E7B40010 */  swc1      $f20, 0x10($sp)
/* BAFD20 802423E0 E7B60014 */  swc1      $f22, 0x14($sp)
/* BAFD24 802423E4 862200A8 */  lh        $v0, 0xa8($s1)
/* BAFD28 802423E8 0260302D */  daddu     $a2, $s3, $zero
/* BAFD2C 802423EC 44820000 */  mtc1      $v0, $f0
/* BAFD30 802423F0 00000000 */  nop       
/* BAFD34 802423F4 46800020 */  cvt.s.w   $f0, $f0
/* BAFD38 802423F8 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAFD3C 802423FC 862200A6 */  lh        $v0, 0xa6($s1)
/* BAFD40 80242400 27B00028 */  addiu     $s0, $sp, 0x28
/* BAFD44 80242404 44820000 */  mtc1      $v0, $f0
/* BAFD48 80242408 00000000 */  nop       
/* BAFD4C 8024240C 46800020 */  cvt.s.w   $f0, $f0
/* BAFD50 80242410 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BAFD54 80242414 8E240080 */  lw        $a0, 0x80($s1)
/* BAFD58 80242418 0C037711 */  jal       func_800DDC44
/* BAFD5C 8024241C 0200382D */   daddu    $a3, $s0, $zero
/* BAFD60 80242420 104000CA */  beqz      $v0, .L8024274C
/* BAFD64 80242424 0280282D */   daddu    $a1, $s4, $zero
/* BAFD68 80242428 8EA20000 */  lw        $v0, ($s5)
/* BAFD6C 8024242C 3C018024 */  lui       $at, %hi(D_802454B0)
/* BAFD70 80242430 D42254B0 */  ldc1      $f2, %lo(D_802454B0)($at)
/* BAFD74 80242434 C440002C */  lwc1      $f0, 0x2c($v0)
/* BAFD78 80242438 C4460028 */  lwc1      $f6, 0x28($v0)
/* BAFD7C 8024243C C4440030 */  lwc1      $f4, 0x30($v0)
/* BAFD80 80242440 46000021 */  cvt.d.s   $f0, $f0
/* BAFD84 80242444 46220000 */  add.d     $f0, $f0, $f2
/* BAFD88 80242448 E7A60020 */  swc1      $f6, 0x20($sp)
/* BAFD8C 8024244C E7A40028 */  swc1      $f4, 0x28($sp)
/* BAFD90 80242450 46200020 */  cvt.s.d   $f0, $f0
/* BAFD94 80242454 E7A00024 */  swc1      $f0, 0x24($sp)
/* BAFD98 80242458 E7B40010 */  swc1      $f20, 0x10($sp)
/* BAFD9C 8024245C E7B60014 */  swc1      $f22, 0x14($sp)
/* BAFDA0 80242460 862200A8 */  lh        $v0, 0xa8($s1)
/* BAFDA4 80242464 44820000 */  mtc1      $v0, $f0
/* BAFDA8 80242468 00000000 */  nop       
/* BAFDAC 8024246C 46800020 */  cvt.s.w   $f0, $f0
/* BAFDB0 80242470 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAFDB4 80242474 862200A6 */  lh        $v0, 0xa6($s1)
/* BAFDB8 80242478 0260302D */  daddu     $a2, $s3, $zero
/* BAFDBC 8024247C 44820000 */  mtc1      $v0, $f0
/* BAFDC0 80242480 00000000 */  nop       
/* BAFDC4 80242484 46800020 */  cvt.s.w   $f0, $f0
/* BAFDC8 80242488 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BAFDCC 8024248C 8E240080 */  lw        $a0, 0x80($s1)
/* BAFDD0 80242490 0C037711 */  jal       func_800DDC44
/* BAFDD4 80242494 0200382D */   daddu    $a3, $s0, $zero
/* BAFDD8 80242498 27A5002C */  addiu     $a1, $sp, 0x2c
/* BAFDDC 8024249C 27A60030 */  addiu     $a2, $sp, 0x30
/* BAFDE0 802424A0 27A70034 */  addiu     $a3, $sp, 0x34
/* BAFDE4 802424A4 27A30038 */  addiu     $v1, $sp, 0x38
/* BAFDE8 802424A8 C6220038 */  lwc1      $f2, 0x38($s1)
/* BAFDEC 802424AC C620003C */  lwc1      $f0, 0x3c($s1)
/* BAFDF0 802424B0 3C014348 */  lui       $at, 0x4348
/* BAFDF4 802424B4 44813000 */  mtc1      $at, $f6
/* BAFDF8 802424B8 46000021 */  cvt.d.s   $f0, $f0
/* BAFDFC 802424BC E7A2002C */  swc1      $f2, 0x2c($sp)
/* BAFE00 802424C0 3C014059 */  lui       $at, 0x4059
/* BAFE04 802424C4 44811800 */  mtc1      $at, $f3
/* BAFE08 802424C8 44801000 */  mtc1      $zero, $f2
/* BAFE0C 802424CC C6240040 */  lwc1      $f4, 0x40($s1)
/* BAFE10 802424D0 46220000 */  add.d     $f0, $f0, $f2
/* BAFE14 802424D4 E7A60038 */  swc1      $f6, 0x38($sp)
/* BAFE18 802424D8 E7A40034 */  swc1      $f4, 0x34($sp)
/* BAFE1C 802424DC 46200020 */  cvt.s.d   $f0, $f0
/* BAFE20 802424E0 E7A00030 */  swc1      $f0, 0x30($sp)
/* BAFE24 802424E4 AFA30010 */  sw        $v1, 0x10($sp)
/* BAFE28 802424E8 8E240080 */  lw        $a0, 0x80($s1)
/* BAFE2C 802424EC 0C0372DF */  jal       func_800DCB7C
/* BAFE30 802424F0 0040802D */   daddu    $s0, $v0, $zero
/* BAFE34 802424F4 1600001C */  bnez      $s0, .L80242568
/* BAFE38 802424F8 00000000 */   nop      
/* BAFE3C 802424FC 1040001A */  beqz      $v0, .L80242568
/* BAFE40 80242500 00000000 */   nop      
/* BAFE44 80242504 C7A20038 */  lwc1      $f2, 0x38($sp)
/* BAFE48 80242508 3C014054 */  lui       $at, 0x4054
/* BAFE4C 8024250C 44810800 */  mtc1      $at, $f1
/* BAFE50 80242510 44800000 */  mtc1      $zero, $f0
/* BAFE54 80242514 460010A1 */  cvt.d.s   $f2, $f2
/* BAFE58 80242518 4622003C */  c.lt.d    $f0, $f2
/* BAFE5C 8024251C 00000000 */  nop       
/* BAFE60 80242520 45000011 */  bc1f      .L80242568
/* BAFE64 80242524 00000000 */   nop      
/* BAFE68 80242528 3C01405E */  lui       $at, 0x405e
/* BAFE6C 8024252C 44810800 */  mtc1      $at, $f1
/* BAFE70 80242530 44800000 */  mtc1      $zero, $f0
/* BAFE74 80242534 00000000 */  nop       
/* BAFE78 80242538 4620103C */  c.lt.d    $f2, $f0
/* BAFE7C 8024253C 00000000 */  nop       
/* BAFE80 80242540 45000009 */  bc1f      .L80242568
/* BAFE84 80242544 00000000 */   nop      
/* BAFE88 80242548 C622003C */  lwc1      $f2, 0x3c($s1)
/* BAFE8C 8024254C C7A00030 */  lwc1      $f0, 0x30($sp)
/* BAFE90 80242550 46001032 */  c.eq.s    $f2, $f0
/* BAFE94 80242554 00000000 */  nop       
/* BAFE98 80242558 45010003 */  bc1t      .L80242568
/* BAFE9C 8024255C 00000000 */   nop      
/* BAFEA0 80242560 080909D3 */  j         .L8024274C
/* BAFEA4 80242564 241E0001 */   addiu    $fp, $zero, 1
.L80242568:
/* BAFEA8 80242568 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* BAFEAC 8024256C 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* BAFEB0 80242570 8E020000 */  lw        $v0, ($s0)
/* BAFEB4 80242574 3C014024 */  lui       $at, 0x4024
/* BAFEB8 80242578 44811800 */  mtc1      $at, $f3
/* BAFEBC 8024257C 44801000 */  mtc1      $zero, $f2
/* BAFEC0 80242580 C440002C */  lwc1      $f0, 0x2c($v0)
/* BAFEC4 80242584 C4460028 */  lwc1      $f6, 0x28($v0)
/* BAFEC8 80242588 C4440030 */  lwc1      $f4, 0x30($v0)
/* BAFECC 8024258C 46000021 */  cvt.d.s   $f0, $f0
/* BAFED0 80242590 46220000 */  add.d     $f0, $f0, $f2
/* BAFED4 80242594 E7A60020 */  swc1      $f6, 0x20($sp)
/* BAFED8 80242598 E7A40028 */  swc1      $f4, 0x28($sp)
/* BAFEDC 8024259C 46200020 */  cvt.s.d   $f0, $f0
/* BAFEE0 802425A0 E7A00024 */  swc1      $f0, 0x24($sp)
/* BAFEE4 802425A4 E7B40010 */  swc1      $f20, 0x10($sp)
/* BAFEE8 802425A8 E7B60014 */  swc1      $f22, 0x14($sp)
/* BAFEEC 802425AC 862200A8 */  lh        $v0, 0xa8($s1)
/* BAFEF0 802425B0 27A50020 */  addiu     $a1, $sp, 0x20
/* BAFEF4 802425B4 44820000 */  mtc1      $v0, $f0
/* BAFEF8 802425B8 00000000 */  nop       
/* BAFEFC 802425BC 46800020 */  cvt.s.w   $f0, $f0
/* BAFF00 802425C0 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAFF04 802425C4 862200A6 */  lh        $v0, 0xa6($s1)
/* BAFF08 802425C8 27A60024 */  addiu     $a2, $sp, 0x24
/* BAFF0C 802425CC 44820000 */  mtc1      $v0, $f0
/* BAFF10 802425D0 00000000 */  nop       
/* BAFF14 802425D4 46800020 */  cvt.s.w   $f0, $f0
/* BAFF18 802425D8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BAFF1C 802425DC 8E240080 */  lw        $a0, 0x80($s1)
/* BAFF20 802425E0 0C037711 */  jal       func_800DDC44
/* BAFF24 802425E4 27A70028 */   addiu    $a3, $sp, 0x28
/* BAFF28 802425E8 8FA60020 */  lw        $a2, 0x20($sp)
/* BAFF2C 802425EC 8E020000 */  lw        $v0, ($s0)
/* BAFF30 802425F0 8FA70028 */  lw        $a3, 0x28($sp)
/* BAFF34 802425F4 C44C0028 */  lwc1      $f12, 0x28($v0)
/* BAFF38 802425F8 C44E0030 */  lwc1      $f14, 0x30($v0)
/* BAFF3C 802425FC 0C00A7B5 */  jal       dist2D
/* BAFF40 80242600 24170001 */   addiu    $s7, $zero, 1
/* BAFF44 80242604 46000506 */  mov.s     $f20, $f0
/* BAFF48 80242608 8E030000 */  lw        $v1, ($s0)
/* BAFF4C 8024260C 862200A6 */  lh        $v0, 0xa6($s1)
/* BAFF50 80242610 4407C000 */  mfc1      $a3, $f24
/* BAFF54 80242614 44824000 */  mtc1      $v0, $f8
/* BAFF58 80242618 00000000 */  nop       
/* BAFF5C 8024261C 46804220 */  cvt.s.w   $f8, $f8
/* BAFF60 80242620 C4600028 */  lwc1      $f0, 0x28($v1)
/* BAFF64 80242624 44064000 */  mfc1      $a2, $f8
/* BAFF68 80242628 26240038 */  addiu     $a0, $s1, 0x38
/* BAFF6C 8024262C E6200038 */  swc1      $f0, 0x38($s1)
/* BAFF70 80242630 C4600030 */  lwc1      $f0, 0x30($v1)
/* BAFF74 80242634 26250040 */  addiu     $a1, $s1, 0x40
/* BAFF78 80242638 0C00A7E7 */  jal       add_vec2D_polar
/* BAFF7C 8024263C E6200040 */   swc1     $f0, 0x40($s1)
/* BAFF80 80242640 862200A6 */  lh        $v0, 0xa6($s1)
/* BAFF84 80242644 44820000 */  mtc1      $v0, $f0
/* BAFF88 80242648 00000000 */  nop       
/* BAFF8C 8024264C 46800020 */  cvt.s.w   $f0, $f0
/* BAFF90 80242650 080909CF */  j         .L8024273C
/* BAFF94 80242654 4600A500 */   add.s    $f20, $f20, $f0
.L80242658:
/* BAFF98 80242658 8EA20000 */  lw        $v0, ($s5)
/* BAFF9C 8024265C 3C014032 */  lui       $at, 0x4032
/* BAFFA0 80242660 44811800 */  mtc1      $at, $f3
/* BAFFA4 80242664 44801000 */  mtc1      $zero, $f2
/* BAFFA8 80242668 C440002C */  lwc1      $f0, 0x2c($v0)
/* BAFFAC 8024266C C4460028 */  lwc1      $f6, 0x28($v0)
/* BAFFB0 80242670 C4440030 */  lwc1      $f4, 0x30($v0)
/* BAFFB4 80242674 46000021 */  cvt.d.s   $f0, $f0
/* BAFFB8 80242678 46220000 */  add.d     $f0, $f0, $f2
/* BAFFBC 8024267C E7A60020 */  swc1      $f6, 0x20($sp)
/* BAFFC0 80242680 E7A40028 */  swc1      $f4, 0x28($sp)
/* BAFFC4 80242684 46200020 */  cvt.s.d   $f0, $f0
/* BAFFC8 80242688 E7A00024 */  swc1      $f0, 0x24($sp)
/* BAFFCC 8024268C E7B40010 */  swc1      $f20, 0x10($sp)
/* BAFFD0 80242690 E7B60014 */  swc1      $f22, 0x14($sp)
/* BAFFD4 80242694 862200A8 */  lh        $v0, 0xa8($s1)
/* BAFFD8 80242698 44820000 */  mtc1      $v0, $f0
/* BAFFDC 8024269C 00000000 */  nop       
/* BAFFE0 802426A0 46800020 */  cvt.s.w   $f0, $f0
/* BAFFE4 802426A4 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAFFE8 802426A8 862200A6 */  lh        $v0, 0xa6($s1)
/* BAFFEC 802426AC 27A60024 */  addiu     $a2, $sp, 0x24
/* BAFFF0 802426B0 44820000 */  mtc1      $v0, $f0
/* BAFFF4 802426B4 00000000 */  nop       
/* BAFFF8 802426B8 46800020 */  cvt.s.w   $f0, $f0
/* BAFFFC 802426BC E7A0001C */  swc1      $f0, 0x1c($sp)
/* BB0000 802426C0 8E240080 */  lw        $a0, 0x80($s1)
/* BB0004 802426C4 0C037711 */  jal       func_800DDC44
/* BB0008 802426C8 27A70028 */   addiu    $a3, $sp, 0x28
/* BB000C 802426CC 1040001F */  beqz      $v0, .L8024274C
/* BB0010 802426D0 00000000 */   nop      
/* BB0014 802426D4 8FA60020 */  lw        $a2, 0x20($sp)
/* BB0018 802426D8 8EA20000 */  lw        $v0, ($s5)
/* BB001C 802426DC 8FA70028 */  lw        $a3, 0x28($sp)
/* BB0020 802426E0 C44C0028 */  lwc1      $f12, 0x28($v0)
/* BB0024 802426E4 0C00A7B5 */  jal       dist2D
/* BB0028 802426E8 C44E0030 */   lwc1     $f14, 0x30($v0)
/* BB002C 802426EC 46000506 */  mov.s     $f20, $f0
/* BB0030 802426F0 8EA30000 */  lw        $v1, ($s5)
/* BB0034 802426F4 862200A6 */  lh        $v0, 0xa6($s1)
/* BB0038 802426F8 4407C000 */  mfc1      $a3, $f24
/* BB003C 802426FC 44824000 */  mtc1      $v0, $f8
/* BB0040 80242700 00000000 */  nop       
/* BB0044 80242704 46804220 */  cvt.s.w   $f8, $f8
/* BB0048 80242708 C4600028 */  lwc1      $f0, 0x28($v1)
/* BB004C 8024270C 44064000 */  mfc1      $a2, $f8
/* BB0050 80242710 0200202D */  daddu     $a0, $s0, $zero
/* BB0054 80242714 E6200038 */  swc1      $f0, 0x38($s1)
/* BB0058 80242718 C4600030 */  lwc1      $f0, 0x30($v1)
/* BB005C 8024271C 0260282D */  daddu     $a1, $s3, $zero
/* BB0060 80242720 0C00A7E7 */  jal       add_vec2D_polar
/* BB0064 80242724 E6200040 */   swc1     $f0, 0x40($s1)
/* BB0068 80242728 862200A6 */  lh        $v0, 0xa6($s1)
/* BB006C 8024272C 44820000 */  mtc1      $v0, $f0
/* BB0070 80242730 00000000 */  nop       
/* BB0074 80242734 46800020 */  cvt.s.w   $f0, $f0
/* BB0078 80242738 4600A500 */  add.s     $f20, $f20, $f0
.L8024273C:
/* BB007C 8024273C 4406B000 */  mfc1      $a2, $f22
/* BB0080 80242740 4405A000 */  mfc1      $a1, $f20
/* BB0084 80242744 0C00EA95 */  jal       npc_move_heading
/* BB0088 80242748 0220202D */   daddu    $a0, $s1, $zero
.L8024274C:
/* BB008C 8024274C C6400008 */  lwc1      $f0, 8($s2)
/* BB0090 80242750 46800020 */  cvt.s.w   $f0, $f0
/* BB0094 80242754 44050000 */  mfc1      $a1, $f0
/* BB0098 80242758 C640000C */  lwc1      $f0, 0xc($s2)
/* BB009C 8024275C 46800020 */  cvt.s.w   $f0, $f0
/* BB00A0 80242760 44060000 */  mfc1      $a2, $f0
/* BB00A4 80242764 C6200040 */  lwc1      $f0, 0x40($s1)
/* BB00A8 80242768 26300038 */  addiu     $s0, $s1, 0x38
/* BB00AC 8024276C E7A00010 */  swc1      $f0, 0x10($sp)
/* BB00B0 80242770 C6400010 */  lwc1      $f0, 0x10($s2)
/* BB00B4 80242774 46800020 */  cvt.s.w   $f0, $f0
/* BB00B8 80242778 E7A00014 */  swc1      $f0, 0x14($sp)
/* BB00BC 8024277C C6400014 */  lwc1      $f0, 0x14($s2)
/* BB00C0 80242780 46800020 */  cvt.s.w   $f0, $f0
/* BB00C4 80242784 E7A00018 */  swc1      $f0, 0x18($sp)
/* BB00C8 80242788 8E440004 */  lw        $a0, 4($s2)
/* BB00CC 8024278C 8E270038 */  lw        $a3, 0x38($s1)
/* BB00D0 80242790 0C0123F5 */  jal       is_point_within_region
/* BB00D4 80242794 26330040 */   addiu    $s3, $s1, 0x40
/* BB00D8 80242798 1040005A */  beqz      $v0, .L80242904
/* BB00DC 8024279C 00000000 */   nop      
/* BB00E0 802427A0 8E430004 */  lw        $v1, 4($s2)
/* BB00E4 802427A4 10600005 */  beqz      $v1, .L802427BC
/* BB00E8 802427A8 24020001 */   addiu    $v0, $zero, 1
/* BB00EC 802427AC 10620029 */  beq       $v1, $v0, .L80242854
/* BB00F0 802427B0 00000000 */   nop      
/* BB00F4 802427B4 08090A41 */  j         .L80242904
/* BB00F8 802427B8 00000000 */   nop      
.L802427BC:
/* BB00FC 802427BC C6480008 */  lwc1      $f8, 8($s2)
/* BB0100 802427C0 46804220 */  cvt.s.w   $f8, $f8
/* BB0104 802427C4 44064000 */  mfc1      $a2, $f8
/* BB0108 802427C8 C648000C */  lwc1      $f8, 0xc($s2)
/* BB010C 802427CC 46804220 */  cvt.s.w   $f8, $f8
/* BB0110 802427D0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BB0114 802427D4 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BB0118 802427D8 44074000 */  mfc1      $a3, $f8
/* BB011C 802427DC 0C00A7B5 */  jal       dist2D
/* BB0120 802427E0 00000000 */   nop      
/* BB0124 802427E4 C6420010 */  lwc1      $f2, 0x10($s2)
/* BB0128 802427E8 468010A0 */  cvt.s.w   $f2, $f2
/* BB012C 802427EC 4600103C */  c.lt.s    $f2, $f0
/* BB0130 802427F0 00000000 */  nop       
/* BB0134 802427F4 45000043 */  bc1f      .L80242904
/* BB0138 802427F8 E7A00038 */   swc1     $f0, 0x38($sp)
/* BB013C 802427FC C64C0008 */  lwc1      $f12, 8($s2)
/* BB0140 80242800 46806320 */  cvt.s.w   $f12, $f12
/* BB0144 80242804 8E260038 */  lw        $a2, 0x38($s1)
/* BB0148 80242808 8E270040 */  lw        $a3, 0x40($s1)
/* BB014C 8024280C C64E000C */  lwc1      $f14, 0xc($s2)
/* BB0150 80242810 0C00A720 */  jal       atan2
/* BB0154 80242814 468073A0 */   cvt.s.w  $f14, $f14
/* BB0158 80242818 0200202D */  daddu     $a0, $s0, $zero
/* BB015C 8024281C 44070000 */  mfc1      $a3, $f0
/* BB0160 80242820 C6400008 */  lwc1      $f0, 8($s2)
/* BB0164 80242824 46800020 */  cvt.s.w   $f0, $f0
/* BB0168 80242828 E6200038 */  swc1      $f0, 0x38($s1)
/* BB016C 8024282C C640000C */  lwc1      $f0, 0xc($s2)
/* BB0170 80242830 46800020 */  cvt.s.w   $f0, $f0
/* BB0174 80242834 E6200040 */  swc1      $f0, 0x40($s1)
/* BB0178 80242838 C6480010 */  lwc1      $f8, 0x10($s2)
/* BB017C 8024283C 46804220 */  cvt.s.w   $f8, $f8
/* BB0180 80242840 44064000 */  mfc1      $a2, $f8
/* BB0184 80242844 0C00A7E7 */  jal       add_vec2D_polar
/* BB0188 80242848 0260282D */   daddu    $a1, $s3, $zero
/* BB018C 8024284C 08090A41 */  j         .L80242904
/* BB0190 80242850 00000000 */   nop      
.L80242854:
/* BB0194 80242854 8E420008 */  lw        $v0, 8($s2)
/* BB0198 80242858 8E430010 */  lw        $v1, 0x10($s2)
/* BB019C 8024285C C6200038 */  lwc1      $f0, 0x38($s1)
/* BB01A0 80242860 00431021 */  addu      $v0, $v0, $v1
/* BB01A4 80242864 44821000 */  mtc1      $v0, $f2
/* BB01A8 80242868 00000000 */  nop       
/* BB01AC 8024286C 468010A0 */  cvt.s.w   $f2, $f2
/* BB01B0 80242870 4600103C */  c.lt.s    $f2, $f0
/* BB01B4 80242874 00000000 */  nop       
/* BB01B8 80242878 45030001 */  bc1tl     .L80242880
/* BB01BC 8024287C E6220038 */   swc1     $f2, 0x38($s1)
.L80242880:
/* BB01C0 80242880 8E420008 */  lw        $v0, 8($s2)
/* BB01C4 80242884 8E430010 */  lw        $v1, 0x10($s2)
/* BB01C8 80242888 C6200038 */  lwc1      $f0, 0x38($s1)
/* BB01CC 8024288C 00431023 */  subu      $v0, $v0, $v1
/* BB01D0 80242890 44821000 */  mtc1      $v0, $f2
/* BB01D4 80242894 00000000 */  nop       
/* BB01D8 80242898 468010A0 */  cvt.s.w   $f2, $f2
/* BB01DC 8024289C 4602003C */  c.lt.s    $f0, $f2
/* BB01E0 802428A0 00000000 */  nop       
/* BB01E4 802428A4 45030001 */  bc1tl     .L802428AC
/* BB01E8 802428A8 E6220038 */   swc1     $f2, 0x38($s1)
.L802428AC:
/* BB01EC 802428AC 8E42000C */  lw        $v0, 0xc($s2)
/* BB01F0 802428B0 8E430014 */  lw        $v1, 0x14($s2)
/* BB01F4 802428B4 C6200040 */  lwc1      $f0, 0x40($s1)
/* BB01F8 802428B8 00431021 */  addu      $v0, $v0, $v1
/* BB01FC 802428BC 44821000 */  mtc1      $v0, $f2
/* BB0200 802428C0 00000000 */  nop       
/* BB0204 802428C4 468010A0 */  cvt.s.w   $f2, $f2
/* BB0208 802428C8 4600103C */  c.lt.s    $f2, $f0
/* BB020C 802428CC 00000000 */  nop       
/* BB0210 802428D0 45030001 */  bc1tl     .L802428D8
/* BB0214 802428D4 E6220040 */   swc1     $f2, 0x40($s1)
.L802428D8:
/* BB0218 802428D8 8E42000C */  lw        $v0, 0xc($s2)
/* BB021C 802428DC 8E430014 */  lw        $v1, 0x14($s2)
/* BB0220 802428E0 C6200040 */  lwc1      $f0, 0x40($s1)
/* BB0224 802428E4 00431023 */  subu      $v0, $v0, $v1
/* BB0228 802428E8 44821000 */  mtc1      $v0, $f2
/* BB022C 802428EC 00000000 */  nop       
/* BB0230 802428F0 468010A0 */  cvt.s.w   $f2, $f2
/* BB0234 802428F4 4602003C */  c.lt.s    $f0, $f2
/* BB0238 802428F8 00000000 */  nop       
/* BB023C 802428FC 45030001 */  bc1tl     .L80242904
/* BB0240 80242900 E6220040 */   swc1     $f2, 0x40($s1)
.L80242904:
/* BB0244 80242904 16E0001F */  bnez      $s7, .L80242984
/* BB0248 80242908 00000000 */   nop      
/* BB024C 8024290C 8E220000 */  lw        $v0, ($s1)
/* BB0250 80242910 30420008 */  andi      $v0, $v0, 8
/* BB0254 80242914 10400003 */  beqz      $v0, .L80242924
/* BB0258 80242918 27A50020 */   addiu    $a1, $sp, 0x20
/* BB025C 8024291C 13C00019 */  beqz      $fp, .L80242984
/* BB0260 80242920 00000000 */   nop      
.L80242924:
/* BB0264 80242924 27A60024 */  addiu     $a2, $sp, 0x24
/* BB0268 80242928 27A20038 */  addiu     $v0, $sp, 0x38
/* BB026C 8024292C C6220038 */  lwc1      $f2, 0x38($s1)
/* BB0270 80242930 C620003C */  lwc1      $f0, 0x3c($s1)
/* BB0274 80242934 3C0143C8 */  lui       $at, 0x43c8
/* BB0278 80242938 44813000 */  mtc1      $at, $f6
/* BB027C 8024293C 46000021 */  cvt.d.s   $f0, $f0
/* BB0280 80242940 E7A20020 */  swc1      $f2, 0x20($sp)
/* BB0284 80242944 3C018024 */  lui       $at, %hi(D_802454B8)
/* BB0288 80242948 D42254B8 */  ldc1      $f2, %lo(D_802454B8)($at)
/* BB028C 8024294C C6240040 */  lwc1      $f4, 0x40($s1)
/* BB0290 80242950 46220000 */  add.d     $f0, $f0, $f2
/* BB0294 80242954 E7A60038 */  swc1      $f6, 0x38($sp)
/* BB0298 80242958 E7A40028 */  swc1      $f4, 0x28($sp)
/* BB029C 8024295C 46200020 */  cvt.s.d   $f0, $f0
/* BB02A0 80242960 E7A00024 */  swc1      $f0, 0x24($sp)
/* BB02A4 80242964 AFA20010 */  sw        $v0, 0x10($sp)
/* BB02A8 80242968 8E240080 */  lw        $a0, 0x80($s1)
/* BB02AC 8024296C 0C0372DF */  jal       func_800DCB7C
/* BB02B0 80242970 27A70028 */   addiu    $a3, $sp, 0x28
/* BB02B4 80242974 10400003 */  beqz      $v0, .L80242984
/* BB02B8 80242978 00000000 */   nop      
/* BB02BC 8024297C C7A00024 */  lwc1      $f0, 0x24($sp)
/* BB02C0 80242980 E620003C */  swc1      $f0, 0x3c($s1)
.L80242984:
/* BB02C4 80242984 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BB02C8 80242988 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BB02CC 8024298C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BB02D0 80242990 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BB02D4 80242994 8C460028 */  lw        $a2, 0x28($v0)
/* BB02D8 80242998 0C00A720 */  jal       atan2
/* BB02DC 8024299C 8C470030 */   lw       $a3, 0x30($v0)
/* BB02E0 802429A0 0220202D */  daddu     $a0, $s1, $zero
/* BB02E4 802429A4 24050321 */  addiu     $a1, $zero, 0x321
/* BB02E8 802429A8 0000302D */  daddu     $a2, $zero, $zero
/* BB02EC 802429AC 0C012530 */  jal       func_800494C0
/* BB02F0 802429B0 E620000C */   swc1     $f0, 0xc($s1)
/* BB02F4 802429B4 8EC200CC */  lw        $v0, 0xcc($s6)
/* BB02F8 802429B8 8C420024 */  lw        $v0, 0x24($v0)
/* BB02FC 802429BC AE220028 */  sw        $v0, 0x28($s1)
/* BB0300 802429C0 96C20096 */  lhu       $v0, 0x96($s6)
/* BB0304 802429C4 A622008E */  sh        $v0, 0x8e($s1)
/* BB0308 802429C8 8FA80080 */  lw        $t0, 0x80($sp)
/* BB030C 802429CC 2402000B */  addiu     $v0, $zero, 0xb
/* BB0310 802429D0 AD020070 */  sw        $v0, 0x70($t0)
.L802429D4:
/* BB0314 802429D4 8FBF0064 */  lw        $ra, 0x64($sp)
/* BB0318 802429D8 8FBE0060 */  lw        $fp, 0x60($sp)
/* BB031C 802429DC 8FB7005C */  lw        $s7, 0x5c($sp)
/* BB0320 802429E0 8FB60058 */  lw        $s6, 0x58($sp)
/* BB0324 802429E4 8FB50054 */  lw        $s5, 0x54($sp)
/* BB0328 802429E8 8FB40050 */  lw        $s4, 0x50($sp)
/* BB032C 802429EC 8FB3004C */  lw        $s3, 0x4c($sp)
/* BB0330 802429F0 8FB20048 */  lw        $s2, 0x48($sp)
/* BB0334 802429F4 8FB10044 */  lw        $s1, 0x44($sp)
/* BB0338 802429F8 8FB00040 */  lw        $s0, 0x40($sp)
/* BB033C 802429FC D7B80078 */  ldc1      $f24, 0x78($sp)
/* BB0340 80242A00 D7B60070 */  ldc1      $f22, 0x70($sp)
/* BB0344 80242A04 D7B40068 */  ldc1      $f20, 0x68($sp)
/* BB0348 80242A08 03E00008 */  jr        $ra
/* BB034C 80242A0C 27BD0080 */   addiu    $sp, $sp, 0x80
