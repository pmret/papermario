.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417D0
/* 95C9D0 802417D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95C9D4 802417D4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 95C9D8 802417D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 95C9DC 802417DC 0C00EABB */  jal       get_npc_unsafe
/* 95C9E0 802417E0 8C84014C */   lw       $a0, 0x14c($a0)
/* 95C9E4 802417E4 24040008 */  addiu     $a0, $zero, 8
/* 95C9E8 802417E8 0040802D */  daddu     $s0, $v0, $zero
/* 95C9EC 802417EC 3C028024 */  lui       $v0, 0x8024
/* 95C9F0 802417F0 2442183C */  addiu     $v0, $v0, 0x183c
/* 95C9F4 802417F4 0C00AB39 */  jal       heap_malloc
/* 95C9F8 802417F8 AE020008 */   sw       $v0, 8($s0)
/* 95C9FC 802417FC 0040182D */  daddu     $v1, $v0, $zero
/* 95CA00 80241800 AE030020 */  sw        $v1, 0x20($s0)
/* 95CA04 80241804 AC600000 */  sw        $zero, ($v1)
/* 95CA08 80241808 8FBF0014 */  lw        $ra, 0x14($sp)
/* 95CA0C 8024180C 8FB00010 */  lw        $s0, 0x10($sp)
/* 95CA10 80241810 24020001 */  addiu     $v0, $zero, 1
/* 95CA14 80241814 03E00008 */  jr        $ra
/* 95CA18 80241818 27BD0018 */   addiu    $sp, $sp, 0x18
