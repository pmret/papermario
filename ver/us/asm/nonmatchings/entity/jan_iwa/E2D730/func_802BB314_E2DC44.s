.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB314_E2DC44
/* E2DC44 802BB314 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2DC48 802BB318 0080102D */  daddu     $v0, $a0, $zero
/* E2DC4C 802BB31C 3C048000 */  lui       $a0, 0x8000
/* E2DC50 802BB320 AFBF0018 */  sw        $ra, 0x18($sp)
/* E2DC54 802BB324 C4400050 */  lwc1      $f0, 0x50($v0)
/* E2DC58 802BB328 3484006A */  ori       $a0, $a0, 0x6a
/* E2DC5C 802BB32C E7A00010 */  swc1      $f0, 0x10($sp)
/* E2DC60 802BB330 8C460048 */  lw        $a2, 0x48($v0)
/* E2DC64 802BB334 8C47004C */  lw        $a3, 0x4c($v0)
/* E2DC68 802BB338 0C052757 */  jal       sfx_play_sound_at_position
/* E2DC6C 802BB33C 0000282D */   daddu    $a1, $zero, $zero
/* E2DC70 802BB340 8FBF0018 */  lw        $ra, 0x18($sp)
/* E2DC74 802BB344 03E00008 */  jr        $ra
/* E2DC78 802BB348 27BD0020 */   addiu    $sp, $sp, 0x20
