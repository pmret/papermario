.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A916C_42EF8C
/* 42EF8C 802A916C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42EF90 802A9170 AFB20018 */  sw        $s2, 0x18($sp)
/* 42EF94 802A9174 0080902D */  daddu     $s2, $a0, $zero
/* 42EF98 802A9178 AFB10014 */  sw        $s1, 0x14($sp)
/* 42EF9C 802A917C 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42EFA0 802A9180 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42EFA4 802A9184 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42EFA8 802A9188 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 42EFAC 802A918C 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 42EFB0 802A9190 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42EFB4 802A9194 AFB00010 */  sw        $s0, 0x10($sp)
/* 42EFB8 802A9198 82620083 */  lb        $v0, 0x83($s3)
/* 42EFBC 802A919C 8E50000C */  lw        $s0, 0xc($s2)
/* 42EFC0 802A91A0 10400023 */  beqz      $v0, .L802A9230
/* 42EFC4 802A91A4 0260182D */   daddu    $v1, $s3, $zero
/* 42EFC8 802A91A8 0C09A216 */  jal       func_80268858
/* 42EFCC 802A91AC 00000000 */   nop
/* 42EFD0 802A91B0 8E050000 */  lw        $a1, ($s0)
/* 42EFD4 802A91B4 26100004 */  addiu     $s0, $s0, 4
/* 42EFD8 802A91B8 0C0B1EAF */  jal       get_variable
/* 42EFDC 802A91BC 0240202D */   daddu    $a0, $s2, $zero
/* 42EFE0 802A91C0 A622004E */  sh        $v0, 0x4e($s1)
/* 42EFE4 802A91C4 8E050000 */  lw        $a1, ($s0)
/* 42EFE8 802A91C8 26100004 */  addiu     $s0, $s0, 4
/* 42EFEC 802A91CC 0C0B1EAF */  jal       get_variable
/* 42EFF0 802A91D0 0240202D */   daddu    $a0, $s2, $zero
/* 42EFF4 802A91D4 A6220052 */  sh        $v0, 0x52($s1)
/* 42EFF8 802A91D8 8E050000 */  lw        $a1, ($s0)
/* 42EFFC 802A91DC 0C0B1EAF */  jal       get_variable
/* 42F000 802A91E0 0240202D */   daddu    $a0, $s2, $zero
/* 42F004 802A91E4 00022400 */  sll       $a0, $v0, 0x10
/* 42F008 802A91E8 00042403 */  sra       $a0, $a0, 0x10
/* 42F00C 802A91EC 0C09A089 */  jal       func_80268224
/* 42F010 802A91F0 A6220050 */   sh       $v0, 0x50($s1)
/* 42F014 802A91F4 3C04FFFF */  lui       $a0, 0xffff
/* 42F018 802A91F8 34847FFF */  ori       $a0, $a0, 0x7fff
/* 42F01C 802A91FC A6220050 */  sh        $v0, 0x50($s1)
/* 42F020 802A9200 A2200060 */  sb        $zero, 0x60($s1)
/* 42F024 802A9204 A6200044 */  sh        $zero, 0x44($s1)
/* 42F028 802A9208 A6200048 */  sh        $zero, 0x48($s1)
/* 42F02C 802A920C 8E620000 */  lw        $v0, ($s3)
/* 42F030 802A9210 2403000A */  addiu     $v1, $zero, 0xa
/* 42F034 802A9214 A2600081 */  sb        $zero, 0x81($s3)
/* 42F038 802A9218 A623004C */  sh        $v1, 0x4c($s1)
/* 42F03C 802A921C 00441024 */  and       $v0, $v0, $a0
/* 42F040 802A9220 0C09A446 */  jal       func_80269118
/* 42F044 802A9224 AE620000 */   sw       $v0, ($s3)
/* 42F048 802A9228 080AA48E */  j         .L802A9238
/* 42F04C 802A922C 24020002 */   addiu    $v0, $zero, 2
.L802A9230:
/* 42F050 802A9230 A0600081 */  sb        $zero, 0x81($v1)
/* 42F054 802A9234 24020002 */  addiu     $v0, $zero, 2
.L802A9238:
/* 42F058 802A9238 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42F05C 802A923C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42F060 802A9240 8FB20018 */  lw        $s2, 0x18($sp)
/* 42F064 802A9244 8FB10014 */  lw        $s1, 0x14($sp)
/* 42F068 802A9248 8FB00010 */  lw        $s0, 0x10($sp)
/* 42F06C 802A924C 03E00008 */  jr        $ra
/* 42F070 802A9250 27BD0028 */   addiu    $sp, $sp, 0x28
