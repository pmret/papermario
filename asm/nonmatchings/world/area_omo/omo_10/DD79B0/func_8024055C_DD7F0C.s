.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024055C_DD7F0C
/* DD7F0C 8024055C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DD7F10 80240560 AFB00010 */  sw        $s0, 0x10($sp)
/* DD7F14 80240564 0080802D */  daddu     $s0, $a0, $zero
/* DD7F18 80240568 AFBF0014 */  sw        $ra, 0x14($sp)
/* DD7F1C 8024056C 8E0300A8 */  lw        $v1, 0xa8($s0)
/* DD7F20 80240570 8E020088 */  lw        $v0, 0x88($s0)
/* DD7F24 80240574 00621821 */  addu      $v1, $v1, $v0
/* DD7F28 80240578 04610004 */  bgez      $v1, .L8024058C
/* DD7F2C 8024057C AE0300A8 */   sw       $v1, 0xa8($s0)
/* DD7F30 80240580 3C020002 */  lui       $v0, 2
/* DD7F34 80240584 08090167 */  j         .L8024059C
/* DD7F38 80240588 00621021 */   addu     $v0, $v1, $v0
.L8024058C:
/* DD7F3C 8024058C 3C040002 */  lui       $a0, 2
/* DD7F40 80240590 0083102A */  slt       $v0, $a0, $v1
/* DD7F44 80240594 10400002 */  beqz      $v0, .L802405A0
/* DD7F48 80240598 00641023 */   subu     $v0, $v1, $a0
.L8024059C:
/* DD7F4C 8024059C AE0200A8 */  sw        $v0, 0xa8($s0)
.L802405A0:
/* DD7F50 802405A0 8E0300AC */  lw        $v1, 0xac($s0)
/* DD7F54 802405A4 8E02008C */  lw        $v0, 0x8c($s0)
/* DD7F58 802405A8 00621821 */  addu      $v1, $v1, $v0
/* DD7F5C 802405AC 04610004 */  bgez      $v1, .L802405C0
/* DD7F60 802405B0 AE0300AC */   sw       $v1, 0xac($s0)
/* DD7F64 802405B4 3C020002 */  lui       $v0, 2
/* DD7F68 802405B8 08090174 */  j         .L802405D0
/* DD7F6C 802405BC 00621021 */   addu     $v0, $v1, $v0
.L802405C0:
/* DD7F70 802405C0 3C040002 */  lui       $a0, 2
/* DD7F74 802405C4 0083102A */  slt       $v0, $a0, $v1
/* DD7F78 802405C8 10400002 */  beqz      $v0, .L802405D4
/* DD7F7C 802405CC 00641023 */   subu     $v0, $v1, $a0
.L802405D0:
/* DD7F80 802405D0 AE0200AC */  sw        $v0, 0xac($s0)
.L802405D4:
/* DD7F84 802405D4 8E0300B0 */  lw        $v1, 0xb0($s0)
/* DD7F88 802405D8 8E020090 */  lw        $v0, 0x90($s0)
/* DD7F8C 802405DC 00621821 */  addu      $v1, $v1, $v0
/* DD7F90 802405E0 04610004 */  bgez      $v1, .L802405F4
/* DD7F94 802405E4 AE0300B0 */   sw       $v1, 0xb0($s0)
/* DD7F98 802405E8 3C020002 */  lui       $v0, 2
/* DD7F9C 802405EC 08090181 */  j         .L80240604
/* DD7FA0 802405F0 00621021 */   addu     $v0, $v1, $v0
.L802405F4:
/* DD7FA4 802405F4 3C040002 */  lui       $a0, 2
/* DD7FA8 802405F8 0083102A */  slt       $v0, $a0, $v1
/* DD7FAC 802405FC 10400002 */  beqz      $v0, .L80240608
/* DD7FB0 80240600 00641023 */   subu     $v0, $v1, $a0
.L80240604:
/* DD7FB4 80240604 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80240608:
/* DD7FB8 80240608 8E0300B4 */  lw        $v1, 0xb4($s0)
/* DD7FBC 8024060C 8E020094 */  lw        $v0, 0x94($s0)
/* DD7FC0 80240610 00621821 */  addu      $v1, $v1, $v0
/* DD7FC4 80240614 04610004 */  bgez      $v1, .L80240628
/* DD7FC8 80240618 AE0300B4 */   sw       $v1, 0xb4($s0)
/* DD7FCC 8024061C 3C020002 */  lui       $v0, 2
/* DD7FD0 80240620 0809018E */  j         .L80240638
/* DD7FD4 80240624 00621021 */   addu     $v0, $v1, $v0
.L80240628:
/* DD7FD8 80240628 3C040002 */  lui       $a0, 2
/* DD7FDC 8024062C 0083102A */  slt       $v0, $a0, $v1
/* DD7FE0 80240630 10400002 */  beqz      $v0, .L8024063C
/* DD7FE4 80240634 00641023 */   subu     $v0, $v1, $a0
.L80240638:
/* DD7FE8 80240638 AE0200B4 */  sw        $v0, 0xb4($s0)
.L8024063C:
/* DD7FEC 8024063C 8E040084 */  lw        $a0, 0x84($s0)
/* DD7FF0 80240640 0C046F07 */  jal       set_main_pan_u
/* DD7FF4 80240644 8E0500A8 */   lw       $a1, 0xa8($s0)
/* DD7FF8 80240648 8E040084 */  lw        $a0, 0x84($s0)
/* DD7FFC 8024064C 0C046F0D */  jal       set_main_pan_v
/* DD8000 80240650 8E0500AC */   lw       $a1, 0xac($s0)
/* DD8004 80240654 8E040084 */  lw        $a0, 0x84($s0)
/* DD8008 80240658 0C046F13 */  jal       set_aux_pan_u
/* DD800C 8024065C 8E0500B0 */   lw       $a1, 0xb0($s0)
/* DD8010 80240660 8E040084 */  lw        $a0, 0x84($s0)
/* DD8014 80240664 0C046F19 */  jal       set_aux_pan_v
/* DD8018 80240668 8E0500B4 */   lw       $a1, 0xb4($s0)
/* DD801C 8024066C 8FBF0014 */  lw        $ra, 0x14($sp)
/* DD8020 80240670 8FB00010 */  lw        $s0, 0x10($sp)
/* DD8024 80240674 0000102D */  daddu     $v0, $zero, $zero
/* DD8028 80240678 03E00008 */  jr        $ra
/* DD802C 8024067C 27BD0018 */   addiu    $sp, $sp, 0x18
