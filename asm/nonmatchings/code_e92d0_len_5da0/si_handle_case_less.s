.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_case_less
/* 0E9AF8 802C5148 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9AFC 802C514C AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9B00 802C5150 0080882D */  daddu $s1, $a0, $zero
/* 0E9B04 802C5154 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9B08 802C5158 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9B0C 802C515C 82300007 */  lb    $s0, 7($s1)
/* 0E9B10 802C5160 06010003 */  bgez  $s0, .L802C5170
/* 0E9B14 802C5164 8E25000C */   lw    $a1, 0xc($s1)
.L802C5168:
/* 0E9B18 802C5168 080B145A */  j     .L802C5168
/* 0E9B1C 802C516C 00000000 */   nop   

.L802C5170:
/* 0E9B20 802C5170 8CA50000 */  lw    $a1, ($a1)
/* 0E9B24 802C5174 0C0B1EAF */  jal   get_variable
/* 0E9B28 802C5178 0220202D */   daddu $a0, $s1, $zero
/* 0E9B2C 802C517C 0040282D */  daddu $a1, $v0, $zero
/* 0E9B30 802C5180 00101080 */  sll   $v0, $s0, 2
/* 0E9B34 802C5184 02221021 */  addu  $v0, $s1, $v0
/* 0E9B38 802C5188 02302021 */  addu  $a0, $s1, $s0
/* 0E9B3C 802C518C 80830110 */  lb    $v1, 0x110($a0)
/* 0E9B40 802C5190 8C420118 */  lw    $v0, 0x118($v0)
/* 0E9B44 802C5194 1C600005 */  bgtz  $v1, .L802C51AC
/* 0E9B48 802C5198 0045102A */   slt   $v0, $v0, $a1
/* 0E9B4C 802C519C 0C0B2279 */  jal   si_goto_end_case
/* 0E9B50 802C51A0 0220202D */   daddu $a0, $s1, $zero
/* 0E9B54 802C51A4 080B1470 */  j     .L802C51C0
/* 0E9B58 802C51A8 AE220008 */   sw    $v0, 8($s1)

.L802C51AC:
/* 0E9B5C 802C51AC 54400004 */  bnel  $v0, $zero, .L802C51C0
/* 0E9B60 802C51B0 A0800110 */   sb    $zero, 0x110($a0)
/* 0E9B64 802C51B4 0C0B2298 */  jal   si_goto_next_case
/* 0E9B68 802C51B8 0220202D */   daddu $a0, $s1, $zero
/* 0E9B6C 802C51BC AE220008 */  sw    $v0, 8($s1)
.L802C51C0:
/* 0E9B70 802C51C0 24020002 */  addiu $v0, $zero, 2
/* 0E9B74 802C51C4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9B78 802C51C8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9B7C 802C51CC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9B80 802C51D0 03E00008 */  jr    $ra
/* 0E9B84 802C51D4 27BD0020 */   addiu $sp, $sp, 0x20

