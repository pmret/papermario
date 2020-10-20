.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240348_C717C8
/* C717C8 80240348 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C717CC 8024034C AFBF001C */  sw        $ra, 0x1c($sp)
/* C717D0 80240350 AFB20018 */  sw        $s2, 0x18($sp)
/* C717D4 80240354 AFB10014 */  sw        $s1, 0x14($sp)
/* C717D8 80240358 AFB00010 */  sw        $s0, 0x10($sp)
/* C717DC 8024035C 8C82000C */  lw        $v0, 0xc($a0)
/* C717E0 80240360 0C0B1EAF */  jal       get_variable
/* C717E4 80240364 8C450000 */   lw       $a1, ($v0)
/* C717E8 80240368 0040902D */  daddu     $s2, $v0, $zero
/* C717EC 8024036C 12400013 */  beqz      $s2, .L802403BC
/* C717F0 80240370 26510002 */   addiu    $s1, $s2, 2
/* C717F4 80240374 96420000 */  lhu       $v0, ($s2)
/* C717F8 80240378 1040001D */  beqz      $v0, .L802403F0
/* C717FC 8024037C 0000802D */   daddu    $s0, $zero, $zero
.L80240380:
/* C71800 80240380 96240000 */  lhu       $a0, ($s1)
/* C71804 80240384 0C046C04 */  jal       get_model_list_index_from_tree_index
/* C71808 80240388 26100001 */   addiu    $s0, $s0, 1
/* C7180C 8024038C 0C046B4C */  jal       get_model_from_list_index
/* C71810 80240390 0040202D */   daddu    $a0, $v0, $zero
/* C71814 80240394 0040202D */  daddu     $a0, $v0, $zero
/* C71818 80240398 2405FFFF */  addiu     $a1, $zero, -1
/* C7181C 8024039C 0C046F1F */  jal       func_8011BC7C
/* C71820 802403A0 0000302D */   daddu    $a2, $zero, $zero
/* C71824 802403A4 96420000 */  lhu       $v0, ($s2)
/* C71828 802403A8 0202102A */  slt       $v0, $s0, $v0
/* C7182C 802403AC 1440FFF4 */  bnez      $v0, .L80240380
/* C71830 802403B0 26310002 */   addiu    $s1, $s1, 2
/* C71834 802403B4 080900FC */  j         .L802403F0
/* C71838 802403B8 00000000 */   nop      
.L802403BC:
/* C7183C 802403BC 3C118015 */  lui       $s1, %hi(gCurrentModelListPtr)
/* C71840 802403C0 8E3112CC */  lw        $s1, %lo(gCurrentModelListPtr)($s1)
/* C71844 802403C4 0000802D */  daddu     $s0, $zero, $zero
.L802403C8:
/* C71848 802403C8 8E240000 */  lw        $a0, ($s1)
/* C7184C 802403CC 50800005 */  beql      $a0, $zero, .L802403E4
/* C71850 802403D0 26100001 */   addiu    $s0, $s0, 1
/* C71854 802403D4 2405FFFF */  addiu     $a1, $zero, -1
/* C71858 802403D8 0C046F1F */  jal       func_8011BC7C
/* C7185C 802403DC 0000302D */   daddu    $a2, $zero, $zero
/* C71860 802403E0 26100001 */  addiu     $s0, $s0, 1
.L802403E4:
/* C71864 802403E4 2A020100 */  slti      $v0, $s0, 0x100
/* C71868 802403E8 1440FFF7 */  bnez      $v0, .L802403C8
/* C7186C 802403EC 26310004 */   addiu    $s1, $s1, 4
.L802403F0:
/* C71870 802403F0 8FBF001C */  lw        $ra, 0x1c($sp)
/* C71874 802403F4 8FB20018 */  lw        $s2, 0x18($sp)
/* C71878 802403F8 8FB10014 */  lw        $s1, 0x14($sp)
/* C7187C 802403FC 8FB00010 */  lw        $s0, 0x10($sp)
/* C71880 80240400 24020002 */  addiu     $v0, $zero, 2
/* C71884 80240404 03E00008 */  jr        $ra
/* C71888 80240408 27BD0020 */   addiu    $sp, $sp, 0x20
