.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CA0_A044E0
/* A044E0 80241CA0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A044E4 80241CA4 AFB40040 */  sw        $s4, 0x40($sp)
/* A044E8 80241CA8 0080A02D */  daddu     $s4, $a0, $zero
/* A044EC 80241CAC AFBF0048 */  sw        $ra, 0x48($sp)
/* A044F0 80241CB0 AFB50044 */  sw        $s5, 0x44($sp)
/* A044F4 80241CB4 AFB3003C */  sw        $s3, 0x3c($sp)
/* A044F8 80241CB8 AFB20038 */  sw        $s2, 0x38($sp)
/* A044FC 80241CBC AFB10034 */  sw        $s1, 0x34($sp)
/* A04500 80241CC0 AFB00030 */  sw        $s0, 0x30($sp)
/* A04504 80241CC4 8E920148 */  lw        $s2, 0x148($s4)
/* A04508 80241CC8 86440008 */  lh        $a0, 8($s2)
/* A0450C 80241CCC 8E90000C */  lw        $s0, 0xc($s4)
/* A04510 80241CD0 0C00EABB */  jal       get_npc_unsafe
/* A04514 80241CD4 00A0882D */   daddu    $s1, $a1, $zero
/* A04518 80241CD8 0280202D */  daddu     $a0, $s4, $zero
/* A0451C 80241CDC 8E050000 */  lw        $a1, ($s0)
/* A04520 80241CE0 0C0B1EAF */  jal       get_variable
/* A04524 80241CE4 0040A82D */   daddu    $s5, $v0, $zero
/* A04528 80241CE8 AFA00010 */  sw        $zero, 0x10($sp)
/* A0452C 80241CEC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04530 80241CF0 8C630030 */  lw        $v1, 0x30($v1)
/* A04534 80241CF4 AFA30014 */  sw        $v1, 0x14($sp)
/* A04538 80241CF8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A0453C 80241CFC 8C63001C */  lw        $v1, 0x1c($v1)
/* A04540 80241D00 AFA30018 */  sw        $v1, 0x18($sp)
/* A04544 80241D04 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04548 80241D08 8C630024 */  lw        $v1, 0x24($v1)
/* A0454C 80241D0C AFA3001C */  sw        $v1, 0x1c($sp)
/* A04550 80241D10 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04554 80241D14 8C630028 */  lw        $v1, 0x28($v1)
/* A04558 80241D18 27B30010 */  addiu     $s3, $sp, 0x10
/* A0455C 80241D1C AFA30020 */  sw        $v1, 0x20($sp)
/* A04560 80241D20 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A04564 80241D24 3C0142F0 */  lui       $at, 0x42f0
/* A04568 80241D28 44810000 */  mtc1      $at, $f0
/* A0456C 80241D2C 8C63002C */  lw        $v1, 0x2c($v1)
/* A04570 80241D30 0040802D */  daddu     $s0, $v0, $zero
/* A04574 80241D34 E7A00028 */  swc1      $f0, 0x28($sp)
/* A04578 80241D38 A7A0002C */  sh        $zero, 0x2c($sp)
/* A0457C 80241D3C 12200006 */  beqz      $s1, .L80241D58
/* A04580 80241D40 AFA30024 */   sw       $v1, 0x24($sp)
/* A04584 80241D44 02A0202D */  daddu     $a0, $s5, $zero
/* A04588 80241D48 0240282D */  daddu     $a1, $s2, $zero
/* A0458C 80241D4C 0280302D */  daddu     $a2, $s4, $zero
/* A04590 80241D50 0C0906DF */  jal       func_80241B7C
/* A04594 80241D54 0200382D */   daddu    $a3, $s0, $zero
.L80241D58:
/* A04598 80241D58 2402FFFE */  addiu     $v0, $zero, -2
/* A0459C 80241D5C A2A200AB */  sb        $v0, 0xab($s5)
/* A045A0 80241D60 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A045A4 80241D64 30620004 */  andi      $v0, $v1, 4
/* A045A8 80241D68 10400007 */  beqz      $v0, .L80241D88
/* A045AC 80241D6C 00000000 */   nop      
/* A045B0 80241D70 824200B4 */  lb        $v0, 0xb4($s2)
/* A045B4 80241D74 1440003C */  bnez      $v0, .L80241E68
/* A045B8 80241D78 0000102D */   daddu    $v0, $zero, $zero
/* A045BC 80241D7C 2402FFFB */  addiu     $v0, $zero, -5
/* A045C0 80241D80 00621024 */  and       $v0, $v1, $v0
/* A045C4 80241D84 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241D88:
/* A045C8 80241D88 8E830070 */  lw        $v1, 0x70($s4)
/* A045CC 80241D8C 2C62000F */  sltiu     $v0, $v1, 0xf
/* A045D0 80241D90 10400034 */  beqz      $v0, .L80241E64
/* A045D4 80241D94 00031080 */   sll      $v0, $v1, 2
/* A045D8 80241D98 3C018024 */  lui       $at, 0x8024
/* A045DC 80241D9C 00220821 */  addu      $at, $at, $v0
/* A045E0 80241DA0 8C224638 */  lw        $v0, 0x4638($at)
/* A045E4 80241DA4 00400008 */  jr        $v0
/* A045E8 80241DA8 00000000 */   nop      
/* A045EC 80241DAC 0280202D */  daddu     $a0, $s4, $zero
/* A045F0 80241DB0 0200282D */  daddu     $a1, $s0, $zero
/* A045F4 80241DB4 0C090265 */  jal       func_80240994
/* A045F8 80241DB8 0260302D */   daddu    $a2, $s3, $zero
/* A045FC 80241DBC 0280202D */  daddu     $a0, $s4, $zero
/* A04600 80241DC0 0200282D */  daddu     $a1, $s0, $zero
/* A04604 80241DC4 0C0902D1 */  jal       func_80240B44
/* A04608 80241DC8 0260302D */   daddu    $a2, $s3, $zero
/* A0460C 80241DCC 0809079A */  j         .L80241E68
/* A04610 80241DD0 0000102D */   daddu    $v0, $zero, $zero
/* A04614 80241DD4 0280202D */  daddu     $a0, $s4, $zero
/* A04618 80241DD8 0200282D */  daddu     $a1, $s0, $zero
/* A0461C 80241DDC 0C09045B */  jal       func_8024116C
/* A04620 80241DE0 0260302D */   daddu    $a2, $s3, $zero
/* A04624 80241DE4 0280202D */  daddu     $a0, $s4, $zero
/* A04628 80241DE8 0200282D */  daddu     $a1, $s0, $zero
/* A0462C 80241DEC 0C09048B */  jal       func_8024122C
/* A04630 80241DF0 0260302D */   daddu    $a2, $s3, $zero
/* A04634 80241DF4 0809079A */  j         .L80241E68
/* A04638 80241DF8 0000102D */   daddu    $v0, $zero, $zero
/* A0463C 80241DFC 0280202D */  daddu     $a0, $s4, $zero
/* A04640 80241E00 0200282D */  daddu     $a1, $s0, $zero
/* A04644 80241E04 0C09055C */  jal       func_80241570
/* A04648 80241E08 0260302D */   daddu    $a2, $s3, $zero
/* A0464C 80241E0C 0280202D */  daddu     $a0, $s4, $zero
/* A04650 80241E10 0200282D */  daddu     $a1, $s0, $zero
/* A04654 80241E14 0C09057A */  jal       func_802415E8
/* A04658 80241E18 0260302D */   daddu    $a2, $s3, $zero
/* A0465C 80241E1C 0809079A */  j         .L80241E68
/* A04660 80241E20 0000102D */   daddu    $v0, $zero, $zero
/* A04664 80241E24 0280202D */  daddu     $a0, $s4, $zero
/* A04668 80241E28 0200282D */  daddu     $a1, $s0, $zero
/* A0466C 80241E2C 0C090595 */  jal       func_80241654
/* A04670 80241E30 0260302D */   daddu    $a2, $s3, $zero
/* A04674 80241E34 0809079A */  j         .L80241E68
/* A04678 80241E38 0000102D */   daddu    $v0, $zero, $zero
/* A0467C 80241E3C 0280202D */  daddu     $a0, $s4, $zero
/* A04680 80241E40 0200282D */  daddu     $a1, $s0, $zero
/* A04684 80241E44 0C0905E2 */  jal       func_80241788
/* A04688 80241E48 0260302D */   daddu    $a2, $s3, $zero
/* A0468C 80241E4C 0809079A */  j         .L80241E68
/* A04690 80241E50 0000102D */   daddu    $v0, $zero, $zero
/* A04694 80241E54 0280202D */  daddu     $a0, $s4, $zero
/* A04698 80241E58 0200282D */  daddu     $a1, $s0, $zero
/* A0469C 80241E5C 0C0905FB */  jal       func_802417EC
/* A046A0 80241E60 0260302D */   daddu    $a2, $s3, $zero
.L80241E64:
/* A046A4 80241E64 0000102D */  daddu     $v0, $zero, $zero
.L80241E68:
/* A046A8 80241E68 8FBF0048 */  lw        $ra, 0x48($sp)
/* A046AC 80241E6C 8FB50044 */  lw        $s5, 0x44($sp)
/* A046B0 80241E70 8FB40040 */  lw        $s4, 0x40($sp)
/* A046B4 80241E74 8FB3003C */  lw        $s3, 0x3c($sp)
/* A046B8 80241E78 8FB20038 */  lw        $s2, 0x38($sp)
/* A046BC 80241E7C 8FB10034 */  lw        $s1, 0x34($sp)
/* A046C0 80241E80 8FB00030 */  lw        $s0, 0x30($sp)
/* A046C4 80241E84 03E00008 */  jr        $ra
/* A046C8 80241E88 27BD0050 */   addiu    $sp, $sp, 0x50
