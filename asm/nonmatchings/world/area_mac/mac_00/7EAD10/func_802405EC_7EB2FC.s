.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405EC_7EB2FC
/* 7EB2FC 802405EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7EB300 802405F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7EB304 802405F4 8C82000C */  lw        $v0, 0xc($a0)
/* 7EB308 802405F8 0C0B1EAF */  jal       get_variable
/* 7EB30C 802405FC 8C450000 */   lw       $a1, ($v0)
/* 7EB310 80240600 0040202D */  daddu     $a0, $v0, $zero
/* 7EB314 80240604 27A50010 */  addiu     $a1, $sp, 0x10
/* 7EB318 80240608 27A60014 */  addiu     $a2, $sp, 0x14
/* 7EB31C 8024060C 0C016F84 */  jal       get_collider_center
/* 7EB320 80240610 27A70018 */   addiu    $a3, $sp, 0x18
/* 7EB324 80240614 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7EB328 80240618 24020002 */  addiu     $v0, $zero, 2
/* 7EB32C 8024061C 03E00008 */  jr        $ra
/* 7EB330 80240620 27BD0028 */   addiu    $sp, $sp, 0x28
