.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C4_E12B24
/* E12B24 802403C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E12B28 802403C8 2402002D */  addiu     $v0, $zero, 0x2d
/* E12B2C 802403CC AFA20010 */  sw        $v0, 0x10($sp)
/* E12B30 802403D0 3C028024 */  lui       $v0, 0x8024
/* E12B34 802403D4 244201D0 */  addiu     $v0, $v0, 0x1d0
/* E12B38 802403D8 27A40010 */  addiu     $a0, $sp, 0x10
/* E12B3C 802403DC AFBF0020 */  sw        $ra, 0x20($sp)
/* E12B40 802403E0 AFA00018 */  sw        $zero, 0x18($sp)
/* E12B44 802403E4 AFA2001C */  sw        $v0, 0x1c($sp)
/* E12B48 802403E8 0C047644 */  jal       queue_render_task
/* E12B4C 802403EC AFA00014 */   sw       $zero, 0x14($sp)
/* E12B50 802403F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* E12B54 802403F4 03E00008 */  jr        $ra
/* E12B58 802403F8 27BD0028 */   addiu    $sp, $sp, 0x28
