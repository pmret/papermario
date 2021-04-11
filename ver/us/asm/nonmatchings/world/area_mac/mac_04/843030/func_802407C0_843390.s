.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_04_UnkFunc31
/* 843390 802407C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 843394 802407C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 843398 802407C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 84339C 802407CC 0C00EABB */  jal       get_npc_unsafe
/* 8433A0 802407D0 8C84014C */   lw       $a0, 0x14c($a0)
/* 8433A4 802407D4 24040008 */  addiu     $a0, $zero, 8
/* 8433A8 802407D8 0040802D */  daddu     $s0, $v0, $zero
/* 8433AC 802407DC 3C028024 */  lui       $v0, %hi(mac_04_UnkFunc28)
/* 8433B0 802407E0 2442082C */  addiu     $v0, $v0, %lo(mac_04_UnkFunc28)
/* 8433B4 802407E4 0C00AB39 */  jal       heap_malloc
/* 8433B8 802407E8 AE020008 */   sw       $v0, 8($s0)
/* 8433BC 802407EC 0040182D */  daddu     $v1, $v0, $zero
/* 8433C0 802407F0 AE030020 */  sw        $v1, 0x20($s0)
/* 8433C4 802407F4 AC600000 */  sw        $zero, ($v1)
/* 8433C8 802407F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8433CC 802407FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 8433D0 80240800 24020001 */  addiu     $v0, $zero, 1
/* 8433D4 80240804 03E00008 */  jr        $ra
/* 8433D8 80240808 27BD0018 */   addiu    $sp, $sp, 0x18
