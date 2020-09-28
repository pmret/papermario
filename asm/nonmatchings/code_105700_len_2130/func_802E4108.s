.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4108
/* 105988 802E4108 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10598C 802E410C AFBF0014 */  sw        $ra, 0x14($sp)
/* 105990 802E4110 AFB00010 */  sw        $s0, 0x10($sp)
/* 105994 802E4114 8C820040 */  lw        $v0, 0x40($a0)
/* 105998 802E4118 84440012 */  lh        $a0, 0x12($v0)
/* 10599C 802E411C 0C04417A */  jal       get_entity_by_index
/* 1059A0 802E4120 2410FFFE */   addiu    $s0, $zero, -2
/* 1059A4 802E4124 8C430000 */  lw        $v1, ($v0)
/* 1059A8 802E4128 84440016 */  lh        $a0, 0x16($v0)
/* 1059AC 802E412C 00701824 */  and       $v1, $v1, $s0
/* 1059B0 802E4130 0C044181 */  jal       get_shadow_by_index
/* 1059B4 802E4134 AC430000 */   sw       $v1, ($v0)
/* 1059B8 802E4138 8C430000 */  lw        $v1, ($v0)
/* 1059BC 802E413C 00701824 */  and       $v1, $v1, $s0
/* 1059C0 802E4140 AC430000 */  sw        $v1, ($v0)
/* 1059C4 802E4144 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1059C8 802E4148 8FB00010 */  lw        $s0, 0x10($sp)
/* 1059CC 802E414C 03E00008 */  jr        $ra
/* 1059D0 802E4150 27BD0018 */   addiu    $sp, $sp, 0x18
