.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244078_8048F8
/* 8048F8 80244078 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8048FC 8024407C AFB00010 */  sw        $s0, 0x10($sp)
/* 804900 80244080 0080802D */  daddu     $s0, $a0, $zero
/* 804904 80244084 AFBF0014 */  sw        $ra, 0x14($sp)
/* 804908 80244088 0C00EABB */  jal       get_npc_unsafe
/* 80490C 8024408C 8E04008C */   lw       $a0, 0x8c($s0)
/* 804910 80244090 0040282D */  daddu     $a1, $v0, $zero
/* 804914 80244094 8E040094 */  lw        $a0, 0x94($s0)
/* 804918 80244098 8CA30028 */  lw        $v1, 0x28($a1)
/* 80491C 8024409C ACA40028 */  sw        $a0, 0x28($a1)
/* 804920 802440A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 804924 802440A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 804928 802440A8 24020002 */  addiu     $v0, $zero, 2
/* 80492C 802440AC 3C018026 */  lui       $at, 0x8026
/* 804930 802440B0 AC232C34 */  sw        $v1, 0x2c34($at)
/* 804934 802440B4 03E00008 */  jr        $ra
/* 804938 802440B8 27BD0018 */   addiu    $sp, $sp, 0x18
