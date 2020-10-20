.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242CF0
/* E08050 80242CF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E08054 80242CF4 AFB10014 */  sw        $s1, 0x14($sp)
/* E08058 80242CF8 0080882D */  daddu     $s1, $a0, $zero
/* E0805C 80242CFC AFBF001C */  sw        $ra, 0x1c($sp)
/* E08060 80242D00 AFB20018 */  sw        $s2, 0x18($sp)
/* E08064 80242D04 AFB00010 */  sw        $s0, 0x10($sp)
/* E08068 80242D08 8E30000C */  lw        $s0, 0xc($s1)
/* E0806C 80242D0C 8E050000 */  lw        $a1, ($s0)
/* E08070 80242D10 0C0B1EAF */  jal       get_variable
/* E08074 80242D14 26100004 */   addiu    $s0, $s0, 4
/* E08078 80242D18 8E050000 */  lw        $a1, ($s0)
/* E0807C 80242D1C 26100004 */  addiu     $s0, $s0, 4
/* E08080 80242D20 0220202D */  daddu     $a0, $s1, $zero
/* E08084 80242D24 0C0B1EAF */  jal       get_variable
/* E08088 80242D28 0040902D */   daddu    $s2, $v0, $zero
/* E0808C 80242D2C 0220202D */  daddu     $a0, $s1, $zero
/* E08090 80242D30 8E050000 */  lw        $a1, ($s0)
/* E08094 80242D34 0C0B1EAF */  jal       get_variable
/* E08098 80242D38 0040802D */   daddu    $s0, $v0, $zero
/* E0809C 80242D3C 0040882D */  daddu     $s1, $v0, $zero
/* E080A0 80242D40 2402FFFF */  addiu     $v0, $zero, -1
/* E080A4 80242D44 16020005 */  bne       $s0, $v0, .L80242D5C
/* E080A8 80242D48 24020001 */   addiu    $v0, $zero, 1
/* E080AC 80242D4C 0C04760B */  jal       func_8011D82C
/* E080B0 80242D50 0220202D */   daddu    $a0, $s1, $zero
/* E080B4 80242D54 08090B7F */  j         .L80242DFC
/* E080B8 80242D58 24020002 */   addiu    $v0, $zero, 2
.L80242D5C:
/* E080BC 80242D5C 12420018 */  beq       $s2, $v0, .L80242DC0
/* E080C0 80242D60 2A420002 */   slti     $v0, $s2, 2
/* E080C4 80242D64 10400005 */  beqz      $v0, .L80242D7C
/* E080C8 80242D68 24020002 */   addiu    $v0, $zero, 2
/* E080CC 80242D6C 12400007 */  beqz      $s2, .L80242D8C
/* E080D0 80242D70 3412FFFF */   ori      $s2, $zero, 0xffff
/* E080D4 80242D74 08090B7F */  j         .L80242DFC
/* E080D8 80242D78 00000000 */   nop      
.L80242D7C:
/* E080DC 80242D7C 1242001B */  beq       $s2, $v0, .L80242DEC
/* E080E0 80242D80 24020002 */   addiu    $v0, $zero, 2
/* E080E4 80242D84 08090B7F */  j         .L80242DFC
/* E080E8 80242D88 00000000 */   nop      
.L80242D8C:
/* E080EC 80242D8C 8E040000 */  lw        $a0, ($s0)
/* E080F0 80242D90 1092001A */  beq       $a0, $s2, .L80242DFC
/* E080F4 80242D94 24020002 */   addiu    $v0, $zero, 2
/* E080F8 80242D98 0C046C04 */  jal       get_model_list_index_from_tree_index
/* E080FC 80242D9C 26100004 */   addiu    $s0, $s0, 4
/* E08100 80242DA0 0C046B4C */  jal       get_model_from_list_index
/* E08104 80242DA4 0040202D */   daddu    $a0, $v0, $zero
/* E08108 80242DA8 0040202D */  daddu     $a0, $v0, $zero
/* E0810C 80242DAC 2405FFFF */  addiu     $a1, $zero, -1
/* E08110 80242DB0 0C046F1F */  jal       func_8011BC7C
/* E08114 80242DB4 0220302D */   daddu    $a2, $s1, $zero
/* E08118 80242DB8 08090B63 */  j         .L80242D8C
/* E0811C 80242DBC 00000000 */   nop      
.L80242DC0:
/* E08120 80242DC0 3412FFFF */  ori       $s2, $zero, 0xffff
.L80242DC4:
/* E08124 80242DC4 8E020000 */  lw        $v0, ($s0)
/* E08128 80242DC8 1052000B */  beq       $v0, $s2, .L80242DF8
/* E0812C 80242DCC 2405FFFF */   addiu    $a1, $zero, -1
/* E08130 80242DD0 96040002 */  lhu       $a0, 2($s0)
/* E08134 80242DD4 0220302D */  daddu     $a2, $s1, $zero
/* E08138 80242DD8 26100004 */  addiu     $s0, $s0, 4
/* E0813C 80242DDC 0C046E54 */  jal       func_8011B950
/* E08140 80242DE0 0000382D */   daddu    $a3, $zero, $zero
/* E08144 80242DE4 08090B71 */  j         .L80242DC4
/* E08148 80242DE8 00000000 */   nop      
.L80242DEC:
/* E0814C 80242DEC 3C028015 */  lui       $v0, 0x8015
/* E08150 80242DF0 8C4212F0 */  lw        $v0, 0x12f0($v0)
/* E08154 80242DF4 A0510000 */  sb        $s1, ($v0)
.L80242DF8:
/* E08158 80242DF8 24020002 */  addiu     $v0, $zero, 2
.L80242DFC:
/* E0815C 80242DFC 8FBF001C */  lw        $ra, 0x1c($sp)
/* E08160 80242E00 8FB20018 */  lw        $s2, 0x18($sp)
/* E08164 80242E04 8FB10014 */  lw        $s1, 0x14($sp)
/* E08168 80242E08 8FB00010 */  lw        $s0, 0x10($sp)
/* E0816C 80242E0C 03E00008 */  jr        $ra
/* E08170 80242E10 27BD0020 */   addiu    $sp, $sp, 0x20
