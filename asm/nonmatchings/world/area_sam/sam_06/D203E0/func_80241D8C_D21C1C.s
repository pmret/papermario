.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D8C_D21C1C
/* D21C1C 80241D8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21C20 80241D90 AFBF0010 */  sw        $ra, 0x10($sp)
/* D21C24 80241D94 10A00003 */  beqz      $a1, .L80241DA4
/* D21C28 80241D98 8C86000C */   lw       $a2, 0xc($a0)
/* D21C2C 80241D9C 3C018024 */  lui       $at, 0x8024
/* D21C30 80241DA0 AC204434 */  sw        $zero, 0x4434($at)
.L80241DA4:
/* D21C34 80241DA4 3C038024 */  lui       $v1, 0x8024
/* D21C38 80241DA8 24634434 */  addiu     $v1, $v1, 0x4434
/* D21C3C 80241DAC 8C620000 */  lw        $v0, ($v1)
/* D21C40 80241DB0 54400003 */  bnel      $v0, $zero, .L80241DC0
/* D21C44 80241DB4 AC600000 */   sw       $zero, ($v1)
/* D21C48 80241DB8 08090775 */  j         .L80241DD4
/* D21C4C 80241DBC 0000102D */   daddu    $v0, $zero, $zero
.L80241DC0:
/* D21C50 80241DC0 8CC50000 */  lw        $a1, ($a2)
/* D21C54 80241DC4 3C068024 */  lui       $a2, 0x8024
/* D21C58 80241DC8 0C0B2026 */  jal       set_variable
/* D21C5C 80241DCC 8CC64438 */   lw       $a2, 0x4438($a2)
/* D21C60 80241DD0 24020002 */  addiu     $v0, $zero, 2
.L80241DD4:
/* D21C64 80241DD4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21C68 80241DD8 03E00008 */  jr        $ra
/* D21C6C 80241DDC 27BD0018 */   addiu    $sp, $sp, 0x18
