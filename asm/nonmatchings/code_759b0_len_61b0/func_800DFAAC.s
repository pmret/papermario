.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DFAAC
/* 78F5C 800DFAAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78F60 800DFAB0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 78F64 800DFAB4 0C037E80 */  jal       check_input_use_partner
/* 78F68 800DFAB8 AFB00010 */   sw       $s0, 0x10($sp)
/* 78F6C 800DFABC 0C03968B */  jal       func_800E5A2C
/* 78F70 800DFAC0 00000000 */   nop
/* 78F74 800DFAC4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 78F78 800DFAC8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 78F7C 800DFACC 8E030000 */  lw        $v1, ($s0)
/* 78F80 800DFAD0 30620008 */  andi      $v0, $v1, 8
/* 78F84 800DFAD4 14400008 */  bnez      $v0, .L800DFAF8
/* 78F88 800DFAD8 30620004 */   andi     $v0, $v1, 4
/* 78F8C 800DFADC 30620002 */  andi      $v0, $v1, 2
/* 78F90 800DFAE0 10400005 */  beqz      $v0, .L800DFAF8
/* 78F94 800DFAE4 30620004 */   andi     $v0, $v1, 4
/* 78F98 800DFAE8 0C038B46 */  jal       update_fall_state
/* 78F9C 800DFAEC 00000000 */   nop
/* 78FA0 800DFAF0 8E030000 */  lw        $v1, ($s0)
/* 78FA4 800DFAF4 30620004 */  andi      $v0, $v1, 4
.L800DFAF8:
/* 78FA8 800DFAF8 10400005 */  beqz      $v0, .L800DFB10
/* 78FAC 800DFAFC 30620008 */   andi     $v0, $v1, 8
/* 78FB0 800DFB00 14400003 */  bnez      $v0, .L800DFB10
/* 78FB4 800DFB04 00000000 */   nop
/* 78FB8 800DFB08 0C038C40 */  jal       func_800E3100
/* 78FBC 800DFB0C 00000000 */   nop
.L800DFB10:
/* 78FC0 800DFB10 0C0393F3 */  jal       check_input_midair_jump
/* 78FC4 800DFB14 00000000 */   nop
/* 78FC8 800DFB18 820300B4 */  lb        $v1, 0xb4($s0)
/* 78FCC 800DFB1C 24020011 */  addiu     $v0, $zero, 0x11
/* 78FD0 800DFB20 1062001A */  beq       $v1, $v0, .L800DFB8C
/* 78FD4 800DFB24 00000000 */   nop
/* 78FD8 800DFB28 0C038D8F */  jal       collision_main_lateral
/* 78FDC 800DFB2C 00000000 */   nop
/* 78FE0 800DFB30 0C039142 */  jal       func_800E4508
/* 78FE4 800DFB34 00000000 */   nop
/* 78FE8 800DFB38 0C0389F8 */  jal       collision_main_above
/* 78FEC 800DFB3C 00000000 */   nop
/* 78FF0 800DFB40 0441000A */  bgez      $v0, .L800DFB6C
/* 78FF4 800DFB44 00000000 */   nop
/* 78FF8 800DFB48 860200C0 */  lh        $v0, 0xc0($s0)
/* 78FFC 800DFB4C 14400007 */  bnez      $v0, .L800DFB6C
/* 79000 800DFB50 00000000 */   nop
/* 79004 800DFB54 8E020004 */  lw        $v0, 4($s0)
/* 79008 800DFB58 30421000 */  andi      $v0, $v0, 0x1000
/* 7900C 800DFB5C 10400003 */  beqz      $v0, .L800DFB6C
/* 79010 800DFB60 00000000 */   nop
/* 79014 800DFB64 0C0393C4 */  jal       func_800E4F10
/* 79018 800DFB68 00000000 */   nop
.L800DFB6C:
/* 7901C 800DFB6C 820300B4 */  lb        $v1, 0xb4($s0)
/* 79020 800DFB70 2402001B */  addiu     $v0, $zero, 0x1b
/* 79024 800DFB74 10620005 */  beq       $v1, $v0, .L800DFB8C
/* 79028 800DFB78 24020022 */   addiu    $v0, $zero, 0x22
/* 7902C 800DFB7C 10620003 */  beq       $v1, $v0, .L800DFB8C
/* 79030 800DFB80 00000000 */   nop
/* 79034 800DFB84 0C0391D1 */  jal       func_800E4744
/* 79038 800DFB88 00000000 */   nop
.L800DFB8C:
/* 7903C 800DFB8C 8E020004 */  lw        $v0, 4($s0)
/* 79040 800DFB90 30420002 */  andi      $v0, $v0, 2
/* 79044 800DFB94 10400003 */  beqz      $v0, .L800DFBA4
/* 79048 800DFB98 00000000 */   nop
/* 7904C 800DFB9C 0C0AF81C */  jal       func_802BE070
/* 79050 800DFBA0 00000000 */   nop
.L800DFBA4:
/* 79054 800DFBA4 8E020000 */  lw        $v0, ($s0)
/* 79058 800DFBA8 3C030400 */  lui       $v1, 0x400
/* 7905C 800DFBAC 00431024 */  and       $v0, $v0, $v1
/* 79060 800DFBB0 14400009 */  bnez      $v0, .L800DFBD8
/* 79064 800DFBB4 00000000 */   nop
/* 79068 800DFBB8 C6000028 */  lwc1      $f0, 0x28($s0)
/* 7906C 800DFBBC C602002C */  lwc1      $f2, 0x2c($s0)
/* 79070 800DFBC0 C6040030 */  lwc1      $f4, 0x30($s0)
/* 79074 800DFBC4 3C02800B */  lui       $v0, %hi(gCameras)
/* 79078 800DFBC8 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 7907C 800DFBCC E4400060 */  swc1      $f0, 0x60($v0)
/* 79080 800DFBD0 E4420064 */  swc1      $f2, 0x64($v0)
/* 79084 800DFBD4 E4440068 */  swc1      $f4, 0x68($v0)
.L800DFBD8:
/* 79088 800DFBD8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7908C 800DFBDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 79090 800DFBE0 03E00008 */  jr        $ra
/* 79094 800DFBE4 27BD0018 */   addiu    $sp, $sp, 0x18
