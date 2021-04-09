.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E8C_D065BC
/* D065BC 80240E8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D065C0 80240E90 AFBF0014 */  sw        $ra, 0x14($sp)
/* D065C4 80240E94 AFB00010 */  sw        $s0, 0x10($sp)
/* D065C8 80240E98 0C00EABB */  jal       get_npc_unsafe
/* D065CC 80240E9C 8C84014C */   lw       $a0, 0x14c($a0)
/* D065D0 80240EA0 24040008 */  addiu     $a0, $zero, 8
/* D065D4 80240EA4 0040802D */  daddu     $s0, $v0, $zero
/* D065D8 80240EA8 3C028024 */  lui       $v0, %hi(sam_02_UnkFunc28)
/* D065DC 80240EAC 24420EF8 */  addiu     $v0, $v0, %lo(sam_02_UnkFunc28)
/* D065E0 80240EB0 0C00AB39 */  jal       heap_malloc
/* D065E4 80240EB4 AE020008 */   sw       $v0, 8($s0)
/* D065E8 80240EB8 0040182D */  daddu     $v1, $v0, $zero
/* D065EC 80240EBC AE030020 */  sw        $v1, 0x20($s0)
/* D065F0 80240EC0 AC600000 */  sw        $zero, ($v1)
/* D065F4 80240EC4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D065F8 80240EC8 8FB00010 */  lw        $s0, 0x10($sp)
/* D065FC 80240ECC 24020001 */  addiu     $v0, $zero, 1
/* D06600 80240ED0 03E00008 */  jr        $ra
/* D06604 80240ED4 27BD0018 */   addiu    $sp, $sp, 0x18
