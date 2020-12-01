.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_spirits_draw_title
/* 1405D4 8024D294 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1405D8 8024D298 AFB00018 */  sw        $s0, 0x18($sp)
/* 1405DC 8024D29C 0080802D */  daddu     $s0, $a0, $zero
/* 1405E0 8024D2A0 AFB20020 */  sw        $s2, 0x20($sp)
/* 1405E4 8024D2A4 00A0902D */  daddu     $s2, $a1, $zero
/* 1405E8 8024D2A8 AFB30024 */  sw        $s3, 0x24($sp)
/* 1405EC 8024D2AC 00C0982D */  daddu     $s3, $a2, $zero
/* 1405F0 8024D2B0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1405F4 8024D2B4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 1405F8 8024D2B8 0C039D59 */  jal       get_player_data
/* 1405FC 8024D2BC 00E0882D */   daddu    $s1, $a3, $zero
/* 140600 8024D2C0 0040202D */  daddu     $a0, $v0, $zero
/* 140604 8024D2C4 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 140608 8024D2C8 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 14060C 8024D2CC 24020005 */  addiu     $v0, $zero, 5
/* 140610 8024D2D0 1462001C */  bne       $v1, $v0, .L8024D344
/* 140614 8024D2D4 00000000 */   nop      
/* 140618 8024D2D8 92020003 */  lbu       $v0, 3($s0)
/* 14061C 8024D2DC 8083028E */  lb        $v1, 0x28e($a0)
/* 140620 8024D2E0 00021080 */  sll       $v0, $v0, 2
/* 140624 8024D2E4 3C048027 */  lui       $a0, %hi(D_802706E0)
/* 140628 8024D2E8 00822021 */  addu      $a0, $a0, $v0
/* 14062C 8024D2EC 8C8406E0 */  lw        $a0, %lo(D_802706E0)($a0)
/* 140630 8024D2F0 0083182A */  slt       $v1, $a0, $v1
/* 140634 8024D2F4 10600004 */  beqz      $v1, .L8024D308
/* 140638 8024D2F8 3C02001D */   lui      $v0, 0x1d
/* 14063C 8024D2FC 3442002A */  ori       $v0, $v0, 0x2a
/* 140640 8024D300 080934C5 */  j         .L8024D314
/* 140644 8024D304 00828021 */   addu     $s0, $a0, $v0
.L8024D308:
/* 140648 8024D308 0C093BA0 */  jal       pause_get_menu_string
/* 14064C 8024D30C 24040056 */   addiu    $a0, $zero, 0x56
/* 140650 8024D310 0040802D */  daddu     $s0, $v0, $zero
.L8024D314:
/* 140654 8024D314 0200202D */  daddu     $a0, $s0, $zero
/* 140658 8024D318 0C04991D */  jal       get_string_width
/* 14065C 8024D31C 0000282D */   daddu    $a1, $zero, $zero
/* 140660 8024D320 0200202D */  daddu     $a0, $s0, $zero
/* 140664 8024D324 02221023 */  subu      $v0, $s1, $v0
/* 140668 8024D328 00021043 */  sra       $v0, $v0, 1
/* 14066C 8024D32C 02422821 */  addu      $a1, $s2, $v0
/* 140670 8024D330 26660001 */  addiu     $a2, $s3, 1
/* 140674 8024D334 240700FF */  addiu     $a3, $zero, 0xff
/* 140678 8024D338 AFA00010 */  sw        $zero, 0x10($sp)
/* 14067C 8024D33C 0C04993B */  jal       draw_string
/* 140680 8024D340 AFA00014 */   sw       $zero, 0x14($sp)
.L8024D344:
/* 140684 8024D344 8FBF0028 */  lw        $ra, 0x28($sp)
/* 140688 8024D348 8FB30024 */  lw        $s3, 0x24($sp)
/* 14068C 8024D34C 8FB20020 */  lw        $s2, 0x20($sp)
/* 140690 8024D350 8FB1001C */  lw        $s1, 0x1c($sp)
/* 140694 8024D354 8FB00018 */  lw        $s0, 0x18($sp)
/* 140698 8024D358 03E00008 */  jr        $ra
/* 14069C 8024D35C 27BD0030 */   addiu    $sp, $sp, 0x30
