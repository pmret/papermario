.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417AC_EAA28C
/* EAA28C 802417AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EAA290 802417B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* EAA294 802417B4 10A00003 */  beqz      $a1, .L802417C4
/* EAA298 802417B8 8C86000C */   lw       $a2, 0xc($a0)
/* EAA29C 802417BC 3C018024 */  lui       $at, %hi(D_80243DD8_EAC8B8)
/* EAA2A0 802417C0 AC203DD8 */  sw        $zero, %lo(D_80243DD8_EAC8B8)($at)
.L802417C4:
/* EAA2A4 802417C4 3C038024 */  lui       $v1, %hi(D_80243DD8_EAC8B8)
/* EAA2A8 802417C8 24633DD8 */  addiu     $v1, $v1, %lo(D_80243DD8_EAC8B8)
/* EAA2AC 802417CC 8C620000 */  lw        $v0, ($v1)
/* EAA2B0 802417D0 54400003 */  bnel      $v0, $zero, .L802417E0
/* EAA2B4 802417D4 AC600000 */   sw       $zero, ($v1)
/* EAA2B8 802417D8 080905FD */  j         .L802417F4
/* EAA2BC 802417DC 0000102D */   daddu    $v0, $zero, $zero
.L802417E0:
/* EAA2C0 802417E0 8CC50000 */  lw        $a1, ($a2)
/* EAA2C4 802417E4 3C068024 */  lui       $a2, %hi(D_80243DDC_EAC8BC)
/* EAA2C8 802417E8 0C0B551A */  jal       dead_set_variable
/* EAA2CC 802417EC 8CC63DDC */   lw       $a2, %lo(D_80243DDC_EAC8BC)($a2)
/* EAA2D0 802417F0 24020002 */  addiu     $v0, $zero, 2
.L802417F4:
/* EAA2D4 802417F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* EAA2D8 802417F8 03E00008 */  jr        $ra
/* EAA2DC 802417FC 27BD0018 */   addiu    $sp, $sp, 0x18
