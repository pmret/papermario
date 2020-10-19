.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405EC_B351BC
/* B351BC 802405EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B351C0 802405F0 0000202D */  daddu     $a0, $zero, $zero
/* B351C4 802405F4 0080282D */  daddu     $a1, $a0, $zero
/* B351C8 802405F8 0080302D */  daddu     $a2, $a0, $zero
/* B351CC 802405FC 0080382D */  daddu     $a3, $a0, $zero
/* B351D0 80240600 AFBF0018 */  sw        $ra, 0x18($sp)
/* B351D4 80240604 AFA00010 */  sw        $zero, 0x10($sp)
/* B351D8 80240608 0C01CA54 */  jal       func_80072950
/* B351DC 8024060C AFA00014 */   sw       $zero, 0x14($sp)
/* B351E0 80240610 8FBF0018 */  lw        $ra, 0x18($sp)
/* B351E4 80240614 24020002 */  addiu     $v0, $zero, 2
/* B351E8 80240618 03E00008 */  jr        $ra
/* B351EC 8024061C 27BD0020 */   addiu    $sp, $sp, 0x20
