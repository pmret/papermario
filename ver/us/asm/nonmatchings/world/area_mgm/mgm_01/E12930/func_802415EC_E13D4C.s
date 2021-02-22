.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415EC_E13D4C
/* E13D4C 802415EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E13D50 802415F0 0000202D */  daddu     $a0, $zero, $zero
/* E13D54 802415F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* E13D58 802415F8 AFB10014 */  sw        $s1, 0x14($sp)
/* E13D5C 802415FC 0C00FB3A */  jal       get_enemy
/* E13D60 80241600 AFB00010 */   sw       $s0, 0x10($sp)
/* E13D64 80241604 24040468 */  addiu     $a0, $zero, 0x468
/* E13D68 80241608 0C00AB0A */  jal       general_heap_malloc
/* E13D6C 8024160C 0040882D */   daddu    $s1, $v0, $zero
/* E13D70 80241610 0000202D */  daddu     $a0, $zero, $zero
/* E13D74 80241614 3C058024 */  lui       $a1, %hi(func_802403C4_E12B24)
/* E13D78 80241618 24A503C4 */  addiu     $a1, $a1, %lo(func_802403C4_E12B24)
/* E13D7C 8024161C 0040802D */  daddu     $s0, $v0, $zero
/* E13D80 80241620 0C048C56 */  jal       bind_dynamic_entity_3
/* E13D84 80241624 AE300080 */   sw       $s0, 0x80($s1)
/* E13D88 80241628 3C048011 */  lui       $a0, %hi(D_80108558)
/* E13D8C 8024162C 24848558 */  addiu     $a0, $a0, %lo(D_80108558)
/* E13D90 80241630 0C050529 */  jal       create_icon
/* E13D94 80241634 AE020000 */   sw       $v0, ($s0)
/* E13D98 80241638 0040202D */  daddu     $a0, $v0, $zero
/* E13D9C 8024163C 24050080 */  addiu     $a1, $zero, 0x80
/* E13DA0 80241640 0C051280 */  jal       set_icon_flags
/* E13DA4 80241644 AE040004 */   sw       $a0, 4($s0)
/* E13DA8 80241648 240500FF */  addiu     $a1, $zero, 0xff
/* E13DAC 8024164C 00A0302D */  daddu     $a2, $a1, $zero
/* E13DB0 80241650 8E040004 */  lw        $a0, 4($s0)
/* E13DB4 80241654 0C0513BF */  jal       icon_set_tint
/* E13DB8 80241658 00A0382D */   daddu    $a3, $a1, $zero
/* E13DBC 8024165C 24020141 */  addiu     $v0, $zero, 0x141
/* E13DC0 80241660 AE020014 */  sw        $v0, 0x14($s0)
/* E13DC4 80241664 2402001C */  addiu     $v0, $zero, 0x1c
/* E13DC8 80241668 0C03A625 */  jal       func_800E9894
/* E13DCC 8024166C AE020018 */   sw       $v0, 0x18($s0)
/* E13DD0 80241670 0C03A5EE */  jal       close_status_menu
/* E13DD4 80241674 00000000 */   nop
/* E13DD8 80241678 8FBF0018 */  lw        $ra, 0x18($sp)
/* E13DDC 8024167C 8FB10014 */  lw        $s1, 0x14($sp)
/* E13DE0 80241680 8FB00010 */  lw        $s0, 0x10($sp)
/* E13DE4 80241684 24020002 */  addiu     $v0, $zero, 2
/* E13DE8 80241688 03E00008 */  jr        $ra
/* E13DEC 8024168C 27BD0020 */   addiu    $sp, $sp, 0x20
