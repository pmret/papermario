.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_hud_elements
/* D7D10 80141610 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7D14 80141614 AFB10014 */  sw        $s1, 0x14($sp)
/* D7D18 80141618 0000882D */  daddu     $s1, $zero, $zero
/* D7D1C 8014161C AFB20018 */  sw        $s2, 0x18($sp)
/* D7D20 80141620 3C120004 */  lui       $s2, 4
/* D7D24 80141624 AFBF001C */  sw        $ra, 0x1c($sp)
/* D7D28 80141628 AFB00010 */  sw        $s0, 0x10($sp)
.L8014162C:
/* D7D2C 8014162C 3C038015 */  lui       $v1, %hi(gHudElementList)
/* D7D30 80141630 8C637960 */  lw        $v1, %lo(gHudElementList)($v1)
/* D7D34 80141634 00111080 */  sll       $v0, $s1, 2
/* D7D38 80141638 00431021 */  addu      $v0, $v0, $v1
/* D7D3C 8014163C 8C500000 */  lw        $s0, ($v0)
/* D7D40 80141640 52000027 */  beql      $s0, $zero, .L801416E0
/* D7D44 80141644 26310001 */   addiu    $s1, $s1, 1
/* D7D48 80141648 8E030000 */  lw        $v1, ($s0)
/* D7D4C 8014164C 10600023 */  beqz      $v1, .L801416DC
/* D7D50 80141650 30620002 */   andi     $v0, $v1, 2
/* D7D54 80141654 54400022 */  bnel      $v0, $zero, .L801416E0
/* D7D58 80141658 26310001 */   addiu    $s1, $s1, 1
/* D7D5C 8014165C 00721024 */  and       $v0, $v1, $s2
/* D7D60 80141660 10400005 */  beqz      $v0, .L80141678
/* D7D64 80141664 00000000 */   nop
/* D7D68 80141668 0C05123D */  jal       free_hud_element
/* D7D6C 8014166C 0220202D */   daddu    $a0, $s1, $zero
/* D7D70 80141670 080505B8 */  j         .L801416E0
/* D7D74 80141674 26310001 */   addiu    $s1, $s1, 1
.L80141678:
/* D7D78 80141678 8E020004 */  lw        $v0, 4($s0)
/* D7D7C 8014167C 1040001B */  beqz      $v0, .L801416EC
/* D7D80 80141680 00000000 */   nop
/* D7D84 80141684 92020047 */  lbu       $v0, 0x47($s0)
/* D7D88 80141688 2442FFFF */  addiu     $v0, $v0, -1
/* D7D8C 8014168C A2020047 */  sb        $v0, 0x47($s0)
/* D7D90 80141690 00021600 */  sll       $v0, $v0, 0x18
/* D7D94 80141694 14400005 */  bnez      $v0, .L801416AC
/* D7D98 80141698 00000000 */   nop
.L8014169C:
/* D7D9C 8014169C 0C0505C1 */  jal       hud_element_update
/* D7DA0 801416A0 0200202D */   daddu    $a0, $s0, $zero
/* D7DA4 801416A4 1440FFFD */  bnez      $v0, .L8014169C
/* D7DA8 801416A8 00000000 */   nop
.L801416AC:
/* D7DAC 801416AC 8E020000 */  lw        $v0, ($s0)
/* D7DB0 801416B0 30420100 */  andi      $v0, $v0, 0x100
/* D7DB4 801416B4 5040000A */  beql      $v0, $zero, .L801416E0
/* D7DB8 801416B8 26310001 */   addiu    $s1, $s1, 1
/* D7DBC 801416BC C6040028 */  lwc1      $f4, 0x28($s0)
/* D7DC0 801416C0 C6000020 */  lwc1      $f0, 0x20($s0)
/* D7DC4 801416C4 C602002C */  lwc1      $f2, 0x2c($s0)
/* D7DC8 801416C8 46002100 */  add.s     $f4, $f4, $f0
/* D7DCC 801416CC C6000024 */  lwc1      $f0, 0x24($s0)
/* D7DD0 801416D0 46001080 */  add.s     $f2, $f2, $f0
/* D7DD4 801416D4 E6040028 */  swc1      $f4, 0x28($s0)
/* D7DD8 801416D8 E602002C */  swc1      $f2, 0x2c($s0)
.L801416DC:
/* D7DDC 801416DC 26310001 */  addiu     $s1, $s1, 1
.L801416E0:
/* D7DE0 801416E0 2A220140 */  slti      $v0, $s1, 0x140
/* D7DE4 801416E4 1440FFD1 */  bnez      $v0, .L8014162C
/* D7DE8 801416E8 00000000 */   nop
.L801416EC:
/* D7DEC 801416EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* D7DF0 801416F0 8FB20018 */  lw        $s2, 0x18($sp)
/* D7DF4 801416F4 8FB10014 */  lw        $s1, 0x14($sp)
/* D7DF8 801416F8 8FB00010 */  lw        $s0, 0x10($sp)
/* D7DFC 801416FC 03E00008 */  jr        $ra
/* D7E00 80141700 27BD0020 */   addiu    $sp, $sp, 0x20
