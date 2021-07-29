.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80150BC0
.word 0x80131E38, 0x80131E44, 0x80131EC4, 0x80131E98, 0x80131EA4, 0x00000000

.section .text

glabel item_entity_update
/* C84D4 80131DD4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C84D8 80131DD8 AFB20018 */  sw        $s2, 0x18($sp)
/* C84DC 80131DDC 0080902D */  daddu     $s2, $a0, $zero
/* C84E0 80131DE0 AFBF0020 */  sw        $ra, 0x20($sp)
/* C84E4 80131DE4 AFB3001C */  sw        $s3, 0x1c($sp)
/* C84E8 80131DE8 AFB10014 */  sw        $s1, 0x14($sp)
/* C84EC 80131DEC AFB00010 */  sw        $s0, 0x10($sp)
/* C84F0 80131DF0 9242002E */  lbu       $v0, 0x2e($s2)
/* C84F4 80131DF4 2442FFFF */  addiu     $v0, $v0, -1
/* C84F8 80131DF8 A242002E */  sb        $v0, 0x2e($s2)
/* C84FC 80131DFC 304200FF */  andi      $v0, $v0, 0xff
/* C8500 80131E00 14400033 */  bnez      $v0, .L80131ED0
/* C8504 80131E04 00000000 */   nop
/* C8508 80131E08 3C138015 */  lui       $s3, %hi(D_80150BC0)
/* C850C 80131E0C 26730BC0 */  addiu     $s3, $s3, %lo(D_80150BC0)
.L80131E10:
/* C8510 80131E10 8E510024 */  lw        $s1, 0x24($s2)
/* C8514 80131E14 8E230000 */  lw        $v1, ($s1)
/* C8518 80131E18 2C620005 */  sltiu     $v0, $v1, 5
/* C851C 80131E1C 1040FFFC */  beqz      $v0, .L80131E10
/* C8520 80131E20 26310004 */   addiu    $s1, $s1, 4
/* C8524 80131E24 00031080 */  sll       $v0, $v1, 2
/* C8528 80131E28 00531021 */  addu      $v0, $v0, $s3
/* C852C 80131E2C 8C420000 */  lw        $v0, ($v0)
/* C8530 80131E30 00400008 */  jr        $v0
/* C8534 80131E34 00000000 */   nop
/* C8538 80131E38 2402003C */  addiu     $v0, $zero, 0x3c
/* C853C 80131E3C 0804C7B4 */  j         .L80131ED0
/* C8540 80131E40 A242002E */   sb       $v0, 0x2e($s2)
/* C8544 80131E44 92220003 */  lbu       $v0, 3($s1)
/* C8548 80131E48 A242002E */  sb        $v0, 0x2e($s2)
/* C854C 80131E4C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C8550 80131E50 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C8554 80131E54 80420070 */  lb        $v0, 0x70($v0)
/* C8558 80131E58 14400007 */  bnez      $v0, .L80131E78
/* C855C 80131E5C 2631000C */   addiu    $s1, $s1, 0xc
/* C8560 80131E60 92220003 */  lbu       $v0, 3($s1)
/* C8564 80131E64 26310004 */  addiu     $s1, $s1, 4
/* C8568 80131E68 A242002C */  sb        $v0, 0x2c($s2)
/* C856C 80131E6C 92220003 */  lbu       $v0, 3($s1)
/* C8570 80131E70 0804C7A3 */  j         .L80131E8C
/* C8574 80131E74 26310004 */   addiu    $s1, $s1, 4
.L80131E78:
/* C8578 80131E78 86220000 */  lh        $v0, ($s1)
/* C857C 80131E7C 26310004 */  addiu     $s1, $s1, 4
/* C8580 80131E80 A242002C */  sb        $v0, 0x2c($s2)
/* C8584 80131E84 86220000 */  lh        $v0, ($s1)
/* C8588 80131E88 26310004 */  addiu     $s1, $s1, 4
.L80131E8C:
/* C858C 80131E8C A242002D */  sb        $v0, 0x2d($s2)
/* C8590 80131E90 0804C7B4 */  j         .L80131ED0
/* C8594 80131E94 AE510024 */   sw       $s1, 0x24($s2)
/* C8598 80131E98 AE510028 */  sw        $s1, 0x28($s2)
/* C859C 80131E9C 0804C784 */  j         .L80131E10
/* C85A0 80131EA0 AE510024 */   sw       $s1, 0x24($s2)
/* C85A4 80131EA4 8E240000 */  lw        $a0, ($s1)
/* C85A8 80131EA8 26310004 */  addiu     $s1, $s1, 4
/* C85AC 80131EAC 8E300000 */  lw        $s0, ($s1)
/* C85B0 80131EB0 0C00A67F */  jal       rand_int
/* C85B4 80131EB4 26310004 */   addiu    $s1, $s1, 4
/* C85B8 80131EB8 0050102A */  slt       $v0, $v0, $s0
/* C85BC 80131EBC 5040FFD4 */  beql      $v0, $zero, .L80131E10
/* C85C0 80131EC0 AE510024 */   sw       $s1, 0x24($s2)
/* C85C4 80131EC4 8E420028 */  lw        $v0, 0x28($s2)
/* C85C8 80131EC8 0804C784 */  j         .L80131E10
/* C85CC 80131ECC AE420024 */   sw       $v0, 0x24($s2)
.L80131ED0:
/* C85D0 80131ED0 8FBF0020 */  lw        $ra, 0x20($sp)
/* C85D4 80131ED4 8FB3001C */  lw        $s3, 0x1c($sp)
/* C85D8 80131ED8 8FB20018 */  lw        $s2, 0x18($sp)
/* C85DC 80131EDC 8FB10014 */  lw        $s1, 0x14($sp)
/* C85E0 80131EE0 8FB00010 */  lw        $s0, 0x10($sp)
/* C85E4 80131EE4 03E00008 */  jr        $ra
/* C85E8 80131EE8 27BD0028 */   addiu    $sp, $sp, 0x28
