.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242288_CCD598
/* CCD598 80242288 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCD59C 8024228C AFBF0010 */  sw        $ra, 0x10($sp)
/* CCD5A0 80242290 8C82000C */  lw        $v0, 0xc($a0)
/* CCD5A4 80242294 0C0B1EAF */  jal       get_variable
/* CCD5A8 80242298 8C450000 */   lw       $a1, ($v0)
/* CCD5AC 8024229C 3C018024 */  lui       $at, 0x8024
/* CCD5B0 802422A0 AC224600 */  sw        $v0, 0x4600($at)
/* CCD5B4 802422A4 24020002 */  addiu     $v0, $zero, 2
/* CCD5B8 802422A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* CCD5BC 802422AC 24030001 */  addiu     $v1, $zero, 1
/* CCD5C0 802422B0 3C018024 */  lui       $at, 0x8024
/* CCD5C4 802422B4 AC2345FC */  sw        $v1, 0x45fc($at)
/* CCD5C8 802422B8 03E00008 */  jr        $ra
/* CCD5CC 802422BC 27BD0018 */   addiu    $sp, $sp, 0x18
