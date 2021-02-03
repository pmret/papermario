.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80246D10
/* 167570 80246D10 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 167574 80246D14 AFB60030 */  sw        $s6, 0x30($sp)
/* 167578 80246D18 0080B02D */  daddu     $s6, $a0, $zero
/* 16757C 80246D1C AFB40028 */  sw        $s4, 0x28($sp)
/* 167580 80246D20 00A0A02D */  daddu     $s4, $a1, $zero
/* 167584 80246D24 AFBF0034 */  sw        $ra, 0x34($sp)
/* 167588 80246D28 AFB5002C */  sw        $s5, 0x2c($sp)
/* 16758C 80246D2C AFB30024 */  sw        $s3, 0x24($sp)
/* 167590 80246D30 AFB20020 */  sw        $s2, 0x20($sp)
/* 167594 80246D34 AFB1001C */  sw        $s1, 0x1c($sp)
/* 167598 80246D38 AFB00018 */  sw        $s0, 0x18($sp)
/* 16759C 80246D3C 82C30004 */  lb        $v1, 4($s6)
/* 1675A0 80246D40 2C620005 */  sltiu     $v0, $v1, 5
/* 1675A4 80246D44 1040000B */  beqz      $v0, .L80246D74
/* 1675A8 80246D48 00C0A82D */   daddu    $s5, $a2, $zero
/* 1675AC 80246D4C 00031080 */  sll       $v0, $v1, 2
/* 1675B0 80246D50 3C018025 */  lui       $at, %hi(jtbl_8024BFE8)
/* 1675B4 80246D54 00220821 */  addu      $at, $at, $v0
/* 1675B8 80246D58 8C22BFE8 */  lw        $v0, %lo(jtbl_8024BFE8)($at)
/* 1675BC 80246D5C 00400008 */  jr        $v0
/* 1675C0 80246D60 00000000 */   nop
glabel L80246D64_1675C4
/* 1675C4 80246D64 2413001C */  addiu     $s3, $zero, 0x1c
/* 1675C8 80246D68 24120004 */  addiu     $s2, $zero, 4
/* 1675CC 80246D6C 0260882D */  daddu     $s1, $s3, $zero
/* 1675D0 80246D70 24100015 */  addiu     $s0, $zero, 0x15
.L80246D74:
/* 1675D4 80246D74 0C0926A9 */  jal       func_80249AA4
/* 1675D8 80246D78 2404000E */   addiu    $a0, $zero, 0xe
/* 1675DC 80246D7C 0040202D */  daddu     $a0, $v0, $zero
/* 1675E0 80246D80 02932821 */  addu      $a1, $s4, $s3
/* 1675E4 80246D84 02B23021 */  addu      $a2, $s5, $s2
/* 1675E8 80246D88 240700FF */  addiu     $a3, $zero, 0xff
/* 1675EC 80246D8C AFA00010 */  sw        $zero, 0x10($sp)
/* 1675F0 80246D90 0C09265F */  jal       func_8024997C
/* 1675F4 80246D94 AFA00014 */   sw       $zero, 0x14($sp)
/* 1675F8 80246D98 0C0926A9 */  jal       func_80249AA4
/* 1675FC 80246D9C 2404000F */   addiu    $a0, $zero, 0xf
/* 167600 80246DA0 0040202D */  daddu     $a0, $v0, $zero
/* 167604 80246DA4 02912821 */  addu      $a1, $s4, $s1
/* 167608 80246DA8 02B03021 */  addu      $a2, $s5, $s0
/* 16760C 80246DAC 240700FF */  addiu     $a3, $zero, 0xff
/* 167610 80246DB0 AFA00010 */  sw        $zero, 0x10($sp)
/* 167614 80246DB4 0C09265F */  jal       func_8024997C
/* 167618 80246DB8 AFA00014 */   sw       $zero, 0x14($sp)
/* 16761C 80246DBC 3C038025 */  lui       $v1, %hi(D_8024C098)
/* 167620 80246DC0 8063C098 */  lb        $v1, %lo(D_8024C098)($v1)
/* 167624 80246DC4 24020001 */  addiu     $v0, $zero, 1
/* 167628 80246DC8 1462000C */  bne       $v1, $v0, .L80246DFC
/* 16762C 80246DCC 00000000 */   nop
/* 167630 80246DD0 92C20003 */  lbu       $v0, 3($s6)
/* 167634 80246DD4 14400004 */  bnez      $v0, .L80246DE8
/* 167638 80246DD8 2623FFF6 */   addiu    $v1, $s1, -0xa
/* 16763C 80246DDC 2663FFF6 */  addiu     $v1, $s3, -0xa
/* 167640 80246DE0 08091B7B */  j         .L80246DEC
/* 167644 80246DE4 26420008 */   addiu    $v0, $s2, 8
.L80246DE8:
/* 167648 80246DE8 26020008 */  addiu     $v0, $s0, 8
.L80246DEC:
/* 16764C 80246DEC 24040032 */  addiu     $a0, $zero, 0x32
/* 167650 80246DF0 02832821 */  addu      $a1, $s4, $v1
/* 167654 80246DF4 0C090B80 */  jal       func_80242E00
/* 167658 80246DF8 02A23021 */   addu     $a2, $s5, $v0
.L80246DFC:
/* 16765C 80246DFC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 167660 80246E00 8FB60030 */  lw        $s6, 0x30($sp)
/* 167664 80246E04 8FB5002C */  lw        $s5, 0x2c($sp)
/* 167668 80246E08 8FB40028 */  lw        $s4, 0x28($sp)
/* 16766C 80246E0C 8FB30024 */  lw        $s3, 0x24($sp)
/* 167670 80246E10 8FB20020 */  lw        $s2, 0x20($sp)
/* 167674 80246E14 8FB1001C */  lw        $s1, 0x1c($sp)
/* 167678 80246E18 8FB00018 */  lw        $s0, 0x18($sp)
/* 16767C 80246E1C 03E00008 */  jr        $ra
/* 167680 80246E20 27BD0038 */   addiu    $sp, $sp, 0x38
