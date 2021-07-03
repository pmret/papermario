.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243080_DE5510
.double 35.0

glabel D_80243088_DE5518
.double 360.0

.section .text

glabel func_8024083C_DE2CCC
/* DE2CCC 8024083C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE2CD0 80240840 AFB20018 */  sw        $s2, 0x18($sp)
/* DE2CD4 80240844 0080902D */  daddu     $s2, $a0, $zero
/* DE2CD8 80240848 AFBF001C */  sw        $ra, 0x1c($sp)
/* DE2CDC 8024084C AFB10014 */  sw        $s1, 0x14($sp)
/* DE2CE0 80240850 AFB00010 */  sw        $s0, 0x10($sp)
/* DE2CE4 80240854 8E500148 */  lw        $s0, 0x148($s2)
/* DE2CE8 80240858 0C00EABB */  jal       get_npc_unsafe
/* DE2CEC 8024085C 86040008 */   lh       $a0, 8($s0)
/* DE2CF0 80240860 8E03006C */  lw        $v1, 0x6c($s0)
/* DE2CF4 80240864 24060001 */  addiu     $a2, $zero, 1
/* DE2CF8 80240868 10660016 */  beq       $v1, $a2, .L802408C4
/* DE2CFC 8024086C 0040882D */   daddu    $s1, $v0, $zero
/* DE2D00 80240870 28620002 */  slti      $v0, $v1, 2
/* DE2D04 80240874 50400005 */  beql      $v0, $zero, .L8024088C
/* DE2D08 80240878 24020002 */   addiu    $v0, $zero, 2
/* DE2D0C 8024087C 10600009 */  beqz      $v1, .L802408A4
/* DE2D10 80240880 3C02003C */   lui      $v0, 0x3c
/* DE2D14 80240884 08090274 */  j         .L802409D0
/* DE2D18 80240888 24020004 */   addiu    $v0, $zero, 4
.L8024088C:
/* DE2D1C 8024088C 10620030 */  beq       $v1, $v0, .L80240950
/* DE2D20 80240890 24020003 */   addiu    $v0, $zero, 3
/* DE2D24 80240894 10620034 */  beq       $v1, $v0, .L80240968
/* DE2D28 80240898 00000000 */   nop
/* DE2D2C 8024089C 08090272 */  j         .L802409C8
/* DE2D30 802408A0 00000000 */   nop
.L802408A4:
/* DE2D34 802408A4 3442000C */  ori       $v0, $v0, 0xc
/* DE2D38 802408A8 3C054387 */  lui       $a1, 0x4387
/* DE2D3C 802408AC 0220202D */  daddu     $a0, $s1, $zero
/* DE2D40 802408B0 AE06006C */  sw        $a2, 0x6c($s0)
/* DE2D44 802408B4 AE000070 */  sw        $zero, 0x70($s0)
/* DE2D48 802408B8 0C00ECD0 */  jal       set_npc_yaw
/* DE2D4C 802408BC AE220028 */   sw       $v0, 0x28($s1)
/* DE2D50 802408C0 AE200048 */  sw        $zero, 0x48($s1)
.L802408C4:
/* DE2D54 802408C4 8E030070 */  lw        $v1, 0x70($s0)
/* DE2D58 802408C8 04610002 */  bgez      $v1, .L802408D4
/* DE2D5C 802408CC 0060102D */   daddu    $v0, $v1, $zero
/* DE2D60 802408D0 2462000F */  addiu     $v0, $v1, 0xf
.L802408D4:
/* DE2D64 802408D4 00022103 */  sra       $a0, $v0, 4
/* DE2D68 802408D8 00041100 */  sll       $v0, $a0, 4
/* DE2D6C 802408DC 00622023 */  subu      $a0, $v1, $v0
/* DE2D70 802408E0 28820004 */  slti      $v0, $a0, 4
/* DE2D74 802408E4 10400003 */  beqz      $v0, .L802408F4
/* DE2D78 802408E8 3C02003C */   lui      $v0, 0x3c
/* DE2D7C 802408EC 0809024B */  j         .L8024092C
/* DE2D80 802408F0 3442000C */   ori      $v0, $v0, 0xc
.L802408F4:
/* DE2D84 802408F4 28820008 */  slti      $v0, $a0, 8
/* DE2D88 802408F8 10400003 */  beqz      $v0, .L80240908
/* DE2D8C 802408FC 3C02003C */   lui      $v0, 0x3c
/* DE2D90 80240900 0809024B */  j         .L8024092C
/* DE2D94 80240904 3442000B */   ori      $v0, $v0, 0xb
.L80240908:
/* DE2D98 80240908 2882000C */  slti      $v0, $a0, 0xc
/* DE2D9C 8024090C 10400003 */  beqz      $v0, .L8024091C
/* DE2DA0 80240910 3C02003C */   lui      $v0, 0x3c
/* DE2DA4 80240914 0809024B */  j         .L8024092C
/* DE2DA8 80240918 3442000C */   ori      $v0, $v0, 0xc
.L8024091C:
/* DE2DAC 8024091C 28820010 */  slti      $v0, $a0, 0x10
/* DE2DB0 80240920 10400003 */  beqz      $v0, .L80240930
/* DE2DB4 80240924 3C02003C */   lui      $v0, 0x3c
/* DE2DB8 80240928 3442000D */  ori       $v0, $v0, 0xd
.L8024092C:
/* DE2DBC 8024092C AE220028 */  sw        $v0, 0x28($s1)
.L80240930:
/* DE2DC0 80240930 8E020070 */  lw        $v0, 0x70($s0)
/* DE2DC4 80240934 24420001 */  addiu     $v0, $v0, 1
/* DE2DC8 80240938 AE020070 */  sw        $v0, 0x70($s0)
/* DE2DCC 8024093C 28420041 */  slti      $v0, $v0, 0x41
/* DE2DD0 80240940 14400021 */  bnez      $v0, .L802409C8
/* DE2DD4 80240944 24020002 */   addiu    $v0, $zero, 2
/* DE2DD8 80240948 08090272 */  j         .L802409C8
/* DE2DDC 8024094C AE02006C */   sw       $v0, 0x6c($s0)
.L80240950:
/* DE2DE0 80240950 3C03003C */  lui       $v1, 0x3c
/* DE2DE4 80240954 3463000C */  ori       $v1, $v1, 0xc
/* DE2DE8 80240958 AE02006C */  sw        $v0, 0x6c($s0)
/* DE2DEC 8024095C AE000070 */  sw        $zero, 0x70($s0)
/* DE2DF0 80240960 AE200048 */  sw        $zero, 0x48($s1)
/* DE2DF4 80240964 AE230028 */  sw        $v1, 0x28($s1)
.L80240968:
/* DE2DF8 80240968 C6200048 */  lwc1      $f0, 0x48($s1)
/* DE2DFC 8024096C 3C018024 */  lui       $at, %hi(D_80243080_DE5510)
/* DE2E00 80240970 D4223080 */  ldc1      $f2, %lo(D_80243080_DE5510)($at)
/* DE2E04 80240974 46000021 */  cvt.d.s   $f0, $f0
/* DE2E08 80240978 46220000 */  add.d     $f0, $f0, $f2
/* DE2E0C 8024097C 3C018024 */  lui       $at, %hi(D_80243088_DE5518)
/* DE2E10 80240980 D4223088 */  ldc1      $f2, %lo(D_80243088_DE5518)($at)
/* DE2E14 80240984 46200020 */  cvt.s.d   $f0, $f0
/* DE2E18 80240988 E6200048 */  swc1      $f0, 0x48($s1)
/* DE2E1C 8024098C 46000021 */  cvt.d.s   $f0, $f0
/* DE2E20 80240990 4620103C */  c.lt.d    $f2, $f0
/* DE2E24 80240994 00000000 */  nop
/* DE2E28 80240998 45000004 */  bc1f      .L802409AC
/* DE2E2C 8024099C 00000000 */   nop
/* DE2E30 802409A0 46220001 */  sub.d     $f0, $f0, $f2
/* DE2E34 802409A4 46200020 */  cvt.s.d   $f0, $f0
/* DE2E38 802409A8 E6200048 */  swc1      $f0, 0x48($s1)
.L802409AC:
/* DE2E3C 802409AC 8E020070 */  lw        $v0, 0x70($s0)
/* DE2E40 802409B0 24420001 */  addiu     $v0, $v0, 1
/* DE2E44 802409B4 AE020070 */  sw        $v0, 0x70($s0)
/* DE2E48 802409B8 2842002E */  slti      $v0, $v0, 0x2e
/* DE2E4C 802409BC 14400002 */  bnez      $v0, .L802409C8
/* DE2E50 802409C0 24020004 */   addiu    $v0, $zero, 4
/* DE2E54 802409C4 AE02006C */  sw        $v0, 0x6c($s0)
.L802409C8:
/* DE2E58 802409C8 8E03006C */  lw        $v1, 0x6c($s0)
/* DE2E5C 802409CC 24020004 */  addiu     $v0, $zero, 4
.L802409D0:
/* DE2E60 802409D0 14620005 */  bne       $v1, $v0, .L802409E8
/* DE2E64 802409D4 0220202D */   daddu    $a0, $s1, $zero
/* DE2E68 802409D8 3C054387 */  lui       $a1, 0x4387
/* DE2E6C 802409DC 0C00ECD0 */  jal       set_npc_yaw
/* DE2E70 802409E0 AC800048 */   sw       $zero, 0x48($a0)
/* DE2E74 802409E4 AE400070 */  sw        $zero, 0x70($s2)
.L802409E8:
/* DE2E78 802409E8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DE2E7C 802409EC 8FB20018 */  lw        $s2, 0x18($sp)
/* DE2E80 802409F0 8FB10014 */  lw        $s1, 0x14($sp)
/* DE2E84 802409F4 8FB00010 */  lw        $s0, 0x10($sp)
/* DE2E88 802409F8 03E00008 */  jr        $ra
/* DE2E8C 802409FC 27BD0020 */   addiu    $sp, $sp, 0x20
