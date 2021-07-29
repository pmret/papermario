.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B4C_9001BC
/* 9001BC 80240B4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9001C0 80240B50 AFB00010 */  sw        $s0, 0x10($sp)
/* 9001C4 80240B54 0080802D */  daddu     $s0, $a0, $zero
/* 9001C8 80240B58 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9001CC 80240B5C 0C00AB39 */  jal       heap_malloc
/* 9001D0 80240B60 24040780 */   addiu    $a0, $zero, 0x780
/* 9001D4 80240B64 0200202D */  daddu     $a0, $s0, $zero
/* 9001D8 80240B68 3C05FD05 */  lui       $a1, 0xfd05
/* 9001DC 80240B6C 34A50F80 */  ori       $a1, $a1, 0xf80
/* 9001E0 80240B70 0C0B2026 */  jal       set_variable
/* 9001E4 80240B74 0040302D */   daddu    $a2, $v0, $zero
/* 9001E8 80240B78 2402FFFF */  addiu     $v0, $zero, -1
/* 9001EC 80240B7C 3C058024 */  lui       $a1, %hi(func_80240B00_900170)
/* 9001F0 80240B80 24A50B00 */  addiu     $a1, $a1, %lo(func_80240B00_900170)
/* 9001F4 80240B84 3C018025 */  lui       $at, %hi(D_802483D0)
/* 9001F8 80240B88 AC2283D0 */  sw        $v0, %lo(D_802483D0)($at)
/* 9001FC 80240B8C 0C048C56 */  jal       create_generic_entity_world
/* 900200 80240B90 0000202D */   daddu    $a0, $zero, $zero
/* 900204 80240B94 8FBF0014 */  lw        $ra, 0x14($sp)
/* 900208 80240B98 8FB00010 */  lw        $s0, 0x10($sp)
/* 90020C 80240B9C 24020002 */  addiu     $v0, $zero, 2
/* 900210 80240BA0 03E00008 */  jr        $ra
/* 900214 80240BA4 27BD0018 */   addiu    $sp, $sp, 0x18
