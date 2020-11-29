.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405E8_800E68
/* 800E68 802405E8 3C05D9FB */  lui       $a1, 0xd9fb
/* 800E6C 802405EC 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 800E70 802405F0 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 800E74 802405F4 8C820000 */  lw        $v0, ($a0)
/* 800E78 802405F8 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 800E7C 802405FC 0040182D */  daddu     $v1, $v0, $zero
/* 800E80 80240600 24420008 */  addiu     $v0, $v0, 8
/* 800E84 80240604 AC820000 */  sw        $v0, ($a0)
/* 800E88 80240608 AC650000 */  sw        $a1, ($v1)
/* 800E8C 8024060C AC600004 */  sw        $zero, 4($v1)
/* 800E90 80240610 24430008 */  addiu     $v1, $v0, 8
/* 800E94 80240614 AC830000 */  sw        $v1, ($a0)
/* 800E98 80240618 3C03DF00 */  lui       $v1, 0xdf00
/* 800E9C 8024061C AC430000 */  sw        $v1, ($v0)
/* 800EA0 80240620 03E00008 */  jr        $ra
/* 800EA4 80240624 AC400004 */   sw       $zero, 4($v0)
