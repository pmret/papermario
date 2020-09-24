.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel delete_entity
/* A6DD0 801106D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A6DD4 801106D4 AFB00010 */  sw        $s0, 0x10($sp)
/* A6DD8 801106D8 0080802D */  daddu     $s0, $a0, $zero
/* A6DDC 801106DC AFBF0018 */  sw        $ra, 0x18($sp)
/* A6DE0 801106E0 0C04417A */  jal       get_entity_by_index
/* A6DE4 801106E4 AFB10014 */   sw       $s1, 0x14($sp)
/* A6DE8 801106E8 0040882D */  daddu     $s1, $v0, $zero
/* A6DEC 801106EC 8E240040 */  lw        $a0, 0x40($s1)
/* A6DF0 801106F0 10800003 */  beqz      $a0, .L80110700
/* A6DF4 801106F4 00000000 */   nop      
/* A6DF8 801106F8 0C00AB4B */  jal       heap_free
/* A6DFC 801106FC 00000000 */   nop      
.L80110700:
/* A6E00 80110700 8E220000 */  lw        $v0, ($s1)
/* A6E04 80110704 30420008 */  andi      $v0, $v0, 8
/* A6E08 80110708 14400005 */  bnez      $v0, .L80110720
/* A6E0C 8011070C 00000000 */   nop      
/* A6E10 80110710 0C048B7F */  jal       func_80122DFC
/* A6E14 80110714 86240014 */   lh       $a0, 0x14($s1)
/* A6E18 80110718 080441CC */  j         .L80110730
/* A6E1C 8011071C 00000000 */   nop      
.L80110720:
/* A6E20 80110720 0C047FF8 */  jal       func_8011FFE0
/* A6E24 80110724 86240014 */   lh       $a0, 0x14($s1)
/* A6E28 80110728 0C04790E */  jal       func_8011E438
/* A6E2C 8011072C 0040202D */   daddu    $a0, $v0, $zero
.L80110730:
/* A6E30 80110730 86240016 */  lh        $a0, 0x16($s1)
/* A6E34 80110734 04800007 */  bltz      $a0, .L80110754
/* A6E38 80110738 00000000 */   nop      
/* A6E3C 8011073C 0C044181 */  jal       get_shadow_by_index
/* A6E40 80110740 00000000 */   nop      
/* A6E44 80110744 8C430000 */  lw        $v1, ($v0)
/* A6E48 80110748 3C041000 */  lui       $a0, 0x1000
/* A6E4C 8011074C 00641825 */  or        $v1, $v1, $a0
/* A6E50 80110750 AC430000 */  sw        $v1, ($v0)
.L80110754:
/* A6E54 80110754 3C118015 */  lui       $s1, 0x8015
/* A6E58 80110758 26311470 */  addiu     $s1, $s1, 0x1470
/* A6E5C 8011075C 8E220000 */  lw        $v0, ($s1)
/* A6E60 80110760 00108080 */  sll       $s0, $s0, 2
/* A6E64 80110764 02021021 */  addu      $v0, $s0, $v0
/* A6E68 80110768 0C00AB4B */  jal       heap_free
/* A6E6C 8011076C 8C440000 */   lw       $a0, ($v0)
/* A6E70 80110770 8E220000 */  lw        $v0, ($s1)
/* A6E74 80110774 02028021 */  addu      $s0, $s0, $v0
/* A6E78 80110778 AE000000 */  sw        $zero, ($s0)
/* A6E7C 8011077C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A6E80 80110780 8FB10014 */  lw        $s1, 0x14($sp)
/* A6E84 80110784 8FB00010 */  lw        $s0, 0x10($sp)
/* A6E88 80110788 03E00008 */  jr        $ra
/* A6E8C 8011078C 27BD0020 */   addiu    $sp, $sp, 0x20
