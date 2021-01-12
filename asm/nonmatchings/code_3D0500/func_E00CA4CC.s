.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00CA4CC
/* 3D09CC E00CA4CC 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* 3D09D0 E00CA4D0 0080482D */  daddu     $t1, $a0, $zero
/* 3D09D4 E00CA4D4 3C0ADB06 */  lui       $t2, 0xdb06
/* 3D09D8 E00CA4D8 354A0024 */  ori       $t2, $t2, 0x24
/* 3D09DC E00CA4DC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D09E0 E00CA4E0 AFB20078 */  sw        $s2, 0x78($sp)
/* 3D09E4 E00CA4E4 3C120001 */  lui       $s2, 1
/* 3D09E8 E00CA4E8 44800000 */  mtc1      $zero, $f0
/* 3D09EC E00CA4EC 36521630 */  ori       $s2, $s2, 0x1630
/* 3D09F0 E00CA4F0 AFB3007C */  sw        $s3, 0x7c($sp)
/* 3D09F4 E00CA4F4 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3D09F8 E00CA4F8 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3D09FC E00CA4FC AFBF0094 */  sw        $ra, 0x94($sp)
/* 3D0A00 E00CA500 AFBE0090 */  sw        $fp, 0x90($sp)
/* 3D0A04 E00CA504 AFB7008C */  sw        $s7, 0x8c($sp)
/* 3D0A08 E00CA508 AFB60088 */  sw        $s6, 0x88($sp)
/* 3D0A0C E00CA50C AFB50084 */  sw        $s5, 0x84($sp)
/* 3D0A10 E00CA510 AFB40080 */  sw        $s4, 0x80($sp)
/* 3D0A14 E00CA514 AFB10074 */  sw        $s1, 0x74($sp)
/* 3D0A18 E00CA518 AFB00070 */  sw        $s0, 0x70($sp)
/* 3D0A1C E00CA51C F7BE00C0 */  sdc1      $f30, 0xc0($sp)
/* 3D0A20 E00CA520 F7BC00B8 */  sdc1      $f28, 0xb8($sp)
/* 3D0A24 E00CA524 F7BA00B0 */  sdc1      $f26, 0xb0($sp)
/* 3D0A28 E00CA528 F7B800A8 */  sdc1      $f24, 0xa8($sp)
/* 3D0A2C E00CA52C F7B600A0 */  sdc1      $f22, 0xa0($sp)
/* 3D0A30 E00CA530 F7B40098 */  sdc1      $f20, 0x98($sp)
/* 3D0A34 E00CA534 8E680000 */  lw        $t0, ($s3)
/* 3D0A38 E00CA538 8D36000C */  lw        $s6, 0xc($t1)
/* 3D0A3C E00CA53C 0100182D */  daddu     $v1, $t0, $zero
/* 3D0A40 E00CA540 44050000 */  mfc1      $a1, $f0
/* 3D0A44 E00CA544 25080008 */  addiu     $t0, $t0, 8
/* 3D0A48 E00CA548 AE680000 */  sw        $t0, ($s3)
/* 3D0A4C E00CA54C 8ECB0014 */  lw        $t3, 0x14($s6)
/* 3D0A50 E00CA550 3C02E700 */  lui       $v0, 0xe700
/* 3D0A54 E00CA554 AFAB0050 */  sw        $t3, 0x50($sp)
/* 3D0A58 E00CA558 8ED50024 */  lw        $s5, 0x24($s6)
/* 3D0A5C E00CA55C 8ECB0000 */  lw        $t3, ($s6)
/* 3D0A60 E00CA560 00A0302D */  daddu     $a2, $a1, $zero
/* 3D0A64 E00CA564 AFAB0054 */  sw        $t3, 0x54($sp)
/* 3D0A68 E00CA568 C6C60034 */  lwc1      $f6, 0x34($s6)
/* 3D0A6C E00CA56C 00A0382D */  daddu     $a3, $a1, $zero
/* 3D0A70 E00CA570 E7A60058 */  swc1      $f6, 0x58($sp)
/* 3D0A74 E00CA574 AC620000 */  sw        $v0, ($v1)
/* 3D0A78 E00CA578 AC600004 */  sw        $zero, 4($v1)
/* 3D0A7C E00CA57C AD0A0000 */  sw        $t2, ($t0)
/* 3D0A80 E00CA580 8D230010 */  lw        $v1, 0x10($t1)
/* 3D0A84 E00CA584 25020008 */  addiu     $v0, $t0, 8
/* 3D0A88 E00CA588 AE620000 */  sw        $v0, ($s3)
/* 3D0A8C E00CA58C 8C62001C */  lw        $v0, 0x1c($v1)
/* 3D0A90 E00CA590 3C038000 */  lui       $v1, 0x8000
/* 3D0A94 E00CA594 00431021 */  addu      $v0, $v0, $v1
/* 3D0A98 E00CA598 0C080108 */  jal       func_E0200420
/* 3D0A9C E00CA59C AD020004 */   sw       $v0, 4($t0)
/* 3D0AA0 E00CA5A0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D0AA4 E00CA5A4 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3D0AA8 E00CA5A8 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3D0AAC E00CA5AC 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 3D0AB0 E00CA5B0 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 3D0AB4 E00CA5B4 96050000 */  lhu       $a1, ($s0)
/* 3D0AB8 E00CA5B8 8E220000 */  lw        $v0, ($s1)
/* 3D0ABC E00CA5BC 00052980 */  sll       $a1, $a1, 6
/* 3D0AC0 E00CA5C0 00B22821 */  addu      $a1, $a1, $s2
/* 3D0AC4 E00CA5C4 0C080118 */  jal       func_E0200460
/* 3D0AC8 E00CA5C8 00452821 */   addu     $a1, $v0, $a1
/* 3D0ACC E00CA5CC 3C03DA38 */  lui       $v1, 0xda38
/* 3D0AD0 E00CA5D0 34630002 */  ori       $v1, $v1, 2
/* 3D0AD4 E00CA5D4 8E650000 */  lw        $a1, ($s3)
/* 3D0AD8 E00CA5D8 96020000 */  lhu       $v0, ($s0)
/* 3D0ADC E00CA5DC 00A0202D */  daddu     $a0, $a1, $zero
/* 3D0AE0 E00CA5E0 24A50008 */  addiu     $a1, $a1, 8
/* 3D0AE4 E00CA5E4 AE650000 */  sw        $a1, ($s3)
/* 3D0AE8 E00CA5E8 AC830000 */  sw        $v1, ($a0)
/* 3D0AEC E00CA5EC 24430001 */  addiu     $v1, $v0, 1
/* 3D0AF0 E00CA5F0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D0AF4 E00CA5F4 00021180 */  sll       $v0, $v0, 6
/* 3D0AF8 E00CA5F8 A6030000 */  sh        $v1, ($s0)
/* 3D0AFC E00CA5FC 8E230000 */  lw        $v1, ($s1)
/* 3D0B00 E00CA600 00521021 */  addu      $v0, $v0, $s2
/* 3D0B04 E00CA604 00621821 */  addu      $v1, $v1, $v0
/* 3D0B08 E00CA608 3C02DE00 */  lui       $v0, 0xde00
/* 3D0B0C E00CA60C AC830004 */  sw        $v1, 4($a0)
/* 3D0B10 E00CA610 ACA20000 */  sw        $v0, ($a1)
/* 3D0B14 E00CA614 8FAB0054 */  lw        $t3, 0x54($sp)
/* 3D0B18 E00CA618 000B1080 */  sll       $v0, $t3, 2
/* 3D0B1C E00CA61C 3C03E00D */  lui       $v1, %hi(D_E00CACB0)
/* 3D0B20 E00CA620 00621821 */  addu      $v1, $v1, $v0
/* 3D0B24 E00CA624 8C63ACB0 */  lw        $v1, %lo(D_E00CACB0)($v1)
/* 3D0B28 E00CA628 24A20008 */  addiu     $v0, $a1, 8
/* 3D0B2C E00CA62C AE620000 */  sw        $v0, ($s3)
/* 3D0B30 E00CA630 29620002 */  slti      $v0, $t3, 2
/* 3D0B34 E00CA634 14400009 */  bnez      $v0, .LE00CA65C
/* 3D0B38 E00CA638 ACA30004 */   sw       $v1, 4($a1)
/* 3D0B3C E00CA63C 3C04FC40 */  lui       $a0, 0xfc40
/* 3D0B40 E00CA640 348499FF */  ori       $a0, $a0, 0x99ff
/* 3D0B44 E00CA644 3C035F0E */  lui       $v1, 0x5f0e
/* 3D0B48 E00CA648 3463FE3F */  ori       $v1, $v1, 0xfe3f
/* 3D0B4C E00CA64C 24A20010 */  addiu     $v0, $a1, 0x10
/* 3D0B50 E00CA650 AE620000 */  sw        $v0, ($s3)
/* 3D0B54 E00CA654 ACA40008 */  sw        $a0, 8($a1)
/* 3D0B58 E00CA658 ACA3000C */  sw        $v1, 0xc($a1)
.LE00CA65C:
/* 3D0B5C E00CA65C 240BFFFF */  addiu     $t3, $zero, -1
/* 3D0B60 E00CA660 0000F02D */  daddu     $fp, $zero, $zero
/* 3D0B64 E00CA664 03C0A02D */  daddu     $s4, $fp, $zero
/* 3D0B68 E00CA668 3C088888 */  lui       $t0, 0x8888
/* 3D0B6C E00CA66C AFAB0060 */  sw        $t3, 0x60($sp)
/* 3D0B70 E00CA670 8FAB0050 */  lw        $t3, 0x50($sp)
/* 3D0B74 E00CA674 35088889 */  ori       $t0, $t0, 0x8889
/* 3D0B78 E00CA678 3162003F */  andi      $v0, $t3, 0x3f
/* 3D0B7C E00CA67C 00021140 */  sll       $v0, $v0, 5
/* 3D0B80 E00CA680 AFA20064 */  sw        $v0, 0x64($sp)
/* 3D0B84 E00CA684 8E660000 */  lw        $a2, ($s3)
/* 3D0B88 E00CA688 3C02FA00 */  lui       $v0, 0xfa00
/* 3D0B8C E00CA68C 00C0382D */  daddu     $a3, $a2, $zero
/* 3D0B90 E00CA690 24C60008 */  addiu     $a2, $a2, 8
/* 3D0B94 E00CA694 24CB0010 */  addiu     $t3, $a2, 0x10
/* 3D0B98 E00CA698 AFAB005C */  sw        $t3, 0x5c($sp)
/* 3D0B9C E00CA69C AE660000 */  sw        $a2, ($s3)
/* 3D0BA0 E00CA6A0 ACE20000 */  sw        $v0, ($a3)
/* 3D0BA4 E00CA6A4 92C2001B */  lbu       $v0, 0x1b($s6)
/* 3D0BA8 E00CA6A8 92C4001F */  lbu       $a0, 0x1f($s6)
/* 3D0BAC E00CA6AC 92C50023 */  lbu       $a1, 0x23($s6)
/* 3D0BB0 E00CA6B0 24C30008 */  addiu     $v1, $a2, 8
/* 3D0BB4 E00CA6B4 AE630000 */  sw        $v1, ($s3)
/* 3D0BB8 E00CA6B8 32A300FF */  andi      $v1, $s5, 0xff
/* 3D0BBC E00CA6BC 00021600 */  sll       $v0, $v0, 0x18
/* 3D0BC0 E00CA6C0 00042400 */  sll       $a0, $a0, 0x10
/* 3D0BC4 E00CA6C4 00441025 */  or        $v0, $v0, $a0
/* 3D0BC8 E00CA6C8 00052A00 */  sll       $a1, $a1, 8
/* 3D0BCC E00CA6CC 00451025 */  or        $v0, $v0, $a1
/* 3D0BD0 E00CA6D0 00431025 */  or        $v0, $v0, $v1
/* 3D0BD4 E00CA6D4 ACE20004 */  sw        $v0, 4($a3)
/* 3D0BD8 E00CA6D8 3C02FB00 */  lui       $v0, 0xfb00
/* 3D0BDC E00CA6DC ACC20000 */  sw        $v0, ($a2)
/* 3D0BE0 E00CA6E0 92C3002B */  lbu       $v1, 0x2b($s6)
/* 3D0BE4 E00CA6E4 92C4002F */  lbu       $a0, 0x2f($s6)
/* 3D0BE8 E00CA6E8 92C50033 */  lbu       $a1, 0x33($s6)
/* 3D0BEC E00CA6EC 3C02DE01 */  lui       $v0, 0xde01
/* 3D0BF0 E00CA6F0 ACC20008 */  sw        $v0, 8($a2)
/* 3D0BF4 E00CA6F4 24C203D0 */  addiu     $v0, $a2, 0x3d0
/* 3D0BF8 E00CA6F8 ACC2000C */  sw        $v0, 0xc($a2)
/* 3D0BFC E00CA6FC AE620000 */  sw        $v0, ($s3)
/* 3D0C00 E00CA700 00031E00 */  sll       $v1, $v1, 0x18
/* 3D0C04 E00CA704 00042400 */  sll       $a0, $a0, 0x10
/* 3D0C08 E00CA708 00641825 */  or        $v1, $v1, $a0
/* 3D0C0C E00CA70C 00052A00 */  sll       $a1, $a1, 8
/* 3D0C10 E00CA710 00651825 */  or        $v1, $v1, $a1
/* 3D0C14 E00CA714 ACC30004 */  sw        $v1, 4($a2)
/* 3D0C18 E00CA718 8EC602A8 */  lw        $a2, 0x2a8($s6)
/* 3D0C1C E00CA71C 26850001 */  addiu     $a1, $s4, 1
.LE00CA720:
/* 3D0C20 E00CA720 00C52021 */  addu      $a0, $a2, $a1
/* 3D0C24 E00CA724 00880018 */  mult      $a0, $t0
/* 3D0C28 E00CA728 00041FC3 */  sra       $v1, $a0, 0x1f
/* 3D0C2C E00CA72C 00005810 */  mfhi      $t3
/* 3D0C30 E00CA730 01641021 */  addu      $v0, $t3, $a0
/* 3D0C34 E00CA734 00021103 */  sra       $v0, $v0, 4
/* 3D0C38 E00CA738 00431823 */  subu      $v1, $v0, $v1
/* 3D0C3C E00CA73C 00031100 */  sll       $v0, $v1, 4
/* 3D0C40 E00CA740 00431023 */  subu      $v0, $v0, $v1
/* 3D0C44 E00CA744 00021040 */  sll       $v0, $v0, 1
/* 3D0C48 E00CA748 00821823 */  subu      $v1, $a0, $v0
/* 3D0C4C E00CA74C 00031080 */  sll       $v0, $v1, 2
/* 3D0C50 E00CA750 02C21021 */  addu      $v0, $s6, $v0
/* 3D0C54 E00CA754 8C420230 */  lw        $v0, 0x230($v0)
/* 3D0C58 E00CA758 54400001 */  bnel      $v0, $zero, .LE00CA760
/* 3D0C5C E00CA75C 27DE0001 */   addiu    $fp, $fp, 1
.LE00CA760:
/* 3D0C60 E00CA760 00A0A02D */  daddu     $s4, $a1, $zero
/* 3D0C64 E00CA764 2A82001E */  slti      $v0, $s4, 0x1e
/* 3D0C68 E00CA768 1440FFED */  bnez      $v0, .LE00CA720
/* 3D0C6C E00CA76C 26850001 */   addiu    $a1, $s4, 1
/* 3D0C70 E00CA770 27DEFFFF */  addiu     $fp, $fp, -1
/* 3D0C74 E00CA774 1BC00130 */  blez      $fp, .LE00CAC38
/* 3D0C78 E00CA778 0000A02D */   daddu    $s4, $zero, $zero
/* 3D0C7C E00CA77C AFA00068 */  sw        $zero, 0x68($sp)
.LE00CA780:
/* 3D0C80 E00CA780 8FAB0068 */  lw        $t3, 0x68($sp)
/* 3D0C84 E00CA784 17C00002 */  bnez      $fp, .LE00CA790
/* 3D0C88 E00CA788 017E001A */   div      $zero, $t3, $fp
/* 3D0C8C E00CA78C 0007000D */  break     7
.LE00CA790:
/* 3D0C90 E00CA790 2401FFFF */   addiu    $at, $zero, -1
/* 3D0C94 E00CA794 17C10004 */  bne       $fp, $at, .LE00CA7A8
/* 3D0C98 E00CA798 3C018000 */   lui      $at, 0x8000
/* 3D0C9C E00CA79C 15610002 */  bne       $t3, $at, .LE00CA7A8
/* 3D0CA0 E00CA7A0 00000000 */   nop
/* 3D0CA4 E00CA7A4 0006000D */  break     6
.LE00CA7A8:
/* 3D0CA8 E00CA7A8 00002812 */   mflo     $a1
/* 3D0CAC E00CA7AC 3C038888 */  lui       $v1, 0x8888
/* 3D0CB0 E00CA7B0 34638889 */  ori       $v1, $v1, 0x8889
/* 3D0CB4 E00CA7B4 8EC402A8 */  lw        $a0, 0x2a8($s6)
/* 3D0CB8 E00CA7B8 26820001 */  addiu     $v0, $s4, 1
/* 3D0CBC E00CA7BC 00822021 */  addu      $a0, $a0, $v0
/* 3D0CC0 E00CA7C0 00830018 */  mult      $a0, $v1
/* 3D0CC4 E00CA7C4 8FAB005C */  lw        $t3, 0x5c($sp)
/* 3D0CC8 E00CA7C8 00141140 */  sll       $v0, $s4, 5
/* 3D0CCC E00CA7CC 01629021 */  addu      $s2, $t3, $v0
/* 3D0CD0 E00CA7D0 00001810 */  mfhi      $v1
/* 3D0CD4 E00CA7D4 00641021 */  addu      $v0, $v1, $a0
/* 3D0CD8 E00CA7D8 00021103 */  sra       $v0, $v0, 4
/* 3D0CDC E00CA7DC 00041FC3 */  sra       $v1, $a0, 0x1f
/* 3D0CE0 E00CA7E0 00439823 */  subu      $s3, $v0, $v1
/* 3D0CE4 E00CA7E4 00131100 */  sll       $v0, $s3, 4
/* 3D0CE8 E00CA7E8 00531023 */  subu      $v0, $v0, $s3
/* 3D0CEC E00CA7EC 00021040 */  sll       $v0, $v0, 1
/* 3D0CF0 E00CA7F0 44856000 */  mtc1      $a1, $f12
/* 3D0CF4 E00CA7F4 00000000 */  nop
/* 3D0CF8 E00CA7F8 46806320 */  cvt.s.w   $f12, $f12
/* 3D0CFC E00CA7FC 0C080140 */  jal       func_E0200500
/* 3D0D00 E00CA800 00829823 */   subu     $s3, $a0, $v0
/* 3D0D04 E00CA804 3C01437F */  lui       $at, 0x437f
/* 3D0D08 E00CA808 44811000 */  mtc1      $at, $f2
/* 3D0D0C E00CA80C 00000000 */  nop
/* 3D0D10 E00CA810 46020002 */  mul.s     $f0, $f0, $f2
/* 3D0D14 E00CA814 00000000 */  nop
/* 3D0D18 E00CA818 4600018D */  trunc.w.s $f6, $f0
/* 3D0D1C E00CA81C 44173000 */  mfc1      $s7, $f6
/* 3D0D20 E00CA820 00000000 */  nop
/* 3D0D24 E00CA824 2AE200C9 */  slti      $v0, $s7, 0xc9
/* 3D0D28 E00CA828 50400001 */  beql      $v0, $zero, .LE00CA830
/* 3D0D2C E00CA82C 241700C8 */   addiu    $s7, $zero, 0xc8
.LE00CA830:
/* 3D0D30 E00CA830 00131080 */  sll       $v0, $s3, 2
/* 3D0D34 E00CA834 02C28021 */  addu      $s0, $s6, $v0
/* 3D0D38 E00CA838 8E020230 */  lw        $v0, 0x230($s0)
/* 3D0D3C E00CA83C 504000DF */  beql      $v0, $zero, .LE00CABBC
/* 3D0D40 E00CA840 26940001 */   addiu    $s4, $s4, 1
/* 3D0D44 E00CA844 8FAB0060 */  lw        $t3, 0x60($sp)
/* 3D0D48 E00CA848 2402FFFF */  addiu     $v0, $zero, -1
/* 3D0D4C E00CA84C 15620012 */  bne       $t3, $v0, .LE00CA898
/* 3D0D50 E00CA850 2402001D */   addiu    $v0, $zero, 0x1d
/* 3D0D54 E00CA854 26630001 */  addiu     $v1, $s3, 1
/* 3D0D58 E00CA858 2862001E */  slti      $v0, $v1, 0x1e
/* 3D0D5C E00CA85C 50400001 */  beql      $v0, $zero, .LE00CA864
/* 3D0D60 E00CA860 0000182D */   daddu    $v1, $zero, $zero
.LE00CA864:
/* 3D0D64 E00CA864 00031080 */  sll       $v0, $v1, 2
/* 3D0D68 E00CA868 02C21021 */  addu      $v0, $s6, $v0
/* 3D0D6C E00CA86C AFB40060 */  sw        $s4, 0x60($sp)
/* 3D0D70 E00CA870 C44C00C8 */  lwc1      $f12, 0xc8($v0)
/* 3D0D74 E00CA874 8E0600C8 */  lw        $a2, 0xc8($s0)
/* 3D0D78 E00CA878 C6000050 */  lwc1      $f0, 0x50($s0)
/* 3D0D7C E00CA87C C44E0050 */  lwc1      $f14, 0x50($v0)
/* 3D0D80 E00CA880 46000007 */  neg.s     $f0, $f0
/* 3D0D84 E00CA884 44070000 */  mfc1      $a3, $f0
/* 3D0D88 E00CA888 0C080148 */  jal       func_E0200520
/* 3D0D8C E00CA88C 46007387 */   neg.s    $f14, $f14
/* 3D0D90 E00CA890 08032A63 */  j         .LE00CA98C
/* 3D0D94 E00CA894 46000787 */   neg.s    $f30, $f0
.LE00CA898:
/* 3D0D98 E00CA898 1282003C */  beq       $s4, $v0, .LE00CA98C
/* 3D0D9C E00CA89C 26630001 */   addiu    $v1, $s3, 1
/* 3D0DA0 E00CA8A0 2862001E */  slti      $v0, $v1, 0x1e
/* 3D0DA4 E00CA8A4 14400002 */  bnez      $v0, .LE00CA8B0
/* 3D0DA8 E00CA8A8 2671FFFF */   addiu    $s1, $s3, -1
/* 3D0DAC E00CA8AC 0000182D */  daddu     $v1, $zero, $zero
.LE00CA8B0:
/* 3D0DB0 E00CA8B0 06220001 */  bltzl     $s1, .LE00CA8B8
/* 3D0DB4 E00CA8B4 2411001D */   addiu    $s1, $zero, 0x1d
.LE00CA8B8:
/* 3D0DB8 E00CA8B8 00031080 */  sll       $v0, $v1, 2
/* 3D0DBC E00CA8BC 02C21021 */  addu      $v0, $s6, $v0
/* 3D0DC0 E00CA8C0 C44C00C8 */  lwc1      $f12, 0xc8($v0)
/* 3D0DC4 E00CA8C4 8E0600C8 */  lw        $a2, 0xc8($s0)
/* 3D0DC8 E00CA8C8 C6000050 */  lwc1      $f0, 0x50($s0)
/* 3D0DCC E00CA8CC C44E0050 */  lwc1      $f14, 0x50($v0)
/* 3D0DD0 E00CA8D0 46000007 */  neg.s     $f0, $f0
/* 3D0DD4 E00CA8D4 44070000 */  mfc1      $a3, $f0
/* 3D0DD8 E00CA8D8 0C080148 */  jal       func_E0200520
/* 3D0DDC E00CA8DC 46007387 */   neg.s    $f14, $f14
/* 3D0DE0 E00CA8E0 00111080 */  sll       $v0, $s1, 2
/* 3D0DE4 E00CA8E4 02C21021 */  addu      $v0, $s6, $v0
/* 3D0DE8 E00CA8E8 C60C00C8 */  lwc1      $f12, 0xc8($s0)
/* 3D0DEC E00CA8EC 8C4600C8 */  lw        $a2, 0xc8($v0)
/* 3D0DF0 E00CA8F0 46000507 */  neg.s     $f20, $f0
/* 3D0DF4 E00CA8F4 C4400050 */  lwc1      $f0, 0x50($v0)
/* 3D0DF8 E00CA8F8 C60E0050 */  lwc1      $f14, 0x50($s0)
/* 3D0DFC E00CA8FC 46000007 */  neg.s     $f0, $f0
/* 3D0E00 E00CA900 44070000 */  mfc1      $a3, $f0
/* 3D0E04 E00CA904 0C080148 */  jal       func_E0200520
/* 3D0E08 E00CA908 46007387 */   neg.s    $f14, $f14
/* 3D0E0C E00CA90C 46000307 */  neg.s     $f12, $f0
/* 3D0E10 E00CA910 46146081 */  sub.s     $f2, $f12, $f20
/* 3D0E14 E00CA914 3C014334 */  lui       $at, 0x4334
/* 3D0E18 E00CA918 44810000 */  mtc1      $at, $f0
/* 3D0E1C E00CA91C 00000000 */  nop
/* 3D0E20 E00CA920 4602003C */  c.lt.s    $f0, $f2
/* 3D0E24 E00CA924 00000000 */  nop
/* 3D0E28 E00CA928 45000005 */  bc1f      .LE00CA940
/* 3D0E2C E00CA92C 00000000 */   nop
/* 3D0E30 E00CA930 3C0143B4 */  lui       $at, 0x43b4
/* 3D0E34 E00CA934 44813000 */  mtc1      $at, $f6
/* 3D0E38 E00CA938 08032A5B */  j         .LE00CA96C
/* 3D0E3C E00CA93C 4606A500 */   add.s    $f20, $f20, $f6
.LE00CA940:
/* 3D0E40 E00CA940 3C01C334 */  lui       $at, 0xc334
/* 3D0E44 E00CA944 44810000 */  mtc1      $at, $f0
/* 3D0E48 E00CA948 00000000 */  nop
/* 3D0E4C E00CA94C 4600103C */  c.lt.s    $f2, $f0
/* 3D0E50 E00CA950 00000000 */  nop
/* 3D0E54 E00CA954 45020006 */  bc1fl     .LE00CA970
/* 3D0E58 E00CA958 460CA780 */   add.s    $f30, $f20, $f12
/* 3D0E5C E00CA95C 3C0143B4 */  lui       $at, 0x43b4
/* 3D0E60 E00CA960 44813000 */  mtc1      $at, $f6
/* 3D0E64 E00CA964 00000000 */  nop
/* 3D0E68 E00CA968 46066300 */  add.s     $f12, $f12, $f6
.LE00CA96C:
/* 3D0E6C E00CA96C 460CA780 */  add.s     $f30, $f20, $f12
.LE00CA970:
/* 3D0E70 E00CA970 3C013FE0 */  lui       $at, 0x3fe0
/* 3D0E74 E00CA974 44811800 */  mtc1      $at, $f3
/* 3D0E78 E00CA978 44801000 */  mtc1      $zero, $f2
/* 3D0E7C E00CA97C 4600F021 */  cvt.d.s   $f0, $f30
/* 3D0E80 E00CA980 46220002 */  mul.d     $f0, $f0, $f2
/* 3D0E84 E00CA984 00000000 */  nop
/* 3D0E88 E00CA988 462007A0 */  cvt.s.d   $f30, $f0
.LE00CA98C:
/* 3D0E8C E00CA98C 00131080 */  sll       $v0, $s3, 2
/* 3D0E90 E00CA990 02C28021 */  addu      $s0, $s6, $v0
/* 3D0E94 E00CA994 8E0301B8 */  lw        $v1, 0x1b8($s0)
/* 3D0E98 E00CA998 8FAB0050 */  lw        $t3, 0x50($sp)
/* 3D0E9C E00CA99C C6180050 */  lwc1      $f24, 0x50($s0)
/* 3D0EA0 E00CA9A0 C61A00C8 */  lwc1      $f26, 0xc8($s0)
/* 3D0EA4 E00CA9A4 C61C0140 */  lwc1      $f28, 0x140($s0)
/* 3D0EA8 E00CA9A8 00031080 */  sll       $v0, $v1, 2
/* 3D0EAC E00CA9AC 00431021 */  addu      $v0, $v0, $v1
/* 3D0EB0 E00CA9B0 00021100 */  sll       $v0, $v0, 4
/* 3D0EB4 E00CA9B4 01621023 */  subu      $v0, $t3, $v0
/* 3D0EB8 E00CA9B8 00021080 */  sll       $v0, $v0, 2
/* 3D0EBC E00CA9BC 44826000 */  mtc1      $v0, $f12
/* 3D0EC0 E00CA9C0 00000000 */  nop
/* 3D0EC4 E00CA9C4 46806320 */  cvt.s.w   $f12, $f12
/* 3D0EC8 E00CA9C8 0C080140 */  jal       func_E0200500
/* 3D0ECC E00CA9CC 01638823 */   subu     $s1, $t3, $v1
/* 3D0ED0 E00CA9D0 3C014040 */  lui       $at, 0x4040
/* 3D0ED4 E00CA9D4 44811000 */  mtc1      $at, $f2
/* 3D0ED8 E00CA9D8 00000000 */  nop
/* 3D0EDC E00CA9DC 46020002 */  mul.s     $f0, $f0, $f2
/* 3D0EE0 E00CA9E0 00000000 */  nop
/* 3D0EE4 E00CA9E4 3C014180 */  lui       $at, 0x4180
/* 3D0EE8 E00CA9E8 44811000 */  mtc1      $at, $f2
/* 3D0EEC E00CA9EC 00000000 */  nop
/* 3D0EF0 E00CA9F0 46020000 */  add.s     $f0, $f0, $f2
/* 3D0EF4 E00CA9F4 44911000 */  mtc1      $s1, $f2
/* 3D0EF8 E00CA9F8 00000000 */  nop
/* 3D0EFC E00CA9FC 468010A0 */  cvt.s.w   $f2, $f2
/* 3D0F00 E00CAA00 46020580 */  add.s     $f22, $f0, $f2
/* 3D0F04 E00CAA04 C7A60058 */  lwc1      $f6, 0x58($sp)
/* 3D0F08 E00CAA08 8FAB0054 */  lw        $t3, 0x54($sp)
/* 3D0F0C E00CAA0C 4606B582 */  mul.s     $f22, $f22, $f6
/* 3D0F10 E00CAA10 00000000 */  nop
/* 3D0F14 E00CAA14 C60002AC */  lwc1      $f0, 0x2ac($s0)
/* 3D0F18 E00CAA18 3C0141C0 */  lui       $at, 0x41c0
/* 3D0F1C E00CAA1C 44813000 */  mtc1      $at, $f6
/* 3D0F20 E00CAA20 00000000 */  nop
/* 3D0F24 E00CAA24 46060002 */  mul.s     $f0, $f0, $f6
/* 3D0F28 E00CAA28 00000000 */  nop
/* 3D0F2C E00CAA2C C7A20064 */  lwc1      $f2, 0x64($sp)
/* 3D0F30 E00CAA30 468010A0 */  cvt.s.w   $f2, $f2
/* 3D0F34 E00CAA34 46020000 */  add.s     $f0, $f0, $f2
/* 3D0F38 E00CAA38 4600018D */  trunc.w.s $f6, $f0
/* 3D0F3C E00CAA3C 44153000 */  mfc1      $s5, $f6
/* 3D0F40 E00CAA40 241300FF */  addiu     $s3, $zero, 0xff
/* 3D0F44 E00CAA44 0260802D */  daddu     $s0, $s3, $zero
/* 3D0F48 E00CAA48 00111040 */  sll       $v0, $s1, 1
/* 3D0F4C E00CAA4C 00511021 */  addu      $v0, $v0, $s1
/* 3D0F50 E00CAA50 000210C0 */  sll       $v0, $v0, 3
/* 3D0F54 E00CAA54 00511021 */  addu      $v0, $v0, $s1
/* 3D0F58 E00CAA58 00021080 */  sll       $v0, $v0, 2
/* 3D0F5C E00CAA5C 02028823 */  subu      $s1, $s0, $v0
/* 3D0F60 E00CAA60 06210022 */  bgez      $s1, .LE00CAAEC
/* 3D0F64 E00CAA64 00000000 */   nop
/* 3D0F68 E00CAA68 44910000 */  mtc1      $s1, $f0
/* 3D0F6C E00CAA6C 00000000 */  nop
/* 3D0F70 E00CAA70 46800020 */  cvt.s.w   $f0, $f0
/* 3D0F74 E00CAA74 3C01E00D */  lui       $at, %hi(D_E00CACC0)
/* 3D0F78 E00CAA78 D422ACC0 */  ldc1      $f2, %lo(D_E00CACC0)($at)
/* 3D0F7C E00CAA7C 46000021 */  cvt.d.s   $f0, $f0
/* 3D0F80 E00CAA80 46220002 */  mul.d     $f0, $f0, $f2
/* 3D0F84 E00CAA84 00000000 */  nop
/* 3D0F88 E00CAA88 3C01E00D */  lui       $at, %hi(D_E00CACC8)
/* 3D0F8C E00CAA8C D426ACC8 */  ldc1      $f6, %lo(D_E00CACC8)($at)
/* 3D0F90 E00CAA90 46260000 */  add.d     $f0, $f0, $f6
/* 3D0F94 E00CAA94 4620018D */  trunc.w.d $f6, $f0
/* 3D0F98 E00CAA98 44103000 */  mfc1      $s0, $f6
/* 3D0F9C E00CAA9C 00000000 */  nop
/* 3D0FA0 E00CAAA0 06010012 */  bgez      $s0, .LE00CAAEC
/* 3D0FA4 E00CAAA4 0000882D */   daddu    $s1, $zero, $zero
/* 3D0FA8 E00CAAA8 44900000 */  mtc1      $s0, $f0
/* 3D0FAC E00CAAAC 00000000 */  nop
/* 3D0FB0 E00CAAB0 46800020 */  cvt.s.w   $f0, $f0
/* 3D0FB4 E00CAAB4 3C01E00D */  lui       $at, %hi(D_E00CACD0)
/* 3D0FB8 E00CAAB8 D422ACD0 */  ldc1      $f2, %lo(D_E00CACD0)($at)
/* 3D0FBC E00CAABC 46000021 */  cvt.d.s   $f0, $f0
/* 3D0FC0 E00CAAC0 46220002 */  mul.d     $f0, $f0, $f2
/* 3D0FC4 E00CAAC4 00000000 */  nop
/* 3D0FC8 E00CAAC8 3C01E00D */  lui       $at, %hi(D_E00CACD8)
/* 3D0FCC E00CAACC D426ACD8 */  ldc1      $f6, %lo(D_E00CACD8)($at)
/* 3D0FD0 E00CAAD0 46260000 */  add.d     $f0, $f0, $f6
/* 3D0FD4 E00CAAD4 4620018D */  trunc.w.d $f6, $f0
/* 3D0FD8 E00CAAD8 44133000 */  mfc1      $s3, $f6
/* 3D0FDC E00CAADC 00000000 */  nop
/* 3D0FE0 E00CAAE0 06610002 */  bgez      $s3, .LE00CAAEC
/* 3D0FE4 E00CAAE4 0220802D */   daddu    $s0, $s1, $zero
/* 3D0FE8 E00CAAE8 0220982D */  daddu     $s3, $s1, $zero
.LE00CAAEC:
/* 3D0FEC E00CAAEC 0C080140 */  jal       func_E0200500
/* 3D0FF0 E00CAAF0 4600F306 */   mov.s    $f12, $f30
/* 3D0FF4 E00CAAF4 4600B502 */  mul.s     $f20, $f22, $f0
/* 3D0FF8 E00CAAF8 00000000 */  nop
/* 3D0FFC E00CAAFC 0C080144 */  jal       func_E0200510
/* 3D1000 E00CAB00 4600F306 */   mov.s    $f12, $f30
/* 3D1004 E00CAB04 4600B002 */  mul.s     $f0, $f22, $f0
/* 3D1008 E00CAB08 00000000 */  nop
/* 3D100C E00CAB0C 24020400 */  addiu     $v0, $zero, 0x400
/* 3D1010 E00CAB10 8FAB0068 */  lw        $t3, 0x68($sp)
/* 3D1014 E00CAB14 44803000 */  mtc1      $zero, $f6
/* 3D1018 E00CAB18 256B00B4 */  addiu     $t3, $t3, 0xb4
/* 3D101C E00CAB1C 4606E080 */  add.s     $f2, $f28, $f6
/* 3D1020 E00CAB20 AFAB0068 */  sw        $t3, 0x68($sp)
/* 3D1024 E00CAB24 A6550008 */  sh        $s5, 8($s2)
/* 3D1028 E00CAB28 A642000A */  sh        $v0, 0xa($s2)
/* 3D102C E00CAB2C 4614C100 */  add.s     $f4, $f24, $f20
/* 3D1030 E00CAB30 A253000C */  sb        $s3, 0xc($s2)
/* 3D1034 E00CAB34 4600118D */  trunc.w.s $f6, $f2
/* 3D1038 E00CAB38 44033000 */  mfc1      $v1, $f6
/* 3D103C E00CAB3C 4600D080 */  add.s     $f2, $f26, $f0
/* 3D1040 E00CAB40 A250000D */  sb        $s0, 0xd($s2)
/* 3D1044 E00CAB44 A251000E */  sb        $s1, 0xe($s2)
/* 3D1048 E00CAB48 4614C501 */  sub.s     $f20, $f24, $f20
/* 3D104C E00CAB4C A257000F */  sb        $s7, 0xf($s2)
/* 3D1050 E00CAB50 A6430004 */  sh        $v1, 4($s2)
/* 3D1054 E00CAB54 4600D001 */  sub.s     $f0, $f26, $f0
/* 3D1058 E00CAB58 4600218D */  trunc.w.s $f6, $f4
/* 3D105C E00CAB5C 44023000 */  mfc1      $v0, $f6
/* 3D1060 E00CAB60 00000000 */  nop
/* 3D1064 E00CAB64 A6420000 */  sh        $v0, ($s2)
/* 3D1068 E00CAB68 4600118D */  trunc.w.s $f6, $f2
/* 3D106C E00CAB6C 44023000 */  mfc1      $v0, $f6
/* 3D1070 E00CAB70 00000000 */  nop
/* 3D1074 E00CAB74 A6420002 */  sh        $v0, 2($s2)
/* 3D1078 E00CAB78 26520010 */  addiu     $s2, $s2, 0x10
/* 3D107C E00CAB7C 4600A18D */  trunc.w.s $f6, $f20
/* 3D1080 E00CAB80 44023000 */  mfc1      $v0, $f6
/* 3D1084 E00CAB84 00000000 */  nop
/* 3D1088 E00CAB88 A6420000 */  sh        $v0, ($s2)
/* 3D108C E00CAB8C 4600018D */  trunc.w.s $f6, $f0
/* 3D1090 E00CAB90 44023000 */  mfc1      $v0, $f6
/* 3D1094 E00CAB94 00000000 */  nop
/* 3D1098 E00CAB98 A6420002 */  sh        $v0, 2($s2)
/* 3D109C E00CAB9C A6430004 */  sh        $v1, 4($s2)
/* 3D10A0 E00CABA0 A6550008 */  sh        $s5, 8($s2)
/* 3D10A4 E00CABA4 A640000A */  sh        $zero, 0xa($s2)
/* 3D10A8 E00CABA8 A253000C */  sb        $s3, 0xc($s2)
/* 3D10AC E00CABAC A250000D */  sb        $s0, 0xd($s2)
/* 3D10B0 E00CABB0 A251000E */  sb        $s1, 0xe($s2)
/* 3D10B4 E00CABB4 A257000F */  sb        $s7, 0xf($s2)
/* 3D10B8 E00CABB8 26940001 */  addiu     $s4, $s4, 1
.LE00CABBC:
/* 3D10BC E00CABBC 2A82001E */  slti      $v0, $s4, 0x1e
/* 3D10C0 E00CABC0 1440FEEF */  bnez      $v0, .LE00CA780
/* 3D10C4 E00CABC4 00000000 */   nop
/* 3D10C8 E00CABC8 8FB40060 */  lw        $s4, 0x60($sp)
/* 3D10CC E00CABCC 2A82001D */  slti      $v0, $s4, 0x1d
/* 3D10D0 E00CABD0 10400019 */  beqz      $v0, .LE00CAC38
/* 3D10D4 E00CABD4 3C050002 */   lui      $a1, 2
/* 3D10D8 E00CABD8 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3D10DC E00CABDC 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3D10E0 E00CABE0 3C080100 */  lui       $t0, 0x100
/* 3D10E4 E00CABE4 35084008 */  ori       $t0, $t0, 0x4008
/* 3D10E8 E00CABE8 3C070600 */  lui       $a3, 0x600
/* 3D10EC E00CABEC 34E70402 */  ori       $a3, $a3, 0x402
/* 3D10F0 E00CABF0 34A50406 */  ori       $a1, $a1, 0x406
/* 3D10F4 E00CABF4 8FAB005C */  lw        $t3, 0x5c($sp)
/* 3D10F8 E00CABF8 00141140 */  sll       $v0, $s4, 5
/* 3D10FC E00CABFC 004B3021 */  addu      $a2, $v0, $t3
.LE00CAC00:
/* 3D1100 E00CAC00 8C830000 */  lw        $v1, ($a0)
/* 3D1104 E00CAC04 26940001 */  addiu     $s4, $s4, 1
/* 3D1108 E00CAC08 0060102D */  daddu     $v0, $v1, $zero
/* 3D110C E00CAC0C 24630008 */  addiu     $v1, $v1, 8
/* 3D1110 E00CAC10 AC460004 */  sw        $a2, 4($v0)
/* 3D1114 E00CAC14 24C60020 */  addiu     $a2, $a2, 0x20
/* 3D1118 E00CAC18 AC830000 */  sw        $v1, ($a0)
/* 3D111C E00CAC1C AC480000 */  sw        $t0, ($v0)
/* 3D1120 E00CAC20 24620008 */  addiu     $v0, $v1, 8
/* 3D1124 E00CAC24 AC820000 */  sw        $v0, ($a0)
/* 3D1128 E00CAC28 2A82001D */  slti      $v0, $s4, 0x1d
/* 3D112C E00CAC2C AC670000 */  sw        $a3, ($v1)
/* 3D1130 E00CAC30 1440FFF3 */  bnez      $v0, .LE00CAC00
/* 3D1134 E00CAC34 AC650004 */   sw       $a1, 4($v1)
.LE00CAC38:
/* 3D1138 E00CAC38 3C05D838 */  lui       $a1, 0xd838
/* 3D113C E00CAC3C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3D1140 E00CAC40 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3D1144 E00CAC44 8C620000 */  lw        $v0, ($v1)
/* 3D1148 E00CAC48 34A50002 */  ori       $a1, $a1, 2
/* 3D114C E00CAC4C 0040202D */  daddu     $a0, $v0, $zero
/* 3D1150 E00CAC50 24420008 */  addiu     $v0, $v0, 8
/* 3D1154 E00CAC54 AC620000 */  sw        $v0, ($v1)
/* 3D1158 E00CAC58 24020040 */  addiu     $v0, $zero, 0x40
/* 3D115C E00CAC5C AC850000 */  sw        $a1, ($a0)
/* 3D1160 E00CAC60 AC820004 */  sw        $v0, 4($a0)
/* 3D1164 E00CAC64 8FBF0094 */  lw        $ra, 0x94($sp)
/* 3D1168 E00CAC68 8FBE0090 */  lw        $fp, 0x90($sp)
/* 3D116C E00CAC6C 8FB7008C */  lw        $s7, 0x8c($sp)
/* 3D1170 E00CAC70 8FB60088 */  lw        $s6, 0x88($sp)
/* 3D1174 E00CAC74 8FB50084 */  lw        $s5, 0x84($sp)
/* 3D1178 E00CAC78 8FB40080 */  lw        $s4, 0x80($sp)
/* 3D117C E00CAC7C 8FB3007C */  lw        $s3, 0x7c($sp)
/* 3D1180 E00CAC80 8FB20078 */  lw        $s2, 0x78($sp)
/* 3D1184 E00CAC84 8FB10074 */  lw        $s1, 0x74($sp)
/* 3D1188 E00CAC88 8FB00070 */  lw        $s0, 0x70($sp)
/* 3D118C E00CAC8C D7BE00C0 */  ldc1      $f30, 0xc0($sp)
/* 3D1190 E00CAC90 D7BC00B8 */  ldc1      $f28, 0xb8($sp)
/* 3D1194 E00CAC94 D7BA00B0 */  ldc1      $f26, 0xb0($sp)
/* 3D1198 E00CAC98 D7B800A8 */  ldc1      $f24, 0xa8($sp)
/* 3D119C E00CAC9C D7B600A0 */  ldc1      $f22, 0xa0($sp)
/* 3D11A0 E00CACA0 D7B40098 */  ldc1      $f20, 0x98($sp)
/* 3D11A4 E00CACA4 03E00008 */  jr        $ra
/* 3D11A8 E00CACA8 27BD00C8 */   addiu    $sp, $sp, 0xc8
/* 3D11AC E00CACAC 00000000 */  nop
