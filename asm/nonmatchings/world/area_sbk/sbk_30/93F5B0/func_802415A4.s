.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415A4
/* 940B54 802415A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 940B58 802415A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 940B5C 802415AC 0C00EABB */  jal       get_npc_unsafe
/* 940B60 802415B0 8C84008C */   lw       $a0, 0x8c($a0)
/* 940B64 802415B4 3C038024 */  lui       $v1, 0x8024
/* 940B68 802415B8 8C634D88 */  lw        $v1, 0x4d88($v1)
/* 940B6C 802415BC AC430028 */  sw        $v1, 0x28($v0)
/* 940B70 802415C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 940B74 802415C4 24020002 */  addiu     $v0, $zero, 2
/* 940B78 802415C8 03E00008 */  jr        $ra
/* 940B7C 802415CC 27BD0018 */   addiu    $sp, $sp, 0x18
