.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B1C
/* ABBDAC 80240B1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ABBDB0 80240B20 AFB10014 */  sw        $s1, 0x14($sp)
/* ABBDB4 80240B24 0080882D */  daddu     $s1, $a0, $zero
/* ABBDB8 80240B28 AFBF0018 */  sw        $ra, 0x18($sp)
/* ABBDBC 80240B2C AFB00010 */  sw        $s0, 0x10($sp)
/* ABBDC0 80240B30 8E300148 */  lw        $s0, 0x148($s1)
/* ABBDC4 80240B34 0C00EABB */  jal       get_npc_unsafe
/* ABBDC8 80240B38 86040008 */   lh       $a0, 8($s0)
/* ABBDCC 80240B3C 9443008E */  lhu       $v1, 0x8e($v0)
/* ABBDD0 80240B40 2463FFFF */  addiu     $v1, $v1, -1
/* ABBDD4 80240B44 A443008E */  sh        $v1, 0x8e($v0)
/* ABBDD8 80240B48 00031C00 */  sll       $v1, $v1, 0x10
/* ABBDDC 80240B4C 14600008 */  bnez      $v1, .L80240B70
/* ABBDE0 80240B50 00000000 */   nop      
/* ABBDE4 80240B54 8E0200B0 */  lw        $v0, 0xb0($s0)
/* ABBDE8 80240B58 30420080 */  andi      $v0, $v0, 0x80
/* ABBDEC 80240B5C 10400003 */  beqz      $v0, .L80240B6C
/* ABBDF0 80240B60 2402000F */   addiu    $v0, $zero, 0xf
/* ABBDF4 80240B64 080902DC */  j         .L80240B70
/* ABBDF8 80240B68 AE220070 */   sw       $v0, 0x70($s1)
.L80240B6C:
/* ABBDFC 80240B6C AE200070 */  sw        $zero, 0x70($s1)
.L80240B70:
/* ABBE00 80240B70 8FBF0018 */  lw        $ra, 0x18($sp)
/* ABBE04 80240B74 8FB10014 */  lw        $s1, 0x14($sp)
/* ABBE08 80240B78 8FB00010 */  lw        $s0, 0x10($sp)
/* ABBE0C 80240B7C 03E00008 */  jr        $ra
/* ABBE10 80240B80 27BD0020 */   addiu    $sp, $sp, 0x20
