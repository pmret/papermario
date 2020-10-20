.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024055C_DB7E6C
/* DB7E6C 8024055C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB7E70 80240560 AFB00010 */  sw        $s0, 0x10($sp)
/* DB7E74 80240564 0080802D */  daddu     $s0, $a0, $zero
/* DB7E78 80240568 AFBF0014 */  sw        $ra, 0x14($sp)
/* DB7E7C 8024056C 8E0300A8 */  lw        $v1, 0xa8($s0)
/* DB7E80 80240570 8E020088 */  lw        $v0, 0x88($s0)
/* DB7E84 80240574 00621821 */  addu      $v1, $v1, $v0
/* DB7E88 80240578 04610004 */  bgez      $v1, .L8024058C
/* DB7E8C 8024057C AE0300A8 */   sw       $v1, 0xa8($s0)
/* DB7E90 80240580 3C020002 */  lui       $v0, 2
/* DB7E94 80240584 08090167 */  j         .L8024059C
/* DB7E98 80240588 00621021 */   addu     $v0, $v1, $v0
.L8024058C:
/* DB7E9C 8024058C 3C040002 */  lui       $a0, 2
/* DB7EA0 80240590 0083102A */  slt       $v0, $a0, $v1
/* DB7EA4 80240594 10400002 */  beqz      $v0, .L802405A0
/* DB7EA8 80240598 00641023 */   subu     $v0, $v1, $a0
.L8024059C:
/* DB7EAC 8024059C AE0200A8 */  sw        $v0, 0xa8($s0)
.L802405A0:
/* DB7EB0 802405A0 8E0300AC */  lw        $v1, 0xac($s0)
/* DB7EB4 802405A4 8E02008C */  lw        $v0, 0x8c($s0)
/* DB7EB8 802405A8 00621821 */  addu      $v1, $v1, $v0
/* DB7EBC 802405AC 04610004 */  bgez      $v1, .L802405C0
/* DB7EC0 802405B0 AE0300AC */   sw       $v1, 0xac($s0)
/* DB7EC4 802405B4 3C020002 */  lui       $v0, 2
/* DB7EC8 802405B8 08090174 */  j         .L802405D0
/* DB7ECC 802405BC 00621021 */   addu     $v0, $v1, $v0
.L802405C0:
/* DB7ED0 802405C0 3C040002 */  lui       $a0, 2
/* DB7ED4 802405C4 0083102A */  slt       $v0, $a0, $v1
/* DB7ED8 802405C8 10400002 */  beqz      $v0, .L802405D4
/* DB7EDC 802405CC 00641023 */   subu     $v0, $v1, $a0
.L802405D0:
/* DB7EE0 802405D0 AE0200AC */  sw        $v0, 0xac($s0)
.L802405D4:
/* DB7EE4 802405D4 8E0300B0 */  lw        $v1, 0xb0($s0)
/* DB7EE8 802405D8 8E020090 */  lw        $v0, 0x90($s0)
/* DB7EEC 802405DC 00621821 */  addu      $v1, $v1, $v0
/* DB7EF0 802405E0 04610004 */  bgez      $v1, .L802405F4
/* DB7EF4 802405E4 AE0300B0 */   sw       $v1, 0xb0($s0)
/* DB7EF8 802405E8 3C020002 */  lui       $v0, 2
/* DB7EFC 802405EC 08090181 */  j         .L80240604
/* DB7F00 802405F0 00621021 */   addu     $v0, $v1, $v0
.L802405F4:
/* DB7F04 802405F4 3C040002 */  lui       $a0, 2
/* DB7F08 802405F8 0083102A */  slt       $v0, $a0, $v1
/* DB7F0C 802405FC 10400002 */  beqz      $v0, .L80240608
/* DB7F10 80240600 00641023 */   subu     $v0, $v1, $a0
.L80240604:
/* DB7F14 80240604 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80240608:
/* DB7F18 80240608 8E0300B4 */  lw        $v1, 0xb4($s0)
/* DB7F1C 8024060C 8E020094 */  lw        $v0, 0x94($s0)
/* DB7F20 80240610 00621821 */  addu      $v1, $v1, $v0
/* DB7F24 80240614 04610004 */  bgez      $v1, .L80240628
/* DB7F28 80240618 AE0300B4 */   sw       $v1, 0xb4($s0)
/* DB7F2C 8024061C 3C020002 */  lui       $v0, 2
/* DB7F30 80240620 0809018E */  j         .L80240638
/* DB7F34 80240624 00621021 */   addu     $v0, $v1, $v0
.L80240628:
/* DB7F38 80240628 3C040002 */  lui       $a0, 2
/* DB7F3C 8024062C 0083102A */  slt       $v0, $a0, $v1
/* DB7F40 80240630 10400002 */  beqz      $v0, .L8024063C
/* DB7F44 80240634 00641023 */   subu     $v0, $v1, $a0
.L80240638:
/* DB7F48 80240638 AE0200B4 */  sw        $v0, 0xb4($s0)
.L8024063C:
/* DB7F4C 8024063C 8E040084 */  lw        $a0, 0x84($s0)
/* DB7F50 80240640 0C046F07 */  jal       set_main_pan_u
/* DB7F54 80240644 8E0500A8 */   lw       $a1, 0xa8($s0)
/* DB7F58 80240648 8E040084 */  lw        $a0, 0x84($s0)
/* DB7F5C 8024064C 0C046F0D */  jal       set_main_pan_v
/* DB7F60 80240650 8E0500AC */   lw       $a1, 0xac($s0)
/* DB7F64 80240654 8E040084 */  lw        $a0, 0x84($s0)
/* DB7F68 80240658 0C046F13 */  jal       set_aux_pan_u
/* DB7F6C 8024065C 8E0500B0 */   lw       $a1, 0xb0($s0)
/* DB7F70 80240660 8E040084 */  lw        $a0, 0x84($s0)
/* DB7F74 80240664 0C046F19 */  jal       set_aux_pan_v
/* DB7F78 80240668 8E0500B4 */   lw       $a1, 0xb4($s0)
/* DB7F7C 8024066C 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB7F80 80240670 8FB00010 */  lw        $s0, 0x10($sp)
/* DB7F84 80240674 0000102D */  daddu     $v0, $zero, $zero
/* DB7F88 80240678 03E00008 */  jr        $ra
/* DB7F8C 8024067C 27BD0018 */   addiu    $sp, $sp, 0x18
