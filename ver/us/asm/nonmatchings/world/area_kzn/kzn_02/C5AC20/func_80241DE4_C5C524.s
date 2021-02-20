.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DE4_C5C524
/* C5C524 80241DE4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C5C528 80241DE8 AFB40040 */  sw        $s4, 0x40($sp)
/* C5C52C 80241DEC 0080A02D */  daddu     $s4, $a0, $zero
/* C5C530 80241DF0 AFBF0048 */  sw        $ra, 0x48($sp)
/* C5C534 80241DF4 AFB50044 */  sw        $s5, 0x44($sp)
/* C5C538 80241DF8 AFB3003C */  sw        $s3, 0x3c($sp)
/* C5C53C 80241DFC AFB20038 */  sw        $s2, 0x38($sp)
/* C5C540 80241E00 AFB10034 */  sw        $s1, 0x34($sp)
/* C5C544 80241E04 AFB00030 */  sw        $s0, 0x30($sp)
/* C5C548 80241E08 8E920148 */  lw        $s2, 0x148($s4)
/* C5C54C 80241E0C 86440008 */  lh        $a0, 8($s2)
/* C5C550 80241E10 8E90000C */  lw        $s0, 0xc($s4)
/* C5C554 80241E14 0C00EABB */  jal       get_npc_unsafe
/* C5C558 80241E18 00A0882D */   daddu    $s1, $a1, $zero
/* C5C55C 80241E1C 0280202D */  daddu     $a0, $s4, $zero
/* C5C560 80241E20 8E050000 */  lw        $a1, ($s0)
/* C5C564 80241E24 0C0B1EAF */  jal       get_variable
/* C5C568 80241E28 0040A82D */   daddu    $s5, $v0, $zero
/* C5C56C 80241E2C AFA00010 */  sw        $zero, 0x10($sp)
/* C5C570 80241E30 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5C574 80241E34 8C630030 */  lw        $v1, 0x30($v1)
/* C5C578 80241E38 AFA30014 */  sw        $v1, 0x14($sp)
/* C5C57C 80241E3C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5C580 80241E40 8C63001C */  lw        $v1, 0x1c($v1)
/* C5C584 80241E44 AFA30018 */  sw        $v1, 0x18($sp)
/* C5C588 80241E48 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5C58C 80241E4C 8C630024 */  lw        $v1, 0x24($v1)
/* C5C590 80241E50 AFA3001C */  sw        $v1, 0x1c($sp)
/* C5C594 80241E54 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5C598 80241E58 8C630028 */  lw        $v1, 0x28($v1)
/* C5C59C 80241E5C 27B30010 */  addiu     $s3, $sp, 0x10
/* C5C5A0 80241E60 AFA30020 */  sw        $v1, 0x20($sp)
/* C5C5A4 80241E64 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5C5A8 80241E68 3C0142F0 */  lui       $at, 0x42f0
/* C5C5AC 80241E6C 44810000 */  mtc1      $at, $f0
/* C5C5B0 80241E70 8C63002C */  lw        $v1, 0x2c($v1)
/* C5C5B4 80241E74 0040802D */  daddu     $s0, $v0, $zero
/* C5C5B8 80241E78 E7A00028 */  swc1      $f0, 0x28($sp)
/* C5C5BC 80241E7C A7A0002C */  sh        $zero, 0x2c($sp)
/* C5C5C0 80241E80 12200007 */  beqz      $s1, .L80241EA0
/* C5C5C4 80241E84 AFA30024 */   sw       $v1, 0x24($sp)
/* C5C5C8 80241E88 02A0202D */  daddu     $a0, $s5, $zero
/* C5C5CC 80241E8C 0240282D */  daddu     $a1, $s2, $zero
/* C5C5D0 80241E90 0280302D */  daddu     $a2, $s4, $zero
/* C5C5D4 80241E94 0C0905B2 */  jal       func_802416C8_C5BE08
/* C5C5D8 80241E98 0200382D */   daddu    $a3, $s0, $zero
/* C5C5DC 80241E9C AE800070 */  sw        $zero, 0x70($s4)
.L80241EA0:
/* C5C5E0 80241EA0 2402FFFE */  addiu     $v0, $zero, -2
/* C5C5E4 80241EA4 A2A200AB */  sb        $v0, 0xab($s5)
/* C5C5E8 80241EA8 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C5C5EC 80241EAC 30620004 */  andi      $v0, $v1, 4
/* C5C5F0 80241EB0 10400007 */  beqz      $v0, .L80241ED0
/* C5C5F4 80241EB4 00000000 */   nop
/* C5C5F8 80241EB8 824200B4 */  lb        $v0, 0xb4($s2)
/* C5C5FC 80241EBC 1440003A */  bnez      $v0, .L80241FA8
/* C5C600 80241EC0 0000102D */   daddu    $v0, $zero, $zero
/* C5C604 80241EC4 2402FFFB */  addiu     $v0, $zero, -5
/* C5C608 80241EC8 00621024 */  and       $v0, $v1, $v0
/* C5C60C 80241ECC AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241ED0:
/* C5C610 80241ED0 8E830070 */  lw        $v1, 0x70($s4)
/* C5C614 80241ED4 2C620015 */  sltiu     $v0, $v1, 0x15
/* C5C618 80241ED8 10400032 */  beqz      $v0, .L80241FA4
/* C5C61C 80241EDC 00031080 */   sll      $v0, $v1, 2
/* C5C620 80241EE0 3C018024 */  lui       $at, %hi(jtbl_80246560_C60CA0)
/* C5C624 80241EE4 00220821 */  addu      $at, $at, $v0
/* C5C628 80241EE8 8C226560 */  lw        $v0, %lo(jtbl_80246560_C60CA0)($at)
/* C5C62C 80241EEC 00400008 */  jr        $v0
/* C5C630 80241EF0 00000000 */   nop
glabel L80241EF4_C5C634
/* C5C634 80241EF4 0280202D */  daddu     $a0, $s4, $zero
/* C5C638 80241EF8 0200282D */  daddu     $a1, $s0, $zero
/* C5C63C 80241EFC 0C090138 */  jal       func_802404E0_C5AC20
/* C5C640 80241F00 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F04_C5C644
/* C5C644 80241F04 0280202D */  daddu     $a0, $s4, $zero
/* C5C648 80241F08 0200282D */  daddu     $a1, $s0, $zero
/* C5C64C 80241F0C 0C0901A4 */  jal       func_80240690_C5ADD0
/* C5C650 80241F10 0260302D */   daddu    $a2, $s3, $zero
/* C5C654 80241F14 080907EA */  j         .L80241FA8
/* C5C658 80241F18 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F1C_C5C65C
/* C5C65C 80241F1C 0280202D */  daddu     $a0, $s4, $zero
/* C5C660 80241F20 0200282D */  daddu     $a1, $s0, $zero
/* C5C664 80241F24 0C09032E */  jal       kzn_02_UnkNpcAIFunc1
/* C5C668 80241F28 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F2C_C5C66C
/* C5C66C 80241F2C 0280202D */  daddu     $a0, $s4, $zero
/* C5C670 80241F30 0200282D */  daddu     $a1, $s0, $zero
/* C5C674 80241F34 0C09035E */  jal       func_80240D78_C5B4B8
/* C5C678 80241F38 0260302D */   daddu    $a2, $s3, $zero
/* C5C67C 80241F3C 080907EA */  j         .L80241FA8
/* C5C680 80241F40 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F44_C5C684
/* C5C684 80241F44 0280202D */  daddu     $a0, $s4, $zero
/* C5C688 80241F48 0200282D */  daddu     $a1, $s0, $zero
/* C5C68C 80241F4C 0C09042F */  jal       kzn_02_UnkNpcAIFunc2
/* C5C690 80241F50 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F54_C5C694
/* C5C694 80241F54 0280202D */  daddu     $a0, $s4, $zero
/* C5C698 80241F58 0200282D */  daddu     $a1, $s0, $zero
/* C5C69C 80241F5C 0C09044D */  jal       func_80241134_C5B874
/* C5C6A0 80241F60 0260302D */   daddu    $a2, $s3, $zero
/* C5C6A4 80241F64 080907EA */  j         .L80241FA8
/* C5C6A8 80241F68 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F6C_C5C6AC
/* C5C6AC 80241F6C 0280202D */  daddu     $a0, $s4, $zero
/* C5C6B0 80241F70 0200282D */  daddu     $a1, $s0, $zero
/* C5C6B4 80241F74 0C090676 */  jal       kzn_02_UnkNpcAIFunc13
/* C5C6B8 80241F78 0260302D */   daddu    $a2, $s3, $zero
glabel L80241F7C_C5C6BC
/* C5C6BC 80241F7C 0280202D */  daddu     $a0, $s4, $zero
/* C5C6C0 80241F80 0200282D */  daddu     $a1, $s0, $zero
/* C5C6C4 80241F84 0C0906C2 */  jal       func_80241B08_C5C248
/* C5C6C8 80241F88 0260302D */   daddu    $a2, $s3, $zero
/* C5C6CC 80241F8C 080907EA */  j         .L80241FA8
/* C5C6D0 80241F90 0000102D */   daddu    $v0, $zero, $zero
glabel L80241F94_C5C6D4
/* C5C6D4 80241F94 0280202D */  daddu     $a0, $s4, $zero
/* C5C6D8 80241F98 0200282D */  daddu     $a1, $s0, $zero
/* C5C6DC 80241F9C 0C090762 */  jal       func_80241D88_C5C4C8
/* C5C6E0 80241FA0 0260302D */   daddu    $a2, $s3, $zero
.L80241FA4:
glabel L80241FA4_C5C6E4
/* C5C6E4 80241FA4 0000102D */  daddu     $v0, $zero, $zero
.L80241FA8:
/* C5C6E8 80241FA8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C5C6EC 80241FAC 8FB50044 */  lw        $s5, 0x44($sp)
/* C5C6F0 80241FB0 8FB40040 */  lw        $s4, 0x40($sp)
/* C5C6F4 80241FB4 8FB3003C */  lw        $s3, 0x3c($sp)
/* C5C6F8 80241FB8 8FB20038 */  lw        $s2, 0x38($sp)
/* C5C6FC 80241FBC 8FB10034 */  lw        $s1, 0x34($sp)
/* C5C700 80241FC0 8FB00030 */  lw        $s0, 0x30($sp)
/* C5C704 80241FC4 03E00008 */  jr        $ra
/* C5C708 80241FC8 27BD0050 */   addiu    $sp, $sp, 0x50
