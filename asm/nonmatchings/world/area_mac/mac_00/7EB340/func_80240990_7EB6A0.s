.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240990_7EB6A0
/* 7EB6A0 80240990 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EB6A4 80240994 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7EB6A8 80240998 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EB6AC 8024099C 0C00EABB */  jal       get_npc_unsafe
/* 7EB6B0 802409A0 8C84014C */   lw       $a0, 0x14c($a0)
/* 7EB6B4 802409A4 24040008 */  addiu     $a0, $zero, 8
/* 7EB6B8 802409A8 0040802D */  daddu     $s0, $v0, $zero
/* 7EB6BC 802409AC 3C028024 */  lui       $v0, %hi(D_802409FC)
/* 7EB6C0 802409B0 244209FC */  addiu     $v0, $v0, %lo(D_802409FC)
/* 7EB6C4 802409B4 0C00AB39 */  jal       heap_malloc
/* 7EB6C8 802409B8 AE020008 */   sw       $v0, 8($s0)
/* 7EB6CC 802409BC 0040182D */  daddu     $v1, $v0, $zero
/* 7EB6D0 802409C0 AE030020 */  sw        $v1, 0x20($s0)
/* 7EB6D4 802409C4 AC600000 */  sw        $zero, ($v1)
/* 7EB6D8 802409C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7EB6DC 802409CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EB6E0 802409D0 24020001 */  addiu     $v0, $zero, 1
/* 7EB6E4 802409D4 03E00008 */  jr        $ra
/* 7EB6E8 802409D8 27BD0018 */   addiu    $sp, $sp, 0x18
