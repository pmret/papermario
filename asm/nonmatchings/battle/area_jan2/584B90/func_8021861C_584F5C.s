.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021861C_584F5C
/* 584F5C 8021861C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 584F60 80218620 AFB3001C */  sw        $s3, 0x1c($sp)
/* 584F64 80218624 0080982D */  daddu     $s3, $a0, $zero
/* 584F68 80218628 AFBF0020 */  sw        $ra, 0x20($sp)
/* 584F6C 8021862C AFB20018 */  sw        $s2, 0x18($sp)
/* 584F70 80218630 AFB10014 */  sw        $s1, 0x14($sp)
/* 584F74 80218634 AFB00010 */  sw        $s0, 0x10($sp)
/* 584F78 80218638 8E70000C */  lw        $s0, 0xc($s3)
/* 584F7C 8021863C 8E050000 */  lw        $a1, ($s0)
/* 584F80 80218640 0C0B1EAF */  jal       get_variable
/* 584F84 80218644 26100004 */   addiu    $s0, $s0, 4
/* 584F88 80218648 0040882D */  daddu     $s1, $v0, $zero
/* 584F8C 8021864C 8E050000 */  lw        $a1, ($s0)
/* 584F90 80218650 26100004 */  addiu     $s0, $s0, 4
/* 584F94 80218654 0C0B1EAF */  jal       get_variable
/* 584F98 80218658 0260202D */   daddu    $a0, $s3, $zero
/* 584F9C 8021865C 0040902D */  daddu     $s2, $v0, $zero
/* 584FA0 80218660 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 584FA4 80218664 16220002 */  bne       $s1, $v0, .L80218670
/* 584FA8 80218668 00000000 */   nop
/* 584FAC 8021866C 8E710148 */  lw        $s1, 0x148($s3)
.L80218670:
/* 584FB0 80218670 0C09A75B */  jal       get_actor
/* 584FB4 80218674 0220202D */   daddu    $a0, $s1, $zero
/* 584FB8 80218678 0040202D */  daddu     $a0, $v0, $zero
/* 584FBC 8021867C 0C099117 */  jal       get_actor_part
/* 584FC0 80218680 0240282D */   daddu    $a1, $s2, $zero
/* 584FC4 80218684 8C440078 */  lw        $a0, 0x78($v0)
/* 584FC8 80218688 0C099791 */  jal       lookup_defense
/* 584FCC 8021868C 24050001 */   addiu    $a1, $zero, 1
/* 584FD0 80218690 0260202D */  daddu     $a0, $s3, $zero
/* 584FD4 80218694 8E050000 */  lw        $a1, ($s0)
/* 584FD8 80218698 0C0B2026 */  jal       set_variable
/* 584FDC 8021869C 0040302D */   daddu    $a2, $v0, $zero
/* 584FE0 802186A0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 584FE4 802186A4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 584FE8 802186A8 8FB20018 */  lw        $s2, 0x18($sp)
/* 584FEC 802186AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 584FF0 802186B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 584FF4 802186B4 24020002 */  addiu     $v0, $zero, 2
/* 584FF8 802186B8 03E00008 */  jr        $ra
/* 584FFC 802186BC 27BD0028 */   addiu    $sp, $sp, 0x28
