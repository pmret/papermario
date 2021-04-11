.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nok_01_UnkFunc31
/* 9C64A8 802410C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C64AC 802410CC AFBF0014 */  sw        $ra, 0x14($sp)
/* 9C64B0 802410D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C64B4 802410D4 0C00EABB */  jal       get_npc_unsafe
/* 9C64B8 802410D8 8C84014C */   lw       $a0, 0x14c($a0)
/* 9C64BC 802410DC 24040008 */  addiu     $a0, $zero, 8
/* 9C64C0 802410E0 0040802D */  daddu     $s0, $v0, $zero
/* 9C64C4 802410E4 3C028024 */  lui       $v0, %hi(nok_01_UnkFunc28)
/* 9C64C8 802410E8 24421134 */  addiu     $v0, $v0, %lo(nok_01_UnkFunc28)
/* 9C64CC 802410EC 0C00AB39 */  jal       heap_malloc
/* 9C64D0 802410F0 AE020008 */   sw       $v0, 8($s0)
/* 9C64D4 802410F4 0040182D */  daddu     $v1, $v0, $zero
/* 9C64D8 802410F8 AE030020 */  sw        $v1, 0x20($s0)
/* 9C64DC 802410FC AC600000 */  sw        $zero, ($v1)
/* 9C64E0 80241100 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9C64E4 80241104 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C64E8 80241108 24020001 */  addiu     $v0, $zero, 1
/* 9C64EC 8024110C 03E00008 */  jr        $ra
/* 9C64F0 80241110 27BD0018 */   addiu    $sp, $sp, 0x18
