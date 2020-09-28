.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80111F2C
/* A862C 80111F2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8630 80111F30 AFB00010 */  sw        $s0, 0x10($sp)
/* A8634 80111F34 0080802D */  daddu     $s0, $a0, $zero
/* A8638 80111F38 3C048015 */  lui       $a0, 0x8015
/* A863C 80111F3C 8C8412EC */  lw        $a0, 0x12ec($a0)
/* A8640 80111F40 AFBF0014 */  sw        $ra, 0x14($sp)
/* A8644 80111F44 0C04417A */  jal       get_entity_by_index
/* A8648 80111F48 00000000 */   nop      
/* A864C 80111F4C 8E03000C */  lw        $v1, 0xc($s0)
/* A8650 80111F50 0200202D */  daddu     $a0, $s0, $zero
/* A8654 80111F54 8C650000 */  lw        $a1, ($v1)
/* A8658 80111F58 0C0B1EAF */  jal       get_variable
/* A865C 80111F5C 0040802D */   daddu    $s0, $v0, $zero
/* A8660 80111F60 1040000B */  beqz      $v0, .L80111F90
/* A8664 80111F64 2403FFFB */   addiu    $v1, $zero, -5
/* A8668 80111F68 8E020000 */  lw        $v0, ($s0)
/* A866C 80111F6C 86040016 */  lh        $a0, 0x16($s0)
/* A8670 80111F70 34420004 */  ori       $v0, $v0, 4
/* A8674 80111F74 0C044181 */  jal       get_shadow_by_index
/* A8678 80111F78 AE020000 */   sw       $v0, ($s0)
/* A867C 80111F7C 8C430000 */  lw        $v1, ($v0)
/* A8680 80111F80 3C040040 */  lui       $a0, 0x40
/* A8684 80111F84 00641825 */  or        $v1, $v1, $a0
/* A8688 80111F88 080447E7 */  j         .L80111F9C
/* A868C 80111F8C AC430000 */   sw       $v1, ($v0)
.L80111F90:
/* A8690 80111F90 8E020000 */  lw        $v0, ($s0)
/* A8694 80111F94 00431024 */  and       $v0, $v0, $v1
/* A8698 80111F98 AE020000 */  sw        $v0, ($s0)
.L80111F9C:
/* A869C 80111F9C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A86A0 80111FA0 8FB00010 */  lw        $s0, 0x10($sp)
/* A86A4 80111FA4 24020002 */  addiu     $v0, $zero, 2
/* A86A8 80111FA8 03E00008 */  jr        $ra
/* A86AC 80111FAC 27BD0018 */   addiu    $sp, $sp, 0x18
