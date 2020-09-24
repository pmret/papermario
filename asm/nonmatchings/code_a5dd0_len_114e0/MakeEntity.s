.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel MakeEntity
/* A8438 80111D38 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A843C 80111D3C AFB20030 */  sw        $s2, 0x30($sp)
/* A8440 80111D40 0080902D */  daddu     $s2, $a0, $zero
/* A8444 80111D44 24020001 */  addiu     $v0, $zero, 1
/* A8448 80111D48 AFBF004C */  sw        $ra, 0x4c($sp)
/* A844C 80111D4C AFBE0048 */  sw        $fp, 0x48($sp)
/* A8450 80111D50 AFB70044 */  sw        $s7, 0x44($sp)
/* A8454 80111D54 AFB60040 */  sw        $s6, 0x40($sp)
/* A8458 80111D58 AFB5003C */  sw        $s5, 0x3c($sp)
/* A845C 80111D5C AFB40038 */  sw        $s4, 0x38($sp)
/* A8460 80111D60 AFB30034 */  sw        $s3, 0x34($sp)
/* A8464 80111D64 AFB1002C */  sw        $s1, 0x2c($sp)
/* A8468 80111D68 AFB00028 */  sw        $s0, 0x28($sp)
/* A846C 80111D6C 8E50000C */  lw        $s0, 0xc($s2)
/* A8470 80111D70 14A2003E */  bne       $a1, $v0, .L80111E6C
/* A8474 80111D74 24020002 */   addiu    $v0, $zero, 2
/* A8478 80111D78 8E050000 */  lw        $a1, ($s0)
/* A847C 80111D7C 26100004 */  addiu     $s0, $s0, 4
/* A8480 80111D80 0240202D */  daddu     $a0, $s2, $zero
/* A8484 80111D84 3C118016 */  lui       $s1, 0x8016
/* A8488 80111D88 2631C7D8 */  addiu     $s1, $s1, -0x3828
/* A848C 80111D8C 0C0B1EAF */  jal       get_variable
/* A8490 80111D90 3C148000 */   lui      $s4, 0x8000
/* A8494 80111D94 8E050000 */  lw        $a1, ($s0)
/* A8498 80111D98 26100004 */  addiu     $s0, $s0, 4
/* A849C 80111D9C 0240202D */  daddu     $a0, $s2, $zero
/* A84A0 80111DA0 0C0B1EAF */  jal       get_variable
/* A84A4 80111DA4 0040F02D */   daddu    $fp, $v0, $zero
/* A84A8 80111DA8 8E050000 */  lw        $a1, ($s0)
/* A84AC 80111DAC 26100004 */  addiu     $s0, $s0, 4
/* A84B0 80111DB0 0240202D */  daddu     $a0, $s2, $zero
/* A84B4 80111DB4 0C0B1EAF */  jal       get_variable
/* A84B8 80111DB8 0040B02D */   daddu    $s6, $v0, $zero
/* A84BC 80111DBC 8E050000 */  lw        $a1, ($s0)
/* A84C0 80111DC0 26100004 */  addiu     $s0, $s0, 4
/* A84C4 80111DC4 0240202D */  daddu     $a0, $s2, $zero
/* A84C8 80111DC8 0C0B1EAF */  jal       get_variable
/* A84CC 80111DCC 0040B82D */   daddu    $s7, $v0, $zero
/* A84D0 80111DD0 8E050000 */  lw        $a1, ($s0)
/* A84D4 80111DD4 26100004 */  addiu     $s0, $s0, 4
/* A84D8 80111DD8 0240202D */  daddu     $a0, $s2, $zero
/* A84DC 80111DDC 0C0B1EAF */  jal       get_variable
/* A84E0 80111DE0 0040A82D */   daddu    $s5, $v0, $zero
/* A84E4 80111DE4 0040982D */  daddu     $s3, $v0, $zero
/* A84E8 80111DE8 AE200000 */  sw        $zero, ($s1)
/* A84EC 80111DEC 2631FFFC */  addiu     $s1, $s1, -4
/* A84F0 80111DF0 AE200000 */  sw        $zero, ($s1)
/* A84F4 80111DF4 2631FFFC */  addiu     $s1, $s1, -4
/* A84F8 80111DF8 AE200000 */  sw        $zero, ($s1)
.L80111DFC:
/* A84FC 80111DFC 8E050000 */  lw        $a1, ($s0)
/* A8500 80111E00 26100004 */  addiu     $s0, $s0, 4
/* A8504 80111E04 0C0B1EAF */  jal       get_variable
/* A8508 80111E08 0240202D */   daddu    $a0, $s2, $zero
/* A850C 80111E0C 10540004 */  beq       $v0, $s4, .L80111E20
/* A8510 80111E10 03C0202D */   daddu    $a0, $fp, $zero
/* A8514 80111E14 AE220000 */  sw        $v0, ($s1)
/* A8518 80111E18 0804477F */  j         .L80111DFC
/* A851C 80111E1C 26310004 */   addiu    $s1, $s1, 4
.L80111E20:
/* A8520 80111E20 3C028016 */  lui       $v0, 0x8016
/* A8524 80111E24 2442C7D0 */  addiu     $v0, $v0, -0x3830
/* A8528 80111E28 02C0282D */  daddu     $a1, $s6, $zero
/* A852C 80111E2C 8C430000 */  lw        $v1, ($v0)
/* A8530 80111E30 8C460004 */  lw        $a2, 4($v0)
/* A8534 80111E34 8C420008 */  lw        $v0, 8($v0)
/* A8538 80111E38 02A0382D */  daddu     $a3, $s5, $zero
/* A853C 80111E3C AFB30010 */  sw        $s3, 0x10($sp)
/* A8540 80111E40 AFB40020 */  sw        $s4, 0x20($sp)
/* A8544 80111E44 AFA60018 */  sw        $a2, 0x18($sp)
/* A8548 80111E48 02E0302D */  daddu     $a2, $s7, $zero
/* A854C 80111E4C AFA30014 */  sw        $v1, 0x14($sp)
/* A8550 80111E50 0C044631 */  jal       create_entity
/* A8554 80111E54 AFA2001C */   sw       $v0, 0x1c($sp)
/* A8558 80111E58 0040182D */  daddu     $v1, $v0, $zero
/* A855C 80111E5C 24020002 */  addiu     $v0, $zero, 2
/* A8560 80111E60 3C018015 */  lui       $at, 0x8015
/* A8564 80111E64 AC2312EC */  sw        $v1, 0x12ec($at)
/* A8568 80111E68 AE430084 */  sw        $v1, 0x84($s2)
.L80111E6C:
/* A856C 80111E6C 8FBF004C */  lw        $ra, 0x4c($sp)
/* A8570 80111E70 8FBE0048 */  lw        $fp, 0x48($sp)
/* A8574 80111E74 8FB70044 */  lw        $s7, 0x44($sp)
/* A8578 80111E78 8FB60040 */  lw        $s6, 0x40($sp)
/* A857C 80111E7C 8FB5003C */  lw        $s5, 0x3c($sp)
/* A8580 80111E80 8FB40038 */  lw        $s4, 0x38($sp)
/* A8584 80111E84 8FB30034 */  lw        $s3, 0x34($sp)
/* A8588 80111E88 8FB20030 */  lw        $s2, 0x30($sp)
/* A858C 80111E8C 8FB1002C */  lw        $s1, 0x2c($sp)
/* A8590 80111E90 8FB00028 */  lw        $s0, 0x28($sp)
/* A8594 80111E94 03E00008 */  jr        $ra
/* A8598 80111E98 27BD0050 */   addiu    $sp, $sp, 0x50
