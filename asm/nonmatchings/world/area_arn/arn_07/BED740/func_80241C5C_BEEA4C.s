.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C5C_BEEA4C
/* BEEA4C 80241C5C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BEEA50 80241C60 AFB40040 */  sw        $s4, 0x40($sp)
/* BEEA54 80241C64 0080A02D */  daddu     $s4, $a0, $zero
/* BEEA58 80241C68 AFBF0048 */  sw        $ra, 0x48($sp)
/* BEEA5C 80241C6C AFB50044 */  sw        $s5, 0x44($sp)
/* BEEA60 80241C70 AFB3003C */  sw        $s3, 0x3c($sp)
/* BEEA64 80241C74 AFB20038 */  sw        $s2, 0x38($sp)
/* BEEA68 80241C78 AFB10034 */  sw        $s1, 0x34($sp)
/* BEEA6C 80241C7C AFB00030 */  sw        $s0, 0x30($sp)
/* BEEA70 80241C80 8E920148 */  lw        $s2, 0x148($s4)
/* BEEA74 80241C84 86440008 */  lh        $a0, 8($s2)
/* BEEA78 80241C88 8E90000C */  lw        $s0, 0xc($s4)
/* BEEA7C 80241C8C 0C00EABB */  jal       get_npc_unsafe
/* BEEA80 80241C90 00A0882D */   daddu    $s1, $a1, $zero
/* BEEA84 80241C94 0280202D */  daddu     $a0, $s4, $zero
/* BEEA88 80241C98 8E050000 */  lw        $a1, ($s0)
/* BEEA8C 80241C9C 0C0B1EAF */  jal       get_variable
/* BEEA90 80241CA0 0040A82D */   daddu    $s5, $v0, $zero
/* BEEA94 80241CA4 AFA00010 */  sw        $zero, 0x10($sp)
/* BEEA98 80241CA8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BEEA9C 80241CAC 8C630030 */  lw        $v1, 0x30($v1)
/* BEEAA0 80241CB0 AFA30014 */  sw        $v1, 0x14($sp)
/* BEEAA4 80241CB4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BEEAA8 80241CB8 8C63001C */  lw        $v1, 0x1c($v1)
/* BEEAAC 80241CBC AFA30018 */  sw        $v1, 0x18($sp)
/* BEEAB0 80241CC0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BEEAB4 80241CC4 8C630024 */  lw        $v1, 0x24($v1)
/* BEEAB8 80241CC8 AFA3001C */  sw        $v1, 0x1c($sp)
/* BEEABC 80241CCC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BEEAC0 80241CD0 8C630028 */  lw        $v1, 0x28($v1)
/* BEEAC4 80241CD4 27B30010 */  addiu     $s3, $sp, 0x10
/* BEEAC8 80241CD8 AFA30020 */  sw        $v1, 0x20($sp)
/* BEEACC 80241CDC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BEEAD0 80241CE0 3C0142F0 */  lui       $at, 0x42f0
/* BEEAD4 80241CE4 44810000 */  mtc1      $at, $f0
/* BEEAD8 80241CE8 8C63002C */  lw        $v1, 0x2c($v1)
/* BEEADC 80241CEC 0040802D */  daddu     $s0, $v0, $zero
/* BEEAE0 80241CF0 E7A00028 */  swc1      $f0, 0x28($sp)
/* BEEAE4 80241CF4 A7A0002C */  sh        $zero, 0x2c($sp)
/* BEEAE8 80241CF8 12200006 */  beqz      $s1, .L80241D14
/* BEEAEC 80241CFC AFA30024 */   sw       $v1, 0x24($sp)
/* BEEAF0 80241D00 02A0202D */  daddu     $a0, $s5, $zero
/* BEEAF4 80241D04 0240282D */  daddu     $a1, $s2, $zero
/* BEEAF8 80241D08 0280302D */  daddu     $a2, $s4, $zero
/* BEEAFC 80241D0C 0C0906CE */  jal       func_80241B38_BEE928
/* BEEB00 80241D10 0200382D */   daddu    $a3, $s0, $zero
.L80241D14:
/* BEEB04 80241D14 2402FFFE */  addiu     $v0, $zero, -2
/* BEEB08 80241D18 A2A200AB */  sb        $v0, 0xab($s5)
/* BEEB0C 80241D1C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BEEB10 80241D20 30620004 */  andi      $v0, $v1, 4
/* BEEB14 80241D24 10400007 */  beqz      $v0, .L80241D44
/* BEEB18 80241D28 00000000 */   nop
/* BEEB1C 80241D2C 824200B4 */  lb        $v0, 0xb4($s2)
/* BEEB20 80241D30 1440003C */  bnez      $v0, .L80241E24
/* BEEB24 80241D34 0000102D */   daddu    $v0, $zero, $zero
/* BEEB28 80241D38 2402FFFB */  addiu     $v0, $zero, -5
/* BEEB2C 80241D3C 00621024 */  and       $v0, $v1, $v0
/* BEEB30 80241D40 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241D44:
/* BEEB34 80241D44 8E830070 */  lw        $v1, 0x70($s4)
/* BEEB38 80241D48 2C62000F */  sltiu     $v0, $v1, 0xf
/* BEEB3C 80241D4C 10400034 */  beqz      $v0, .L80241E20
/* BEEB40 80241D50 00031080 */   sll      $v0, $v1, 2
/* BEEB44 80241D54 3C018024 */  lui       $at, %hi(jtbl_80247968_BF4758)
/* BEEB48 80241D58 00220821 */  addu      $at, $at, $v0
/* BEEB4C 80241D5C 8C227968 */  lw        $v0, %lo(jtbl_80247968_BF4758)($at)
/* BEEB50 80241D60 00400008 */  jr        $v0
/* BEEB54 80241D64 00000000 */   nop
glabel L80241D68_BEEB58
/* BEEB58 80241D68 0280202D */  daddu     $a0, $s4, $zero
/* BEEB5C 80241D6C 0200282D */  daddu     $a1, $s0, $zero
/* BEEB60 80241D70 0C090254 */  jal       func_80240950_BED740
/* BEEB64 80241D74 0260302D */   daddu    $a2, $s3, $zero
glabel L80241D78_BEEB68
/* BEEB68 80241D78 0280202D */  daddu     $a0, $s4, $zero
/* BEEB6C 80241D7C 0200282D */  daddu     $a1, $s0, $zero
/* BEEB70 80241D80 0C0902C0 */  jal       func_80240B00_BED8F0
/* BEEB74 80241D84 0260302D */   daddu    $a2, $s3, $zero
/* BEEB78 80241D88 08090789 */  j         .L80241E24
/* BEEB7C 80241D8C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241D90_BEEB80
/* BEEB80 80241D90 0280202D */  daddu     $a0, $s4, $zero
/* BEEB84 80241D94 0200282D */  daddu     $a1, $s0, $zero
/* BEEB88 80241D98 0C09044A */  jal       arn_07_UnkNpcAIFunc1
/* BEEB8C 80241D9C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241DA0_BEEB90
/* BEEB90 80241DA0 0280202D */  daddu     $a0, $s4, $zero
/* BEEB94 80241DA4 0200282D */  daddu     $a1, $s0, $zero
/* BEEB98 80241DA8 0C09047A */  jal       func_802411E8_BEDFD8
/* BEEB9C 80241DAC 0260302D */   daddu    $a2, $s3, $zero
/* BEEBA0 80241DB0 08090789 */  j         .L80241E24
/* BEEBA4 80241DB4 0000102D */   daddu    $v0, $zero, $zero
glabel L80241DB8_BEEBA8
/* BEEBA8 80241DB8 0280202D */  daddu     $a0, $s4, $zero
/* BEEBAC 80241DBC 0200282D */  daddu     $a1, $s0, $zero
/* BEEBB0 80241DC0 0C09054B */  jal       arn_07_UnkNpcAIFunc2
/* BEEBB4 80241DC4 0260302D */   daddu    $a2, $s3, $zero
glabel L80241DC8_BEEBB8
/* BEEBB8 80241DC8 0280202D */  daddu     $a0, $s4, $zero
/* BEEBBC 80241DCC 0200282D */  daddu     $a1, $s0, $zero
/* BEEBC0 80241DD0 0C090569 */  jal       func_802415A4_BEE394
/* BEEBC4 80241DD4 0260302D */   daddu    $a2, $s3, $zero
/* BEEBC8 80241DD8 08090789 */  j         .L80241E24
/* BEEBCC 80241DDC 0000102D */   daddu    $v0, $zero, $zero
glabel L80241DE0_BEEBD0
/* BEEBD0 80241DE0 0280202D */  daddu     $a0, $s4, $zero
/* BEEBD4 80241DE4 0200282D */  daddu     $a1, $s0, $zero
/* BEEBD8 80241DE8 0C090584 */  jal       func_80241610_BEE400
/* BEEBDC 80241DEC 0260302D */   daddu    $a2, $s3, $zero
/* BEEBE0 80241DF0 08090789 */  j         .L80241E24
/* BEEBE4 80241DF4 0000102D */   daddu    $v0, $zero, $zero
glabel L80241DF8_BEEBE8
/* BEEBE8 80241DF8 0280202D */  daddu     $a0, $s4, $zero
/* BEEBEC 80241DFC 0200282D */  daddu     $a1, $s0, $zero
/* BEEBF0 80241E00 0C0905D1 */  jal       arn_07_UnkNpcAIFunc3
/* BEEBF4 80241E04 0260302D */   daddu    $a2, $s3, $zero
/* BEEBF8 80241E08 08090789 */  j         .L80241E24
/* BEEBFC 80241E0C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241E10_BEEC00
/* BEEC00 80241E10 0280202D */  daddu     $a0, $s4, $zero
/* BEEC04 80241E14 0200282D */  daddu     $a1, $s0, $zero
/* BEEC08 80241E18 0C0905EA */  jal       func_802417A8_BEE598
/* BEEC0C 80241E1C 0260302D */   daddu    $a2, $s3, $zero
.L80241E20:
glabel L80241E20_BEEC10
/* BEEC10 80241E20 0000102D */  daddu     $v0, $zero, $zero
.L80241E24:
/* BEEC14 80241E24 8FBF0048 */  lw        $ra, 0x48($sp)
/* BEEC18 80241E28 8FB50044 */  lw        $s5, 0x44($sp)
/* BEEC1C 80241E2C 8FB40040 */  lw        $s4, 0x40($sp)
/* BEEC20 80241E30 8FB3003C */  lw        $s3, 0x3c($sp)
/* BEEC24 80241E34 8FB20038 */  lw        $s2, 0x38($sp)
/* BEEC28 80241E38 8FB10034 */  lw        $s1, 0x34($sp)
/* BEEC2C 80241E3C 8FB00030 */  lw        $s0, 0x30($sp)
/* BEEC30 80241E40 03E00008 */  jr        $ra
/* BEEC34 80241E44 27BD0050 */   addiu    $sp, $sp, 0x50
