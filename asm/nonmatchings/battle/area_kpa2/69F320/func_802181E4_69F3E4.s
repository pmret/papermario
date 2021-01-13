.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181E4_69F3E4
/* 69F3E4 802181E4 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 69F3E8 802181E8 AFB30074 */  sw        $s3, 0x74($sp)
/* 69F3EC 802181EC 0080982D */  daddu     $s3, $a0, $zero
/* 69F3F0 802181F0 AFBF0088 */  sw        $ra, 0x88($sp)
/* 69F3F4 802181F4 AFB70084 */  sw        $s7, 0x84($sp)
/* 69F3F8 802181F8 AFB60080 */  sw        $s6, 0x80($sp)
/* 69F3FC 802181FC AFB5007C */  sw        $s5, 0x7c($sp)
/* 69F400 80218200 AFB40078 */  sw        $s4, 0x78($sp)
/* 69F404 80218204 AFB20070 */  sw        $s2, 0x70($sp)
/* 69F408 80218208 AFB1006C */  sw        $s1, 0x6c($sp)
/* 69F40C 8021820C AFB00068 */  sw        $s0, 0x68($sp)
/* 69F410 80218210 F7B800A0 */  sdc1      $f24, 0xa0($sp)
/* 69F414 80218214 F7B60098 */  sdc1      $f22, 0x98($sp)
/* 69F418 80218218 F7B40090 */  sdc1      $f20, 0x90($sp)
/* 69F41C 8021821C 8E640148 */  lw        $a0, 0x148($s3)
/* 69F420 80218220 0C09A75B */  jal       get_actor
/* 69F424 80218224 00A0802D */   daddu    $s0, $a1, $zero
/* 69F428 80218228 14400003 */  bnez      $v0, .L80218238
/* 69F42C 8021822C 0040202D */   daddu    $a0, $v0, $zero
/* 69F430 80218230 08086154 */  j         .L80218550
/* 69F434 80218234 24020002 */   addiu    $v0, $zero, 2
.L80218238:
/* 69F438 80218238 0C099117 */  jal       get_actor_part
/* 69F43C 8021823C 24050001 */   addiu    $a1, $zero, 1
/* 69F440 80218240 12000013 */  beqz      $s0, .L80218290
/* 69F444 80218244 0040A82D */   daddu    $s5, $v0, $zero
/* 69F448 80218248 0000802D */  daddu     $s0, $zero, $zero
/* 69F44C 8021824C 241100FF */  addiu     $s1, $zero, 0xff
/* 69F450 80218250 AE600074 */  sw        $zero, 0x74($s3)
/* 69F454 80218254 AE600078 */  sw        $zero, 0x78($s3)
/* 69F458 80218258 AE600070 */  sw        $zero, 0x70($s3)
/* 69F45C 8021825C 0200282D */  daddu     $a1, $s0, $zero
.L80218260:
/* 69F460 80218260 24060011 */  addiu     $a2, $zero, 0x11
/* 69F464 80218264 24070014 */  addiu     $a3, $zero, 0x14
/* 69F468 80218268 AFA00010 */  sw        $zero, 0x10($sp)
/* 69F46C 8021826C AFA00014 */  sw        $zero, 0x14($sp)
/* 69F470 80218270 AFB10018 */  sw        $s1, 0x18($sp)
/* 69F474 80218274 AFA0001C */  sw        $zero, 0x1c($sp)
/* 69F478 80218278 8EA40084 */  lw        $a0, 0x84($s5)
/* 69F47C 8021827C 0C0B79E0 */  jal       func_802DE780
/* 69F480 80218280 26100001 */   addiu    $s0, $s0, 1
/* 69F484 80218284 2A02000A */  slti      $v0, $s0, 0xa
/* 69F488 80218288 1440FFF5 */  bnez      $v0, .L80218260
/* 69F48C 8021828C 0200282D */   daddu    $a1, $s0, $zero
.L80218290:
/* 69F490 80218290 8E620074 */  lw        $v0, 0x74($s3)
/* 69F494 80218294 2444000A */  addiu     $a0, $v0, 0xa
/* 69F498 80218298 28820168 */  slti      $v0, $a0, 0x168
/* 69F49C 8021829C 14400010 */  bnez      $v0, .L802182E0
/* 69F4A0 802182A0 AE640074 */   sw       $a0, 0x74($s3)
/* 69F4A4 802182A4 3C02B60B */  lui       $v0, 0xb60b
/* 69F4A8 802182A8 344260B7 */  ori       $v0, $v0, 0x60b7
/* 69F4AC 802182AC 00820018 */  mult      $a0, $v0
/* 69F4B0 802182B0 00041FC3 */  sra       $v1, $a0, 0x1f
/* 69F4B4 802182B4 00004010 */  mfhi      $t0
/* 69F4B8 802182B8 01041021 */  addu      $v0, $t0, $a0
/* 69F4BC 802182BC 00021203 */  sra       $v0, $v0, 8
/* 69F4C0 802182C0 00431023 */  subu      $v0, $v0, $v1
/* 69F4C4 802182C4 00021840 */  sll       $v1, $v0, 1
/* 69F4C8 802182C8 00621821 */  addu      $v1, $v1, $v0
/* 69F4CC 802182CC 00031100 */  sll       $v0, $v1, 4
/* 69F4D0 802182D0 00431023 */  subu      $v0, $v0, $v1
/* 69F4D4 802182D4 000210C0 */  sll       $v0, $v0, 3
/* 69F4D8 802182D8 00821023 */  subu      $v0, $a0, $v0
/* 69F4DC 802182DC AE620074 */  sw        $v0, 0x74($s3)
.L802182E0:
/* 69F4E0 802182E0 0000882D */  daddu     $s1, $zero, $zero
/* 69F4E4 802182E4 3C128000 */  lui       $s2, 0x8000
/* 69F4E8 802182E8 0220802D */  daddu     $s0, $s1, $zero
/* 69F4EC 802182EC 3C013FF0 */  lui       $at, 0x3ff0
/* 69F4F0 802182F0 4481C800 */  mtc1      $at, $f25
/* 69F4F4 802182F4 4480C000 */  mtc1      $zero, $f24
/* 69F4F8 802182F8 3C01404C */  lui       $at, 0x404c
/* 69F4FC 802182FC 4481B800 */  mtc1      $at, $f23
/* 69F500 80218300 4480B000 */  mtc1      $zero, $f22
/* 69F504 80218304 3C0141E0 */  lui       $at, 0x41e0
/* 69F508 80218308 4481A800 */  mtc1      $at, $f21
/* 69F50C 8021830C 4480A000 */  mtc1      $zero, $f20
.L80218310:
/* 69F510 80218310 96640076 */  lhu       $a0, 0x76($s3)
/* 69F514 80218314 00902021 */  addu      $a0, $a0, $s0
/* 69F518 80218318 24840078 */  addiu     $a0, $a0, 0x78
/* 69F51C 8021831C 00042400 */  sll       $a0, $a0, 0x10
/* 69F520 80218320 0C00A4F5 */  jal       cosine
/* 69F524 80218324 00042403 */   sra      $a0, $a0, 0x10
/* 69F528 80218328 46000021 */  cvt.d.s   $f0, $f0
/* 69F52C 8021832C 46380000 */  add.d     $f0, $f0, $f24
/* 69F530 80218330 46360002 */  mul.d     $f0, $f0, $f22
/* 69F534 80218334 00000000 */  nop
/* 69F538 80218338 27A20020 */  addiu     $v0, $sp, 0x20
/* 69F53C 8021833C 4620A03E */  c.le.d    $f20, $f0
/* 69F540 80218340 00000000 */  nop
/* 69F544 80218344 45010005 */  bc1t      .L8021835C
/* 69F548 80218348 00511021 */   addu     $v0, $v0, $s1
/* 69F54C 8021834C 4620008D */  trunc.w.d $f2, $f0
/* 69F550 80218350 44031000 */  mfc1      $v1, $f2
/* 69F554 80218354 080860DD */  j         .L80218374
/* 69F558 80218358 A0430000 */   sb       $v1, ($v0)
.L8021835C:
/* 69F55C 8021835C 46340001 */  sub.d     $f0, $f0, $f20
/* 69F560 80218360 4620008D */  trunc.w.d $f2, $f0
/* 69F564 80218364 44031000 */  mfc1      $v1, $f2
/* 69F568 80218368 00000000 */  nop
/* 69F56C 8021836C 00721825 */  or        $v1, $v1, $s2
/* 69F570 80218370 A0430000 */  sb        $v1, ($v0)
.L80218374:
/* 69F574 80218374 96640076 */  lhu       $a0, 0x76($s3)
/* 69F578 80218378 00902021 */  addu      $a0, $a0, $s0
/* 69F57C 8021837C 2484003C */  addiu     $a0, $a0, 0x3c
/* 69F580 80218380 00042400 */  sll       $a0, $a0, 0x10
/* 69F584 80218384 0C00A4F5 */  jal       cosine
/* 69F588 80218388 00042403 */   sra      $a0, $a0, 0x10
/* 69F58C 8021838C 46000021 */  cvt.d.s   $f0, $f0
/* 69F590 80218390 46380000 */  add.d     $f0, $f0, $f24
/* 69F594 80218394 46360002 */  mul.d     $f0, $f0, $f22
/* 69F598 80218398 00000000 */  nop
/* 69F59C 8021839C 27A20038 */  addiu     $v0, $sp, 0x38
/* 69F5A0 802183A0 4620A03E */  c.le.d    $f20, $f0
/* 69F5A4 802183A4 00000000 */  nop
/* 69F5A8 802183A8 45010005 */  bc1t      .L802183C0
/* 69F5AC 802183AC 00511021 */   addu     $v0, $v0, $s1
/* 69F5B0 802183B0 4620008D */  trunc.w.d $f2, $f0
/* 69F5B4 802183B4 44031000 */  mfc1      $v1, $f2
/* 69F5B8 802183B8 080860F6 */  j         .L802183D8
/* 69F5BC 802183BC A0430000 */   sb       $v1, ($v0)
.L802183C0:
/* 69F5C0 802183C0 46340001 */  sub.d     $f0, $f0, $f20
/* 69F5C4 802183C4 4620008D */  trunc.w.d $f2, $f0
/* 69F5C8 802183C8 44031000 */  mfc1      $v1, $f2
/* 69F5CC 802183CC 00000000 */  nop
/* 69F5D0 802183D0 00721825 */  or        $v1, $v1, $s2
/* 69F5D4 802183D4 A0430000 */  sb        $v1, ($v0)
.L802183D8:
/* 69F5D8 802183D8 96640076 */  lhu       $a0, 0x76($s3)
/* 69F5DC 802183DC 00902021 */  addu      $a0, $a0, $s0
/* 69F5E0 802183E0 248400B4 */  addiu     $a0, $a0, 0xb4
/* 69F5E4 802183E4 00042400 */  sll       $a0, $a0, 0x10
/* 69F5E8 802183E8 0C00A4F5 */  jal       cosine
/* 69F5EC 802183EC 00042403 */   sra      $a0, $a0, 0x10
/* 69F5F0 802183F0 46000021 */  cvt.d.s   $f0, $f0
/* 69F5F4 802183F4 46380000 */  add.d     $f0, $f0, $f24
/* 69F5F8 802183F8 46360002 */  mul.d     $f0, $f0, $f22
/* 69F5FC 802183FC 00000000 */  nop
/* 69F600 80218400 27A20050 */  addiu     $v0, $sp, 0x50
/* 69F604 80218404 4620A03E */  c.le.d    $f20, $f0
/* 69F608 80218408 00000000 */  nop
/* 69F60C 8021840C 45010005 */  bc1t      .L80218424
/* 69F610 80218410 00511021 */   addu     $v0, $v0, $s1
/* 69F614 80218414 4620008D */  trunc.w.d $f2, $f0
/* 69F618 80218418 44031000 */  mfc1      $v1, $f2
/* 69F61C 8021841C 0808610F */  j         .L8021843C
/* 69F620 80218420 A0430000 */   sb       $v1, ($v0)
.L80218424:
/* 69F624 80218424 46340001 */  sub.d     $f0, $f0, $f20
/* 69F628 80218428 4620008D */  trunc.w.d $f2, $f0
/* 69F62C 8021842C 44031000 */  mfc1      $v1, $f2
/* 69F630 80218430 00000000 */  nop
/* 69F634 80218434 00721825 */  or        $v1, $v1, $s2
/* 69F638 80218438 A0430000 */  sb        $v1, ($v0)
.L8021843C:
/* 69F63C 8021843C 26310001 */  addiu     $s1, $s1, 1
/* 69F640 80218440 2A220014 */  slti      $v0, $s1, 0x14
/* 69F644 80218444 1440FFB2 */  bnez      $v0, .L80218310
/* 69F648 80218448 26100019 */   addiu    $s0, $s0, 0x19
/* 69F64C 8021844C 8EA2007C */  lw        $v0, 0x7c($s5)
/* 69F650 80218450 3C030004 */  lui       $v1, 4
/* 69F654 80218454 00431024 */  and       $v0, $v0, $v1
/* 69F658 80218458 10400025 */  beqz      $v0, .L802184F0
/* 69F65C 8021845C 0000882D */   daddu    $s1, $zero, $zero
/* 69F660 80218460 27B70020 */  addiu     $s7, $sp, 0x20
/* 69F664 80218464 27B60038 */  addiu     $s6, $sp, 0x38
/* 69F668 80218468 27B40050 */  addiu     $s4, $sp, 0x50
/* 69F66C 8021846C 241300FF */  addiu     $s3, $zero, 0xff
/* 69F670 80218470 0000802D */  daddu     $s0, $zero, $zero
.L80218474:
/* 69F674 80218474 02F11021 */  addu      $v0, $s7, $s1
/* 69F678 80218478 02D12021 */  addu      $a0, $s6, $s1
/* 69F67C 8021847C 90430000 */  lbu       $v1, ($v0)
/* 69F680 80218480 02911021 */  addu      $v0, $s4, $s1
/* 69F684 80218484 90840000 */  lbu       $a0, ($a0)
/* 69F688 80218488 90420000 */  lbu       $v0, ($v0)
/* 69F68C 8021848C 00031E00 */  sll       $v1, $v1, 0x18
/* 69F690 80218490 00042400 */  sll       $a0, $a0, 0x10
/* 69F694 80218494 00641825 */  or        $v1, $v1, $a0
/* 69F698 80218498 00021200 */  sll       $v0, $v0, 8
/* 69F69C 8021849C 00621825 */  or        $v1, $v1, $v0
/* 69F6A0 802184A0 347200FF */  ori       $s2, $v1, 0xff
/* 69F6A4 802184A4 0200282D */  daddu     $a1, $s0, $zero
.L802184A8:
/* 69F6A8 802184A8 2406000C */  addiu     $a2, $zero, 0xc
/* 69F6AC 802184AC 0220382D */  daddu     $a3, $s1, $zero
/* 69F6B0 802184B0 AFB20010 */  sw        $s2, 0x10($sp)
/* 69F6B4 802184B4 AFA00014 */  sw        $zero, 0x14($sp)
/* 69F6B8 802184B8 AFB30018 */  sw        $s3, 0x18($sp)
/* 69F6BC 802184BC AFA0001C */  sw        $zero, 0x1c($sp)
/* 69F6C0 802184C0 8EA40084 */  lw        $a0, 0x84($s5)
/* 69F6C4 802184C4 0C0B79E0 */  jal       func_802DE780
/* 69F6C8 802184C8 26100001 */   addiu    $s0, $s0, 1
/* 69F6CC 802184CC 2A02000A */  slti      $v0, $s0, 0xa
/* 69F6D0 802184D0 1440FFF5 */  bnez      $v0, .L802184A8
/* 69F6D4 802184D4 0200282D */   daddu    $a1, $s0, $zero
/* 69F6D8 802184D8 26310001 */  addiu     $s1, $s1, 1
/* 69F6DC 802184DC 2A220014 */  slti      $v0, $s1, 0x14
/* 69F6E0 802184E0 1440FFE4 */  bnez      $v0, .L80218474
/* 69F6E4 802184E4 0000802D */   daddu    $s0, $zero, $zero
/* 69F6E8 802184E8 08086154 */  j         .L80218550
/* 69F6EC 802184EC 0000102D */   daddu    $v0, $zero, $zero
.L802184F0:
/* 69F6F0 802184F0 241200FF */  addiu     $s2, $zero, 0xff
/* 69F6F4 802184F4 0240A02D */  daddu     $s4, $s2, $zero
/* 69F6F8 802184F8 0000802D */  daddu     $s0, $zero, $zero
.L802184FC:
/* 69F6FC 802184FC 0200282D */  daddu     $a1, $s0, $zero
.L80218500:
/* 69F700 80218500 2406000C */  addiu     $a2, $zero, 0xc
/* 69F704 80218504 0220382D */  daddu     $a3, $s1, $zero
/* 69F708 80218508 AFB20010 */  sw        $s2, 0x10($sp)
/* 69F70C 8021850C AFA00014 */  sw        $zero, 0x14($sp)
/* 69F710 80218510 AFB40018 */  sw        $s4, 0x18($sp)
/* 69F714 80218514 AFA0001C */  sw        $zero, 0x1c($sp)
/* 69F718 80218518 8EA40084 */  lw        $a0, 0x84($s5)
/* 69F71C 8021851C 0C0B79E0 */  jal       func_802DE780
/* 69F720 80218520 26100001 */   addiu    $s0, $s0, 1
/* 69F724 80218524 2A02000A */  slti      $v0, $s0, 0xa
/* 69F728 80218528 1440FFF5 */  bnez      $v0, .L80218500
/* 69F72C 8021852C 0200282D */   daddu    $a1, $s0, $zero
/* 69F730 80218530 26310001 */  addiu     $s1, $s1, 1
/* 69F734 80218534 2A220014 */  slti      $v0, $s1, 0x14
/* 69F738 80218538 1440FFF0 */  bnez      $v0, .L802184FC
/* 69F73C 8021853C 0000802D */   daddu    $s0, $zero, $zero
/* 69F740 80218540 0000102D */  daddu     $v0, $zero, $zero
/* 69F744 80218544 AE600074 */  sw        $zero, 0x74($s3)
/* 69F748 80218548 AE600078 */  sw        $zero, 0x78($s3)
/* 69F74C 8021854C AE600070 */  sw        $zero, 0x70($s3)
.L80218550:
/* 69F750 80218550 8FBF0088 */  lw        $ra, 0x88($sp)
/* 69F754 80218554 8FB70084 */  lw        $s7, 0x84($sp)
/* 69F758 80218558 8FB60080 */  lw        $s6, 0x80($sp)
/* 69F75C 8021855C 8FB5007C */  lw        $s5, 0x7c($sp)
/* 69F760 80218560 8FB40078 */  lw        $s4, 0x78($sp)
/* 69F764 80218564 8FB30074 */  lw        $s3, 0x74($sp)
/* 69F768 80218568 8FB20070 */  lw        $s2, 0x70($sp)
/* 69F76C 8021856C 8FB1006C */  lw        $s1, 0x6c($sp)
/* 69F770 80218570 8FB00068 */  lw        $s0, 0x68($sp)
/* 69F774 80218574 D7B800A0 */  ldc1      $f24, 0xa0($sp)
/* 69F778 80218578 D7B60098 */  ldc1      $f22, 0x98($sp)
/* 69F77C 8021857C D7B40090 */  ldc1      $f20, 0x90($sp)
/* 69F780 80218580 03E00008 */  jr        $ra
/* 69F784 80218584 27BD00A8 */   addiu    $sp, $sp, 0xa8
