.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E0036650
.double 0.6, 0.0

.section .text

glabel got_item_outline_appendGfx
/* 345704 E0036224 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 345708 E0036228 0080402D */  daddu     $t0, $a0, $zero
/* 34570C E003622C AFBF00B8 */  sw        $ra, 0xb8($sp)
/* 345710 E0036230 AFB700B4 */  sw        $s7, 0xb4($sp)
/* 345714 E0036234 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 345718 E0036238 AFB500AC */  sw        $s5, 0xac($sp)
/* 34571C E003623C AFB400A8 */  sw        $s4, 0xa8($sp)
/* 345720 E0036240 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 345724 E0036244 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 345728 E0036248 AFB1009C */  sw        $s1, 0x9c($sp)
/* 34572C E003624C AFB00098 */  sw        $s0, 0x98($sp)
/* 345730 E0036250 F7B800D0 */  sdc1      $f24, 0xd0($sp)
/* 345734 E0036254 F7B600C8 */  sdc1      $f22, 0xc8($sp)
/* 345738 E0036258 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 34573C E003625C 8D07000C */  lw        $a3, 0xc($t0)
/* 345740 E0036260 44800000 */  mtc1      $zero, $f0
/* 345744 E0036264 C4F80018 */  lwc1      $f24, 0x18($a3)
/* 345748 E0036268 8CF30000 */  lw        $s3, ($a3)
/* 34574C E003626C 4600C032 */  c.eq.s    $f24, $f0
/* 345750 E0036270 00000000 */  nop
/* 345754 E0036274 450100E0 */  bc1t      .LE00365F8
/* 345758 E0036278 3C04DB06 */   lui      $a0, 0xdb06
/* 34575C E003627C 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 345760 E0036280 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 345764 E0036284 34840024 */  ori       $a0, $a0, 0x24
/* 345768 E0036288 8CC50000 */  lw        $a1, ($a2)
/* 34576C E003628C 3C02E700 */  lui       $v0, 0xe700
/* 345770 E0036290 00A0182D */  daddu     $v1, $a1, $zero
/* 345774 E0036294 24A50008 */  addiu     $a1, $a1, 8
/* 345778 E0036298 ACC50000 */  sw        $a1, ($a2)
/* 34577C E003629C AC620000 */  sw        $v0, ($v1)
/* 345780 E00362A0 24A20008 */  addiu     $v0, $a1, 8
/* 345784 E00362A4 AC600004 */  sw        $zero, 4($v1)
/* 345788 E00362A8 ACC20000 */  sw        $v0, ($a2)
/* 34578C E00362AC ACA40000 */  sw        $a0, ($a1)
/* 345790 E00362B0 8D030010 */  lw        $v1, 0x10($t0)
/* 345794 E00362B4 24A20010 */  addiu     $v0, $a1, 0x10
/* 345798 E00362B8 ACC20000 */  sw        $v0, ($a2)
/* 34579C E00362BC 8C63001C */  lw        $v1, 0x1c($v1)
/* 3457A0 E00362C0 3C02DE00 */  lui       $v0, 0xde00
/* 3457A4 E00362C4 ACA20008 */  sw        $v0, 8($a1)
/* 3457A8 E00362C8 3C020901 */  lui       $v0, 0x901
/* 3457AC E00362CC 24428100 */  addiu     $v0, $v0, -0x7f00
/* 3457B0 E00362D0 ACA2000C */  sw        $v0, 0xc($a1)
/* 3457B4 E00362D4 3C028000 */  lui       $v0, 0x8000
/* 3457B8 E00362D8 00621821 */  addu      $v1, $v1, $v0
/* 3457BC E00362DC 1660000E */  bnez      $s3, .LE0036318
/* 3457C0 E00362E0 ACA30004 */   sw       $v1, 4($a1)
/* 3457C4 E00362E4 24A20018 */  addiu     $v0, $a1, 0x18
/* 3457C8 E00362E8 ACC20000 */  sw        $v0, ($a2)
/* 3457CC E00362EC 3C02FA00 */  lui       $v0, 0xfa00
/* 3457D0 E00362F0 ACA20010 */  sw        $v0, 0x10($a1)
/* 3457D4 E00362F4 90E3001F */  lbu       $v1, 0x1f($a3)
/* 3457D8 E00362F8 24A20020 */  addiu     $v0, $a1, 0x20
/* 3457DC E00362FC ACC20000 */  sw        $v0, ($a2)
/* 3457E0 E0036300 3C02FB00 */  lui       $v0, 0xfb00
/* 3457E4 E0036304 ACA20018 */  sw        $v0, 0x18($a1)
/* 3457E8 E0036308 240200FF */  addiu     $v0, $zero, 0xff
/* 3457EC E003630C ACA2001C */  sw        $v0, 0x1c($a1)
/* 3457F0 E0036310 0800D8D3 */  j         .LE003634C
/* 3457F4 E0036314 2402FF00 */   addiu    $v0, $zero, -0x100
.LE0036318:
/* 3457F8 E0036318 3C04FFFF */  lui       $a0, 0xffff
/* 3457FC E003631C 348400FF */  ori       $a0, $a0, 0xff
/* 345800 E0036320 24A20018 */  addiu     $v0, $a1, 0x18
/* 345804 E0036324 ACC20000 */  sw        $v0, ($a2)
/* 345808 E0036328 3C02FA00 */  lui       $v0, 0xfa00
/* 34580C E003632C ACA20010 */  sw        $v0, 0x10($a1)
/* 345810 E0036330 90E3001F */  lbu       $v1, 0x1f($a3)
/* 345814 E0036334 24A20020 */  addiu     $v0, $a1, 0x20
/* 345818 E0036338 ACC20000 */  sw        $v0, ($a2)
/* 34581C E003633C 3C02FB00 */  lui       $v0, 0xfb00
/* 345820 E0036340 ACA20018 */  sw        $v0, 0x18($a1)
/* 345824 E0036344 2402FF00 */  addiu     $v0, $zero, -0x100
/* 345828 E0036348 ACA4001C */  sw        $a0, 0x1c($a1)
.LE003634C:
/* 34582C E003634C 00621825 */  or        $v1, $v1, $v0
/* 345830 E0036350 ACA30014 */  sw        $v1, 0x14($a1)
/* 345834 E0036354 8CE50004 */  lw        $a1, 4($a3)
/* 345838 E0036358 8CE60008 */  lw        $a2, 8($a3)
/* 34583C E003635C 8CE7000C */  lw        $a3, 0xc($a3)
/* 345840 E0036360 0C080108 */  jal       shim_guTranslateF
/* 345844 E0036364 27A40018 */   addiu    $a0, $sp, 0x18
/* 345848 E0036368 27B00058 */  addiu     $s0, $sp, 0x58
/* 34584C E003636C 4480A000 */  mtc1      $zero, $f20
/* 345850 E0036370 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 345854 E0036374 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 345858 E0036378 3C013F80 */  lui       $at, 0x3f80
/* 34585C E003637C 4481B000 */  mtc1      $at, $f22
/* 345860 E0036380 00031080 */  sll       $v0, $v1, 2
/* 345864 E0036384 00431021 */  addu      $v0, $v0, $v1
/* 345868 E0036388 00021080 */  sll       $v0, $v0, 2
/* 34586C E003638C 00431023 */  subu      $v0, $v0, $v1
/* 345870 E0036390 000218C0 */  sll       $v1, $v0, 3
/* 345874 E0036394 00431021 */  addu      $v0, $v0, $v1
/* 345878 E0036398 000210C0 */  sll       $v0, $v0, 3
/* 34587C E003639C 4406A000 */  mfc1      $a2, $f20
/* 345880 E00363A0 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 345884 E00363A4 00220821 */  addu      $at, $at, $v0
/* 345888 E00363A8 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 34588C E00363AC 4407B000 */  mfc1      $a3, $f22
/* 345890 E00363B0 46000007 */  neg.s     $f0, $f0
/* 345894 E00363B4 44050000 */  mfc1      $a1, $f0
/* 345898 E00363B8 0200202D */  daddu     $a0, $s0, $zero
/* 34589C E00363BC 0C080104 */  jal       shim_guRotateF
/* 3458A0 E00363C0 E7B40010 */   swc1     $f20, 0x10($sp)
/* 3458A4 E00363C4 0200202D */  daddu     $a0, $s0, $zero
/* 3458A8 E00363C8 27A50018 */  addiu     $a1, $sp, 0x18
/* 3458AC E00363CC 0C080114 */  jal       shim_guMtxCatF
/* 3458B0 E00363D0 00A0302D */   daddu    $a2, $a1, $zero
/* 3458B4 E00363D4 0200202D */  daddu     $a0, $s0, $zero
/* 3458B8 E00363D8 4405A000 */  mfc1      $a1, $f20
/* 3458BC E00363DC 3C07C000 */  lui       $a3, 0xc000
/* 3458C0 E00363E0 0C080108 */  jal       shim_guTranslateF
/* 3458C4 E00363E4 00A0302D */   daddu    $a2, $a1, $zero
/* 3458C8 E00363E8 0200202D */  daddu     $a0, $s0, $zero
/* 3458CC E00363EC 27A50018 */  addiu     $a1, $sp, 0x18
/* 3458D0 E00363F0 0C080114 */  jal       shim_guMtxCatF
/* 3458D4 E00363F4 00A0302D */   daddu    $a2, $a1, $zero
/* 3458D8 E00363F8 3C01E003 */  lui       $at, %hi(D_E0036650)
/* 3458DC E00363FC D4226650 */  ldc1      $f2, %lo(D_E0036650)($at)
/* 3458E0 E0036400 4600C021 */  cvt.d.s   $f0, $f24
/* 3458E4 E0036404 46220002 */  mul.d     $f0, $f0, $f2
/* 3458E8 E0036408 00000000 */  nop
/* 3458EC E003640C 3C120001 */  lui       $s2, 1
/* 3458F0 E0036410 36521630 */  ori       $s2, $s2, 0x1630
/* 3458F4 E0036414 0200202D */  daddu     $a0, $s0, $zero
/* 3458F8 E0036418 46200620 */  cvt.s.d   $f24, $f0
/* 3458FC E003641C 4405C000 */  mfc1      $a1, $f24
/* 345900 E0036420 4407B000 */  mfc1      $a3, $f22
/* 345904 E0036424 0C080110 */  jal       shim_guScaleF
/* 345908 E0036428 00A0302D */   daddu    $a2, $a1, $zero
/* 34590C E003642C 0200202D */  daddu     $a0, $s0, $zero
/* 345910 E0036430 27A50018 */  addiu     $a1, $sp, 0x18
/* 345914 E0036434 0C080114 */  jal       shim_guMtxCatF
/* 345918 E0036438 00A0302D */   daddu    $a2, $a1, $zero
/* 34591C E003643C 27A40018 */  addiu     $a0, $sp, 0x18
/* 345920 E0036440 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 345924 E0036444 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 345928 E0036448 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 34592C E003644C 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 345930 E0036450 96050000 */  lhu       $a1, ($s0)
/* 345934 E0036454 8E220000 */  lw        $v0, ($s1)
/* 345938 E0036458 00052980 */  sll       $a1, $a1, 6
/* 34593C E003645C 00B22821 */  addu      $a1, $a1, $s2
/* 345940 E0036460 0C080118 */  jal       shim_guMtxF2L
/* 345944 E0036464 00452821 */   addu     $a1, $v0, $a1
/* 345948 E0036468 3C05DA38 */  lui       $a1, 0xda38
/* 34594C E003646C 34A50002 */  ori       $a1, $a1, 2
/* 345950 E0036470 0000482D */  daddu     $t1, $zero, $zero
/* 345954 E0036474 3C170900 */  lui       $s7, 0x900
/* 345958 E0036478 26F70000 */  addiu     $s7, $s7, 0
/* 34595C E003647C 3C160900 */  lui       $s6, 0x900
/* 345960 E0036480 26D64000 */  addiu     $s6, $s6, 0x4000
/* 345964 E0036484 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 345968 E0036488 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 34596C E003648C 0040302D */  daddu     $a2, $v0, $zero
/* 345970 E0036490 3C0DFD68 */  lui       $t5, 0xfd68
/* 345974 E0036494 35AD007F */  ori       $t5, $t5, 0x7f
/* 345978 E0036498 3C0AF568 */  lui       $t2, 0xf568
/* 34597C E003649C 354A2000 */  ori       $t2, $t2, 0x2000
/* 345980 E00364A0 3C150700 */  lui       $s5, 0x700
/* 345984 E00364A4 3C14E600 */  lui       $s4, 0xe600
/* 345988 E00364A8 3C19F400 */  lui       $t9, 0xf400
/* 34598C E00364AC 3C0C071F */  lui       $t4, 0x71f
/* 345990 E00364B0 358CC07C */  ori       $t4, $t4, 0xc07c
/* 345994 E00364B4 3C18E700 */  lui       $t8, 0xe700
/* 345998 E00364B8 3C0FF200 */  lui       $t7, 0xf200
/* 34599C E00364BC 3C0B001F */  lui       $t3, 0x1f
/* 3459A0 E00364C0 356BC07C */  ori       $t3, $t3, 0xc07c
/* 3459A4 E00364C4 3C0EDE00 */  lui       $t6, 0xde00
/* 3459A8 E00364C8 3C08E003 */  lui       $t0, %hi(D_E0036630)
/* 3459AC E00364CC 25086630 */  addiu     $t0, $t0, %lo(D_E0036630)
/* 3459B0 E00364D0 0120382D */  daddu     $a3, $t1, $zero
/* 3459B4 E00364D4 8CC30000 */  lw        $v1, ($a2)
/* 3459B8 E00364D8 96020000 */  lhu       $v0, ($s0)
/* 3459BC E00364DC 0060202D */  daddu     $a0, $v1, $zero
/* 3459C0 E00364E0 24630008 */  addiu     $v1, $v1, 8
/* 3459C4 E00364E4 ACC30000 */  sw        $v1, ($a2)
/* 3459C8 E00364E8 24430001 */  addiu     $v1, $v0, 1
/* 3459CC E00364EC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3459D0 E00364F0 00021180 */  sll       $v0, $v0, 6
/* 3459D4 E00364F4 AC850000 */  sw        $a1, ($a0)
/* 3459D8 E00364F8 A6030000 */  sh        $v1, ($s0)
/* 3459DC E00364FC 8E230000 */  lw        $v1, ($s1)
/* 3459E0 E0036500 00521021 */  addu      $v0, $v0, $s2
/* 3459E4 E0036504 00621821 */  addu      $v1, $v1, $v0
/* 3459E8 E0036508 AC830004 */  sw        $v1, 4($a0)
.LE003650C:
/* 3459EC E003650C 16600002 */  bnez      $s3, .LE0036518
/* 3459F0 E0036510 00F62021 */   addu     $a0, $a3, $s6
/* 3459F4 E0036514 00F72021 */  addu      $a0, $a3, $s7
.LE0036518:
/* 3459F8 E0036518 24E71000 */  addiu     $a3, $a3, 0x1000
/* 3459FC E003651C 8CC30000 */  lw        $v1, ($a2)
/* 345A00 E0036520 25290001 */  addiu     $t1, $t1, 1
/* 345A04 E0036524 0060102D */  daddu     $v0, $v1, $zero
/* 345A08 E0036528 24630008 */  addiu     $v1, $v1, 8
/* 345A0C E003652C AC4D0000 */  sw        $t5, ($v0)
/* 345A10 E0036530 AC440004 */  sw        $a0, 4($v0)
/* 345A14 E0036534 AC6A0000 */  sw        $t2, ($v1)
/* 345A18 E0036538 AC750004 */  sw        $s5, 4($v1)
/* 345A1C E003653C AC740008 */  sw        $s4, 8($v1)
/* 345A20 E0036540 AC60000C */  sw        $zero, 0xc($v1)
/* 345A24 E0036544 AC790010 */  sw        $t9, 0x10($v1)
/* 345A28 E0036548 AC6C0014 */  sw        $t4, 0x14($v1)
/* 345A2C E003654C AC780018 */  sw        $t8, 0x18($v1)
/* 345A30 E0036550 AC60001C */  sw        $zero, 0x1c($v1)
/* 345A34 E0036554 AC6A0020 */  sw        $t2, 0x20($v1)
/* 345A38 E0036558 AC600024 */  sw        $zero, 0x24($v1)
/* 345A3C E003655C AC6F0028 */  sw        $t7, 0x28($v1)
/* 345A40 E0036560 AC6B002C */  sw        $t3, 0x2c($v1)
/* 345A44 E0036564 AC6E0030 */  sw        $t6, 0x30($v1)
/* 345A48 E0036568 8D040000 */  lw        $a0, ($t0)
/* 345A4C E003656C 25080004 */  addiu     $t0, $t0, 4
/* 345A50 E0036570 24620008 */  addiu     $v0, $v1, 8
/* 345A54 E0036574 ACC30000 */  sw        $v1, ($a2)
/* 345A58 E0036578 ACC20000 */  sw        $v0, ($a2)
/* 345A5C E003657C 24620010 */  addiu     $v0, $v1, 0x10
/* 345A60 E0036580 ACC20000 */  sw        $v0, ($a2)
/* 345A64 E0036584 24620018 */  addiu     $v0, $v1, 0x18
/* 345A68 E0036588 ACC20000 */  sw        $v0, ($a2)
/* 345A6C E003658C 24620020 */  addiu     $v0, $v1, 0x20
/* 345A70 E0036590 ACC20000 */  sw        $v0, ($a2)
/* 345A74 E0036594 24620028 */  addiu     $v0, $v1, 0x28
/* 345A78 E0036598 ACC20000 */  sw        $v0, ($a2)
/* 345A7C E003659C 24620030 */  addiu     $v0, $v1, 0x30
/* 345A80 E00365A0 ACC20000 */  sw        $v0, ($a2)
/* 345A84 E00365A4 24620038 */  addiu     $v0, $v1, 0x38
/* 345A88 E00365A8 ACC20000 */  sw        $v0, ($a2)
/* 345A8C E00365AC 29220004 */  slti      $v0, $t1, 4
/* 345A90 E00365B0 1440FFD6 */  bnez      $v0, .LE003650C
/* 345A94 E00365B4 AC640034 */   sw       $a0, 0x34($v1)
/* 345A98 E00365B8 3C03D838 */  lui       $v1, 0xd838
/* 345A9C E00365BC 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 345AA0 E00365C0 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 345AA4 E00365C4 8C820000 */  lw        $v0, ($a0)
/* 345AA8 E00365C8 34630002 */  ori       $v1, $v1, 2
/* 345AAC E00365CC 0040282D */  daddu     $a1, $v0, $zero
/* 345AB0 E00365D0 24420008 */  addiu     $v0, $v0, 8
/* 345AB4 E00365D4 AC820000 */  sw        $v0, ($a0)
/* 345AB8 E00365D8 ACA30000 */  sw        $v1, ($a1)
/* 345ABC E00365DC 24030040 */  addiu     $v1, $zero, 0x40
/* 345AC0 E00365E0 ACA30004 */  sw        $v1, 4($a1)
/* 345AC4 E00365E4 24430008 */  addiu     $v1, $v0, 8
/* 345AC8 E00365E8 AC830000 */  sw        $v1, ($a0)
/* 345ACC E00365EC 3C03E700 */  lui       $v1, 0xe700
/* 345AD0 E00365F0 AC430000 */  sw        $v1, ($v0)
/* 345AD4 E00365F4 AC400004 */  sw        $zero, 4($v0)
.LE00365F8:
/* 345AD8 E00365F8 8FBF00B8 */  lw        $ra, 0xb8($sp)
/* 345ADC E00365FC 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 345AE0 E0036600 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 345AE4 E0036604 8FB500AC */  lw        $s5, 0xac($sp)
/* 345AE8 E0036608 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 345AEC E003660C 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 345AF0 E0036610 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 345AF4 E0036614 8FB1009C */  lw        $s1, 0x9c($sp)
/* 345AF8 E0036618 8FB00098 */  lw        $s0, 0x98($sp)
/* 345AFC E003661C D7B800D0 */  ldc1      $f24, 0xd0($sp)
/* 345B00 E0036620 D7B600C8 */  ldc1      $f22, 0xc8($sp)
/* 345B04 E0036624 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 345B08 E0036628 03E00008 */  jr        $ra
/* 345B0C E003662C 27BD00D8 */   addiu    $sp, $sp, 0xd8
