.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B4C_A8D5CC
/* A8D5CC 80240B4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8D5D0 80240B50 AFB10014 */  sw        $s1, 0x14($sp)
/* A8D5D4 80240B54 0080882D */  daddu     $s1, $a0, $zero
/* A8D5D8 80240B58 AFBF0018 */  sw        $ra, 0x18($sp)
/* A8D5DC 80240B5C AFB00010 */  sw        $s0, 0x10($sp)
/* A8D5E0 80240B60 8E300148 */  lw        $s0, 0x148($s1)
/* A8D5E4 80240B64 0C00EABB */  jal       get_npc_unsafe
/* A8D5E8 80240B68 86040008 */   lh       $a0, 8($s0)
/* A8D5EC 80240B6C 9443008E */  lhu       $v1, 0x8e($v0)
/* A8D5F0 80240B70 2463FFFF */  addiu     $v1, $v1, -1
/* A8D5F4 80240B74 A443008E */  sh        $v1, 0x8e($v0)
/* A8D5F8 80240B78 00031C00 */  sll       $v1, $v1, 0x10
/* A8D5FC 80240B7C 14600008 */  bnez      $v1, .L80240BA0
/* A8D600 80240B80 00000000 */   nop      
/* A8D604 80240B84 8E0200B0 */  lw        $v0, 0xb0($s0)
/* A8D608 80240B88 30420080 */  andi      $v0, $v0, 0x80
/* A8D60C 80240B8C 10400003 */  beqz      $v0, .L80240B9C
/* A8D610 80240B90 2402000F */   addiu    $v0, $zero, 0xf
/* A8D614 80240B94 080902E8 */  j         .L80240BA0
/* A8D618 80240B98 AE220070 */   sw       $v0, 0x70($s1)
.L80240B9C:
/* A8D61C 80240B9C AE200070 */  sw        $zero, 0x70($s1)
.L80240BA0:
/* A8D620 80240BA0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A8D624 80240BA4 8FB10014 */  lw        $s1, 0x14($sp)
/* A8D628 80240BA8 8FB00010 */  lw        $s0, 0x10($sp)
/* A8D62C 80240BAC 03E00008 */  jr        $ra
/* A8D630 80240BB0 27BD0020 */   addiu    $sp, $sp, 0x20
