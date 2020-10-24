.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241888_A17AA8
/* A17AA8 80241888 27BDFF88 */  addiu     $sp, $sp, -0x78
/* A17AAC 8024188C AFB3004C */  sw        $s3, 0x4c($sp)
/* A17AB0 80241890 0080982D */  daddu     $s3, $a0, $zero
/* A17AB4 80241894 AFBF0054 */  sw        $ra, 0x54($sp)
/* A17AB8 80241898 AFB40050 */  sw        $s4, 0x50($sp)
/* A17ABC 8024189C AFB20048 */  sw        $s2, 0x48($sp)
/* A17AC0 802418A0 AFB10044 */  sw        $s1, 0x44($sp)
/* A17AC4 802418A4 AFB00040 */  sw        $s0, 0x40($sp)
/* A17AC8 802418A8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* A17ACC 802418AC F7B80068 */  sdc1      $f24, 0x68($sp)
/* A17AD0 802418B0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* A17AD4 802418B4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* A17AD8 802418B8 8E710148 */  lw        $s1, 0x148($s3)
/* A17ADC 802418BC 00A0902D */  daddu     $s2, $a1, $zero
/* A17AE0 802418C0 86240008 */  lh        $a0, 8($s1)
/* A17AE4 802418C4 0C00EABB */  jal       get_npc_unsafe
/* A17AE8 802418C8 00C0A02D */   daddu    $s4, $a2, $zero
/* A17AEC 802418CC 0040802D */  daddu     $s0, $v0, $zero
/* A17AF0 802418D0 C6200078 */  lwc1      $f0, 0x78($s1)
/* A17AF4 802418D4 46800020 */  cvt.s.w   $f0, $f0
/* A17AF8 802418D8 46000021 */  cvt.d.s   $f0, $f0
/* A17AFC 802418DC 3C014059 */  lui       $at, 0x4059
/* A17B00 802418E0 44811800 */  mtc1      $at, $f3
/* A17B04 802418E4 44801000 */  mtc1      $zero, $f2
/* A17B08 802418E8 8602008E */  lh        $v0, 0x8e($s0)
/* A17B0C 802418EC 9603008E */  lhu       $v1, 0x8e($s0)
/* A17B10 802418F0 46220003 */  div.d     $f0, $f0, $f2
/* A17B14 802418F4 46200620 */  cvt.s.d   $f24, $f0
/* A17B18 802418F8 C6200088 */  lwc1      $f0, 0x88($s1)
/* A17B1C 802418FC 46800020 */  cvt.s.w   $f0, $f0
/* A17B20 80241900 46000021 */  cvt.d.s   $f0, $f0
/* A17B24 80241904 46220003 */  div.d     $f0, $f0, $f2
/* A17B28 80241908 46200020 */  cvt.s.d   $f0, $f0
/* A17B2C 8024190C 18400003 */  blez      $v0, .L8024191C
/* A17B30 80241910 4600C680 */   add.s    $f26, $f24, $f0
/* A17B34 80241914 2462FFFF */  addiu     $v0, $v1, -1
/* A17B38 80241918 A602008E */  sh        $v0, 0x8e($s0)
.L8024191C:
/* A17B3C 8024191C 8E220070 */  lw        $v0, 0x70($s1)
/* A17B40 80241920 18400034 */  blez      $v0, .L802419F4
/* A17B44 80241924 00000000 */   nop      
/* A17B48 80241928 C62C0074 */  lwc1      $f12, 0x74($s1)
/* A17B4C 8024192C 46806320 */  cvt.s.w   $f12, $f12
/* A17B50 80241930 44820000 */  mtc1      $v0, $f0
/* A17B54 80241934 00000000 */  nop       
/* A17B58 80241938 46800020 */  cvt.s.w   $f0, $f0
/* A17B5C 8024193C 46000021 */  cvt.d.s   $f0, $f0
/* A17B60 80241940 46220003 */  div.d     $f0, $f0, $f2
/* A17B64 80241944 0C00A8BB */  jal       sin_deg
/* A17B68 80241948 462005A0 */   cvt.s.d  $f22, $f0
/* A17B6C 8024194C 8E020000 */  lw        $v0, ($s0)
/* A17B70 80241950 30420008 */  andi      $v0, $v0, 8
/* A17B74 80241954 10400003 */  beqz      $v0, .L80241964
/* A17B78 80241958 46000506 */   mov.s    $f20, $f0
/* A17B7C 8024195C 08090669 */  j         .L802419A4
/* A17B80 80241960 0000102D */   daddu    $v0, $zero, $zero
.L80241964:
/* A17B84 80241964 27A50028 */  addiu     $a1, $sp, 0x28
/* A17B88 80241968 27A6002C */  addiu     $a2, $sp, 0x2c
/* A17B8C 8024196C C6000038 */  lwc1      $f0, 0x38($s0)
/* A17B90 80241970 C602003C */  lwc1      $f2, 0x3c($s0)
/* A17B94 80241974 C6040040 */  lwc1      $f4, 0x40($s0)
/* A17B98 80241978 3C01447A */  lui       $at, 0x447a
/* A17B9C 8024197C 44813000 */  mtc1      $at, $f6
/* A17BA0 80241980 27A20034 */  addiu     $v0, $sp, 0x34
/* A17BA4 80241984 E7A00028 */  swc1      $f0, 0x28($sp)
/* A17BA8 80241988 E7A2002C */  swc1      $f2, 0x2c($sp)
/* A17BAC 8024198C E7A40030 */  swc1      $f4, 0x30($sp)
/* A17BB0 80241990 E7A60034 */  swc1      $f6, 0x34($sp)
/* A17BB4 80241994 AFA20010 */  sw        $v0, 0x10($sp)
/* A17BB8 80241998 8E040080 */  lw        $a0, 0x80($s0)
/* A17BBC 8024199C 0C0372DF */  jal       func_800DCB7C
/* A17BC0 802419A0 27A70030 */   addiu    $a3, $sp, 0x30
.L802419A4:
/* A17BC4 802419A4 10400007 */  beqz      $v0, .L802419C4
/* A17BC8 802419A8 00000000 */   nop      
/* A17BCC 802419AC 4616A082 */  mul.s     $f2, $f20, $f22
/* A17BD0 802419B0 00000000 */  nop       
/* A17BD4 802419B4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A17BD8 802419B8 46180000 */  add.s     $f0, $f0, $f24
/* A17BDC 802419BC 08090674 */  j         .L802419D0
/* A17BE0 802419C0 46020000 */   add.s    $f0, $f0, $f2
.L802419C4:
/* A17BE4 802419C4 4616A002 */  mul.s     $f0, $f20, $f22
/* A17BE8 802419C8 00000000 */  nop       
/* A17BEC 802419CC 4600D000 */  add.s     $f0, $f26, $f0
.L802419D0:
/* A17BF0 802419D0 E600003C */  swc1      $f0, 0x3c($s0)
/* A17BF4 802419D4 8E220074 */  lw        $v0, 0x74($s1)
/* A17BF8 802419D8 2442000A */  addiu     $v0, $v0, 0xa
/* A17BFC 802419DC 44826000 */  mtc1      $v0, $f12
/* A17C00 802419E0 00000000 */  nop       
/* A17C04 802419E4 0C00A6C9 */  jal       clamp_angle
/* A17C08 802419E8 46806320 */   cvt.s.w  $f12, $f12
/* A17C0C 802419EC 4600020D */  trunc.w.s $f8, $f0
/* A17C10 802419F0 E6280074 */  swc1      $f8, 0x74($s1)
.L802419F4:
/* A17C14 802419F4 8E220090 */  lw        $v0, 0x90($s1)
/* A17C18 802419F8 1C400040 */  bgtz      $v0, .L80241AFC
/* A17C1C 802419FC 2442FFFF */   addiu    $v0, $v0, -1
/* A17C20 80241A00 860200A8 */  lh        $v0, 0xa8($s0)
/* A17C24 80241A04 C600003C */  lwc1      $f0, 0x3c($s0)
/* A17C28 80241A08 44821000 */  mtc1      $v0, $f2
/* A17C2C 80241A0C 00000000 */  nop       
/* A17C30 80241A10 468010A0 */  cvt.s.w   $f2, $f2
/* A17C34 80241A14 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A17C38 80241A18 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A17C3C 80241A1C 46020000 */  add.s     $f0, $f0, $f2
/* A17C40 80241A20 3C014024 */  lui       $at, 0x4024
/* A17C44 80241A24 44812800 */  mtc1      $at, $f5
/* A17C48 80241A28 44802000 */  mtc1      $zero, $f4
/* A17C4C 80241A2C C442002C */  lwc1      $f2, 0x2c($v0)
/* A17C50 80241A30 46000021 */  cvt.d.s   $f0, $f0
/* A17C54 80241A34 46240000 */  add.d     $f0, $f0, $f4
/* A17C58 80241A38 460010A1 */  cvt.d.s   $f2, $f2
/* A17C5C 80241A3C 4620103C */  c.lt.d    $f2, $f0
/* A17C60 80241A40 00000000 */  nop       
/* A17C64 80241A44 4500002E */  bc1f      .L80241B00
/* A17C68 80241A48 0280202D */   daddu    $a0, $s4, $zero
/* A17C6C 80241A4C 24020001 */  addiu     $v0, $zero, 1
/* A17C70 80241A50 AFA20010 */  sw        $v0, 0x10($sp)
/* A17C74 80241A54 8E460024 */  lw        $a2, 0x24($s2)
/* A17C78 80241A58 8E470028 */  lw        $a3, 0x28($s2)
/* A17C7C 80241A5C 0C01242D */  jal       func_800490B4
/* A17C80 80241A60 0220282D */   daddu    $a1, $s1, $zero
/* A17C84 80241A64 10400026 */  beqz      $v0, .L80241B00
/* A17C88 80241A68 0000202D */   daddu    $a0, $zero, $zero
/* A17C8C 80241A6C 0200282D */  daddu     $a1, $s0, $zero
/* A17C90 80241A70 0000302D */  daddu     $a2, $zero, $zero
/* A17C94 80241A74 2412000C */  addiu     $s2, $zero, 0xc
/* A17C98 80241A78 860300A8 */  lh        $v1, 0xa8($s0)
/* A17C9C 80241A7C 3C013F80 */  lui       $at, 0x3f80
/* A17CA0 80241A80 44810000 */  mtc1      $at, $f0
/* A17CA4 80241A84 3C014000 */  lui       $at, 0x4000
/* A17CA8 80241A88 44811000 */  mtc1      $at, $f2
/* A17CAC 80241A8C 3C01C1A0 */  lui       $at, 0xc1a0
/* A17CB0 80241A90 44812000 */  mtc1      $at, $f4
/* A17CB4 80241A94 44834000 */  mtc1      $v1, $f8
/* A17CB8 80241A98 00000000 */  nop       
/* A17CBC 80241A9C 46804220 */  cvt.s.w   $f8, $f8
/* A17CC0 80241AA0 44074000 */  mfc1      $a3, $f8
/* A17CC4 80241AA4 27A20038 */  addiu     $v0, $sp, 0x38
/* A17CC8 80241AA8 AFB2001C */  sw        $s2, 0x1c($sp)
/* A17CCC 80241AAC AFA20020 */  sw        $v0, 0x20($sp)
/* A17CD0 80241AB0 E7A00010 */  swc1      $f0, 0x10($sp)
/* A17CD4 80241AB4 E7A20014 */  swc1      $f2, 0x14($sp)
/* A17CD8 80241AB8 0C01BFA4 */  jal       fx_emote
/* A17CDC 80241ABC E7A40018 */   swc1     $f4, 0x18($sp)
/* A17CE0 80241AC0 0200202D */  daddu     $a0, $s0, $zero
/* A17CE4 80241AC4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* A17CE8 80241AC8 C480003C */  lwc1      $f0, 0x3c($a0)
/* A17CEC 80241ACC 3C060020 */  lui       $a2, 0x20
/* A17CF0 80241AD0 0C012530 */  jal       func_800494C0
/* A17CF4 80241AD4 E4800064 */   swc1     $f0, 0x64($a0)
/* A17CF8 80241AD8 8E220018 */  lw        $v0, 0x18($s1)
/* A17CFC 80241ADC 9442002A */  lhu       $v0, 0x2a($v0)
/* A17D00 80241AE0 30420001 */  andi      $v0, $v0, 1
/* A17D04 80241AE4 10400003 */  beqz      $v0, .L80241AF4
/* A17D08 80241AE8 2402000A */   addiu    $v0, $zero, 0xa
/* A17D0C 80241AEC 080906E7 */  j         .L80241B9C
/* A17D10 80241AF0 AE620070 */   sw       $v0, 0x70($s3)
.L80241AF4:
/* A17D14 80241AF4 080906E7 */  j         .L80241B9C
/* A17D18 80241AF8 AE720070 */   sw       $s2, 0x70($s3)
.L80241AFC:
/* A17D1C 80241AFC AE220090 */  sw        $v0, 0x90($s1)
.L80241B00:
/* A17D20 80241B00 8602008C */  lh        $v0, 0x8c($s0)
/* A17D24 80241B04 14400025 */  bnez      $v0, .L80241B9C
/* A17D28 80241B08 00000000 */   nop      
/* A17D2C 80241B0C 8602008E */  lh        $v0, 0x8e($s0)
/* A17D30 80241B10 1C400022 */  bgtz      $v0, .L80241B9C
/* A17D34 80241B14 00000000 */   nop      
/* A17D38 80241B18 8E620074 */  lw        $v0, 0x74($s3)
/* A17D3C 80241B1C 2442FFFF */  addiu     $v0, $v0, -1
/* A17D40 80241B20 1840001D */  blez      $v0, .L80241B98
/* A17D44 80241B24 AE620074 */   sw       $v0, 0x74($s3)
/* A17D48 80241B28 8E220018 */  lw        $v0, 0x18($s1)
/* A17D4C 80241B2C 9442002A */  lhu       $v0, 0x2a($v0)
/* A17D50 80241B30 30420010 */  andi      $v0, $v0, 0x10
/* A17D54 80241B34 14400007 */  bnez      $v0, .L80241B54
/* A17D58 80241B38 00000000 */   nop      
/* A17D5C 80241B3C C600000C */  lwc1      $f0, 0xc($s0)
/* A17D60 80241B40 3C014334 */  lui       $at, 0x4334
/* A17D64 80241B44 44816000 */  mtc1      $at, $f12
/* A17D68 80241B48 0C00A6C9 */  jal       clamp_angle
/* A17D6C 80241B4C 460C0300 */   add.s    $f12, $f0, $f12
/* A17D70 80241B50 E600000C */  swc1      $f0, 0xc($s0)
.L80241B54:
/* A17D74 80241B54 0C00A67F */  jal       rand_int
/* A17D78 80241B58 240403E8 */   addiu    $a0, $zero, 0x3e8
/* A17D7C 80241B5C 3C032E8B */  lui       $v1, 0x2e8b
/* A17D80 80241B60 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* A17D84 80241B64 00430018 */  mult      $v0, $v1
/* A17D88 80241B68 00021FC3 */  sra       $v1, $v0, 0x1f
/* A17D8C 80241B6C 00004010 */  mfhi      $t0
/* A17D90 80241B70 00082043 */  sra       $a0, $t0, 1
/* A17D94 80241B74 00832023 */  subu      $a0, $a0, $v1
/* A17D98 80241B78 00041840 */  sll       $v1, $a0, 1
/* A17D9C 80241B7C 00641821 */  addu      $v1, $v1, $a0
/* A17DA0 80241B80 00031880 */  sll       $v1, $v1, 2
/* A17DA4 80241B84 00641823 */  subu      $v1, $v1, $a0
/* A17DA8 80241B88 00431023 */  subu      $v0, $v0, $v1
/* A17DAC 80241B8C 24420005 */  addiu     $v0, $v0, 5
/* A17DB0 80241B90 080906E7 */  j         .L80241B9C
/* A17DB4 80241B94 A602008E */   sh       $v0, 0x8e($s0)
.L80241B98:
/* A17DB8 80241B98 AE600070 */  sw        $zero, 0x70($s3)
.L80241B9C:
/* A17DBC 80241B9C 8FBF0054 */  lw        $ra, 0x54($sp)
/* A17DC0 80241BA0 8FB40050 */  lw        $s4, 0x50($sp)
/* A17DC4 80241BA4 8FB3004C */  lw        $s3, 0x4c($sp)
/* A17DC8 80241BA8 8FB20048 */  lw        $s2, 0x48($sp)
/* A17DCC 80241BAC 8FB10044 */  lw        $s1, 0x44($sp)
/* A17DD0 80241BB0 8FB00040 */  lw        $s0, 0x40($sp)
/* A17DD4 80241BB4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* A17DD8 80241BB8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* A17DDC 80241BBC D7B60060 */  ldc1      $f22, 0x60($sp)
/* A17DE0 80241BC0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* A17DE4 80241BC4 03E00008 */  jr        $ra
/* A17DE8 80241BC8 27BD0078 */   addiu    $sp, $sp, 0x78
