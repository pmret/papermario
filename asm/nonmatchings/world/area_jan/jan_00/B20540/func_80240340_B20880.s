.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_B20880
/* B20880 80240340 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B20884 80240344 AFBF0020 */  sw        $ra, 0x20($sp)
/* B20888 80240348 AFB1001C */  sw        $s1, 0x1c($sp)
/* B2088C 8024034C AFB00018 */  sw        $s0, 0x18($sp)
/* B20890 80240350 8C910148 */  lw        $s1, 0x148($a0)
/* B20894 80240354 0C00EABB */  jal       get_npc_unsafe
/* B20898 80240358 86240008 */   lh       $a0, 8($s1)
/* B2089C 8024035C 8E23006C */  lw        $v1, 0x6c($s1)
/* B208A0 80240360 28630005 */  slti      $v1, $v1, 5
/* B208A4 80240364 1060001D */  beqz      $v1, .L802403DC
/* B208A8 80240368 0040802D */   daddu    $s0, $v0, $zero
/* B208AC 8024036C 0C00A67F */  jal       rand_int
/* B208B0 80240370 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B208B4 80240374 2842012D */  slti      $v0, $v0, 0x12d
/* B208B8 80240378 14400018 */  bnez      $v0, .L802403DC
/* B208BC 8024037C 24020003 */   addiu    $v0, $zero, 3
/* B208C0 80240380 860300A8 */  lh        $v1, 0xa8($s0)
/* B208C4 80240384 C604003C */  lwc1      $f4, 0x3c($s0)
/* B208C8 80240388 C6000040 */  lwc1      $f0, 0x40($s0)
/* B208CC 8024038C 3C014014 */  lui       $at, 0x4014
/* B208D0 80240390 44811800 */  mtc1      $at, $f3
/* B208D4 80240394 44801000 */  mtc1      $zero, $f2
/* B208D8 80240398 AFA20010 */  sw        $v0, 0x10($sp)
/* B208DC 8024039C 46000021 */  cvt.d.s   $f0, $f0
/* B208E0 802403A0 46220000 */  add.d     $f0, $f0, $f2
/* B208E4 802403A4 AFA00014 */  sw        $zero, 0x14($sp)
/* B208E8 802403A8 44831000 */  mtc1      $v1, $f2
/* B208EC 802403AC 00000000 */  nop       
/* B208F0 802403B0 468010A0 */  cvt.s.w   $f2, $f2
/* B208F4 802403B4 46022100 */  add.s     $f4, $f4, $f2
/* B208F8 802403B8 8E050038 */  lw        $a1, 0x38($s0)
/* B208FC 802403BC 46200020 */  cvt.s.d   $f0, $f0
/* B20900 802403C0 44062000 */  mfc1      $a2, $f4
/* B20904 802403C4 44070000 */  mfc1      $a3, $f0
/* B20908 802403C8 0C04C6A5 */  jal       make_item_entity_nodelay
/* B2090C 802403CC 24040156 */   addiu    $a0, $zero, 0x156
/* B20910 802403D0 8E22006C */  lw        $v0, 0x6c($s1)
/* B20914 802403D4 24420001 */  addiu     $v0, $v0, 1
/* B20918 802403D8 AE22006C */  sw        $v0, 0x6c($s1)
.L802403DC:
/* B2091C 802403DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* B20920 802403E0 8FB1001C */  lw        $s1, 0x1c($sp)
/* B20924 802403E4 8FB00018 */  lw        $s0, 0x18($sp)
/* B20928 802403E8 24020002 */  addiu     $v0, $zero, 2
/* B2092C 802403EC 03E00008 */  jr        $ra
/* B20930 802403F0 27BD0028 */   addiu    $sp, $sp, 0x28
