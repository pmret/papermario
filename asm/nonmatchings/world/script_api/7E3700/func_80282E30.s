.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282E30
/* 7E3CB0 80282E30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E3CB4 80282E34 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E3CB8 80282E38 0080802D */  daddu     $s0, $a0, $zero
/* 7E3CBC 80282E3C AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E3CC0 80282E40 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E3CC4 80282E44 8E0400B0 */  lw        $a0, 0xb0($s0)
/* 7E3CC8 80282E48 0C04417A */  jal       get_entity_by_index
/* 7E3CCC 80282E4C 8E1100AC */   lw       $s1, 0xac($s0)
/* 7E3CD0 80282E50 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 7E3CD4 80282E54 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 7E3CD8 80282E58 0040502D */  daddu     $t2, $v0, $zero
/* 7E3CDC 80282E5C C4600028 */  lwc1      $f0, 0x28($v1)
/* 7E3CE0 80282E60 C462002C */  lwc1      $f2, 0x2c($v1)
/* 7E3CE4 80282E64 8E2D0008 */  lw        $t5, 8($s1)
/* 7E3CE8 80282E68 8E2B000C */  lw        $t3, 0xc($s1)
/* 7E3CEC 80282E6C 8E2C0010 */  lw        $t4, 0x10($s1)
/* 7E3CF0 80282E70 4600010D */  trunc.w.s $f4, $f0
/* 7E3CF4 80282E74 44042000 */  mfc1      $a0, $f4
/* 7E3CF8 80282E78 4600110D */  trunc.w.s $f4, $f2
/* 7E3CFC 80282E7C 44092000 */  mfc1      $t1, $f4
/* 7E3D00 80282E80 008D2023 */  subu      $a0, $a0, $t5
/* 7E3D04 80282E84 C4600030 */  lwc1      $f0, 0x30($v1)
/* 7E3D08 80282E88 012B4823 */  subu      $t1, $t1, $t3
/* 7E3D0C 80282E8C 4600010D */  trunc.w.s $f4, $f0
/* 7E3D10 80282E90 44082000 */  mfc1      $t0, $f4
/* 7E3D14 80282E94 04810002 */  bgez      $a0, .L80282EA0
/* 7E3D18 80282E98 010C4023 */   subu     $t0, $t0, $t4
/* 7E3D1C 80282E9C 2484FFE7 */  addiu     $a0, $a0, -0x19
.L80282EA0:
/* 7E3D20 80282EA0 05020001 */  bltzl     $t0, .L80282EA8
/* 7E3D24 80282EA4 2508FFE7 */   addiu    $t0, $t0, -0x19
.L80282EA8:
/* 7E3D28 80282EA8 3C0551EB */  lui       $a1, 0x51eb
/* 7E3D2C 80282EAC 34A5851F */  ori       $a1, $a1, 0x851f
/* 7E3D30 80282EB0 00850018 */  mult      $a0, $a1
/* 7E3D34 80282EB4 00001810 */  mfhi      $v1
/* 7E3D38 80282EB8 00000000 */  nop       
/* 7E3D3C 80282EBC 00000000 */  nop       
/* 7E3D40 80282EC0 01250018 */  mult      $t1, $a1
/* 7E3D44 80282EC4 000417C3 */  sra       $v0, $a0, 0x1f
/* 7E3D48 80282EC8 00003010 */  mfhi      $a2
/* 7E3D4C 80282ECC 000318C3 */  sra       $v1, $v1, 3
/* 7E3D50 80282ED0 00622023 */  subu      $a0, $v1, $v0
/* 7E3D54 80282ED4 01050018 */  mult      $t0, $a1
/* 7E3D58 80282ED8 000917C3 */  sra       $v0, $t1, 0x1f
/* 7E3D5C 80282EDC 000618C3 */  sra       $v1, $a2, 3
/* 7E3D60 80282EE0 00624823 */  subu      $t1, $v1, $v0
/* 7E3D64 80282EE4 000817C3 */  sra       $v0, $t0, 0x1f
/* 7E3D68 80282EE8 00003810 */  mfhi      $a3
/* 7E3D6C 80282EEC 000718C3 */  sra       $v1, $a3, 3
/* 7E3D70 80282EF0 00624023 */  subu      $t0, $v1, $v0
/* 7E3D74 80282EF4 0080382D */  daddu     $a3, $a0, $zero
/* 7E3D78 80282EF8 00041040 */  sll       $v0, $a0, 1
/* 7E3D7C 80282EFC 00441021 */  addu      $v0, $v0, $a0
/* 7E3D80 80282F00 000210C0 */  sll       $v0, $v0, 3
/* 7E3D84 80282F04 00822021 */  addu      $a0, $a0, $v0
/* 7E3D88 80282F08 00091040 */  sll       $v0, $t1, 1
/* 7E3D8C 80282F0C 00491021 */  addu      $v0, $v0, $t1
/* 7E3D90 80282F10 000210C0 */  sll       $v0, $v0, 3
/* 7E3D94 80282F14 01224821 */  addu      $t1, $t1, $v0
/* 7E3D98 80282F18 0100302D */  daddu     $a2, $t0, $zero
/* 7E3D9C 80282F1C 00081040 */  sll       $v0, $t0, 1
/* 7E3DA0 80282F20 00481021 */  addu      $v0, $v0, $t0
/* 7E3DA4 80282F24 000210C0 */  sll       $v0, $v0, 3
/* 7E3DA8 80282F28 01024021 */  addu      $t0, $t0, $v0
/* 7E3DAC 80282F2C 2482000C */  addiu     $v0, $a0, 0xc
/* 7E3DB0 80282F30 004D2021 */  addu      $a0, $v0, $t5
/* 7E3DB4 80282F34 012B4821 */  addu      $t1, $t1, $t3
/* 7E3DB8 80282F38 2502000C */  addiu     $v0, $t0, 0xc
/* 7E3DBC 80282F3C 004C4021 */  addu      $t0, $v0, $t4
/* 7E3DC0 80282F40 AE040084 */  sw        $a0, 0x84($s0)
/* 7E3DC4 80282F44 AE090088 */  sw        $t1, 0x88($s0)
/* 7E3DC8 80282F48 AE08008C */  sw        $t0, 0x8c($s0)
/* 7E3DCC 80282F4C C5400048 */  lwc1      $f0, 0x48($t2)
/* 7E3DD0 80282F50 4600010D */  trunc.w.s $f4, $f0
/* 7E3DD4 80282F54 44042000 */  mfc1      $a0, $f4
/* 7E3DD8 80282F58 00000000 */  nop       
/* 7E3DDC 80282F5C AE040090 */  sw        $a0, 0x90($s0)
/* 7E3DE0 80282F60 C540004C */  lwc1      $f0, 0x4c($t2)
/* 7E3DE4 80282F64 4600010D */  trunc.w.s $f4, $f0
/* 7E3DE8 80282F68 E6040094 */  swc1      $f4, 0x94($s0)
/* 7E3DEC 80282F6C C5400050 */  lwc1      $f0, 0x50($t2)
/* 7E3DF0 80282F70 4600010D */  trunc.w.s $f4, $f0
/* 7E3DF4 80282F74 44032000 */  mfc1      $v1, $f4
/* 7E3DF8 80282F78 00000000 */  nop       
/* 7E3DFC 80282F7C AE030098 */  sw        $v1, 0x98($s0)
/* 7E3E00 80282F80 8E220008 */  lw        $v0, 8($s1)
/* 7E3E04 80282F84 00822023 */  subu      $a0, $a0, $v0
/* 7E3E08 80282F88 00850018 */  mult      $a0, $a1
/* 7E3E0C 80282F8C 8E220010 */  lw        $v0, 0x10($s1)
/* 7E3E10 80282F90 00005010 */  mfhi      $t2
/* 7E3E14 80282F94 00624023 */  subu      $t0, $v1, $v0
/* 7E3E18 80282F98 000417C3 */  sra       $v0, $a0, 0x1f
/* 7E3E1C 80282F9C 01050018 */  mult      $t0, $a1
/* 7E3E20 80282FA0 000A18C3 */  sra       $v1, $t2, 3
/* 7E3E24 80282FA4 00625023 */  subu      $t2, $v1, $v0
/* 7E3E28 80282FA8 01472823 */  subu      $a1, $t2, $a3
/* 7E3E2C 80282FAC 000817C3 */  sra       $v0, $t0, 0x1f
/* 7E3E30 80282FB0 00004810 */  mfhi      $t1
/* 7E3E34 80282FB4 000918C3 */  sra       $v1, $t1, 3
/* 7E3E38 80282FB8 00621023 */  subu      $v0, $v1, $v0
/* 7E3E3C 80282FBC 10A00005 */  beqz      $a1, .L80282FD4
/* 7E3E40 80282FC0 00462023 */   subu     $a0, $v0, $a2
/* 7E3E44 80282FC4 10800004 */  beqz      $a0, .L80282FD8
/* 7E3E48 80282FC8 01453021 */   addu     $a2, $t2, $a1
/* 7E3E4C 80282FCC 0000202D */  daddu     $a0, $zero, $zero
/* 7E3E50 80282FD0 0080282D */  daddu     $a1, $a0, $zero
.L80282FD4:
/* 7E3E54 80282FD4 01453021 */  addu      $a2, $t2, $a1
.L80282FD8:
/* 7E3E58 80282FD8 00441821 */  addu      $v1, $v0, $a0
/* 7E3E5C 80282FDC AE05009C */  sw        $a1, 0x9c($s0)
/* 7E3E60 80282FE0 AE0000A0 */  sw        $zero, 0xa0($s0)
/* 7E3E64 80282FE4 14A00005 */  bnez      $a1, .L80282FFC
/* 7E3E68 80282FE8 AE0400A4 */   sw       $a0, 0xa4($s0)
/* 7E3E6C 80282FEC 14800003 */  bnez      $a0, .L80282FFC
/* 7E3E70 80282FF0 24020002 */   addiu    $v0, $zero, 2
/* 7E3E74 80282FF4 080A0C1B */  j         .L8028306C
/* 7E3E78 80282FF8 AE0200A8 */   sw       $v0, 0xa8($s0)
.L80282FFC:
/* 7E3E7C 80282FFC 92240004 */  lbu       $a0, 4($s1)
/* 7E3E80 80283000 00C4102A */  slt       $v0, $a2, $a0
/* 7E3E84 80283004 10400017 */  beqz      $v0, .L80283064
/* 7E3E88 80283008 24020001 */   addiu    $v0, $zero, 1
/* 7E3E8C 8028300C 04C20016 */  bltzl     $a2, .L80283068
/* 7E3E90 80283010 AE0200A8 */   sw       $v0, 0xa8($s0)
/* 7E3E94 80283014 92220005 */  lbu       $v0, 5($s1)
/* 7E3E98 80283018 0062102A */  slt       $v0, $v1, $v0
/* 7E3E9C 8028301C 10400011 */  beqz      $v0, .L80283064
/* 7E3EA0 80283020 24020001 */   addiu    $v0, $zero, 1
/* 7E3EA4 80283024 0460000F */  bltz      $v1, .L80283064
/* 7E3EA8 80283028 00640018 */   mult     $v1, $a0
/* 7E3EAC 8028302C 8E220000 */  lw        $v0, ($s1)
/* 7E3EB0 80283030 00007012 */  mflo      $t6
/* 7E3EB4 80283034 00CE1821 */  addu      $v1, $a2, $t6
/* 7E3EB8 80283038 00431021 */  addu      $v0, $v0, $v1
/* 7E3EBC 8028303C 90420000 */  lbu       $v0, ($v0)
/* 7E3EC0 80283040 14400008 */  bnez      $v0, .L80283064
/* 7E3EC4 80283044 24020001 */   addiu    $v0, $zero, 1
/* 7E3EC8 80283048 3C038016 */  lui       $v1, %hi(gCollisionStatus)
/* 7E3ECC 8028304C 8463A550 */  lh        $v1, %lo(gCollisionStatus)($v1)
/* 7E3ED0 80283050 2402FFFF */  addiu     $v0, $zero, -1
/* 7E3ED4 80283054 10620003 */  beq       $v1, $v0, .L80283064
/* 7E3ED8 80283058 24020001 */   addiu    $v0, $zero, 1
/* 7E3EDC 8028305C 080A0C1A */  j         .L80283068
/* 7E3EE0 80283060 AE0000A8 */   sw       $zero, 0xa8($s0)
.L80283064:
/* 7E3EE4 80283064 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80283068:
/* 7E3EE8 80283068 24020002 */  addiu     $v0, $zero, 2
.L8028306C:
/* 7E3EEC 8028306C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E3EF0 80283070 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E3EF4 80283074 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E3EF8 80283078 03E00008 */  jr        $ra
/* 7E3EFC 8028307C 27BD0020 */   addiu    $sp, $sp, 0x20
