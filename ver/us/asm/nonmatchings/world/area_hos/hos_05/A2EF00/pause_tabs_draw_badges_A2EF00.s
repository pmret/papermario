.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hos_05_UnkFunc27
/* A2EF00 80244CC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A2EF04 80244CC4 AFB10014 */  sw        $s1, 0x14($sp)
/* A2EF08 80244CC8 0080882D */  daddu     $s1, $a0, $zero
/* A2EF0C 80244CCC AFBF001C */  sw        $ra, 0x1c($sp)
/* A2EF10 80244CD0 AFB20018 */  sw        $s2, 0x18($sp)
/* A2EF14 80244CD4 AFB00010 */  sw        $s0, 0x10($sp)
/* A2EF18 80244CD8 8E30000C */  lw        $s0, 0xc($s1)
/* A2EF1C 80244CDC 8E050000 */  lw        $a1, ($s0)
/* A2EF20 80244CE0 0C0B1EAF */  jal       get_variable
/* A2EF24 80244CE4 26100004 */   addiu    $s0, $s0, 4
/* A2EF28 80244CE8 8E050000 */  lw        $a1, ($s0)
/* A2EF2C 80244CEC 26100004 */  addiu     $s0, $s0, 4
/* A2EF30 80244CF0 0220202D */  daddu     $a0, $s1, $zero
/* A2EF34 80244CF4 0C0B1EAF */  jal       get_variable
/* A2EF38 80244CF8 0040902D */   daddu    $s2, $v0, $zero
/* A2EF3C 80244CFC 0220202D */  daddu     $a0, $s1, $zero
/* A2EF40 80244D00 8E050000 */  lw        $a1, ($s0)
/* A2EF44 80244D04 0C0B1EAF */  jal       get_variable
/* A2EF48 80244D08 0040802D */   daddu    $s0, $v0, $zero
/* A2EF4C 80244D0C 0040882D */  daddu     $s1, $v0, $zero
/* A2EF50 80244D10 2402FFFF */  addiu     $v0, $zero, -1
/* A2EF54 80244D14 16020005 */  bne       $s0, $v0, .L80244D2C
/* A2EF58 80244D18 24020001 */   addiu    $v0, $zero, 1
/* A2EF5C 80244D1C 0C04760B */  jal       func_8011D82C
/* A2EF60 80244D20 0220202D */   daddu    $a0, $s1, $zero
/* A2EF64 80244D24 08091373 */  j         .L80244DCC
/* A2EF68 80244D28 24020002 */   addiu    $v0, $zero, 2
.L80244D2C:
/* A2EF6C 80244D2C 12420018 */  beq       $s2, $v0, .L80244D90
/* A2EF70 80244D30 2A420002 */   slti     $v0, $s2, 2
/* A2EF74 80244D34 10400005 */  beqz      $v0, .L80244D4C
/* A2EF78 80244D38 24020002 */   addiu    $v0, $zero, 2
/* A2EF7C 80244D3C 12400007 */  beqz      $s2, .L80244D5C
/* A2EF80 80244D40 3412FFFF */   ori      $s2, $zero, 0xffff
/* A2EF84 80244D44 08091373 */  j         .L80244DCC
/* A2EF88 80244D48 00000000 */   nop
.L80244D4C:
/* A2EF8C 80244D4C 1242001B */  beq       $s2, $v0, .L80244DBC
/* A2EF90 80244D50 24020002 */   addiu    $v0, $zero, 2
/* A2EF94 80244D54 08091373 */  j         .L80244DCC
/* A2EF98 80244D58 00000000 */   nop
.L80244D5C:
/* A2EF9C 80244D5C 8E040000 */  lw        $a0, ($s0)
/* A2EFA0 80244D60 1092001A */  beq       $a0, $s2, .L80244DCC
/* A2EFA4 80244D64 24020002 */   addiu    $v0, $zero, 2
/* A2EFA8 80244D68 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A2EFAC 80244D6C 26100004 */   addiu    $s0, $s0, 4
/* A2EFB0 80244D70 0C046B4C */  jal       get_model_from_list_index
/* A2EFB4 80244D74 0040202D */   daddu    $a0, $v0, $zero
/* A2EFB8 80244D78 0040202D */  daddu     $a0, $v0, $zero
/* A2EFBC 80244D7C 2405FFFF */  addiu     $a1, $zero, -1
/* A2EFC0 80244D80 0C046F1F */  jal       func_8011BC7C
/* A2EFC4 80244D84 0220302D */   daddu    $a2, $s1, $zero
/* A2EFC8 80244D88 08091357 */  j         .L80244D5C
/* A2EFCC 80244D8C 00000000 */   nop
.L80244D90:
/* A2EFD0 80244D90 3412FFFF */  ori       $s2, $zero, 0xffff
.L80244D94:
/* A2EFD4 80244D94 8E020000 */  lw        $v0, ($s0)
/* A2EFD8 80244D98 1052000B */  beq       $v0, $s2, .L80244DC8
/* A2EFDC 80244D9C 2405FFFF */   addiu    $a1, $zero, -1
/* A2EFE0 80244DA0 96040002 */  lhu       $a0, 2($s0)
/* A2EFE4 80244DA4 0220302D */  daddu     $a2, $s1, $zero
/* A2EFE8 80244DA8 26100004 */  addiu     $s0, $s0, 4
/* A2EFEC 80244DAC 0C046E54 */  jal       func_8011B950
/* A2EFF0 80244DB0 0000382D */   daddu    $a3, $zero, $zero
/* A2EFF4 80244DB4 08091365 */  j         .L80244D94
/* A2EFF8 80244DB8 00000000 */   nop
.L80244DBC:
/* A2EFFC 80244DBC 3C028015 */  lui       $v0, %hi(D_801512F0)
/* A2F000 80244DC0 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* A2F004 80244DC4 A0510000 */  sb        $s1, ($v0)
.L80244DC8:
/* A2F008 80244DC8 24020002 */  addiu     $v0, $zero, 2
.L80244DCC:
/* A2F00C 80244DCC 8FBF001C */  lw        $ra, 0x1c($sp)
/* A2F010 80244DD0 8FB20018 */  lw        $s2, 0x18($sp)
/* A2F014 80244DD4 8FB10014 */  lw        $s1, 0x14($sp)
/* A2F018 80244DD8 8FB00010 */  lw        $s0, 0x10($sp)
/* A2F01C 80244DDC 03E00008 */  jr        $ra
/* A2F020 80244DE0 27BD0020 */   addiu    $sp, $sp, 0x20
