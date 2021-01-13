.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419C4_EAA4A4
/* EAA4A4 802419C4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EAA4A8 802419C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* EAA4AC 802419CC 0080882D */  daddu     $s1, $a0, $zero
/* EAA4B0 802419D0 AFBF0034 */  sw        $ra, 0x34($sp)
/* EAA4B4 802419D4 AFB60030 */  sw        $s6, 0x30($sp)
/* EAA4B8 802419D8 AFB5002C */  sw        $s5, 0x2c($sp)
/* EAA4BC 802419DC AFB40028 */  sw        $s4, 0x28($sp)
/* EAA4C0 802419E0 AFB30024 */  sw        $s3, 0x24($sp)
/* EAA4C4 802419E4 AFB20020 */  sw        $s2, 0x20($sp)
/* EAA4C8 802419E8 AFB00018 */  sw        $s0, 0x18($sp)
/* EAA4CC 802419EC F7B60040 */  sdc1      $f22, 0x40($sp)
/* EAA4D0 802419F0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* EAA4D4 802419F4 8E30000C */  lw        $s0, 0xc($s1)
/* EAA4D8 802419F8 8E160000 */  lw        $s6, ($s0)
/* EAA4DC 802419FC 26100004 */  addiu     $s0, $s0, 4
/* EAA4E0 80241A00 0C0B53A3 */  jal       func_802D4E8C
/* EAA4E4 80241A04 02C0282D */   daddu    $a1, $s6, $zero
/* EAA4E8 80241A08 44820000 */  mtc1      $v0, $f0
/* EAA4EC 80241A0C 00000000 */  nop
/* EAA4F0 80241A10 46800020 */  cvt.s.w   $f0, $f0
/* EAA4F4 80241A14 E7A00010 */  swc1      $f0, 0x10($sp)
/* EAA4F8 80241A18 8E140000 */  lw        $s4, ($s0)
/* EAA4FC 80241A1C 26100004 */  addiu     $s0, $s0, 4
/* EAA500 80241A20 0220202D */  daddu     $a0, $s1, $zero
/* EAA504 80241A24 0C0B53A3 */  jal       func_802D4E8C
/* EAA508 80241A28 0280282D */   daddu    $a1, $s4, $zero
/* EAA50C 80241A2C 0220202D */  daddu     $a0, $s1, $zero
/* EAA510 80241A30 8E150000 */  lw        $s5, ($s0)
/* EAA514 80241A34 4482B000 */  mtc1      $v0, $f22
/* EAA518 80241A38 00000000 */  nop
/* EAA51C 80241A3C 4680B5A0 */  cvt.s.w   $f22, $f22
/* EAA520 80241A40 0C0B53A3 */  jal       func_802D4E8C
/* EAA524 80241A44 02A0282D */   daddu    $a1, $s5, $zero
/* EAA528 80241A48 2404FFFC */  addiu     $a0, $zero, -4
/* EAA52C 80241A4C 44820000 */  mtc1      $v0, $f0
/* EAA530 80241A50 00000000 */  nop
/* EAA534 80241A54 46800020 */  cvt.s.w   $f0, $f0
/* EAA538 80241A58 0C00F92F */  jal       func_8003E4BC
/* EAA53C 80241A5C E7A00014 */   swc1     $f0, 0x14($sp)
/* EAA540 80241A60 3C048008 */  lui       $a0, %hi(D_8007C760)
/* EAA544 80241A64 8C84C760 */  lw        $a0, %lo(D_8007C760)($a0)
/* EAA548 80241A68 3C014334 */  lui       $at, 0x4334
/* EAA54C 80241A6C 44816000 */  mtc1      $at, $f12
/* EAA550 80241A70 00041880 */  sll       $v1, $a0, 2
/* EAA554 80241A74 00641821 */  addu      $v1, $v1, $a0
/* EAA558 80241A78 00031880 */  sll       $v1, $v1, 2
/* EAA55C 80241A7C 00641823 */  subu      $v1, $v1, $a0
/* EAA560 80241A80 000320C0 */  sll       $a0, $v1, 3
/* EAA564 80241A84 00641821 */  addu      $v1, $v1, $a0
/* EAA568 80241A88 000318C0 */  sll       $v1, $v1, 3
/* EAA56C 80241A8C 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EAA570 80241A90 00230821 */  addu      $at, $at, $v1
/* EAA574 80241A94 C4208DEC */  lwc1      $f0, %lo(D_800B8DEC)($at)
/* EAA578 80241A98 460C0300 */  add.s     $f12, $f0, $f12
/* EAA57C 80241A9C 0C00AB85 */  jal       func_8002AE14
/* EAA580 80241AA0 0040982D */   daddu    $s3, $v0, $zero
/* EAA584 80241AA4 27B00010 */  addiu     $s0, $sp, 0x10
/* EAA588 80241AA8 0200202D */  daddu     $a0, $s0, $zero
/* EAA58C 80241AAC 27B20014 */  addiu     $s2, $sp, 0x14
/* EAA590 80241AB0 0240282D */  daddu     $a1, $s2, $zero
/* EAA594 80241AB4 3C064170 */  lui       $a2, 0x4170
/* EAA598 80241AB8 8E67000C */  lw        $a3, 0xc($s3)
/* EAA59C 80241ABC 0C00ACA3 */  jal       func_8002B28C
/* EAA5A0 80241AC0 46000506 */   mov.s    $f20, $f0
/* EAA5A4 80241AC4 0200202D */  daddu     $a0, $s0, $zero
/* EAA5A8 80241AC8 3C064120 */  lui       $a2, 0x4120
/* EAA5AC 80241ACC 4407A000 */  mfc1      $a3, $f20
/* EAA5B0 80241AD0 0C00ACA3 */  jal       func_8002B28C
/* EAA5B4 80241AD4 0240282D */   daddu    $a1, $s2, $zero
/* EAA5B8 80241AD8 0220202D */  daddu     $a0, $s1, $zero
/* EAA5BC 80241ADC C7A00010 */  lwc1      $f0, 0x10($sp)
/* EAA5C0 80241AE0 4600008D */  trunc.w.s $f2, $f0
/* EAA5C4 80241AE4 44061000 */  mfc1      $a2, $f2
/* EAA5C8 80241AE8 0C0B551A */  jal       func_802D5468
/* EAA5CC 80241AEC 02C0282D */   daddu    $a1, $s6, $zero
/* EAA5D0 80241AF0 0220202D */  daddu     $a0, $s1, $zero
/* EAA5D4 80241AF4 4600B08D */  trunc.w.s $f2, $f22
/* EAA5D8 80241AF8 44061000 */  mfc1      $a2, $f2
/* EAA5DC 80241AFC 0C0B551A */  jal       func_802D5468
/* EAA5E0 80241B00 0280282D */   daddu    $a1, $s4, $zero
/* EAA5E4 80241B04 0220202D */  daddu     $a0, $s1, $zero
/* EAA5E8 80241B08 C7A00014 */  lwc1      $f0, 0x14($sp)
/* EAA5EC 80241B0C 4600008D */  trunc.w.s $f2, $f0
/* EAA5F0 80241B10 44061000 */  mfc1      $a2, $f2
/* EAA5F4 80241B14 0C0B551A */  jal       func_802D5468
/* EAA5F8 80241B18 02A0282D */   daddu    $a1, $s5, $zero
/* EAA5FC 80241B1C 8FBF0034 */  lw        $ra, 0x34($sp)
/* EAA600 80241B20 8FB60030 */  lw        $s6, 0x30($sp)
/* EAA604 80241B24 8FB5002C */  lw        $s5, 0x2c($sp)
/* EAA608 80241B28 8FB40028 */  lw        $s4, 0x28($sp)
/* EAA60C 80241B2C 8FB30024 */  lw        $s3, 0x24($sp)
/* EAA610 80241B30 8FB20020 */  lw        $s2, 0x20($sp)
/* EAA614 80241B34 8FB1001C */  lw        $s1, 0x1c($sp)
/* EAA618 80241B38 8FB00018 */  lw        $s0, 0x18($sp)
/* EAA61C 80241B3C D7B60040 */  ldc1      $f22, 0x40($sp)
/* EAA620 80241B40 D7B40038 */  ldc1      $f20, 0x38($sp)
/* EAA624 80241B44 24020002 */  addiu     $v0, $zero, 2
/* EAA628 80241B48 03E00008 */  jr        $ra
/* EAA62C 80241B4C 27BD0048 */   addiu    $sp, $sp, 0x48
