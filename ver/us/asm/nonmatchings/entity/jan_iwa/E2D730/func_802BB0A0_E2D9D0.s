.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802BCDC0_E2F6F0
.double 0.02

glabel D_802BCDC8_E2F6F8
.double 0.4

glabel D_802BCDD0_E2F700
.double 0.8

.section .text

glabel func_802BB0A0_E2D9D0
/* E2D9D0 802BB0A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2D9D4 802BB0A4 AFB10014 */  sw        $s1, 0x14($sp)
/* E2D9D8 802BB0A8 0080882D */  daddu     $s1, $a0, $zero
/* E2D9DC 802BB0AC AFBF001C */  sw        $ra, 0x1c($sp)
/* E2D9E0 802BB0B0 AFB20018 */  sw        $s2, 0x18($sp)
/* E2D9E4 802BB0B4 AFB00010 */  sw        $s0, 0x10($sp)
/* E2D9E8 802BB0B8 0C0AEC00 */  jal       func_802BB000_E2D930
/* E2D9EC 802BB0BC 8E300040 */   lw       $s0, 0x40($s1)
/* E2D9F0 802BB0C0 82030002 */  lb        $v1, 2($s0)
/* E2D9F4 802BB0C4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* E2D9F8 802BB0C8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* E2D9FC 802BB0CC 10600005 */  beqz      $v1, .L802BB0E4
/* E2DA00 802BB0D0 24020001 */   addiu    $v0, $zero, 1
/* E2DA04 802BB0D4 1062000A */  beq       $v1, $v0, .L802BB100
/* E2DA08 802BB0D8 00000000 */   nop
/* E2DA0C 802BB0DC 080AEC67 */  j         .L802BB19C
/* E2DA10 802BB0E0 00000000 */   nop
.L802BB0E4:
/* E2DA14 802BB0E4 24020001 */  addiu     $v0, $zero, 1
/* E2DA18 802BB0E8 AE000018 */  sw        $zero, 0x18($s0)
/* E2DA1C 802BB0EC A6000000 */  sh        $zero, ($s0)
/* E2DA20 802BB0F0 A2020002 */  sb        $v0, 2($s0)
/* E2DA24 802BB0F4 AE000004 */  sw        $zero, 4($s0)
/* E2DA28 802BB0F8 080AEC67 */  j         .L802BB19C
/* E2DA2C 802BB0FC AE00000C */   sw       $zero, 0xc($s0)
.L802BB100:
/* E2DA30 802BB100 92220006 */  lbu       $v0, 6($s1)
/* E2DA34 802BB104 30420001 */  andi      $v0, $v0, 1
/* E2DA38 802BB108 14400017 */  bnez      $v0, .L802BB168
/* E2DA3C 802BB10C 00000000 */   nop
/* E2DA40 802BB110 C6000014 */  lwc1      $f0, 0x14($s0)
/* E2DA44 802BB114 3C01802C */  lui       $at, %hi(D_802BCDC0_E2F6F0)
/* E2DA48 802BB118 D422CDC0 */  ldc1      $f2, %lo(D_802BCDC0_E2F6F0)($at)
/* E2DA4C 802BB11C 46000021 */  cvt.d.s   $f0, $f0
/* E2DA50 802BB120 46220000 */  add.d     $f0, $f0, $f2
/* E2DA54 802BB124 3C014000 */  lui       $at, 0x4000
/* E2DA58 802BB128 44812800 */  mtc1      $at, $f5
/* E2DA5C 802BB12C 44802000 */  mtc1      $zero, $f4
/* E2DA60 802BB130 46200020 */  cvt.s.d   $f0, $f0
/* E2DA64 802BB134 460000A1 */  cvt.d.s   $f2, $f0
/* E2DA68 802BB138 4622203C */  c.lt.d    $f4, $f2
/* E2DA6C 802BB13C 00000000 */  nop
/* E2DA70 802BB140 45000016 */  bc1f      .L802BB19C
/* E2DA74 802BB144 E6000014 */   swc1     $f0, 0x14($s0)
/* E2DA78 802BB148 45000014 */  bc1f      .L802BB19C
/* E2DA7C 802BB14C 00000000 */   nop
/* E2DA80 802BB150 3C01802C */  lui       $at, %hi(D_802BCDC8_E2F6F8)
/* E2DA84 802BB154 D420CDC8 */  ldc1      $f0, %lo(D_802BCDC8_E2F6F8)($at)
/* E2DA88 802BB158 46201001 */  sub.d     $f0, $f2, $f0
/* E2DA8C 802BB15C 46200020 */  cvt.s.d   $f0, $f0
/* E2DA90 802BB160 080AEC67 */  j         .L802BB19C
/* E2DA94 802BB164 E6000014 */   swc1     $f0, 0x14($s0)
.L802BB168:
/* E2DA98 802BB168 C6000014 */  lwc1      $f0, 0x14($s0)
/* E2DA9C 802BB16C 3C01802C */  lui       $at, %hi(D_802BCDD0_E2F700)
/* E2DAA0 802BB170 D422CDD0 */  ldc1      $f2, %lo(D_802BCDD0_E2F700)($at)
/* E2DAA4 802BB174 46000021 */  cvt.d.s   $f0, $f0
/* E2DAA8 802BB178 46220000 */  add.d     $f0, $f0, $f2
/* E2DAAC 802BB17C 3C014160 */  lui       $at, 0x4160
/* E2DAB0 802BB180 44811000 */  mtc1      $at, $f2
/* E2DAB4 802BB184 46200020 */  cvt.s.d   $f0, $f0
/* E2DAB8 802BB188 4600103C */  c.lt.s    $f2, $f0
/* E2DABC 802BB18C 00000000 */  nop
/* E2DAC0 802BB190 45000002 */  bc1f      .L802BB19C
/* E2DAC4 802BB194 E6000014 */   swc1     $f0, 0x14($s0)
/* E2DAC8 802BB198 E6020014 */  swc1      $f2, 0x14($s0)
.L802BB19C:
/* E2DACC 802BB19C C6000008 */  lwc1      $f0, 8($s0)
/* E2DAD0 802BB1A0 C60C0014 */  lwc1      $f12, 0x14($s0)
/* E2DAD4 802BB1A4 0C00A6C9 */  jal       clamp_angle
/* E2DAD8 802BB1A8 460C0300 */   add.s    $f12, $f0, $f12
/* E2DADC 802BB1AC E6000008 */  swc1      $f0, 8($s0)
/* E2DAE0 802BB1B0 92220006 */  lbu       $v0, 6($s1)
/* E2DAE4 802BB1B4 30420001 */  andi      $v0, $v0, 1
/* E2DAE8 802BB1B8 14400015 */  bnez      $v0, .L802BB210
/* E2DAEC 802BB1BC 3C030001 */   lui      $v1, 1
/* E2DAF0 802BB1C0 8E420004 */  lw        $v0, 4($s2)
/* E2DAF4 802BB1C4 00431024 */  and       $v0, $v0, $v1
/* E2DAF8 802BB1C8 10400011 */  beqz      $v0, .L802BB210
/* E2DAFC 802BB1CC 00000000 */   nop
/* E2DB00 802BB1D0 C62C0048 */  lwc1      $f12, 0x48($s1)
/* E2DB04 802BB1D4 C62E0050 */  lwc1      $f14, 0x50($s1)
/* E2DB08 802BB1D8 8E460028 */  lw        $a2, 0x28($s2)
/* E2DB0C 802BB1DC 0C00A7B5 */  jal       dist2D
/* E2DB10 802BB1E0 8E470030 */   lw       $a3, 0x30($s2)
/* E2DB14 802BB1E4 46000021 */  cvt.d.s   $f0, $f0
/* E2DB18 802BB1E8 3C01404E */  lui       $at, 0x404e
/* E2DB1C 802BB1EC 44811800 */  mtc1      $at, $f3
/* E2DB20 802BB1F0 44801000 */  mtc1      $zero, $f2
/* E2DB24 802BB1F4 46200005 */  abs.d     $f0, $f0
/* E2DB28 802BB1F8 4622003C */  c.lt.d    $f0, $f2
/* E2DB2C 802BB1FC 00000000 */  nop
/* E2DB30 802BB200 45000003 */  bc1f      .L802BB210
/* E2DB34 802BB204 00000000 */   nop
/* E2DB38 802BB208 0C043F5A */  jal       exec_entity_commandlist
/* E2DB3C 802BB20C 0220202D */   daddu    $a0, $s1, $zero
.L802BB210:
/* E2DB40 802BB210 8FBF001C */  lw        $ra, 0x1c($sp)
/* E2DB44 802BB214 8FB20018 */  lw        $s2, 0x18($sp)
/* E2DB48 802BB218 8FB10014 */  lw        $s1, 0x14($sp)
/* E2DB4C 802BB21C 8FB00010 */  lw        $s0, 0x10($sp)
/* E2DB50 802BB220 03E00008 */  jr        $ra
/* E2DB54 802BB224 27BD0020 */   addiu    $sp, $sp, 0x20
