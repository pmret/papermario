.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A08_DF18A8
/* DF18A8 80242A08 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* DF18AC 80242A0C AFB7004C */  sw        $s7, 0x4c($sp)
/* DF18B0 80242A10 0080B82D */  daddu     $s7, $a0, $zero
/* DF18B4 80242A14 AFB10034 */  sw        $s1, 0x34($sp)
/* DF18B8 80242A18 00A0882D */  daddu     $s1, $a1, $zero
/* DF18BC 80242A1C AFBF0050 */  sw        $ra, 0x50($sp)
/* DF18C0 80242A20 AFB60048 */  sw        $s6, 0x48($sp)
/* DF18C4 80242A24 AFB50044 */  sw        $s5, 0x44($sp)
/* DF18C8 80242A28 AFB40040 */  sw        $s4, 0x40($sp)
/* DF18CC 80242A2C AFB3003C */  sw        $s3, 0x3c($sp)
/* DF18D0 80242A30 AFB20038 */  sw        $s2, 0x38($sp)
/* DF18D4 80242A34 AFB00030 */  sw        $s0, 0x30($sp)
/* DF18D8 80242A38 8EF30148 */  lw        $s3, 0x148($s7)
/* DF18DC 80242A3C 86640008 */  lh        $a0, 8($s3)
/* DF18E0 80242A40 8EF0000C */  lw        $s0, 0xc($s7)
/* DF18E4 80242A44 0C00FB5A */  jal       get_enemy_safe
/* DF18E8 80242A48 0000B02D */   daddu    $s6, $zero, $zero
/* DF18EC 80242A4C 10400131 */  beqz      $v0, .L80242F14
/* DF18F0 80242A50 24020005 */   addiu    $v0, $zero, 5
/* DF18F4 80242A54 8E63006C */  lw        $v1, 0x6c($s3)
/* DF18F8 80242A58 1062012F */  beq       $v1, $v0, .L80242F18
/* DF18FC 80242A5C 0000102D */   daddu    $v0, $zero, $zero
/* DF1900 80242A60 8E050000 */  lw        $a1, ($s0)
/* DF1904 80242A64 0C0B1EAF */  jal       evt_get_variable
/* DF1908 80242A68 02E0202D */   daddu    $a0, $s7, $zero
/* DF190C 80242A6C 86640008 */  lh        $a0, 8($s3)
/* DF1910 80242A70 0C00EABB */  jal       get_npc_unsafe
/* DF1914 80242A74 0040A82D */   daddu    $s5, $v0, $zero
/* DF1918 80242A78 8E630070 */  lw        $v1, 0x70($s3)
/* DF191C 80242A7C 30630002 */  andi      $v1, $v1, 2
/* DF1920 80242A80 10600008 */  beqz      $v1, .L80242AA4
/* DF1924 80242A84 0040902D */   daddu    $s2, $v0, $zero
/* DF1928 80242A88 964200A8 */  lhu       $v0, 0xa8($s2)
/* DF192C 80242A8C 00021400 */  sll       $v0, $v0, 0x10
/* DF1930 80242A90 00021C03 */  sra       $v1, $v0, 0x10
/* DF1934 80242A94 000217C2 */  srl       $v0, $v0, 0x1f
/* DF1938 80242A98 00621821 */  addu      $v1, $v1, $v0
/* DF193C 80242A9C 00031843 */  sra       $v1, $v1, 1
/* DF1940 80242AA0 A24300AB */  sb        $v1, 0xab($s2)
.L80242AA4:
/* DF1944 80242AA4 16200005 */  bnez      $s1, .L80242ABC
/* DF1948 80242AA8 3C030004 */   lui      $v1, 4
/* DF194C 80242AAC 8E6200B0 */  lw        $v0, 0xb0($s3)
/* DF1950 80242AB0 30420004 */  andi      $v0, $v0, 4
/* DF1954 80242AB4 10400019 */  beqz      $v0, .L80242B1C
/* DF1958 80242AB8 00000000 */   nop
.L80242ABC:
/* DF195C 80242ABC 34630102 */  ori       $v1, $v1, 0x102
/* DF1960 80242AC0 AEE00070 */  sw        $zero, 0x70($s7)
/* DF1964 80242AC4 8E420000 */  lw        $v0, ($s2)
/* DF1968 80242AC8 0240202D */  daddu     $a0, $s2, $zero
/* DF196C 80242ACC A640008E */  sh        $zero, 0x8e($s2)
/* DF1970 80242AD0 00431025 */  or        $v0, $v0, $v1
/* DF1974 80242AD4 0C00EAFF */  jal       disable_npc_shadow
/* DF1978 80242AD8 AE420000 */   sw       $v0, ($s2)
/* DF197C 80242ADC 3C041F30 */  lui       $a0, 0x1f30
/* DF1980 80242AE0 8E420000 */  lw        $v0, ($s2)
/* DF1984 80242AE4 2403F7FF */  addiu     $v1, $zero, -0x801
/* DF1988 80242AE8 00431024 */  and       $v0, $v0, $v1
/* DF198C 80242AEC AE420000 */  sw        $v0, ($s2)
/* DF1990 80242AF0 8E620000 */  lw        $v0, ($s3)
/* DF1994 80242AF4 8E6300B0 */  lw        $v1, 0xb0($s3)
/* DF1998 80242AF8 34840040 */  ori       $a0, $a0, 0x40
/* DF199C 80242AFC AE60006C */  sw        $zero, 0x6c($s3)
/* DF19A0 80242B00 00441025 */  or        $v0, $v0, $a0
/* DF19A4 80242B04 AE620000 */  sw        $v0, ($s3)
/* DF19A8 80242B08 30620004 */  andi      $v0, $v1, 4
/* DF19AC 80242B0C 10400003 */  beqz      $v0, .L80242B1C
/* DF19B0 80242B10 2402FFFB */   addiu    $v0, $zero, -5
/* DF19B4 80242B14 00621024 */  and       $v0, $v1, $v0
/* DF19B8 80242B18 AE6200B0 */  sw        $v0, 0xb0($s3)
.L80242B1C:
/* DF19BC 80242B1C 8EE30070 */  lw        $v1, 0x70($s7)
/* DF19C0 80242B20 24100001 */  addiu     $s0, $zero, 1
/* DF19C4 80242B24 10700012 */  beq       $v1, $s0, .L80242B70
/* DF19C8 80242B28 28620002 */   slti     $v0, $v1, 2
/* DF19CC 80242B2C 10400005 */  beqz      $v0, .L80242B44
/* DF19D0 80242B30 24020002 */   addiu    $v0, $zero, 2
/* DF19D4 80242B34 10600007 */  beqz      $v1, .L80242B54
/* DF19D8 80242B38 0000102D */   daddu    $v0, $zero, $zero
/* DF19DC 80242B3C 08090BC6 */  j         .L80242F18
/* DF19E0 80242B40 00000000 */   nop
.L80242B44:
/* DF19E4 80242B44 1062005B */  beq       $v1, $v0, .L80242CB4
/* DF19E8 80242B48 0000102D */   daddu    $v0, $zero, $zero
/* DF19EC 80242B4C 08090BC6 */  j         .L80242F18
/* DF19F0 80242B50 00000000 */   nop
.L80242B54:
/* DF19F4 80242B54 8E420000 */  lw        $v0, ($s2)
/* DF19F8 80242B58 0240202D */  daddu     $a0, $s2, $zero
/* DF19FC 80242B5C 34420002 */  ori       $v0, $v0, 2
/* DF1A00 80242B60 0C00EAFF */  jal       disable_npc_shadow
/* DF1A04 80242B64 AE420000 */   sw       $v0, ($s2)
/* DF1A08 80242B68 AE60006C */  sw        $zero, 0x6c($s3)
/* DF1A0C 80242B6C AEF00070 */  sw        $s0, 0x70($s7)
.L80242B70:
/* DF1A10 80242B70 8E74006C */  lw        $s4, 0x6c($s3)
/* DF1A14 80242B74 24020001 */  addiu     $v0, $zero, 1
/* DF1A18 80242B78 168200E7 */  bne       $s4, $v0, .L80242F18
/* DF1A1C 80242B7C 0000102D */   daddu    $v0, $zero, $zero
/* DF1A20 80242B80 8E64007C */  lw        $a0, 0x7c($s3)
/* DF1A24 80242B84 24110002 */  addiu     $s1, $zero, 2
/* DF1A28 80242B88 0C00EABB */  jal       get_npc_unsafe
/* DF1A2C 80242B8C AE71006C */   sw       $s1, 0x6c($s3)
/* DF1A30 80242B90 0040802D */  daddu     $s0, $v0, $zero
/* DF1A34 80242B94 C6000038 */  lwc1      $f0, 0x38($s0)
/* DF1A38 80242B98 E6400038 */  swc1      $f0, 0x38($s2)
/* DF1A3C 80242B9C C6000040 */  lwc1      $f0, 0x40($s0)
/* DF1A40 80242BA0 E6400040 */  swc1      $f0, 0x40($s2)
/* DF1A44 80242BA4 C6020034 */  lwc1      $f2, 0x34($s0)
/* DF1A48 80242BA8 3C014387 */  lui       $at, 0x4387
/* DF1A4C 80242BAC 44810000 */  mtc1      $at, $f0
/* DF1A50 80242BB0 26440038 */  addiu     $a0, $s2, 0x38
/* DF1A54 80242BB4 46020001 */  sub.s     $f0, $f0, $f2
/* DF1A58 80242BB8 C6680078 */  lwc1      $f8, 0x78($s3)
/* DF1A5C 80242BBC 46804220 */  cvt.s.w   $f8, $f8
/* DF1A60 80242BC0 44064000 */  mfc1      $a2, $f8
/* DF1A64 80242BC4 44070000 */  mfc1      $a3, $f0
/* DF1A68 80242BC8 0C00A7E7 */  jal       add_vec2D_polar
/* DF1A6C 80242BCC 26450040 */   addiu    $a1, $s2, 0x40
/* DF1A70 80242BD0 C600003C */  lwc1      $f0, 0x3c($s0)
/* DF1A74 80242BD4 C6620074 */  lwc1      $f2, 0x74($s3)
/* DF1A78 80242BD8 468010A0 */  cvt.s.w   $f2, $f2
/* DF1A7C 80242BDC 46020000 */  add.s     $f0, $f0, $f2
/* DF1A80 80242BE0 E640003C */  swc1      $f0, 0x3c($s2)
/* DF1A84 80242BE4 A2740007 */  sb        $s4, 7($s3)
/* DF1A88 80242BE8 C6400038 */  lwc1      $f0, 0x38($s2)
/* DF1A8C 80242BEC 4600020D */  trunc.w.s $f8, $f0
/* DF1A90 80242BF0 44024000 */  mfc1      $v0, $f8
/* DF1A94 80242BF4 00000000 */  nop
/* DF1A98 80242BF8 A6620010 */  sh        $v0, 0x10($s3)
/* DF1A9C 80242BFC C640003C */  lwc1      $f0, 0x3c($s2)
/* DF1AA0 80242C00 4600020D */  trunc.w.s $f8, $f0
/* DF1AA4 80242C04 44024000 */  mfc1      $v0, $f8
/* DF1AA8 80242C08 00000000 */  nop
/* DF1AAC 80242C0C A6620012 */  sh        $v0, 0x12($s3)
/* DF1AB0 80242C10 C6400040 */  lwc1      $f0, 0x40($s2)
/* DF1AB4 80242C14 4600020D */  trunc.w.s $f8, $f0
/* DF1AB8 80242C18 44024000 */  mfc1      $v0, $f8
/* DF1ABC 80242C1C 00000000 */  nop
/* DF1AC0 80242C20 A6620014 */  sh        $v0, 0x14($s3)
/* DF1AC4 80242C24 AE400044 */  sw        $zero, 0x44($s2)
/* DF1AC8 80242C28 AE400048 */  sw        $zero, 0x48($s2)
/* DF1ACC 80242C2C AE40004C */  sw        $zero, 0x4c($s2)
/* DF1AD0 80242C30 C6A00000 */  lwc1      $f0, ($s5)
/* DF1AD4 80242C34 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DF1AD8 80242C38 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DF1ADC 80242C3C C64C0038 */  lwc1      $f12, 0x38($s2)
/* DF1AE0 80242C40 C64E0040 */  lwc1      $f14, 0x40($s2)
/* DF1AE4 80242C44 E6400018 */  swc1      $f0, 0x18($s2)
/* DF1AE8 80242C48 8C460028 */  lw        $a2, 0x28($v0)
/* DF1AEC 80242C4C 0C00A720 */  jal       atan2
/* DF1AF0 80242C50 8C470030 */   lw       $a3, 0x30($v0)
/* DF1AF4 80242C54 E640000C */  swc1      $f0, 0xc($s2)
/* DF1AF8 80242C58 C6A0000C */  lwc1      $f0, 0xc($s5)
/* DF1AFC 80242C5C 8E420000 */  lw        $v0, ($s2)
/* DF1B00 80242C60 0240202D */  daddu     $a0, $s2, $zero
/* DF1B04 80242C64 E640001C */  swc1      $f0, 0x1c($s2)
/* DF1B08 80242C68 C6A00010 */  lwc1      $f0, 0x10($s5)
/* DF1B0C 80242C6C 2403FFFD */  addiu     $v1, $zero, -3
/* DF1B10 80242C70 E6400014 */  swc1      $f0, 0x14($s2)
/* DF1B14 80242C74 C600003C */  lwc1      $f0, 0x3c($s0)
/* DF1B18 80242C78 00431024 */  and       $v0, $v0, $v1
/* DF1B1C 80242C7C AE420000 */  sw        $v0, ($s2)
/* DF1B20 80242C80 0C00EAE8 */  jal       enable_npc_shadow
/* DF1B24 80242C84 E6400064 */   swc1     $f0, 0x64($s2)
/* DF1B28 80242C88 8E420000 */  lw        $v0, ($s2)
/* DF1B2C 80242C8C 3C03E0FF */  lui       $v1, 0xe0ff
/* DF1B30 80242C90 34420800 */  ori       $v0, $v0, 0x800
/* DF1B34 80242C94 AE420000 */  sw        $v0, ($s2)
/* DF1B38 80242C98 8E620000 */  lw        $v0, ($s3)
/* DF1B3C 80242C9C 3463FFFF */  ori       $v1, $v1, 0xffff
/* DF1B40 80242CA0 00431024 */  and       $v0, $v0, $v1
/* DF1B44 80242CA4 AE620000 */  sw        $v0, ($s3)
/* DF1B48 80242CA8 2402005A */  addiu     $v0, $zero, 0x5a
/* DF1B4C 80242CAC A642008E */  sh        $v0, 0x8e($s2)
/* DF1B50 80242CB0 AEF10070 */  sw        $s1, 0x70($s7)
.L80242CB4:
/* DF1B54 80242CB4 0000202D */  daddu     $a0, $zero, $zero
/* DF1B58 80242CB8 27B00020 */  addiu     $s0, $sp, 0x20
/* DF1B5C 80242CBC 864200A8 */  lh        $v0, 0xa8($s2)
/* DF1B60 80242CC0 3C013FE0 */  lui       $at, 0x3fe0
/* DF1B64 80242CC4 44810800 */  mtc1      $at, $f1
/* DF1B68 80242CC8 44800000 */  mtc1      $zero, $f0
/* DF1B6C 80242CCC 44821000 */  mtc1      $v0, $f2
/* DF1B70 80242CD0 00000000 */  nop
/* DF1B74 80242CD4 468010A1 */  cvt.d.w   $f2, $f2
/* DF1B78 80242CD8 46201082 */  mul.d     $f2, $f2, $f0
/* DF1B7C 80242CDC 00000000 */  nop
/* DF1B80 80242CE0 0200282D */  daddu     $a1, $s0, $zero
/* DF1B84 80242CE4 C6440038 */  lwc1      $f4, 0x38($s2)
/* DF1B88 80242CE8 C640003C */  lwc1      $f0, 0x3c($s2)
/* DF1B8C 80242CEC 27B10024 */  addiu     $s1, $sp, 0x24
/* DF1B90 80242CF0 E7A40020 */  swc1      $f4, 0x20($sp)
/* DF1B94 80242CF4 C6440040 */  lwc1      $f4, 0x40($s2)
/* DF1B98 80242CF8 46000021 */  cvt.d.s   $f0, $f0
/* DF1B9C 80242CFC 46220000 */  add.d     $f0, $f0, $f2
/* DF1BA0 80242D00 E7A40028 */  swc1      $f4, 0x28($sp)
/* DF1BA4 80242D04 C6420018 */  lwc1      $f2, 0x18($s2)
/* DF1BA8 80242D08 46200020 */  cvt.s.d   $f0, $f0
/* DF1BAC 80242D0C E7A00024 */  swc1      $f0, 0x24($sp)
/* DF1BB0 80242D10 E7A20010 */  swc1      $f2, 0x10($sp)
/* DF1BB4 80242D14 C640000C */  lwc1      $f0, 0xc($s2)
/* DF1BB8 80242D18 0220302D */  daddu     $a2, $s1, $zero
/* DF1BBC 80242D1C E7A00014 */  swc1      $f0, 0x14($sp)
/* DF1BC0 80242D20 864200A6 */  lh        $v0, 0xa6($s2)
/* DF1BC4 80242D24 27B40028 */  addiu     $s4, $sp, 0x28
/* DF1BC8 80242D28 44820000 */  mtc1      $v0, $f0
/* DF1BCC 80242D2C 00000000 */  nop
/* DF1BD0 80242D30 46800020 */  cvt.s.w   $f0, $f0
/* DF1BD4 80242D34 E7A00018 */  swc1      $f0, 0x18($sp)
/* DF1BD8 80242D38 864200A8 */  lh        $v0, 0xa8($s2)
/* DF1BDC 80242D3C 0280382D */  daddu     $a3, $s4, $zero
/* DF1BE0 80242D40 44820000 */  mtc1      $v0, $f0
/* DF1BE4 80242D44 00000000 */  nop
/* DF1BE8 80242D48 46800020 */  cvt.s.w   $f0, $f0
/* DF1BEC 80242D4C 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* DF1BF0 80242D50 E7A0001C */   swc1     $f0, 0x1c($sp)
/* DF1BF4 80242D54 54400001 */  bnel      $v0, $zero, .L80242D5C
/* DF1BF8 80242D58 24160001 */   addiu    $s6, $zero, 1
.L80242D5C:
/* DF1BFC 80242D5C 0200282D */  daddu     $a1, $s0, $zero
/* DF1C00 80242D60 0220302D */  daddu     $a2, $s1, $zero
/* DF1C04 80242D64 C6400038 */  lwc1      $f0, 0x38($s2)
/* DF1C08 80242D68 C642003C */  lwc1      $f2, 0x3c($s2)
/* DF1C0C 80242D6C C6440040 */  lwc1      $f4, 0x40($s2)
/* DF1C10 80242D70 3C01447A */  lui       $at, 0x447a
/* DF1C14 80242D74 44813000 */  mtc1      $at, $f6
/* DF1C18 80242D78 27A2002C */  addiu     $v0, $sp, 0x2c
/* DF1C1C 80242D7C E7A00020 */  swc1      $f0, 0x20($sp)
/* DF1C20 80242D80 E7A20024 */  swc1      $f2, 0x24($sp)
/* DF1C24 80242D84 E7A40028 */  swc1      $f4, 0x28($sp)
/* DF1C28 80242D88 E7A6002C */  swc1      $f6, 0x2c($sp)
/* DF1C2C 80242D8C AFA20010 */  sw        $v0, 0x10($sp)
/* DF1C30 80242D90 8E440080 */  lw        $a0, 0x80($s2)
/* DF1C34 80242D94 0C0372DF */  jal       npc_raycast_down_sides
/* DF1C38 80242D98 0280382D */   daddu    $a3, $s4, $zero
/* DF1C3C 80242D9C 10400019 */  beqz      $v0, .L80242E04
/* DF1C40 80242DA0 00000000 */   nop
/* DF1C44 80242DA4 C640001C */  lwc1      $f0, 0x1c($s2)
/* DF1C48 80242DA8 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* DF1C4C 80242DAC 46000005 */  abs.s     $f0, $f0
/* DF1C50 80242DB0 4600103C */  c.lt.s    $f2, $f0
/* DF1C54 80242DB4 00000000 */  nop
/* DF1C58 80242DB8 45000012 */  bc1f      .L80242E04
/* DF1C5C 80242DBC 00000000 */   nop
/* DF1C60 80242DC0 C7A40024 */  lwc1      $f4, 0x24($sp)
/* DF1C64 80242DC4 C6400064 */  lwc1      $f0, 0x64($s2)
/* DF1C68 80242DC8 46002001 */  sub.s     $f0, $f4, $f0
/* DF1C6C 80242DCC 3C014034 */  lui       $at, 0x4034
/* DF1C70 80242DD0 44811800 */  mtc1      $at, $f3
/* DF1C74 80242DD4 44801000 */  mtc1      $zero, $f2
/* DF1C78 80242DD8 46000005 */  abs.s     $f0, $f0
/* DF1C7C 80242DDC 46000021 */  cvt.d.s   $f0, $f0
/* DF1C80 80242DE0 4622003C */  c.lt.d    $f0, $f2
/* DF1C84 80242DE4 00000000 */  nop
/* DF1C88 80242DE8 45000006 */  bc1f      .L80242E04
/* DF1C8C 80242DEC 0240202D */   daddu    $a0, $s2, $zero
/* DF1C90 80242DF0 8E450018 */  lw        $a1, 0x18($s2)
/* DF1C94 80242DF4 8E46000C */  lw        $a2, 0xc($s2)
/* DF1C98 80242DF8 2416000A */  addiu     $s6, $zero, 0xa
/* DF1C9C 80242DFC 0C00EA95 */  jal       npc_move_heading
/* DF1CA0 80242E00 E644003C */   swc1     $f4, 0x3c($s2)
.L80242E04:
/* DF1CA4 80242E04 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* DF1CA8 80242E08 3C013FF0 */  lui       $at, 0x3ff0
/* DF1CAC 80242E0C 44811800 */  mtc1      $at, $f3
/* DF1CB0 80242E10 44801000 */  mtc1      $zero, $f2
/* DF1CB4 80242E14 46000021 */  cvt.d.s   $f0, $f0
/* DF1CB8 80242E18 4622003C */  c.lt.d    $f0, $f2
/* DF1CBC 80242E1C 00000000 */  nop
/* DF1CC0 80242E20 45030001 */  bc1tl     .L80242E28
/* DF1CC4 80242E24 2416000B */   addiu    $s6, $zero, 0xb
.L80242E28:
/* DF1CC8 80242E28 9642008E */  lhu       $v0, 0x8e($s2)
/* DF1CCC 80242E2C 2442FFFF */  addiu     $v0, $v0, -1
/* DF1CD0 80242E30 A642008E */  sh        $v0, 0x8e($s2)
/* DF1CD4 80242E34 00021400 */  sll       $v0, $v0, 0x10
/* DF1CD8 80242E38 58400001 */  blezl     $v0, .L80242E40
/* DF1CDC 80242E3C 24160014 */   addiu    $s6, $zero, 0x14
.L80242E40:
/* DF1CE0 80242E40 56C00019 */  bnel      $s6, $zero, .L80242EA8
/* DF1CE4 80242E44 AFA00010 */   sw       $zero, 0x10($sp)
/* DF1CE8 80242E48 8E620070 */  lw        $v0, 0x70($s3)
/* DF1CEC 80242E4C 30420001 */  andi      $v0, $v0, 1
/* DF1CF0 80242E50 10400009 */  beqz      $v0, .L80242E78
/* DF1CF4 80242E54 00000000 */   nop
/* DF1CF8 80242E58 C640004C */  lwc1      $f0, 0x4c($s2)
/* DF1CFC 80242E5C 3C014044 */  lui       $at, 0x4044
/* DF1D00 80242E60 44811800 */  mtc1      $at, $f3
/* DF1D04 80242E64 44801000 */  mtc1      $zero, $f2
/* DF1D08 80242E68 46000021 */  cvt.d.s   $f0, $f0
/* DF1D0C 80242E6C 46220000 */  add.d     $f0, $f0, $f2
/* DF1D10 80242E70 46200020 */  cvt.s.d   $f0, $f0
/* DF1D14 80242E74 E640004C */  swc1      $f0, 0x4c($s2)
.L80242E78:
/* DF1D18 80242E78 8E450018 */  lw        $a1, 0x18($s2)
/* DF1D1C 80242E7C 8E46000C */  lw        $a2, 0xc($s2)
/* DF1D20 80242E80 0C00EA95 */  jal       npc_move_heading
/* DF1D24 80242E84 0240202D */   daddu    $a0, $s2, $zero
/* DF1D28 80242E88 C644003C */  lwc1      $f4, 0x3c($s2)
/* DF1D2C 80242E8C C640001C */  lwc1      $f0, 0x1c($s2)
/* DF1D30 80242E90 46002100 */  add.s     $f4, $f4, $f0
/* DF1D34 80242E94 C6420014 */  lwc1      $f2, 0x14($s2)
/* DF1D38 80242E98 46020001 */  sub.s     $f0, $f0, $f2
/* DF1D3C 80242E9C E644003C */  swc1      $f4, 0x3c($s2)
/* DF1D40 80242EA0 08090BC5 */  j         .L80242F14
/* DF1D44 80242EA4 E640001C */   swc1     $f0, 0x1c($s2)
.L80242EA8:
/* DF1D48 80242EA8 AFA00014 */  sw        $zero, 0x14($sp)
/* DF1D4C 80242EAC 8E450038 */  lw        $a1, 0x38($s2)
/* DF1D50 80242EB0 8E46003C */  lw        $a2, 0x3c($s2)
/* DF1D54 80242EB4 8E470040 */  lw        $a3, 0x40($s2)
/* DF1D58 80242EB8 0C01BECC */  jal       fx_walk
/* DF1D5C 80242EBC 24040002 */   addiu    $a0, $zero, 2
/* DF1D60 80242EC0 3C01C47A */  lui       $at, 0xc47a
/* DF1D64 80242EC4 44810000 */  mtc1      $at, $f0
/* DF1D68 80242EC8 AE60006C */  sw        $zero, 0x6c($s3)
/* DF1D6C 80242ECC 8E420000 */  lw        $v0, ($s2)
/* DF1D70 80242ED0 0240202D */  daddu     $a0, $s2, $zero
/* DF1D74 80242ED4 AE400038 */  sw        $zero, 0x38($s2)
/* DF1D78 80242ED8 AE400040 */  sw        $zero, 0x40($s2)
/* DF1D7C 80242EDC AE40001C */  sw        $zero, 0x1c($s2)
/* DF1D80 80242EE0 34420002 */  ori       $v0, $v0, 2
/* DF1D84 80242EE4 E640003C */  swc1      $f0, 0x3c($s2)
/* DF1D88 80242EE8 0C00EAFF */  jal       disable_npc_shadow
/* DF1D8C 80242EEC AE420000 */   sw       $v0, ($s2)
/* DF1D90 80242EF0 8E420000 */  lw        $v0, ($s2)
/* DF1D94 80242EF4 2403F7FF */  addiu     $v1, $zero, -0x801
/* DF1D98 80242EF8 00431024 */  and       $v0, $v0, $v1
/* DF1D9C 80242EFC AE420000 */  sw        $v0, ($s2)
/* DF1DA0 80242F00 8E620000 */  lw        $v0, ($s3)
/* DF1DA4 80242F04 3C031F00 */  lui       $v1, 0x1f00
/* DF1DA8 80242F08 00431025 */  or        $v0, $v0, $v1
/* DF1DAC 80242F0C AE620000 */  sw        $v0, ($s3)
/* DF1DB0 80242F10 AEE00070 */  sw        $zero, 0x70($s7)
.L80242F14:
/* DF1DB4 80242F14 0000102D */  daddu     $v0, $zero, $zero
.L80242F18:
/* DF1DB8 80242F18 8FBF0050 */  lw        $ra, 0x50($sp)
/* DF1DBC 80242F1C 8FB7004C */  lw        $s7, 0x4c($sp)
/* DF1DC0 80242F20 8FB60048 */  lw        $s6, 0x48($sp)
/* DF1DC4 80242F24 8FB50044 */  lw        $s5, 0x44($sp)
/* DF1DC8 80242F28 8FB40040 */  lw        $s4, 0x40($sp)
/* DF1DCC 80242F2C 8FB3003C */  lw        $s3, 0x3c($sp)
/* DF1DD0 80242F30 8FB20038 */  lw        $s2, 0x38($sp)
/* DF1DD4 80242F34 8FB10034 */  lw        $s1, 0x34($sp)
/* DF1DD8 80242F38 8FB00030 */  lw        $s0, 0x30($sp)
/* DF1DDC 80242F3C 03E00008 */  jr        $ra
/* DF1DE0 80242F40 27BD0058 */   addiu    $sp, $sp, 0x58
