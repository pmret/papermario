.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244984_805204
/* 805204 80244984 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 805208 80244988 AFB3001C */  sw        $s3, 0x1c($sp)
/* 80520C 8024498C 0080982D */  daddu     $s3, $a0, $zero
/* 805210 80244990 AFB20018 */  sw        $s2, 0x18($sp)
/* 805214 80244994 3C12F840 */  lui       $s2, 0xf840
/* 805218 80244998 36526200 */  ori       $s2, $s2, 0x6200
/* 80521C 8024499C AFB10014 */  sw        $s1, 0x14($sp)
/* 805220 802449A0 0000882D */  daddu     $s1, $zero, $zero
/* 805224 802449A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 805228 802449A8 0220802D */  daddu     $s0, $s1, $zero
/* 80522C 802449AC AFBF0020 */  sw        $ra, 0x20($sp)
/* 805230 802449B0 0000202D */  daddu     $a0, $zero, $zero
.L802449B4:
/* 805234 802449B4 0C0B1EAF */  jal       evt_get_variable
/* 805238 802449B8 02502821 */   addu     $a1, $s2, $s0
/* 80523C 802449BC 50400001 */  beql      $v0, $zero, .L802449C4
/* 805240 802449C0 26310001 */   addiu    $s1, $s1, 1
.L802449C4:
/* 805244 802449C4 26100001 */  addiu     $s0, $s0, 1
/* 805248 802449C8 2A020010 */  slti      $v0, $s0, 0x10
/* 80524C 802449CC 1440FFF9 */  bnez      $v0, .L802449B4
/* 805250 802449D0 0000202D */   daddu    $a0, $zero, $zero
/* 805254 802449D4 AE710084 */  sw        $s1, 0x84($s3)
/* 805258 802449D8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 80525C 802449DC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 805260 802449E0 8FB20018 */  lw        $s2, 0x18($sp)
/* 805264 802449E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 805268 802449E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 80526C 802449EC 24020002 */  addiu     $v0, $zero, 2
/* 805270 802449F0 03E00008 */  jr        $ra
/* 805274 802449F4 27BD0028 */   addiu    $sp, $sp, 0x28
