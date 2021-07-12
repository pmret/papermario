.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218070_557450
/* 557450 80218070 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 557454 80218074 AFB00030 */  sw        $s0, 0x30($sp)
/* 557458 80218078 0080802D */  daddu     $s0, $a0, $zero
/* 55745C 8021807C AFBF0044 */  sw        $ra, 0x44($sp)
/* 557460 80218080 AFB40040 */  sw        $s4, 0x40($sp)
/* 557464 80218084 AFB3003C */  sw        $s3, 0x3c($sp)
/* 557468 80218088 AFB20038 */  sw        $s2, 0x38($sp)
/* 55746C 8021808C AFB10034 */  sw        $s1, 0x34($sp)
/* 557470 80218090 F7BE0070 */  sdc1      $f30, 0x70($sp)
/* 557474 80218094 F7BC0068 */  sdc1      $f28, 0x68($sp)
/* 557478 80218098 F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 55747C 8021809C F7B80058 */  sdc1      $f24, 0x58($sp)
/* 557480 802180A0 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 557484 802180A4 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 557488 802180A8 8E02000C */  lw        $v0, 0xc($s0)
/* 55748C 802180AC 0C0B1EAF */  jal       get_variable
/* 557490 802180B0 8C450000 */   lw       $a1, ($v0)
/* 557494 802180B4 8E040148 */  lw        $a0, 0x148($s0)
/* 557498 802180B8 0C09A75B */  jal       get_actor
/* 55749C 802180BC 0040982D */   daddu    $s3, $v0, $zero
/* 5574A0 802180C0 0040902D */  daddu     $s2, $v0, $zero
/* 5574A4 802180C4 16400005 */  bnez      $s2, .L802180DC
/* 5574A8 802180C8 24040001 */   addiu    $a0, $zero, 1
/* 5574AC 802180CC 0C04E035 */  jal       set_screen_overlay_alpha
/* 5574B0 802180D0 0000282D */   daddu    $a1, $zero, $zero
/* 5574B4 802180D4 08086116 */  j         .L80218458
/* 5574B8 802180D8 0000102D */   daddu    $v0, $zero, $zero
.L802180DC:
/* 5574BC 802180DC 12600002 */  beqz      $s3, .L802180E8
/* 5574C0 802180E0 2651000C */   addiu    $s1, $s2, 0xc
/* 5574C4 802180E4 8E74000C */  lw        $s4, 0xc($s3)
.L802180E8:
/* 5574C8 802180E8 0240202D */  daddu     $a0, $s2, $zero
/* 5574CC 802180EC C6420160 */  lwc1      $f2, 0x160($s2)
/* 5574D0 802180F0 C640018C */  lwc1      $f0, 0x18c($s2)
/* 5574D4 802180F4 C65E0144 */  lwc1      $f30, 0x144($s2)
/* 5574D8 802180F8 C6460148 */  lwc1      $f6, 0x148($s2)
/* 5574DC 802180FC 24050001 */  addiu     $a1, $zero, 1
/* 5574E0 80218100 E7A60024 */  swc1      $f6, 0x24($sp)
/* 5574E4 80218104 C646014C */  lwc1      $f6, 0x14c($s2)
/* 5574E8 80218108 E7A60028 */  swc1      $f6, 0x28($sp)
/* 5574EC 8021810C C65C015C */  lwc1      $f28, 0x15c($s2)
/* 5574F0 80218110 C65A0164 */  lwc1      $f26, 0x164($s2)
/* 5574F4 80218114 0C099117 */  jal       get_actor_part
/* 5574F8 80218118 46001500 */   add.s    $f20, $f2, $f0
/* 5574FC 8021811C 3C03006D */  lui       $v1, 0x6d
/* 557500 80218120 8C420088 */  lw        $v0, 0x88($v0)
/* 557504 80218124 3463000C */  ori       $v1, $v1, 0xc
/* 557508 80218128 14430002 */  bne       $v0, $v1, .L80218134
/* 55750C 8021812C 24050001 */   addiu    $a1, $zero, 1
/* 557510 80218130 0000282D */  daddu     $a1, $zero, $zero
.L80218134:
/* 557514 80218134 27A60018 */  addiu     $a2, $sp, 0x18
/* 557518 80218138 8E4301F4 */  lw        $v1, 0x1f4($s2)
/* 55751C 8021813C 27A20020 */  addiu     $v0, $sp, 0x20
/* 557520 80218140 AFA20010 */  sw        $v0, 0x10($sp)
/* 557524 80218144 8C640084 */  lw        $a0, 0x84($v1)
/* 557528 80218148 0C0B7A37 */  jal       func_802DE8DC
/* 55752C 8021814C 27A7001C */   addiu    $a3, $sp, 0x1c
/* 557530 80218150 C7B80018 */  lwc1      $f24, 0x18($sp)
/* 557534 80218154 4680C620 */  cvt.s.w   $f24, $f24
/* 557538 80218158 3C018023 */  lui       $at, %hi(D_8022EB70_56DF50)
/* 55753C 8021815C D420EB70 */  ldc1      $f0, %lo(D_8022EB70_56DF50)($at)
/* 557540 80218160 4600C621 */  cvt.d.s   $f24, $f24
/* 557544 80218164 4620C602 */  mul.d     $f24, $f24, $f0
/* 557548 80218168 00000000 */  nop
/* 55754C 8021816C 8FA2001C */  lw        $v0, 0x1c($sp)
/* 557550 80218170 24420014 */  addiu     $v0, $v0, 0x14
/* 557554 80218174 4482B000 */  mtc1      $v0, $f22
/* 557558 80218178 00000000 */  nop
/* 55755C 8021817C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 557560 80218180 4600B5A1 */  cvt.d.s   $f22, $f22
/* 557564 80218184 4620B582 */  mul.d     $f22, $f22, $f0
/* 557568 80218188 00000000 */  nop
/* 55756C 8021818C 4600A306 */  mov.s     $f12, $f20
/* 557570 80218190 AFA2001C */  sw        $v0, 0x1c($sp)
/* 557574 80218194 4620C620 */  cvt.s.d   $f24, $f24
/* 557578 80218198 0C00A8D4 */  jal       cos_deg
/* 55757C 8021819C 4620B5A0 */   cvt.s.d  $f22, $f22
/* 557580 802181A0 3C018023 */  lui       $at, %hi(D_8022EB78_56DF58)
/* 557584 802181A4 D422EB78 */  ldc1      $f2, %lo(D_8022EB78_56DF58)($at)
/* 557588 802181A8 4600E321 */  cvt.d.s   $f12, $f28
/* 55758C 802181AC 46226300 */  add.d     $f12, $f12, $f2
/* 557590 802181B0 4600C602 */  mul.s     $f24, $f24, $f0
/* 557594 802181B4 00000000 */  nop
/* 557598 802181B8 0C00A8BB */  jal       sin_deg
/* 55759C 802181BC 46206320 */   cvt.s.d  $f12, $f12
/* 5575A0 802181C0 4600B582 */  mul.s     $f22, $f22, $f0
/* 5575A4 802181C4 00000000 */  nop
/* 5575A8 802181C8 0C00A8D4 */  jal       cos_deg
/* 5575AC 802181CC 4600D306 */   mov.s    $f12, $f26
/* 5575B0 802181D0 4600D306 */  mov.s     $f12, $f26
/* 5575B4 802181D4 0C00A8BB */  jal       sin_deg
/* 5575B8 802181D8 46000506 */   mov.s    $f20, $f0
/* 5575BC 802181DC 4614C502 */  mul.s     $f20, $f24, $f20
/* 5575C0 802181E0 00000000 */  nop
/* 5575C4 802181E4 4600B002 */  mul.s     $f0, $f22, $f0
/* 5575C8 802181E8 00000000 */  nop
/* 5575CC 802181EC 4600A500 */  add.s     $f20, $f20, $f0
/* 5575D0 802181F0 4600A18D */  trunc.w.s $f6, $f20
/* 5575D4 802181F4 E7A60018 */  swc1      $f6, 0x18($sp)
/* 5575D8 802181F8 0C00A8BB */  jal       sin_deg
/* 5575DC 802181FC 4600D306 */   mov.s    $f12, $f26
/* 5575E0 80218200 4600D306 */  mov.s     $f12, $f26
/* 5575E4 80218204 0C00A8D4 */  jal       cos_deg
/* 5575E8 80218208 46000506 */   mov.s    $f20, $f0
/* 5575EC 8021820C 4600A507 */  neg.s     $f20, $f20
/* 5575F0 80218210 4614C602 */  mul.s     $f24, $f24, $f20
/* 5575F4 80218214 00000000 */  nop
/* 5575F8 80218218 4600B582 */  mul.s     $f22, $f22, $f0
/* 5575FC 8021821C 00000000 */  nop
/* 557600 80218220 8E23007C */  lw        $v1, 0x7c($s1)
/* 557604 80218224 4616C600 */  add.s     $f24, $f24, $f22
/* 557608 80218228 2C62000C */  sltiu     $v0, $v1, 0xc
/* 55760C 8021822C 4600C18D */  trunc.w.s $f6, $f24
/* 557610 80218230 E7A6001C */  swc1      $f6, 0x1c($sp)
/* 557614 80218234 10400044 */  beqz      $v0, .L80218348
/* 557618 80218238 00031080 */   sll      $v0, $v1, 2
/* 55761C 8021823C 3C018023 */  lui       $at, %hi(jtbl_8022EB80_56DF60)
/* 557620 80218240 00220821 */  addu      $at, $at, $v0
/* 557624 80218244 8C22EB80 */  lw        $v0, %lo(jtbl_8022EB80_56DF60)($at)
/* 557628 80218248 00400008 */  jr        $v0
/* 55762C 8021824C 00000000 */   nop
glabel L80218250_557630
/* 557630 80218250 0220202D */  daddu     $a0, $s1, $zero
/* 557634 80218254 0C08600E */  jal       func_80218038_557418
/* 557638 80218258 24050122 */   addiu    $a1, $zero, 0x122
/* 55763C 8021825C 080860D3 */  j         .L8021834C
/* 557640 80218260 00000000 */   nop
glabel L80218264_557644
/* 557644 80218264 0220202D */  daddu     $a0, $s1, $zero
/* 557648 80218268 080860B6 */  j         .L802182D8
/* 55764C 8021826C 240500FA */   addiu    $a1, $zero, 0xfa
glabel L80218270_557650
/* 557650 80218270 0220202D */  daddu     $a0, $s1, $zero
/* 557654 80218274 080860B6 */  j         .L802182D8
/* 557658 80218278 240500F0 */   addiu    $a1, $zero, 0xf0
glabel L8021827C_55765C
/* 55765C 8021827C 0220202D */  daddu     $a0, $s1, $zero
/* 557660 80218280 080860B6 */  j         .L802182D8
/* 557664 80218284 240500E6 */   addiu    $a1, $zero, 0xe6
glabel L80218288_557668
/* 557668 80218288 0220202D */  daddu     $a0, $s1, $zero
/* 55766C 8021828C 080860B6 */  j         .L802182D8
/* 557670 80218290 240500DC */   addiu    $a1, $zero, 0xdc
glabel L80218294_557674
/* 557674 80218294 0220202D */  daddu     $a0, $s1, $zero
/* 557678 80218298 080860B6 */  j         .L802182D8
/* 55767C 8021829C 240500D2 */   addiu    $a1, $zero, 0xd2
glabel L802182A0_557680
/* 557680 802182A0 0220202D */  daddu     $a0, $s1, $zero
/* 557684 802182A4 080860B6 */  j         .L802182D8
/* 557688 802182A8 240500B4 */   addiu    $a1, $zero, 0xb4
glabel L802182AC_55768C
/* 55768C 802182AC 0220202D */  daddu     $a0, $s1, $zero
/* 557690 802182B0 080860B6 */  j         .L802182D8
/* 557694 802182B4 2405008C */   addiu    $a1, $zero, 0x8c
glabel L802182B8_557698
/* 557698 802182B8 0220202D */  daddu     $a0, $s1, $zero
/* 55769C 802182BC 080860B6 */  j         .L802182D8
/* 5576A0 802182C0 24050064 */   addiu    $a1, $zero, 0x64
glabel L802182C4_5576A4
/* 5576A4 802182C4 0220202D */  daddu     $a0, $s1, $zero
/* 5576A8 802182C8 080860B6 */  j         .L802182D8
/* 5576AC 802182CC 24050046 */   addiu    $a1, $zero, 0x46
glabel L802182D0_5576B0
/* 5576B0 802182D0 0220202D */  daddu     $a0, $s1, $zero
/* 5576B4 802182D4 24050028 */  addiu     $a1, $zero, 0x28
.L802182D8:
/* 5576B8 802182D8 0C08600E */  jal       func_80218038_557418
/* 5576BC 802182DC 00000000 */   nop
/* 5576C0 802182E0 24044000 */  addiu     $a0, $zero, 0x4000
/* 5576C4 802182E4 0C00A67F */  jal       rand_int
/* 5576C8 802182E8 0040802D */   daddu    $s0, $v0, $zero
/* 5576CC 802182EC 3C036666 */  lui       $v1, 0x6666
/* 5576D0 802182F0 34636667 */  ori       $v1, $v1, 0x6667
/* 5576D4 802182F4 00430018 */  mult      $v0, $v1
/* 5576D8 802182F8 00021FC3 */  sra       $v1, $v0, 0x1f
/* 5576DC 802182FC 00004010 */  mfhi      $t0
/* 5576E0 80218300 00082043 */  sra       $a0, $t0, 1
/* 5576E4 80218304 00832023 */  subu      $a0, $a0, $v1
/* 5576E8 80218308 00041880 */  sll       $v1, $a0, 2
/* 5576EC 8021830C 00641821 */  addu      $v1, $v1, $a0
/* 5576F0 80218310 00431023 */  subu      $v0, $v0, $v1
/* 5576F4 80218314 080860D3 */  j         .L8021834C
/* 5576F8 80218318 02021021 */   addu     $v0, $s0, $v0
glabel L8021831C_5576FC
/* 5576FC 8021831C 0220202D */  daddu     $a0, $s1, $zero
/* 557700 80218320 0C08600E */  jal       func_80218038_557418
/* 557704 80218324 24050014 */   addiu    $a1, $zero, 0x14
/* 557708 80218328 0220202D */  daddu     $a0, $s1, $zero
/* 55770C 8021832C 0C08600E */  jal       func_80218038_557418
/* 557710 80218330 24050014 */   addiu    $a1, $zero, 0x14
/* 557714 80218334 0220202D */  daddu     $a0, $s1, $zero
/* 557718 80218338 0C08600E */  jal       func_80218038_557418
/* 55771C 8021833C 24050014 */   addiu    $a1, $zero, 0x14
/* 557720 80218340 080860D3 */  j         .L8021834C
/* 557724 80218344 00000000 */   nop
.L80218348:
/* 557728 80218348 0000102D */  daddu     $v0, $zero, $zero
.L8021834C:
/* 55772C 8021834C 44823000 */  mtc1      $v0, $f6
/* 557730 80218350 00000000 */  nop
/* 557734 80218354 468031A0 */  cvt.s.w   $f6, $f6
/* 557738 80218358 44053000 */  mfc1      $a1, $f6
/* 55773C 8021835C 0C04E035 */  jal       set_screen_overlay_alpha
/* 557740 80218360 24040001 */   addiu    $a0, $zero, 1
/* 557744 80218364 C7A40018 */  lwc1      $f4, 0x18($sp)
/* 557748 80218368 46802120 */  cvt.s.w   $f4, $f4
/* 55774C 8021836C 24040001 */  addiu     $a0, $zero, 1
/* 557750 80218370 C7A20020 */  lwc1      $f2, 0x20($sp)
/* 557754 80218374 468010A0 */  cvt.s.w   $f2, $f2
/* 557758 80218378 4604F100 */  add.s     $f4, $f30, $f4
/* 55775C 8021837C C7A60028 */  lwc1      $f6, 0x28($sp)
/* 557760 80218380 46023080 */  add.s     $f2, $f6, $f2
/* 557764 80218384 C7A60024 */  lwc1      $f6, 0x24($sp)
/* 557768 80218388 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 55776C 8021838C 46800020 */  cvt.s.w   $f0, $f0
/* 557770 80218390 46003000 */  add.s     $f0, $f6, $f0
/* 557774 80218394 4600118D */  trunc.w.s $f6, $f2
/* 557778 80218398 E7A60010 */  swc1      $f6, 0x10($sp)
/* 55777C 8021839C 4600218D */  trunc.w.s $f6, $f4
/* 557780 802183A0 44063000 */  mfc1      $a2, $f6
/* 557784 802183A4 4600018D */  trunc.w.s $f6, $f0
/* 557788 802183A8 44073000 */  mfc1      $a3, $f6
/* 55778C 802183AC 0C04DFB0 */  jal       set_screen_overlay_center_worldpos
/* 557790 802183B0 0000282D */   daddu    $a1, $zero, $zero
/* 557794 802183B4 C7A40018 */  lwc1      $f4, 0x18($sp)
/* 557798 802183B8 46802120 */  cvt.s.w   $f4, $f4
/* 55779C 802183BC 0240202D */  daddu     $a0, $s2, $zero
/* 5577A0 802183C0 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* 5577A4 802183C4 468010A0 */  cvt.s.w   $f2, $f2
/* 5577A8 802183C8 4604F100 */  add.s     $f4, $f30, $f4
/* 5577AC 802183CC C7A60024 */  lwc1      $f6, 0x24($sp)
/* 5577B0 802183D0 46023080 */  add.s     $f2, $f6, $f2
/* 5577B4 802183D4 C7A60028 */  lwc1      $f6, 0x28($sp)
/* 5577B8 802183D8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 5577BC 802183DC 46800020 */  cvt.s.w   $f0, $f0
/* 5577C0 802183E0 46003000 */  add.s     $f0, $f6, $f0
/* 5577C4 802183E4 4600218D */  trunc.w.s $f6, $f4
/* 5577C8 802183E8 E6260084 */  swc1      $f6, 0x84($s1)
/* 5577CC 802183EC 4600118D */  trunc.w.s $f6, $f2
/* 5577D0 802183F0 E6260088 */  swc1      $f6, 0x88($s1)
/* 5577D4 802183F4 4600018D */  trunc.w.s $f6, $f0
/* 5577D8 802183F8 E626008C */  swc1      $f6, 0x8c($s1)
/* 5577DC 802183FC 0C099117 */  jal       get_actor_part
/* 5577E0 80218400 24050002 */   addiu    $a1, $zero, 2
/* 5577E4 80218404 0040202D */  daddu     $a0, $v0, $zero
/* 5577E8 80218408 97A2001A */  lhu       $v0, 0x1a($sp)
/* 5577EC 8021840C 97A3001E */  lhu       $v1, 0x1e($sp)
/* 5577F0 80218410 2442FFFB */  addiu     $v0, $v0, -5
/* 5577F4 80218414 24630005 */  addiu     $v1, $v1, 5
/* 5577F8 80218418 A4820014 */  sh        $v0, 0x14($a0)
/* 5577FC 8021841C 1260000D */  beqz      $s3, .L80218454
/* 557800 80218420 A4830016 */   sh       $v1, 0x16($a0)
/* 557804 80218424 C6200084 */  lwc1      $f0, 0x84($s1)
/* 557808 80218428 46800020 */  cvt.s.w   $f0, $f0
/* 55780C 8021842C E6800004 */  swc1      $f0, 4($s4)
/* 557810 80218430 C6200088 */  lwc1      $f0, 0x88($s1)
/* 557814 80218434 46800020 */  cvt.s.w   $f0, $f0
/* 557818 80218438 E6800008 */  swc1      $f0, 8($s4)
/* 55781C 8021843C 8E22008C */  lw        $v0, 0x8c($s1)
/* 557820 80218440 24420019 */  addiu     $v0, $v0, 0x19
/* 557824 80218444 44820000 */  mtc1      $v0, $f0
/* 557828 80218448 00000000 */  nop
/* 55782C 8021844C 46800020 */  cvt.s.w   $f0, $f0
/* 557830 80218450 E680000C */  swc1      $f0, 0xc($s4)
.L80218454:
/* 557834 80218454 24020002 */  addiu     $v0, $zero, 2
.L80218458:
/* 557838 80218458 8FBF0044 */  lw        $ra, 0x44($sp)
/* 55783C 8021845C 8FB40040 */  lw        $s4, 0x40($sp)
/* 557840 80218460 8FB3003C */  lw        $s3, 0x3c($sp)
/* 557844 80218464 8FB20038 */  lw        $s2, 0x38($sp)
/* 557848 80218468 8FB10034 */  lw        $s1, 0x34($sp)
/* 55784C 8021846C 8FB00030 */  lw        $s0, 0x30($sp)
/* 557850 80218470 D7BE0070 */  ldc1      $f30, 0x70($sp)
/* 557854 80218474 D7BC0068 */  ldc1      $f28, 0x68($sp)
/* 557858 80218478 D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 55785C 8021847C D7B80058 */  ldc1      $f24, 0x58($sp)
/* 557860 80218480 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 557864 80218484 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 557868 80218488 03E00008 */  jr        $ra
/* 55786C 8021848C 27BD0078 */   addiu    $sp, $sp, 0x78
