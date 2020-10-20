.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241680
/* 8537F0 80241680 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8537F4 80241684 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8537F8 80241688 AFB00010 */  sw        $s0, 0x10($sp)
/* 8537FC 8024168C 0C00EABB */  jal       get_npc_unsafe
/* 853800 80241690 8C84014C */   lw       $a0, 0x14c($a0)
/* 853804 80241694 24040008 */  addiu     $a0, $zero, 8
/* 853808 80241698 0040802D */  daddu     $s0, $v0, $zero
/* 85380C 8024169C 3C028024 */  lui       $v0, 0x8024
/* 853810 802416A0 244216EC */  addiu     $v0, $v0, 0x16ec
/* 853814 802416A4 0C00AB39 */  jal       heap_malloc
/* 853818 802416A8 AE020008 */   sw       $v0, 8($s0)
/* 85381C 802416AC 0040182D */  daddu     $v1, $v0, $zero
/* 853820 802416B0 AE030020 */  sw        $v1, 0x20($s0)
/* 853824 802416B4 AC600000 */  sw        $zero, ($v1)
/* 853828 802416B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 85382C 802416BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 853830 802416C0 24020001 */  addiu     $v0, $zero, 1
/* 853834 802416C4 03E00008 */  jr        $ra
/* 853838 802416C8 27BD0018 */   addiu    $sp, $sp, 0x18
