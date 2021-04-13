.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DAC0
/* 38EC0 8005DAC0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 38EC4 8005DAC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 38EC8 8005DAC8 00A0802D */  daddu     $s0, $a1, $zero
/* 38ECC 8005DACC AFB10014 */  sw        $s1, 0x14($sp)
/* 38ED0 8005DAD0 00C0882D */  daddu     $s1, $a2, $zero
/* 38ED4 8005DAD4 AFB20018 */  sw        $s2, 0x18($sp)
/* 38ED8 8005DAD8 00E0902D */  daddu     $s2, $a3, $zero
/* 38EDC 8005DADC 3C038011 */  lui       $v1, %hi(D_8010F188)
/* 38EE0 8005DAE0 2463F188 */  addiu     $v1, $v1, %lo(D_8010F188)
/* 38EE4 8005DAE4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 38EE8 8005DAE8 8FB30038 */  lw        $s3, 0x38($sp)
/* 38EEC 8005DAEC 2402FFFF */  addiu     $v0, $zero, -1
/* 38EF0 8005DAF0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 38EF4 8005DAF4 AE000000 */  sw        $zero, ($s0)
/* 38EF8 8005DAF8 AE200000 */  sw        $zero, ($s1)
/* 38EFC 8005DAFC AE400000 */  sw        $zero, ($s2)
/* 38F00 8005DB00 1482000A */  bne       $a0, $v0, .L8005DB2C
/* 38F04 8005DB04 AE600000 */   sw       $zero, ($s3)
/* 38F08 8005DB08 C4600028 */  lwc1      $f0, 0x28($v1)
/* 38F0C 8005DB0C E6000000 */  swc1      $f0, ($s0)
/* 38F10 8005DB10 C460002C */  lwc1      $f0, 0x2c($v1)
/* 38F14 8005DB14 E6200000 */  swc1      $f0, ($s1)
/* 38F18 8005DB18 C4600030 */  lwc1      $f0, 0x30($v1)
/* 38F1C 8005DB1C E6400000 */  swc1      $f0, ($s2)
/* 38F20 8005DB20 8C620000 */  lw        $v0, ($v1)
/* 38F24 8005DB24 080176D5 */  j         .L8005DB54
/* 38F28 8005DB28 30420006 */   andi     $v0, $v0, 6
.L8005DB2C:
/* 38F2C 8005DB2C 0C00E9EB */  jal       func_8003A7AC
/* 38F30 8005DB30 00000000 */   nop
/* 38F34 8005DB34 C4400038 */  lwc1      $f0, 0x38($v0)
/* 38F38 8005DB38 E6000000 */  swc1      $f0, ($s0)
/* 38F3C 8005DB3C C440003C */  lwc1      $f0, 0x3c($v0)
/* 38F40 8005DB40 E6200000 */  swc1      $f0, ($s1)
/* 38F44 8005DB44 C4400040 */  lwc1      $f0, 0x40($v0)
/* 38F48 8005DB48 E6400000 */  swc1      $f0, ($s2)
/* 38F4C 8005DB4C 8C420000 */  lw        $v0, ($v0)
/* 38F50 8005DB50 30420800 */  andi      $v0, $v0, 0x800
.L8005DB54:
/* 38F54 8005DB54 10400002 */  beqz      $v0, .L8005DB60
/* 38F58 8005DB58 24020001 */   addiu    $v0, $zero, 1
/* 38F5C 8005DB5C AE620000 */  sw        $v0, ($s3)
.L8005DB60:
/* 38F60 8005DB60 8FBF0020 */  lw        $ra, 0x20($sp)
/* 38F64 8005DB64 8FB3001C */  lw        $s3, 0x1c($sp)
/* 38F68 8005DB68 8FB20018 */  lw        $s2, 0x18($sp)
/* 38F6C 8005DB6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 38F70 8005DB70 8FB00010 */  lw        $s0, 0x10($sp)
/* 38F74 8005DB74 03E00008 */  jr        $ra
/* 38F78 8005DB78 27BD0028 */   addiu    $sp, $sp, 0x28
