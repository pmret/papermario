.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel al_LoadPRG
/* 02F9B4 800545B4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 02F9B8 800545B8 AFB20028 */  sw    $s2, 0x28($sp)
/* 02F9BC 800545BC 0080902D */  daddu $s2, $a0, $zero
/* 02F9C0 800545C0 AFB00020 */  sw    $s0, 0x20($sp)
/* 02F9C4 800545C4 00A0802D */  daddu $s0, $a1, $zero
/* 02F9C8 800545C8 0200202D */  daddu $a0, $s0, $zero
/* 02F9CC 800545CC 27A50010 */  addiu $a1, $sp, 0x10
/* 02F9D0 800545D0 24060010 */  addiu $a2, $zero, 0x10
/* 02F9D4 800545D4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 02F9D8 800545D8 0C015380 */  jal   al_DmaCopy
/* 02F9DC 800545DC AFB10024 */   sw    $s1, 0x24($sp)
/* 02F9E0 800545E0 8FA20014 */  lw    $v0, 0x14($sp)
/* 02F9E4 800545E4 2451FFF0 */  addiu $s1, $v0, -0x10
/* 02F9E8 800545E8 2E220201 */  sltiu $v0, $s1, 0x201
/* 02F9EC 800545EC 14400002 */  bnez  $v0, .L800545F8
/* 02F9F0 800545F0 26040010 */   addiu $a0, $s0, 0x10
/* 02F9F4 800545F4 24110200 */  addiu $s1, $zero, 0x200
.L800545F8:
/* 02F9F8 800545F8 8E450058 */  lw    $a1, 0x58($s2)
/* 02F9FC 800545FC 0C015380 */  jal   al_DmaCopy
/* 02FA00 80054600 0220302D */   daddu $a2, $s1, $zero
/* 02FA04 80054604 001118C2 */  srl   $v1, $s1, 3
/* 02FA08 80054608 24020040 */  addiu $v0, $zero, 0x40
/* 02FA0C 8005460C 00438823 */  subu  $s1, $v0, $v1
/* 02FA10 80054610 1A20000C */  blez  $s1, .L80054644
/* 02FA14 80054614 26440014 */   addiu $a0, $s2, 0x14
/* 02FA18 80054618 24060008 */  addiu $a2, $zero, 8
/* 02FA1C 8005461C 8E500058 */  lw    $s0, 0x58($s2)
/* 02FA20 80054620 000310C0 */  sll   $v0, $v1, 3
/* 02FA24 80054624 02028021 */  addu  $s0, $s0, $v0
/* 02FA28 80054628 0C0153DD */  jal   al_CopyWords
/* 02FA2C 8005462C 0200282D */   daddu $a1, $s0, $zero
/* 02FA30 80054630 0200202D */  daddu $a0, $s0, $zero
/* 02FA34 80054634 24850008 */  addiu $a1, $a0, 8
/* 02FA38 80054638 001130C0 */  sll   $a2, $s1, 3
/* 02FA3C 8005463C 0C0153DD */  jal   al_CopyWords
/* 02FA40 80054640 24C6FFF8 */   addiu $a2, $a2, -8
.L80054644:
/* 02FA44 80054644 8FBF002C */  lw    $ra, 0x2c($sp)
/* 02FA48 80054648 8FB20028 */  lw    $s2, 0x28($sp)
/* 02FA4C 8005464C 8FB10024 */  lw    $s1, 0x24($sp)
/* 02FA50 80054650 8FB00020 */  lw    $s0, 0x20($sp)
/* 02FA54 80054654 03E00008 */  jr    $ra
/* 02FA58 80054658 27BD0030 */   addiu $sp, $sp, 0x30

/* 02FA5C 8005465C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 02FA60 80054660 AFB30024 */  sw    $s3, 0x24($sp)
/* 02FA64 80054664 0000982D */  daddu $s3, $zero, $zero
/* 02FA68 80054668 3405FFFF */  ori   $a1, $zero, 0xffff
/* 02FA6C 8005466C AFB40028 */  sw    $s4, 0x28($sp)
/* 02FA70 80054670 3C1400FF */  lui   $s4, 0xff
/* 02FA74 80054674 AFB20020 */  sw    $s2, 0x20($sp)
/* 02FA78 80054678 3C12800A */  lui   $s2, 0x800a
/* 02FA7C 8005467C 8E52A5C0 */  lw    $s2, -0x5a40($s2)
/* 02FA80 80054680 0285A025 */  or    $s4, $s4, $a1
/* 02FA84 80054684 AFB5002C */  sw    $s5, 0x2c($sp)
/* 02FA88 80054688 24150030 */  addiu $s5, $zero, 0x30
/* 02FA8C 8005468C AFBF0030 */  sw    $ra, 0x30($sp)
/* 02FA90 80054690 AFB1001C */  sw    $s1, 0x1c($sp)
/* 02FA94 80054694 AFB00018 */  sw    $s0, 0x18($sp)
/* 02FA98 80054698 8E43002C */  lw    $v1, 0x2c($s2)
.L8005469C:
/* 02FA9C 8005469C 94620000 */  lhu   $v0, ($v1)
/* 02FAA0 800546A0 5045001F */  beql  $v0, $a1, .L80054720
/* 02FAA4 800546A4 0260102D */   daddu $v0, $s3, $zero
/* 02FAA8 800546A8 5444FFFC */  bnel  $v0, $a0, .L8005469C
/* 02FAAC 800546AC 24630008 */   addiu $v1, $v1, 8
/* 02FAB0 800546B0 0000802D */  daddu $s0, $zero, $zero
/* 02FAB4 800546B4 0060882D */  daddu $s1, $v1, $zero
.L800546B8:
/* 02FAB8 800546B8 96220002 */  lhu   $v0, 2($s1)
/* 02FABC 800546BC 50400014 */  beql  $v0, $zero, .L80054710
/* 02FAC0 800546C0 26310002 */   addiu $s1, $s1, 2
/* 02FAC4 800546C4 8E440020 */  lw    $a0, 0x20($s2)
/* 02FAC8 800546C8 000210C0 */  sll   $v0, $v0, 3
/* 02FACC 800546CC 00822021 */  addu  $a0, $a0, $v0
/* 02FAD0 800546D0 8C820000 */  lw    $v0, ($a0)
/* 02FAD4 800546D4 8E43001C */  lw    $v1, 0x1c($s2)
/* 02FAD8 800546D8 00541024 */  and   $v0, $v0, $s4
/* 02FADC 800546DC 00431821 */  addu  $v1, $v0, $v1
/* 02FAE0 800546E0 AFA30010 */  sw    $v1, 0x10($sp)
/* 02FAE4 800546E4 8C820004 */  lw    $v0, 4($a0)
/* 02FAE8 800546E8 AFA20014 */  sw    $v0, 0x14($sp)
/* 02FAEC 800546EC 00021602 */  srl   $v0, $v0, 0x18
/* 02FAF0 800546F0 54550006 */  bnel  $v0, $s5, .L8005470C
/* 02FAF4 800546F4 24130066 */   addiu $s3, $zero, 0x66
/* 02FAF8 800546F8 0060202D */  daddu $a0, $v1, $zero
/* 02FAFC 800546FC 0C015313 */  jal   func_80054C4C
/* 02FB00 80054700 0200282D */   daddu $a1, $s0, $zero
/* 02FB04 80054704 080151C4 */  j     .L80054710
/* 02FB08 80054708 26310002 */   addiu $s1, $s1, 2

.L8005470C:
/* 02FB0C 8005470C 26310002 */  addiu $s1, $s1, 2
.L80054710:
/* 02FB10 80054710 26100001 */  addiu $s0, $s0, 1
/* 02FB14 80054714 2A020003 */  slti  $v0, $s0, 3
/* 02FB18 80054718 1440FFE7 */  bnez  $v0, .L800546B8
/* 02FB1C 8005471C 0260102D */   daddu $v0, $s3, $zero
.L80054720:
/* 02FB20 80054720 8FBF0030 */  lw    $ra, 0x30($sp)
/* 02FB24 80054724 8FB5002C */  lw    $s5, 0x2c($sp)
/* 02FB28 80054728 8FB40028 */  lw    $s4, 0x28($sp)
/* 02FB2C 8005472C 8FB30024 */  lw    $s3, 0x24($sp)
/* 02FB30 80054730 8FB20020 */  lw    $s2, 0x20($sp)
/* 02FB34 80054734 8FB1001C */  lw    $s1, 0x1c($sp)
/* 02FB38 80054738 8FB00018 */  lw    $s0, 0x18($sp)
/* 02FB3C 8005473C 03E00008 */  jr    $ra
/* 02FB40 80054740 27BD0038 */   addiu $sp, $sp, 0x38

