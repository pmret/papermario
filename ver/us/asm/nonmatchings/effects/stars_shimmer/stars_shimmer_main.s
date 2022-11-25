.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E0044E20
.double 0.1

dlabel D_E0044E28
.double 0.005

dlabel D_E0044E30
.double 0.4

dlabel D_E0044E38
.double 0.4

dlabel jtbl_E0044E40
.word .LE0044284, .LE0044284, .LE0044344, .LE00442A8, .LE0044344, .LE0044344

dlabel D_E0044E58
.double 0.01

.section .text

glabel stars_shimmer_main
/* 354F60 E0044000 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 354F64 E0044004 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 354F68 E0044008 4485A000 */  mtc1      $a1, $f20
/* 354F6C E004400C F7B60058 */  sdc1      $f22, 0x58($sp)
/* 354F70 E0044010 4486B000 */  mtc1      $a2, $f22
/* 354F74 E0044014 AFB3003C */  sw        $s3, 0x3c($sp)
/* 354F78 E0044018 0080982D */  daddu     $s3, $a0, $zero
/* 354F7C E004401C F7B80060 */  sdc1      $f24, 0x60($sp)
/* 354F80 E0044020 4487C000 */  mtc1      $a3, $f24
/* 354F84 E0044024 27A40010 */  addiu     $a0, $sp, 0x10
/* 354F88 E0044028 AFB20038 */  sw        $s2, 0x38($sp)
/* 354F8C E004402C 8FB20098 */  lw        $s2, 0x98($sp)
/* 354F90 E0044030 3C02E004 */  lui       $v0, %hi(stars_shimmer_init)
/* 354F94 E0044034 2442441C */  addiu     $v0, $v0, %lo(stars_shimmer_init)
/* 354F98 E0044038 AFA20018 */  sw        $v0, 0x18($sp)
/* 354F9C E004403C 3C02E004 */  lui       $v0, %hi(stars_shimmer_update)
/* 354FA0 E0044040 24424424 */  addiu     $v0, $v0, %lo(stars_shimmer_update)
/* 354FA4 E0044044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 354FA8 E0044048 3C02E004 */  lui       $v0, %hi(stars_shimmer_render)
/* 354FAC E004404C 244248E4 */  addiu     $v0, $v0, %lo(stars_shimmer_render)
/* 354FB0 E0044050 AFA20020 */  sw        $v0, 0x20($sp)
/* 354FB4 E0044054 24020022 */  addiu     $v0, $zero, 0x22
/* 354FB8 E0044058 AFBF0048 */  sw        $ra, 0x48($sp)
/* 354FBC E004405C AFB50044 */  sw        $s5, 0x44($sp)
/* 354FC0 E0044060 AFB40040 */  sw        $s4, 0x40($sp)
/* 354FC4 E0044064 AFB10034 */  sw        $s1, 0x34($sp)
/* 354FC8 E0044068 AFB00030 */  sw        $s0, 0x30($sp)
/* 354FCC E004406C F7BE0078 */  sdc1      $f30, 0x78($sp)
/* 354FD0 E0044070 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 354FD4 E0044074 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 354FD8 E0044078 AFA00010 */  sw        $zero, 0x10($sp)
/* 354FDC E004407C AFA00024 */  sw        $zero, 0x24($sp)
/* 354FE0 E0044080 AFA20014 */  sw        $v0, 0x14($sp)
/* 354FE4 E0044084 0C080124 */  jal       shim_create_effect_instance
/* 354FE8 E0044088 26520001 */   addiu    $s2, $s2, 1
/* 354FEC E004408C 00122040 */  sll       $a0, $s2, 1
/* 354FF0 E0044090 00922021 */  addu      $a0, $a0, $s2
/* 354FF4 E0044094 00042080 */  sll       $a0, $a0, 2
/* 354FF8 E0044098 00922023 */  subu      $a0, $a0, $s2
/* 354FFC E004409C 00042080 */  sll       $a0, $a0, 2
/* 355000 E00440A0 0040802D */  daddu     $s0, $v0, $zero
/* 355004 E00440A4 0C08012C */  jal       shim_general_heap_malloc
/* 355008 E00440A8 AE120008 */   sw       $s2, 8($s0)
/* 35500C E00440AC 0040182D */  daddu     $v1, $v0, $zero
/* 355010 E00440B0 14600003 */  bnez      $v1, .LE00440C0
/* 355014 E00440B4 AE03000C */   sw       $v1, 0xc($s0)
.LE00440B8:
/* 355018 E00440B8 0801102E */  j         .LE00440B8
/* 35501C E00440BC 00000000 */   nop
.LE00440C0:
/* 355020 E00440C0 24020006 */  addiu     $v0, $zero, 6
/* 355024 E00440C4 56620004 */  bnel      $s3, $v0, .LE00440D8
/* 355028 E00440C8 A4600000 */   sh       $zero, ($v1)
/* 35502C E00440CC 24020001 */  addiu     $v0, $zero, 1
/* 355030 E00440D0 A4620000 */  sh        $v0, ($v1)
/* 355034 E00440D4 24130003 */  addiu     $s3, $zero, 3
.LE00440D8:
/* 355038 E00440D8 E4740004 */  swc1      $f20, 4($v1)
/* 35503C E00440DC E4760008 */  swc1      $f22, 8($v1)
/* 355040 E00440E0 E478000C */  swc1      $f24, 0xc($v1)
/* 355044 E00440E4 AC600020 */  sw        $zero, 0x20($v1)
/* 355048 E00440E8 A4730002 */  sh        $s3, 2($v1)
/* 35504C E00440EC 8FA2009C */  lw        $v0, 0x9c($sp)
/* 355050 E00440F0 24110001 */  addiu     $s1, $zero, 1
/* 355054 E00440F4 AC620024 */  sw        $v0, 0x24($v1)
/* 355058 E00440F8 0232102A */  slt       $v0, $s1, $s2
/* 35505C E00440FC 104000B8 */  beqz      $v0, .LE00443E0
/* 355060 E0044100 2463002C */   addiu    $v1, $v1, 0x2c
/* 355064 E0044104 3C15E004 */  lui       $s5, %hi(jtbl_E0044E40)
/* 355068 E0044108 26B54E40 */  addiu     $s5, $s5, %lo(jtbl_E0044E40)
/* 35506C E004410C 24700018 */  addiu     $s0, $v1, 0x18
/* 355070 E0044110 2654FFFF */  addiu     $s4, $s2, -1
/* 355074 E0044114 44940000 */  mtc1      $s4, $f0
/* 355078 E0044118 00000000 */  nop
/* 35507C E004411C 46800020 */  cvt.s.w   $f0, $f0
/* 355080 E0044120 4480D000 */  mtc1      $zero, $f26
/* 355084 E0044124 3C01E004 */  lui       $at, %hi(D_E0044E20)
/* 355088 E0044128 D43E4E20 */  ldc1      $f30, %lo(D_E0044E20)($at)
/* 35508C E004412C 3C0143B4 */  lui       $at, 0x43b4
/* 355090 E0044130 44811000 */  mtc1      $at, $f2
/* 355094 E0044134 3C01E004 */  lui       $at, %hi(D_E0044E28)
/* 355098 E0044138 D43C4E28 */  ldc1      $f28, %lo(D_E0044E28)($at)
/* 35509C E004413C 46001083 */  div.s     $f2, $f2, $f0
/* 3550A0 E0044140 E7A20028 */  swc1      $f2, 0x28($sp)
.LE0044144:
/* 3550A4 E0044144 44910000 */  mtc1      $s1, $f0
/* 3550A8 E0044148 00000000 */  nop
/* 3550AC E004414C 46800020 */  cvt.s.w   $f0, $f0
/* 3550B0 E0044150 C7AA0028 */  lwc1      $f10, 0x28($sp)
/* 3550B4 E0044154 2A620002 */  slti      $v0, $s3, 2
/* 3550B8 E0044158 46005582 */  mul.s     $f22, $f10, $f0
/* 3550BC E004415C 00000000 */  nop
/* 3550C0 E0044160 54400007 */  bnel      $v0, $zero, .LE0044180
/* 3550C4 E0044164 461AB600 */   add.s    $f24, $f22, $f26
/* 3550C8 E0044168 0C080138 */  jal       shim_rand_int
/* 3550CC E004416C 24040167 */   addiu    $a0, $zero, 0x167
/* 3550D0 E0044170 44820000 */  mtc1      $v0, $f0
/* 3550D4 E0044174 00000000 */  nop
/* 3550D8 E0044178 46800020 */  cvt.s.w   $f0, $f0
/* 3550DC E004417C 4600B600 */  add.s     $f24, $f22, $f0
.LE0044180:
/* 3550E0 E0044180 3C014120 */  lui       $at, 0x4120
/* 3550E4 E0044184 4481A000 */  mtc1      $at, $f20
/* 3550E8 E0044188 00000000 */  nop
/* 3550EC E004418C 4614B502 */  mul.s     $f20, $f22, $f20
/* 3550F0 E0044190 00000000 */  nop
/* 3550F4 E0044194 3C0142B4 */  lui       $at, 0x42b4
/* 3550F8 E0044198 44810000 */  mtc1      $at, $f0
/* 3550FC E004419C 4600C306 */  mov.s     $f12, $f24
/* 355100 E00441A0 0C080140 */  jal       shim_sin_deg
/* 355104 E00441A4 4600A501 */   sub.s    $f20, $f20, $f0
/* 355108 E00441A8 4600C306 */  mov.s     $f12, $f24
/* 35510C E00441AC 0C080144 */  jal       shim_cos_deg
/* 355110 E00441B0 46000586 */   mov.s    $f22, $f0
/* 355114 E00441B4 4600A306 */  mov.s     $f12, $f20
/* 355118 E00441B8 0C080140 */  jal       shim_sin_deg
/* 35511C E00441BC 46000506 */   mov.s    $f20, $f0
/* 355120 E00441C0 C7AA0090 */  lwc1      $f10, 0x90($sp)
/* 355124 E00441C4 460050A1 */  cvt.d.s   $f2, $f10
/* 355128 E00441C8 3C01E004 */  lui       $at, %hi(D_E0044E30)
/* 35512C E00441CC D42A4E30 */  ldc1      $f10, %lo(D_E0044E30)($at)
/* 355130 E00441D0 462A1202 */  mul.d     $f8, $f2, $f10
/* 355134 E00441D4 00000000 */  nop
/* 355138 E00441D8 463E1082 */  mul.d     $f2, $f2, $f30
/* 35513C E00441DC 00000000 */  nop
/* 355140 E00441E0 C7AA0094 */  lwc1      $f10, 0x94($sp)
/* 355144 E00441E4 46005121 */  cvt.d.s   $f4, $f10
/* 355148 E00441E8 463E2182 */  mul.d     $f6, $f4, $f30
/* 35514C E00441EC 00000000 */  nop
/* 355150 E00441F0 3C01E004 */  lui       $at, %hi(D_E0044E38)
/* 355154 E00441F4 D42A4E38 */  ldc1      $f10, %lo(D_E0044E38)($at)
/* 355158 E00441F8 462A2102 */  mul.d     $f4, $f4, $f10
/* 35515C E00441FC 00000000 */  nop
/* 355160 E0044200 46000021 */  cvt.d.s   $f0, $f0
/* 355164 E0044204 46201082 */  mul.d     $f2, $f2, $f0
/* 355168 E0044208 00000000 */  nop
/* 35516C E004420C 46203182 */  mul.d     $f6, $f6, $f0
/* 355170 E0044210 00000000 */  nop
/* 355174 E0044214 2622001E */  addiu     $v0, $s1, 0x1e
/* 355178 E0044218 AE02000C */  sw        $v0, 0xc($s0)
/* 35517C E004421C 3C013F80 */  lui       $at, 0x3f80
/* 355180 E0044220 44810000 */  mtc1      $at, $f0
/* 355184 E0044224 2622FFFF */  addiu     $v0, $s1, -1
/* 355188 E0044228 AE000008 */  sw        $zero, 8($s0)
/* 35518C E004422C E6000004 */  swc1      $f0, 4($s0)
/* 355190 E0044230 C7AA0094 */  lwc1      $f10, 0x94($sp)
/* 355194 E0044234 46224201 */  sub.d     $f8, $f8, $f2
/* 355198 E0044238 44940000 */  mtc1      $s4, $f0
/* 35519C E004423C 00000000 */  nop
/* 3551A0 E0044240 46800020 */  cvt.s.w   $f0, $f0
/* 3551A4 E0044244 46005003 */  div.s     $f0, $f10, $f0
/* 3551A8 E0044248 46262101 */  sub.d     $f4, $f4, $f6
/* 3551AC E004424C 44821000 */  mtc1      $v0, $f2
/* 3551B0 E0044250 00000000 */  nop
/* 3551B4 E0044254 468010A0 */  cvt.s.w   $f2, $f2
/* 3551B8 E0044258 2E620006 */  sltiu     $v0, $s3, 6
/* 3551BC E004425C 46020182 */  mul.s     $f6, $f0, $f2
/* 3551C0 E0044260 00000000 */  nop
/* 3551C4 E0044264 46204220 */  cvt.s.d   $f8, $f8
/* 3551C8 E0044268 10400036 */  beqz      $v0, .LE0044344
/* 3551CC E004426C 46202120 */   cvt.s.d  $f4, $f4
/* 3551D0 E0044270 00131080 */  sll       $v0, $s3, 2
/* 3551D4 E0044274 00551021 */  addu      $v0, $v0, $s5
/* 3551D8 E0044278 8C420000 */  lw        $v0, ($v0)
/* 3551DC E004427C 00400008 */  jr        $v0
/* 3551E0 E0044280 00000000 */   nop
.LE0044284:
/* 3551E4 E0044284 4608B002 */  mul.s     $f0, $f22, $f8
/* 3551E8 E0044288 00000000 */  nop
/* 3551EC E004428C 4604A082 */  mul.s     $f2, $f20, $f4
/* 3551F0 E0044290 00000000 */  nop
/* 3551F4 E0044294 AE000000 */  sw        $zero, ($s0)
/* 3551F8 E0044298 AE00FFF4 */  sw        $zero, -0xc($s0)
/* 3551FC E004429C E600FFF8 */  swc1      $f0, -8($s0)
/* 355200 E00442A0 080110F4 */  j         .LE00443D0
/* 355204 E00442A4 E602FFFC */   swc1     $f2, -4($s0)
.LE00442A8:
/* 355208 E00442A8 0C080138 */  jal       shim_rand_int
/* 35520C E00442AC 24040064 */   addiu    $a0, $zero, 0x64
/* 355210 E00442B0 C7AA0090 */  lwc1      $f10, 0x90($sp)
/* 355214 E00442B4 460AB002 */  mul.s     $f0, $f22, $f10
/* 355218 E00442B8 00000000 */  nop
/* 35521C E00442BC 44821000 */  mtc1      $v0, $f2
/* 355220 E00442C0 00000000 */  nop
/* 355224 E00442C4 468010A0 */  cvt.s.w   $f2, $f2
/* 355228 E00442C8 46020002 */  mul.s     $f0, $f0, $f2
/* 35522C E00442CC 00000000 */  nop
/* 355230 E00442D0 46000021 */  cvt.d.s   $f0, $f0
/* 355234 E00442D4 463C0002 */  mul.d     $f0, $f0, $f28
/* 355238 E00442D8 00000000 */  nop
/* 35523C E00442DC 24040064 */  addiu     $a0, $zero, 0x64
/* 355240 E00442E0 46200020 */  cvt.s.d   $f0, $f0
/* 355244 E00442E4 0C080138 */  jal       shim_rand_int
/* 355248 E00442E8 E600FFEC */   swc1     $f0, -0x14($s0)
/* 35524C E00442EC C7AA0094 */  lwc1      $f10, 0x94($sp)
/* 355250 E00442F0 460AA002 */  mul.s     $f0, $f20, $f10
/* 355254 E00442F4 00000000 */  nop
/* 355258 E00442F8 44821000 */  mtc1      $v0, $f2
/* 35525C E00442FC 00000000 */  nop
/* 355260 E0044300 468010A0 */  cvt.s.w   $f2, $f2
/* 355264 E0044304 46020002 */  mul.s     $f0, $f0, $f2
/* 355268 E0044308 00000000 */  nop
/* 35526C E004430C 8E02000C */  lw        $v0, 0xc($s0)
/* 355270 E0044310 46000021 */  cvt.d.s   $f0, $f0
/* 355274 E0044314 463C0002 */  mul.d     $f0, $f0, $f28
/* 355278 E0044318 00000000 */  nop
/* 35527C E004431C 00111840 */  sll       $v1, $s1, 1
/* 355280 E0044320 AE00FFF4 */  sw        $zero, -0xc($s0)
/* 355284 E0044324 E61AFFFC */  swc1      $f26, -4($s0)
/* 355288 E0044328 E61AFFF8 */  swc1      $f26, -8($s0)
/* 35528C E004432C E61A0000 */  swc1      $f26, ($s0)
/* 355290 E0044330 00431021 */  addu      $v0, $v0, $v1
/* 355294 E0044334 AE02000C */  sw        $v0, 0xc($s0)
/* 355298 E0044338 46200020 */  cvt.s.d   $f0, $f0
/* 35529C E004433C 080110F4 */  j         .LE00443D0
/* 3552A0 E0044340 E600FFF0 */   swc1     $f0, -0x10($s0)
.LE0044344:
/* 3552A4 E0044344 4608B002 */  mul.s     $f0, $f22, $f8
/* 3552A8 E0044348 00000000 */  nop
/* 3552AC E004434C 4608A082 */  mul.s     $f2, $f20, $f8
/* 3552B0 E0044350 00000000 */  nop
/* 3552B4 E0044354 2404000A */  addiu     $a0, $zero, 0xa
/* 3552B8 E0044358 E606FFF0 */  swc1      $f6, -0x10($s0)
/* 3552BC E004435C E600FFF8 */  swc1      $f0, -8($s0)
/* 3552C0 E0044360 0C080138 */  jal       shim_rand_int
/* 3552C4 E0044364 E602FFF4 */   swc1     $f2, -0xc($s0)
/* 3552C8 E0044368 00021023 */  negu      $v0, $v0
/* 3552CC E004436C 3C013CF5 */  lui       $at, 0x3cf5
/* 3552D0 E0044370 3421C28F */  ori       $at, $at, 0xc28f
/* 3552D4 E0044374 44811000 */  mtc1      $at, $f2
/* 3552D8 E0044378 44820000 */  mtc1      $v0, $f0
/* 3552DC E004437C 00000000 */  nop
/* 3552E0 E0044380 46800020 */  cvt.s.w   $f0, $f0
/* 3552E4 E0044384 46020002 */  mul.s     $f0, $f0, $f2
/* 3552E8 E0044388 00000000 */  nop
/* 3552EC E004438C 2404000A */  addiu     $a0, $zero, 0xa
/* 3552F0 E0044390 0C080138 */  jal       shim_rand_int
/* 3552F4 E0044394 E600FFFC */   swc1     $f0, -4($s0)
/* 3552F8 E0044398 3C013D23 */  lui       $at, 0x3d23
/* 3552FC E004439C 3421D70A */  ori       $at, $at, 0xd70a
/* 355300 E00443A0 44811000 */  mtc1      $at, $f2
/* 355304 E00443A4 44820000 */  mtc1      $v0, $f0
/* 355308 E00443A8 00000000 */  nop
/* 35530C E00443AC 46800020 */  cvt.s.w   $f0, $f0
/* 355310 E00443B0 46020002 */  mul.s     $f0, $f0, $f2
/* 355314 E00443B4 00000000 */  nop
/* 355318 E00443B8 3C01E004 */  lui       $at, %hi(D_E0044E58)
/* 35531C E00443BC D4224E58 */  ldc1      $f2, %lo(D_E0044E58)($at)
/* 355320 E00443C0 46000021 */  cvt.d.s   $f0, $f0
/* 355324 E00443C4 46220000 */  add.d     $f0, $f0, $f2
/* 355328 E00443C8 46200020 */  cvt.s.d   $f0, $f0
/* 35532C E00443CC E6000000 */  swc1      $f0, ($s0)
.LE00443D0:
/* 355330 E00443D0 26310001 */  addiu     $s1, $s1, 1
/* 355334 E00443D4 0232102A */  slt       $v0, $s1, $s2
/* 355338 E00443D8 1440FF5A */  bnez      $v0, .LE0044144
/* 35533C E00443DC 2610002C */   addiu    $s0, $s0, 0x2c
.LE00443E0:
/* 355340 E00443E0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 355344 E00443E4 8FB50044 */  lw        $s5, 0x44($sp)
/* 355348 E00443E8 8FB40040 */  lw        $s4, 0x40($sp)
/* 35534C E00443EC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 355350 E00443F0 8FB20038 */  lw        $s2, 0x38($sp)
/* 355354 E00443F4 8FB10034 */  lw        $s1, 0x34($sp)
/* 355358 E00443F8 8FB00030 */  lw        $s0, 0x30($sp)
/* 35535C E00443FC D7BE0078 */  ldc1      $f30, 0x78($sp)
/* 355360 E0044400 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 355364 E0044404 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 355368 E0044408 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 35536C E004440C D7B60058 */  ldc1      $f22, 0x58($sp)
/* 355370 E0044410 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 355374 E0044414 03E00008 */  jr        $ra
/* 355378 E0044418 27BD0080 */   addiu    $sp, $sp, 0x80
