.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6118
/* 107998 802E6118 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 10799C 802E611C AFB10014 */  sw        $s1, 0x14($sp)
/* 1079A0 802E6120 0080882D */  daddu     $s1, $a0, $zero
/* 1079A4 802E6124 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1079A8 802E6128 AFB00010 */  sw        $s0, 0x10($sp)
/* 1079AC 802E612C 8E300040 */  lw        $s0, 0x40($s1)
/* 1079B0 802E6130 0C039769 */  jal       set_action_state
/* 1079B4 802E6134 24040006 */   addiu    $a0, $zero, 6
/* 1079B8 802E6138 3C014170 */  lui       $at, 0x4170
/* 1079BC 802E613C 44810000 */  mtc1      $at, $f0
/* 1079C0 802E6140 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 1079C4 802E6144 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 1079C8 802E6148 AC400074 */  sw        $zero, 0x74($v0)
/* 1079CC 802E614C E4400070 */  swc1      $f0, 0x70($v0)
/* 1079D0 802E6150 C6000000 */  lwc1      $f0, ($s0)
/* 1079D4 802E6154 46800020 */  cvt.s.w   $f0, $f0
/* 1079D8 802E6158 E4400078 */  swc1      $f0, 0x78($v0)
/* 1079DC 802E615C C620004C */  lwc1      $f0, 0x4c($s1)
/* 1079E0 802E6160 E440007C */  swc1      $f0, 0x7c($v0)
/* 1079E4 802E6164 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1079E8 802E6168 8FB10014 */  lw        $s1, 0x14($sp)
/* 1079EC 802E616C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1079F0 802E6170 03E00008 */  jr        $ra
/* 1079F4 802E6174 27BD0020 */   addiu    $sp, $sp, 0x20
