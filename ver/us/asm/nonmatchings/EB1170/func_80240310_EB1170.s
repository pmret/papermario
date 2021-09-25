.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_EB1170
/* EB1170 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB1174 80240314 AFB00010 */  sw        $s0, 0x10($sp)
/* EB1178 80240318 3C108024 */  lui       $s0, %hi(D_80241780_EB25E0)
/* EB117C 8024031C 26101780 */  addiu     $s0, $s0, %lo(D_80241780_EB25E0)
/* EB1180 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB1184 80240324 AFB10014 */  sw        $s1, 0x14($sp)
/* EB1188 80240328 8E020000 */  lw        $v0, ($s0)
/* EB118C 8024032C 14400010 */  bnez      $v0, .L80240370
/* EB1190 80240330 0080882D */   daddu    $s1, $a0, $zero
/* EB1194 80240334 0C00AFF5 */  jal       dead_heap_malloc
/* EB1198 80240338 24040040 */   addiu    $a0, $zero, 0x40
/* EB119C 8024033C AE020000 */  sw        $v0, ($s0)
/* EB11A0 80240340 0000182D */  daddu     $v1, $zero, $zero
/* EB11A4 80240344 0040282D */  daddu     $a1, $v0, $zero
/* EB11A8 80240348 0220202D */  daddu     $a0, $s1, $zero
.L8024034C:
/* EB11AC 8024034C 8C820084 */  lw        $v0, 0x84($a0)
/* EB11B0 80240350 24840004 */  addiu     $a0, $a0, 4
/* EB11B4 80240354 24630001 */  addiu     $v1, $v1, 1
/* EB11B8 80240358 ACA20000 */  sw        $v0, ($a1)
/* EB11BC 8024035C 28620010 */  slti      $v0, $v1, 0x10
/* EB11C0 80240360 1440FFFA */  bnez      $v0, .L8024034C
/* EB11C4 80240364 24A50004 */   addiu    $a1, $a1, 4
/* EB11C8 80240368 080900EB */  j         .L802403AC
/* EB11CC 8024036C 00000000 */   nop
.L80240370:
/* EB11D0 80240370 0000182D */  daddu     $v1, $zero, $zero
/* EB11D4 80240374 0040282D */  daddu     $a1, $v0, $zero
/* EB11D8 80240378 0220202D */  daddu     $a0, $s1, $zero
.L8024037C:
/* EB11DC 8024037C 8CA20000 */  lw        $v0, ($a1)
/* EB11E0 80240380 24A50004 */  addiu     $a1, $a1, 4
/* EB11E4 80240384 24630001 */  addiu     $v1, $v1, 1
/* EB11E8 80240388 AC820084 */  sw        $v0, 0x84($a0)
/* EB11EC 8024038C 28620010 */  slti      $v0, $v1, 0x10
/* EB11F0 80240390 1440FFFA */  bnez      $v0, .L8024037C
/* EB11F4 80240394 24840004 */   addiu    $a0, $a0, 4
/* EB11F8 80240398 3C108024 */  lui       $s0, %hi(D_80241780_EB25E0)
/* EB11FC 8024039C 26101780 */  addiu     $s0, $s0, %lo(D_80241780_EB25E0)
/* EB1200 802403A0 0C00B007 */  jal       func_8002C01C
/* EB1204 802403A4 8E040000 */   lw       $a0, ($s0)
/* EB1208 802403A8 AE000000 */  sw        $zero, ($s0)
.L802403AC:
/* EB120C 802403AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB1210 802403B0 8FB10014 */  lw        $s1, 0x14($sp)
/* EB1214 802403B4 8FB00010 */  lw        $s0, 0x10($sp)
/* EB1218 802403B8 24020002 */  addiu     $v0, $zero, 2
/* EB121C 802403BC 03E00008 */  jr        $ra
/* EB1220 802403C0 27BD0020 */   addiu    $sp, $sp, 0x20
