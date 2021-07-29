.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802465A0_B6C050
.word L80240A10_B664C0, L80240A28_B664D8, L80240A48_B664F8, L80240A60_B66510, L80240A9C_B6654C, L80240AE8_B66598

.section .text

glabel func_80240990_B66440
/* B66440 80240990 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B66444 80240994 AFB20028 */  sw        $s2, 0x28($sp)
/* B66448 80240998 0080902D */  daddu     $s2, $a0, $zero
/* B6644C 8024099C AFBF002C */  sw        $ra, 0x2c($sp)
/* B66450 802409A0 AFB10024 */  sw        $s1, 0x24($sp)
/* B66454 802409A4 AFB00020 */  sw        $s0, 0x20($sp)
/* B66458 802409A8 8E500148 */  lw        $s0, 0x148($s2)
/* B6645C 802409AC 0C00EABB */  jal       get_npc_unsafe
/* B66460 802409B0 86040008 */   lh       $a0, 8($s0)
/* B66464 802409B4 8E03006C */  lw        $v1, 0x6c($s0)
/* B66468 802409B8 1460000B */  bnez      $v1, .L802409E8
/* B6646C 802409BC 0040882D */   daddu    $s1, $v0, $zero
/* B66470 802409C0 0C00A67F */  jal       rand_int
/* B66474 802409C4 24040064 */   addiu    $a0, $zero, 0x64
/* B66478 802409C8 28420032 */  slti      $v0, $v0, 0x32
/* B6647C 802409CC 14400002 */  bnez      $v0, .L802409D8
/* B66480 802409D0 24020001 */   addiu    $v0, $zero, 1
/* B66484 802409D4 24020003 */  addiu     $v0, $zero, 3
.L802409D8:
/* B66488 802409D8 AE02006C */  sw        $v0, 0x6c($s0)
/* B6648C 802409DC 3C054387 */  lui       $a1, 0x4387
/* B66490 802409E0 0C00ECD0 */  jal       set_npc_yaw
/* B66494 802409E4 0220202D */   daddu    $a0, $s1, $zero
.L802409E8:
/* B66498 802409E8 8E02006C */  lw        $v0, 0x6c($s0)
/* B6649C 802409EC 2443FFFF */  addiu     $v1, $v0, -1
/* B664A0 802409F0 2C620006 */  sltiu     $v0, $v1, 6
/* B664A4 802409F4 1040004D */  beqz      $v0, .L80240B2C
/* B664A8 802409F8 00031080 */   sll      $v0, $v1, 2
/* B664AC 802409FC 3C018024 */  lui       $at, %hi(jtbl_802465A0_B6C050)
/* B664B0 80240A00 00220821 */  addu      $at, $at, $v0
/* B664B4 80240A04 8C2265A0 */  lw        $v0, %lo(jtbl_802465A0_B6C050)($at)
/* B664B8 80240A08 00400008 */  jr        $v0
/* B664BC 80240A0C 00000000 */   nop
glabel L80240A10_B664C0
/* B664C0 80240A10 3C030042 */  lui       $v1, 0x42
/* B664C4 80240A14 3463000F */  ori       $v1, $v1, 0xf
/* B664C8 80240A18 24020002 */  addiu     $v0, $zero, 2
/* B664CC 80240A1C AE02006C */  sw        $v0, 0x6c($s0)
/* B664D0 80240A20 AE000070 */  sw        $zero, 0x70($s0)
/* B664D4 80240A24 AE230028 */  sw        $v1, 0x28($s1)
glabel L80240A28_B664D8
/* B664D8 80240A28 8E020070 */  lw        $v0, 0x70($s0)
/* B664DC 80240A2C 24420001 */  addiu     $v0, $v0, 1
/* B664E0 80240A30 AE020070 */  sw        $v0, 0x70($s0)
/* B664E4 80240A34 28420033 */  slti      $v0, $v0, 0x33
/* B664E8 80240A38 1440003C */  bnez      $v0, .L80240B2C
/* B664EC 80240A3C 24020005 */   addiu    $v0, $zero, 5
/* B664F0 80240A40 080902CB */  j         .L80240B2C
/* B664F4 80240A44 AE02006C */   sw       $v0, 0x6c($s0)
glabel L80240A48_B664F8
/* B664F8 80240A48 3C030042 */  lui       $v1, 0x42
/* B664FC 80240A4C 34630010 */  ori       $v1, $v1, 0x10
/* B66500 80240A50 24020004 */  addiu     $v0, $zero, 4
/* B66504 80240A54 AE02006C */  sw        $v0, 0x6c($s0)
/* B66508 80240A58 AE000070 */  sw        $zero, 0x70($s0)
/* B6650C 80240A5C AE230028 */  sw        $v1, 0x28($s1)
glabel L80240A60_B66510
/* B66510 80240A60 8E020070 */  lw        $v0, 0x70($s0)
/* B66514 80240A64 24030019 */  addiu     $v1, $zero, 0x19
/* B66518 80240A68 24420001 */  addiu     $v0, $v0, 1
/* B6651C 80240A6C 14430005 */  bne       $v0, $v1, .L80240A84
/* B66520 80240A70 AE020070 */   sw       $v0, 0x70($s0)
/* B66524 80240A74 3C0142B4 */  lui       $at, 0x42b4
/* B66528 80240A78 44810000 */  mtc1      $at, $f0
/* B6652C 80240A7C 00000000 */  nop
/* B66530 80240A80 E620000C */  swc1      $f0, 0xc($s1)
.L80240A84:
/* B66534 80240A84 8E020070 */  lw        $v0, 0x70($s0)
/* B66538 80240A88 2842003D */  slti      $v0, $v0, 0x3d
/* B6653C 80240A8C 14400027 */  bnez      $v0, .L80240B2C
/* B66540 80240A90 24020005 */   addiu    $v0, $zero, 5
/* B66544 80240A94 080902CB */  j         .L80240B2C
/* B66548 80240A98 AE02006C */   sw       $v0, 0x6c($s0)
glabel L80240A9C_B6654C
/* B6654C 80240A9C 3C030042 */  lui       $v1, 0x42
/* B66550 80240AA0 24020006 */  addiu     $v0, $zero, 6
/* B66554 80240AA4 34630003 */  ori       $v1, $v1, 3
/* B66558 80240AA8 AE02006C */  sw        $v0, 0x6c($s0)
/* B6655C 80240AAC AE000070 */  sw        $zero, 0x70($s0)
/* B66560 80240AB0 862400A8 */  lh        $a0, 0xa8($s1)
/* B66564 80240AB4 2402000A */  addiu     $v0, $zero, 0xa
/* B66568 80240AB8 AE230028 */  sw        $v1, 0x28($s1)
/* B6656C 80240ABC AFA00014 */  sw        $zero, 0x14($sp)
/* B66570 80240AC0 AFA20018 */  sw        $v0, 0x18($sp)
/* B66574 80240AC4 44840000 */  mtc1      $a0, $f0
/* B66578 80240AC8 00000000 */  nop
/* B6657C 80240ACC 46800020 */  cvt.s.w   $f0, $f0
/* B66580 80240AD0 E7A00010 */  swc1      $f0, 0x10($sp)
/* B66584 80240AD4 8E250038 */  lw        $a1, 0x38($s1)
/* B66588 80240AD8 8E26003C */  lw        $a2, 0x3c($s1)
/* B6658C 80240ADC 8E270040 */  lw        $a3, 0x40($s1)
/* B66590 80240AE0 0C01C1E4 */  jal       fx_sweat
/* B66594 80240AE4 0000202D */   daddu    $a0, $zero, $zero
glabel L80240AE8_B66598
/* B66598 80240AE8 8E020070 */  lw        $v0, 0x70($s0)
/* B6659C 80240AEC 24420001 */  addiu     $v0, $v0, 1
/* B665A0 80240AF0 AE020070 */  sw        $v0, 0x70($s0)
/* B665A4 80240AF4 2842000B */  slti      $v0, $v0, 0xb
/* B665A8 80240AF8 1440000C */  bnez      $v0, .L80240B2C
/* B665AC 80240AFC 00000000 */   nop
/* B665B0 80240B00 0C00A67F */  jal       rand_int
/* B665B4 80240B04 24040064 */   addiu    $a0, $zero, 0x64
/* B665B8 80240B08 0040182D */  daddu     $v1, $v0, $zero
/* B665BC 80240B0C 2862005A */  slti      $v0, $v1, 0x5a
/* B665C0 80240B10 14400005 */  bnez      $v0, .L80240B28
/* B665C4 80240B14 24020007 */   addiu    $v0, $zero, 7
/* B665C8 80240B18 2862005F */  slti      $v0, $v1, 0x5f
/* B665CC 80240B1C 14400002 */  bnez      $v0, .L80240B28
/* B665D0 80240B20 24020001 */   addiu    $v0, $zero, 1
/* B665D4 80240B24 24020003 */  addiu     $v0, $zero, 3
.L80240B28:
/* B665D8 80240B28 AE02006C */  sw        $v0, 0x6c($s0)
.L80240B2C:
/* B665DC 80240B2C 8E03006C */  lw        $v1, 0x6c($s0)
/* B665E0 80240B30 24020007 */  addiu     $v0, $zero, 7
/* B665E4 80240B34 50620001 */  beql      $v1, $v0, .L80240B3C
/* B665E8 80240B38 AE400070 */   sw       $zero, 0x70($s2)
.L80240B3C:
/* B665EC 80240B3C 8FBF002C */  lw        $ra, 0x2c($sp)
/* B665F0 80240B40 8FB20028 */  lw        $s2, 0x28($sp)
/* B665F4 80240B44 8FB10024 */  lw        $s1, 0x24($sp)
/* B665F8 80240B48 8FB00020 */  lw        $s0, 0x20($sp)
/* B665FC 80240B4C 03E00008 */  jr        $ra
/* B66600 80240B50 27BD0030 */   addiu    $sp, $sp, 0x30
