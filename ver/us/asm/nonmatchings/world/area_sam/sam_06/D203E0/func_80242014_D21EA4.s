.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_06_UnkFunc33
/* D21EA4 80242014 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D21EA8 80242018 AFB10014 */  sw        $s1, 0x14($sp)
/* D21EAC 8024201C 0080882D */  daddu     $s1, $a0, $zero
/* D21EB0 80242020 AFBF0018 */  sw        $ra, 0x18($sp)
/* D21EB4 80242024 AFB00010 */  sw        $s0, 0x10($sp)
/* D21EB8 80242028 8E30000C */  lw        $s0, 0xc($s1)
/* D21EBC 8024202C 8E050000 */  lw        $a1, ($s0)
/* D21EC0 80242030 0C0B1EAF */  jal       get_variable
/* D21EC4 80242034 26100004 */   addiu    $s0, $s0, 4
/* D21EC8 80242038 0220202D */  daddu     $a0, $s1, $zero
/* D21ECC 8024203C 8E050000 */  lw        $a1, ($s0)
/* D21ED0 80242040 0C0B1EAF */  jal       get_variable
/* D21ED4 80242044 0040802D */   daddu    $s0, $v0, $zero
/* D21ED8 80242048 44820000 */  mtc1      $v0, $f0
/* D21EDC 8024204C 00000000 */  nop
/* D21EE0 80242050 46800020 */  cvt.s.w   $f0, $f0
/* D21EE4 80242054 24020002 */  addiu     $v0, $zero, 2
/* D21EE8 80242058 00501804 */  sllv      $v1, $s0, $v0
/* D21EEC 8024205C 00701821 */  addu      $v1, $v1, $s0
/* D21EF0 80242060 00431804 */  sllv      $v1, $v1, $v0
/* D21EF4 80242064 00701823 */  subu      $v1, $v1, $s0
/* D21EF8 80242068 000320C0 */  sll       $a0, $v1, 3
/* D21EFC 8024206C 00641821 */  addu      $v1, $v1, $a0
/* D21F00 80242070 000318C0 */  sll       $v1, $v1, 3
/* D21F04 80242074 3C01800B */  lui       $at, %hi(gCameras+0x18)
/* D21F08 80242078 00230821 */  addu      $at, $at, $v1
/* D21F0C 8024207C E4201D98 */  swc1      $f0, %lo(gCameras+0x18)($at)
/* D21F10 80242080 8FBF0018 */  lw        $ra, 0x18($sp)
/* D21F14 80242084 8FB10014 */  lw        $s1, 0x14($sp)
/* D21F18 80242088 8FB00010 */  lw        $s0, 0x10($sp)
/* D21F1C 8024208C 03E00008 */  jr        $ra
/* D21F20 80242090 27BD0020 */   addiu    $sp, $sp, 0x20
