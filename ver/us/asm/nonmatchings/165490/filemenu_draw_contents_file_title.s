.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_file_title
/* 165CAC 8024544C 3C028025 */  lui       $v0, %hi(D_8024C098_C09918)
/* 165CB0 80245450 8042C098 */  lb        $v0, %lo(D_8024C098_C09918)($v0)
/* 165CB4 80245454 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 165CB8 80245458 AFB10024 */  sw        $s1, 0x24($sp)
/* 165CBC 8024545C 0080882D */  daddu     $s1, $a0, $zero
/* 165CC0 80245460 AFB3002C */  sw        $s3, 0x2c($sp)
/* 165CC4 80245464 00C0982D */  daddu     $s3, $a2, $zero
/* 165CC8 80245468 AFB00020 */  sw        $s0, 0x20($sp)
/* 165CCC 8024546C 00E0802D */  daddu     $s0, $a3, $zero
/* 165CD0 80245470 AFBF0034 */  sw        $ra, 0x34($sp)
/* 165CD4 80245474 AFB40030 */  sw        $s4, 0x30($sp)
/* 165CD8 80245478 14400007 */  bnez      $v0, .L80245498
/* 165CDC 8024547C AFB20028 */   sw       $s2, 0x28($sp)
/* 165CE0 80245480 90A20003 */  lbu       $v0, 3($a1)
/* 165CE4 80245484 14510004 */  bne       $v0, $s1, .L80245498
/* 165CE8 80245488 2624003C */   addiu    $a0, $s1, 0x3c
/* 165CEC 8024548C 2665FFFD */  addiu     $a1, $s3, -3
/* 165CF0 80245490 0C090B80 */  jal       filemenu_set_cursor_goal_pos
/* 165CF4 80245494 26060008 */   addiu    $a2, $s0, 8
.L80245498:
/* 165CF8 80245498 0C0926A9 */  jal       filemenu_get_menu_message
/* 165CFC 8024549C 2404001A */   addiu    $a0, $zero, 0x1a
/* 165D00 802454A0 0040202D */  daddu     $a0, $v0, $zero
/* 165D04 802454A4 26650005 */  addiu     $a1, $s3, 5
/* 165D08 802454A8 26120001 */  addiu     $s2, $s0, 1
/* 165D0C 802454AC 0240302D */  daddu     $a2, $s2, $zero
/* 165D10 802454B0 240700FF */  addiu     $a3, $zero, 0xff
/* 165D14 802454B4 24140001 */  addiu     $s4, $zero, 1
/* 165D18 802454B8 AFA00010 */  sw        $zero, 0x10($sp)
/* 165D1C 802454BC 0C09265F */  jal       filemenu_draw_message
/* 165D20 802454C0 AFB40014 */   sw       $s4, 0x14($sp)
/* 165D24 802454C4 3C028007 */  lui       $v0, %hi(D_80077A24)
/* 165D28 802454C8 00511021 */  addu      $v0, $v0, $s1
/* 165D2C 802454CC 90427A24 */  lbu       $v0, %lo(D_80077A24)($v0)
/* 165D30 802454D0 1440000D */  bnez      $v0, .L80245508
/* 165D34 802454D4 26240001 */   addiu    $a0, $s1, 1
/* 165D38 802454D8 02342021 */  addu      $a0, $s1, $s4
/* 165D3C 802454DC 26650021 */  addiu     $a1, $s3, 0x21
/* 165D40 802454E0 0240302D */  daddu     $a2, $s2, $zero
/* 165D44 802454E4 0280382D */  daddu     $a3, $s4, $zero
/* 165D48 802454E8 240200FF */  addiu     $v0, $zero, 0xff
/* 165D4C 802454EC AFA20014 */  sw        $v0, 0x14($sp)
/* 165D50 802454F0 24020002 */  addiu     $v0, $zero, 2
/* 165D54 802454F4 AFA00010 */  sw        $zero, 0x10($sp)
/* 165D58 802454F8 0C049DA7 */  jal       draw_number
/* 165D5C 802454FC AFA20018 */   sw       $v0, 0x18($sp)
/* 165D60 80245500 0809155A */  j         .L80245568
/* 165D64 80245504 00000000 */   nop
.L80245508:
/* 165D68 80245508 26650021 */  addiu     $a1, $s3, 0x21
/* 165D6C 8024550C 0240302D */  daddu     $a2, $s2, $zero
/* 165D70 80245510 24070001 */  addiu     $a3, $zero, 1
/* 165D74 80245514 241000FF */  addiu     $s0, $zero, 0xff
/* 165D78 80245518 24020002 */  addiu     $v0, $zero, 2
/* 165D7C 8024551C AFA00010 */  sw        $zero, 0x10($sp)
/* 165D80 80245520 AFB00014 */  sw        $s0, 0x14($sp)
/* 165D84 80245524 0C049DA7 */  jal       draw_number
/* 165D88 80245528 AFA20018 */   sw       $v0, 0x18($sp)
/* 165D8C 8024552C 00112040 */  sll       $a0, $s1, 1
/* 165D90 80245530 00912021 */  addu      $a0, $a0, $s1
/* 165D94 80245534 000420C0 */  sll       $a0, $a0, 3
/* 165D98 80245538 3C028007 */  lui       $v0, %hi(D_800779CB)
/* 165D9C 8024553C 244279CB */  addiu     $v0, $v0, %lo(D_800779CB)
/* 165DA0 80245540 00822021 */  addu      $a0, $a0, $v0
/* 165DA4 80245544 24050008 */  addiu     $a1, $zero, 8
/* 165DA8 80245548 2666002E */  addiu     $a2, $s3, 0x2e
/* 165DAC 8024554C 0240382D */  daddu     $a3, $s2, $zero
/* 165DB0 80245550 24020009 */  addiu     $v0, $zero, 9
/* 165DB4 80245554 AFB00010 */  sw        $s0, 0x10($sp)
/* 165DB8 80245558 AFA00014 */  sw        $zero, 0x14($sp)
/* 165DBC 8024555C AFB40018 */  sw        $s4, 0x18($sp)
/* 165DC0 80245560 0C0926AE */  jal       filemenu_draw_file_name
/* 165DC4 80245564 AFA2001C */   sw       $v0, 0x1c($sp)
.L80245568:
/* 165DC8 80245568 8FBF0034 */  lw        $ra, 0x34($sp)
/* 165DCC 8024556C 8FB40030 */  lw        $s4, 0x30($sp)
/* 165DD0 80245570 8FB3002C */  lw        $s3, 0x2c($sp)
/* 165DD4 80245574 8FB20028 */  lw        $s2, 0x28($sp)
/* 165DD8 80245578 8FB10024 */  lw        $s1, 0x24($sp)
/* 165DDC 8024557C 8FB00020 */  lw        $s0, 0x20($sp)
/* 165DE0 80245580 03E00008 */  jr        $ra
/* 165DE4 80245584 27BD0038 */   addiu    $sp, $sp, 0x38
