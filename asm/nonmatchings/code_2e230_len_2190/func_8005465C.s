.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005465C
/* 2FA5C 8005465C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 2FA60 80054660 AFB30024 */  sw        $s3, 0x24($sp)
/* 2FA64 80054664 0000982D */  daddu     $s3, $zero, $zero
/* 2FA68 80054668 3405FFFF */  ori       $a1, $zero, 0xffff
/* 2FA6C 8005466C AFB40028 */  sw        $s4, 0x28($sp)
/* 2FA70 80054670 3C1400FF */  lui       $s4, 0xff
/* 2FA74 80054674 AFB20020 */  sw        $s2, 0x20($sp)
/* 2FA78 80054678 3C12800A */  lui       $s2, %hi(D_8009A5C0)
/* 2FA7C 8005467C 8E52A5C0 */  lw        $s2, %lo(D_8009A5C0)($s2)
/* 2FA80 80054680 0285A025 */  or        $s4, $s4, $a1
/* 2FA84 80054684 AFB5002C */  sw        $s5, 0x2c($sp)
/* 2FA88 80054688 24150030 */  addiu     $s5, $zero, 0x30
/* 2FA8C 8005468C AFBF0030 */  sw        $ra, 0x30($sp)
/* 2FA90 80054690 AFB1001C */  sw        $s1, 0x1c($sp)
/* 2FA94 80054694 AFB00018 */  sw        $s0, 0x18($sp)
/* 2FA98 80054698 8E43002C */  lw        $v1, 0x2c($s2)
.L8005469C:
/* 2FA9C 8005469C 94620000 */  lhu       $v0, ($v1)
/* 2FAA0 800546A0 5045001F */  beql      $v0, $a1, .L80054720
/* 2FAA4 800546A4 0260102D */   daddu    $v0, $s3, $zero
/* 2FAA8 800546A8 5444FFFC */  bnel      $v0, $a0, .L8005469C
/* 2FAAC 800546AC 24630008 */   addiu    $v1, $v1, 8
/* 2FAB0 800546B0 0000802D */  daddu     $s0, $zero, $zero
/* 2FAB4 800546B4 0060882D */  daddu     $s1, $v1, $zero
.L800546B8:
/* 2FAB8 800546B8 96220002 */  lhu       $v0, 2($s1)
/* 2FABC 800546BC 50400014 */  beql      $v0, $zero, .L80054710
/* 2FAC0 800546C0 26310002 */   addiu    $s1, $s1, 2
/* 2FAC4 800546C4 8E440020 */  lw        $a0, 0x20($s2)
/* 2FAC8 800546C8 000210C0 */  sll       $v0, $v0, 3
/* 2FACC 800546CC 00822021 */  addu      $a0, $a0, $v0
/* 2FAD0 800546D0 8C820000 */  lw        $v0, ($a0)
/* 2FAD4 800546D4 8E43001C */  lw        $v1, 0x1c($s2)
/* 2FAD8 800546D8 00541024 */  and       $v0, $v0, $s4
/* 2FADC 800546DC 00431821 */  addu      $v1, $v0, $v1
/* 2FAE0 800546E0 AFA30010 */  sw        $v1, 0x10($sp)
/* 2FAE4 800546E4 8C820004 */  lw        $v0, 4($a0)
/* 2FAE8 800546E8 AFA20014 */  sw        $v0, 0x14($sp)
/* 2FAEC 800546EC 00021602 */  srl       $v0, $v0, 0x18
/* 2FAF0 800546F0 54550006 */  bnel      $v0, $s5, .L8005470C
/* 2FAF4 800546F4 24130066 */   addiu    $s3, $zero, 0x66
/* 2FAF8 800546F8 0060202D */  daddu     $a0, $v1, $zero
/* 2FAFC 800546FC 0C015313 */  jal       func_80054C4C
/* 2FB00 80054700 0200282D */   daddu    $a1, $s0, $zero
/* 2FB04 80054704 080151C4 */  j         .L80054710
/* 2FB08 80054708 26310002 */   addiu    $s1, $s1, 2
.L8005470C:
/* 2FB0C 8005470C 26310002 */  addiu     $s1, $s1, 2
.L80054710:
/* 2FB10 80054710 26100001 */  addiu     $s0, $s0, 1
/* 2FB14 80054714 2A020003 */  slti      $v0, $s0, 3
/* 2FB18 80054718 1440FFE7 */  bnez      $v0, .L800546B8
/* 2FB1C 8005471C 0260102D */   daddu    $v0, $s3, $zero
.L80054720:
/* 2FB20 80054720 8FBF0030 */  lw        $ra, 0x30($sp)
/* 2FB24 80054724 8FB5002C */  lw        $s5, 0x2c($sp)
/* 2FB28 80054728 8FB40028 */  lw        $s4, 0x28($sp)
/* 2FB2C 8005472C 8FB30024 */  lw        $s3, 0x24($sp)
/* 2FB30 80054730 8FB20020 */  lw        $s2, 0x20($sp)
/* 2FB34 80054734 8FB1001C */  lw        $s1, 0x1c($sp)
/* 2FB38 80054738 8FB00018 */  lw        $s0, 0x18($sp)
/* 2FB3C 8005473C 03E00008 */  jr        $ra
/* 2FB40 80054740 27BD0038 */   addiu    $sp, $sp, 0x38
