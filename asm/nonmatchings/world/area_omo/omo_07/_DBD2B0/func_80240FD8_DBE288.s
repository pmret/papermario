.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FD8_DBE288
/* DBE288 80240FD8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBE28C 80240FDC AFB10014 */  sw        $s1, 0x14($sp)
/* DBE290 80240FE0 0080882D */  daddu     $s1, $a0, $zero
/* DBE294 80240FE4 AFBF0018 */  sw        $ra, 0x18($sp)
/* DBE298 80240FE8 AFB00010 */  sw        $s0, 0x10($sp)
/* DBE29C 80240FEC 8E300148 */  lw        $s0, 0x148($s1)
/* DBE2A0 80240FF0 0C00EABB */  jal       get_npc_unsafe
/* DBE2A4 80240FF4 86040008 */   lh       $a0, 8($s0)
/* DBE2A8 80240FF8 9443008E */  lhu       $v1, 0x8e($v0)
/* DBE2AC 80240FFC 2463FFFF */  addiu     $v1, $v1, -1
/* DBE2B0 80241000 A443008E */  sh        $v1, 0x8e($v0)
/* DBE2B4 80241004 00031C00 */  sll       $v1, $v1, 0x10
/* DBE2B8 80241008 14600008 */  bnez      $v1, .L8024102C
/* DBE2BC 8024100C 00000000 */   nop      
/* DBE2C0 80241010 8E0200B0 */  lw        $v0, 0xb0($s0)
/* DBE2C4 80241014 30420080 */  andi      $v0, $v0, 0x80
/* DBE2C8 80241018 10400003 */  beqz      $v0, .L80241028
/* DBE2CC 8024101C 2402000F */   addiu    $v0, $zero, 0xf
/* DBE2D0 80241020 0809040B */  j         .L8024102C
/* DBE2D4 80241024 AE220070 */   sw       $v0, 0x70($s1)
.L80241028:
/* DBE2D8 80241028 AE200070 */  sw        $zero, 0x70($s1)
.L8024102C:
/* DBE2DC 8024102C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DBE2E0 80241030 8FB10014 */  lw        $s1, 0x14($sp)
/* DBE2E4 80241034 8FB00010 */  lw        $s0, 0x10($sp)
/* DBE2E8 80241038 03E00008 */  jr        $ra
/* DBE2EC 8024103C 27BD0020 */   addiu    $sp, $sp, 0x20
