.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424D4_95D6D4
/* 95D6D4 802424D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95D6D8 802424D8 3C058024 */  lui       $a1, %hi(func_80242468_95D668)
/* 95D6DC 802424DC 24A52468 */  addiu     $a1, $a1, %lo(func_80242468_95D668)
/* 95D6E0 802424E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95D6E4 802424E4 0C048C8F */  jal       bind_dynamic_entity_7
/* 95D6E8 802424E8 0000202D */   daddu    $a0, $zero, $zero
/* 95D6EC 802424EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95D6F0 802424F0 3C018025 */  lui       $at, %hi(D_8024DFC0)
/* 95D6F4 802424F4 AC22DFC0 */  sw        $v0, %lo(D_8024DFC0)($at)
/* 95D6F8 802424F8 24020002 */  addiu     $v0, $zero, 2
/* 95D6FC 802424FC 03E00008 */  jr        $ra
/* 95D700 80242500 27BD0018 */   addiu    $sp, $sp, 0x18
