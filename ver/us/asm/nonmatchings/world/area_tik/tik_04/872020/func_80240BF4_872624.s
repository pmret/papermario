.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_04_UnkFunc30
/* 872624 80240BF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 872628 80240BF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 87262C 80240BFC 8C82000C */  lw        $v0, 0xc($a0)
/* 872630 80240C00 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* 872634 80240C04 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* 872638 80240C08 0C0B2026 */  jal       set_variable
/* 87263C 80240C0C 8C450000 */   lw       $a1, ($v0)
/* 872640 80240C10 8FBF0010 */  lw        $ra, 0x10($sp)
/* 872644 80240C14 24020002 */  addiu     $v0, $zero, 2
/* 872648 80240C18 03E00008 */  jr        $ra
/* 87264C 80240C1C 27BD0018 */   addiu    $sp, $sp, 0x18
