.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219818_6A0A18
/* 6A0A18 80219818 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 6A0A1C 8021981C AFB1001C */  sw        $s1, 0x1c($sp)
/* 6A0A20 80219820 0080882D */  daddu     $s1, $a0, $zero
/* 6A0A24 80219824 AFB20020 */  sw        $s2, 0x20($sp)
/* 6A0A28 80219828 AFBF002C */  sw        $ra, 0x2c($sp)
/* 6A0A2C 8021982C AFB40028 */  sw        $s4, 0x28($sp)
/* 6A0A30 80219830 AFB30024 */  sw        $s3, 0x24($sp)
/* 6A0A34 80219834 AFB00018 */  sw        $s0, 0x18($sp)
/* 6A0A38 80219838 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 6A0A3C 8021983C F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6A0A40 80219840 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6A0A44 80219844 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6A0A48 80219848 8E240148 */  lw        $a0, 0x148($s1)
/* 6A0A4C 8021984C 8E30000C */  lw        $s0, 0xc($s1)
/* 6A0A50 80219850 0C09A75B */  jal       get_actor
/* 6A0A54 80219854 00A0902D */   daddu    $s2, $a1, $zero
/* 6A0A58 80219858 0040A02D */  daddu     $s4, $v0, $zero
/* 6A0A5C 8021985C 128000F9 */  beqz      $s4, .L80219C44
/* 6A0A60 80219860 24020002 */   addiu    $v0, $zero, 2
/* 6A0A64 80219864 12400041 */  beqz      $s2, .L8021996C
/* 6A0A68 80219868 0000982D */   daddu    $s3, $zero, $zero
/* 6A0A6C 8021986C 8E050000 */  lw        $a1, ($s0)
/* 6A0A70 80219870 26100004 */  addiu     $s0, $s0, 4
/* 6A0A74 80219874 0C0B1EAF */  jal       get_variable
/* 6A0A78 80219878 0220202D */   daddu    $a0, $s1, $zero
/* 6A0A7C 8021987C 8E050000 */  lw        $a1, ($s0)
/* 6A0A80 80219880 26100004 */  addiu     $s0, $s0, 4
/* 6A0A84 80219884 4482D000 */  mtc1      $v0, $f26
/* 6A0A88 80219888 00000000 */  nop
/* 6A0A8C 8021988C 4680D6A0 */  cvt.s.w   $f26, $f26
/* 6A0A90 80219890 0C0B1EAF */  jal       get_variable
/* 6A0A94 80219894 0220202D */   daddu    $a0, $s1, $zero
/* 6A0A98 80219898 8E050000 */  lw        $a1, ($s0)
/* 6A0A9C 8021989C 26100004 */  addiu     $s0, $s0, 4
/* 6A0AA0 802198A0 4482C000 */  mtc1      $v0, $f24
/* 6A0AA4 802198A4 00000000 */  nop
/* 6A0AA8 802198A8 4680C620 */  cvt.s.w   $f24, $f24
/* 6A0AAC 802198AC 0C0B1EAF */  jal       get_variable
/* 6A0AB0 802198B0 0220202D */   daddu    $a0, $s1, $zero
/* 6A0AB4 802198B4 8E050000 */  lw        $a1, ($s0)
/* 6A0AB8 802198B8 4482B000 */  mtc1      $v0, $f22
/* 6A0ABC 802198BC 00000000 */  nop
/* 6A0AC0 802198C0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6A0AC4 802198C4 0C0B210B */  jal       evt_get_float_variable
/* 6A0AC8 802198C8 0220202D */   daddu    $a0, $s1, $zero
/* 6A0ACC 802198CC 82830210 */  lb        $v1, 0x210($s4)
/* 6A0AD0 802198D0 2402000A */  addiu     $v0, $zero, 0xa
/* 6A0AD4 802198D4 14620007 */  bne       $v1, $v0, .L802198F4
/* 6A0AD8 802198D8 46000506 */   mov.s    $f20, $f0
/* 6A0ADC 802198DC 3C018023 */  lui       $at, %hi(D_80234780_6BB980)
/* 6A0AE0 802198E0 D4224780 */  ldc1      $f2, %lo(D_80234780_6BB980)($at)
/* 6A0AE4 802198E4 4600A021 */  cvt.d.s   $f0, $f20
/* 6A0AE8 802198E8 46220002 */  mul.d     $f0, $f0, $f2
/* 6A0AEC 802198EC 00000000 */  nop
/* 6A0AF0 802198F0 46200520 */  cvt.s.d   $f20, $f0
.L802198F4:
/* 6A0AF4 802198F4 0C00AB39 */  jal       heap_malloc
/* 6A0AF8 802198F8 2404009C */   addiu    $a0, $zero, 0x9c
/* 6A0AFC 802198FC 0040882D */  daddu     $s1, $v0, $zero
/* 6A0B00 80219900 0000902D */  daddu     $s2, $zero, $zero
/* 6A0B04 80219904 24060032 */  addiu     $a2, $zero, 0x32
/* 6A0B08 80219908 240500FF */  addiu     $a1, $zero, 0xff
/* 6A0B0C 8021990C 24040001 */  addiu     $a0, $zero, 1
/* 6A0B10 80219910 3C0142B4 */  lui       $at, 0x42b4
/* 6A0B14 80219914 44810000 */  mtc1      $at, $f0
/* 6A0B18 80219918 26230030 */  addiu     $v1, $s1, 0x30
/* 6A0B1C 8021991C AE910078 */  sw        $s1, 0x78($s4)
.L80219920:
/* 6A0B20 80219920 E47AFFD4 */  swc1      $f26, -0x2c($v1)
/* 6A0B24 80219924 E478FFD8 */  swc1      $f24, -0x28($v1)
/* 6A0B28 80219928 E476FFDC */  swc1      $f22, -0x24($v1)
/* 6A0B2C 8021992C E474FFE0 */  swc1      $f20, -0x20($v1)
/* 6A0B30 80219930 AC64FFE4 */  sw        $a0, -0x1c($v1)
/* 6A0B34 80219934 AC66FFE8 */  sw        $a2, -0x18($v1)
/* 6A0B38 80219938 AC65FFEC */  sw        $a1, -0x14($v1)
/* 6A0B3C 8021993C AC65FFF0 */  sw        $a1, -0x10($v1)
/* 6A0B40 80219940 E460FFF4 */  swc1      $f0, -0xc($v1)
/* 6A0B44 80219944 AC60FFF8 */  sw        $zero, -8($v1)
/* 6A0B48 80219948 AC60FFFC */  sw        $zero, -4($v1)
/* 6A0B4C 8021994C AC600000 */  sw        $zero, ($v1)
/* 6A0B50 80219950 24630034 */  addiu     $v1, $v1, 0x34
/* 6A0B54 80219954 26520001 */  addiu     $s2, $s2, 1
/* 6A0B58 80219958 2A420003 */  slti      $v0, $s2, 3
/* 6A0B5C 8021995C 1440FFF0 */  bnez      $v0, .L80219920
/* 6A0B60 80219960 24840010 */   addiu    $a0, $a0, 0x10
/* 6A0B64 80219964 08086711 */  j         .L80219C44
/* 6A0B68 80219968 0000102D */   daddu    $v0, $zero, $zero
.L8021996C:
/* 6A0B6C 8021996C 8E910078 */  lw        $s1, 0x78($s4)
/* 6A0B70 80219970 0260902D */  daddu     $s2, $s3, $zero
/* 6A0B74 80219974 26300030 */  addiu     $s0, $s1, 0x30
.L80219978:
/* 6A0B78 80219978 8E02FFE4 */  lw        $v0, -0x1c($s0)
/* 6A0B7C 8021997C 18400019 */  blez      $v0, .L802199E4
/* 6A0B80 80219980 2442FFFF */   addiu    $v0, $v0, -1
/* 6A0B84 80219984 1C4000A4 */  bgtz      $v0, .L80219C18
/* 6A0B88 80219988 AE02FFE4 */   sw       $v0, -0x1c($s0)
/* 6A0B8C 8021998C C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A0B90 80219990 2402FFFF */  addiu     $v0, $zero, -1
/* 6A0B94 80219994 AFA20014 */  sw        $v0, 0x14($sp)
/* 6A0B98 80219998 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6A0B9C 8021999C 8E05FFD4 */  lw        $a1, -0x2c($s0)
/* 6A0BA0 802199A0 8E06FFD8 */  lw        $a2, -0x28($s0)
/* 6A0BA4 802199A4 8E07FFDC */  lw        $a3, -0x24($s0)
/* 6A0BA8 802199A8 0C01CA9C */  jal       playFX_85
/* 6A0BAC 802199AC 0000202D */   daddu    $a0, $zero, $zero
/* 6A0BB0 802199B0 AE220000 */  sw        $v0, ($s1)
/* 6A0BB4 802199B4 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0BB8 802199B8 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A0BBC 802199BC E440003C */  swc1      $f0, 0x3c($v0)
/* 6A0BC0 802199C0 8E220000 */  lw        $v0, ($s1)
/* 6A0BC4 802199C4 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A0BC8 802199C8 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0BCC 802199CC E4400040 */  swc1      $f0, 0x40($v0)
/* 6A0BD0 802199D0 8E220000 */  lw        $v0, ($s1)
/* 6A0BD4 802199D4 C600FFFC */  lwc1      $f0, -4($s0)
/* 6A0BD8 802199D8 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0BDC 802199DC 08086706 */  j         .L80219C18
/* 6A0BE0 802199E0 E4400044 */   swc1     $f0, 0x44($v0)
.L802199E4:
/* 6A0BE4 802199E4 8E020000 */  lw        $v0, ($s0)
/* 6A0BE8 802199E8 10400003 */  beqz      $v0, .L802199F8
/* 6A0BEC 802199EC 2402000A */   addiu    $v0, $zero, 0xa
/* 6A0BF0 802199F0 08086706 */  j         .L80219C18
/* 6A0BF4 802199F4 26730001 */   addiu    $s3, $s3, 1
.L802199F8:
/* 6A0BF8 802199F8 82830210 */  lb        $v1, 0x210($s4)
/* 6A0BFC 802199FC 10620023 */  beq       $v1, $v0, .L80219A8C
/* 6A0C00 80219A00 00000000 */   nop
/* 6A0C04 80219A04 C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 6A0C08 80219A08 3C014044 */  lui       $at, 0x4044
/* 6A0C0C 80219A0C 44810800 */  mtc1      $at, $f1
/* 6A0C10 80219A10 44800000 */  mtc1      $zero, $f0
/* 6A0C14 80219A14 460010A1 */  cvt.d.s   $f2, $f2
/* 6A0C18 80219A18 4620103C */  c.lt.d    $f2, $f0
/* 6A0C1C 80219A1C 3C014008 */  lui       $at, 0x4008
/* 6A0C20 80219A20 44810800 */  mtc1      $at, $f1
/* 6A0C24 80219A24 44800000 */  mtc1      $zero, $f0
/* 6A0C28 80219A28 45030037 */  bc1tl     .L80219B08
/* 6A0C2C 80219A2C 46201000 */   add.d    $f0, $f2, $f0
/* 6A0C30 80219A30 3C01404E */  lui       $at, 0x404e
/* 6A0C34 80219A34 44810800 */  mtc1      $at, $f1
/* 6A0C38 80219A38 44800000 */  mtc1      $zero, $f0
/* 6A0C3C 80219A3C 00000000 */  nop
/* 6A0C40 80219A40 4620103C */  c.lt.d    $f2, $f0
/* 6A0C44 80219A44 3C018023 */  lui       $at, %hi(D_80234788_6BB988)
/* 6A0C48 80219A48 D4204788 */  ldc1      $f0, %lo(D_80234788_6BB988)($at)
/* 6A0C4C 80219A4C 4503002E */  bc1tl     .L80219B08
/* 6A0C50 80219A50 46201000 */   add.d    $f0, $f2, $f0
/* 6A0C54 80219A54 3C014054 */  lui       $at, 0x4054
/* 6A0C58 80219A58 44810800 */  mtc1      $at, $f1
/* 6A0C5C 80219A5C 44800000 */  mtc1      $zero, $f0
/* 6A0C60 80219A60 00000000 */  nop
/* 6A0C64 80219A64 4620103C */  c.lt.d    $f2, $f0
/* 6A0C68 80219A68 3C018023 */  lui       $at, %hi(D_80234790_6BB990)
/* 6A0C6C 80219A6C D4204790 */  ldc1      $f0, %lo(D_80234790_6BB990)($at)
/* 6A0C70 80219A70 45030025 */  bc1tl     .L80219B08
/* 6A0C74 80219A74 46201000 */   add.d    $f0, $f2, $f0
/* 6A0C78 80219A78 3C013FF0 */  lui       $at, 0x3ff0
/* 6A0C7C 80219A7C 44810800 */  mtc1      $at, $f1
/* 6A0C80 80219A80 44800000 */  mtc1      $zero, $f0
/* 6A0C84 80219A84 080866C2 */  j         .L80219B08
/* 6A0C88 80219A88 46201000 */   add.d    $f0, $f2, $f0
.L80219A8C:
/* 6A0C8C 80219A8C C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 6A0C90 80219A90 3C014030 */  lui       $at, 0x4030
/* 6A0C94 80219A94 44810800 */  mtc1      $at, $f1
/* 6A0C98 80219A98 44800000 */  mtc1      $zero, $f0
/* 6A0C9C 80219A9C 460010A1 */  cvt.d.s   $f2, $f2
/* 6A0CA0 80219AA0 4620103C */  c.lt.d    $f2, $f0
/* 6A0CA4 80219AA4 3C018023 */  lui       $at, %hi(D_80234798_6BB998)
/* 6A0CA8 80219AA8 D4204798 */  ldc1      $f0, %lo(D_80234798_6BB998)($at)
/* 6A0CAC 80219AAC 45030016 */  bc1tl     .L80219B08
/* 6A0CB0 80219AB0 46201000 */   add.d    $f0, $f2, $f0
/* 6A0CB4 80219AB4 3C014038 */  lui       $at, 0x4038
/* 6A0CB8 80219AB8 44810800 */  mtc1      $at, $f1
/* 6A0CBC 80219ABC 44800000 */  mtc1      $zero, $f0
/* 6A0CC0 80219AC0 00000000 */  nop
/* 6A0CC4 80219AC4 4620103C */  c.lt.d    $f2, $f0
/* 6A0CC8 80219AC8 3C018023 */  lui       $at, %hi(D_802347A0_6BB9A0)
/* 6A0CCC 80219ACC D42047A0 */  ldc1      $f0, %lo(D_802347A0_6BB9A0)($at)
/* 6A0CD0 80219AD0 4503000D */  bc1tl     .L80219B08
/* 6A0CD4 80219AD4 46201000 */   add.d    $f0, $f2, $f0
/* 6A0CD8 80219AD8 3C014040 */  lui       $at, 0x4040
/* 6A0CDC 80219ADC 44810800 */  mtc1      $at, $f1
/* 6A0CE0 80219AE0 44800000 */  mtc1      $zero, $f0
/* 6A0CE4 80219AE4 00000000 */  nop
/* 6A0CE8 80219AE8 4620103C */  c.lt.d    $f2, $f0
/* 6A0CEC 80219AEC 3C018023 */  lui       $at, %hi(D_802347A8_6BB9A8)
/* 6A0CF0 80219AF0 D42047A8 */  ldc1      $f0, %lo(D_802347A8_6BB9A8)($at)
/* 6A0CF4 80219AF4 45020004 */  bc1fl     .L80219B08
/* 6A0CF8 80219AF8 46201000 */   add.d    $f0, $f2, $f0
/* 6A0CFC 80219AFC 3C018023 */  lui       $at, %hi(D_802347B0_6BB9B0)
/* 6A0D00 80219B00 D42047B0 */  ldc1      $f0, %lo(D_802347B0_6BB9B0)($at)
/* 6A0D04 80219B04 46201000 */  add.d     $f0, $f2, $f0
.L80219B08:
/* 6A0D08 80219B08 46200020 */  cvt.s.d   $f0, $f0
/* 6A0D0C 80219B0C E600FFD8 */  swc1      $f0, -0x28($s0)
/* 6A0D10 80219B10 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A0D14 80219B14 3C014190 */  lui       $at, 0x4190
/* 6A0D18 80219B18 44811000 */  mtc1      $at, $f2
/* 6A0D1C 80219B1C 8E03FFE8 */  lw        $v1, -0x18($s0)
/* 6A0D20 80219B20 46020000 */  add.s     $f0, $f0, $f2
/* 6A0D24 80219B24 28620011 */  slti      $v0, $v1, 0x11
/* 6A0D28 80219B28 1040000E */  beqz      $v0, .L80219B64
/* 6A0D2C 80219B2C E600FFF8 */   swc1     $f0, -8($s0)
/* 6A0D30 80219B30 00031200 */  sll       $v0, $v1, 8
/* 6A0D34 80219B34 00431823 */  subu      $v1, $v0, $v1
/* 6A0D38 80219B38 04620001 */  bltzl     $v1, .L80219B40
/* 6A0D3C 80219B3C 2463000F */   addiu    $v1, $v1, 0xf
.L80219B40:
/* 6A0D40 80219B40 8E02FFE8 */  lw        $v0, -0x18($s0)
/* 6A0D44 80219B44 00031903 */  sra       $v1, $v1, 4
/* 6A0D48 80219B48 AE03FFEC */  sw        $v1, -0x14($s0)
/* 6A0D4C 80219B4C 00021A00 */  sll       $v1, $v0, 8
/* 6A0D50 80219B50 00621023 */  subu      $v0, $v1, $v0
/* 6A0D54 80219B54 04420001 */  bltzl     $v0, .L80219B5C
/* 6A0D58 80219B58 2442000F */   addiu    $v0, $v0, 0xf
.L80219B5C:
/* 6A0D5C 80219B5C 00021103 */  sra       $v0, $v0, 4
/* 6A0D60 80219B60 AE02FFF0 */  sw        $v0, -0x10($s0)
.L80219B64:
/* 6A0D64 80219B64 8E220000 */  lw        $v0, ($s1)
/* 6A0D68 80219B68 C600FFD4 */  lwc1      $f0, -0x2c($s0)
/* 6A0D6C 80219B6C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0D70 80219B70 E4400004 */  swc1      $f0, 4($v0)
/* 6A0D74 80219B74 8E220000 */  lw        $v0, ($s1)
/* 6A0D78 80219B78 C600FFD8 */  lwc1      $f0, -0x28($s0)
/* 6A0D7C 80219B7C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0D80 80219B80 E4400008 */  swc1      $f0, 8($v0)
/* 6A0D84 80219B84 8E220000 */  lw        $v0, ($s1)
/* 6A0D88 80219B88 C600FFDC */  lwc1      $f0, -0x24($s0)
/* 6A0D8C 80219B8C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0D90 80219B90 E440000C */  swc1      $f0, 0xc($v0)
/* 6A0D94 80219B94 8E220000 */  lw        $v0, ($s1)
/* 6A0D98 80219B98 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A0D9C 80219B9C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0DA0 80219BA0 E440003C */  swc1      $f0, 0x3c($v0)
/* 6A0DA4 80219BA4 8E220000 */  lw        $v0, ($s1)
/* 6A0DA8 80219BA8 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A0DAC 80219BAC 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0DB0 80219BB0 E4400040 */  swc1      $f0, 0x40($v0)
/* 6A0DB4 80219BB4 8E220000 */  lw        $v0, ($s1)
/* 6A0DB8 80219BB8 C600FFFC */  lwc1      $f0, -4($s0)
/* 6A0DBC 80219BBC 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0DC0 80219BC0 E4400044 */  swc1      $f0, 0x44($v0)
/* 6A0DC4 80219BC4 8E220000 */  lw        $v0, ($s1)
/* 6A0DC8 80219BC8 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A0DCC 80219BCC 8C42000C */  lw        $v0, 0xc($v0)
/* 6A0DD0 80219BD0 E4400038 */  swc1      $f0, 0x38($v0)
/* 6A0DD4 80219BD4 8E220000 */  lw        $v0, ($s1)
/* 6A0DD8 80219BD8 8C43000C */  lw        $v1, 0xc($v0)
/* 6A0DDC 80219BDC 8E02FFEC */  lw        $v0, -0x14($s0)
/* 6A0DE0 80219BE0 AC620024 */  sw        $v0, 0x24($v1)
/* 6A0DE4 80219BE4 8E220000 */  lw        $v0, ($s1)
/* 6A0DE8 80219BE8 8C43000C */  lw        $v1, 0xc($v0)
/* 6A0DEC 80219BEC 8E02FFF0 */  lw        $v0, -0x10($s0)
/* 6A0DF0 80219BF0 AC620034 */  sw        $v0, 0x34($v1)
/* 6A0DF4 80219BF4 8E02FFE8 */  lw        $v0, -0x18($s0)
/* 6A0DF8 80219BF8 2442FFFF */  addiu     $v0, $v0, -1
/* 6A0DFC 80219BFC 1C400006 */  bgtz      $v0, .L80219C18
/* 6A0E00 80219C00 AE02FFE8 */   sw       $v0, -0x18($s0)
/* 6A0E04 80219C04 8E240000 */  lw        $a0, ($s1)
/* 6A0E08 80219C08 0C016914 */  jal       remove_effect
/* 6A0E0C 80219C0C 00000000 */   nop
/* 6A0E10 80219C10 24020001 */  addiu     $v0, $zero, 1
/* 6A0E14 80219C14 AE020000 */  sw        $v0, ($s0)
.L80219C18:
/* 6A0E18 80219C18 26100034 */  addiu     $s0, $s0, 0x34
/* 6A0E1C 80219C1C 26520001 */  addiu     $s2, $s2, 1
/* 6A0E20 80219C20 2A420003 */  slti      $v0, $s2, 3
/* 6A0E24 80219C24 1440FF54 */  bnez      $v0, .L80219978
/* 6A0E28 80219C28 26310034 */   addiu    $s1, $s1, 0x34
/* 6A0E2C 80219C2C 2A620003 */  slti      $v0, $s3, 3
/* 6A0E30 80219C30 14400004 */  bnez      $v0, .L80219C44
/* 6A0E34 80219C34 0000102D */   daddu    $v0, $zero, $zero
/* 6A0E38 80219C38 0C00AB4B */  jal       heap_free
/* 6A0E3C 80219C3C 0220202D */   daddu    $a0, $s1, $zero
/* 6A0E40 80219C40 24020002 */  addiu     $v0, $zero, 2
.L80219C44:
/* 6A0E44 80219C44 8FBF002C */  lw        $ra, 0x2c($sp)
/* 6A0E48 80219C48 8FB40028 */  lw        $s4, 0x28($sp)
/* 6A0E4C 80219C4C 8FB30024 */  lw        $s3, 0x24($sp)
/* 6A0E50 80219C50 8FB20020 */  lw        $s2, 0x20($sp)
/* 6A0E54 80219C54 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6A0E58 80219C58 8FB00018 */  lw        $s0, 0x18($sp)
/* 6A0E5C 80219C5C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 6A0E60 80219C60 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6A0E64 80219C64 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6A0E68 80219C68 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6A0E6C 80219C6C 03E00008 */  jr        $ra
/* 6A0E70 80219C70 27BD0050 */   addiu    $sp, $sp, 0x50
