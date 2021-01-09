.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024140C_C8EFBC
/* C8EFBC 8024140C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8EFC0 80241410 AFB00010 */  sw        $s0, 0x10($sp)
/* C8EFC4 80241414 0080802D */  daddu     $s0, $a0, $zero
/* C8EFC8 80241418 AFBF0014 */  sw        $ra, 0x14($sp)
/* C8EFCC 8024141C 0C00AB39 */  jal       heap_malloc
/* C8EFD0 80241420 24040780 */   addiu    $a0, $zero, 0x780
/* C8EFD4 80241424 0200202D */  daddu     $a0, $s0, $zero
/* C8EFD8 80241428 3C05FD05 */  lui       $a1, 0xfd05
/* C8EFDC 8024142C 34A50F80 */  ori       $a1, $a1, 0xf80
/* C8EFE0 80241430 0C0B2026 */  jal       set_variable
/* C8EFE4 80241434 0040302D */   daddu    $a2, $v0, $zero
/* C8EFE8 80241438 2402FFFF */  addiu     $v0, $zero, -1
/* C8EFEC 8024143C 3C058024 */  lui       $a1, %hi(func_802413C0_C8DB64)
/* C8EFF0 80241440 24A513C0 */  addiu     $a1, $a1, %lo(func_802413C0_C8DB64)
/* C8EFF4 80241444 3C018025 */  lui       $at, %hi(D_80248380)
/* C8EFF8 80241448 AC228380 */  sw        $v0, %lo(D_80248380)($at)
/* C8EFFC 8024144C 0C048C56 */  jal       bind_dynamic_entity_3
/* C8F000 80241450 0000202D */   daddu    $a0, $zero, $zero
/* C8F004 80241454 8FBF0014 */  lw        $ra, 0x14($sp)
/* C8F008 80241458 8FB00010 */  lw        $s0, 0x10($sp)
/* C8F00C 8024145C 24020002 */  addiu     $v0, $zero, 2
/* C8F010 80241460 03E00008 */  jr        $ra
/* C8F014 80241464 27BD0018 */   addiu    $sp, $sp, 0x18
