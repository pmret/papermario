.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AE0_9F6520
/* 9F6520 80241AE0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9F6524 80241AE4 AFB40040 */  sw        $s4, 0x40($sp)
/* 9F6528 80241AE8 0080A02D */  daddu     $s4, $a0, $zero
/* 9F652C 80241AEC AFBF0048 */  sw        $ra, 0x48($sp)
/* 9F6530 80241AF0 AFB50044 */  sw        $s5, 0x44($sp)
/* 9F6534 80241AF4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9F6538 80241AF8 AFB20038 */  sw        $s2, 0x38($sp)
/* 9F653C 80241AFC AFB10034 */  sw        $s1, 0x34($sp)
/* 9F6540 80241B00 AFB00030 */  sw        $s0, 0x30($sp)
/* 9F6544 80241B04 8E920148 */  lw        $s2, 0x148($s4)
/* 9F6548 80241B08 86440008 */  lh        $a0, 8($s2)
/* 9F654C 80241B0C 8E90000C */  lw        $s0, 0xc($s4)
/* 9F6550 80241B10 0C00EABB */  jal       get_npc_unsafe
/* 9F6554 80241B14 00A0882D */   daddu    $s1, $a1, $zero
/* 9F6558 80241B18 0280202D */  daddu     $a0, $s4, $zero
/* 9F655C 80241B1C 8E050000 */  lw        $a1, ($s0)
/* 9F6560 80241B20 0C0B1EAF */  jal       get_variable
/* 9F6564 80241B24 0040A82D */   daddu    $s5, $v0, $zero
/* 9F6568 80241B28 AFA00010 */  sw        $zero, 0x10($sp)
/* 9F656C 80241B2C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9F6570 80241B30 8C630030 */  lw        $v1, 0x30($v1)
/* 9F6574 80241B34 AFA30014 */  sw        $v1, 0x14($sp)
/* 9F6578 80241B38 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9F657C 80241B3C 8C63001C */  lw        $v1, 0x1c($v1)
/* 9F6580 80241B40 AFA30018 */  sw        $v1, 0x18($sp)
/* 9F6584 80241B44 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9F6588 80241B48 8C630024 */  lw        $v1, 0x24($v1)
/* 9F658C 80241B4C AFA3001C */  sw        $v1, 0x1c($sp)
/* 9F6590 80241B50 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9F6594 80241B54 8C630028 */  lw        $v1, 0x28($v1)
/* 9F6598 80241B58 27B30010 */  addiu     $s3, $sp, 0x10
/* 9F659C 80241B5C AFA30020 */  sw        $v1, 0x20($sp)
/* 9F65A0 80241B60 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 9F65A4 80241B64 3C0142F0 */  lui       $at, 0x42f0
/* 9F65A8 80241B68 44810000 */  mtc1      $at, $f0
/* 9F65AC 80241B6C 8C63002C */  lw        $v1, 0x2c($v1)
/* 9F65B0 80241B70 0040802D */  daddu     $s0, $v0, $zero
/* 9F65B4 80241B74 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9F65B8 80241B78 A7A0002C */  sh        $zero, 0x2c($sp)
/* 9F65BC 80241B7C 12200006 */  beqz      $s1, .L80241B98
/* 9F65C0 80241B80 AFA30024 */   sw       $v1, 0x24($sp)
/* 9F65C4 80241B84 02A0202D */  daddu     $a0, $s5, $zero
/* 9F65C8 80241B88 0240282D */  daddu     $a1, $s2, $zero
/* 9F65CC 80241B8C 0280302D */  daddu     $a2, $s4, $zero
/* 9F65D0 80241B90 0C09066F */  jal       nok_11_UnkFunc5
/* 9F65D4 80241B94 0200382D */   daddu    $a3, $s0, $zero
.L80241B98:
/* 9F65D8 80241B98 2402FFFE */  addiu     $v0, $zero, -2
/* 9F65DC 80241B9C A2A200AB */  sb        $v0, 0xab($s5)
/* 9F65E0 80241BA0 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 9F65E4 80241BA4 30620004 */  andi      $v0, $v1, 4
/* 9F65E8 80241BA8 10400007 */  beqz      $v0, .L80241BC8
/* 9F65EC 80241BAC 00000000 */   nop
/* 9F65F0 80241BB0 824200B4 */  lb        $v0, 0xb4($s2)
/* 9F65F4 80241BB4 1440003C */  bnez      $v0, .L80241CA8
/* 9F65F8 80241BB8 0000102D */   daddu    $v0, $zero, $zero
/* 9F65FC 80241BBC 2402FFFB */  addiu     $v0, $zero, -5
/* 9F6600 80241BC0 00621024 */  and       $v0, $v1, $v0
/* 9F6604 80241BC4 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241BC8:
/* 9F6608 80241BC8 8E830070 */  lw        $v1, 0x70($s4)
/* 9F660C 80241BCC 2C62000F */  sltiu     $v0, $v1, 0xf
/* 9F6610 80241BD0 10400034 */  beqz      $v0, L80241CA4_9F66E4
/* 9F6614 80241BD4 00031080 */   sll      $v0, $v1, 2
/* 9F6618 80241BD8 3C018024 */  lui       $at, %hi(jtbl_80245D68_9FA7A8)
/* 9F661C 80241BDC 00220821 */  addu      $at, $at, $v0
/* 9F6620 80241BE0 8C225D68 */  lw        $v0, %lo(jtbl_80245D68_9FA7A8)($at)
/* 9F6624 80241BE4 00400008 */  jr        $v0
/* 9F6628 80241BE8 00000000 */   nop
glabel L80241BEC_9F662C
/* 9F662C 80241BEC 0280202D */  daddu     $a0, $s4, $zero
/* 9F6630 80241BF0 0200282D */  daddu     $a1, $s0, $zero
/* 9F6634 80241BF4 0C0901F5 */  jal       func_802407D4_9F5214
/* 9F6638 80241BF8 0260302D */   daddu    $a2, $s3, $zero
glabel L80241BFC_9F663C
/* 9F663C 80241BFC 0280202D */  daddu     $a0, $s4, $zero
/* 9F6640 80241C00 0200282D */  daddu     $a1, $s0, $zero
/* 9F6644 80241C04 0C090261 */  jal       func_80240984_9F53C4
/* 9F6648 80241C08 0260302D */   daddu    $a2, $s3, $zero
/* 9F664C 80241C0C 0809072A */  j         .L80241CA8
/* 9F6650 80241C10 0000102D */   daddu    $v0, $zero, $zero
glabel L80241C14_9F6654
/* 9F6654 80241C14 0280202D */  daddu     $a0, $s4, $zero
/* 9F6658 80241C18 0200282D */  daddu     $a1, $s0, $zero
/* 9F665C 80241C1C 0C0903EB */  jal       nok_11_UnkNpcAIFunc1
/* 9F6660 80241C20 0260302D */   daddu    $a2, $s3, $zero
glabel L80241C24_9F6664
/* 9F6664 80241C24 0280202D */  daddu     $a0, $s4, $zero
/* 9F6668 80241C28 0200282D */  daddu     $a1, $s0, $zero
/* 9F666C 80241C2C 0C09041B */  jal       nok_11_UnkFunc4
/* 9F6670 80241C30 0260302D */   daddu    $a2, $s3, $zero
/* 9F6674 80241C34 0809072A */  j         .L80241CA8
/* 9F6678 80241C38 0000102D */   daddu    $v0, $zero, $zero
glabel L80241C3C_9F667C
/* 9F667C 80241C3C 0280202D */  daddu     $a0, $s4, $zero
/* 9F6680 80241C40 0200282D */  daddu     $a1, $s0, $zero
/* 9F6684 80241C44 0C0904EC */  jal       nok_11_UnkNpcAIFunc2
/* 9F6688 80241C48 0260302D */   daddu    $a2, $s3, $zero
glabel L80241C4C_9F668C
/* 9F668C 80241C4C 0280202D */  daddu     $a0, $s4, $zero
/* 9F6690 80241C50 0200282D */  daddu     $a1, $s0, $zero
/* 9F6694 80241C54 0C09050A */  jal       func_80241428_9F5E68
/* 9F6698 80241C58 0260302D */   daddu    $a2, $s3, $zero
/* 9F669C 80241C5C 0809072A */  j         .L80241CA8
/* 9F66A0 80241C60 0000102D */   daddu    $v0, $zero, $zero
glabel L80241C64_9F66A4
/* 9F66A4 80241C64 0280202D */  daddu     $a0, $s4, $zero
/* 9F66A8 80241C68 0200282D */  daddu     $a1, $s0, $zero
/* 9F66AC 80241C6C 0C090525 */  jal       nok_11_UnkNpcAIFunc14
/* 9F66B0 80241C70 0260302D */   daddu    $a2, $s3, $zero
/* 9F66B4 80241C74 0809072A */  j         .L80241CA8
/* 9F66B8 80241C78 0000102D */   daddu    $v0, $zero, $zero
glabel L80241C7C_9F66BC
/* 9F66BC 80241C7C 0280202D */  daddu     $a0, $s4, $zero
/* 9F66C0 80241C80 0200282D */  daddu     $a1, $s0, $zero
/* 9F66C4 80241C84 0C090572 */  jal       nok_11_UnkNpcAIFunc3
/* 9F66C8 80241C88 0260302D */   daddu    $a2, $s3, $zero
/* 9F66CC 80241C8C 0809072A */  j         .L80241CA8
/* 9F66D0 80241C90 0000102D */   daddu    $v0, $zero, $zero
glabel L80241C94_9F66D4
/* 9F66D4 80241C94 0280202D */  daddu     $a0, $s4, $zero
/* 9F66D8 80241C98 0200282D */  daddu     $a1, $s0, $zero
/* 9F66DC 80241C9C 0C09058B */  jal       nok_11_UnkFunc6
/* 9F66E0 80241CA0 0260302D */   daddu    $a2, $s3, $zero
glabel L80241CA4_9F66E4
/* 9F66E4 80241CA4 0000102D */  daddu     $v0, $zero, $zero
.L80241CA8:
/* 9F66E8 80241CA8 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9F66EC 80241CAC 8FB50044 */  lw        $s5, 0x44($sp)
/* 9F66F0 80241CB0 8FB40040 */  lw        $s4, 0x40($sp)
/* 9F66F4 80241CB4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9F66F8 80241CB8 8FB20038 */  lw        $s2, 0x38($sp)
/* 9F66FC 80241CBC 8FB10034 */  lw        $s1, 0x34($sp)
/* 9F6700 80241CC0 8FB00030 */  lw        $s0, 0x30($sp)
/* 9F6704 80241CC4 03E00008 */  jr        $ra
/* 9F6708 80241CC8 27BD0050 */   addiu    $sp, $sp, 0x50
