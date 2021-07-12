.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802430A8_C713D8
.word L80241C38_C6FF68, L80241C48_C6FF78, L80241C60_C6FF90, L80241C70_C6FFA0, L80241CF0_C70020, L80241CF0_C70020, L80241CF0_C70020, L80241CF0_C70020, L80241CF0_C70020, L80241CF0_C70020, L80241C88_C6FFB8, L80241C98_C6FFC8, L80241CB0_C6FFE0, L80241CC8_C6FFF8, L80241CE0_C70010, 0

.section .text

glabel func_80241B2C_C6FE5C
/* C6FE5C 80241B2C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C6FE60 80241B30 AFB40040 */  sw        $s4, 0x40($sp)
/* C6FE64 80241B34 0080A02D */  daddu     $s4, $a0, $zero
/* C6FE68 80241B38 AFBF0048 */  sw        $ra, 0x48($sp)
/* C6FE6C 80241B3C AFB50044 */  sw        $s5, 0x44($sp)
/* C6FE70 80241B40 AFB3003C */  sw        $s3, 0x3c($sp)
/* C6FE74 80241B44 AFB20038 */  sw        $s2, 0x38($sp)
/* C6FE78 80241B48 AFB10034 */  sw        $s1, 0x34($sp)
/* C6FE7C 80241B4C AFB00030 */  sw        $s0, 0x30($sp)
/* C6FE80 80241B50 8E920148 */  lw        $s2, 0x148($s4)
/* C6FE84 80241B54 86440008 */  lh        $a0, 8($s2)
/* C6FE88 80241B58 8E90000C */  lw        $s0, 0xc($s4)
/* C6FE8C 80241B5C 0C00EABB */  jal       get_npc_unsafe
/* C6FE90 80241B60 00A0882D */   daddu    $s1, $a1, $zero
/* C6FE94 80241B64 0280202D */  daddu     $a0, $s4, $zero
/* C6FE98 80241B68 8E050000 */  lw        $a1, ($s0)
/* C6FE9C 80241B6C 0C0B1EAF */  jal       get_variable
/* C6FEA0 80241B70 0040A82D */   daddu    $s5, $v0, $zero
/* C6FEA4 80241B74 AFA00010 */  sw        $zero, 0x10($sp)
/* C6FEA8 80241B78 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C6FEAC 80241B7C 8C630030 */  lw        $v1, 0x30($v1)
/* C6FEB0 80241B80 AFA30014 */  sw        $v1, 0x14($sp)
/* C6FEB4 80241B84 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C6FEB8 80241B88 8C63001C */  lw        $v1, 0x1c($v1)
/* C6FEBC 80241B8C AFA30018 */  sw        $v1, 0x18($sp)
/* C6FEC0 80241B90 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C6FEC4 80241B94 8C630024 */  lw        $v1, 0x24($v1)
/* C6FEC8 80241B98 AFA3001C */  sw        $v1, 0x1c($sp)
/* C6FECC 80241B9C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C6FED0 80241BA0 8C630028 */  lw        $v1, 0x28($v1)
/* C6FED4 80241BA4 27B30010 */  addiu     $s3, $sp, 0x10
/* C6FED8 80241BA8 AFA30020 */  sw        $v1, 0x20($sp)
/* C6FEDC 80241BAC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C6FEE0 80241BB0 3C0142F0 */  lui       $at, 0x42f0
/* C6FEE4 80241BB4 44810000 */  mtc1      $at, $f0
/* C6FEE8 80241BB8 8C63002C */  lw        $v1, 0x2c($v1)
/* C6FEEC 80241BBC 0040802D */  daddu     $s0, $v0, $zero
/* C6FEF0 80241BC0 E7A00028 */  swc1      $f0, 0x28($sp)
/* C6FEF4 80241BC4 A7A0002C */  sh        $zero, 0x2c($sp)
/* C6FEF8 80241BC8 12200006 */  beqz      $s1, .L80241BE4
/* C6FEFC 80241BCC AFA30024 */   sw       $v1, 0x24($sp)
/* C6FF00 80241BD0 02A0202D */  daddu     $a0, $s5, $zero
/* C6FF04 80241BD4 0240282D */  daddu     $a1, $s2, $zero
/* C6FF08 80241BD8 0280302D */  daddu     $a2, $s4, $zero
/* C6FF0C 80241BDC 0C090682 */  jal       kzn_07_UnkFunc5
/* C6FF10 80241BE0 0200382D */   daddu    $a3, $s0, $zero
.L80241BE4:
/* C6FF14 80241BE4 2402FFFE */  addiu     $v0, $zero, -2
/* C6FF18 80241BE8 A2A200AB */  sb        $v0, 0xab($s5)
/* C6FF1C 80241BEC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C6FF20 80241BF0 30620004 */  andi      $v0, $v1, 4
/* C6FF24 80241BF4 10400007 */  beqz      $v0, .L80241C14
/* C6FF28 80241BF8 00000000 */   nop
/* C6FF2C 80241BFC 824200B4 */  lb        $v0, 0xb4($s2)
/* C6FF30 80241C00 1440003C */  bnez      $v0, .L80241CF4
/* C6FF34 80241C04 0000102D */   daddu    $v0, $zero, $zero
/* C6FF38 80241C08 2402FFFB */  addiu     $v0, $zero, -5
/* C6FF3C 80241C0C 00621024 */  and       $v0, $v1, $v0
/* C6FF40 80241C10 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241C14:
/* C6FF44 80241C14 8E830070 */  lw        $v1, 0x70($s4)
/* C6FF48 80241C18 2C62000F */  sltiu     $v0, $v1, 0xf
/* C6FF4C 80241C1C 10400034 */  beqz      $v0, L80241CF0_C70020
/* C6FF50 80241C20 00031080 */   sll      $v0, $v1, 2
/* C6FF54 80241C24 3C018024 */  lui       $at, %hi(jtbl_802430A8_C713D8)
/* C6FF58 80241C28 00220821 */  addu      $at, $at, $v0
/* C6FF5C 80241C2C 8C2230A8 */  lw        $v0, %lo(jtbl_802430A8_C713D8)($at)
/* C6FF60 80241C30 00400008 */  jr        $v0
/* C6FF64 80241C34 00000000 */   nop
glabel L80241C38_C6FF68
/* C6FF68 80241C38 0280202D */  daddu     $a0, $s4, $zero
/* C6FF6C 80241C3C 0200282D */  daddu     $a1, $s0, $zero
/* C6FF70 80241C40 0C090208 */  jal       kzn_07_UnkNpcAIFunc23
/* C6FF74 80241C44 0260302D */   daddu    $a2, $s3, $zero
glabel L80241C48_C6FF78
/* C6FF78 80241C48 0280202D */  daddu     $a0, $s4, $zero
/* C6FF7C 80241C4C 0200282D */  daddu     $a1, $s0, $zero
/* C6FF80 80241C50 0C090274 */  jal       func_802409D0_C6ED00
/* C6FF84 80241C54 0260302D */   daddu    $a2, $s3, $zero
/* C6FF88 80241C58 0809073D */  j         .L80241CF4
/* C6FF8C 80241C5C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241C60_C6FF90
/* C6FF90 80241C60 0280202D */  daddu     $a0, $s4, $zero
/* C6FF94 80241C64 0200282D */  daddu     $a1, $s0, $zero
/* C6FF98 80241C68 0C0903FE */  jal       kzn_07_UnkNpcAIFunc1
/* C6FF9C 80241C6C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241C70_C6FFA0
/* C6FFA0 80241C70 0280202D */  daddu     $a0, $s4, $zero
/* C6FFA4 80241C74 0200282D */  daddu     $a1, $s0, $zero
/* C6FFA8 80241C78 0C09042E */  jal       kzn_07_UnkFunc4
/* C6FFAC 80241C7C 0260302D */   daddu    $a2, $s3, $zero
/* C6FFB0 80241C80 0809073D */  j         .L80241CF4
/* C6FFB4 80241C84 0000102D */   daddu    $v0, $zero, $zero
glabel L80241C88_C6FFB8
/* C6FFB8 80241C88 0280202D */  daddu     $a0, $s4, $zero
/* C6FFBC 80241C8C 0200282D */  daddu     $a1, $s0, $zero
/* C6FFC0 80241C90 0C0904FF */  jal       kzn_07_UnkNpcAIFunc2
/* C6FFC4 80241C94 0260302D */   daddu    $a2, $s3, $zero
glabel L80241C98_C6FFC8
/* C6FFC8 80241C98 0280202D */  daddu     $a0, $s4, $zero
/* C6FFCC 80241C9C 0200282D */  daddu     $a1, $s0, $zero
/* C6FFD0 80241CA0 0C09051D */  jal       func_80241474_C6F7A4
/* C6FFD4 80241CA4 0260302D */   daddu    $a2, $s3, $zero
/* C6FFD8 80241CA8 0809073D */  j         .L80241CF4
/* C6FFDC 80241CAC 0000102D */   daddu    $v0, $zero, $zero
glabel L80241CB0_C6FFE0
/* C6FFE0 80241CB0 0280202D */  daddu     $a0, $s4, $zero
/* C6FFE4 80241CB4 0200282D */  daddu     $a1, $s0, $zero
/* C6FFE8 80241CB8 0C090538 */  jal       kzn_07_UnkNpcAIFunc14
/* C6FFEC 80241CBC 0260302D */   daddu    $a2, $s3, $zero
/* C6FFF0 80241CC0 0809073D */  j         .L80241CF4
/* C6FFF4 80241CC4 0000102D */   daddu    $v0, $zero, $zero
glabel L80241CC8_C6FFF8
/* C6FFF8 80241CC8 0280202D */  daddu     $a0, $s4, $zero
/* C6FFFC 80241CCC 0200282D */  daddu     $a1, $s0, $zero
/* C70000 80241CD0 0C090585 */  jal       kzn_07_UnkNpcAIFunc3
/* C70004 80241CD4 0260302D */   daddu    $a2, $s3, $zero
/* C70008 80241CD8 0809073D */  j         .L80241CF4
/* C7000C 80241CDC 0000102D */   daddu    $v0, $zero, $zero
glabel L80241CE0_C70010
/* C70010 80241CE0 0280202D */  daddu     $a0, $s4, $zero
/* C70014 80241CE4 0200282D */  daddu     $a1, $s0, $zero
/* C70018 80241CE8 0C09059E */  jal       kzn_07_UnkFunc6
/* C7001C 80241CEC 0260302D */   daddu    $a2, $s3, $zero
glabel L80241CF0_C70020
/* C70020 80241CF0 0000102D */  daddu     $v0, $zero, $zero
.L80241CF4:
/* C70024 80241CF4 8FBF0048 */  lw        $ra, 0x48($sp)
/* C70028 80241CF8 8FB50044 */  lw        $s5, 0x44($sp)
/* C7002C 80241CFC 8FB40040 */  lw        $s4, 0x40($sp)
/* C70030 80241D00 8FB3003C */  lw        $s3, 0x3c($sp)
/* C70034 80241D04 8FB20038 */  lw        $s2, 0x38($sp)
/* C70038 80241D08 8FB10034 */  lw        $s1, 0x34($sp)
/* C7003C 80241D0C 8FB00030 */  lw        $s0, 0x30($sp)
/* C70040 80241D10 03E00008 */  jr        $ra
/* C70044 80241D14 27BD0050 */   addiu    $sp, $sp, 0x50
