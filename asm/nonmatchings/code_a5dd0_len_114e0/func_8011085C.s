.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011085C
/* A6F5C 8011085C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A6F60 80110860 AFB00010 */  sw        $s0, 0x10($sp)
/* A6F64 80110864 0080802D */  daddu     $s0, $a0, $zero
/* A6F68 80110868 AFBF0018 */  sw        $ra, 0x18($sp)
/* A6F6C 8011086C 0C044181 */  jal       get_shadow_by_index
/* A6F70 80110870 AFB10014 */   sw       $s1, 0x14($sp)
/* A6F74 80110874 84440008 */  lh        $a0, 8($v0)
/* A6F78 80110878 0C048B7F */  jal       func_80122DFC
/* A6F7C 8011087C 00108080 */   sll      $s0, $s0, 2
/* A6F80 80110880 3C118015 */  lui       $s1, 0x8015
/* A6F84 80110884 26311658 */  addiu     $s1, $s1, 0x1658
/* A6F88 80110888 8E220000 */  lw        $v0, ($s1)
/* A6F8C 8011088C 02021021 */  addu      $v0, $s0, $v0
/* A6F90 80110890 0C00AB4B */  jal       heap_free
/* A6F94 80110894 8C440000 */   lw       $a0, ($v0)
/* A6F98 80110898 8E220000 */  lw        $v0, ($s1)
/* A6F9C 8011089C 02028021 */  addu      $s0, $s0, $v0
/* A6FA0 801108A0 AE000000 */  sw        $zero, ($s0)
/* A6FA4 801108A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A6FA8 801108A8 8FB10014 */  lw        $s1, 0x14($sp)
/* A6FAC 801108AC 8FB00010 */  lw        $s0, 0x10($sp)
/* A6FB0 801108B0 03E00008 */  jr        $ra
/* A6FB4 801108B4 27BD0020 */   addiu    $sp, $sp, 0x20
