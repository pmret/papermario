.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EB4_C42C64
/* C42C64 80242EB4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C42C68 80242EB8 AFB30024 */  sw        $s3, 0x24($sp)
/* C42C6C 80242EBC 0080982D */  daddu     $s3, $a0, $zero
/* C42C70 80242EC0 AFBF0028 */  sw        $ra, 0x28($sp)
/* C42C74 80242EC4 AFB20020 */  sw        $s2, 0x20($sp)
/* C42C78 80242EC8 AFB1001C */  sw        $s1, 0x1c($sp)
/* C42C7C 80242ECC AFB00018 */  sw        $s0, 0x18($sp)
/* C42C80 80242ED0 8E720148 */  lw        $s2, 0x148($s3)
/* C42C84 80242ED4 86440008 */  lh        $a0, 8($s2)
/* C42C88 80242ED8 0C00EABB */  jal       get_npc_unsafe
/* C42C8C 80242EDC 24100007 */   addiu    $s0, $zero, 7
/* C42C90 80242EE0 0040882D */  daddu     $s1, $v0, $zero
.L80242EE4:
/* C42C94 80242EE4 822200A4 */  lb        $v0, 0xa4($s1)
/* C42C98 80242EE8 52020007 */  beql      $s0, $v0, .L80242F08
/* C42C9C 80242EEC 26100001 */   addiu    $s0, $s0, 1
/* C42CA0 80242EF0 0C00FB3A */  jal       get_enemy
/* C42CA4 80242EF4 0200202D */   daddu    $a0, $s0, $zero
/* C42CA8 80242EF8 8C42006C */  lw        $v0, 0x6c($v0)
/* C42CAC 80242EFC 30420100 */  andi      $v0, $v0, 0x100
/* C42CB0 80242F00 1440001D */  bnez      $v0, .L80242F78
/* C42CB4 80242F04 26100001 */   addiu    $s0, $s0, 1
.L80242F08:
/* C42CB8 80242F08 2A020009 */  slti      $v0, $s0, 9
/* C42CBC 80242F0C 1440FFF5 */  bnez      $v0, .L80242EE4
/* C42CC0 80242F10 00000000 */   nop      
/* C42CC4 80242F14 8E42006C */  lw        $v0, 0x6c($s2)
/* C42CC8 80242F18 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* C42CCC 80242F1C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* C42CD0 80242F20 34420100 */  ori       $v0, $v0, 0x100
/* C42CD4 80242F24 AE42006C */  sw        $v0, 0x6c($s2)
/* C42CD8 80242F28 C4600028 */  lwc1      $f0, 0x28($v1)
/* C42CDC 80242F2C E6200038 */  swc1      $f0, 0x38($s1)
/* C42CE0 80242F30 C4600030 */  lwc1      $f0, 0x30($v1)
/* C42CE4 80242F34 E6200040 */  swc1      $f0, 0x40($s1)
/* C42CE8 80242F38 8E43006C */  lw        $v1, 0x6c($s2)
/* C42CEC 80242F3C 30621000 */  andi      $v0, $v1, 0x1000
/* C42CF0 80242F40 14400003 */  bnez      $v0, .L80242F50
/* C42CF4 80242F44 3C048000 */   lui      $a0, 0x8000
/* C42CF8 80242F48 34621000 */  ori       $v0, $v1, 0x1000
/* C42CFC 80242F4C AE42006C */  sw        $v0, 0x6c($s2)
.L80242F50:
/* C42D00 80242F50 C6200040 */  lwc1      $f0, 0x40($s1)
/* C42D04 80242F54 34840011 */  ori       $a0, $a0, 0x11
/* C42D08 80242F58 E7A00010 */  swc1      $f0, 0x10($sp)
/* C42D0C 80242F5C 8E260038 */  lw        $a2, 0x38($s1)
/* C42D10 80242F60 8E27003C */  lw        $a3, 0x3c($s1)
/* C42D14 80242F64 0C052757 */  jal       play_sound_at_position
/* C42D18 80242F68 24050002 */   addiu    $a1, $zero, 2
/* C42D1C 80242F6C 2402000F */  addiu     $v0, $zero, 0xf
/* C42D20 80242F70 A620008E */  sh        $zero, 0x8e($s1)
/* C42D24 80242F74 AE620070 */  sw        $v0, 0x70($s3)
.L80242F78:
/* C42D28 80242F78 8FBF0028 */  lw        $ra, 0x28($sp)
/* C42D2C 80242F7C 8FB30024 */  lw        $s3, 0x24($sp)
/* C42D30 80242F80 8FB20020 */  lw        $s2, 0x20($sp)
/* C42D34 80242F84 8FB1001C */  lw        $s1, 0x1c($sp)
/* C42D38 80242F88 8FB00018 */  lw        $s0, 0x18($sp)
/* C42D3C 80242F8C 03E00008 */  jr        $ra
/* C42D40 80242F90 27BD0030 */   addiu    $sp, $sp, 0x30
