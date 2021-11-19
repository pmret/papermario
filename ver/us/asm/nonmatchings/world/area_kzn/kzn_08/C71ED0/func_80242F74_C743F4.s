.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80245830_C76CB0
.double 380.0

dlabel D_80245838_C76CB8
.double -380.0

dlabel D_80245840_C76CC0
.double 305.0

dlabel D_80245848_C76CC8
.double 375.0

dlabel D_80245850_C76CD0
.double 45.0

dlabel D_80245858_C76CD8
.double 150.0

.section .text

glabel func_80242F74_C743F4
/* C743F4 80242F74 27BDFF80 */  addiu     $sp, $sp, -0x80
/* C743F8 80242F78 AFBF0064 */  sw        $ra, 0x64($sp)
/* C743FC 80242F7C AFBE0060 */  sw        $fp, 0x60($sp)
/* C74400 80242F80 AFB7005C */  sw        $s7, 0x5c($sp)
/* C74404 80242F84 AFB60058 */  sw        $s6, 0x58($sp)
/* C74408 80242F88 AFB50054 */  sw        $s5, 0x54($sp)
/* C7440C 80242F8C AFB40050 */  sw        $s4, 0x50($sp)
/* C74410 80242F90 AFB3004C */  sw        $s3, 0x4c($sp)
/* C74414 80242F94 AFB20048 */  sw        $s2, 0x48($sp)
/* C74418 80242F98 AFB10044 */  sw        $s1, 0x44($sp)
/* C7441C 80242F9C AFB00040 */  sw        $s0, 0x40($sp)
/* C74420 80242FA0 F7B80078 */  sdc1      $f24, 0x78($sp)
/* C74424 80242FA4 F7B60070 */  sdc1      $f22, 0x70($sp)
/* C74428 80242FA8 F7B40068 */  sdc1      $f20, 0x68($sp)
/* C7442C 80242FAC AFA40080 */  sw        $a0, 0x80($sp)
/* C74430 80242FB0 8C960148 */  lw        $s6, 0x148($a0)
/* C74434 80242FB4 00C0902D */  daddu     $s2, $a2, $zero
/* C74438 80242FB8 86C40008 */  lh        $a0, 8($s6)
/* C7443C 80242FBC 0C00EABB */  jal       get_npc_unsafe
/* C74440 80242FC0 0000B82D */   daddu    $s7, $zero, $zero
/* C74444 80242FC4 0040882D */  daddu     $s1, $v0, $zero
/* C74448 80242FC8 9622008E */  lhu       $v0, 0x8e($s1)
/* C7444C 80242FCC 2442FFFF */  addiu     $v0, $v0, -1
/* C74450 80242FD0 A622008E */  sh        $v0, 0x8e($s1)
/* C74454 80242FD4 00021400 */  sll       $v0, $v0, 0x10
/* C74458 80242FD8 8EC30090 */  lw        $v1, 0x90($s6)
/* C7445C 80242FDC 00021403 */  sra       $v0, $v0, 0x10
/* C74460 80242FE0 0062182A */  slt       $v1, $v1, $v0
/* C74464 80242FE4 14600005 */  bnez      $v1, .L80242FFC
/* C74468 80242FE8 02E0F02D */   daddu    $fp, $s7, $zero
/* C7446C 80242FEC 8EC20000 */  lw        $v0, ($s6)
/* C74470 80242FF0 3C031F10 */  lui       $v1, 0x1f10
/* C74474 80242FF4 00431025 */  or        $v0, $v0, $v1
/* C74478 80242FF8 AEC20000 */  sw        $v0, ($s6)
.L80242FFC:
/* C7447C 80242FFC 8622008E */  lh        $v0, 0x8e($s1)
/* C74480 80243000 1440025D */  bnez      $v0, .L80243978
/* C74484 80243004 00000000 */   nop
/* C74488 80243008 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C7448C 8024300C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C74490 80243010 0C00A6C9 */  jal       clamp_angle
/* C74494 80243014 C44C00A8 */   lwc1     $f12, 0xa8($v0)
/* C74498 80243018 3C014334 */  lui       $at, 0x4334
/* C7449C 8024301C 44811000 */  mtc1      $at, $f2
/* C744A0 80243020 00000000 */  nop
/* C744A4 80243024 4602003C */  c.lt.s    $f0, $f2
/* C744A8 80243028 00000000 */  nop
/* C744AC 8024302C 45000011 */  bc1f      .L80243074
/* C744B0 80243030 00000000 */   nop
/* C744B4 80243034 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* C744B8 80243038 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* C744BC 8024303C 3C0142B4 */  lui       $at, 0x42b4
/* C744C0 80243040 44816000 */  mtc1      $at, $f12
/* C744C4 80243044 00031080 */  sll       $v0, $v1, 2
/* C744C8 80243048 00431021 */  addu      $v0, $v0, $v1
/* C744CC 8024304C 00021080 */  sll       $v0, $v0, 2
/* C744D0 80243050 00431023 */  subu      $v0, $v0, $v1
/* C744D4 80243054 000218C0 */  sll       $v1, $v0, 3
/* C744D8 80243058 00431021 */  addu      $v0, $v0, $v1
/* C744DC 8024305C 000210C0 */  sll       $v0, $v0, 3
/* C744E0 80243060 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* C744E4 80243064 00220821 */  addu      $at, $at, $v0
/* C744E8 80243068 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* C744EC 8024306C 08090C2C */  j         .L802430B0
/* C744F0 80243070 460C0301 */   sub.s    $f12, $f0, $f12
.L80243074:
/* C744F4 80243074 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* C744F8 80243078 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* C744FC 8024307C 3C0142B4 */  lui       $at, 0x42b4
/* C74500 80243080 44816000 */  mtc1      $at, $f12
/* C74504 80243084 00031080 */  sll       $v0, $v1, 2
/* C74508 80243088 00431021 */  addu      $v0, $v0, $v1
/* C7450C 8024308C 00021080 */  sll       $v0, $v0, 2
/* C74510 80243090 00431023 */  subu      $v0, $v0, $v1
/* C74514 80243094 000218C0 */  sll       $v1, $v0, 3
/* C74518 80243098 00431021 */  addu      $v0, $v0, $v1
/* C7451C 8024309C 000210C0 */  sll       $v0, $v0, 3
/* C74520 802430A0 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* C74524 802430A4 00220821 */  addu      $at, $at, $v0
/* C74528 802430A8 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* C7452C 802430AC 460C0300 */  add.s     $f12, $f0, $f12
.L802430B0:
/* C74530 802430B0 0C00A6C9 */  jal       clamp_angle
/* C74534 802430B4 00000000 */   nop
/* C74538 802430B8 46000586 */  mov.s     $f22, $f0
/* C7453C 802430BC 3C014334 */  lui       $at, 0x4334
/* C74540 802430C0 44816000 */  mtc1      $at, $f12
/* C74544 802430C4 0C00A6C9 */  jal       clamp_angle
/* C74548 802430C8 460CB300 */   add.s    $f12, $f22, $f12
/* C7454C 802430CC 8EC20088 */  lw        $v0, 0x88($s6)
/* C74550 802430D0 14400010 */  bnez      $v0, .L80243114
/* C74554 802430D4 46000606 */   mov.s    $f24, $f0
/* C74558 802430D8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C7455C 802430DC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C74560 802430E0 804300B4 */  lb        $v1, 0xb4($v0)
/* C74564 802430E4 3C014200 */  lui       $at, 0x4200
/* C74568 802430E8 4481A000 */  mtc1      $at, $f20
/* C7456C 802430EC 10600016 */  beqz      $v1, .L80243148
/* C74570 802430F0 24020001 */   addiu    $v0, $zero, 1
/* C74574 802430F4 3C0142C8 */  lui       $at, 0x42c8
/* C74578 802430F8 4481A000 */  mtc1      $at, $f20
/* C7457C 802430FC 14620013 */  bne       $v1, $v0, .L8024314C
/* C74580 80243100 26300038 */   addiu    $s0, $s1, 0x38
/* C74584 80243104 3C0142B4 */  lui       $at, 0x42b4
/* C74588 80243108 4481A000 */  mtc1      $at, $f20
/* C7458C 8024310C 08090C54 */  j         .L80243150
/* C74590 80243110 0200202D */   daddu    $a0, $s0, $zero
.L80243114:
/* C74594 80243114 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C74598 80243118 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C7459C 8024311C 804300B4 */  lb        $v1, 0xb4($v0)
/* C745A0 80243120 3C014218 */  lui       $at, 0x4218
/* C745A4 80243124 4481A000 */  mtc1      $at, $f20
/* C745A8 80243128 10600007 */  beqz      $v1, .L80243148
/* C745AC 8024312C 24020001 */   addiu    $v0, $zero, 1
/* C745B0 80243130 3C0142B4 */  lui       $at, 0x42b4
/* C745B4 80243134 4481A000 */  mtc1      $at, $f20
/* C745B8 80243138 14620004 */  bne       $v1, $v0, .L8024314C
/* C745BC 8024313C 26300038 */   addiu    $s0, $s1, 0x38
/* C745C0 80243140 3C014296 */  lui       $at, 0x4296
/* C745C4 80243144 4481A000 */  mtc1      $at, $f20
.L80243148:
/* C745C8 80243148 26300038 */  addiu     $s0, $s1, 0x38
.L8024314C:
/* C745CC 8024314C 0200202D */  daddu     $a0, $s0, $zero
.L80243150:
/* C745D0 80243150 3C15800F */  lui       $s5, %hi(gPlayerStatusPtr)
/* C745D4 80243154 26B57B30 */  addiu     $s5, $s5, %lo(gPlayerStatusPtr)
/* C745D8 80243158 4407C000 */  mfc1      $a3, $f24
/* C745DC 8024315C 862200A6 */  lh        $v0, 0xa6($s1)
/* C745E0 80243160 8EA30000 */  lw        $v1, ($s5)
/* C745E4 80243164 44824000 */  mtc1      $v0, $f8
/* C745E8 80243168 00000000 */  nop
/* C745EC 8024316C 46804220 */  cvt.s.w   $f8, $f8
/* C745F0 80243170 C4600028 */  lwc1      $f0, 0x28($v1)
/* C745F4 80243174 44064000 */  mfc1      $a2, $f8
/* C745F8 80243178 26330040 */  addiu     $s3, $s1, 0x40
/* C745FC 8024317C E6200038 */  swc1      $f0, 0x38($s1)
/* C74600 80243180 C4600030 */  lwc1      $f0, 0x30($v1)
/* C74604 80243184 0260282D */  daddu     $a1, $s3, $zero
/* C74608 80243188 0C00A7E7 */  jal       add_vec2D_polar
/* C7460C 8024318C E6200040 */   swc1     $f0, 0x40($s1)
/* C74610 80243190 862200A6 */  lh        $v0, 0xa6($s1)
/* C74614 80243194 44820000 */  mtc1      $v0, $f0
/* C74618 80243198 00000000 */  nop
/* C7461C 8024319C 46800020 */  cvt.s.w   $f0, $f0
/* C74620 802431A0 4600A000 */  add.s     $f0, $f20, $f0
/* C74624 802431A4 4406B000 */  mfc1      $a2, $f22
/* C74628 802431A8 44050000 */  mfc1      $a1, $f0
/* C7462C 802431AC 0C00EA95 */  jal       npc_move_heading
/* C74630 802431B0 0220202D */   daddu    $a0, $s1, $zero
/* C74634 802431B4 8EC20088 */  lw        $v0, 0x88($s6)
/* C74638 802431B8 1440005D */  bnez      $v0, .L80243330
/* C7463C 802431BC 00000000 */   nop
/* C74640 802431C0 C6200038 */  lwc1      $f0, 0x38($s1)
/* C74644 802431C4 3C018024 */  lui       $at, %hi(D_80245830_C76CB0)
/* C74648 802431C8 D4245830 */  ldc1      $f4, %lo(D_80245830_C76CB0)($at)
/* C7464C 802431CC 46000021 */  cvt.d.s   $f0, $f0
/* C74650 802431D0 4620203C */  c.lt.d    $f4, $f0
/* C74654 802431D4 00000000 */  nop
/* C74658 802431D8 45000005 */  bc1f      .L802431F0
/* C7465C 802431DC 00000000 */   nop
/* C74660 802431E0 3C0143BE */  lui       $at, 0x43be
/* C74664 802431E4 44810000 */  mtc1      $at, $f0
/* C74668 802431E8 00000000 */  nop
/* C7466C 802431EC E6200038 */  swc1      $f0, 0x38($s1)
.L802431F0:
/* C74670 802431F0 C6200038 */  lwc1      $f0, 0x38($s1)
/* C74674 802431F4 3C018024 */  lui       $at, %hi(D_80245838_C76CB8)
/* C74678 802431F8 D4225838 */  ldc1      $f2, %lo(D_80245838_C76CB8)($at)
/* C7467C 802431FC 46000021 */  cvt.d.s   $f0, $f0
/* C74680 80243200 4622003C */  c.lt.d    $f0, $f2
/* C74684 80243204 00000000 */  nop
/* C74688 80243208 45000005 */  bc1f      .L80243220
/* C7468C 8024320C 00000000 */   nop
/* C74690 80243210 3C01C3BE */  lui       $at, 0xc3be
/* C74694 80243214 44810000 */  mtc1      $at, $f0
/* C74698 80243218 00000000 */  nop
/* C7469C 8024321C E6200038 */  swc1      $f0, 0x38($s1)
.L80243220:
/* C746A0 80243220 C6200040 */  lwc1      $f0, 0x40($s1)
/* C746A4 80243224 46000021 */  cvt.d.s   $f0, $f0
/* C746A8 80243228 4620203C */  c.lt.d    $f4, $f0
/* C746AC 8024322C 00000000 */  nop
/* C746B0 80243230 45000005 */  bc1f      .L80243248
/* C746B4 80243234 00000000 */   nop
/* C746B8 80243238 3C0143BE */  lui       $at, 0x43be
/* C746BC 8024323C 44810000 */  mtc1      $at, $f0
/* C746C0 80243240 00000000 */  nop
/* C746C4 80243244 E6200040 */  swc1      $f0, 0x40($s1)
.L80243248:
/* C746C8 80243248 C6200040 */  lwc1      $f0, 0x40($s1)
/* C746CC 8024324C 46000021 */  cvt.d.s   $f0, $f0
/* C746D0 80243250 4622003C */  c.lt.d    $f0, $f2
/* C746D4 80243254 00000000 */  nop
/* C746D8 80243258 45000005 */  bc1f      .L80243270
/* C746DC 8024325C 00000000 */   nop
/* C746E0 80243260 3C01C3BE */  lui       $at, 0xc3be
/* C746E4 80243264 44810000 */  mtc1      $at, $f0
/* C746E8 80243268 00000000 */  nop
/* C746EC 8024326C E6200040 */  swc1      $f0, 0x40($s1)
.L80243270:
/* C746F0 80243270 C6220038 */  lwc1      $f2, 0x38($s1)
/* C746F4 80243274 46021082 */  mul.s     $f2, $f2, $f2
/* C746F8 80243278 00000000 */  nop
/* C746FC 8024327C C6200040 */  lwc1      $f0, 0x40($s1)
/* C74700 80243280 46000002 */  mul.s     $f0, $f0, $f0
/* C74704 80243284 00000000 */  nop
/* C74708 80243288 46001300 */  add.s     $f12, $f2, $f0
/* C7470C 8024328C 46006004 */  sqrt.s    $f0, $f12
/* C74710 80243290 46000032 */  c.eq.s    $f0, $f0
/* C74714 80243294 00000000 */  nop
/* C74718 80243298 45010003 */  bc1t      .L802432A8
/* C7471C 8024329C 00000000 */   nop
/* C74720 802432A0 0C0187BC */  jal       sqrtf
/* C74724 802432A4 00000000 */   nop
.L802432A8:
/* C74728 802432A8 8E260038 */  lw        $a2, 0x38($s1)
/* C7472C 802432AC 8E270040 */  lw        $a3, 0x40($s1)
/* C74730 802432B0 4480A000 */  mtc1      $zero, $f20
/* C74734 802432B4 E7A00038 */  swc1      $f0, 0x38($sp)
/* C74738 802432B8 4600A306 */  mov.s     $f12, $f20
/* C7473C 802432BC 0C00A720 */  jal       atan2
/* C74740 802432C0 4600A386 */   mov.s    $f14, $f20
/* C74744 802432C4 46000586 */  mov.s     $f22, $f0
/* C74748 802432C8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* C7474C 802432CC 3C018024 */  lui       $at, %hi(D_80245840_C76CC0)
/* C74750 802432D0 D4205840 */  ldc1      $f0, %lo(D_80245840_C76CC0)($at)
/* C74754 802432D4 460010A1 */  cvt.d.s   $f2, $f2
/* C74758 802432D8 4620103C */  c.lt.d    $f2, $f0
/* C7475C 802432DC 00000000 */  nop
/* C74760 802432E0 45000004 */  bc1f      .L802432F4
/* C74764 802432E4 0200202D */   daddu    $a0, $s0, $zero
/* C74768 802432E8 3C064398 */  lui       $a2, 0x4398
/* C7476C 802432EC 08090CC5 */  j         .L80243314
/* C74770 802432F0 34C68000 */   ori      $a2, $a2, 0x8000
.L802432F4:
/* C74774 802432F4 3C018024 */  lui       $at, %hi(D_80245848_C76CC8)
/* C74778 802432F8 D4205848 */  ldc1      $f0, %lo(D_80245848_C76CC8)($at)
/* C7477C 802432FC 4622003C */  c.lt.d    $f0, $f2
/* C74780 80243300 00000000 */  nop
/* C74784 80243304 450000FA */  bc1f      .L802436F0
/* C74788 80243308 00000000 */   nop
/* C7478C 8024330C 3C0643BB */  lui       $a2, 0x43bb
/* C74790 80243310 34C68000 */  ori       $a2, $a2, 0x8000
.L80243314:
/* C74794 80243314 4407B000 */  mfc1      $a3, $f22
/* C74798 80243318 0260282D */  daddu     $a1, $s3, $zero
/* C7479C 8024331C E6340038 */  swc1      $f20, 0x38($s1)
/* C747A0 80243320 0C00A7E7 */  jal       add_vec2D_polar
/* C747A4 80243324 E6340040 */   swc1     $f20, 0x40($s1)
/* C747A8 80243328 08090DBC */  j         .L802436F0
/* C747AC 8024332C 00000000 */   nop
.L80243330:
/* C747B0 80243330 8E220000 */  lw        $v0, ($s1)
/* C747B4 80243334 30420040 */  andi      $v0, $v0, 0x40
/* C747B8 80243338 144000B0 */  bnez      $v0, .L802435FC
/* C747BC 8024333C 27A50020 */   addiu    $a1, $sp, 0x20
/* C747C0 80243340 27B40020 */  addiu     $s4, $sp, 0x20
/* C747C4 80243344 0280282D */  daddu     $a1, $s4, $zero
/* C747C8 80243348 27B30024 */  addiu     $s3, $sp, 0x24
/* C747CC 8024334C 8EA20000 */  lw        $v0, ($s5)
/* C747D0 80243350 3C014032 */  lui       $at, 0x4032
/* C747D4 80243354 44811800 */  mtc1      $at, $f3
/* C747D8 80243358 44801000 */  mtc1      $zero, $f2
/* C747DC 8024335C C440002C */  lwc1      $f0, 0x2c($v0)
/* C747E0 80243360 C4460028 */  lwc1      $f6, 0x28($v0)
/* C747E4 80243364 C4440030 */  lwc1      $f4, 0x30($v0)
/* C747E8 80243368 46000021 */  cvt.d.s   $f0, $f0
/* C747EC 8024336C 46220000 */  add.d     $f0, $f0, $f2
/* C747F0 80243370 E7A60020 */  swc1      $f6, 0x20($sp)
/* C747F4 80243374 E7A40028 */  swc1      $f4, 0x28($sp)
/* C747F8 80243378 46200020 */  cvt.s.d   $f0, $f0
/* C747FC 8024337C E7A00024 */  swc1      $f0, 0x24($sp)
/* C74800 80243380 E7B40010 */  swc1      $f20, 0x10($sp)
/* C74804 80243384 E7B60014 */  swc1      $f22, 0x14($sp)
/* C74808 80243388 862200A8 */  lh        $v0, 0xa8($s1)
/* C7480C 8024338C 0260302D */  daddu     $a2, $s3, $zero
/* C74810 80243390 44820000 */  mtc1      $v0, $f0
/* C74814 80243394 00000000 */  nop
/* C74818 80243398 46800020 */  cvt.s.w   $f0, $f0
/* C7481C 8024339C E7A00018 */  swc1      $f0, 0x18($sp)
/* C74820 802433A0 862200A6 */  lh        $v0, 0xa6($s1)
/* C74824 802433A4 27B00028 */  addiu     $s0, $sp, 0x28
/* C74828 802433A8 44820000 */  mtc1      $v0, $f0
/* C7482C 802433AC 00000000 */  nop
/* C74830 802433B0 46800020 */  cvt.s.w   $f0, $f0
/* C74834 802433B4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* C74838 802433B8 8E240080 */  lw        $a0, 0x80($s1)
/* C7483C 802433BC 0C037711 */  jal       npc_test_move_simple_with_slipping
/* C74840 802433C0 0200382D */   daddu    $a3, $s0, $zero
/* C74844 802433C4 104000CA */  beqz      $v0, .L802436F0
/* C74848 802433C8 0280282D */   daddu    $a1, $s4, $zero
/* C7484C 802433CC 8EA20000 */  lw        $v0, ($s5)
/* C74850 802433D0 3C018024 */  lui       $at, %hi(D_80245850_C76CD0)
/* C74854 802433D4 D4225850 */  ldc1      $f2, %lo(D_80245850_C76CD0)($at)
/* C74858 802433D8 C440002C */  lwc1      $f0, 0x2c($v0)
/* C7485C 802433DC C4460028 */  lwc1      $f6, 0x28($v0)
/* C74860 802433E0 C4440030 */  lwc1      $f4, 0x30($v0)
/* C74864 802433E4 46000021 */  cvt.d.s   $f0, $f0
/* C74868 802433E8 46220000 */  add.d     $f0, $f0, $f2
/* C7486C 802433EC E7A60020 */  swc1      $f6, 0x20($sp)
/* C74870 802433F0 E7A40028 */  swc1      $f4, 0x28($sp)
/* C74874 802433F4 46200020 */  cvt.s.d   $f0, $f0
/* C74878 802433F8 E7A00024 */  swc1      $f0, 0x24($sp)
/* C7487C 802433FC E7B40010 */  swc1      $f20, 0x10($sp)
/* C74880 80243400 E7B60014 */  swc1      $f22, 0x14($sp)
/* C74884 80243404 862200A8 */  lh        $v0, 0xa8($s1)
/* C74888 80243408 44820000 */  mtc1      $v0, $f0
/* C7488C 8024340C 00000000 */  nop
/* C74890 80243410 46800020 */  cvt.s.w   $f0, $f0
/* C74894 80243414 E7A00018 */  swc1      $f0, 0x18($sp)
/* C74898 80243418 862200A6 */  lh        $v0, 0xa6($s1)
/* C7489C 8024341C 0260302D */  daddu     $a2, $s3, $zero
/* C748A0 80243420 44820000 */  mtc1      $v0, $f0
/* C748A4 80243424 00000000 */  nop
/* C748A8 80243428 46800020 */  cvt.s.w   $f0, $f0
/* C748AC 8024342C E7A0001C */  swc1      $f0, 0x1c($sp)
/* C748B0 80243430 8E240080 */  lw        $a0, 0x80($s1)
/* C748B4 80243434 0C037711 */  jal       npc_test_move_simple_with_slipping
/* C748B8 80243438 0200382D */   daddu    $a3, $s0, $zero
/* C748BC 8024343C 27A5002C */  addiu     $a1, $sp, 0x2c
/* C748C0 80243440 27A60030 */  addiu     $a2, $sp, 0x30
/* C748C4 80243444 27A70034 */  addiu     $a3, $sp, 0x34
/* C748C8 80243448 27A30038 */  addiu     $v1, $sp, 0x38
/* C748CC 8024344C C6220038 */  lwc1      $f2, 0x38($s1)
/* C748D0 80243450 C620003C */  lwc1      $f0, 0x3c($s1)
/* C748D4 80243454 3C014348 */  lui       $at, 0x4348
/* C748D8 80243458 44813000 */  mtc1      $at, $f6
/* C748DC 8024345C 46000021 */  cvt.d.s   $f0, $f0
/* C748E0 80243460 E7A2002C */  swc1      $f2, 0x2c($sp)
/* C748E4 80243464 3C014059 */  lui       $at, 0x4059
/* C748E8 80243468 44811800 */  mtc1      $at, $f3
/* C748EC 8024346C 44801000 */  mtc1      $zero, $f2
/* C748F0 80243470 C6240040 */  lwc1      $f4, 0x40($s1)
/* C748F4 80243474 46220000 */  add.d     $f0, $f0, $f2
/* C748F8 80243478 E7A60038 */  swc1      $f6, 0x38($sp)
/* C748FC 8024347C E7A40034 */  swc1      $f4, 0x34($sp)
/* C74900 80243480 46200020 */  cvt.s.d   $f0, $f0
/* C74904 80243484 E7A00030 */  swc1      $f0, 0x30($sp)
/* C74908 80243488 AFA30010 */  sw        $v1, 0x10($sp)
/* C7490C 8024348C 8E240080 */  lw        $a0, 0x80($s1)
/* C74910 80243490 0C0372DF */  jal       npc_raycast_down_sides
/* C74914 80243494 0040802D */   daddu    $s0, $v0, $zero
/* C74918 80243498 1600001C */  bnez      $s0, .L8024350C
/* C7491C 8024349C 00000000 */   nop
/* C74920 802434A0 1040001A */  beqz      $v0, .L8024350C
/* C74924 802434A4 00000000 */   nop
/* C74928 802434A8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* C7492C 802434AC 3C014054 */  lui       $at, 0x4054
/* C74930 802434B0 44810800 */  mtc1      $at, $f1
/* C74934 802434B4 44800000 */  mtc1      $zero, $f0
/* C74938 802434B8 460010A1 */  cvt.d.s   $f2, $f2
/* C7493C 802434BC 4622003C */  c.lt.d    $f0, $f2
/* C74940 802434C0 00000000 */  nop
/* C74944 802434C4 45000011 */  bc1f      .L8024350C
/* C74948 802434C8 00000000 */   nop
/* C7494C 802434CC 3C01405E */  lui       $at, 0x405e
/* C74950 802434D0 44810800 */  mtc1      $at, $f1
/* C74954 802434D4 44800000 */  mtc1      $zero, $f0
/* C74958 802434D8 00000000 */  nop
/* C7495C 802434DC 4620103C */  c.lt.d    $f2, $f0
/* C74960 802434E0 00000000 */  nop
/* C74964 802434E4 45000009 */  bc1f      .L8024350C
/* C74968 802434E8 00000000 */   nop
/* C7496C 802434EC C622003C */  lwc1      $f2, 0x3c($s1)
/* C74970 802434F0 C7A00030 */  lwc1      $f0, 0x30($sp)
/* C74974 802434F4 46001032 */  c.eq.s    $f2, $f0
/* C74978 802434F8 00000000 */  nop
/* C7497C 802434FC 45010003 */  bc1t      .L8024350C
/* C74980 80243500 00000000 */   nop
/* C74984 80243504 08090DBC */  j         .L802436F0
/* C74988 80243508 241E0001 */   addiu    $fp, $zero, 1
.L8024350C:
/* C7498C 8024350C 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* C74990 80243510 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* C74994 80243514 8E020000 */  lw        $v0, ($s0)
/* C74998 80243518 3C014024 */  lui       $at, 0x4024
/* C7499C 8024351C 44811800 */  mtc1      $at, $f3
/* C749A0 80243520 44801000 */  mtc1      $zero, $f2
/* C749A4 80243524 C440002C */  lwc1      $f0, 0x2c($v0)
/* C749A8 80243528 C4460028 */  lwc1      $f6, 0x28($v0)
/* C749AC 8024352C C4440030 */  lwc1      $f4, 0x30($v0)
/* C749B0 80243530 46000021 */  cvt.d.s   $f0, $f0
/* C749B4 80243534 46220000 */  add.d     $f0, $f0, $f2
/* C749B8 80243538 E7A60020 */  swc1      $f6, 0x20($sp)
/* C749BC 8024353C E7A40028 */  swc1      $f4, 0x28($sp)
/* C749C0 80243540 46200020 */  cvt.s.d   $f0, $f0
/* C749C4 80243544 E7A00024 */  swc1      $f0, 0x24($sp)
/* C749C8 80243548 E7B40010 */  swc1      $f20, 0x10($sp)
/* C749CC 8024354C E7B60014 */  swc1      $f22, 0x14($sp)
/* C749D0 80243550 862200A8 */  lh        $v0, 0xa8($s1)
/* C749D4 80243554 27A50020 */  addiu     $a1, $sp, 0x20
/* C749D8 80243558 44820000 */  mtc1      $v0, $f0
/* C749DC 8024355C 00000000 */  nop
/* C749E0 80243560 46800020 */  cvt.s.w   $f0, $f0
/* C749E4 80243564 E7A00018 */  swc1      $f0, 0x18($sp)
/* C749E8 80243568 862200A6 */  lh        $v0, 0xa6($s1)
/* C749EC 8024356C 27A60024 */  addiu     $a2, $sp, 0x24
/* C749F0 80243570 44820000 */  mtc1      $v0, $f0
/* C749F4 80243574 00000000 */  nop
/* C749F8 80243578 46800020 */  cvt.s.w   $f0, $f0
/* C749FC 8024357C E7A0001C */  swc1      $f0, 0x1c($sp)
/* C74A00 80243580 8E240080 */  lw        $a0, 0x80($s1)
/* C74A04 80243584 0C037711 */  jal       npc_test_move_simple_with_slipping
/* C74A08 80243588 27A70028 */   addiu    $a3, $sp, 0x28
/* C74A0C 8024358C 8FA60020 */  lw        $a2, 0x20($sp)
/* C74A10 80243590 8E020000 */  lw        $v0, ($s0)
/* C74A14 80243594 8FA70028 */  lw        $a3, 0x28($sp)
/* C74A18 80243598 C44C0028 */  lwc1      $f12, 0x28($v0)
/* C74A1C 8024359C C44E0030 */  lwc1      $f14, 0x30($v0)
/* C74A20 802435A0 0C00A7B5 */  jal       dist2D
/* C74A24 802435A4 24170001 */   addiu    $s7, $zero, 1
/* C74A28 802435A8 46000506 */  mov.s     $f20, $f0
/* C74A2C 802435AC 8E030000 */  lw        $v1, ($s0)
/* C74A30 802435B0 862200A6 */  lh        $v0, 0xa6($s1)
/* C74A34 802435B4 4407C000 */  mfc1      $a3, $f24
/* C74A38 802435B8 44824000 */  mtc1      $v0, $f8
/* C74A3C 802435BC 00000000 */  nop
/* C74A40 802435C0 46804220 */  cvt.s.w   $f8, $f8
/* C74A44 802435C4 C4600028 */  lwc1      $f0, 0x28($v1)
/* C74A48 802435C8 44064000 */  mfc1      $a2, $f8
/* C74A4C 802435CC 26240038 */  addiu     $a0, $s1, 0x38
/* C74A50 802435D0 E6200038 */  swc1      $f0, 0x38($s1)
/* C74A54 802435D4 C4600030 */  lwc1      $f0, 0x30($v1)
/* C74A58 802435D8 26250040 */  addiu     $a1, $s1, 0x40
/* C74A5C 802435DC 0C00A7E7 */  jal       add_vec2D_polar
/* C74A60 802435E0 E6200040 */   swc1     $f0, 0x40($s1)
/* C74A64 802435E4 862200A6 */  lh        $v0, 0xa6($s1)
/* C74A68 802435E8 44820000 */  mtc1      $v0, $f0
/* C74A6C 802435EC 00000000 */  nop
/* C74A70 802435F0 46800020 */  cvt.s.w   $f0, $f0
/* C74A74 802435F4 08090DB8 */  j         .L802436E0
/* C74A78 802435F8 4600A500 */   add.s    $f20, $f20, $f0
.L802435FC:
/* C74A7C 802435FC 8EA20000 */  lw        $v0, ($s5)
/* C74A80 80243600 3C014032 */  lui       $at, 0x4032
/* C74A84 80243604 44811800 */  mtc1      $at, $f3
/* C74A88 80243608 44801000 */  mtc1      $zero, $f2
/* C74A8C 8024360C C440002C */  lwc1      $f0, 0x2c($v0)
/* C74A90 80243610 C4460028 */  lwc1      $f6, 0x28($v0)
/* C74A94 80243614 C4440030 */  lwc1      $f4, 0x30($v0)
/* C74A98 80243618 46000021 */  cvt.d.s   $f0, $f0
/* C74A9C 8024361C 46220000 */  add.d     $f0, $f0, $f2
/* C74AA0 80243620 E7A60020 */  swc1      $f6, 0x20($sp)
/* C74AA4 80243624 E7A40028 */  swc1      $f4, 0x28($sp)
/* C74AA8 80243628 46200020 */  cvt.s.d   $f0, $f0
/* C74AAC 8024362C E7A00024 */  swc1      $f0, 0x24($sp)
/* C74AB0 80243630 E7B40010 */  swc1      $f20, 0x10($sp)
/* C74AB4 80243634 E7B60014 */  swc1      $f22, 0x14($sp)
/* C74AB8 80243638 862200A8 */  lh        $v0, 0xa8($s1)
/* C74ABC 8024363C 44820000 */  mtc1      $v0, $f0
/* C74AC0 80243640 00000000 */  nop
/* C74AC4 80243644 46800020 */  cvt.s.w   $f0, $f0
/* C74AC8 80243648 E7A00018 */  swc1      $f0, 0x18($sp)
/* C74ACC 8024364C 862200A6 */  lh        $v0, 0xa6($s1)
/* C74AD0 80243650 27A60024 */  addiu     $a2, $sp, 0x24
/* C74AD4 80243654 44820000 */  mtc1      $v0, $f0
/* C74AD8 80243658 00000000 */  nop
/* C74ADC 8024365C 46800020 */  cvt.s.w   $f0, $f0
/* C74AE0 80243660 E7A0001C */  swc1      $f0, 0x1c($sp)
/* C74AE4 80243664 8E240080 */  lw        $a0, 0x80($s1)
/* C74AE8 80243668 0C037711 */  jal       npc_test_move_simple_with_slipping
/* C74AEC 8024366C 27A70028 */   addiu    $a3, $sp, 0x28
/* C74AF0 80243670 1040001F */  beqz      $v0, .L802436F0
/* C74AF4 80243674 00000000 */   nop
/* C74AF8 80243678 8FA60020 */  lw        $a2, 0x20($sp)
/* C74AFC 8024367C 8EA20000 */  lw        $v0, ($s5)
/* C74B00 80243680 8FA70028 */  lw        $a3, 0x28($sp)
/* C74B04 80243684 C44C0028 */  lwc1      $f12, 0x28($v0)
/* C74B08 80243688 0C00A7B5 */  jal       dist2D
/* C74B0C 8024368C C44E0030 */   lwc1     $f14, 0x30($v0)
/* C74B10 80243690 46000506 */  mov.s     $f20, $f0
/* C74B14 80243694 8EA30000 */  lw        $v1, ($s5)
/* C74B18 80243698 862200A6 */  lh        $v0, 0xa6($s1)
/* C74B1C 8024369C 4407C000 */  mfc1      $a3, $f24
/* C74B20 802436A0 44824000 */  mtc1      $v0, $f8
/* C74B24 802436A4 00000000 */  nop
/* C74B28 802436A8 46804220 */  cvt.s.w   $f8, $f8
/* C74B2C 802436AC C4600028 */  lwc1      $f0, 0x28($v1)
/* C74B30 802436B0 44064000 */  mfc1      $a2, $f8
/* C74B34 802436B4 0200202D */  daddu     $a0, $s0, $zero
/* C74B38 802436B8 E6200038 */  swc1      $f0, 0x38($s1)
/* C74B3C 802436BC C4600030 */  lwc1      $f0, 0x30($v1)
/* C74B40 802436C0 0260282D */  daddu     $a1, $s3, $zero
/* C74B44 802436C4 0C00A7E7 */  jal       add_vec2D_polar
/* C74B48 802436C8 E6200040 */   swc1     $f0, 0x40($s1)
/* C74B4C 802436CC 862200A6 */  lh        $v0, 0xa6($s1)
/* C74B50 802436D0 44820000 */  mtc1      $v0, $f0
/* C74B54 802436D4 00000000 */  nop
/* C74B58 802436D8 46800020 */  cvt.s.w   $f0, $f0
/* C74B5C 802436DC 4600A500 */  add.s     $f20, $f20, $f0
.L802436E0:
/* C74B60 802436E0 4406B000 */  mfc1      $a2, $f22
/* C74B64 802436E4 4405A000 */  mfc1      $a1, $f20
/* C74B68 802436E8 0C00EA95 */  jal       npc_move_heading
/* C74B6C 802436EC 0220202D */   daddu    $a0, $s1, $zero
.L802436F0:
/* C74B70 802436F0 C6400008 */  lwc1      $f0, 8($s2)
/* C74B74 802436F4 46800020 */  cvt.s.w   $f0, $f0
/* C74B78 802436F8 44050000 */  mfc1      $a1, $f0
/* C74B7C 802436FC C640000C */  lwc1      $f0, 0xc($s2)
/* C74B80 80243700 46800020 */  cvt.s.w   $f0, $f0
/* C74B84 80243704 44060000 */  mfc1      $a2, $f0
/* C74B88 80243708 C6200040 */  lwc1      $f0, 0x40($s1)
/* C74B8C 8024370C 26300038 */  addiu     $s0, $s1, 0x38
/* C74B90 80243710 E7A00010 */  swc1      $f0, 0x10($sp)
/* C74B94 80243714 C6400010 */  lwc1      $f0, 0x10($s2)
/* C74B98 80243718 46800020 */  cvt.s.w   $f0, $f0
/* C74B9C 8024371C E7A00014 */  swc1      $f0, 0x14($sp)
/* C74BA0 80243720 C6400014 */  lwc1      $f0, 0x14($s2)
/* C74BA4 80243724 46800020 */  cvt.s.w   $f0, $f0
/* C74BA8 80243728 E7A00018 */  swc1      $f0, 0x18($sp)
/* C74BAC 8024372C 8E440004 */  lw        $a0, 4($s2)
/* C74BB0 80243730 8E270038 */  lw        $a3, 0x38($s1)
/* C74BB4 80243734 0C0123F5 */  jal       is_point_within_region
/* C74BB8 80243738 26330040 */   addiu    $s3, $s1, 0x40
/* C74BBC 8024373C 1040005A */  beqz      $v0, .L802438A8
/* C74BC0 80243740 00000000 */   nop
/* C74BC4 80243744 8E430004 */  lw        $v1, 4($s2)
/* C74BC8 80243748 10600005 */  beqz      $v1, .L80243760
/* C74BCC 8024374C 24020001 */   addiu    $v0, $zero, 1
/* C74BD0 80243750 10620029 */  beq       $v1, $v0, .L802437F8
/* C74BD4 80243754 00000000 */   nop
/* C74BD8 80243758 08090E2A */  j         .L802438A8
/* C74BDC 8024375C 00000000 */   nop
.L80243760:
/* C74BE0 80243760 C6480008 */  lwc1      $f8, 8($s2)
/* C74BE4 80243764 46804220 */  cvt.s.w   $f8, $f8
/* C74BE8 80243768 44064000 */  mfc1      $a2, $f8
/* C74BEC 8024376C C648000C */  lwc1      $f8, 0xc($s2)
/* C74BF0 80243770 46804220 */  cvt.s.w   $f8, $f8
/* C74BF4 80243774 C62C0038 */  lwc1      $f12, 0x38($s1)
/* C74BF8 80243778 C62E0040 */  lwc1      $f14, 0x40($s1)
/* C74BFC 8024377C 44074000 */  mfc1      $a3, $f8
/* C74C00 80243780 0C00A7B5 */  jal       dist2D
/* C74C04 80243784 00000000 */   nop
/* C74C08 80243788 C6420010 */  lwc1      $f2, 0x10($s2)
/* C74C0C 8024378C 468010A0 */  cvt.s.w   $f2, $f2
/* C74C10 80243790 4600103C */  c.lt.s    $f2, $f0
/* C74C14 80243794 00000000 */  nop
/* C74C18 80243798 45000043 */  bc1f      .L802438A8
/* C74C1C 8024379C E7A00038 */   swc1     $f0, 0x38($sp)
/* C74C20 802437A0 C64C0008 */  lwc1      $f12, 8($s2)
/* C74C24 802437A4 46806320 */  cvt.s.w   $f12, $f12
/* C74C28 802437A8 8E260038 */  lw        $a2, 0x38($s1)
/* C74C2C 802437AC 8E270040 */  lw        $a3, 0x40($s1)
/* C74C30 802437B0 C64E000C */  lwc1      $f14, 0xc($s2)
/* C74C34 802437B4 0C00A720 */  jal       atan2
/* C74C38 802437B8 468073A0 */   cvt.s.w  $f14, $f14
/* C74C3C 802437BC 0200202D */  daddu     $a0, $s0, $zero
/* C74C40 802437C0 44070000 */  mfc1      $a3, $f0
/* C74C44 802437C4 C6400008 */  lwc1      $f0, 8($s2)
/* C74C48 802437C8 46800020 */  cvt.s.w   $f0, $f0
/* C74C4C 802437CC E6200038 */  swc1      $f0, 0x38($s1)
/* C74C50 802437D0 C640000C */  lwc1      $f0, 0xc($s2)
/* C74C54 802437D4 46800020 */  cvt.s.w   $f0, $f0
/* C74C58 802437D8 E6200040 */  swc1      $f0, 0x40($s1)
/* C74C5C 802437DC C6480010 */  lwc1      $f8, 0x10($s2)
/* C74C60 802437E0 46804220 */  cvt.s.w   $f8, $f8
/* C74C64 802437E4 44064000 */  mfc1      $a2, $f8
/* C74C68 802437E8 0C00A7E7 */  jal       add_vec2D_polar
/* C74C6C 802437EC 0260282D */   daddu    $a1, $s3, $zero
/* C74C70 802437F0 08090E2A */  j         .L802438A8
/* C74C74 802437F4 00000000 */   nop
.L802437F8:
/* C74C78 802437F8 8E420008 */  lw        $v0, 8($s2)
/* C74C7C 802437FC 8E430010 */  lw        $v1, 0x10($s2)
/* C74C80 80243800 C6200038 */  lwc1      $f0, 0x38($s1)
/* C74C84 80243804 00431021 */  addu      $v0, $v0, $v1
/* C74C88 80243808 44821000 */  mtc1      $v0, $f2
/* C74C8C 8024380C 00000000 */  nop
/* C74C90 80243810 468010A0 */  cvt.s.w   $f2, $f2
/* C74C94 80243814 4600103C */  c.lt.s    $f2, $f0
/* C74C98 80243818 00000000 */  nop
/* C74C9C 8024381C 45030001 */  bc1tl     .L80243824
/* C74CA0 80243820 E6220038 */   swc1     $f2, 0x38($s1)
.L80243824:
/* C74CA4 80243824 8E420008 */  lw        $v0, 8($s2)
/* C74CA8 80243828 8E430010 */  lw        $v1, 0x10($s2)
/* C74CAC 8024382C C6200038 */  lwc1      $f0, 0x38($s1)
/* C74CB0 80243830 00431023 */  subu      $v0, $v0, $v1
/* C74CB4 80243834 44821000 */  mtc1      $v0, $f2
/* C74CB8 80243838 00000000 */  nop
/* C74CBC 8024383C 468010A0 */  cvt.s.w   $f2, $f2
/* C74CC0 80243840 4602003C */  c.lt.s    $f0, $f2
/* C74CC4 80243844 00000000 */  nop
/* C74CC8 80243848 45030001 */  bc1tl     .L80243850
/* C74CCC 8024384C E6220038 */   swc1     $f2, 0x38($s1)
.L80243850:
/* C74CD0 80243850 8E42000C */  lw        $v0, 0xc($s2)
/* C74CD4 80243854 8E430014 */  lw        $v1, 0x14($s2)
/* C74CD8 80243858 C6200040 */  lwc1      $f0, 0x40($s1)
/* C74CDC 8024385C 00431021 */  addu      $v0, $v0, $v1
/* C74CE0 80243860 44821000 */  mtc1      $v0, $f2
/* C74CE4 80243864 00000000 */  nop
/* C74CE8 80243868 468010A0 */  cvt.s.w   $f2, $f2
/* C74CEC 8024386C 4600103C */  c.lt.s    $f2, $f0
/* C74CF0 80243870 00000000 */  nop
/* C74CF4 80243874 45030001 */  bc1tl     .L8024387C
/* C74CF8 80243878 E6220040 */   swc1     $f2, 0x40($s1)
.L8024387C:
/* C74CFC 8024387C 8E42000C */  lw        $v0, 0xc($s2)
/* C74D00 80243880 8E430014 */  lw        $v1, 0x14($s2)
/* C74D04 80243884 C6200040 */  lwc1      $f0, 0x40($s1)
/* C74D08 80243888 00431023 */  subu      $v0, $v0, $v1
/* C74D0C 8024388C 44821000 */  mtc1      $v0, $f2
/* C74D10 80243890 00000000 */  nop
/* C74D14 80243894 468010A0 */  cvt.s.w   $f2, $f2
/* C74D18 80243898 4602003C */  c.lt.s    $f0, $f2
/* C74D1C 8024389C 00000000 */  nop
/* C74D20 802438A0 45030001 */  bc1tl     .L802438A8
/* C74D24 802438A4 E6220040 */   swc1     $f2, 0x40($s1)
.L802438A8:
/* C74D28 802438A8 16E0001F */  bnez      $s7, .L80243928
/* C74D2C 802438AC 00000000 */   nop
/* C74D30 802438B0 8E220000 */  lw        $v0, ($s1)
/* C74D34 802438B4 30420008 */  andi      $v0, $v0, 8
/* C74D38 802438B8 10400003 */  beqz      $v0, .L802438C8
/* C74D3C 802438BC 27A50020 */   addiu    $a1, $sp, 0x20
/* C74D40 802438C0 13C00019 */  beqz      $fp, .L80243928
/* C74D44 802438C4 00000000 */   nop
.L802438C8:
/* C74D48 802438C8 27A60024 */  addiu     $a2, $sp, 0x24
/* C74D4C 802438CC 27A20038 */  addiu     $v0, $sp, 0x38
/* C74D50 802438D0 C6220038 */  lwc1      $f2, 0x38($s1)
/* C74D54 802438D4 C620003C */  lwc1      $f0, 0x3c($s1)
/* C74D58 802438D8 3C0143C8 */  lui       $at, 0x43c8
/* C74D5C 802438DC 44813000 */  mtc1      $at, $f6
/* C74D60 802438E0 46000021 */  cvt.d.s   $f0, $f0
/* C74D64 802438E4 E7A20020 */  swc1      $f2, 0x20($sp)
/* C74D68 802438E8 3C018024 */  lui       $at, %hi(D_80245858_C76CD8)
/* C74D6C 802438EC D4225858 */  ldc1      $f2, %lo(D_80245858_C76CD8)($at)
/* C74D70 802438F0 C6240040 */  lwc1      $f4, 0x40($s1)
/* C74D74 802438F4 46220000 */  add.d     $f0, $f0, $f2
/* C74D78 802438F8 E7A60038 */  swc1      $f6, 0x38($sp)
/* C74D7C 802438FC E7A40028 */  swc1      $f4, 0x28($sp)
/* C74D80 80243900 46200020 */  cvt.s.d   $f0, $f0
/* C74D84 80243904 E7A00024 */  swc1      $f0, 0x24($sp)
/* C74D88 80243908 AFA20010 */  sw        $v0, 0x10($sp)
/* C74D8C 8024390C 8E240080 */  lw        $a0, 0x80($s1)
/* C74D90 80243910 0C0372DF */  jal       npc_raycast_down_sides
/* C74D94 80243914 27A70028 */   addiu    $a3, $sp, 0x28
/* C74D98 80243918 10400003 */  beqz      $v0, .L80243928
/* C74D9C 8024391C 00000000 */   nop
/* C74DA0 80243920 C7A00024 */  lwc1      $f0, 0x24($sp)
/* C74DA4 80243924 E620003C */  swc1      $f0, 0x3c($s1)
.L80243928:
/* C74DA8 80243928 C62C0038 */  lwc1      $f12, 0x38($s1)
/* C74DAC 8024392C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C74DB0 80243930 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C74DB4 80243934 C62E0040 */  lwc1      $f14, 0x40($s1)
/* C74DB8 80243938 8C460028 */  lw        $a2, 0x28($v0)
/* C74DBC 8024393C 0C00A720 */  jal       atan2
/* C74DC0 80243940 8C470030 */   lw       $a3, 0x30($v0)
/* C74DC4 80243944 0220202D */  daddu     $a0, $s1, $zero
/* C74DC8 80243948 24050321 */  addiu     $a1, $zero, 0x321
/* C74DCC 8024394C 0000302D */  daddu     $a2, $zero, $zero
/* C74DD0 80243950 0C012530 */  jal       ai_enemy_play_sound
/* C74DD4 80243954 E620000C */   swc1     $f0, 0xc($s1)
/* C74DD8 80243958 8EC200CC */  lw        $v0, 0xcc($s6)
/* C74DDC 8024395C 8C420024 */  lw        $v0, 0x24($v0)
/* C74DE0 80243960 AE220028 */  sw        $v0, 0x28($s1)
/* C74DE4 80243964 96C20096 */  lhu       $v0, 0x96($s6)
/* C74DE8 80243968 A622008E */  sh        $v0, 0x8e($s1)
/* C74DEC 8024396C 8FA80080 */  lw        $t0, 0x80($sp)
/* C74DF0 80243970 2402000B */  addiu     $v0, $zero, 0xb
/* C74DF4 80243974 AD020070 */  sw        $v0, 0x70($t0)
.L80243978:
/* C74DF8 80243978 8FBF0064 */  lw        $ra, 0x64($sp)
/* C74DFC 8024397C 8FBE0060 */  lw        $fp, 0x60($sp)
/* C74E00 80243980 8FB7005C */  lw        $s7, 0x5c($sp)
/* C74E04 80243984 8FB60058 */  lw        $s6, 0x58($sp)
/* C74E08 80243988 8FB50054 */  lw        $s5, 0x54($sp)
/* C74E0C 8024398C 8FB40050 */  lw        $s4, 0x50($sp)
/* C74E10 80243990 8FB3004C */  lw        $s3, 0x4c($sp)
/* C74E14 80243994 8FB20048 */  lw        $s2, 0x48($sp)
/* C74E18 80243998 8FB10044 */  lw        $s1, 0x44($sp)
/* C74E1C 8024399C 8FB00040 */  lw        $s0, 0x40($sp)
/* C74E20 802439A0 D7B80078 */  ldc1      $f24, 0x78($sp)
/* C74E24 802439A4 D7B60070 */  ldc1      $f22, 0x70($sp)
/* C74E28 802439A8 D7B40068 */  ldc1      $f20, 0x68($sp)
/* C74E2C 802439AC 03E00008 */  jr        $ra
/* C74E30 802439B0 27BD0080 */   addiu    $sp, $sp, 0x80
