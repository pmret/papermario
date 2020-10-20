.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405B4_BC8414
/* BC8414 802405B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC8418 802405B8 AFB10014 */  sw        $s1, 0x14($sp)
/* BC841C 802405BC 0080882D */  daddu     $s1, $a0, $zero
/* BC8420 802405C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC8424 802405C4 AFB00010 */  sw        $s0, 0x10($sp)
/* BC8428 802405C8 0C00EABB */  jal       get_npc_unsafe
/* BC842C 802405CC 8E24014C */   lw       $a0, 0x14c($s1)
/* BC8430 802405D0 0000202D */  daddu     $a0, $zero, $zero
/* BC8434 802405D4 0C00EABB */  jal       get_npc_unsafe
/* BC8438 802405D8 0040802D */   daddu    $s0, $v0, $zero
/* BC843C 802405DC AE020020 */  sw        $v0, 0x20($s0)
/* BC8440 802405E0 8E23014C */  lw        $v1, 0x14c($s1)
/* BC8444 802405E4 00032040 */  sll       $a0, $v1, 1
/* BC8448 802405E8 00832021 */  addu      $a0, $a0, $v1
/* BC844C 802405EC 00041900 */  sll       $v1, $a0, 4
/* BC8450 802405F0 00641823 */  subu      $v1, $v1, $a0
/* BC8454 802405F4 AE230078 */  sw        $v1, 0x78($s1)
/* BC8458 802405F8 8E030000 */  lw        $v1, ($s0)
/* BC845C 802405FC 3C040004 */  lui       $a0, 4
/* BC8460 80240600 00641825 */  or        $v1, $v1, $a0
/* BC8464 80240604 AE030000 */  sw        $v1, ($s0)
/* BC8468 80240608 AE200074 */  sw        $zero, 0x74($s1)
/* BC846C 8024060C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC8470 80240610 8FB10014 */  lw        $s1, 0x14($sp)
/* BC8474 80240614 8FB00010 */  lw        $s0, 0x10($sp)
/* BC8478 80240618 24020002 */  addiu     $v0, $zero, 2
/* BC847C 8024061C 03E00008 */  jr        $ra
/* BC8480 80240620 27BD0020 */   addiu    $sp, $sp, 0x20
