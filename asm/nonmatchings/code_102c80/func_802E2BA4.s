.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E2BA4
/* 104424 802E2BA4 27BDFE80 */  addiu     $sp, $sp, -0x180
/* 104428 802E2BA8 AFB20130 */  sw        $s2, 0x130($sp)
/* 10442C 802E2BAC 3C12800A */  lui       $s2, %hi(D_8009A66C)
/* 104430 802E2BB0 8E52A66C */  lw        $s2, %lo(D_8009A66C)($s2)
/* 104434 802E2BB4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* 104438 802E2BB8 3C0143B4 */  lui       $at, 0x43b4
/* 10443C 802E2BBC 4481D000 */  mtc1      $at, $f26
/* 104440 802E2BC0 AFB70144 */  sw        $s7, 0x144($sp)
/* 104444 802E2BC4 0000B82D */  daddu     $s7, $zero, $zero
/* 104448 802E2BC8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* 10444C 802E2BCC 3C013B80 */  lui       $at, 0x3b80
/* 104450 802E2BD0 4481C000 */  mtc1      $at, $f24
/* 104454 802E2BD4 27A80098 */  addiu     $t0, $sp, 0x98
/* 104458 802E2BD8 AFB60140 */  sw        $s6, 0x140($sp)
/* 10445C 802E2BDC 27B600D8 */  addiu     $s6, $sp, 0xd8
/* 104460 802E2BE0 AFB5013C */  sw        $s5, 0x13c($sp)
/* 104464 802E2BE4 27B50058 */  addiu     $s5, $sp, 0x58
/* 104468 802E2BE8 AFA80120 */  sw        $t0, 0x120($sp)
/* 10446C 802E2BEC 3C080001 */  lui       $t0, 1
/* 104470 802E2BF0 F7B60158 */  sdc1      $f22, 0x158($sp)
/* 104474 802E2BF4 3C013F80 */  lui       $at, 0x3f80
/* 104478 802E2BF8 4481B000 */  mtc1      $at, $f22
/* 10447C 802E2BFC 35081630 */  ori       $t0, $t0, 0x1630
/* 104480 802E2C00 AFBF014C */  sw        $ra, 0x14c($sp)
/* 104484 802E2C04 AFBE0148 */  sw        $fp, 0x148($sp)
/* 104488 802E2C08 AFB40138 */  sw        $s4, 0x138($sp)
/* 10448C 802E2C0C AFB30134 */  sw        $s3, 0x134($sp)
/* 104490 802E2C10 AFB1012C */  sw        $s1, 0x12c($sp)
/* 104494 802E2C14 AFB00128 */  sw        $s0, 0x128($sp)
/* 104498 802E2C18 F7BE0178 */  sdc1      $f30, 0x178($sp)
/* 10449C 802E2C1C F7BC0170 */  sdc1      $f28, 0x170($sp)
/* 1044A0 802E2C20 F7B40150 */  sdc1      $f20, 0x150($sp)
/* 1044A4 802E2C24 0C04417A */  jal       get_entity_by_index
/* 1044A8 802E2C28 AFA80124 */   sw       $t0, 0x124($sp)
/* 1044AC 802E2C2C AFA2011C */  sw        $v0, 0x11c($sp)
/* 1044B0 802E2C30 8C540040 */  lw        $s4, 0x40($v0)
/* 1044B4 802E2C34 4480A000 */  mtc1      $zero, $f20
/* 1044B8 802E2C38 C4400048 */  lwc1      $f0, 0x48($v0)
/* 1044BC 802E2C3C 0280982D */  daddu     $s3, $s4, $zero
/* 1044C0 802E2C40 2651FFFC */  addiu     $s1, $s2, -4
/* 1044C4 802E2C44 46000007 */  neg.s     $f0, $f0
/* 1044C8 802E2C48 E7A00118 */  swc1      $f0, 0x118($sp)
/* 1044CC 802E2C4C C440004C */  lwc1      $f0, 0x4c($v0)
/* 1044D0 802E2C50 C4420050 */  lwc1      $f2, 0x50($v0)
/* 1044D4 802E2C54 8E9E0034 */  lw        $fp, 0x34($s4)
/* 1044D8 802E2C58 46000787 */  neg.s     $f30, $f0
/* 1044DC 802E2C5C 46001707 */  neg.s     $f28, $f2
.L802E2C60:
/* 1044E0 802E2C60 8683003C */  lh        $v1, 0x3c($s4)
/* 1044E4 802E2C64 240200FF */  addiu     $v0, $zero, 0xff
/* 1044E8 802E2C68 1462000F */  bne       $v1, $v0, .L802E2CA8
/* 1044EC 802E2C6C 26310008 */   addiu    $s1, $s1, 8
/* 1044F0 802E2C70 3C03E200 */  lui       $v1, 0xe200
/* 1044F4 802E2C74 3463001C */  ori       $v1, $v1, 0x1c
/* 1044F8 802E2C78 3C020055 */  lui       $v0, 0x55
/* 1044FC 802E2C7C 34422078 */  ori       $v0, $v0, 0x2078
/* 104500 802E2C80 AE23FFFC */  sw        $v1, -4($s1)
/* 104504 802E2C84 AE220000 */  sw        $v0, ($s1)
/* 104508 802E2C88 26310008 */  addiu     $s1, $s1, 8
/* 10450C 802E2C8C 26520010 */  addiu     $s2, $s2, 0x10
/* 104510 802E2C90 3C03FC12 */  lui       $v1, 0xfc12
/* 104514 802E2C94 34631824 */  ori       $v1, $v1, 0x1824
/* 104518 802E2C98 3C02FF33 */  lui       $v0, 0xff33
/* 10451C 802E2C9C 3442FFFF */  ori       $v0, $v0, 0xffff
/* 104520 802E2CA0 080B8B35 */  j         .L802E2CD4
/* 104524 802E2CA4 AE23FFFC */   sw       $v1, -4($s1)
.L802E2CA8:
/* 104528 802E2CA8 3C03FCFF */  lui       $v1, 0xfcff
/* 10452C 802E2CAC 3463C3FF */  ori       $v1, $v1, 0xc3ff
/* 104530 802E2CB0 3C02FF30 */  lui       $v0, 0xff30
/* 104534 802E2CB4 3442FE7F */  ori       $v0, $v0, 0xfe7f
/* 104538 802E2CB8 AE23FFFC */  sw        $v1, -4($s1)
/* 10453C 802E2CBC AE220000 */  sw        $v0, ($s1)
/* 104540 802E2CC0 26310008 */  addiu     $s1, $s1, 8
/* 104544 802E2CC4 3C02FA00 */  lui       $v0, 0xfa00
/* 104548 802E2CC8 AE22FFFC */  sw        $v0, -4($s1)
/* 10454C 802E2CCC 9282003D */  lbu       $v0, 0x3d($s4)
/* 104550 802E2CD0 26520010 */  addiu     $s2, $s2, 0x10
.L802E2CD4:
/* 104554 802E2CD4 AE220000 */  sw        $v0, ($s1)
/* 104558 802E2CD8 8FA50118 */  lw        $a1, 0x118($sp)
/* 10455C 802E2CDC 4406F000 */  mfc1      $a2, $f30
/* 104560 802E2CE0 4407E000 */  mfc1      $a3, $f28
/* 104564 802E2CE4 0C019E40 */  jal       guTranslateF
/* 104568 802E2CE8 27A40018 */   addiu    $a0, $sp, 0x18
/* 10456C 802E2CEC 02978021 */  addu      $s0, $s4, $s7
/* 104570 802E2CF0 9202008B */  lbu       $v0, 0x8b($s0)
/* 104574 802E2CF4 44820000 */  mtc1      $v0, $f0
/* 104578 802E2CF8 00000000 */  nop       
/* 10457C 802E2CFC 46800020 */  cvt.s.w   $f0, $f0
/* 104580 802E2D00 461A0002 */  mul.s     $f0, $f0, $f26
/* 104584 802E2D04 00000000 */  nop       
/* 104588 802E2D08 46180002 */  mul.s     $f0, $f0, $f24
/* 10458C 802E2D0C 00000000 */  nop       
/* 104590 802E2D10 4406B000 */  mfc1      $a2, $f22
/* 104594 802E2D14 4407A000 */  mfc1      $a3, $f20
/* 104598 802E2D18 8FA40120 */  lw        $a0, 0x120($sp)
/* 10459C 802E2D1C 44050000 */  mfc1      $a1, $f0
/* 1045A0 802E2D20 0C019EC8 */  jal       guRotateF
/* 1045A4 802E2D24 E7B40010 */   swc1     $f20, 0x10($sp)
/* 1045A8 802E2D28 920200A4 */  lbu       $v0, 0xa4($s0)
/* 1045AC 802E2D2C 44820000 */  mtc1      $v0, $f0
/* 1045B0 802E2D30 00000000 */  nop       
/* 1045B4 802E2D34 46800020 */  cvt.s.w   $f0, $f0
/* 1045B8 802E2D38 461A0002 */  mul.s     $f0, $f0, $f26
/* 1045BC 802E2D3C 00000000 */  nop       
/* 1045C0 802E2D40 26310008 */  addiu     $s1, $s1, 8
/* 1045C4 802E2D44 46180002 */  mul.s     $f0, $f0, $f24
/* 1045C8 802E2D48 00000000 */  nop       
/* 1045CC 802E2D4C 26520018 */  addiu     $s2, $s2, 0x18
/* 1045D0 802E2D50 26F70001 */  addiu     $s7, $s7, 1
/* 1045D4 802E2D54 4406A000 */  mfc1      $a2, $f20
/* 1045D8 802E2D58 4407B000 */  mfc1      $a3, $f22
/* 1045DC 802E2D5C 44050000 */  mfc1      $a1, $f0
/* 1045E0 802E2D60 02C0202D */  daddu     $a0, $s6, $zero
/* 1045E4 802E2D64 0C019EC8 */  jal       guRotateF
/* 1045E8 802E2D68 E7B40010 */   swc1     $f20, 0x10($sp)
/* 1045EC 802E2D6C 02C0282D */  daddu     $a1, $s6, $zero
/* 1045F0 802E2D70 8FA40120 */  lw        $a0, 0x120($sp)
/* 1045F4 802E2D74 0C019D80 */  jal       guMtxCatF
/* 1045F8 802E2D78 02C0302D */   daddu    $a2, $s6, $zero
/* 1045FC 802E2D7C 02C0202D */  daddu     $a0, $s6, $zero
/* 104600 802E2D80 27A50018 */  addiu     $a1, $sp, 0x18
/* 104604 802E2D84 0C019D80 */  jal       guMtxCatF
/* 104608 802E2D88 00A0302D */   daddu    $a2, $a1, $zero
/* 10460C 802E2D8C 02A0202D */  daddu     $a0, $s5, $zero
/* 104610 802E2D90 8E6500C0 */  lw        $a1, 0xc0($s3)
/* 104614 802E2D94 8E660124 */  lw        $a2, 0x124($s3)
/* 104618 802E2D98 8E670188 */  lw        $a3, 0x188($s3)
/* 10461C 802E2D9C 0C019E40 */  jal       guTranslateF
/* 104620 802E2DA0 26730004 */   addiu    $s3, $s3, 4
/* 104624 802E2DA4 27A40018 */  addiu     $a0, $sp, 0x18
/* 104628 802E2DA8 02A0282D */  daddu     $a1, $s5, $zero
/* 10462C 802E2DAC 0C019D80 */  jal       guMtxCatF
/* 104630 802E2DB0 02A0302D */   daddu    $a2, $s5, $zero
/* 104634 802E2DB4 02A0202D */  daddu     $a0, $s5, $zero
/* 104638 802E2DB8 3C058007 */  lui       $a1, %hi(D_800741F0)
/* 10463C 802E2DBC 94A541F0 */  lhu       $a1, %lo(D_800741F0)($a1)
/* 104640 802E2DC0 3C02800A */  lui       $v0, %hi(D_8009A674)
/* 104644 802E2DC4 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* 104648 802E2DC8 8FA80124 */  lw        $t0, 0x124($sp)
/* 10464C 802E2DCC 00052980 */  sll       $a1, $a1, 6
/* 104650 802E2DD0 00A82821 */  addu      $a1, $a1, $t0
/* 104654 802E2DD4 0C019D40 */  jal       guMtxF2L
/* 104658 802E2DD8 00452821 */   addu     $a1, $v0, $a1
/* 10465C 802E2DDC 3C05D838 */  lui       $a1, 0xd838
/* 104660 802E2DE0 34A50002 */  ori       $a1, $a1, 2
/* 104664 802E2DE4 3C028007 */  lui       $v0, %hi(D_800741F0)
/* 104668 802E2DE8 944241F0 */  lhu       $v0, %lo(D_800741F0)($v0)
/* 10466C 802E2DEC 3C03DA38 */  lui       $v1, 0xda38
/* 104670 802E2DF0 AE23FFFC */  sw        $v1, -4($s1)
/* 104674 802E2DF4 8FA80124 */  lw        $t0, 0x124($sp)
/* 104678 802E2DF8 24430001 */  addiu     $v1, $v0, 1
/* 10467C 802E2DFC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 104680 802E2E00 00021180 */  sll       $v0, $v0, 6
/* 104684 802E2E04 3C018007 */  lui       $at, %hi(D_800741F0)
/* 104688 802E2E08 A42341F0 */  sh        $v1, %lo(D_800741F0)($at)
/* 10468C 802E2E0C 3C03800A */  lui       $v1, %hi(D_8009A674)
/* 104690 802E2E10 8C63A674 */  lw        $v1, %lo(D_8009A674)($v1)
/* 104694 802E2E14 00481021 */  addu      $v0, $v0, $t0
/* 104698 802E2E18 00621821 */  addu      $v1, $v1, $v0
/* 10469C 802E2E1C AE230000 */  sw        $v1, ($s1)
/* 1046A0 802E2E20 97C40002 */  lhu       $a0, 2($fp)
/* 1046A4 802E2E24 27DE0004 */  addiu     $fp, $fp, 4
/* 1046A8 802E2E28 8FA8011C */  lw        $t0, 0x11c($sp)
/* 1046AC 802E2E2C 26310008 */  addiu     $s1, $s1, 8
/* 1046B0 802E2E30 8D030044 */  lw        $v1, 0x44($t0)
/* 1046B4 802E2E34 3C02DE00 */  lui       $v0, 0xde00
/* 1046B8 802E2E38 AE22FFFC */  sw        $v0, -4($s1)
/* 1046BC 802E2E3C 24020040 */  addiu     $v0, $zero, 0x40
/* 1046C0 802E2E40 00641821 */  addu      $v1, $v1, $a0
/* 1046C4 802E2E44 AE230000 */  sw        $v1, ($s1)
/* 1046C8 802E2E48 26310008 */  addiu     $s1, $s1, 8
/* 1046CC 802E2E4C AE220000 */  sw        $v0, ($s1)
/* 1046D0 802E2E50 2AE20018 */  slti      $v0, $s7, 0x18
/* 1046D4 802E2E54 1440FF82 */  bnez      $v0, .L802E2C60
/* 1046D8 802E2E58 AE25FFFC */   sw       $a1, -4($s1)
/* 1046DC 802E2E5C 8FBF014C */  lw        $ra, 0x14c($sp)
/* 1046E0 802E2E60 8FBE0148 */  lw        $fp, 0x148($sp)
/* 1046E4 802E2E64 8FB70144 */  lw        $s7, 0x144($sp)
/* 1046E8 802E2E68 8FB60140 */  lw        $s6, 0x140($sp)
/* 1046EC 802E2E6C 8FB5013C */  lw        $s5, 0x13c($sp)
/* 1046F0 802E2E70 8FB40138 */  lw        $s4, 0x138($sp)
/* 1046F4 802E2E74 8FB30134 */  lw        $s3, 0x134($sp)
/* 1046F8 802E2E78 3C01800A */  lui       $at, %hi(D_8009A66C)
/* 1046FC 802E2E7C AC32A66C */  sw        $s2, %lo(D_8009A66C)($at)
/* 104700 802E2E80 8FB20130 */  lw        $s2, 0x130($sp)
/* 104704 802E2E84 8FB1012C */  lw        $s1, 0x12c($sp)
/* 104708 802E2E88 8FB00128 */  lw        $s0, 0x128($sp)
/* 10470C 802E2E8C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* 104710 802E2E90 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* 104714 802E2E94 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* 104718 802E2E98 D7B80160 */  ldc1      $f24, 0x160($sp)
/* 10471C 802E2E9C D7B60158 */  ldc1      $f22, 0x158($sp)
/* 104720 802E2EA0 D7B40150 */  ldc1      $f20, 0x150($sp)
/* 104724 802E2EA4 03E00008 */  jr        $ra
/* 104728 802E2EA8 27BD0180 */   addiu    $sp, $sp, 0x180
/* 10472C 802E2EAC 00000000 */  nop       
